// forward linked list

#include <cstdio>

struct Element
{
	Element* next{};
	char prefix[2];
	int operating_number;
	void insert_after(Element* element)
	{
		element->next = next;
		next = element;
	}

};

int main()
{
	Element trooper1,trooper2,trooper3;
	trooper1.prefix[0] = 'T';
	trooper1.prefix[1] = 'K';
	trooper2.prefix[0] = 'N';
	trooper2.prefix[1] = 'F';
	trooper3.prefix[0] = 'L';
	trooper3.prefix[1] = 'S';
	trooper1.operating_number = 421;
	trooper2.operating_number = 5;
	trooper3.operating_number = 218;
	trooper1.insert_after(&trooper2);
	trooper2.insert_after(&trooper3);
	for(Element* cursor = &trooper1; cursor;cursor=cursor->next)
	{
		printf("stormtrooper %c%c-%d\n",cursor->prefix[0],cursor->prefix[1],cursor->operating_number);
	}
	return 0;
}

