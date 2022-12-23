#ifndef C_LINKED_LIST_LIBRARY_H
#define C_LINKED_LIST_LIBRARY_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

/* Structure of a linked list */
typedef struct node
{
	int value;
	struct node *next;
} Node;

/* Printing the list*/
void print_list(Node *head);

/* Inserting and deleting elements*/
Node *insert_at_head(Node *head, int new_value);
Node *insert_at_tail(Node *head, int new_value);
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);

/* Common operation with linked lists*/
int length(Node *head);
int recursive_length(Node *node);
bool is_member(Node *node, int find_value);
int count_matches(Node *node, int find_value);
void replace_matches(Node *node, int find_value, int replace_value);

#endif