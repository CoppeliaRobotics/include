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

struct TypeTag_bool {};
struct TypeTag_int {};
struct TypeTag_long {};
struct TypeTag_float {};
struct TypeTag_double {};
template<typename T> struct TypeTag_table {};
template<typename T> struct TypeTag_grid {};
struct TypeTag_string {};
struct TypeTag_buffer {};
struct TypeTag_vector3 {};
struct TypeTag_quaternion {};
struct TypeTag_struct {};
struct TypeTag_func {};

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

static void readFromStack(TypeTag_bool, sim::handle_t stackHandle, bool *value, const ReadOptions &rdopt = {})
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

static void readFromStack(TypeTag_int, sim::handle_t stackHandle, int *value, const ReadOptions &rdopt = {})
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

static void readFromStack(TypeTag_long, sim::handle_t stackHandle, sim::long_t *value, const ReadOptions &rdopt = {})
{
    sim::long_t v;
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

static void readFromStack(TypeTag_float, sim::handle_t stackHandle, float *value, const ReadOptions &rdopt = {})
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

static void readFromStack(TypeTag_double, sim::handle_t stackHandle, double *value, const ReadOptions &rdopt = {})
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

static void readFromStack(TypeTag_string, sim::handle_t stackHandle, std::string *value, const ReadOptions &rdopt = {})
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

static void readFromStack(TypeTag_buffer, sim::handle_t stackHandle, std::string *value, const ReadOptions &rdopt = {})
{
    std::string v;
    if(sim::getStackStringValue(stackHandle, &v) == 1)
    {
        *value = v;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        throw sim::exception("expected buffer");
    }
}

static void readFromStack(TypeTag_func, sim::handle_t stackHandle, std::string *value, const ReadOptions &rdopt = {})
{
    std::string v;
    if(sim::getStackStringValue(stackHandle, &v) == 1)
    {
        *value = v;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        throw sim::exception("expected func");
    }
}

template<typename TypeTag, typename T>
static void readFromStack(TypeTag, sim::handle_t stackHandle, std::optional<T> *value, const ReadOptions &rdopt = {})
{
    if(sim::getStackItemType(stackHandle, -1) == sim_stackitem_null)
    {
        *value = std::nullopt;
        sim::popStackItem(stackHandle, 1);
    }
    else
    {
        T v;
        readFromStack(TypeTag{}, stackHandle, &v, rdopt); // will call sim::popStackItem() by itself
        *value = v;
    }
}

template<typename ItemTypeTag, typename T>
static void readFromStack(TypeTag_table<ItemTypeTag>, sim::handle_t stackHandle, std::vector<T> *vec, const ReadOptions &rdopt = {})
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
        readFromStack(TypeTag_int{}, stackHandle, &j);
        sim::moveStackItemToTop(stackHandle, oldsz - 1);
        if constexpr(std::is_same<T, bool>::value)
        {
            T v;
            readFromStack(ItemTypeTag{}, stackHandle, &v);
            (*vec)[i] = v;
        }
        else
        {
            readFromStack(ItemTypeTag{}, stackHandle, &vec->at(i));
        }
    }
}

template<typename ItemTypeTag, typename T>
static void readFromStack(TypeTag_table<ItemTypeTag>, sim::handle_t stackHandle, std::vector<T> *vec, int (*f)(sim::handle_t, std::vector<T>*), const ReadOptions &rdopt = {})
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
void readFromStack(TypeTag_table<float> t, sim::handle_t stackHandle, std::vector<float> *vec, const ReadOptions &rdopt)
{
    readFromStack(t, stackHandle, vec, sim::getStackFloatTable, rdopt);
}

template<>
void readFromStack(TypeTag_table<double> t, sim::handle_t stackHandle, std::vector<double> *vec, const ReadOptions &rdopt)
{
    readFromStack(t, stackHandle, vec, sim::getStackDoubleTable, rdopt);
}

template<>
void readFromStack(TypeTag_table<int> t, sim::handle_t stackHandle, std::vector<int> *vec, const ReadOptions &rdopt)
{
    readFromStack(t, stackHandle, vec, sim::getStackInt32Table, rdopt);
}

