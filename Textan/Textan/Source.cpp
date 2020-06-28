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
		cout << "Команды:" << endl;
		cout << "1 - Перейти на следующий подуровень" << endl;
		cout << "2 - Перейти на следующий раздел в том же уровне" << endl;
		cout << "3 - Вернуться на предыдущую строчку" << endl;
		cout << "4 - Перейти на первую строчку" << endl;
		cout << "5 - Записать строку на текущую позицию" << endl;
		cout << "6 - Записать следующую строку в этом же уровне" << endl;
		cout << "7 - Записать строку в этом же подуровне" << endl;
		cout << "8 - Добавить раздел в этом же уровне" << endl;
		cout << "9 - Добавить раздел в этом же подуровне" << endl;
		cout << "10 - Удаление строки на том же уровне" << endl;
		cout << "11 - Удаление раздела на том же уровне" << endl;
		cout << "12 - Прочитать текст из файла" << endl;
		cout << "13 - Вывод (сохранение) текста в файл" << endl;
		cout << "14 - Вывод текста на консоль" << endl;
		cout << "15 - Выход" << endl;
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
			cout << "Введи строку:" << endl;
			cin >> str;
			//getline(cin, str, ';');
			txt.SetLine(str);
			break;
		}
		case 6:
		{
			cout << "Введи строку:" << endl;
			cin >> str;
			//getline(cin, str, ';');
			txt.InsNextLine(str);
			break;
		}
		case 7:
		{
			cout << "Введи строку:" << endl;
			cin >> str;
			//getline(cin, str, ';');
			txt.InsDownLine(str);
			break;
		}
		case 8:
		{
			cout << "Введи строку:" << endl;
			cin >> str;
			//getline(cin, str, ';');
			txt.InsNextSection(str);
			break;
		}
		case 9:
		{
			cout << "Введи строку:" << endl;
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
			cout << "Выход" << endl;
			break;
		}
		}
	} while (key != 15);
	cout << "Печать свободных звеньев" << endl;
	setlocale(LC_ALL, "C");
	TTextLink::PrintFreeLink();
	TTextLink::MemCleaner(txt);
	setlocale(LC_ALL, "Russian");
	cout << "После сборки мусора" << endl;
	setlocale(LC_ALL, "C");
	TTextLink::PrintFreeLink();
	_getch();
}