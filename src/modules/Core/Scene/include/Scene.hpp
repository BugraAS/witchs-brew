#pragma once

#include "Node.hpp"
#include "Runnable.hpp"
#include "RunnableNode.hpp"
#include "VisualNode.hpp"
#include <vector>

/**
 * @brief The Scene class represents a scene.
 * @details This class is derived from the Runnable interface and manages the processes of nodes in the scene.
 */
class Scene : public Runnable{
private:
    static Scene *singleton;
    Node root;
public:
      /**
     * @brief Adds a node to the scene.
     * @param n The node to be added.
     */
    static void addNode(Node* n);

     /**
     * @brief Gets the root node of the scene.
     * @return The root node of the scene.
     */
    static Node* getRoot();

     /**
     * @brief Gets the singleton instance of the scene.
     * @return The singleton instance of the scene.
     */
    static inline Scene* getSingleton(){return singleton;}

     /**
     * @brief Gets a vector containing visual nodes.
     * @return Vector of visual nodes.
     */
    static std::vector<Node*> getVisual();

    /**
     * @brief Gets a vector containing runnable nodes.
     * @return Vector of runnable nodes.
     */
    static std::vector<Node*> getRunnable();
    // There is no removal. Nodes delete themselves
    // TODO: except they dont, fix it later

     /**
     * @brief Scene processing function.
     * @details Performs the processes of nodes in the scene.
     */
    virtual void process() override;

      /**
     * @brief Default constructor for the Scene class.
     */
    explicit Scene();

    /**
     * @brief Default destructor for the Scene class.
     */
    ~Scene();
    friend Node; //so the nodes can remove themselves
};
/*
// Scene class holding orphan nodes
class Scene {
private:
    std::vector<Node*> nodes;

public:
    void addNode(Node* node) {
        nodes.push_back(node);
    }

    // Process all enabled nodes and their children
    void process() {
        for (Node* node : nodes) {
            if (node->isEnabled()) {
                processNodeAndChildren(node);
            }
        }
    }

    // Render visible nodes
    std::vector<VisualNode*> getVisibleNodes() const {
        std::vector<VisualNode*> visibleNodes;
        for (Node* node : nodes) {
            if (node->checkType(NodeType::VISUAL) && node->isVisible()) {
                visibleNodes.push_back(static_cast<VisualNode*>(node));
            }
        }
        return visibleNodes;
    }

private:
    // Recursively process node and its children
    void processNodeAndChildren(Node* node) {
        if (node->checkType(NodeType::PROCESSABLE)) {
            // Call process() only if it is a RunnableNode
            static_cast<RunnableNode*>(node)->process();
        }

        // Process children
        for (Node* child : getChildren(node)) {
            processNodeAndChildren(child);
        }
    }

    // Helper function to get children of a node
    std::vector<Node*> getChildren(Node* parent) const {
        // For simplicity, return an empty vector here
        // In a real scenario, you would need a mechanism to manage parent-child relationships
        return {};
    }
};
*/
