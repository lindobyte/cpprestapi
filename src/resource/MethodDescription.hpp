#pragma once

#include "../Webservice.hpp"
#include <unordered_set>
#include <unordered_map>
#include <string>

class MethodDescription
{
public:
    enum class type {
        GET,
        PUT,
        POST,
        DELETE
    };

    //method (string), header (hash), requiredParameter (set), optionalParameter (set), pathParamLen (int)
    MethodDescription(enum MethodDescription::type type,
                      int pathParamLen = 0,
                      std::unordered_map<std::string, std::string> header = {
                          {header::key::contentType, header::value::applicationJson},
                          {header::key::accept,      header::value::applicationJson}
                      },
                      std::unordered_set<std::string> requiredParam = {},
                      std::unordered_set<std::string> optionalParam = {});

    const enum MethodDescription::type getType() const;
    int getPathParamLen() const;
    const std::unordered_map<std::string, std::string>& getHeader() const;
    const std::unordered_set<std::string>& getRequiredParam() const;
    const std::unordered_set<std::string>& getOptionalParam() const;

private:
    MethodDescription::type type;
    int pathParamLen;
    std::unordered_map<std::string, std::string> header;
    std::unordered_set<std::string> requiredParam;
    std::unordered_set<std::string> optionalParam;
};