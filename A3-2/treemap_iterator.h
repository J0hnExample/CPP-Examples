// C++ Aufgabe Treemap V5.2 - treemap_iterator, alias treemap::iterator
// Autor: Hartmut Schirmacher, Berliner Hochschule für Technik

#pragma once

// an iterator references a treemap_node, so it must know about it
// please note that the iterator does *not* need to know the treemap itself! (except for the "friend" stateent below)
#include "treemap_node.h"

namespace my {

    // forward declaration of treemap, just in case you want to keep a pointer to a treemap or such
    template<typename K, typename T>
    class treemap;

    // iterator: references a node within the tree
    template<typename K, typename T>
    class treemap_iterator {
    protected:

        // treemap is a friend, can call protected constructor
        // template<typename KK, typename TT>
        friend class treemap<K,T>;

        // construct iterator referencing a speciic node
        // - only treemap shall be allowed to do so
        treemap_iterator(/* TODO ... */ )
        { /* TODO */}

        // non-owning reference to the actual node
        /* TODO */ 
        
    public:

        // type aliases, should be exactly the same as for treemap itself
        using key_type = K;
        using mapped_type = T;
        using value_type = std::pair<K, T>;
        using node = my::treemap_node<K, T>; // from treemap_node.h

        // access data of referenced map element (node)
        value_type& operator*()
        {
            /* TODO, replace this code */
            static value_type dummy; // this increases Payload::count() by 1!
            return dummy; 
        }
        value_type* operator->()
        {
            /* TODO, replace this code */
            static value_type dummy; // this increases Payload::count() by 1!
            return &dummy; 
        }

        // two iterators are equal if they point to the same node
        bool operator==(const treemap_iterator& rhs) const
        {
            /* TODO, replace this code */
            return false; 
        }

        bool operator!=(const treemap_iterator& rhs) const
        {
            /* TODO, replace this code */
            return false; 
        }

        // next element in map, pre-increment
        // note: must modify self!
        treemap_iterator& operator++()
        {
            /* TODO */
            return *this; 
        }

        // prev element in map, pre-decrement
        // note: must modify self!
        treemap_iterator& operator--()
        {
            /* TODO */
            return *this; 
        }

    }; // class iterator

} // my::

