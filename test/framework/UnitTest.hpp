//
// Created by kolterdyx on 1/11/22.
//

#ifndef CEMENTENGINE_UNITTEST_HPP
#define CEMENTENGINE_UNITTEST_HPP

#include <utility>
#include <functional>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "color.hpp"

struct assertionResult {
    bool assertion;
    std::string msg;

    assertionResult(bool res, std::string msg) {
        this->assertion = res;
        this->msg = std::move(msg);
    }
};

class UnitTest {
private:
    std::string name;

    std::map<std::string, std::function<void()>> _tests;

    std::vector<std::string> assertionFails;

public:
    template<class T>
    void assertEquals(T a, T b) {
        bool ret = a == b;
        if (!ret) {
            assertionFails.push_back(std::string("") + a + std::string(" != ") + b);
            throw std::exception();
        }
    };


    template<class T>
    void assertNotEquals(T a, T b) {
        bool ret = a != b;
        if (!ret) {
            assertionFails.push_back(std::string("") + a + std::string(" == ") + b);
            throw std::exception();
        }
    };

    template<class T>
    void assertGreater(T a, T b) {
        bool ret = a > b;
        if (!ret) {
            assertionFails.push_back(std::string("") + std::to_string(a) + std::string(" <= ") + std::to_string(b));
            throw std::exception();
        }
    };

    template<class T>
    void assertGreaterEqual(T a, T b) {
        bool ret = a >= b;
        if (!ret) {
            assertionFails.push_back(std::string("") + std::to_string(a) + std::string(" < ") + std::to_string(b));
            throw std::exception();
        }
    };

    template<class T>
    void assertLess(T a, T b) {
        bool ret = a < b;
        if (!ret) {
            assertionFails.push_back(std::string("") + std::to_string(a) + std::string(" >= ") + std::to_string(b));
            throw std::exception();
        }
    };

    template<class T>
    void assertLessEqual(T a, T b) {
        bool ret = a <= b;
        if (!ret) {
            assertionFails.push_back(std::string("") + std::to_string(a) + std::string(" > ") + std::to_string(b));
            throw std::exception();
        }
    };

    void assertTrue(bool expr);

    void assertFalse(bool expr);

    void addTest(const std::function<void()> &func, std::string name);

    static void print_fail(const std::basic_string<char> &string);

    static void print_pass(const std::string &test_name);

public:

    void launch();

    UnitTest(std::string name);

};


#endif //CEMENTENGINE_UNITTEST_HPP
