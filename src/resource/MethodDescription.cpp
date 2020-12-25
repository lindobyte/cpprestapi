#include "MethodDescription.hpp"

MethodDescription::MethodDescription(enum MethodDescription::type type,
                                     int pathParamLen,
                                     std::unordered_map<std::string, std::string> header,
                                     std::unordered_set<std::string> requiredParam,
                                     std::unordered_set<std::string> optionalParam)
    : type(type),
      pathParamLen(pathParamLen),
      header(header),
      requiredParam(requiredParam),
      optionalParam(optionalParam)
{
}

const enum MethodDescription::type MethodDescription::getType() const
{
    return type;
}

int MethodDescription::getPathParamLen() const
{
    return pathParamLen;
}

const std::unordered_map<std::string, std::string>& MethodDescription::getHeader() const
{
    return header;
}

const std::unordered_set<std::string>& MethodDescription::getRequiredParam() const
{
    return requiredParam;
}

const std::unordered_set<std::string>& MethodDescription::getOptionalParam() const
{
    return optionalParam;
}
