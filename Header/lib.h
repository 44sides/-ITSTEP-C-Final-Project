#pragma once
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <stdarg.h>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <direct.h>
#include <windows.h>
using namespace std;

void SetColor(int text, int background)
{
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(StdOut, (WORD)((background << 4) | text));
}

struct FAV {
	char name[50];
	int mode; // 1 - book, 2 - magazine, 3 - newspaper, 4 - encyc, 5 - dict
};


struct USERS {
	char nick[50];
	char password[50];
};


struct DATA {
	int day;
	int month;
	int year;
};

struct DICTS {
	char name[85];
	char publisher[70];

	int pages;

	DATA Date_delivery;
};

struct ENCYCS {
	char name[75];
	char publisher[70];
	char topic[30];// Биология, Мифология, География, История, Животные, Религия, Позновательное

	int pages;

	DATA Date_delivery;
};

struct NEWSPAPERS {
	char name[75];
	char topic[30];// Реклама, Спорт, Новости, Агропромышленность

	DATA Date_delivery;
};

struct MAGAZINES {
	char name[75];
	char topic[30];// Здоровье, История, Природа, Технологии, Наука

	int pages;

	DATA Date_delivery;
};

struct BOOKS {
	char name[80];
	char author[45];// Джон Толкин, Филип Пулман, Михаил Булгаков, Иван Тургенев, Николай Гоголь
	//Федор Достоевский, Лев Толстой, Джоан Роулинг, Льюис Кэрролл, Леся Украинка, Иван Багряный, Иван Котляревский, Всеволод Нестайко

	char genre[30]; // Фэнтези, Роман, Повесть, Сказка, Драма, Приключенческий, Поэма
	char language[40]; // украинский, русский, английски

	int pages;
	int year_publish;

	DATA Date_delivery;
};

void menu_guest(int choice, BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, int mode, char user_name[], int month, char filename[]);
void menu_admin(int choice, BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, int &size_users);




