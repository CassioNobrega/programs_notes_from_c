#ifndef NODE_TREE_H
#define NODE_TREE_H

struct NodeTree {
        int data;
        struct NodeTree *node_left;
        struct NodeTree *node_right;
};

#endif // NODE_TREE_H
