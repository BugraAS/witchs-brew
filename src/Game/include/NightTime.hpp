#pragma once

#include "EventQueue.hpp"
#include "Node.hpp"
#include "PotionShop.hpp"
#include "RunnableNode.hpp"

// NightTime class is derived from Node and RunnableNode, representing the nighttime in the game.
class NightTime : public Node, public RunnableNode {
public:
    Event startDay; // Event representing the start of the day.

private:
    PotionShop* shop; // Pointer to the PotionShop associated with the nighttime.

public:
    // Function to end the night, fires the startDay event, disables the nighttime, and makes it invisible.
    void endNight();

    // Initialization function for the NightTime class, takes a pointer to void as a parameter.
    virtual void Init(void* data) override;

    // Inline function to get a pointer to the PotionShop associated with the nighttime.
    inline PotionShop* getShop() const { return shop; }

    // Constructor for the NightTime class, taking a PotionShop pointer as a parameter.
    explicit NightTime(PotionShop* shop);

    // Destructor for the NightTime class, using default implementation.
    virtual ~NightTime() = default;

    // Function to process the nighttime logic, implementing the virtual function from the base class.
    virtual void process() override;
};
