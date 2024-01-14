#include "DayTime.hpp"
#include "EventQueue.hpp"
#include "PotionShop.hpp"

// Constructor for the DayTime class, takes a PotionShop pointer as a parameter.
DayTime::DayTime(PotionShop* shop)
: shop(shop) , startNight(500) // Initializes the shop pointer and sets the startNight event time.
{

}

// Empty process function, needs implementation based on the class's requirements.
void DayTime::process(){
    // Implement the logic for the daytime processing here.
}

// Function to end the day, fires the startNight event, disables the daytime, and makes it invisible.
void DayTime::endDay(){
    EventQueue::fireEvent(startNight, 0); // Fires the startNight event with a delay of 0.
    disable(); // Disables the daytime functionality.
    makeInvisible(); // Makes the daytime invisible.
}

// Initialization function for the DayTime class, takes a pointer to void as a parameter.
void DayTime::Init(void* data){
    Event startDay = *((Event*)data); // Casts the void pointer to an Event pointer.
    // Lambda function to handle the startDay event, enables the daytime and makes it visible.
    EventHandler handle = [this](void* x)-> bool{
        this->enable(); // Enables the daytime functionality.
        this->makeVisible(); // Makes the daytime visible.
        return false; // The handler is not self-removing.
    };
    EventQueue::addHandler(startDay, handle); // Adds the handler to the EventQueue for the startDay event.
}
