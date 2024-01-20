#include <iostream>

using namespace std;

// CUSTOM DYNAMIC DATA STRUCTURES. Это уже есть в STL, просто делаю своё.

// интерфейс для всех типов для print и add добавить ? получится ли. Лучше не стоит наверное

// структуры в различных файлах 
enum Struct_Name { List = 1, DoubledLinkedList, Binary_Tree, Stack, Queue, Priority_queue, Qeque};

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	int get_size() { return size; };
	void pop_front(); // удалить самый первый элемент списка
	void clear();

	T& operator [](const int index);

	void push_front(T data);
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();

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
	int size; 
	Node <T>* head; // корневой, начальный элемент

};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
	clear();
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
		current->pNext = new Node<T>(data);

	}
	size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;

	delete temp;

	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr) // либо до конца списка
	{
		if (counter == index) // либо до искомого индекса
		{
			return current->data;
		}
		else 
		{
			current = current->pNext;
			counter++;
		}
	}
	
	cerr << "Error: wrong index"; 
}

template<typename T>
void List<T>::push_front(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = new Node<T>(data);
		current->pNext = head;
		head = current;
	}
	size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (head == nullptr || index <= 0) // 0 элементов или индекс <= 0
	{
		push_front(data);										
	}
	else if (index > size)   // 1 элемент или индекс больше размера списка 
	{
		push_back(data);										
	}
	else // между 2-мя элементами
	{
		 
		Node<T>* left = head;
		Node<T>* right;

		for (int i = 0; i < index - 1; i++)
		{
			left = left->pNext;
		}
		right = left->pNext; 

		Node<T>* current = new Node<T>(data, right); // сразу же текущий указывает на  right
		left->pNext = current;

		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index >= size)
	{
		index = size;
		pop_back();
		return;
	}

	if (head == nullptr)
	{
		cout << "List is empty";
	}
	else if (index <= 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* current;
		Node<T>* left = head;
		Node<T>* right;

		for (int i = 0; i < index - 1 ; i++)
		{
			left = left->pNext;
		}
		right = left->pNext->pNext;

		delete left->pNext;
		left->pNext = right; // связываем левый и правый элемент
		size--; 
	}

}

template<typename T>
void List<T>::pop_back()
{
	int k = 0;
	if (head == nullptr)
	{
		cout << "List is empty\n";
		return;
	}
	else if (head->pNext == nullptr)
	{
		clear();
	}
	else
	{
		Node<T>* current = head;
		Node<T>* left = head;
		while (current->pNext != nullptr)
		{
			left = current;
			current = current->pNext;
		}
		left->pNext = nullptr;
		delete current;
		size--;
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
		"7 - Deque (double-ended queue)\n \n"; //Дэк, двусторонняя очередь
	
	List<int> lst;
	lst.insert(999, 2);
	lst.insert(999, 2);
	lst.insert(999, 2);
	lst.push_back(5);
	lst.push_back(10);
	//lst.push_back(15);
	//lst.push_back(20);
	//lst.push_front(100);
	//lst.push_front(200);

	//lst.push_back(30);
	//lst.push_back(40);

	//lst.push_front(300);
	//lst.push_front(400);

	
	lst.insert(999, 2);

	while (true)
	{
		for (int i = 0; i < lst.get_size(); i++)
		{
			cout <<"Element #"<<i<<" = "<< lst[i] << endl;
		}
		int n;
		cout << "Input the num of elem to remove:\n";
		cin >> n;
		lst.removeAt(n);
	}

	
	
	

	/*cout << "\nNow pop_front\n\n";
	lst.pop_front();
	
	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << "\nNow pop_front\n\n";
	lst.pop_front();

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << "\nNow push_back\n\n";
	lst.push_back(20000);
	
	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst[i] << endl;
	}*/
}

