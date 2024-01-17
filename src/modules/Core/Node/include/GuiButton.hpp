#pragma once

#include "GuiNode.hpp"
#include "raylib.h"
#include <string>
/**
 * @brief GuiButton class represents a button in a graphical user interface.
 * @details Derived from GuiNode, it provides functionality for displaying and handling button interactions.
 */
class GuiButton : public GuiNode{
    protected:
    ::Rectangle shape;
    std::string message;
    void (*handler)() = nullptr;
    public:
         /**
         * @brief Default constructor for GuiButton.
         * @details Initializes the button with a default shape and message.
         */
        explicit inline GuiButton() : shape(::Rectangle{0.0,0.0,60.0,20.0}), message("Button") {}
        
        /**
         * @brief Set the shape (rectangle) of the button.
         * @param shape The new shape of the button.
         */
        inline void setShape(::Rectangle shape){this->shape = shape;}

         /**
         * @brief Get the shape (rectangle) of the button.
         * @return The shape of the button.
         */
        inline ::Rectangle& getShape(){return shape;}

         /**
         * @brief Set the text message displayed on the button.
         * @param message The new text message for the button.
         */
        inline void setMessage(std::string message){this->message = message;}

        /**
         * @brief Set the function handler to be called when the button is pressed.
         * @param handler The function pointer to be set as the handler.
         */
        inline void setHandler(void (*handler)()){this->handler = handler;}

         /**
         * @brief Get the text message displayed on the button.
         * @return The text message of the button.
         */
        inline std::string& getMessage(){return message;}

        /**
         * @brief Display the button using the provided transformation matrix.
         * @param transform The transformation matrix to apply to the button.
         */
        virtual void display(Matrix transform) override;

        /**
         * @brief Destructor for GuiButton.
         * @details Default virtual destructor for proper polymorphic behavior.
         */
        virtual ~GuiButton() = default;
};
