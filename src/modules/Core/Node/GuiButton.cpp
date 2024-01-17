#include "GuiButton.hpp"

/**
 * @brief Displays the GUI button using the provided transformation matrix.
 * @param transform The transformation matrix to apply to the button.
 */
void GuiButton::display(Matrix transform){
    bool pressed = raygui::GuiButton(shape, message.c_str());
    if(pressed & (handler != nullptr))
        handler();
}
