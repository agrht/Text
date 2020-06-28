#include<string>
#include<iostream>
using namespace std;
#include"TextLink.h"
#include "Text.h"

TTextLink::TTextLink(const char * _str, TTextLink *_pNext, TTextLink *_pDown)
{
	pNext = _pNext;
	pDown = _pDown;
	if (_str == NULL)
	{
		Str[0] = '/0';
	}
	else
		strcpy_s(Str, _str);
}

void* TTextLink::operator new(size_t size) 
{
	TTextLink *pLink = MemHeader.pFree;
	if (MemHeader.pFree)// != NULL)
		MemHeader.pFree = pLink->pNext;
	return pLink;
}

void TTextLink::operator delete(void *pMem) 
{
	TTextLink *pLink = (TTextLink *)pMem;
	pLink->pNext = MemHeader.pFree;
	MemHeader.pFree = pLink;
}

//инициализация
void TTextLink::InitMemSystem(int size) 
{
	MemHeader.pFirst = (TTextLink *) new char[sizeof(TTextLink)*size];
	MemHeader.pFree = MemHeader.pFirst;
	MemHeader.pLast = MemHeader.pFirst + (size - 1);
	TTextLink *pLink = MemHeader.pFirst;
	for (int i = 0; i < size - 1; i++)
	{
		pLink->Str[0] = '\0';
		pLink->pNext = pLink + 1;
		pLink++;
	}
	pLink->pNext = NULL;
}

void TTextLink::PrintFreeLink(void) 
{
	for (TTextLink *pLink = MemHeader.pFree; pLink != NULL; pLink = pLink->pNext)
	{
		if(pLink->Str[0]!='\0')
			cout << pLink->Str << endl;
	}
}

void TTextLink::MemCleaner(TText& txt) 
{
	for (txt.Reset(); !txt.IsEnd(); txt.GoNext())
	{
		string tmp = "&&&";
		tmp += txt.GetLine();
		txt.SetLine(tmp);
	}
	TTextLink *pLink;
	for (pLink = MemHeader.pFree; pLink != NULL; pLink = pLink->pNext)
	{
		strcpy_s(pLink->Str, "&&&");
	}
	for (pLink = MemHeader.pFirst; pLink <= MemHeader.pLast; pLink++)
	{
		if (strstr(pLink->Str, "&&&"))
		{
			strcpy_s(pLink->Str, pLink->Str + 3);
		}
		else
		{
			delete pLink;
		}
	}
}