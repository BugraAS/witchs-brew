#pragma once

#include "EventQueue.hpp"
#include "Node.hpp"
#include "PotionShop.hpp"
#include "RunnableNode.hpp"

// DayTime class is derived from Node and RunnableNode, representing the daytime in the game.
class DayTime : public Node, public RunnableNode {
public:
    Event startNight; // Event representing the start of the night.

private:
    PotionShop* shop; // Pointer to the PotionShop associated with the daytime.

public:
    // Function to end the day, fires the startNight event, disables the daytime, and makes it invisible.
    void endDay();

    // Initialization function for the DayTime class, takes a pointer to void as a parameter.
    virtual void Init(void* data) override;

    // Inline function to get a pointer to the PotionShop associated with the daytime.
    inline PotionShop* getShop() const { return shop; }

    // Constructor for the DayTime class, taking a PotionShop pointer as a parameter.
    explicit DayTime(PotionShop* shop);

    // Destructor for the DayTime class, using default implementation.
    virtual ~DayTime() = default;

    // Function to process the daytime logic, implementing the virtual function from the base class.
    virtual void process() override;
};
