#include <iostream>
#include <string>

template<class T>
struct node
{
	node<T>* next;
	T data;
};

template<class T>
class LinkedList
{
public:

	int size;
	node<T>* first;
	node<T>* last;

	LinkedList<T>()
	{
		size = 0;
		first = nullptr;
		last = nullptr;
	}

	void replace(int indx, T data)
	{
		getNode(indx)->data = data;
	}

	void add(T data)
	{
		size++;
		if (first == nullptr)
		{
			first = new node<T>;
			first->data = data;
			first->next = nullptr;
			last = first;
		}
		else
		{
			node<T>* tempNodePtr = new node<T>;
			tempNodePtr->data = data;
			tempNodePtr->next = nullptr;
			last->next = tempNodePtr;
			last = tempNodePtr;
		}
	}

	T& getData(int index)
	{
		node<T>* tempPtr = this->first;
		for (int i = 0; i < index; i++) {
			tempPtr = tempPtr->next;
		}
		return tempPtr->data;
	}

	void remove(int index, int numberOfElements = 1)
	{
		node<T>* start;
		node<T>* end;
		node<T>* tmp;
		if (index == 0)
		{
			end = first;
			for (int i = 0; i < numberOfElements; i++)
			{
				tmp = end;
				end = end->next;
				delete tmp;
			}
			first = end;
		}
		else
		{
			start = getNode(index - 1);
			if (size == numberOfElements + index) {
				start->next = nullptr;
				last = start;
			}
			else
			{
				end = start->next;
				for (int i = 0; i < numberOfElements; i++)
				{
					tmp = end;
					end = end->next;
					delete tmp;
				}
				start->next = end;
			}
		}
		size -= numberOfElements;
	}

	void clear()
	{
		remove(0, size);
	}

	T& operator[](int index)
	{
		return getData(index);
	}

	void insert(int index, T data)
	{
		node<T>* newNode = new node<T>;
		if (index == 0)
		{
			newNode->next = first;
			newNode->data = data;
			first = newNode;
		}
		else
		{
			node <T>* currentNode = getNode(index - 1);
			newNode->data = data;
			newNode->next = currentNode->next;
			currentNode->next = newNode;
		}
		if (index == size) {
			last = newNode;
		}

		size++;
	}

	node<T>* getNode(int index)
	{
		node<T>* tempPtr = first;
		for (int i = 0; i < index; i++)
		{
			tempPtr = tempPtr->next;
		}
		return tempPtr;
	}

	void print()
	{
		int indx = 0;
		for (node<T>* tempPtr = first; tempPtr != nullptr; tempPtr = tempPtr->next)
		{
			std::cout << "Index: " << indx++ << ", Data: " << tempPtr->data << std::endl;
		}
		std::cout << "Die Liste hat " << size << " ELemente." << std::endl;
	}
};