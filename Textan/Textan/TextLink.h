#pragma once
#include<string>
#include<iostream>
using namespace std;
#define MemSize 100

class TTextLink;
class TText;

struct TTextMem
{
	TTextLink* pFirst;   //указатель на первое звено
	TTextLink* pLast;    //указатель на последнее звено
	TTextLink* pFree;   //указатель на первое свободное звено
	friend class TTextLink;
};

//класс объектов-значений для текста
class TTextLink
{
protected:
	TTextLink *pNext, *pDown;
	static TTextMem MemHeader; //система управления памятью
	friend class TText;
	char Str[81];
public:	
	static 	void InitMemSystem(int size = MemSize); //инициализация памяти
	static void PrintFreeLink(void); //печать свободных звеньев
	void* operator new(size_t size); //выделение звена
	void operator delete (void *pMem); //освобождение звена
	static void MemCleaner(TText& txt);   //сборка мусора
	TTextLink(const char *_str = NULL, TTextLink *_pNext = NULL, TTextLink *_pDown = NULL); //конструктор
	~TTextLink() {}; //деструктор

	friend ostream& operator <<(ostream& os, const TTextLink& Link)
	{
		return os << Link.Str;
	}
};
