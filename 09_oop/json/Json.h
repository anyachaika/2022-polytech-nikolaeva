#pragma once
#include <string>
#include <iostream>
#include <utility>
#include <unordered_map>

class Token {
public:
    std::string token{};
};

class NumToken : public Token {
public:
    explicit NumToken(int i) {
        token = std::to_string(i);
    }
};

class DoubleToken : public Token {
public:
    explicit DoubleToken(double d) {
        token = std::to_string(d);
    }
};

class StrToken : public Token {
public:
    explicit StrToken(std::string s) {
        token = std::move(s);
        token.append("\"");
        token.insert(0, "\"");
    }
};

class BoolToken : public Token {
public:
    explicit BoolToken(bool b) {
        token = b ? "true" : "false";
    }
};

class ArrayToken : public Token {
public:
    explicit ArrayToken(std::vector<Token> v) {
        token = "[";
        for (auto &i : v) {
            token.append(i.token);
            token.append(",");
        }
        token.pop_back();
        token.append("]");
    }
};


class Json {
public:
    std::unordered_map<std::string, Token> json{};
    explicit Json(std::unordered_map<std::string, Token> j) {
        json = std::move(j);
    }
    std::string toString() {
        std::string s = "{";
        for (auto &i : json) {
            s.append("\"");
            s.append(i.first);
            s.append("\":");
            s.append(i.second.token);
            s.append(",");
        }
        if (s.size() > 1) {
            s.pop_back();
        }
        s.append("}");
        return s;
    }
};

