#include "Scene.hpp"
#include "Node.hpp"
#include "RendererDefault.hpp"
#include "RunnableNode.hpp"
#include "VisualNode.hpp"
#include <functional>
#include <memory>
#include <vector>

//TODO: Write tests for this class

/**
 * @brief The singleton instance of the Scene class.
 */
Scene *Scene::singleton=nullptr;

/**
 * @brief Processes the scene by fetching visibles and running runnables.
 */
void Scene::process(){
    RendererDefault::fetchVisibles();
    auto runnables = getRunnable();
    for (Node* runnable : runnables) {
        static_cast<Runnable*>(runnable)->process();
    }
}

/**
 * @brief Retrieves visual nodes in the scene.
 * @return Vector of visual nodes.
 */
std::vector<Node*> Scene::getVisual(){
    std::vector<Node*> out{};

    std::function<void(Node*)> recurseChild = [&](Node* n) -> void{
        if(n->checkType(NodeType::VISUAL))
            out.push_back((Node*)n);
        std::vector<std::unique_ptr<Node>> &childs = n->getChildren();
        for(std::unique_ptr<Node> &c: childs){
            if(c->isVisible())
                recurseChild(c.get());
        }
    };

    recurseChild(Scene::getRoot());
    return out;
}

/**
 * @brief Gets a vector containing runnable nodes in the scene.
 * @return Vector of runnable nodes.
 */
std::vector<Node*> Scene::getRunnable(){
    std::vector<Node*> out{};

    std::function<void(Node*)> recurseChild = [&](Node* n) -> void{
        if(n->checkType(NodeType::PROCESSABLE))
            out.push_back(n);
        std::vector<std::unique_ptr<Node>> &childs = n->getChildren();
        for(std::unique_ptr<Node> &c: childs){
            if(c->isEnabled())
                recurseChild(c.get());
        }
    };

    recurseChild(Scene::getRoot());
    return out;
}
/**
 * @brief Default constructor for the Scene class.
 */
Scene::Scene()
: root("root")
{
    singleton = this;
}

/**
 * @brief Default destructor for the Scene class.
 */
Scene::~Scene(){
    singleton = nullptr;
}

/**
 * @brief Adds a node to the scene.
 * @param n The node to be added.
 */
void Scene::addNode(Node *n){
    // if(n == nullptr) //intentionally removed safeguard
    //     return;
    n->setParent(Scene::getRoot());
}

/**
 * @brief Gets the root node of the scene.
 * @return The root node of the scene.
 */
Node* Scene::getRoot(){
    return &singleton->root;
}
