#pragma once
/////////////GUEST_1/////////////////////
void find_Magazine_with_Name(MAGAZINES *st, int size, char Main_phrase[], char Phrase[]);
void find_Magazine_with_Topic(MAGAZINES *st, int size, char Main_phrase[], char Phrase[]);

void inform_about_magazine(MAGAZINES *st, int index);
void which_inform_output_cycle_magazine(MAGAZINES *st, int indexes[], int size, char Main_phrase[], char Phrase[]);
/////////////GUEST_1/////////////////////

/////////////GUEST_2/////////////////////
void find_Magazine_with_Day(MAGAZINES *st, int size, char Main_phrase[], char Phrase[], int month);
void find_Magazine_freshest(MAGAZINES *st, int size, char Main_phrase[], char Phrase[], int month);
void find_Magazine_all(MAGAZINES *st, int size_, char Main_phrase[], char Phrase[], int month);
void find_Magazine_all_S(MAGAZINES *st, int size, char Main_phrase[], char Phrase[], int month);
/////////////GUEST_2/////////////////////

/////////////SORTING/////////////////////
void Sort_Magazine_with_Name(MAGAZINES st[], int size, char Main_phrase[], char Phrase[]);
void Sort_Magazine_with_Pages(MAGAZINES B_st[], int size, char Main_phrase[], char Phrase[]);
/////////////SORTING/////////////////////

///////////////////////INFUNCS///////////////////////////////////
void which_inform_output_cycle_magazine(MAGAZINES *st, int indexes[], int size, char Main_phrase[], char Phrase[])
{
	size--; int c;

	cout << " - Информацию о каком журнале желаете посмотреть?\n\n";
	cout << "-|9|: Назад\n\n -> ";

	cin >> c; cin.get(); c--;

	while (c >= 0 && c <= size)
	{
		inform_about_magazine(st, indexes[c]);

		system("cls");
		SetColor(8, 0);
		cout << Main_phrase << endl;
		cout << Phrase << endl;
		SetColor(7, 0);

		cout << " - Информацию о каком журнале желаете посмотреть?\n\n";

		for (int i = 0; i <= size; i++)
			cout << " Журнал " << i + 1 << ":" << "\n • " << st[indexes[i]].name << "\n\n";

		cout << "-|9|: Назад\n\n -> ";
		cin >> c; cin.get(); c--;
	}
}
///////////////////////INFUNCS///////////////////////////////////
///////////////////////OUTPUT///////////////////////////////////
void inform_about_magazine(MAGAZINES *st, int index)
{
	system("cls");
	cout << "===================================\n";
	cout << "НАЗВАНИЕ: " << st[index].name << "\n\n";
	cout << "ТЕМАТИКА: " << st[index].topic << "\n\n";
	cout << "СТРАНИЦ: " << st[index].pages << "\n\n\n";

	cout << "ДАТА ЗАВОЗА: " << st[index].Date_delivery.day << "." << st[index].Date_delivery.month << "." << st[index].Date_delivery.year << "\n";
	cout << "===================================\n\n";

	cout << "-|9|: Назад\n\n -> ";
	cin.get();
}
///////////////////////OUTPUT///////////////////////////////////
/////////////GUEST_1/////////////////////
void find_Magazine_with_Name(MAGAZINES *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	char name[75]; int index = 100; int c;
	cout << " Название журнала: "; cin.getline(name, 75); cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (stricmp(st[i].name, name) == 0)
		{
			cout << " Журнал:" << "\n • " << st[i].name << "\n\n";
			index = i;
		}
	}

	if (index == 100)
	{
		cout << " Журнал не был найдена\n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
	{
		cout << " - Желаете посмотреть информацию о журнале?\n";
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> c; cin.get();

		if (c == 1)
			inform_about_magazine(st, index);
	}
}

void find_Magazine_with_Topic(MAGAZINES *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c;	int num = 1;
	int *indexes = new int[25]; int ind = 0;

	cout << " |1|: ЗДОРОВЬЕ\n";
	cout << " |2|: ИСТОРИЯ\n";
	cout << " |3|: ПРИРОДА\n";
	cout << " |4|: ТЕХНОЛОГИИ\n";
	cout << " |5|: НАУКА\n\n";

	cout << "-|9|: Назад\n\n -> ";

	cin >> c; cin.get();

	if (c >= 1 && c <= 5)
	{
		system("cls");
		SetColor(8, 0);
		cout << Main_phrase << endl;
		cout << Phrase << endl;
		SetColor(7, 0);

		if (c == 1)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].topic, "Здоровье") == 0)
				{
					cout << " Энциклопедия " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_magazine(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 2)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].topic, "История") == 0)
				{
					cout << " Энциклопедия " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_magazine(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 3)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].topic, "Природа") == 0)
				{
					cout << " Энциклопедия " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_magazine(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 4)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].topic, "Технологии") == 0)
				{
					cout << " Энциклопедия " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_magazine(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 5)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].topic, "Наука") == 0)
				{
					cout << " Энциклопедия " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_magazine(st, indexes, ind, Main_phrase, Phrase);
		}
	}

	delete[] indexes;
}


