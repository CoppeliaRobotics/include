#pragma once

#include <cstdint>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include <set>
#include <boost/algorithm/string.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/format.hpp>

#ifdef SIM_STUBS_GEN_EIGEN
#include <Eigen/Dense>
#include <Eigen/Geometry>
#endif // SIM_STUBS_GEN_EIGEN

template<typename T>
struct Grid
{
    std::vector<int> dims;
    std::vector<T> data;
};

struct ReadOptions
{
    std::vector<size_t> minSize;
    std::vector<size_t> maxSize;

    ReadOptions& setBounds(size_t dim, size_t minSize_, size_t maxSize_)
    {
        while(minSize.size() <= dim) minSize.push_back(0);
        while(maxSize.size() <= dim) maxSize.push_back(std::numeric_limits<size_t>::max());
        minSize[dim] = minSize_;
        maxSize[dim] = maxSize_;
        return *this;
    }

    ReadOptions& setBounds(size_t dim, const std::string &s)
    {
        if(s == "*") return setBounds(dim, 0, -1);
        auto n = s.find("..");
        if(n == std::string::npos)
        {
            int f = std::stoi(s);
            return setBounds(dim, f, f);
        }
        else
        {
            std::string smin = s.substr(0, n);
            std::string smax = s.substr(n + 2);
            int min = std::stoi(smin);
            int max = smax == "*" ? -1 : std::stoi(smax);
            return setBounds(dim, min, max);
        }
    }

    ReadOptions& setBounds(const std::string &s)
    {
        if(s != "")
        {
            std::vector<std::string> ss;
            boost::split(ss, s, boost::is_any_of(", "));
            for(size_t dim = 0; dim < ss.size(); dim++)
                setBounds(dim, ss.at(dim));
        }
        return *this;
    }

    void validateTableSize(size_t sz) const
    {
        if(minSize.empty() || maxSize.empty()) return;
        if(minSize[0] == maxSize[0])
        {
            if(sz != minSize[0])
                throw sim::exception("must have exactly %d elements", minSize[0]);
        }
        else
        {
            if(sz < minSize[0])
                throw sim::exception("must have at least %d elements", minSize[0]);
            if(sz > maxSize[0])
                throw sim::exception("must have at most %d elements", maxSize[0]);
        }
    }

    void validateSize(size_t dim, size_t sz) const
    {
        if(dim >= minSize.size() || dim >= maxSize.size()) return;
        if(minSize[dim] == maxSize[dim])
        {
            if(sz != minSize[dim])
                throw sim::exception("dimension %d must have exactly %d elements", dim + 1, minSize[dim]);
        }
        else
        {
            if(sz < minSize[dim])
                throw sim::exception("dimension %d must have at least %d elements", dim + 1, minSize[dim]);
            if(sz > maxSize[dim])
                throw sim::exception("dimension %d must have at most %d elements", dim + 1, maxSize[dim]);
        }
    }

    template<typename T>
    void validateSize(const std::vector<T> &szs) const
    {
        size_t n = std::min(minSize.size(), maxSize.size());
        if(n && szs.size() != n)
            throw sim::exception("incorrect dimension count: %d (should be %d)", szs.size(), n);
        for(size_t dim = 0; dim < n; dim++)
            validateSize(dim, szs.at(dim));
    }
};

struct WriteOptions
{
    void *dummy{nullptr};
};

static void readFromStack(sim::handle_t stackHandle, bool *value, const ReadOptions &rdopt = {})
{
    bool v;
    if(sim::getStackBoolValue(stackHandle, &v) == 1)
    {
        *value = v;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        throw sim::exception("expected bool");
    }
}

static void readFromStack(sim::handle_t stackHandle, int *value, const ReadOptions &rdopt = {})
{
    int v;
    if(sim::getStackInt32Value(stackHandle, &v) == 1)
    {
        *value = v;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        throw sim::exception("expected int");
    }
}

static void readFromStack(sim::handle_t stackHandle, int64_t *value, const ReadOptions &rdopt = {})
{
    int64_t v;
    if(sim::getStackInt64Value(stackHandle, &v) == 1)
    {
        *value = v;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        throw sim::exception("expected int64");
    }
}

static void readFromStack(sim::handle_t stackHandle, float *value, const ReadOptions &rdopt = {})
{
    float v;
    if(sim::getStackFloatValue(stackHandle, &v) == 1)
    {
        *value = v;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        throw sim::exception("expected float");
    }
}

static void readFromStack(sim::handle_t stackHandle, double *value, const ReadOptions &rdopt = {})
{
    double v;
    if(sim::getStackDoubleValue(stackHandle, &v) == 1)
    {
        *value = v;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        throw sim::exception("expected double");
    }
}

