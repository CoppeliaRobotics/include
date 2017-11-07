#pragma once

#include "stackObject.h"
#include <map>

class CStackArray;

class CStackMap : public CStackObject
{
public:
    CStackMap();
    virtual ~CStackMap();

    void appendTopStackItem(const char* key,int stackId);

    CStackObject* copyYourself();

    void setNull(const char* key);
    void setBool(const char* key,bool d);
    void setFloat(const char* key,float d);
    void setDouble(const char* key,double d);
    void setInt(const char* key,int d);
    void setString(const char* key,const std::string& d);
    void setString(const char* key,const char* d,size_t bufferLength);
    void setArray(const char* key,CStackArray* arr);
    void setMap(const char* key,CStackMap* map);

    bool isKeyPresent(const char* key);
    bool isNull(const char* key);
    bool isBool(const char* key);
    bool isNumber(const char* key);
    bool isString(const char* key);
    bool isArray(const char* key,size_t minSize=0);
    bool isMap(const char* key);
    bool getBool(const char* key);
    float getFloat(const char* key);
    double getDouble(const char* key);
    int getInt(const char* key);
    std::string getString(const char* key);
    CStackArray* getArray(const char* key);
    CStackMap* getMap(const char* key);

    bool contains(const char* key,int theType,size_t theMinSizeIfArray=0,bool onlyNumbersInArray=false);

    std::map<std::string,CStackObject*>* getKeyValuePairs();

protected:
    void _remove(const char* key);

    std::map<std::string,CStackObject*> _objectValues;
};
