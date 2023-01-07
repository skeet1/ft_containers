## Map
# RED_BLACK_TREE

Trees are often used to implement data structers who needs inserting and deletion and also searching for elements, cause the trees can do this job in a minumum time, and usally implemented using a self-balancing binary search tree, such as a *RED-BLACK-TREE* and *AVL TREE*.

before start talking about each one of them, let's take a look about what *Binary Search Tree* and, *Balancing Binary Search Tree* means?

*Binary Search Tree*:
A binary tree is a special type of tree in which every node or vertex has either no child node or one child node or two child nodes. A binary tree is an important class of a tree data structure in which a node can have at most two children.
And a binary search tree (BST) is a data structure that stores items in a sorted manner, allowing for fast search, insertion, and deletion of elements. It works by storing items in a tree-like structure, with the "left" subtree of a node containing items that are less than the node's key, and the "right" subtree containing items that are greater than the node's key. This allows for fast search of elements by starting at the root node and comparing the target key with the keys in the tree, as described in my previous answer.

Binary search trees have several useful properties:

- They allow for fast search, insertion, and deletion of elements.
- They allow for easy implementation of map and set data structures.
- They allow for in-order traversal of the tree, which means that the elements in the tree can be visited in sorted order.

*Balancing Binary Search Tree*:
A self-balancing binary search tree (BST) is a type of binary search tree that automatically adjusts its structure to maintain balance, resulting in improved search, insertion, and deletion performance. There are several different techniques that can be used to implement self-balancing BSTs, including rotations, rebalancing, height-balancing, and color-balancing.

Now we have a general idea about balancing binary search tree, and we are ready to learn more about AVL and Red-Black-Tree.

*AVL* trees and *red-black* trees are both types of self-balancing binary search trees. They are used to store data in a sorted, searchable manner and allow for quick insertion, deletion, and lookup of elements.

One main difference between AVL trees and red-black trees is that AVL trees are more strictly balanced than red-black trees. This means that the height of an AVL tree is always O(log n) where n is the number of nodes in the tree, while the height of a red-black tree is only O(log n) on average. This can make AVL trees slightly faster when it comes to searching for elements, but it also means that AVL trees may require more rotations (a process used to balance the tree) when inserting and deleting elements, which can make them slower in practice.

Another difference between AVL trees and red-black trees is the way they store and maintain balance. AVL trees use a technique called height-balancing, where the height of the left and right subtrees of any node differ by at most 1. Red-black trees, on the other hand, use a technique called color-balancing, where each node is assigned a color (red or black) and certain rules are followed to ensure that the tree remains balanced.

Overall, both AVL trees and red-black trees are efficient data structures for storing and searching data, but red-black trees may be more suitable in cases where frequent insertions and deletions are expected, due to their more relaxed balance conditions.


## RESOURCES TO LEARN MORE ABOUT RED BLACK TREE :##
  - https://www.geeksforgeeks.org/introduction-to-red-black-tree/
  - https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
  - https://www.programiz.com/dsa/red-black-tree
