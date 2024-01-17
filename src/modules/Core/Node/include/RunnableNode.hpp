#pragma once

#include "NodeType.hpp"
#include "Runnable.hpp"

/**
 * @brief Represents a node with the ability to be processed as part of a runnable system.
 * @details This class inherits the NodeType to mark it as processable and can be used in a
 * hierarchy to organize nodes based on their behavior.
 */
class RunnableNode : virtual public NodeType{
//TODO: figure out a way to make this inherit Runnable instead of Node itselff, without breaking the code
    public:
        /**
         * @brief Default constructor for RunnableNode.
         */
        inline RunnableNode(){setFlag( NodeType::PROCESSABLE);}
};
