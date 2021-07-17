#include <iostream>

#include "include/LinkedList.h"

int main()
{
	
	LinkedList<std::string> list;
	list.add("Objekt_0");
	list.add("Objekt_1");
	list.add("Objekt_2");
	list.remove(1);
	list.print();

	list.clear();
	list.print();

	list.add("Objekt_0");
	list.add("Objekt_2");
	list.insert(1, "Objekt_1");
	list.print();	

	LinkedList<int> listInts;
	listInts.add(0);
	listInts.add(1);
	for (int i = 2; i < 20; i++)
	{
		listInts.add(listInts[i - 2] + listInts[i - 1]);
	}
	listInts.print();




	return 0;
}

