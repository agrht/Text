#include<fstream>
#include<string>
#include "TextLink.h"
#include "Stack.cpp"
#include "Text.h"

using namespace std;
static int Size;
TText::TText()
{
	pFirst = NULL;
	Stack.Clear();
}

TTextLink* TText::GetpCurr()
{
	return pCurr;
}

void TText::GoFirstLink()
{
	pCurr = pFirst;
	Stack.Clear();
}

void TText::GoNextLink()
{
	if (!pCurr)
		throw 7;
	if (pCurr->pNext == NULL)
		return;
	Stack.Push(pCurr);
	pCurr = pCurr->pNext;
}

void TText::GoDownLink()
{
	if (!pCurr)
		throw 77;
	if (pCurr->pDown == NULL)
		return;
	Stack.Push(pCurr);
	pCurr = pCurr->pDown;
}

void TText::GoPrevLink()
{
	if (pCurr == NULL)
		throw 777;
	if (Stack.IsEmpty())
		return;
	pCurr = Stack.Pop();
}

void TText::SetLine(string str)
{
	if (!pCurr)
		throw 3;
	strcpy_s(pCurr->Str, str.c_str());
}

string TText::GetLine()
{
	return string(pCurr->Str);
}

void TText::InsNextLine(string str)
{
	if (!pCurr)
		throw 33;
	TTextLink *p = new TTextLink(str.c_str());
	p->pNext = pCurr->pNext;
	pCurr->pNext = p;
}

void TText::InsNextSection(string str)
{
	if (!pCurr)
		throw 1;
	TTextLink *p = new TTextLink(str.c_str());
	p->pDown = pCurr->pNext;
	pCurr->pNext = p;
}

void TText::InsDownLine(string str)
{
	if (!pCurr)
		throw 11;
	TTextLink *p = new TTextLink(str.c_str());
	p->pNext = pCurr->pDown;
	pCurr->pDown = p;
}

void TText::InsDownSection(string str)
{
	if (!pCurr)
		throw 123;
	TTextLink *p = new TTextLink(str.c_str());
	p->pDown = pCurr->pDown;
	pCurr->pDown = p;
}

void TText::DelNext()
{
	if (!pCurr)
		throw 12;
	if (!pCurr->pNext)
		return;
	TTextLink *p = pCurr->pNext;
	pCurr->pNext = p->pNext;
	delete p;
}

void TText::DelDown()
{
	if (!pCurr)
		throw 6;
	if (!pCurr->pDown)
		return;
	TTextLink *p = pCurr->pDown;
	pCurr->pDown = p->pNext;
	delete p;
}

void TText::Read(string fn)
{
	ifstream ifs(fn);
	pFirst = ReadRec(ifs);
}

TTextLink* TText::ReadRec(ifstream& ifs)
{
	TTextLink *pHead, *p;
	pHead = new TTextLink;
	pHead = NULL;
	p = NULL;
	char str[81];
	while (!ifs.eof())
	{
		ifs.getline(str, 80, '\n');
		if (str[0] == '}')
			break;
		else
			if (str[0] == '{')
				p->pDown = ReadRec(ifs);
			else
			{
				TTextLink *tmp = new TTextLink(str);
				if (pHead == NULL)
					pHead = p = tmp;
				else
				{
					p->pNext = tmp;
					p = p->pNext;
				}
			}
	}
	return pHead;
}

void TText::Write(string fn)
{
	while (!Stack.IsEmpty()) Stack.Pop();
	ofstream ofs(fn);
	WriteRec(ofs, pFirst);
}

void TText::WriteRec(ofstream& ofs, TTextLink *p)
{
	if (p)
	{
		string s;
		for (int i = 0; i < Size; i++)  s += ' ';
		s += p->Str;
		ofs << s << endl;
		if (p->pDown)
		{
			ofs << '{' << endl;
			Stack.Push(p);
			WriteRec(ofs, p->pDown);
			Stack.Pop();
			ofs << '}' << endl;
			Size++;
		}
		if (p->pNext)
		{
			WriteRec(ofs, p->pNext);
			Size++;
		}
	}
	Size--;
}

int TText::Reset()
{
	while (!Stack.IsEmpty()) Stack.Pop();
	pCurr = pFirst;
	if (pCurr != NULL)
	{
		Stack.Push(pCurr);
		if (pCurr->pNext != NULL)
			Stack.Push(pCurr->pNext);
		if (pCurr->pDown != NULL)
			Stack.Push(pCurr->pDown);
	}
	return IsEnd();
}

int TText::IsEnd()
{
	return Stack.IsEmpty();
}

int TText::GoNext()
{
	if (!IsEnd())
	{
		pCurr = Stack.Top();
		Stack.Pop();
		if (pCurr != pFirst)
		{
			if (pCurr->pNext != NULL)
				Stack.Push(pCurr->pNext);
			if (pCurr->pDown != NULL)
				Stack.Push(pCurr->pDown);
		}
		return true;
	}
	return false;
}

void TText::Print(TTextLink *p, TTextLink *curr)
{
	if (p)
	{
		string s;
		for (int i = 0; i < Size; i++)  s += '  ';
		s += p->Str;
		if (curr == p) cout << "/pCurr/ " << s << endl;
		else cout << "/-----/ " << s << endl;
		if (p->pDown)
		{
			Stack.Push(p);
			Print(p->pDown, curr);
			Stack.Pop();
			Size++;
		}
		if (p->pNext)
		{
			Print(p->pNext, curr);
			Size++;
		}
		Size--;
	}
	pCurr = curr;
}
