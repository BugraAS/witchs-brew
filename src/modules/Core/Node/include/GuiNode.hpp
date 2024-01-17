#pragma once

#include "Node2D.hpp"
#include "NodeType.hpp"
#include "VisualNode.hpp"
#include "raygui-implement.h"

/**
 * @brief GuiNode class represents a graphical user interface (GUI) node.
 * @details Derived from VisualNode and Node2D, it serves as the base class for GUI elements.
 */

class GuiNode : public VisualNode, public Node2D{
    protected:
    public:
         /**
         * @brief Default constructor for GuiNode.
         * @details Initializes the GuiNode and sets the GUI flag in its NodeType.
         */
        explicit inline GuiNode() {setFlag(NodeType::GUI);}

        /**
         * @brief Pure virtual function to display the GUI node using the provided transformation matrix.
         * @param transform The transformation matrix to apply to the GUI node.
         */
        virtual void display(Matrix transform) = 0;

         /**
         * @brief Destructor for GuiNode.
         * @details Default virtual destructor for proper polymorphic behavior.
         */
        virtual ~GuiNode() = default;
};
