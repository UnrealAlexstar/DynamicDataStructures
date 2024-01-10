#include <iostream>

using namespace std;

// CUSTOM DYNAMIC DATA STRUCTURES. Это уже есть в STL, просто делаю своё.

// интерфейс для всех типов для print и add добавить

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) // если не передадим адрес следующего элемента, то указываем что конец (0)
		{									      // если не передадим данные, то вызовется конструктор того типа данных, что передали
			this->data = data;
			this->pNext = pNext;

		}
	};
	int Size; 
	Node <T>* head;

};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List()
{

}


template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
	}
}

int main()
{
	cout << "Enter the dynamic data structure you want to work with:\n"
		"1 - Linked list\n"
		"2 - Doubly linked list\n"
		"3 - Binary tree\n"
		"4 - Stack\n"
		"5 - Queue\n"
		"6 - Priority queue\n"
		"7 - Deque (double-ended queue)\n";
	/*List<int> lst;
	lst.push_back(5);
	lst.push_back(10);*/


}

