#pragma once

template<typename T>
struct vector_node {
	T value;
	vector_node* next = nullptr;
};

template<typename T>
class vector {
public:
	vector() {}
	vector(T* mas, int length) 
	{
		for (int i = 0; i < length; i++)
		{
			push_back(mas[i]);
		}
	}
	vector(const vector& copy)
	{
		for (int i = 0; i < copy.length(); i++)
		{
			push_back(vector[i]);
		}
	}

	~vector()
	{
		clear();
	}

	void push_back(T member)
	{
		if (!head)
		{
			vector_node<T>* newHead = new vector_node<T>;
			newHead->value = member;
			head = newHead;
			return;
		}
		vector_node<T>* newNode = new vector_node<T>;
		newNode->value = member;
		vector_node<T>* cntr = head;
		while (cntr->next != nullptr)
		{
			cntr = cntr->next;
		}
		cntr->next = newNode
	}
	T pop_back() //here can be std::exceptions class
	{
		if (!head)
		{
			return 0; //throw
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		vector_node<T>* cntr = head;
		while (cntr->next->next != nullptr)
		{
			cntr = cntr->next;
		}
		delete cntr->next;
		cntr->next = nullptr;
		
	}
	
	T& operator[] (int number)
	{
		vector_node<T>* cntr = head;
		while (int i = 0; i < number; i++)
		{
			if (cntr == nullptr)
			{
				break;
				return 0; //throw
			}
			cntr = cntr->next;
		}
		return cntr->value;
	}

	void clear()
	{
		vector_node<T>* cntr, prev;
		cntr = head;
		if (!head)
		{
			return;
		}
		while (cntr->next != nullptr)
		{
			prev = cntr;
			cntr = cntr->next;
			delete prev;
		}
		delete cntr;
		head = nullptr;
	}

	int length()
	{
		if (!head)
		{
			return 0;
		}
		int i = 1;
		vector_node<T>* cntr = head;
		while (cntr->next != nullptr)
		{
			cntr = cntr->next;
			i++;
		}
		return i;
	}
private:
	vector_node<T>* head = nullptr;
};

