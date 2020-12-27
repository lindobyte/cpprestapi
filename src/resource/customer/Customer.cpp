#include "Customer.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

Customer::Customer(uri_builder uri)
    : Resource(uri.append_path(U("customer")).to_string())/*,
      getDescription(MethodDescription::type::GET),
      putDescription(MethodDescription::type::PUT),
      postDescription(MethodDescription::type::POST),
      deleteDescription(MethodDescription::type::DELETE)*/
{
}

void Customer::handleGet(http_request &message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::NotFound, "{\"key\":\"test\",\"customer\":\"tz\"}");
};

/*void Customer::handle_post(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Customer::handle_delete(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Customer::handle_put(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};*/
