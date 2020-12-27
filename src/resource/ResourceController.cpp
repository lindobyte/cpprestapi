#include "ResourceController.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

ResourceController::ResourceController(utility::string_t &url)
    : m_listener(url)
{
    m_listener.support(methods::GET,
                       std::bind(&ResourceController::handleRequest, this, std::placeholders::_1));
    m_listener.support(methods::PUT,
                       std::bind(&ResourceController::handleRequest, this, std::placeholders::_1));
    m_listener.support(methods::POST,
                       std::bind(&ResourceController::handleRequest, this, std::placeholders::_1));
    m_listener.support(methods::DEL,
                       std::bind(&ResourceController::handleRequest, this, std::placeholders::_1));
}

ResourceController::~ResourceController()
{
}

pplx::task<void> ResourceController::open()
{
    return m_listener.open();
}

pplx::task<void> ResourceController::close()
{
    return m_listener.close();
}

void ResourceController::handleRequest(http_request message)
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

void ResourceController::handleGet(http_request &message)
{
    ucout << message.to_string() << endl;

    //message.reply(status_codes::NotFound, "{\"key\":\"test\"}");
    message.reply(status_codes::MethodNotAllowed);
};

void ResourceController::handlePut(http_request &message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void ResourceController::handlePost(http_request &message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};

void ResourceController::handleDelete(http_request &message)
{
    ucout << message.to_string() << endl;

    message.reply(status_codes::MethodNotAllowed);
};
