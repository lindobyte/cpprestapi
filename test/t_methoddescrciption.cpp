#include <gtest/gtest.h>
#include "../src/resource/MethodDescription.hpp"

using namespace std;

TEST(methodDescription, standardValues)
{
    MethodDescription m;
    EXPECT_FALSE(m.isInitialized());

    MethodDescription method(0);
    EXPECT_TRUE(method.isInitialized());

    int pathParamLen;
    pathParamLen = method.getPathParamLen();
    EXPECT_EQ(pathParamLen, 0);

    const unordered_map<string, string> header = method.getHeader();
    ASSERT_EQ(header.size(), 0);

    const unordered_set<string> requiredQueryParam = method.getRequiredQueryParam();
    EXPECT_TRUE(requiredQueryParam.empty());
    const unordered_set<string> optionalQueryParam = method.getOptionalQueryParam();
    EXPECT_TRUE(optionalQueryParam.empty());

    const unordered_set<string> requiredBodyParam = method.getRequiredBodyParam();
    EXPECT_TRUE(requiredBodyParam.empty());
    const unordered_set<string> optionalBodyParam = method.getOptionalBodyParam();
    EXPECT_TRUE(optionalBodyParam.empty());

    const unordered_set<string> accept = method.getAccept();
    ASSERT_EQ(accept.size(), 1);
    EXPECT_EQ(accept.count(headerValue::applicationJson), 1);

    const unordered_set<string> contentType = method.getContentType();
    ASSERT_EQ(contentType.size(), 1);
    EXPECT_EQ(contentType.count(headerValue::applicationJson), 1);
}

TEST(methodDescription, specifiedValues)
{
    MethodDescription method(2,
                             {"param1","param2","param3", "param1"},
                             {"oparam1", "oparam2"},
                             {"bparam1","bparam2","bparam3", "bparam1"},
                             {"boparam1", "boparam2"},
                             {"contentJson", "contentXml"},
                             {"acceptJson", "acceptXml"},
                             {{"key1", "value1"},{"key2","value2"}});

    EXPECT_EQ(method.getPathParamLen(), 2);

    const unordered_map<string, string> header = method.getHeader();
    ASSERT_EQ(header.size(), 2);
    EXPECT_EQ(header.at("key1"), "value1");
    EXPECT_EQ(header.at("key2"), "value2");

    const unordered_set<string> requiredQueryParam = method.getRequiredQueryParam();
    ASSERT_EQ(requiredQueryParam.size(), 3);
    EXPECT_EQ(requiredQueryParam.count("param1"), 1);
    EXPECT_EQ(requiredQueryParam.count("param2"), 1);
    EXPECT_EQ(requiredQueryParam.count("param3"), 1);
    EXPECT_EQ(requiredQueryParam.count("param"),  0);

    const unordered_set<string> optionalQueryParam = method.getOptionalQueryParam();
    ASSERT_EQ(optionalQueryParam.size(), 2);
    EXPECT_EQ(optionalQueryParam.count("oparam1"), 1);
    EXPECT_EQ(optionalQueryParam.count("oparam2"), 1);
    EXPECT_EQ(optionalQueryParam.count("oparam"),  0);

    const unordered_set<string> requiredBodyParam = method.getRequiredBodyParam();
    ASSERT_EQ(requiredBodyParam.size(), 3);
    EXPECT_EQ(requiredBodyParam.count("bparam1"), 1);
    EXPECT_EQ(requiredBodyParam.count("bparam2"), 1);
    EXPECT_EQ(requiredBodyParam.count("bparam3"), 1);
    EXPECT_EQ(requiredBodyParam.count("bparam"),  0);

    const unordered_set<string> optionalBodyParam = method.getOptionalBodyParam();
    ASSERT_EQ(optionalBodyParam.size(), 2);
    EXPECT_EQ(optionalBodyParam.count("boparam1"), 1);
    EXPECT_EQ(optionalBodyParam.count("boparam2"), 1);
    EXPECT_EQ(optionalBodyParam.count("boparam"),  0);

    const unordered_set<string> contentType = method.getContentType();
    ASSERT_EQ(contentType.size(), 2);
    EXPECT_EQ(contentType.count("contentJson"), 1);
    EXPECT_EQ(contentType.count("contentXml"), 1);

    const unordered_set<string> accept = method.getAccept();
    ASSERT_EQ(accept.size(), 2);
    EXPECT_EQ(accept.count("acceptJson"), 1);
    EXPECT_EQ(accept.count("acceptXml"), 1);
}


