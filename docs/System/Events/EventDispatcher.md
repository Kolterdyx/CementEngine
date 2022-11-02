# Event Dispatcher

## Subscribing to events

### Event handler

```c++
void onMyEvent( const BaseEvent& e ) {
    std::cout << "Caught event of type: " << e.type() << std::endl;
}
```

### Callback setup

```c++
dispatcher.subscribe(MyEvent::event_type, std::bind(&onMyEvent, object, std::placeholders::_1));
```

Lambdas can also be used:

```c++
dispatcher.subscribe(MyEvent::event_type, []( const BaseEvent& e ) {
        std::cout << "Caught event of type: " << e.type() << std::endl;
    });
```

### Posting events

```c++
dispatcher.post(MyEvent());
```