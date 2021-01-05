#pragma once

#include "../../Webservice.hpp"
#include "../Resource.hpp"
#include "../MethodDescription.hpp"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

class Country : public Resource
{
public:
    Country(uri_builder uri);

private:
    void handleGet(http_request &message);
    /*void handle_put(http_request message);
    void handle_post(http_request message);
    void handle_delete(http_request message);*/
};
