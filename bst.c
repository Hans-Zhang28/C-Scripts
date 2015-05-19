// bst.c

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "bst.h"

// see bst.h documentation
struct bsttree *create_bst(void) 
{
	struct bsttree *tree = malloc(sizeof(struct bsttree));
	tree->root = NULL;
	return tree;
}


// destroy_tree(node) destroys node
// effects: node is deallocated along with all nodes linked to it.
// time: O(n) where n is the number of nodes linked to struct bstnode node.

void destroy_tree(struct bstnode *node)
{
	if (NULL == node) {return;}
	destroy_tree(node->left);
	destroy_tree(node->right);
	free(node);
}


// see bst.h documentation
void destroy_bst(struct bsttree *t)
{
   assert(t);
   destroy_tree(t->root);
   free(t);
}


// see bst.h documentation
struct bstnode *make_bstnode(int val, struct bstnode *l, struct bstnode *r) 
{
	struct bstnode *new = malloc(sizeof(struct bstnode));
	new->item = val;
	new->left = l;
	new->right = r;
	return new;
}



// see bst.h documentation
bool is_bstempty(struct bsttree *t)
{
	assert(t);
	return (NULL == t->root);
}


// inorder_node(node) prints all nodes of node in order
//  (left, root, right)
// effects: node's item is printed to the screen, 
//          along with all nodes' items linked to it
// time: O(n) where n is the number of printed nodes
void inorder_node(struct bstnode *node) {
	if (NULL == node) {return;}
	inorder_node(node->left);
	printf("  %d", node->item);
	inorder_node(node->right);
}

// see bst.h documentation
void traverse_inorder(struct bsttree *t)
{
	assert(t);
	inorder_node(t->root);
	printf("\n");
}


bool is_tree(struct bstnode *prev, struct bstnode *cur);


// see bst.h documentation
bool is_bst(struct bsttree *t)
{
    assert(t);
    return is_tree(t->root, t->root->left);
}


// is_tree(n) returns true if n is a valid BST, otherwise false.
// Time: O(n) where n is the number of nodes in t.
bool is_tree(struct bstnode *prev, struct bstnode *cur) 
{
    if (cur) 
    {
        if (!is_tree(cur, cur->left)) 
            return false;
        if (prev != NULL && prev->item <= cur->item) 
            return false;
        return is_tree(cur, cur->right);        
        }
    return true;
}



//see bst.h documentation
//refer from section 11 slide 46
void bst_insert(int val, struct bsttree *t) 
{
    struct bstnode *prev = NULL;
    struct bstnode *cur = t->root;
    while (cur != NULL) 
    {
        if (cur->item == val) return;
        prev = cur;
        if (cur->item < val) cur = cur->right;
        else cur = cur->left;
    }
    struct bstnode *new = make_bstnode(val, NULL, NULL);
    if (prev == NULL) 
    {
        t->root = new;
    } else if (prev->item < val) 
    {
        prev->right = new;
    } else 
    {
        prev->left = new;
    }
}



//see bst.h documentation
bool bst_search(struct bsttree *t, int val)
{
    struct bstnode *cur = t->root;
    while (cur != NULL) {
        if (cur->item == val) return true;
        if (cur->item < val) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return false;
}


int bst_height_helper(struct bstnode *n);


//see bst.h documentation
int bst_height(struct bsttree *t){
    struct bstnode *cur = t->root;
    return bst_height_helper(cur);
}

// bst_height_helper(n) return height of the tree.
// Time: O(n), where n is the number of nodes in t.
int bst_height_helper(struct bstnode *n){
    if (n == NULL) return 0;
    else 
    {
        int h_left = bst_height_helper(n->left);
        int h_right = bst_height_helper(n->right);
        if (h_left > h_right) 
        {
            return(++h_left);
        } else 
        {
            return(++h_right);
        }
    }
}


void mirror_helper(struct bstnode *n);


//see bst.h documentation
void mirror(struct bsttree *t) 
{
    assert(t != NULL);
    mirror_helper(t->root);
}

void mirror_helper(struct bstnode *n) 
{
    if (n == NULL) return;
    struct bstnode *temp = n->left;
    n->left = n->right;
    n->right = temp;
    mirror_helper(n->right);
    mirror_helper(n->left);
}
                                       

 


