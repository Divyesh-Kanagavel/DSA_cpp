#include<stdio.h>
#include <search.h> // hash table

void print_entry(ENTRY *entry)
{
	if (entry == NULL)
	{
		printf("NULL\n");
		return;
	}
	printf("%s -> %d\n", entry->key,entry->data);
}

int main()
{
	hcreate(30);
	ENTRY entry = {.key="hello", .data= (void*)1};
	ENTRY *result = hsearch(entry,ENTER); // to enter a entry into hash table
        print_entry(result);
        result = hsearch(entry, FIND); // to find if the entry exists inside the hash table
	print_entry(result);
	
      //   hdestroy();
       	return 0;
}       
