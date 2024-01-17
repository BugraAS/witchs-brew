#pragma once

#include "Node2D.hpp"
#include "Node3D.hpp"
#include "VisualNode.hpp"
#include "raylib.h"
#include <type_traits>
#include <vector>

/**
 * @brief Template class for managing packed 2D or 3D visual nodes along with their transformations.
 * @details The template type T must inherit VisualNode and be either a subclass of Node2D or Node3D.
 */
template<class T> class PackedNodes{
    static_assert(std::is_base_of<VisualNode, T>(), "T must inherit VisualNode");
    static_assert(std::is_base_of<Node2D, T>() ^ std::is_base_of<Node3D, T>(), "T must inherit Node2D or Node3D");

    private:
    int size{0};
    std::vector<T*> nodes{};
    std::vector<::Matrix> transforms{};
    public:
     /**
     * @brief Default constructor for PackedNodes.
     */
    explicit inline PackedNodes() {}

    /**
     * @brief Gets the number of nodes in the packed collection.
     * @return The number of nodes.
     */
    inline int length() {return size;}

    /**
     * @brief Adds a node to the packed collection along with its transformation.
     * @param node A pointer to the node to be added.
     * @param transform The transformation matrix for the node.
     */
    inline void add(T* node, ::Matrix transform){
        nodes.push_back(node);
        transforms.push_back(transform);
        size++;
    }

    /**
     * @brief Gets a pointer to the node at the specified index.
     * @param i The index of the node.
     * @return A pointer to the node at the specified index.
     */
    inline T* getNode(int i){
        return nodes[i];
    }

    /**
     * @brief Gets the transformation matrix for the node at the specified index.
     * @param i The index of the node.
     * @return The transformation matrix for the node at the specified index.
     */
    inline ::Matrix getTranform(int i){
        return transforms[i];
    }

    /**
     * @brief Clears the packed collection, removing all nodes and transformations.
     */
    inline void clear(){
        nodes.clear();
        transforms.clear();
        size = 0;
    }
};
