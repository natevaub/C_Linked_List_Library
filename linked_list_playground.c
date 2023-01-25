
#include "c_linked_list_library.h"

void print_list(Node *head)
{
	Node *current;
	current = head;
	int i = 0;

	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

Node *insert_at_head(Node *head, int new_value)
{
	Node *new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;
	if (head == NULL) return new_node;
	else 
	{
		new_node->next = head;
		return new_node;
	}
}

Node *insert_at_tail(Node *head, int new_value)
{
	Node *new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;
	if (head == NULL) return new_node;
	else
	{
		Node *current = head;
		while (current->next!= NULL)
			current = current->next;
		current->next = new_node;
		return head;
	}
}

Node *delete_at_head(Node *head)
{
	if (head == NULL) return NULL;
	else
	{
		Node *to_return = head->next;
		free(head);
		return to_return;
	}
}

Node *delete_at_tail(Node *head)
{
	if (head == NULL) return NULL;
	else if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		Node *current = head;
		Node *prev = NULL;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		free(current);
		return head;
	}
}

int length(Node *head)
{
	Node *current;
	current = head;
	int length = 0;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}
	return length;
}

int recursive_length(Node *node)
{
	if (node == NULL) return 0;
	else return 1 + recursive_length(node->next);
}

bool is_member(Node *node, int find_value)
{
	if (node == NULL) return false;
	else if (node->value == find_value) return true;
	else return is_member(node->next, find_value);
}

int count_matches(Node *node, int find_value)
{
	if (node == NULL) return 0;
	else if (node->value == find_value)
		return 1 + count_matches(node->next, find_value);
	else return count_matches(node->next, find_value);
}

void replace_matches(Node *node, int find_value, int replace_value)
{
	if (node != NULL)
	{
		if (node->value == find_value)
			node->value = replace_value;
		replace_matches(node->next, find_value, replace_value);
	}
}

Node *delete_first_match(Node *head, int delete_value, bool *was_deleted)
{
	if (head == NULL)
	{
		*was_deleted = false;
		return NULL;
	}

	if (head->value == delete_value)
	{
		Node *temp = head->next;
		free(head);
		*was_deleted = true;
		return temp;
	}

	Node *current = head->next;
	Node *prev = head;

	while (current != NULL)
	{
		if (current->value == delete_value)
		{
			prev->next = current->next;
			free(current);
			*was_deleted = true;
			return head;
		}

		prev = current;
		current = current->next;
	}
	*was_deleted = false;
	return head;
}


Node *efficient_delete_match(Node *head, int delete_value, int *num_deleted)
{
	*num_deleted = 0;

	if (head == NULL) return NULL;

	Node *current, *temp, *new_head;
	current = head;
	while (current->value == delete_value)
	{
		temp = current;
		current = current->next;
		free(temp);
		*num_deleted = *num_deleted + 1;

		if (current == NULL) return NULL;
	}

	new_head = current;

	while (current->next != NULL)
	{
		if (current->next->value == delete_value)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			*num_deleted = *num_deleted + 1;
		}
		else current = current->next;
	}

	return new_head;
}
