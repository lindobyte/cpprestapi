#include "Resource.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

Resource::Resource(utility::string_t url)
    : m_listener(url)
{
    cout << "Listening for requests at: " << url << endl;

    m_listener.support(methods::GET,
                       std::bind(&Resource::handleRequest, this, std::placeholders::_1));
    m_listener.support(methods::PUT,
                       std::bind(&Resource::handleRequest, this, std::placeholders::_1));
    m_listener.support(methods::POST,
                       std::bind(&Resource::handleRequest, this, std::placeholders::_1));
    m_listener.support(methods::DEL,
                       std::bind(&Resource::handleRequest, this, std::placeholders::_1));
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
    if(message.method() ==  http::methods::GET) {
        handleGet(message);
    }
    else if(message.method() ==  http::methods::PUT) {
        handlePut(message);
    }
    else if(message.method() ==  http::methods::POST) {
        handlePost(message);
    }
    else if(message.method() ==  http::methods::DEL) {
        handleDelete(message);
    }
    else {
        /* error handling */
    }
}

void Resource::handleGet(http_request &message)
{
    ucout << message.to_string() << endl;

    //message.reply(status_codes::NotFound, "{\"key\":\"test\"}");
    message.reply(status_codes::MethodNotAllowed);
};

void Resource::handlePut(http_request &message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Resource::handlePost(http_request &message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void Resource::handleDelete(http_request &message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};
