#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <unordered_map>
#include "doctest.h"
#include "Json.h"

TEST_CASE("tests for json") {
    CHECK_EQ(Json{std::unordered_map<std::string, Token>{}}.toString(), "{}");
    CHECK_EQ(Json{std::unordered_map<std::string, Token>{
                    {"int_token", NumToken(9090)},
                    {"double_token", DoubleToken(7.68)},
                    {"str_token", StrToken("hi")},
                    {"bool_token", BoolToken(true)},
{"array_token", ArrayToken({NumToken(1), StrToken("ok"), BoolToken(false)})}}}
                    .toString(),
            "{\"bool_token\":true,\"array_token\":[1,\"ok\",false],\"str_token\":\"hi\","
            "\"double_token\":7.680000,\"int_token\":9090}");

    CHECK_EQ(Json{std::unordered_map<std::string, Token>{
            {"str_token", StrToken("hello world")}}}.toString(),
             "{\"str_token\":\"hello world\"}");

    CHECK_EQ(Json{std::unordered_map<std::string, Token>{
            {"bool_token", BoolToken(false)}}}.toString(),
             "{\"bool_token\":false}");

    CHECK_EQ(Json{std::unordered_map<std::string, Token>{
            {"array_token", ArrayToken({StrToken("hello"), ArrayToken({BoolToken(true), BoolToken(false)}), StrToken("world")})}}}.toString(),
            "{\"array_token\":[\"hello\",[true,false],\"world\"]}");
}