void find_Magazine_with_Pages(MAGAZINES *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c;
	int *indexes = new int[25]; int ind = 0; int num = 1;
	int from, to;

	cout << " От: "; cin >> from; cin.get(); cout << '\n';
	cout << " До: "; cin >> to; cin.get(); cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (st[i].pages >= from && st[i].pages <= to)
		{
			cout << " Журнал " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
			indexes[ind] = i;
			ind++;
		}
	}

	if (ind == 0)
	{
		cout << " Журналов по данному промежутку не было найдено\n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
		which_inform_output_cycle_magazine(st, indexes, ind, Main_phrase,Phrase);

	delete[] indexes;
}
/////////////GUEST_1/////////////////////






/////////////GUEST_2/////////////////////
void find_Magazine_with_Day(MAGAZINES *st, int size, char Main_phrase[], char Phrase[], int month)
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c;
	int *indexes = new int[25]; int ind = 0; int num = 1;
	int day;

	cout << " День: "; cin >> day; cin.get(); cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (st[i].Date_delivery.day == day && st[i].Date_delivery.month == month)
		{
			cout << " Журнал " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
			indexes[ind] = i;
			ind++;
		}
	}

	if (day > 31)
	{
		cout << " - Ошибка...\n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else if (ind == 0)
	{
		cout << " В этот день месяца ничего не завозили\n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
		which_inform_output_cycle_magazine(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}


void find_Magazine_freshest(MAGAZINES *st, int size, char Main_phrase[], char Phrase[], int month)
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c; int maxindex = 0;
	int max = st[0].Date_delivery.day;

	if (size == 0)
	{
		cout << " За прошлый месяц журналов не было завезено\n\n" << endl;
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			if (max < st[i].Date_delivery.day)
			{
				max = st[i].Date_delivery.day;
				maxindex = i;
			}
		}

		cout << " Журнал:" << "\n • " << st[maxindex].name << ": |" << max << "." << month << "|" << "\n\n";


		cout << " - Желаете посмотреть информацию о журнале?\n";
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> c; cin.get();

		if (c == 1)
			inform_about_magazine(st, maxindex);
	}
}



void find_Magazine_all(MAGAZINES *st, int size_, char Main_phrase[], char Phrase[], int month)
{
	int size = 0;
	for (int i = 0; i < size_; i++)
	{
		if (st[i].Date_delivery.month == month)
			size++;
	}

	system("cls");
	cout << Main_phrase << endl;
	cout << Phrase << endl;

	int c;
	int *indexes = new int[25]; int ind = 0; int num = 1;

	for (int i = 0; i < size; i++)
	{
		cout << " Журнал " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
		indexes[ind] = i;
		ind++;
	}

	which_inform_output_cycle_magazine(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}




void find_Magazine_all_S(MAGAZINES *st, int size, char Main_phrase[], char Phrase[], int month)
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int ind = 0;

	for (int i = 0; i < size; i++)
	{
		cout << " Журнал " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
		ind++;
	}

	cout << "-|9|: Назад\n\n -> ";
	cin.get();
}
/////////////GUEST_2/////////////////////


















/////////////SORTING/////////////////////
void Sort_Magazine_with_Name(MAGAZINES st[], int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	char **arr = new char*[size]; int size_word;
	char *temp;

	for (int i = 0; i < size; i++)
	{
		size_word = strlen(st[i].name);
		arr[i] = new char[size_word];
		arr[i] = st[i].name;
	}

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (strcmp(arr[j + 1], arr[j]) < 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
		cout << " - " << arr[i] << "\n\n";


	cout << "\n-|9|: Назад\n\n -> ";
	cin.get();
}



void Sort_Magazine_with_Pages(MAGAZINES B_st[], int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	MAGAZINES *st = new MAGAZINES[size];
	for (int i = 0; i < size; i++)
		st[i] = B_st[i];


	int tmp;

	for (int i = 1; i < size; i++)
	{
		tmp = st[i].pages;
		while (st[i - 1].pages > tmp)
		{
			st[i].pages = st[i - 1].pages;
			i--;
		}
		st[i].pages = tmp;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (B_st[j].pages == st[i].pages)
			{
				cout << " - " << B_st[j].name << ": ";
				break;
			}
		}
		cout << st[i].pages << " страниц\n\n";
	}

	cout << "\n-|9|: Назад\n\n -> ";
	cin.get();
}
/////////////SORTING/////////////////////