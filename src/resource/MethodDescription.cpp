#include "MethodDescription.hpp"

MethodDescription::MethodDescription(int pathParamLen,
                                     std::unordered_set<std::string> requiredParam,
                                     std::unordered_set<std::string> optionalParam,
                                     std::unordered_map<std::string, std::string> header)
    : pathParamLen(pathParamLen),
      header(header),
      requiredParam(requiredParam),
      optionalParam(optionalParam)
{
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
