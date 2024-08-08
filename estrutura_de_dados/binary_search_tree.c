#include "node_tree.h"

#include <stdio.h>
#include <stdlib.h>


static void add_search_tree_recursive(struct NodeTree **node, int data);
static void add_search_tree_interactive(struct NodeTree **node, int data);
void get_search_tree(struct NodeTree *root);


int main()
{

        struct NodeTree *root = NULL;

        /*
        add_search_tree_recursive(&root, 1);
        printf("%d\n", root->data);
        add_search_tree_recursive(&root, 8);
        printf("%d\n", root->node_right->data);
        add_search_tree_recursive(&root, 5);
        printf("%d\n", root->node_right->node_left->data);
        */

        add_search_tree_interactive(&root, 1);
        printf("%d\n", root->data);
        add_search_tree_interactive(&root, 7);
        printf("%d\n", root->node_right->data);
        add_search_tree_interactive(&root, 5);
        printf("%d\n", root->node_right->node_left->data);



        return 0;
};


static void add_search_tree_recursive(struct NodeTree **node, int data)
{
        struct NodeTree
        *aux,
        *new_node = (struct NodeTree *)malloc(sizeof(struct NodeTree));

        new_node->data = data;
        new_node->node_left = NULL;
        new_node->node_right = NULL;

        if (*node) {
                aux = *node;
                if(data < aux->data)
                        add_search_tree_recursive(&aux->node_left, data);
                else
                        add_search_tree_recursive(&aux->node_right, data);
        } else
                *node = new_node;
};


static void add_search_tree_interactive(struct NodeTree **node, int data)
{
        struct NodeTree
        *aux,
        *new_node = (struct NodeTree *)malloc(sizeof(struct NodeTree));

        new_node->data = data;
        new_node->node_left = NULL;
        new_node->node_right = NULL;

        if (*node) {
                aux = *node;
                while (aux) {
                        /* direciona pra esquerda ou direita */
                        if (data < aux->data) 
                                if (aux->node_left)
                                        aux = aux->node_left;
                                else {
                                        aux->node_left = new_node;
                                        aux = NULL;
                                }
                        else
                                if (aux->node_right)
                                        aux = aux->node_right; 
                                else {
                                        aux->node_right = new_node;
                                        aux = NULL;
                                }
                };               
        } else 
                *node = new_node;

};
