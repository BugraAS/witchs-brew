/**
 * @file DayGui.hpp
 * @brief Header file for the DayGui class.
 */

#pragma once

#include "GuiNode.hpp"
#include "raylib.h"
#include <vector>

/**
 * @class DayGui
 * @brief Represents the graphical user interface for the daytime.
 * @details Derived from GuiNode, the DayGui class provides functionality to display the daytime GUI.
 */
class DayGui : public GuiNode {
private:
    std::vector<::Rectangle> boxes; ///< Vector to store rectangles used for drawing GUI elements.

public:
    /**
     * @brief Constructor for the DayGui class.
     */
    DayGui();

    /**
     * @brief Function to display the daytime GUI.
     * @param transform The transformation matrix to apply to GUI elements.
     * @details Implements the virtual function from the base class.
     */
    virtual void display(Matrix transform) override;

private:
    /**
     * @brief Function to transform the rectangles based on a given matrix.
     * @param m The transformation matrix to apply.
     * @return A vector of transformed rectangles.
     */
    std::vector<::Rectangle> transformBoxes(Matrix m);
};
