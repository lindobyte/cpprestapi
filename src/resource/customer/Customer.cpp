#include "Customer.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

Customer::Customer(utility::string_t url)
    : ResourceController(url)/*,
      getDescription(MethodDescription::type::GET),
      putDescription(MethodDescription::type::PUT),
      postDescription(MethodDescription::type::POST),
      deleteDescription(MethodDescription::type::DELETE)*/
{
    /*m_listener.support(methods::GET, std::bind(&Customer::handle_get, this, std::placeholders::_1));
    m_listener.support(methods::PUT, std::bind(&Customer::handle_put, this, std::placeholders::_1));
    m_listener.support(methods::POST, std::bind(&Customer::handle_post, this, std::placeholders::_1));
    m_listener.support(methods::DEL, std::bind(&Customer::handle_delete, this, std::placeholders::_1));*/
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
