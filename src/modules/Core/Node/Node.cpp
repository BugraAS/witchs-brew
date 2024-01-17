#include "Node.hpp"
#include <algorithm>
#include <memory>
#include <vector>
/**
 * @brief Process function for the Node class.
 * @details This function is intended to be overridden by derived classes to define custom processing logic.
 */
void Node::process(){
    return;
}
/**
 * @brief Destructor for the Node class.
 * @details Clears the parent-child relationship by setting the parent to nullptr.
 */
Node::~Node(){
    setParent(nullptr);
}
/**
 * @brief Removes a child node from the list of children.
 * @param n The child node to be removed.
 */
void Node::removeChild(Node* n){
    std::vector<std::unique_ptr<Node>>::iterator res = children.begin();
    if((res = std::find_if(children.begin(),children.end(),
        [&](std::unique_ptr<Node> &v)-> bool{
            return v.get() == n;
        })) != children.end()){
            std::unique_ptr<Node> &temp= children.at(res - children.begin());
            n = temp.release();
            children.erase(res);
        }
}
/**
 * @brief Sets the parent node for this node.
 * @param parent The parent node to be set.
 */
void Node::setParent(Node* parent){
    if(this->parent == parent)
        return;
    Node* oldparent = this->parent;
    if (oldparent != nullptr) {
        oldparent->removeChild(this);
    }
    this->parent = parent;
    if(parent != nullptr)
        parent->getChildren().push_back(std::unique_ptr<Node>(this));
}
/**
 * @brief Initialization function for the Node class.
 * @param data A pointer to initialization data (not used in this implementation).
 */
void Node::Init(void* data){return;}
/**
 * @brief Deinitialization function for the Node class.
 */
void Node::DeInit(){return;}
