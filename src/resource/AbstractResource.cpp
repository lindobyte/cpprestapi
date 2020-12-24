#include "AbstractResource.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

AbstractResource::AbstractResource(utility::string_t &url)
    : m_listener(url)
{
    m_listener.support(methods::GET,
                       std::bind(&AbstractResource::handle_get, this, std::placeholders::_1));
    m_listener.support(methods::PUT,
                       std::bind(&AbstractResource::handle_put, this, std::placeholders::_1));
    m_listener.support(methods::POST,
                       std::bind(&AbstractResource::handle_post, this, std::placeholders::_1));
    m_listener.support(methods::DEL,
                       std::bind(&AbstractResource::handle_delete, this, std::placeholders::_1));
}

AbstractResource::~AbstractResource()
{
}

pplx::task<void> AbstractResource::open()
{
    return m_listener.open();
}

pplx::task<void> AbstractResource::close()
{
    return m_listener.close();
}

void AbstractResource::handleRequest(http_request message)
{

}

void AbstractResource::handle_get(http_request message)
{
    ucout << message.to_string() << endl;

    //message.reply(status_codes::NotFound, "{\"key\":\"test\"}");
    message.reply(status_codes::MethodNotAllowed);
};

void AbstractResource::handle_post(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void AbstractResource::handle_delete(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void AbstractResource::handle_put(http_request message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

