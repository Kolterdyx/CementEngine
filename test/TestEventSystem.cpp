#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "../Core/Events/Event.hpp"
#include "../Core/Events/EventDispatcher.hpp"


int i = 0;

std::string test;
using namespace Cement;

struct TestEvent1 : public Event {
public:
    TestEvent1(int i) : i(i) {}
    int i;
};

struct TestEvent2 : public Event {

public:
    TestEvent2(std::string s) : s(s) {}
    std::string s;
};

struct handler {
    void receive(const TestEvent1 &event) {
        i = event.i;
    }

    void receive2(const TestEvent2 &event) {
        test = event.s;
    }
};

TEST_CASE("Test the Event System", "[Event IEntitySystem]") {

    i = 0;
    test = "";

    EventDispatcher dispatcher;


    SECTION("Test basic event subscription") {
        handler h;
        dispatcher.sink<TestEvent2>().connect<&handler::receive2>(h);

        dispatcher.emit<TestEvent2>("Hello");

        REQUIRE(test == "Hello");
        REQUIRE(i == 0);
    }

    SECTION("Test proper event dispatching") {
        handler h;
        dispatcher.sink<TestEvent2>().connect<&handler::receive2>(h);
        dispatcher.emit<TestEvent1>(1);

        REQUIRE(test == "");
        REQUIRE(i == 0);


        dispatcher.sink<TestEvent1>().connect<&handler::receive>(h);


        dispatcher.emit<TestEvent1>(1);
        dispatcher.emit<TestEvent2>("Hello");

        REQUIRE(test == "Hello");
        REQUIRE(i == 1);

        dispatcher.emit<TestEvent1>(2);
        dispatcher.emit<TestEvent2>("world");

        REQUIRE(test == "world");
        REQUIRE(i == 2);
    }


}

