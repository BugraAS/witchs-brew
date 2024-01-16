/**
 * @file NightTime.hpp
 * @brief Header file for the NightTime class.
 */

#pragma once

#include "EventQueue.hpp"
#include "Node.hpp"
#include "PotionShop.hpp"
#include "RunnableNode.hpp"

/**
 * @class NightTime
 * @brief Represents the nighttime in the game.
 * @details Derived from Node and RunnableNode, the NightTime class manages nighttime events and logic.
 */
class NightTime : public Node, public RunnableNode {
public:
    Event startDay; ///< Event representing the start of the day.

private:
    PotionShop* shop; ///< Pointer to the PotionShop associated with the nighttime.

public:
    /**
     * @brief Function to end the night.
     * @details Fires the startDay event, disables the nighttime, and makes it invisible.
     */
    void endNight();

    /**
     * @brief Initialization function for the NightTime class.
     * @param data A pointer to void, which may be used for initialization.
     * @details Implements the virtual function from the base class.
     */
    virtual void Init(void* data) override;

    /**
     * @brief Inline function to get a pointer to the PotionShop associated with the nighttime.
     * @return A pointer to the PotionShop.
     */
    inline PotionShop* getShop() const { return shop; }

    /**
     * @brief Constructor for the NightTime class.
     * @param shop A pointer to the PotionShop associated with the nighttime.
     */
    explicit NightTime(PotionShop* shop);

    /**
     * @brief Destructor for the NightTime class.
     * @details Uses default implementation.
     */
    virtual ~NightTime() = default;

    /**
     * @brief Function to process the nighttime logic.
     * @details Implements the virtual function from the base class.
     */
    virtual void process() override;
};
