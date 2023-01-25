#include "c_linked_list_library.h"

int main(void)
{
	Node *list1_head = NULL;
	list1_head = insert_at_head(list1_head, 5);
	list1_head = insert_at_head(list1_head, 5);
	list1_head = insert_at_head(list1_head, 5);
	list1_head = insert_at_tail(list1_head, 7);
	list1_head = insert_at_head(list1_head, 11);
	list1_head = insert_at_tail(list1_head, 200);
	// list1_head = delete_at_head(list1_head);
	// list1_head = delete_at_tail(list1_head);
	replace_matches(list1_head, 5, 500);
	int num_deleted = 0;
	efficient_delete_match(list1_head, 500, &num_deleted);
	if (num_deleted > 0)
	{
		printf("%d occurences found and deleted\n", num_deleted);
	}
	else
	{
		printf("None\n");
	}
	bool deleted;
	list1_head = delete_first_match(list1_head, 800, &deleted);
	if (deleted)
		printf("A node has been deleted\n");
	else if (!deleted)
		printf("No node have been deleted\n");
	
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