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
	for (int i = 2; i < 40; i++)
	{
		listInts.add(listInts[i - 2] + listInts[i - 1]);
	}
	
	int sum = 0;
	// Beispiel Loop (effiziente Vatiante)
	for (node<int>* tmp = listInts.first; tmp != nullptr; tmp = tmp->next)
	{
		sum += tmp->data;
	}
	float goldenRatio = static_cast<float>(sum) / static_cast<float>(sum - listInts.last->data);

	listInts.remove(20, 20);
	listInts.print();

	std::cout << "Golden ratio = " << goldenRatio << std::endl;

	return 0;
}

