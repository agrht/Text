#pragma once
template <class T>

class TStack
{
	T *mas;
	int num;
	int size;
public:
	TStack(int _size = 100000)
	{
		if (_size <= 0) 
			throw _size;
		size = _size;
		mas = new T[size];
		num = -1;
	}

	~TStack()
	{
		delete[] mas;
	}

	TStack(const TStack& stack)
	{
		size = stack.size;
		mas = new T[size];
		num = stack.num;
		for (int i = 0; i <= num; i++)
			mas[i] = stack.mas[i];
	}

	TStack& operator= (const TStack& stack)
	{
		if (this != &stack) 
		{
			delete[] mas;
			size = stack.size;
			mas = new T[size];
			num = stack.num;
			for (int i = 0; i <= num; i++)
				mas[i] = stack.mas[i];
		}
		return *this;
	}

	int GetSize() const 
	{
		return num;
	}

	void Clear()
	{
		num = -1;
	}

	bool IsEmpty() const
	{
		return (num == -1);
	}

	bool IsFull() const
	{
		return (num == (size - 1));
	}

	void Push(T el)
	{
		if (IsFull())
			throw el;
		else
			mas[++num] = el;
	}

	T Pop() 
	{
		if (num == -1)
			throw num;
		return mas[num--];
	}

	T Top()
	{
		if (num == -1)
			throw num;
		return mas[num];
	}
};