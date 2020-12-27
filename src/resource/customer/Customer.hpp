#pragma once

#include "../../Webservice.hpp"
#include "../ResourceController.hpp"
#include "../MethodDescription.hpp"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

class Customer : public ResourceController
{
public:
    //Customer() {}
    Customer(utility::string_t url);

private:
    void handleGet(http_request &message);
    /*void handle_put(http_request message);
    void handle_post(http_request message);
    void handle_delete(http_request message);*/

    MethodDescription getDescription;
    MethodDescription putDescription;
    MethodDescription postDescription;
    MethodDescription deleteDescription;

    //http_listener m_listener;
};
