#include "Customer.h"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

Customer::Customer(utility::string_t url) : m_listener(url)
{
    m_listener.support(methods::GET, std::bind(&Customer::handle_get, this, std::placeholders::_1));
    m_listener.support(methods::PUT, std::bind(&Customer::handle_put, this, std::placeholders::_1));
    m_listener.support(methods::POST, std::bind(&Customer::handle_post, this, std::placeholders::_1));
    m_listener.support(methods::DEL, std::bind(&Customer::handle_delete, this, std::placeholders::_1));
}

//
// A GET of the dealer resource produces a list of existing tables.
//
void Customer::handle_get(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::NotFound, "{\"key\":\"test\"}");
};

//
// A POST of the dealer resource creates a new table and returns a resource for
// that table.
//
void Customer::handle_post(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::NotFound);
};

//
// A DELETE of the player resource leaves the table.
//
void Customer::handle_delete(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::NotFound);
};

//
// A PUT to a table resource makes a card request (hit / stay).
//
void Customer::handle_put(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::NotFound);
};