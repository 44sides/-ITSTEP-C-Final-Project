/////////////GUEST_1/////////////////////
void find_Book_with_Name(BOOKS *st, int size, char Main_phrase[], char Phrase[]);
void find_Book_with_Author(BOOKS *st, int size, char Main_phrase[], char Phrase[]);
void find_Book_with_Genre(BOOKS *st, int size, char Main_phrase[], char Phrase[]);
void find_Book_with_Language(BOOKS *st, int size, char Main_phrase[], char Phrase[]);
void find_Book_with_Pages(BOOKS *st, int size, char Main_phrase[], char Phrase[]);

void inform_about_book(BOOKS *st, int index);

void which_inform_output_cycle_book(BOOKS *st, int indexes[], int size, char Main_phrase[], char Phrase[]);
/////////////GUEST_1/////////////////////

/////////////GUEST_2/////////////////////
void find_Book_with_Day(BOOKS *st, int size, char Main_phrase[], char Phrase[], int month);
void find_Book_all(BOOKS *st, int size_, char Main_phrase[], char Phrase[], int month);
void find_Book_all_S(BOOKS *st, int size, char Main_phrase[], char Phrase[], int month);
/////////////GUEST_2/////////////////////

/////////////SORITNG/////////////////////
void Sort_Book_with_Name(BOOKS st[], int size, char Main_phrase[], char Phrase[]);
void Sort_Book_with_Pages(BOOKS B_st[], int size, char Main_phrase[], char Phrase[]);
/////////////SORTING/////////////////////


///////////////////////INFUNCS///////////////////////////////////
void which_inform_output_cycle_book(BOOKS *st, int indexes[], int size, char Main_phrase[], char Phrase[])
{
	size--; int c;

	cout << " - Информацию о какой книге желаете посмотреть?\n\n";
	cout << "-|9|: Назад\n\n -> ";

	cin >> c; cin.get(); c--;

	while (c >= 0 && c <= size)
	{
		inform_about_book(st, indexes[c]);

		system("cls");
		SetColor(8, 0);
		cout << Main_phrase << endl;
		cout << Phrase << endl;
		SetColor(7, 0);

		cout << " - Информацию о какой книге желаете посмотреть?\n\n";

		for (int i = 0; i <= size; i++)
			cout << " Книга " << i + 1 << ":" << "\n • " << st[indexes[i]].name << "\n\n";

		cout << "-|9|: Назад\n\n -> ";
		cin >> c; cin.get(); c--;
	}
}
///////////////////////INFUNCS///////////////////////////////////
///////////////////////OUTPUT///////////////////////////////////
void inform_about_book(BOOKS *st, int index)
{
	system("cls");
	cout << "===================================\n";
	cout << "НАЗВАНИЕ: " << st[index].name << "\n\n";
	cout << "АВТОР: " << st[index].author << "\n\n";
	cout << "ЖАНР: " << st[index].genre << "\n\n";
	cout << "ЯЗЫК: " << st[index].language << "\n\n";

	cout << "СТРАНИЦ: " << st[index].pages << "\n\n";
	cout << "ГОД ПУБЛИКАЦИИ: " << st[index].year_publish << "\n\n\n";

	cout << "ДАТА ЗАВОЗА: " << st[index].Date_delivery.day << "." << st[index].Date_delivery.month << "." << st[index].Date_delivery.year << "\n";
	cout << "===================================\n\n";

	cout << "-|9|: Назад\n\n -> ";
	cin.get();
}
///////////////////////OUTPUT///////////////////////////////////
/////////////GUEST_1/////////////////////
void find_Book_with_Name(BOOKS *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);
	

	char name[75]; int index = 100; int c;
	cout << " Название книги: "; cin.getline(name, 75); cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (stricmp(st[i].name, name) == 0)
		{
			cout << " Книга:" << "\n • " << st[i].name << "\n\n";
			index = i;
		}
	}

	if (index == 100)
	{
		cout << " Книга не была найдена\n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
	{
		cout << " - Желаете посмотреть информацию о книге?\n";
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> c; cin.get();

		if (c == 1)
			inform_about_book(st, index);
	}
}


