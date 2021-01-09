#include <gtest/gtest.h>
#include "../src/resource/Resource.hpp"
#include "../src/Const.hpp"

using namespace web::http;
using namespace std;

namespace testws {

class Testws : public Resource
{
public:
    Testws(web::uri_builder uri)
        : Resource(uri.append_path(U("testws")).to_string())
    {
        getDescription = MethodDescription(1,{},{},{},{},{},{});
    };

private:
    void handleGet(web::http::http_request &message)
    {
        ucout << message.to_string() << endl;

        message.reply(status_codes::OK, "{\"key\":\"test\",\"country\":\"de\"}");
    };
    /*void handle_put(http_request message);
    void handle_post(http_request message);
    void handle_delete(http_request message);*/
};

}

TEST(validate, pathParameter)
{
    uri_builder uri("http://localhost:8885");
    uri_builder uri_request("http://localhost:8885/testws/2506");
    http_request request;

    request.set_method(web::http::methods::GET);
    request.set_request_uri(uri_request.to_uri());

    /* check with 1 path parameter */
    testws::Testws testws1(uri);
    ASSERT_NO_THROW(testws1.handleRequest(request));

    pplx::task<http_response> taskResponse = request.get_response();
    ASSERT_TRUE(taskResponse.is_done());

    http_response response = taskResponse.get();
    EXPECT_EQ(response.status_code(), web::http::status_codes::OK);

    pplx::task<web::json::value> taskJson = response.extract_json(true);
    taskJson.then([=](pplx::task<web::json::value> task)
    {
        web::json::value json = task.get();

        ASSERT_TRUE(json.is_object());
        ASSERT_ANY_THROW(json.at("invalidKey"));

        ASSERT_NO_THROW(json.at("key"));
        EXPECT_EQ(json.at("key").as_string(), "test");

        ASSERT_NO_THROW(json.at("country"));
        EXPECT_EQ(json.at("country").as_string(), "de");
    });
}

TEST(validate, pathParameterInvalid)
{
    uri_builder uri("http://localhost:8885");
    uri_builder uri_request("http://localhost:8885/testws/2506/1980");
    http_request request;

    request.set_method(web::http::methods::GET);
    request.set_request_uri(uri_request.to_uri());

    testws::Testws testws1(uri);
    ASSERT_NO_THROW(testws1.handleRequest(request));

    pplx::task<http_response> taskResponse = request.get_response();

    /* callback function for request.get_response() */
    taskResponse.then([=](pplx::task<web::http::http_response> task)
    {
        web::http::http_response  response = task.get();

        EXPECT_EQ(response.status_code(), web::http::status_codes::BadRequest);
    });
}