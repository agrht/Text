#pragma once
#include "TextLink.h"
#include "Stack.cpp"
#include<string>
using namespace std;
class TText
{
protected:
	TTextLink *pFirst;
	TTextLink *pCurr;
	TStack <TTextLink*> Stack;
	TTextLink* ReadRec(ifstream &ifs);   //ввод
public:
	TText();        //конструктор 
	~TText() {};	//деструктор 
	TTextLink* GetpCurr(); //указатель на текущую строку
	void GoFirstLink();   //перейти на первую строку
	void GoNextLink();   //перейти на следующий раздел в том же уровне
	void GoDownLink();   //перейти на следующий подуровень
	void GoPrevLink();   //вернутся на предыдущую строку
	void SetLine(string str);   //записать строку на текущую позицию
	string GetLine();    //получить текущую строку
	void InsNextLine(string str);   //вставить следующую строку в этом же уровне
	void InsNextSection(string str);   //вставить раздел в том же уровне
	void InsDownLine(string str);   //вставить строку в том же подуровне
	void InsDownSection(string str);   //вставить раздел в том же подуровне
	void DelNext();   //удаление строки на том же уровне
	void DelDown();   //удаление раздела на том же уровне
	void Read(string fn);   //ввод текста из файла
	void Write(string fn);   //вывод текста в файл 	
	int Reset();   //установить на первую запись 
	int IsEnd();   //конец?
	int GoNext();   //переход к след записи
	void WriteRec(std:: ofstream& ofs, TTextLink* p); //вывод
	void Print(TTextLink *p, TTextLink *curr); //печать на консоль
};