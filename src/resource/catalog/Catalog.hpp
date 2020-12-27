#pragma once

#include "../../Webservice.hpp"
#include "../ResourceController.hpp"
#include "../MethodDescription.hpp"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

class Catalog : public ResourceController
{
public:
    Catalog(uri_builder uri);

private:
    void handleGet(http_request &message);
    /*void handle_put(http_request message);
    void handle_post(http_request message);
    void handle_delete(http_request message);*/
};
