#include "Resource.hpp"
#include "../Const.hpp"

#include <boost/algorithm/string.hpp>

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

#define RA_CONFIG_BITMASK_IGNORE_CONTENT_TYPE 1


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
            validate(message, getDescription, RA_CONFIG_BITMASK_IGNORE_CONTENT_TYPE);
            handleGet(message);
        }
        else if(message.method() ==  http::methods::PUT) {
            validate(message, putDescription);
            handlePut(message);
        }
        else if(message.method() ==  http::methods::POST) {
            validate(message, postDescription);
            handlePost(message);
        }
        else if(message.method() ==  http::methods::DEL) {
            validate(message, deleteDescription);
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

void Resource::validateSpecifiedHeader(const web::http::http_headers &request_header,
                                       const std::string &key,
                                       const std::string &value)
{
    web::http::http_headers::const_iterator it;

    it = request_header.find(key);
    if(it != request_header.end()) {
        if(!boost::iequals(it->second, value)) {
            throw invalid_argument("Header <" + key + ":" + it->second + "> is invalid, " +
                                   "expected <" + key + ":" + value + ">");
        }
    }
    else {
        throw invalid_argument("Header key <" + key + "> is not available");
    }
}

void Resource::validateContentType(const web::http::http_headers &request_header,
                                   const std::unordered_set<std::string> &contentTypes)
{
    for(const auto &contentType : contentTypes) {
        validateSpecifiedHeader(request_header, headerKey::contentType, contentType);
    }
}

void Resource::validateAccept(const web::http::http_headers &request_header,
                              const std::unordered_set<std::string> &accepts)
{
    for(const auto &accept : accepts) {
        validateSpecifiedHeader(request_header, headerKey::accept, accept);
    }
}

void Resource::validateHeader(const web::http::http_headers &request_header,
                              const std::unordered_map<std::string, std::string> &desc_header)
{
    for(const auto &elem : desc_header) {
        validateSpecifiedHeader(request_header, elem.first, elem.second);
    }
}

void Resource::validate(web::http::http_request &message,
                        MethodDescription &description,
                        uint16_t configBitmask)
{
    if(description.isInitialized()) {
        validateHeader(message.headers(), description.getHeader());
        validateAccept(message.headers(), description.getAccept());
        if(!(configBitmask & RA_CONFIG_BITMASK_IGNORE_CONTENT_TYPE)) {
            validateContentType(message.headers(), description.getContentType());
        }
    }
}