template<typename ItemTypeTag, typename T>
static void readFromStack(TypeTag_grid<ItemTypeTag>, sim::handle_t stackHandle, Grid<T> *grid, const ReadOptions &rdopt = {})
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
            readFromStack(TypeTag_string{}, stackHandle, &key);

            sim::moveStackItemToTop(stackHandle, oldsz - 1); // move value to top
            try
            {
                if(0) {}
                else if(key == "dims")
                {
                    readFromStack(TypeTag_table<int>{}, stackHandle, &grid->dims, ReadOptions().setBounds(0, 1, -1));
                }
                else if(key == "data")
                {
                    readFromStack(TypeTag_table<ItemTypeTag>{}, stackHandle, &grid->data, ReadOptions());
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

static void readFromStack(TypeTag_vector3, sim::handle_t stackHandle, Eigen::Vector3d *vec, const ReadOptions &rdopt = {})
{
    std::vector<double> v;
    ReadOptions rdopt1;
    rdopt1.minSize = rdopt1.maxSize = {3};
    readFromStack(TypeTag_table<double>{}, stackHandle, &v, sim::getStackDoubleTable, rdopt1);
    (*vec) << v[0], v[1], v[2];
}

static void readFromStack(TypeTag_quaternion, sim::handle_t stackHandle, Eigen::Quaterniond *q, const ReadOptions &rdopt = {})
{
    std::vector<double> v;
    ReadOptions rdopt1;
    rdopt1.minSize = rdopt1.maxSize = {4};
    readFromStack(TypeTag_table<double>{}, stackHandle, &v, sim::getStackDoubleTable, rdopt1);
    // note about quaternion order: Eigen=WXYZ, CoppeliaSim=XYZW
    *q = Eigen::Quaterniond(v[3], v[0], v[1], v[2]);
}

#endif // SIM_STUBS_GEN_EIGEN

static void readFromStack(sim::handle_t stackHandle, bool *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_bool{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, int *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_int{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, sim::long_t *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_long{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, float *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_float{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, double *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_double{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::string *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_string{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::optional<int> *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_int{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::optional<sim::long_t> *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_long{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::optional<float> *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_float{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::optional<double> *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_double{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::optional<std::string> *value, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_string{}, stackHandle, value, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::vector<float> *vec, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_table<TypeTag_float>{}, stackHandle, vec, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::vector<double> *vec, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_table<TypeTag_double>{}, stackHandle, vec, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::vector<int> *vec, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_table<TypeTag_int>{}, stackHandle, vec, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, std::vector<std::string> *vec, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_table<TypeTag_string>{}, stackHandle, vec, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, Grid<double> *grid, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_grid<TypeTag_double>{}, stackHandle, grid, rdopt);
}

#ifdef SIM_STUBS_GEN_EIGEN

static void readFromStack(sim::handle_t stackHandle, Eigen::Vector3d *vec, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_vector3{}, stackHandle, vec, rdopt);
}

static void readFromStack(sim::handle_t stackHandle, Eigen::Quaterniond *q, const ReadOptions &rdopt = {})
{
    readFromStack(TypeTag_quaternion{}, stackHandle, q, rdopt);
}

#endif // SIM_STUBS_GEN_EIGEN

static void writeToStack(TypeTag_bool, const bool &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushBoolOntoStack(stackHandle, value);
}

static void writeToStack(TypeTag_int, const int &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushInt32OntoStack(stackHandle, value);
}

static void writeToStack(TypeTag_long, const sim::long_t &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushInt64OntoStack(stackHandle, value);
}

static void writeToStack(TypeTag_float, const float &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushFloatOntoStack(stackHandle, value);
}

static void writeToStack(TypeTag_double, const double &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushDoubleOntoStack(stackHandle, value);
}

static void writeToStack(TypeTag_string, const std::string &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushStringOntoStack(stackHandle, value);
}

static void writeToStack(TypeTag_buffer, const std::string &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushBufferOntoStack(stackHandle, value);
}

static void writeToStack(TypeTag_func, const std::string &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushStringOntoStack(stackHandle, value);
}

template<typename TypeTag, typename T>
static void writeToStack(TypeTag, const std::optional<T> &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    if(!value)
    {
        sim::pushNullOntoStack(stackHandle);
        return;
    }

    writeToStack(TypeTag{}, *value, stackHandle, wropt);
}

template<typename ItemTypeTag, typename T>
static void writeToStack(TypeTag_table<ItemTypeTag>, const std::vector<T> &vec, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    sim::pushTableOntoStack(stackHandle);
    for(size_t i = 0; i < vec.size(); i++)
    {
        writeToStack(TypeTag_int{}, int(i + 1), stackHandle);
        writeToStack(ItemTypeTag{}, vec.at(i), stackHandle);
        sim::insertDataIntoStackTable(stackHandle);
    }
}

template<>
void writeToStack(TypeTag_table<float>, const std::vector<float> &vec, sim::handle_t stackHandle, const WriteOptions &wropt)
{
    sim::pushFloatTableOntoStack(stackHandle, vec);
}

template<>
void writeToStack(TypeTag_table<double>, const std::vector<double> &vec, sim::handle_t stackHandle, const WriteOptions &wropt)
{
    sim::pushDoubleTableOntoStack(stackHandle, vec);
}

template<>
void writeToStack(TypeTag_table<int>, const std::vector<int> &vec, sim::handle_t stackHandle, const WriteOptions &wropt)
{
    sim::pushInt32TableOntoStack(stackHandle, vec);
}

template<typename ItemTypeTag, typename T>
static void writeToStack(TypeTag_grid<ItemTypeTag>, const Grid<T> &grid, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    try
    {
        sim::pushTableOntoStack(stackHandle);
        try
        {
            writeToStack(TypeTag_string{}, std::string{"dims"}, stackHandle);
            writeToStack(TypeTag_table<int>{}, grid.dims, stackHandle);
            sim::insertDataIntoStackTable(stackHandle);
        }
        catch(std::exception &ex)
        {
            throw sim::exception("field 'dims': %s", ex.what());
        }
        try
        {
            writeToStack(TypeTag_string{}, std::string{"data"}, stackHandle);
            writeToStack(TypeTag_table<T>{}, grid.data, stackHandle);
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

static void writeToStack(TypeTag_vector3, const Eigen::Vector3d &vec, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    std::vector<double> v {vec.x(), vec.y(), vec.z()};
    writeToStack(TypeTag_table<double>{}, v, stackHandle, wropt);
}

static void writeToStack(TypeTag_quaternion, const Eigen::Quaterniond &q, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    // note about quaternion order: Eigen=WXYZ, CoppeliaSim=XYZW
    std::vector<double> v {q.x(), q.y(), q.z(), q.w()};
    writeToStack(TypeTag_table<double>{}, v, stackHandle, wropt);
}

#endif // SIM_STUBS_GEN_EIGEN

static void writeToStack(const bool &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_bool{}, value, stackHandle, wropt);
}

static void writeToStack(const int &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_int{}, value, stackHandle, wropt);
}

static void writeToStack(const sim::long_t &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_long{}, value, stackHandle, wropt);
}

static void writeToStack(const float &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_float{}, value, stackHandle, wropt);
}

static void writeToStack(const double &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_double{}, value, stackHandle, wropt);
}

static void writeToStack(const std::string &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_string{}, value, stackHandle, wropt);
}

static void writeToStack(const std::optional<int> &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_int{}, value, stackHandle, wropt);
}

static void writeToStack(const std::optional<sim::long_t> &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_long{}, value, stackHandle, wropt);
}

static void writeToStack(const std::optional<float> &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_float{}, value, stackHandle, wropt);
}

static void writeToStack(const std::optional<double> &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_double{}, value, stackHandle, wropt);
}

static void writeToStack(const std::optional<std::string> &value, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_string{}, value, stackHandle, wropt);
}

static void writeToStack(const std::vector<float> &vec, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_table<TypeTag_float>{}, vec, stackHandle, wropt);
}

static void writeToStack(const std::vector<double> &vec, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_table<TypeTag_double>{}, vec, stackHandle, wropt);
}

static void writeToStack(const std::vector<int> &vec, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_table<TypeTag_int>{}, vec, stackHandle, wropt);
}

static void writeToStack(const std::vector<std::string> &vec, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_table<TypeTag_string>{}, vec, stackHandle, wropt);
}

static void writeToStack(const Grid<double> &grid, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_grid<TypeTag_double>{}, grid, stackHandle, wropt);
}

#ifdef SIM_STUBS_GEN_EIGEN

static void writeToStack(const Eigen::Vector3d &vec, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_vector3{}, vec, stackHandle, wropt);
}

static void writeToStack(const Eigen::Quaterniond &q, sim::handle_t stackHandle, const WriteOptions &wropt = {})
{
    writeToStack(TypeTag_quaternion{}, q, stackHandle, wropt);
}

#endif // SIM_STUBS_GEN_EIGEN
