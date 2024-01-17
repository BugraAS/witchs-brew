#include "GuiButton.hpp"
#include "GuiCheckBox.hpp"
/**
 * @brief Displays the GUI checkbox using the provided transformation matrix.
 * @param transform The transformation matrix to apply to the checkbox.
 */
void GuiCheckBox::display(Matrix transform){
    bool old = pressed;
    raygui::GuiCheckBox(shape, message.c_str(), &pressed);
    bool changed = old ^ pressed;
    if(changed & (handler != nullptr))
        handler(pressed);
}
