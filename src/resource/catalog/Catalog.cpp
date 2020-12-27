#include "Catalog.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

utility::string_t test = "blabla";

Catalog::Catalog(uri_builder uri)
    : ResourceController(uri.append_path(U("catalog")).to_string())
    /*: ResourceController(uri.append_path(U("catalog")).to_uri().to_string()),
      getDescription(MethodDescription::type::GET),
      putDescription(MethodDescription::type::PUT),
      postDescription(MethodDescription::type::POST),
      deleteDescription(MethodDescription::type::DELETE)*/
{
}

void Catalog::handleGet(http_request &message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::NotFound, "{\"key\":\"test\",\"catalog\":\"tz\"}");
};

/*void Catalog::handle_post(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Catalog::handle_delete(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Catalog::handle_put(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};*/
