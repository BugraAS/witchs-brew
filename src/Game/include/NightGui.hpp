/**
 * @file NightGui.hpp
 * @brief Header file for the NightGui class.
 */

#pragma once

#include "GuiNode.hpp"
#include "raylib.h"
#include <vector>

/**
 * @class NightGui
 * @brief Represents the graphical user interface for the nighttime.
 * @details Derived from GuiNode, the NightGui class is responsible for displaying nighttime GUI elements.
 */
class NightGui : public GuiNode {
private:
    std::vector<::Rectangle> boxes; ///< Vector to store rectangles used for drawing GUI elements.

public:
    /**
     * @brief Constructor for the NightGui class.
     */
    NightGui();

    /**
     * @brief Function to display the nighttime GUI.
     * @param transform The transformation matrix to apply to GUI elements.
     * @details Implements the virtual function from the base class.
     */
    virtual void display(Matrix transform) override;

private:
    /**
     * @brief Function to transform the rectangles based on a given matrix.
     * @param m The transformation matrix.
     * @return Transformed rectangles.
     */
    std::vector<::Rectangle> transformBoxes(Matrix m);
};
