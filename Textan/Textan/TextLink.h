#pragma once
#include<string>
#include<iostream>
using namespace std;
#define MemSize 100

class TTextLink;
class TText;

struct TTextMem
{
	TTextLink* pFirst;   //��������� �� ������ �����
	TTextLink* pLast;    //��������� �� ��������� �����
	TTextLink* pFree;   //��������� �� ������ ��������� �����
	friend class TTextLink;
};

//����� ��������-�������� ��� ������
class TTextLink
{
protected:
	TTextLink *pNext, *pDown;
	static TTextMem MemHeader; //������� ���������� �������
	friend class TText;
	char Str[81];
public:	
	static 	void InitMemSystem(int size = MemSize); //������������� ������
	static void PrintFreeLink(void); //������ ��������� �������
	void* operator new(size_t size); //��������� �����
	void operator delete (void *pMem); //������������ �����
	static void MemCleaner(TText& txt);   //������ ������
	TTextLink(const char *_str = NULL, TTextLink *_pNext = NULL, TTextLink *_pDown = NULL); //�����������
	~TTextLink() {}; //����������

	friend ostream& operator <<(ostream& os, const TTextLink& Link)
	{
		return os << Link.Str;
	}
};
