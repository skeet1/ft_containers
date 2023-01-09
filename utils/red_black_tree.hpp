/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:43:06 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/09 14:56:48 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>

template<class Key, class T>
class RBT {
    private:
        struct Node {
            Key     _key;
            T       _value;
            Node*   _parent;
            Node*   _uncle;
            Node*   _left;
            Node*   _right;
            size_t  _height;
        };
        
        Node*   root;
    
    public:
        RBT()
        {
            root = NULL;
        }

        RBT(Key key, T value)
        {
            root->_key = key;
            root->_value = value;
            root->_parent = NULL;
            root->_left = NULL;
            root->_right = NULL;
            root->_uncle = NULL;
            root->_height = 0;
        }

        Node*   newNode(Key key, T value)
        {
            Node* myNode = new Node;
            
            myNode->_key = key;
            myNode->_value = value;
            myNode->_parent = NULL;
            myNode->_right = NULL;
            myNode->_left = NULL;
            myNode->_uncle = NULL;
            myNode->_height = 0;

            return myNode;
        }

        void    insert(Key key, T value)
        {
            root = insert(root, key, value);
        }

        Node*   insert(Node* root, Key key, T val)
        {
            if (root == NULL)
                return newNode(key, val);
            if (root->_key > key)
            {
                root->_left = insert(root->_left, key, val);
            }
            else if (root->_key < key)
            {
                root->_right = insert(root->_right, key, val);
            }
            return root;
        }

        void    printTree()
        {
            printTree(root, 0);
        }

        void    printTree(Node* root, int depth)
        {
            if (root == NULL)
                return ;
            printTree(root->_right, depth+1);
            for (int i = 0; i < depth; i++)
                std::cout << "       ";
            std::cout << "(" << root->_key << ":" << root->_value << ")" << std::endl;
            printTree(root->_left, depth+1);
        }
};

#endif 