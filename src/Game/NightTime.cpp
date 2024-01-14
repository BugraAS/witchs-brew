#include "NightTime.hpp"
#include "Event.hpp"
#include "EventQueue.hpp"
#include "Global.hpp"
#include "PotionShop.hpp"
#include <iostream>

// Constructor for the NightTime class, takes a PotionShop pointer as a parameter.
NightTime::NightTime(PotionShop* shop)
: shop(shop), startDay(501)
{

}

// Empty process function, needs implementation based on the class's requirements.
void NightTime::process(){
    return;
}

// Function to end the night, fires the startDay event, disables the nighttime, and makes it invisible.
void NightTime::endNight(){
    EventQueue::fireEvent(startDay, 0); // Fires the startDay event with a delay of 0.
    disable(); // Disables the nighttime functionality.
    makeInvisible(); // Makes the nighttime invisible.
}

// Initialization function for the NightTime class, takes a pointer to void as a parameter.
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
