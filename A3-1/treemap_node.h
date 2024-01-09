// C++ Aufgabe Treemap V5 part 1 - treemap_node, alias treemap::node
// Autor: Hartmut Schirmacher, BHT Berlin

#pragma once

#include <memory>

namespace my {

    // this is the template for a node in the treemap's tree
    // please note that the node does not need to know anything about the treemap itself (or about the iterator, later)
    template<typename K, typename T>
    class treemap_node
        : public std::enable_shared_from_this<treemap_node<K,T>> 
    {

    public:

        // aloas to shorten things
        using node = treemap_node<K,T>;
        using node_ptr = std::shared_ptr<node>;

        // public attributes
        std::pair<K,T> value_; 
        std::weak_ptr<node> up_;
        node_ptr left_, right_; 

        treemap_node(K key, T mapped, node_ptr up) 
        :  value_(std::make_pair(key,mapped)), up_(up), left_(), right_()
        {}

        // try to insert new (key,mapped) node in tree, return (new node, true)
        // if key already in tree, do not overwrite, just return (existing node, false)
        std::pair<node_ptr, bool> insert(K key, T mapped) 
        {
            // TODO, this is dummy code!
            return std::make_pair(nullptr, false); 
        } 

        // find node with the given key, and return pointer to it. return nullptr if not found
        std::shared_ptr<node> find(K key)  
        {
            // TODO, this is dummy code!
            return nullptr;
        }


    }; // class treemap_node

} // my::