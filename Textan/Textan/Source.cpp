#include <string>
#include<conio.h>
#include<fstream>
#include<iostream>
#include "Text.h"
#include "TextLink.h"

using namespace std;

TTextMem TTextLink::MemHeader;
int main()
{
	TTextLink::InitMemSystem();
	TTextLink *text, *t;
	TText txt;
	string str;
	int key = 0;
	txt.Read("schon.txt");
	txt.GoFirstLink();
	t = txt.GetpCurr();
	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "�������:" << endl;
		cout << "1 - ������� �� ��������� ����������" << endl;
		cout << "2 - ������� �� ��������� ������ � ��� �� ������" << endl;
		cout << "3 - ��������� �� ���������� �������" << endl;
		cout << "4 - ������� �� ������ �������" << endl;
		cout << "5 - �������� ������ �� ������� �������" << endl;
		cout << "6 - �������� ��������� ������ � ���� �� ������" << endl;
		cout << "7 - �������� ������ � ���� �� ���������" << endl;
		cout << "8 - �������� ������ � ���� �� ������" << endl;
		cout << "9 - �������� ������ � ���� �� ���������" << endl;
		cout << "10 - �������� ������ �� ��� �� ������" << endl;
		cout << "11 - �������� ������� �� ��� �� ������" << endl;
		cout << "12 - ��������� ����� �� �����" << endl;
		cout << "13 - ����� (����������) ������ � ����" << endl;
		cout << "14 - ����� ������ �� �������" << endl;
		cout << "15 - �����" << endl;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			txt.GoDownLink();
			break;
		}
		case 2:
		{
			txt.GoNextLink();
			break;
		}
		case 3:
		{
			txt.GoPrevLink();
			break;
		}
		case 4:
		{
			txt.GoFirstLink();
			break;
		}
		case 5:
		{
			cout << "����� ������:" << endl;
			cin >> str;
			//getline(cin, str, ';');
			txt.SetLine(str);
			break;
		}
		case 6:
		{
			cout << "����� ������:" << endl;
			cin >> str;
			//getline(cin, str, ';');
			txt.InsNextLine(str);
			break;
		}
		case 7:
		{
			cout << "����� ������:" << endl;
			cin >> str;
			//getline(cin, str, ';');
			txt.InsDownLine(str);
			break;
		}
		case 8:
		{
			cout << "����� ������:" << endl;
			cin >> str;
			//getline(cin, str, ';');
			txt.InsNextSection(str);
			break;
		}
		case 9:
		{
			cout << "����� ������:" << endl;
			cin >> str;
			//getline(cin, str, ';');
			txt.InsDownSection(str);
			break;
		}
		case 10:
		{
			txt.DelNext();
			break;
		}
		case 11:
		{
			txt.DelDown();
			break;
		}
		case 12:
		{
			txt.Read("schon.txt");
			break;
		}
		case 13:
		{
			txt.Write("schon.txt");
			break;
		}
		case 14:
		{
			text = txt.GetpCurr();
			txt.Print(t, text);
			break;
		}
		case 15:
		{
			cout << "�����" << endl;
			break;
		}
		}
	} while (key != 15);
	cout << "������ ��������� �������" << endl;
	setlocale(LC_ALL, "C");
	TTextLink::PrintFreeLink();
	TTextLink::MemCleaner(txt);
	setlocale(LC_ALL, "Russian");
	cout << "����� ������ ������" << endl;
	setlocale(LC_ALL, "C");
	TTextLink::PrintFreeLink();
	_getch();
}