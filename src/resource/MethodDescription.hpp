#pragma once

#include <set>
#include <string>
#include <unordered_map>

class MethodDescription
{
public:
    //method (string), header (hash), requiredParameter (set), optionalParameter (set), pathParamLen (int)
    MethodDescription(std::string type,
                      int pathParamLen,
                      std::unordered_map<std::string, std::string> header,
                      std::set<std::string> requiredParam,
                      std::set<std::string> optionalParam);

    std::string getType() const;
    int getPathParamLen() const;
    std::unordered_map<std::string, std::string> getHeader() const;
    std::set<std::string> getRequiredParam() const;
    std::set<std::string> getOptionalParam() const;

private:
    std::string type;
    int pathParamLen;
    std::unordered_map<std::string, std::string> header;
    std::set<std::string> requiredParam;
    std::set<std::string> optionalParam;
};