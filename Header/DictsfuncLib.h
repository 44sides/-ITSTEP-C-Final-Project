#pragma once
/////////////GUEST_1//////////#2///////////
void find_Dict_with_Name(DICTS *st, int size, char Main_phrase[], char Phrase[]);
void find_Dict_with_Publisher(DICTS *st, int size, char Main_phrase[], char Phrase[]);

void inform_about_dict(DICTS *st, int index);
void which_inform_output_cycle_dict(DICTS *st, int indexes[], int size, char Main_phrase[], char Phrase[]);
/////////////GUEST_1//////////////////////

/////////////GUEST_2/////////////////////
void find_Dict_with_Day(DICTS *st, int size, char Main_phrase[], char Phrase[], int month);
void find_Dict_all(DICTS *st, int size_, char Main_phrase[], char Phrase[], int month);
void find_Dict_all_S(DICTS *st, int size, char Main_phrase[], char Phrase[], int month);
/////////////GUEST_2/////////////////////

/////////////SORTING/////////////////////
void Sort_Dict_with_Name(DICTS st[], int size, char Main_phrase[], char Phrase[]);
void Sort_Dict_with_Pages(DICTS B_st[], int size, char Main_phrase[], char Phrase[]);
/////////////SORTING/////////////////////

///////////////////////INFUNCS///////////////////////////////////
void which_inform_output_cycle_dict(DICTS *st, int indexes[], int size, char Main_phrase[], char Phrase[])
{
	size--; int c;

	cout << " - Информацию о каком словаре желаете посмотреть?\n\n";
	cout << "-|9|: Назад\n\n -> ";

	cin >> c; cin.get(); c--;

	while (c >= 0 && c <= size)
	{
		inform_about_dict(st, indexes[c]);

		system("cls");
		SetColor(8, 0);
		cout << Main_phrase << endl;
		cout << Phrase << endl;
		SetColor(7, 0);

		cout << " - Информацию о каком словаре желаете посмотреть?\n\n";

		for (int i = 0; i <= size; i++)
			cout << " Словарь " << i + 1 << ":" << "\n • " << st[indexes[i]].name << "\n\n";

		cout << "-|9|: Назад\n\n -> ";
		cin >> c; cin.get(); c--;
	}
}
///////////////////////INFUNCS///////////////////////////////////
///////////////////////OUTPUT///////////////////////////////////
void inform_about_dict(DICTS *st, int index)
{
	system("cls");
	cout << "===================================\n";
	cout << "НАЗВАНИЕ: " << st[index].name << "\n\n";
	cout << "ИЗДАТЕЛЬСТВО: " << st[index].publisher << "\n\n";
	cout << "СТРАНИЦ: " << st[index].pages << "\n\n\n";

	cout << "ДАТА ЗАВОЗА: " << st[index].Date_delivery.day << "." << st[index].Date_delivery.month << "." << st[index].Date_delivery.year << "\n";
	cout << "===================================\n\n";

	cout << "-|9|: Назад\n\n -> ";
	cin.get();
}
///////////////////////OUTPUT///////////////////////////////////
/////////////GUEST_1///////////////////////
void find_Dict_with_Name(DICTS *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);


	char name[75]; int index = 100; int c;
	cout << " Название словаря: "; cin.getline(name, 75); cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (stricmp(st[i].name, name) == 0)
		{
			cout << " Словарь:" << "\n • " << st[i].name << "\n\n";
			index = i;
		}
	}

	if (index == 100)
	{
		cout << " Словарь не был найден\n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
	{
		cout << " - Желаете посмотреть информацию о словаре?\n";
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> c; cin.get();

		if (c == 1)
			inform_about_dict(st, index);
	}
}



void find_Dict_with_Publisher(DICTS *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);


	char publisher[45]; int c;
	int *indexes = new int[25]; int ind = 0; int num = 1;


	cout << " Издательство: "; cin.getline(publisher, 45); cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (stricmp(st[i].publisher, publisher) == 0)
		{
			cout << " Словарь " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
			indexes[ind] = i;
			ind++;
		}
	}


	if (ind == 0)
	{
		cout << " Словарей с данным издательством не было найдено\n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
		which_inform_output_cycle_dict(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}
/////////////GUEST_1///////////////////////






/////////////GUEST_2/////////////////////
void find_Dict_with_Day(DICTS *st, int size, char Main_phrase[], char Phrase[], int month)
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
			cout << " Словарь " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
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
		which_inform_output_cycle_dict(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}


void find_Dict_all(DICTS *st, int size_, char Main_phrase[], char Phrase[], int month)
{
	int size = 0;

	for (int i = 0; i < size_; i++)
	{
		if (st[i].Date_delivery.month == month)
			size++;
	}

	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c;
	int *indexes = new int[25]; int ind = 0; int num = 1;

	for (int i = 0; i < size; i++)
	{
		cout << " Словарь " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
		indexes[ind] = i;
		ind++;
	}

	which_inform_output_cycle_dict(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}


void find_Dict_all_S(DICTS *st, int size, char Main_phrase[], char Phrase[], int month)
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int ind = 0;

	for (int i = 0; i < size; i++)
	{
		cout << " Словарь " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
		ind++;
	}

	cout << "-|9|: Назад\n\n -> ";
	cin.get();
}
/////////////GUEST_2/////////////////////




/////////////SORTING/////////////////////
void Sort_Dict_with_Name(DICTS st[], int size, char Main_phrase[], char Phrase[])
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



void Sort_Dict_with_Pages(DICTS B_st[], int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	DICTS *st = new DICTS[size];
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