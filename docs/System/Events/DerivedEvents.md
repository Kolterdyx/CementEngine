
# Derived Events

By inheriting from the `BaseEvent` class, one can create their own event classes and types.

## Example

### Event definition
```c++
class MessageEvent : protected BaseEvent {

    // Unique identifier
    static constexpr EventType event_type = 0xC0FFEE;
    
    // Field to store our data
    std::string msg;

    EventType type() const override {
        return event_type;
    };
    
    // Constructor that takes some data
    MessageEvent(std::string msg) {
        this->msg = msg;
    }
};
```

### Event listening

Create some callbacks:

```c++

void onMessageEventFunction(const BaseEvent& e) {
    const MessageEvent& event = static_cast<const MessageEvent&>(e);
    std::cout << event.msg << std::endl;
}

class MyClass {
    void onMessageEventMethod(const BaseEvent& e) {
        const MessageEvent& event = static_cast<const MessageEvent&>(e);
        std::cout << event.msg << std::endl;
    }
};
```

Subscribe the callbacks to the desired event:

```c++
MyClass myClassInst();

void dispatcher.subscribe(MessageEvent::event_type, std::bind(&onMessageEventFunction, NULL, std::placeholders::_1));
void dispatcher.subscribe(MessageEvent::event_type, std::bind(&MyClass.onMessageEventMethod, myClassInst, std::placeholders::_1));
```

### Firing/Posting the event

```c++
dispatcher.post(MessageEvent("Hello world!"));
```