void find_Book_with_Author(BOOKS *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	char author[45]; int c;
	int *indexes = new int[25]; int ind = 0;

	cout << " Автор: "; cin.getline(author, 75); cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (stricmp(st[i].author, author) == 0)
		{
			cout << " Книга " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
			indexes[ind] = i;
			ind++;
		}
	}


	if (ind == 0)
	{
		cout << " Книг данного автора не было найдено\n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
		which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}


void find_Book_with_Genre(BOOKS *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c;	int num = 1;
	int *indexes = new int[25]; int ind = 0;

	cout << " |1|: ФЭНТЕЗИ\n";
	cout << " |2|: РОМАН\n";
	cout << " |3|: ПОВЕСТЬ\n";
	cout << " |4|: СКАЗКА\n";
	cout << " |5|: ДРАМА\n";
	cout << " |6|: ПРИКЛЮЧЕНЧЕСКИЙ\n";
	cout << " |7|: ПОЭМА\n\n";

	cout << "-|9|: Назад\n\n -> ";

	cin >> c; cin.get();

	if (c >= 1 && c <= 7)
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
				if (stricmp(st[i].genre, "Фэнтези") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 2)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].genre, "Роман") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 3)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].genre, "Повесть") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 4)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].genre, "Сказка") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 5)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].genre, "Драма") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 6)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].genre, "Приключенческий") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 7)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].genre, "Поэма") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
	}

	delete[] indexes;
}

void find_Book_with_Language(BOOKS *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c;
	int *indexes = new int[25]; int ind = 0; int num = 1;

	cout << " |1|: РУССКИЙ\n";
	cout << " |2|: УКРАИНСКИЙ\n";
	cout << " |3|: АНГЛИЙСКИЙ\n\n";

	cout << "-|9|: Назад\n\n -> ";

	cin >> c; cin.get();

	if (c >= 1 && c <= 3)
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
				if (stricmp(st[i].language, "Русский") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n";
					indexes[ind] = i;
					ind++;
					num++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 2)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].language, "Украинский") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n";
					indexes[ind] = i;
					ind++;
					num++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 3)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].language, "Английский") == 0)
				{
					cout << " Книга " << num << ":" << "\n • " << st[i].name << "\n\n";
					indexes[ind] = i;
					ind++;
					num++;
				}
			}
			which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);
		}
	}

	delete[] indexes;
}

void find_Book_with_Pages(BOOKS *st, int size, char Main_phrase[], char Phrase[])
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
			cout << " Книга " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
			indexes[ind] = i;
			ind++;
		}
	}

	if (ind == 0)
	{
		cout << " Книг по данному промежутку не было найдено\n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
		which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}
/////////////GUEST_1/////////////////////




/////////////GUEST_2/////////////////////
void find_Book_with_Day(BOOKS *st, int size, char Main_phrase[], char Phrase[], int month)
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
			cout << " Книга " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
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
		which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}


void find_Book_all(BOOKS *st, int size_, char Main_phrase[], char Phrase[], int month)
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
			cout << " Книга " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
			indexes[ind] = i;
			ind++;
	}

		which_inform_output_cycle_book(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}


void find_Book_all_S(BOOKS *st, int size, char Main_phrase[], char Phrase[], int month)
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int ind = 0;

	for (int i = 0; i < size; i++)
	{
		cout << " Книга " << ind + 1 << ":" << "\n • " << st[i].name << "\n\n";
		ind++;
	}

	cout << "-|9|: Назад\n\n -> ";
	cin.get();
}
/////////////GUEST_2/////////////////////










/////////////SORTING/////////////////////
void Sort_Book_with_Name(BOOKS st[], int size, char Main_phrase[], char Phrase[])
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



void Sort_Book_with_Pages(BOOKS B_st[], int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	BOOKS *st = new BOOKS[size];
	for (int i = 0; i < size; i++)
		st[i] = B_st[i];


	int tmp; int pos;

	for (int i = 0; i < size; ++i) // выбором
	{
		pos = i;
		tmp = st[i].pages;
		for (int j = i + 1; j < size; ++j)
		{
			if (st[j].pages < tmp)
			{
				pos = j;
				tmp = st[j].pages;
			}
		}
		st[pos].pages = st[i].pages;
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