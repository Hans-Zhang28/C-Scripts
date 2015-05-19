#include "tree2list.h"
#include <stdio.h>
#include <assert.h>

// link_nodes(cur) returns the structure of doubly linked lists.
// Time: O(n) where n is the number of nodes in cur.
struct node *link_nodes(struct node *cur) 
{
    if (cur == NULL) 
    {
        return NULL;
    } 
    if (cur->left) 
    {
        struct node *new = link_nodes(cur->left);
        while (new->right) 
        {
            new = new->right;
        }
        cur->left = new;
        new->right = cur;
    } 
    if (cur->right) 
    {
        struct node *new = link_nodes(cur->right);
        while (new->left) 
        {
            new = new->left;           
        }
        cur->right = new;
        new->left = cur;
    }
    return cur;
}


struct node *tree2list(struct node *root) 
{
    if (root == NULL) return  NULL;
    root = link_nodes(root);
    struct node *new = root;
    while (root->left) 
    {
        root = root->left;
    }
    while (new->right) 
    {
        new = new->right;
    }
    root->left = new;
    new->right = root;
    return root;
}
