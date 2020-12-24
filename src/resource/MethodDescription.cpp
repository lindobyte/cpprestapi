#include "MethodDescription.h"

MethodDescription::MethodDescription(std::string type,
                                     int pathParamLen,
                                     std::unordered_map<std::string, std::string> header,
                                     std::set<std::string> requiredParam,
                                     std::set<std::string> optionalParam)
    : type(type),
      pathParamLen(pathParamLen),
      header(header),
      requiredParam(requiredParam),
      optionalParam(optionalParam)
{

}

std::string MethodDescription::getType() const
{
    return type;
}

int MethodDescription::getPathParamLen() const
{
    return pathParamLen;
}

std::unordered_map<std::string, std::string> MethodDescription::getHeader() const
{
    return header;
}

std::set<std::string> MethodDescription::getRequiredParam() const
{
    return requiredParam;
}

std::set<std::string> MethodDescription::getOptionalParam() const
{
    return optionalParam;
}
