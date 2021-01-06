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
        std::cout << "TEST" << std::endl;
    };

private:
    void handleGet(web::http::http_request &message)
    {
        ucout << message.to_string() << endl;

        message.reply(status_codes::OK, "{\"key\":\"test\",\"Country\":\"tz\"}");
    };
    /*void handle_put(http_request message);
    void handle_post(http_request message);
    void handle_delete(http_request message);*/
};

}

TEST(resource, validate)
{
#if 0
    uri_builder uri("http://localhost:8885");
    http_request request;
    http_headers headers = request.headers();

    headers.set_content_type(headerValue::applicationJson);
    headers.add(headerKey::accept, headerValue::applicationJson);

    ucout << "content type: " << headers.content_type() << endl;

    //request.set_he
    ucout << " request content type: " << request.headers().content_type() << endl;

    //request.get
    testws::Testws testws(uri);

    ASSERT_NO_THROW(testws.handleRequest(request));
    pplx::task<http_response> taskResponse = request.get_response();
    http_response response = taskResponse.get();

    ucout << "RESPONSE: " << response.to_string() << endl;
#endif
}