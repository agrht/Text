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
	TTextLink* ReadRec(ifstream &ifs);   //����
public:
	TText();        //����������� 
	~TText() {};	//���������� 
	TTextLink* GetpCurr(); //��������� �� ������� ������
	void GoFirstLink();   //������� �� ������ ������
	void GoNextLink();   //������� �� ��������� ������ � ��� �� ������
	void GoDownLink();   //������� �� ��������� ����������
	void GoPrevLink();   //�������� �� ���������� ������
	void SetLine(string str);   //�������� ������ �� ������� �������
	string GetLine();    //�������� ������� ������
	void InsNextLine(string str);   //�������� ��������� ������ � ���� �� ������
	void InsNextSection(string str);   //�������� ������ � ��� �� ������
	void InsDownLine(string str);   //�������� ������ � ��� �� ���������
	void InsDownSection(string str);   //�������� ������ � ��� �� ���������
	void DelNext();   //�������� ������ �� ��� �� ������
	void DelDown();   //�������� ������� �� ��� �� ������
	void Read(string fn);   //���� ������ �� �����
	void Write(string fn);   //����� ������ � ���� 	
	int Reset();   //���������� �� ������ ������ 
	int IsEnd();   //�����?
	int GoNext();   //������� � ���� ������
	void WriteRec(std:: ofstream& ofs, TTextLink* p); //�����
	void Print(TTextLink *p, TTextLink *curr); //������ �� �������
};