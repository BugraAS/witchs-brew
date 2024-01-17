#pragma once

#include "GuiNode.hpp"
#include "raylib.h"
#include <string>

/**
 * @brief GuiCheckBox class represents a check box in a graphical user interface.
 * @details Derived from GuiNode, it provides functionality for displaying and handling check box interactions.
 */
class GuiCheckBox : public GuiNode{
    protected:
    ::Rectangle shape;
    std::string message;
    void (*handler)(bool) = nullptr;
    bool pressed = true;
    public:

        /**
         * @brief Default constructor for GuiCheckBox.
         * @details Initializes the check box with a default shape, message, and pressed state.
         */
        explicit inline GuiCheckBox() : shape(::Rectangle{0.0,0.0,60.0,20.0}), message("Button") {}

        /**
         * @brief Constructor for GuiCheckBox with initial pressed state.
         * @param pressed The initial state of the checkbox (pressed or not pressed).
         */
        explicit inline GuiCheckBox(bool pressed): GuiCheckBox() {this->pressed = pressed;}

        /**
         * @brief Constructor for GuiCheckBox with initial pressed state, shape, and message.
         * @param pressed The initial state of the checkbox (pressed or not).
         * @param shape The shape of the checkbox.
         * @param message The text message for the checkbox.
         */
        explicit inline GuiCheckBox(bool pressed, ::Rectangle shape, std::string message): GuiCheckBox(pressed)
        {
            this->shape = shape;
            this->message = message;
        }

        /**
         * @brief Constructor for GuiCheckBox with initial pressed state, shape, message, and handler.
         * @param pressed The initial state of the checkbox (pressed or not).
         * @param shape The shape of the checkbox.
         * @param message The text message for the checkbox.
         * @param handler The function pointer to be set as the handler.
         */
        explicit inline GuiCheckBox(bool pressed, ::Rectangle shape, std::string message, void (*handler)(bool)): GuiCheckBox(pressed,shape,message)
        {
            this->handler = handler;
        }
         /**
         * @brief Set the shape (rectangle) of the checkbox.
         * @param shape The new shape of the checkbox.
         */
        inline void setShape(::Rectangle shape){this->shape = shape;}

        /**
         * @brief Get the shape (rectangle) of the checkbox.
         * @return The shape of the checkbox.
         */
        inline ::Rectangle& getShape(){return shape;}

        /**
         * @brief Set the text message displayed near the checkbox.
         * @param message The new text message for the checkbox.
         */
        inline void setMessage(std::string message){this->message = message;}

        /**
         * @brief Set the function handler to be called when the checkbox state changes.
         * @param handler The function pointer to be set as the handler.
         */
        inline void setHandler(void (*handler)(bool)){this->handler = handler;}

        /**
         * @brief Set the pressed state of the checkbox.
         * @param pressed The new state of the checkbox (pressed or not).
         */
        inline void setPressed(bool pressed){this->pressed = pressed;}

        /**
         * @brief Check if the checkbox is currently pressed.
         * @return True if the checkbox is pressed, false otherwise.
         */
        inline bool isPressed(){return pressed;}

        /**
         * @brief Get the text message displayed near the checkbox.
         * @return The text message of the checkbox.
         */
        inline std::string& getMessage(){return message;}

        /**
         * @brief Display the checkbox using the provided transformation matrix.
         * @param transform The transformation matrix to apply to the checkbox.
         */
        virtual void display(Matrix transform) override;
        /**
         * @brief Destructor for GuiCheckBox.
         * @details Default virtual destructor for proper polymorphic behavior.
         */
        virtual ~GuiCheckBox() = default;
};
