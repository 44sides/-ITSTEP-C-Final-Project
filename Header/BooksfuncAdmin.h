#pragma once
void add_book(BOOKS *st, int size);
void remove_book(BOOKS *st, int size);

void output_Books_admin(BOOKS *st, int size);


void add_book(BOOKS *st, int size)
{
	FILE *file;
	size++; int ind = size - 1;

	BOOKS *new_st = new BOOKS[size];

	for (int i = 0; i < size - 1; i++)
	{
		new_st[i] = st[i];
	}


	system("cls");
	cout << "  |Внести издание в базу| -> |Книга| -> \n\n";

	cout << "===================================\n";
	cout << "НАЗВАНИЕ: "; cin.getline(new_st[ind].name, 80); cout << "\n";
	cout << "АВТОР: "; cin.getline(new_st[ind].author, 45); cout << "\n";
	cout << "ЖАНР: "; cin.getline(new_st[ind].genre, 30); cout << "\n";
	cout << "ЯЗЫК: "; cin.getline(new_st[ind].language, 40); cout << "\n";

	cout << "СТРАНИЦ: "; cin >> new_st[ind].pages; cout << "\n\n";
	cout << "ГОД ПУБЛИКАЦИИ: "; cin >> new_st[ind].year_publish; cout << "\n\n";

	cout << "ДАТА ЗАВОЗА: \n";
	cout << "-День: "; cin >> new_st[ind].Date_delivery.day;
	cout << "-Месяц: "; cin >> new_st[ind].Date_delivery.month;
	cout << "-Год: "; cin >> new_st[ind].Date_delivery.year;
	cout << "===================================\n\n";


	file = fopen("Books.dat", "wb");

	if (file == NULL) 
		perror("Ошибка открытия файла");
	else
	{
		fwrite(new_st, sizeof(BOOKS), size, file);
		fclose(file);
	}

	cout << " - Новая книга успешно записана в базу - \n\n";
	cout << "-|9|: Назад\n\n -> ";
	cin.get(); cin.get();
}



void remove_book(BOOKS *st, int size)
{
	output_Books_admin(st, size);

	FILE *file; int choice, index = 0;
	int	new_size = size - 1;

	BOOKS *new_st = new BOOKS[new_size];


	cout << " -Номер книги для удаления: "; cin >> choice; choice--; cout << "\n\n";

	for (int i = 0; i < size; i++)
	{
		if (i != choice)
		{
			new_st[index] = st[i];
			index++;
		}
	}



	file = fopen("Books.dat", "wb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		fwrite(new_st, sizeof(BOOKS), new_size, file);
		fclose(file);
	}

	cout << " - Книга успешно удалена из базы - \n\n";
	cout << "-|9|: Назад\n\n -> ";
	cin.get(); cin.get();
}




void output_Books_admin(BOOKS *st, int size)
{
	system("cls");

	cout << "  |Удалить издание из базы| -> |Книга| -> \n\n";

	int ind = 1; int choice;
	for (int i = 0; i < size; i++)
	{
		cout << " Книга " << ind << ":" << "\n • " << st[i].name << "\n\n";
		ind++;
	}
	cout << "\n";
}