static void readFromStack(sim::handle_t stackHandle, std::string *value, const ReadOptions &rdopt = {})
{
    std::string v;
    if(sim::getStackStringValue(stackHandle, &v) == 1)
    {
        *value = v;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        throw sim::exception("expected string");
    }
}

template<typename T>
static void readFromStack(sim::handle_t stackHandle, std::optional<T> *value, const ReadOptions &rdopt = {})
{
    if(sim::getStackItemType(stackHandle, -1) == sim_stackitem_null)
    {
        *value = std::nullopt;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        T v;
        readFromStack(stackHandle, &v, rdopt); // will call sim::popStackItem() by itself
        *value = v;
    }
}

template<typename T>
static void readFromStack(sim::handle_t stackHandle, std::vector<T> *vec, const ReadOptions &rdopt = {})
{
    int sz = sim::getStackTableInfo(stackHandle, 0);
    if(sz < 0)
        throw sim::exception("expected array (simGetStackTableInfo(stackHandle, 0) returned %d)", sz);

    rdopt.validateTableSize(sz);

    int oldsz = sim::getStackSize(stackHandle);
    sim::unfoldStackTable(stackHandle);
    int sz1 = (sim::getStackSize(stackHandle) - oldsz + 1) / 2;
    if(sz != sz1)
        throw std::runtime_error("simUnfoldStackTable unpacked more elements than simGetStackTableInfo reported");

    vec->resize(sz);

    for(int i = 0; i < sz; i++)
    {
        sim::moveStackItemToTop(stackHandle, oldsz - 1);
        int j;
        readFromStack(stackHandle, &j);
        sim::moveStackItemToTop(stackHandle, oldsz - 1);
        if constexpr(std::is_same<T, bool>::value)
        {
            T v;
            readFromStack(stackHandle, &v);
            (*vec)[i] = v;
        }
        else
        {
            readFromStack(stackHandle, &vec->at(i));
        }
    }
}

template<typename T>
static void readFromStack(sim::handle_t stackHandle, std::vector<T> *vec, int (*f)(sim::handle_t, std::vector<T>*), const ReadOptions &rdopt = {})
{
    int sz = sim::getStackTableInfo(stackHandle, 0);
    if(sz < 0)
        throw sim::exception("expected array (simGetStackTableInfo(stackHandle, 0) returned %d)", sz);

    rdopt.validateTableSize(sz);

    int chk = sim::getStackTableInfo(stackHandle, 2);
    if(chk != 1)
        throw sim::exception("table contains non-numbers (simGetStackTableInfo(stackHandle, 2) returned %d)", chk);

    vec->resize(sz);

    int ret = f(stackHandle, vec);
    if(ret != 1)
        throw sim::exception("readFunc error %d", ret);

    sim::popStackItem(stackHandle, 1);
}

template<>
void readFromStack(sim::handle_t stackHandle, std::vector<float> *vec, const ReadOptions &rdopt)
{
    readFromStack(stackHandle, vec, sim::getStackFloatTable, rdopt);
}

template<>
void readFromStack(sim::handle_t stackHandle, std::vector<double> *vec, const ReadOptions &rdopt)
{
    readFromStack(stackHandle, vec, sim::getStackDoubleTable, rdopt);
}

template<>
void readFromStack(sim::handle_t stackHandle, std::vector<int> *vec, const ReadOptions &rdopt)
{
    readFromStack(stackHandle, vec, sim::getStackInt32Table, rdopt);
}

template<typename T>
static void readFromStack(sim::handle_t stackHandle, Grid<T> *grid, const ReadOptions &rdopt = {})
{
    try
    {
        int info = sim::getStackTableInfo(stackHandle, 0);
        if(info != sim_stack_table_map && info != sim_stack_table_empty)
        {
            throw sim::exception("expected a map");
        }

        int oldsz = sim::getStackSize(stackHandle);
        sim::unfoldStackTable(stackHandle);
        int numItems = (sim::getStackSize(stackHandle) - oldsz + 1) / 2;

        std::set<std::string> requiredFields{"dims", "data"};

        while(numItems >= 1)
        {
            sim::moveStackItemToTop(stackHandle, oldsz - 1); // move key to top
            std::string key;
            readFromStack(stackHandle, &key);

            sim::moveStackItemToTop(stackHandle, oldsz - 1); // move value to top
            try
            {
                if(0) {}
                else if(key == "dims")
                {
                    readFromStack(stackHandle, &grid->dims, ReadOptions().setBounds(0, 1, -1));
                }
                else if(key == "data")
                {
                    readFromStack(stackHandle, &grid->data, ReadOptions());
                }
                else
                {
                    throw sim::exception("unexpected key");
                }
            }
            catch(std::exception &ex)
            {
                throw sim::exception("field '%s': %s", key, ex.what());
            }

            requiredFields.erase(key);
            numItems = (sim::getStackSize(stackHandle) - oldsz + 1) / 2;
        }

        for(const auto &field : requiredFields)
            throw sim::exception("missing required field '%s'", field);

        if(grid->dims.size() < 1)
            throw sim::exception("must have at least one dimension");

        size_t elemCount = 1;
        for(const int &i : grid->dims) elemCount *= i;
        if(grid->data.size() != elemCount)
            throw sim::exception("incorrect data length (expected %d elements)", elemCount);

        rdopt.validateSize(grid->dims);
    }
    catch(std::exception &ex)
    {
        throw sim::exception("readFromStack(Grid): %s", ex.what());
    }
}

