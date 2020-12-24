#pragma once

#include "../../Webservice.hpp"
#include "../Resource.hpp"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

class Customer : public Resource
{
public:
    //Customer() {}
    Customer(utility::string_t url);

private:
    void handle_get(http_request message);
    /*void handle_put(http_request message);
    void handle_post(http_request message);
    void handle_delete(http_request message);*/

    //http_listener m_listener;
};
