#pragma once

#include "NodeType.hpp"
#include "Runnable.hpp"
#include <memory>
#include <string>
#include <vector>

/**
 * @brief The Node class represents a basic node in a hierarchical structure.
 * @details Node is a virtual class inheriting from NodeType and implementing Runnable.
 * It serves as a building block for creating hierarchical structures of nodes in a scene.
 */
class Node : virtual public NodeType, public Runnable {
    public:
        std::string name;
    protected:
        std::vector<std::unique_ptr<Node>> children{};
        Node* parent = nullptr;
        bool enabled = true; //stops children from being processed
        bool visible = true; //stops children from being rendered
    public:
        /**
         * @brief Virtual function to be overridden for custom processing logic.
         * @details Subclasses should implement their specific behavior in this function.
         */
        virtual void process() override;

        /**
         * @brief Initializes the node with optional data.
         * @param data A pointer to additional data for initialization (can be nullptr).
         */
        virtual void Init(void* data);

         /**
         * @brief Deinitializes the node.
         * @details Performs any cleanup or resource release needed before the node is destroyed.
         */
        virtual void DeInit();
        /**
         * @brief Gets the parent node of the current node.
         * @return A pointer to the parent node.
         */
        inline Node* getParent(){return parent;}
         /**
         * @brief Sets the parent node of the current node.
         * @param parent A pointer to the parent node.
         */
        void setParent(Node* parent);

         /**
         * @brief Finds a child node by its name.
         * @param name The name of the child node to find.
         * @return A pointer to the found child node, or nullptr if not found.
         */
        Node* findChild(std::string name);

        /**
         * @brief Gets the vector of children nodes.
         * @return A reference to the vector of children nodes.
         */
        inline std::vector<std::unique_ptr<Node>>& getChildren(){ return children;}

        /**
         * @brief Checks if the node is enabled.
         * @return True if the node is enabled, false otherwise.
         */
        inline bool isEnabled(){return enabled;}

        /**
         * @brief Enables the node for processing.
         */
        inline void enable(){enabled = true;}

        /**
         * @brief Disables the node, preventing it from being processed.
         */
        inline void disable(){enabled = false;}

        /**
         * @brief Checks if the node is an orphan (has no parent).
         * @return True if the node has no parent, false otherwise.
         */
        inline bool isOrphan(){return parent == nullptr;}

        /**
         * @brief Checks if the node is visible.
         * @return True if the node is visible, false otherwise.
         */
        inline bool isVisible(){return visible;}

        /**
         * @brief Makes the node visible.
         */
        inline void makeVisible(){visible = true;}

        /**
         * @brief Makes the node invisible.
         */
         inline void makeInvisible(){visible = false;}

        /**
         * @brief Default constructor for Node.
         */
        explicit inline Node() =default;

        /**
         * @brief Constructor for Node with a specified name.
         * @param name The name of the node.
         */
        explicit inline Node(std::string name): Node(){this->name = name;}

        // Delete copy and move constructors and assignment operators
        explicit Node(const Node &) = delete;
        explicit Node(Node &&) = delete;
        Node &operator=(Node &&) = default;
        Node &operator=(const Node &) = default;

         /**
         * @brief Virtual destructor for Node.
         * @details Ensures proper cleanup when derived classes are destroyed.
         */
        virtual ~Node();
    protected:
         /**
         * @brief Removes a child node from the current node.
         * @param n A pointer to the child node to be removed.
         */
        void removeChild(Node* n);
};
