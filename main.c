#include "c_linked_list_library.h"

int main(void)
{
	Node *list1_head = NULL;
	list1_head = insert_at_head(list1_head, 5);
	list1_head = insert_at_tail(list1_head, 7);
	list1_head = insert_at_head(list1_head, 11);
	list1_head = insert_at_tail(list1_head, 200);
	// list1_head = delete_at_head(list1_head);
	// list1_head = delete_at_tail(list1_head);
	replace_matches(list1_head, 5, 500);
	
	print_list(list1_head);
	printf("Len is %d\n",
			recursive_length(list1_head));
	if (is_member(list1_head, 5))
		printf("5 is in the list\n");
	else
		printf("5 is not in the list\n");
	printf("Matches = %d\n", count_matches(list1_head, 4));
	printf("Matches = %d\n", count_matches(list1_head, 500));
}