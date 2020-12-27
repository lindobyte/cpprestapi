#pragma once

#include "../Webservice.hpp"
#include <unordered_set>
#include <unordered_map>
#include <string>

class MethodDescription
{
public:
    MethodDescription(int pathParamLen = 0,
                      std::unordered_map<std::string, std::string> header = {
                          {headerKey::contentType, headerValue::applicationJson},
                          {headerKey::accept,      headerValue::applicationJson}
                      },
                      std::unordered_set<std::string> requiredParam = {},
                      std::unordered_set<std::string> optionalParam = {});

    int getPathParamLen() const;
    const std::unordered_map<std::string, std::string>& getHeader() const;
    const std::unordered_set<std::string>& getRequiredParam() const;
    const std::unordered_set<std::string>& getOptionalParam() const;

private:
    int pathParamLen;
    std::unordered_map<std::string, std::string> header;
    std::unordered_set<std::string> requiredParam;
    std::unordered_set<std::string> optionalParam;
};