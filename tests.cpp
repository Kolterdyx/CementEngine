#include "Core/EventSystem/EventSystem.hpp"
#include "catch2/catch_test_macros.hpp"

int i = 0;

std::string test;

class TestEvent1 : public BaseEvent {
public:
    constexpr static const EventType type = "Test 1";

    EventType getType() const {
        return type;
    }
};

class TestEvent2 : public BaseEvent {
public:
    constexpr static const EventType type = "Test 2";

    EventType getType() const {
        return type;
    }

    std::string msg;

    explicit TestEvent2(std::string msg) {
        this->msg = msg;
    }
};

void testHandler1(const BaseEvent &e) {
    i++;
}

void testHandler2(const BaseEvent &e) {
    const TestEvent2 &event = dynamic_cast<const TestEvent2 &>(e);
    test = event.msg;
}

TEST_CASE("Test the Event system", "[Event System]") {
    EventDispatcher dispatcher;

    SECTION("Test basic event subscription") {
        dispatcher.subscribe("Test 1", [](const BaseEvent& e) { testHandler1(e); });
        dispatcher.subscribe("Test 2", [](const BaseEvent& e) { testHandler2(e); });

        dispatcher.post(TestEvent2("Hello"));

        REQUIRE( test == "Hello" );
        REQUIRE( i == 0 );
    }

    SECTION("Test proper event dispatching") {
        dispatcher.post(TestEvent1());

        REQUIRE( test == "Hello" );
        REQUIRE( i == 1 );

        dispatcher.subscribe("Test 1", [](const BaseEvent &e) { testHandler1(e); });
        dispatcher.subscribe("Test 1", [](const BaseEvent &e) { testHandler1(e); });

        dispatcher.post(TestEvent1());

        REQUIRE(test == "Hello");
        REQUIRE(i == 4);


        dispatcher.post(TestEvent2("world"));

        REQUIRE( test == "world" );
        REQUIRE( i == 4 );
    }


}

