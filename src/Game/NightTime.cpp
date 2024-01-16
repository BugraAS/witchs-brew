/**
 * @file NightTime.cpp
 * @brief Implementation of the NightTime class.
 */

#include "NightTime.hpp"
#include "Event.hpp"
#include "EventQueue.hpp"
#include "Global.hpp"
#include "PotionShop.hpp"
#include <iostream>

/**
 * @brief Constructor for the NightTime class.
 * @param shop A pointer to the PotionShop associated with the NightTime instance.
 */
NightTime::NightTime(PotionShop* shop)
    : shop(shop), startDay(501)
{
}

/**
 * @brief Empty process function.
 * @details This function needs implementation based on the class's requirements.
 */
void NightTime::process(){
    return;
}

/**
 * @brief Function to end the night.
 * @details Fires the startDay event, disables the nighttime, and makes it invisible.
 */
void NightTime::endNight(){
    EventQueue::fireEvent(startDay, 0); // Fires the startDay event with a delay of 0.
    disable(); // Disables the nighttime functionality.
    makeInvisible(); // Makes the nighttime invisible.
}

/**
 * @brief Initialization function for the NightTime class.
 * @details Takes a pointer to void as a parameter.
 * @param data A pointer to void containing data for initialization.
 */
void NightTime::Init(void* data){
    Event startNight = *((Event*)data); // Casts the void pointer to an Event pointer.
    
    // Lambda function to handle the startNight event, enables the nighttime and makes it visible.
    EventHandler handle = [this](void* x)-> bool{
        this->enable(); // Enables the nighttime functionality.
        this->makeVisible(); // Makes the nighttime visible.
        return false; // The handler is not self-removing.
    };
    
    EventQueue::addHandler(startNight, handle); // Adds the handler to the EventQueue for the startNight event.
}