#ifdef SIM_STUBS_GEN_EIGEN

static void readFromStack(sim::handle_t stackHandle, Eigen::Vector3d *vec, const ReadOptions &rdopt = {})
{
    std::vector<double> v;
    ReadOptions rdopt1;
    rdopt1.minSize = rdopt1.maxSize = {3};
    readFromStack(stackHandle, &v, sim::getStackDoubleTable, rdopt1);
    (*vec) << v[0], v[1], v[2];
}

static void readFromStack(sim::handle_t stackHandle, Eigen::Quaterniond *q, const ReadOptions &rdopt = {})
{
    std::vector<double> v;
    ReadOptions rdopt1;
    rdopt1.minSize = rdopt1.maxSize = {4};
    readFromStack(stackHandle, &v, sim::getStackDoubleTable, rdopt1);
    // note about quaternion order: Eigen=WXYZ, CoppeliaSim=XYZW
    *q = Eigen::Quaterniond(v[3], v[0], v[1], v[2]);
}

#endif // SIM_STUBS_GEN_EIGEN

static void writeToStack(const bool &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushBoolOntoStack(stackHandle, value);
}

static void writeToStack(const int &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushInt32OntoStack(stackHandle, value);
}

static void writeToStack(const int64_t &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushInt64OntoStack(stackHandle, value);
}

static void writeToStack(const float &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushFloatOntoStack(stackHandle, value);
}

static void writeToStack(const double &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushDoubleOntoStack(stackHandle, value);
}

static void writeToStack(const std::string &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushStringOntoStack(stackHandle, value);
}

template<typename T>
static void writeToStack(const std::optional<T> &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    if(!value)
    {
        sim::pushNullOntoStack(stackHandle);
        return;
    }

    writeToStack(*value, stackHandle, wropt);
}

template<typename T>
static void writeToStack(const std::vector<T> &vec, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushTableOntoStack(stackHandle);
    for(size_t i = 0; i < vec.size(); i++)
    {
        writeToStack(int(i + 1), stackHandle);
        writeToStack(vec.at(i), stackHandle);
        sim::insertDataIntoStackTable(stackHandle);
    }
}

template<>
void writeToStack(const std::vector<float> &vec, sim::handle_t stackHandle, const WriteOptions &wropt)
{
    sim::pushFloatTableOntoStack(stackHandle, vec);
}

template<>
void writeToStack(const std::vector<double> &vec, sim::handle_t stackHandle, const WriteOptions &wropt)
{
    sim::pushDoubleTableOntoStack(stackHandle, vec);
}

template<>
void writeToStack(const std::vector<int> &vec, sim::handle_t stackHandle, const WriteOptions &wropt)
{
    sim::pushInt32TableOntoStack(stackHandle, vec);
}

template<typename T>
static void writeToStack(const Grid<T> &grid, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    try
    {
        sim::pushTableOntoStack(stackHandle);
        try
        {
            writeToStack(std::string{"dims"}, stackHandle);
            writeToStack(grid.dims, stackHandle);
            sim::insertDataIntoStackTable(stackHandle);
        }
        catch(std::exception &ex)
        {
            throw sim::exception("field 'dims': %s", ex.what());
        }
        try
        {
            writeToStack(std::string{"data"}, stackHandle);
            writeToStack(grid.data, stackHandle);
            sim::insertDataIntoStackTable(stackHandle);
        }
        catch(std::exception &ex)
        {
            throw sim::exception("field 'data': %s", ex.what());
        }
    }
    catch(std::exception &ex)
    {
        throw sim::exception("writeToStack(Grid): %s", ex.what());
    }
}

#ifdef SIM_STUBS_GEN_EIGEN

static void writeToStack(const Eigen::Vector3d &vec, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    std::vector<double> v {vec.x(), vec.y(), vec.z()};
    writeToStack(v, stackHandle, wropt);
}

static void writeToStack(const Eigen::Quaterniond &q, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    // note about quaternion order: Eigen=WXYZ, CoppeliaSim=XYZW
    std::vector<double> v {q.x(), q.y(), q.z(), q.w()};
    writeToStack(v, stackHandle, wropt);
}

#endif // SIM_STUBS_GEN_EIGEN
