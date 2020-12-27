#include <gtest/gtest.h>
#include "../src/resource/MethodDescription.hpp"

using namespace std;

TEST(methodDescription, standardValues)
{
    int pathParamLen;

    MethodDescription method;

    pathParamLen = method.getPathParamLen();
    EXPECT_EQ(pathParamLen, 0);

    const unordered_map<string, string> header = method.getHeader();
    ASSERT_EQ(header.size(), 2);
    EXPECT_EQ(header.at(headerKey::contentType), headerValue::applicationJson);
    EXPECT_EQ(header.at(headerKey::accept),      headerValue::applicationJson);

    const unordered_set<string> requiredParam = method.getRequiredParam();
    EXPECT_TRUE(requiredParam.empty());

    const unordered_set<string> optionalParam = method.getOptionalParam();
    EXPECT_TRUE(optionalParam.empty());
}

TEST(methodDescription, specifiedValues)
{
    MethodDescription method(2,
                             {{"key1", "value1"},{"key2","value2"}},
                             {"param1","param2","param3", "param1"},
                             {"oparam1", "oparam2"});

    EXPECT_EQ(method.getPathParamLen(), 2);

    const unordered_map<string, string> header = method.getHeader();
    ASSERT_EQ(header.size(), 2);
    EXPECT_EQ(header.at("key1"), "value1");
    EXPECT_EQ(header.at("key2"), "value2");

    const unordered_set<string> requiredParam = method.getRequiredParam();
    ASSERT_EQ(requiredParam.size(), 3);
    EXPECT_EQ(requiredParam.count("param1"), 1);
    EXPECT_EQ(requiredParam.count("param2"), 1);
    EXPECT_EQ(requiredParam.count("param3"), 1);
    EXPECT_EQ(requiredParam.count("param"),  0);

    const unordered_set<string> optionalParam = method.getOptionalParam();
    ASSERT_EQ(optionalParam.size(), 2);
    EXPECT_EQ(optionalParam.count("oparam1"), 1);
    EXPECT_EQ(optionalParam.count("oparam2"), 1);
    EXPECT_EQ(optionalParam.count("oparam"),  0);
}


