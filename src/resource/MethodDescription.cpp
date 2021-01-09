#include "MethodDescription.hpp"

MethodDescription::MethodDescription(int pathParamLen,
                                     std::unordered_set<std::string> requiredQueryParam,
                                     std::unordered_set<std::string> optionalQueryParam,
                                     std::unordered_set<std::string> requiredBodyParam,
                                     std::unordered_set<std::string> optionalBodyParam,
                                     std::unordered_set<std::string> contentType,
                                     std::unordered_set<std::string> accept,
                                     std::unordered_map<std::string, std::string> header)
    : pathParamLen(pathParamLen),
      requiredQueryParam(requiredQueryParam),
      optionalQueryParam(optionalQueryParam),
      requiredBodyParam(requiredBodyParam),
      optionalBodyParam(optionalBodyParam),
      contentType(contentType),
      accept(accept),
      header(header)
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

const std::unordered_set<std::string>& MethodDescription::getRequiredQueryParam() const
{
    return requiredQueryParam;
}

const std::unordered_set<std::string>& MethodDescription::getOptionalQueryParam() const
{
    return optionalQueryParam;
}

const std::unordered_set<std::string>& MethodDescription::getRequiredBodyParam() const
{
    return requiredBodyParam;
}

const std::unordered_set<std::string>& MethodDescription::getOptionalBodyParam() const
{
    return optionalBodyParam;
}

const std::unordered_set<std::string>& MethodDescription::getContentType() const
{
    return contentType;
}

const std::unordered_set<std::string>& MethodDescription::getAccept() const
{
    return accept;
}
