/**
 * @file InputHandle.hpp
 * @brief Header file for the InputHandle class.
 */

#pragma once

#include "InputHandle.hpp"

/**
 * @class InputHandle
 * @brief Singleton class for handling input events.
 * @details The InputHandle class manages key mappings and processes input events.
 */
class InputHandle {
private:
    static InputHandle* singleton;  ///< Static pointer to the singleton instance.

    /**
     * @brief Constructor: Initialize the keyMap.
     */
    InputHandle();

public:
    std::map<int, std::vector<InputEvent::ENUM>> keyMap; ///< Map to store key mappings.

    /**
     * @brief Destructor: Cleanup and set the singleton instance to null.
     */
    ~InputHandle();

    /**
     * @brief Process inputs - Placeholder comment for future implementation.
     * @details This function is a placeholder for handling inputs. Actual implementation is pending.
     */
    void process();

    /**
     * @brief Map a key to an input event type.
     * @param keyCode The key code to be mapped.
     * @param eventType The input event type to be associated with the key.
     */
    void mapKey(int keyCode, InputEvent::ENUM eventType);

    /**
     * @brief Unmap a key, removing it from the keyMap.
     * @param keyCode The key code to be unmapped.
     */
    void unmapKey(int keyCode);

    /**
     * @brief Clear all key mappings from the keyMap.
     */
    void clearKeyMappings();

    /**
     * @brief Static function to get the singleton instance of InputHandle.
     * @return Pointer to the singleton instance of InputHandle.
     */
    static InputHandle* getInstance() { return singleton; }
};
