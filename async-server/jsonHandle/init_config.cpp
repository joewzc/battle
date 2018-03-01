#include <iostream>
#include <fstream>
#include <string.h>
#include "init_config.h"

using namespace std;


bool init(char* path, Json::Value &value) {
    ifstream ifs;
    ifs.open(path);
    config.clear();
    Json::CharReaderBuilder builder;
    builder["collectComments"] = false;
    JSONCPP_STRING errs;
    bool result = true;

    if(!parseFromStream(builder, ifs, &value, &errs)) {
        result = false;
    }
    return result;
}

template<typename T>
bool DynamicGetValue(Json::Value &value, T &&sValue) {
    bool result = true;
    switch(value.type()) {
        case Json::stringValue:
            sValue = atof(value.asString().c_str());
            break;
        case Json::intValue:
            sValue = value.asInt();
            break;
        case Json::uintValue:
            sValue = value.asUInt();
            break;
        case Json::booleanValue:
            sValue = value.asBool();
            break;
        case Json::realValue:
            sValue = value.asDouble();
            break;
        default:
            result = false;
            break;
    }
    return result;
}

bool DynamicGetStrValue(Json::Value &value, string &sValue) {
    bool result = true;
    double nValue = -1;
    if (value.type() == Json::stringValue) {
        sValue = value.asString();
    }
    else if (DynamicGetValue<double&> (value, nValue)) {
       sprintf((char*)sValue.data(), "%.8f", nValue); 
    }
    else {
        result = false;
    }
    return result;
}
