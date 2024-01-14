#include "EventQueue.hpp"
#include <utility>
#include <vector>

// Static initialization of the singleton instance
EventQueue* EventQueue::singleton = nullptr;

// Constructor
EventQueue::EventQueue() {
    singleton = this;  // Set the singleton instance to the current instance
}

// Destructor
EventQueue::~EventQueue() {
    singleton = nullptr;  // Reset the singleton instance on destruction
}

// Add an event to the event queue
void EventQueue::addEvent(Event e){
    return;  // Currently, this method does nothing
}

// Add an event handler for a specific event
void EventQueue::addHandler(Event event, EventHandler handler) {
    if(handler){
        // Check if the eventHandlers map already contains the specified event
        if(singleton->eventHandlers.count(event) != 0)
            // If it does, add the handler to the existing vector of handlers for that event
            singleton->eventHandlers[event].push_back(handler);
        else
            // If it doesn't, create a new vector with the handler and insert it into the map
            singleton->eventHandlers.insert(std::pair<Event, std::vector<EventHandler>>(event,{handler}));
    }
}

// Process the events in the event queue
void EventQueue::process() {
    for (auto& payload : activeEvents) {
        // Check if there are handlers registered for the current event in the eventHandlers map
        if (eventHandlers.find(payload.first) != eventHandlers.end()) {
            // Iterate through the vector of handlers for the current event
            for (EventHandler& handler : eventHandlers[payload.first]) {
                // Call the handler with the payload (event data)
                if (!handler(payload.second)) {
                    break;  // Stop processing handlers if one returns false
                }
            }
        }
    }
    activeEvents.clear();  // Clear the processed events from the activeEvents vector
}
