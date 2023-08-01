#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <queue>
template <typename T>
class queue
{
	struct que
	{
		T data;
		float priority = 0;
		que* next = nullptr;
		que* prev = nullptr;

		que() {}

		que(T data, float priority, que* next = nullptr, que* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
			this->priority = priority;

		}
	};

	size_t size = 0;

	que* root = nullptr;
	que* head = nullptr;


public:
	void enqueue(T _data, float prior)
	{
		que* newcell = new que(_data, prior);

		if (!size)
		{
			root = head = newcell;
		}
		else if (newcell->priority < head->priority)
		{
			head->next = newcell;
			newcell->prev = head;
			head = newcell;
		}
		else if (newcell->priority > root->priority)
		{
			root->prev = newcell;
			newcell->next = root;
			root = newcell;
		}
		else
		{
			que* temp = root;
			while (temp->next != nullptr)
			{
				if (newcell->priority >= temp->priority)
				{
					newcell->next = temp;
					newcell->prev = temp->prev;
					temp->prev->next = newcell;
					temp->prev = newcell;
					break;
				}
				temp = temp->next;
			}
		}

		++size;
	}

	T dequeue()
	{
		if (size > 0)
		{
			que* temp = head;
			T t = temp->data;
			if (size == 1)
			{
				root = nullptr;
				head = nullptr;
			}
			else
			{
				head = head->prev;
				head->next = nullptr;
			}
			--size;
			delete temp;
			return t;
		}

		throw;
	}

	bool check_queue()
	{
		if (size > 0)
		{
			return 1;
		}
		return 0;
	}

	int get_size()
	{
		return size;
	}



	bool find(T _data)
	{
		que* temp = root;
		if (size > 0)
		{
			while (temp != nullptr)
			{
				if (temp->data == _data)
				{
					return true;
				}
				temp = temp->next;
			}
		}

		return false;
	}
};

void main()
{
	queue<int> a;
	a.enqueue(2, 2);
	a.enqueue(3, 3);
	a.enqueue(1, 1);
	a.enqueue(5, 5);
	a.enqueue(4, 4);
	a.enqueue(23, 2.4);
	printf("%d\n", a.dequeue());
	printf("%d\n", a.dequeue());
	printf("%d\n", a.dequeue());
	printf("%d\n", a.dequeue());
	printf("%d\n", a.dequeue());
	printf("%d\n", a.dequeue());

	system("pause");
}