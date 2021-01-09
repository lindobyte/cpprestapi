#pragma once

#include "../Webservice.hpp"
#include <unordered_set>
#include <unordered_map>
#include <string>

class MethodDescription
{
public:
    MethodDescription(int pathParamLen = 0,
                      std::unordered_set<std::string> requiredQueryParam = {},
                      std::unordered_set<std::string> optionalQueryParam = {},
                      std::unordered_set<std::string> requiredBodyParam = {},
                      std::unordered_set<std::string> optionalBodyParam = {},
                      std::unordered_set<std::string> contentType = {headerValue::applicationJson},
                      std::unordered_set<std::string> accept = {headerValue::applicationJson},
                      std::unordered_map<std::string, std::string> header = {});

    int getPathParamLen() const;
    const std::unordered_map<std::string, std::string>& getHeader() const;
    const std::unordered_set<std::string>& getRequiredQueryParam() const;
    const std::unordered_set<std::string>& getOptionalQueryParam() const;
    const std::unordered_set<std::string>& getRequiredBodyParam() const;
    const std::unordered_set<std::string>& getOptionalBodyParam() const;
    const std::unordered_set<std::string>& getContentType() const;
    const std::unordered_set<std::string>& getAccept() const;

private:
    int pathParamLen;
    std::unordered_map<std::string, std::string> header;
    std::unordered_set<std::string> requiredQueryParam;
    std::unordered_set<std::string> optionalQueryParam;
    std::unordered_set<std::string> requiredBodyParam;
    std::unordered_set<std::string> optionalBodyParam;
    std::unordered_set<std::string> contentType;
    std::unordered_set<std::string> accept;
};