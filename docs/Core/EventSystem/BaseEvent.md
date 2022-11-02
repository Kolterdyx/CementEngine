# Base Event

This is the base class for all the events. It is not meant to be instanced, but to be inherited from.

## Event type

The `type` field of an event is of type `const char *`. It must be unique, as it will be used to identify
it when
calling the observer functions.

## `getType()`

This method will usually return the `type` field, but it can be defined to return a different value if needed. The
event dispatcher will call this function to tell event types apart.
