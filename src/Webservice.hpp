#pragma once

#include "Const.hpp"

#include <cpprest/asyncrt_utils.h>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/uri.h>
#include <list>

class Resource;

class Webservice
{
public:
    Webservice(utility::string_t &address,
               utility::string_t &port);

    void initialize();

    void shutdown();
private:
    utility::string_t address;
    std::list<std::shared_ptr<Resource>> resourceList;
};
