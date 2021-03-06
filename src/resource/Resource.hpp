#pragma once

#include "../Webservice.hpp"
#include "MethodDescription.hpp"

class Resource
{
public:
    Resource(utility::string_t url);
    ~Resource();

    void handleRequest(web::http::http_request message);

    pplx::task<void> open();
    pplx::task<void> close();

protected:
    MethodDescription getDescription;
    MethodDescription putDescription;
    MethodDescription postDescription;
    MethodDescription deleteDescription;

    virtual void handleGet(web::http::http_request &message);
    virtual void handlePut(web::http::http_request &message);
    virtual void handlePost(web::http::http_request &message);
    virtual void handleDelete(web::http::http_request &message);

    virtual void validate(web::http::http_request &message,
                          MethodDescription &description,
                          uint16_t configBitmask = 0);

#if 0
    /// It validates required information into the Http headers.
    virtual void handleHttpHeaders(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

    /**
     * @param payload The string containing the Json data.
     * @return Only part of the payload with attributes in Poco Json Object format.
     */
    Poco::JSON::Object::Ptr getJsonAttributesSectionObject(const std::string &);

    /*!
        * It validates a set of parameters have been set in a Json payload.
        *
        * @param jsonObject        Poco Json Object that contains payload data.
        * @param attributesNames   Attributes list to be validated.
        */
    void assertPayloadAttributes(const Poco::JSON::Object::Ptr &, const std::list<std::string> &);

    /*!
        * It sets all the HTTP Response information based on the HTTP Code.
        *
        * @param statusCode    The HTTP Status Code.
        * @param response      Response to be handled.
        */
    void handleHttpStatusCode(int statusCode, Poco::Net::HTTPServerResponse &);

    /*!
        * @param fragment Part that it wishes to add to a URL.
        * @return A complete URL with a fragment added to its end.
        */
    std::string getUrl(const std::string & fragment);

    /*!
        * It converts an exception to Json API format.
        *
        * @param exception The exception thrown.
        * @return The exception Json API formatted.
        */
    std::string toJson(const Exception &);

    /*!
        * @param name The parameter name.
        * @return The parameter value.
        */
    std::string getQueryParameter(const std::string &);
#endif


private:
    web::http::experimental::listener::http_listener m_listener;

    void validateSpecifiedHeader(const web::http::http_headers &request_header,
                                 const std::string &key,
                                 const std::string &value);
    void validateContentType(const web::http::http_headers &request_header,
                             const std::unordered_set<std::string> &contentTypes);
    void validateAccept(const web::http::http_headers &request_header,
                        const std::unordered_set<std::string> &accepts);
    void validateHeader(const web::http::http_headers &request_header,
                        const std::unordered_map<std::string, std::string> &desc_header);

    void validatePathParameter(const web::uri &request_uri,
                               MethodDescription &description);

    /*std::string baseUrl;
    std::string requestURI;
    std::string requestHost;
    Poco::URI::QueryParameters queryStringParameters;*/

};