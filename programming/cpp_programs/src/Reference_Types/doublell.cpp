/* doubly linked list */
// forward linked list

#include <cstdio>

struct Element
{
	Element* next{};
    Element* prev{};
	char prefix[2];
	int operating_number;
	void insert_after(Element* element)
	{
		element->next = next;
        element->prev = this;
		if (next)
		{
			next->prev = element;
		}
		next = element;
	}

    void insert_before(Element* element)
    {
        element->prev = prev;       
        element->next = this;
		if (prev)
            prev->next = element;
        prev = element;
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
	trooper1.insert_after(&trooper3);
	trooper3.insert_before(&trooper2);
	for(Element* cursor = &trooper1; cursor;cursor=cursor->next)
	{
		printf("stormtrooper %c%c-%d\n",cursor->prefix[0],cursor->prefix[1],cursor->operating_number);
	}
    for(Element* cursor = &trooper3; cursor;cursor=cursor->prev)
	{
		printf("stormtrooper %c%c-%d\n",cursor->prefix[0],cursor->prefix[1],cursor->operating_number);
	}

	return 0;
}

