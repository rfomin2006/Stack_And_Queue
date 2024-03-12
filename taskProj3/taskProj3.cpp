#include <iostream>
#include <list>

const int list_size = 1000;

struct Stack {
	int top;
	int array[list_size];
};

struct Queue {
	int front, rear;
	std::string array[list_size];
};

void stack_push(Stack& s, int value) {
	if (s.top == list_size - 1) {
		std::cout << "Stack overflow" << std::endl;
		return;
	}
	s.top++;
	s.array[s.top] = value;
}

void stack_pop(Stack& s) {
	if (s.top == -1) {
		std::cout << "Stack underflow" << std::endl;
		return;
	}
	s.top--;
}

int stack_peek(Stack& s) {
	if (s.top == -1) {
		std::cout << "Stack is empty" << std::endl;
		return -1;
	}
	return s.array[s.top];
}

void queue_enqueue(Queue& q, std::string value) {
	if (q.rear == list_size - 1) {
		std::cout << "Queue overflow" << std::endl;
		return;
	}
	if (q.front == -1) {
		q.front = 0;
	}
	q.rear++;
	q.array[q.rear] = value;
}

void queue_dequeue(Queue& q) {
	if (q.front == -1 || q.front > q.rear) {
		std::cout << "Queue underflow" << std::endl;
		return;
	}
	q.front++;
}

std::string queue_peek(Queue& q) {
	if (q.front == -1 || q.front > q.rear) {
		std::cout << "Queue is empty" << std::endl;
		return "";
	}
	return q.array[q.front];
}

template<typename T>
struct stack_list {
	std::list<T> lst;
	int c = 0;

	void add(T el)
	{
		if (c < list_size)
		{
			lst.push_back(el);
			c++;
		}
		else
		{
			std::cout << "Overdose";
		}
	}

	T get()
	{
		if (c == 0)
		{
			std::cout << "Cringe";
			return -1;
		}
		else {
			T to_return = lst.back();
			lst.pop_back();
			return to_return;
		};
	}
	
};

template<typename T>
struct queue_list
{
	std::list<T> lst;
	int c = 0;

	void add(T el)
	{
		if (c < list_size)
		{
			lst.push_back(el);
			c++;
		}
		else
		{
			std::cout << "Overdose";
		}
	}

	T get()
	{
		if (c == 0)
		{
			std::cout << "Cringe";
			return -1;
		}
		else
		{
			T to_return = lst.front();
			lst.pop_front();
			return to_return;
		}
	}
};

int main()
{
	stack_list<int> int_stack;

	queue_list<int> int_queue;


	for (int i = 0; i < 10; i++)
	{
		int_queue.add(i);
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << int_queue.get() << "\n";
	}

	return 0;
}