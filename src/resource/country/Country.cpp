#include "Country.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

Country::Country(uri_builder uri)
    : Resource(uri.append_path(U("country")).to_string())
    /*: Resource(uri.append_path(U("Country")).to_uri().to_string()),
      getDescription(MethodDescription::type::GET),
      putDescription(MethodDescription::type::PUT),
      postDescription(MethodDescription::type::POST),
      deleteDescription(MethodDescription::type::DELETE)*/
{
    getDescription = MethodDescription(1);
}

void Country::handleGet(http_request &message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::OK, "{\"key\":\"test\",\"Country\":\"tz\"}");
};

/*void Country::handle_post(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Country::handle_delete(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Country::handle_put(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};*/
