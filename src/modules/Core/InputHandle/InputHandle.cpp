#include "InputHandle.hpp"

// Singleton instance initialization
InputHandle* InputHandle::singleton = nullptr;

// Constructor: Initialize the keyMap
InputHandle::InputHandle()
: keyMap()
{
    singleton = this;
}

// Destructor: Cleanup and set the singleton instance to null
InputHandle::~InputHandle(){
    singleton = nullptr;
}

// Process inputs - Placeholder comment for future implementation
void InputHandle::process(){
    //TODO: Handle inputs
    //we will ignore this for now since everything is based on clicks
}

// Map a key to an input event type
void InputHandle::mapKey(int keyCode, InputEvent::ENUM eventType) {
    singleton->keyMap[keyCode] = {eventType};
}

// Unmap a key, removing it from the keyMap
void InputHandle::unmapKey(int keyCode) {
    singleton->keyMap.erase(keyCode);
}

// Clear all key mappings from the keyMap
void InputHandle::clearKeyMappings() {
    singleton->keyMap.clear();
}
