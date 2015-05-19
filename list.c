//list.c

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


// see list.h for documentation
struct llist *create_list(void) {
	struct llist *lst = malloc(sizeof(struct llist));
	lst->first = NULL;
	lst->last = NULL;
	lst->len=0;
 	return lst;
}

// see list.h for documentation
void destroy_list(struct llist *lst) {
	assert(lst);
	struct llnode *current = lst->first; 
	struct llnode *next;
	while (current != NULL) {
		next = current->next; // note the next pointer
		free(current); // delete the node
		current = next; // advance to the next node
	}
	free(lst); 
}


// see list.h for documentation
int list_length(struct llist *lst) {
  	assert(lst);
	return lst->len;
}




// see list.h for documentation
void print_list(struct llist *lst) {
  	assert(lst);
	struct llnode *current;
	for (current = lst->first; current != NULL; current = current->next)
		printf("  %d", current->item);
	printf("\n");
}
	

// see list.h for documentation
void add_first(int n, struct llist *lst) {
    assert(lst);
	struct llnode *new = malloc(sizeof(struct llnode));
    new->item = n;
    new->next = lst->first;
    lst->first = new;
    if (lst->len == 0) lst->last = new;
    ++lst->len;
}

// see list.h for documentation
void add_last(int n, struct llist *lst) {
    assert(lst);
    struct llnode *new = malloc(sizeof(struct llnode));
    new->item = n;
    new->next = NULL;
    if (lst->len == 0) {
        lst->first = new;
    } else {
        lst->last->next = new;
    }
    lst->last = new;
    ++lst->len;
}

// see list.h for documentation
int delete_first(struct llist *lst) {
    assert(lst);
    struct llnode *new = lst->first;
	int temp = lst->first->item;
    if (lst->len == 1) lst->last = NULL;
    lst->first = lst->first->next;
    free(new);
    --lst->len;
    return temp;
}

// see list.h for documentation
int get_ith(struct llist *lst, int index) {
    assert(-1 < index && index < (lst->len));
    struct llnode *cur = lst->first;
    struct llnode *prev = NULL;
    while ((index > 0) && (cur != NULL)) {
        prev = cur;
        cur = cur->next;
        --index;
    }
    return cur->item;          	
}


// see list.h for documentation
//refer from section 11 slide 26
void insert_ith(struct llist *lst, int index, int data) {
    assert(0 <= index && index <= (lst->len));
    struct llnode *cur = lst->first;
    struct llnode *prev = NULL;
    while ((index > 0) && (cur != NULL)) {
        prev = cur;
        cur = cur->next;
        --index;
    }
    struct llnode *new = malloc(sizeof(struct llnode));
    new->item = data;
    new->next = cur;
    if (prev == NULL) {
        lst->first = new;
        lst->last = new;        
    } else if (cur == NULL) {
        prev->next = new;
        lst->last = new;
    } else {
        prev->next = new;
    }
    ++lst->len;
}

// see list.h for documentation
void lst_append(struct llist *lst1, struct llist *lst2) {
	assert(lst1 != NULL && lst2 != NULL);
    lst1->last->next = lst2->first;
    lst1->last = lst2->last;
    lst1->len = lst1->len + lst2->len;
    lst2->len = 0;
    lst2->first = NULL;
    lst2->last = NULL;
}

// see list.h for documentation
bool eq_list(struct llist *lst1, struct llist *lst2) {
	assert(lst1 != NULL && lst2 != NULL);
    if (lst1->len != lst2->len) return false;
    struct llnode *cur1 = lst1->first;
    struct llnode *cur2 = lst2->first;
    int acc = 0;
    while (acc < lst1->len) {
        if (cur1->item != cur2->item) return false;
        cur1 = cur1->next;
        cur2 = cur2->next;
        ++acc;
    }
    return true;
}


// see list.h for documentation
int maxminlist(struct llist *lst, int *max, int *min)
{
    struct llnode *cur = lst->first->next;
    *max = lst->first->item;
    *min = lst->first->item;
    int acc = 1;
    if (lst->len == 0) {
        return 0;
    } else {
        while (acc < lst->len) {
            if (cur->item > *max) *max = cur->item;
            if (cur->item < *min) *min = cur->item;
            cur = cur->next;
            ++acc;
        }
        return 1;
    }    
}


// see list.h for documentation
void list_map( struct llist *lst, int (*function_ptr)( int) ) {
    assert(lst != NULL);
    struct llnode *cur = lst->first;
    int acc = 0;
    while (acc < lst->len) {
        cur->item = function_ptr(cur->item);
        cur = cur->next;
        ++acc;   
    }
}