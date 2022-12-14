#include "../Core/EventSystem/EventSystem.hpp"
#include "catch2/catch_test_macros.hpp"


int i = 0;

std::string test;

using namespace Cement;

class TestEvent1 : public Event {
public:
    constexpr static const EventType type = "Test 1";

    EventType getType() const {
        return type;
    }
};

class TestEvent2 : public Event {
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

void testHandler1(const Event &e) {
    i++;
}

void testHandler2(const Event &e) {
    const TestEvent2 &event = dynamic_cast<const TestEvent2 &>(e);
    test = event.msg;
}

TEST_CASE("Test the Event System", "[Event IEntitySystem]") {

    i = 0;
    test = "";

    EventDispatcher dispatcher;

    SECTION("Test basic event subscription") {
        dispatcher.subscribe("Test 1", [](const Event &e) { testHandler1(e); });
        dispatcher.subscribe("Test 2", [](const Event &e) { testHandler2(e); });

        dispatcher.post(TestEvent2("Hello"));

        REQUIRE(test == "Hello");
        REQUIRE(i == 0);
    }

    SECTION("Test proper event dispatching") {

        dispatcher.subscribe("Test 2", [](const Event &e) { testHandler2(e); });
        dispatcher.post(TestEvent1());

        REQUIRE(test == "");
        REQUIRE(i == 0);

        dispatcher.subscribe("Test 1", [](const Event &e) { testHandler1(e); });

        dispatcher.post(TestEvent1());
        dispatcher.post(TestEvent2("Hello"));

        REQUIRE(test == "Hello");
        REQUIRE(i == 1);

        dispatcher.subscribe("Test 1", [](const Event &e) { testHandler1(e); });
        dispatcher.post(TestEvent1());
        dispatcher.post(TestEvent2("world"));

        REQUIRE(test == "world");
        REQUIRE(i == 3);
    }


}

