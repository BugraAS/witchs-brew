/**
 * @file DayTime.hpp
 * @brief Header file for the DayTime class.
 */

#pragma once

#include "EventQueue.hpp"
#include "Node.hpp"
#include "PotionShop.hpp"
#include "RunnableNode.hpp"

/**
 * @class DayTime
 * @brief Represents the daytime in the game.
 * @details Derived from Node and RunnableNode, the DayTime class manages daytime events and logic.
 */
class DayTime : public Node, public RunnableNode {
public:
    Event startNight; ///< Event representing the start of the night.

private:
    PotionShop* shop; ///< Pointer to the PotionShop associated with the daytime.

public:
    /**
     * @brief Function to end the day.
     * @details Fires the startNight event, disables the daytime, and makes it invisible.
     */
    void endDay();

    /**
     * @brief Initialization function for the DayTime class.
     * @param data A pointer to void.
     * @details Overrides the virtual function from the base class.
     */
    virtual void Init(void* data) override;

    /**
     * @brief Inline function to get a pointer to the PotionShop associated with the daytime.
     * @return A pointer to the PotionShop.
     */
    inline PotionShop* getShop() const { return shop; }

    /**
     * @brief Constructor for the DayTime class.
     * @param shop A pointer to the PotionShop associated with the daytime.
     */
    explicit DayTime(PotionShop* shop);

    /**
     * @brief Destructor for the DayTime class.
     * @details Uses the default implementation.
     */
    virtual ~DayTime() = default;

    /**
     * @brief Function to process the daytime logic.
     * @details Implements the virtual function from the base class.
     */
    virtual void process() override;
};
