#include "Resource.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

Resource::Resource(utility::string_t &url)
    : m_listener(url)
{
    m_listener.support(methods::GET,
                       std::bind(&Resource::handle_get, this, std::placeholders::_1));
    m_listener.support(methods::PUT,
                       std::bind(&Resource::handle_put, this, std::placeholders::_1));
    m_listener.support(methods::POST,
                       std::bind(&Resource::handle_post, this, std::placeholders::_1));
    m_listener.support(methods::DEL,
                       std::bind(&Resource::handle_delete, this, std::placeholders::_1));
}

Resource::~Resource()
{
}

pplx::task<void> Resource::open()
{
    return m_listener.open();
}

pplx::task<void> Resource::close()
{
    return m_listener.close();
}

void Resource::handleRequest(http_request message)
{

}

void Resource::handle_get(http_request message)
{
    ucout << message.to_string() << endl;

    //message.reply(status_codes::NotFound, "{\"key\":\"test\"}");
    message.reply(status_codes::MethodNotAllowed);
};

void Resource::handle_post(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Resource::handle_delete(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Resource::handle_put(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

