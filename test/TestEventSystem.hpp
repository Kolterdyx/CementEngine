//
// Created by kolterdyx on 1/11/22.
//

#ifndef CEMENTENGINE_TESTEVENTSYSTEM_HPP
#define CEMENTENGINE_TESTEVENTSYSTEM_HPP


#include "framework/UnitTest.hpp"
#include "../Core/EventSystem/EventSystem.hpp"

class TestEvent : public BaseEvent {

public:
    std::string msg;


    // Unique identifier
    static constexpr EventType event_type = "TestEvent";


    EventType type() const override {
        return event_type;
    };


    // Constructor that takes some data
    TestEvent(std::string msg) {
        this->msg = msg;
    }


};

class TestEventSystem : public UnitTest {


    void test_post_event() {
        EventDispatcher dispatcher;

        dispatcher.post(TestEvent("yeet"));
    };

    void test_subscribe_callback() {
        EventDispatcher dispatcher;

        dispatcher.subscribe("TestEvent", [](const BaseEvent &e) {
            std::cout << "Caught event of type: " << e.type() << std::endl;
        });
    };

    void test_handle_event() {
        EventDispatcher dispatcher;

        dispatcher.subscribe("TestEvent", [this](const BaseEvent &e) { handler_test(e); });

        dispatcher.post(TestEvent("yeet"));

        assertEquals(this->event_value, std::string("yeet"));
    };

    void test_multiple_callbacks() {
        EventDispatcher dispatcher;

        dispatcher.subscribe("TestEvent", [this](const BaseEvent &e) { handler_test2(e); });
        dispatcher.subscribe("TestEvent", [this](const BaseEvent &e) { handler_test2(e); });
        dispatcher.subscribe("TestEvent", [this](const BaseEvent &e) { handler_test2(e); });
        dispatcher.subscribe("TestEvent", [this](const BaseEvent &e) { handler_test2(e); });

        dispatcher.post(TestEvent("yeet"));

        assertTrue(this->event_value2 == 4);
    };


    void handler_test(const BaseEvent &e) {
        const TestEvent &event = dynamic_cast<const TestEvent &>(e);
        this->event_value = event.msg;
    };


    void handler_test2(const BaseEvent &e) {
        this->event_value2++;
    };


public:
    TestEventSystem() : UnitTest("TestEventSystem") {
        addTest([this] { test_post_event(); }, "test_post_event");
        addTest([this] { test_subscribe_callback(); }, "test_subscribe_callback");
        addTest([this] { test_handle_event(); }, "test_handle_event");
        addTest([this] { test_multiple_callbacks(); }, "test_multiple_callbacks");
    }

    std::string event_value;
    int event_value2 = 0;
};


#endif //CEMENTENGINE_TESTEVENTSYSTEM_HPP
