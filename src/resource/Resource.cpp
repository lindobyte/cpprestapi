#include "Resource.hpp"

#include <boost/algorithm/string.hpp>

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
    try {
        if(message.method() ==  http::methods::GET) {
            validate(message, getDescription);
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
            message.reply(status_codes::MethodNotAllowed);
        }
    }
    catch (const std::invalid_argument& ia) {
        message.reply(status_codes::BadRequest,
                      std::string("{\"errorMsg\": \"") + ia.what() + std::string("\"}"));
    }
}

void Resource::handleGet(http_request &message)
{
    ucout << message.to_string() << endl;

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

void Resource::validateHeader(const web::http::http_headers &request_header,
                              const std::unordered_map<std::string, std::string> &desc_header)
{
    for(const auto &elem : desc_header) {
        web::http::http_headers::const_iterator it;

        it = request_header.find(elem.first);
        if(it != request_header.end()) {
            if(!boost::iequals(it->second, elem.second)) {
                throw invalid_argument("Header <" + elem.first + ":" + it->second + "> is invalid,"
                                       + " expected <" + elem.first + ":" + elem.second + ">");
            }
        }
        else {
            throw invalid_argument("Header key <" + elem.first + "> is not available");
        }
    }
}

void Resource::validate(web::http::http_request &message,
                        MethodDescription &description)
{
    validateHeader(message.headers(), description.getHeader());
}