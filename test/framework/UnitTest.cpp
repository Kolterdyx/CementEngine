//
// Created by kolterdyx on 1/11/22.
//

#include "UnitTest.hpp"

#include <utility>


void UnitTest::addTest(const std::function<void()> &func, std::string name) {
    _tests[std::move(name)] = func;
}

void UnitTest::launch() {
    std::cout << DYE_YELLOW("Running tests for: ") << DYE_WHITE(name) << std::endl;
    int passed = 0;
    for (auto &&test: _tests) {
        try {
            test.second();
        } catch(std::exception& e) {
            assertionFails.push_back(e.what());
            print_fail(test.first);
            continue;
        }
        passed++;
        print_pass(test.first);
    }
    for (auto error : assertionFails) {
        std::cout << DYE_RED(error) << std::endl;
    }
    std::cout << DYE_YELLOW("Passed ") << DYE_WHITE(std::to_string(passed)) << DYE_YELLOW(" tests out of ") << DYE_WHITE(std::to_string(_tests.size())) << std::endl;
}


void UnitTest::assertTrue(const bool expr) {
    bool ret = expr;
    if (!ret) {
        assertionFails.push_back("false");
        throw std::exception();
    }
}

void UnitTest::assertFalse(const bool expr) {
    bool ret = !expr;
    if (!ret) {
        assertionFails.push_back("true");
        throw std::exception();
    }
}

void UnitTest::print_fail(const std::string& test_name) {
    std::cout << DYE_YELLOW("[") << DYE_RED("FAIL") << DYE_YELLOW("] ") << test_name << std::endl;
}

void UnitTest::print_pass(const std::string& test_name) {
    std::cout << DYE_YELLOW("[") << DYE_GREEN("PASS") << DYE_YELLOW("] ") << test_name << std::endl;
}

UnitTest::UnitTest(std::string name) {
    this->name = std::move(name);
}
