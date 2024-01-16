/**
 * @file EventQueue.hpp
 * @brief Header file for the EventQueue class.
 */

#pragma once

#include "EventQueue.hpp"

/**
 * @class EventQueue
 * @brief Singleton class for managing and processing events.
 * @details The EventQueue class handles the registration of event handlers and the processing of events.
 */
class EventQueue {
private:
    static EventQueue* singleton;  ///< Static pointer to the singleton instance.

    std::map<Event, std::vector<EventHandler>> eventHandlers;  ///< Map to store event handlers.
    std::vector<std::pair<Event, void*>> activeEvents;  ///< Vector to store active events.

    /**
     * @brief Constructor: Set the singleton instance to the current instance.
     */
    EventQueue();

public:
    /**
     * @brief Destructor: Reset the singleton instance on destruction.
     */
    ~EventQueue();

    /**
     * @brief Add an event to the event queue.
     * @param e The event to be added.
     */
    void addEvent(Event e);

    /**
     * @brief Add an event handler for a specific event.
     * @param event The event for which the handler is registered.
     * @param handler The event handler function to be added.
     */
    void addHandler(Event event, EventHandler handler);

    /**
     * @brief Process the events in the event queue.
     * @details This function processes the registered event handlers for active events.
     */
    void process();

    /**
     * @brief Static function to get the singleton instance of EventQueue.
     * @return Pointer to the singleton instance of EventQueue.
     */
    static EventQueue* getInstance() { return singleton; }
};
