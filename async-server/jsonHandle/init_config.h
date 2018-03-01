#ifndef _INIT_CONFIG_H
#define _INIT_CONFIG_H

#include "json/json.h"
#include <string>

enum ValueType {
  nullValue = 0, ///< 'null' value
  intValue,      ///< signed integer value
  uintValue,     ///< unsigned integer value
  realValue,     ///< double value
  stringValue,   ///< UTF-8 string value
  booleanValue,  ///< bool value
  arrayValue,    ///< array value (ordered list)
  objectValue    ///< object value (collection of name/value pairs).
};

bool init(char*, Json::Value &);
template<typename T>
bool DynamicGetValue(Json::Value &, T &&);

bool DynamicGetStrValue(Json::Value &, string &);

#endif
