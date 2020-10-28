#pragma once
void add_newspaper(NEWSPAPERS *st, int size);
void remove_newspaper(NEWSPAPERS *st, int size);

void output_Newspapers_admin(NEWSPAPERS *st, int size);


void add_newspaper(NEWSPAPERS *st, int size)
{
	FILE *file;
	size++; int ind = size - 1;

	NEWSPAPERS *new_st = new NEWSPAPERS[size];

	for (int i = 0; i < size - 1; i++)
	{
		new_st[i] = st[i];
	}


	system("cls");

	cout << "  |Внести издание в базу| -> |Газета| -> \n\n";

	cout << "===================================\n";
	cout << "НАЗВАНИЕ: "; cin.getline(new_st[ind].name, 80); cout << "\n";
	cout << "ТЕМАТИКА: "; cin.getline(new_st[ind].topic, 30); cout << "\n\n";

	cout << "ДАТА ЗАВОЗА: \n";
	cout << "-День: "; cin >> new_st[ind].Date_delivery.day;
	cout << "-Месяц: "; cin >> new_st[ind].Date_delivery.month;
	cout << "-Год: "; cin >> new_st[ind].Date_delivery.year;
	cout << "===================================\n\n";


	file = fopen("Newspapers.dat", "wb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		fwrite(new_st, sizeof(NEWSPAPERS), size, file);
		fclose(file);
	}

	cout << " - Новая газета успешно записана в базу - \n\n";
	cout << "-|9|: Назад\n\n -> ";
	cin.get(); cin.get();
}



void remove_newspaper(NEWSPAPERS *st, int size)
{
	output_Newspapers_admin(st, size);

	FILE *file; int choice, index = 0;
	int	new_size = size - 1;

	NEWSPAPERS *new_st = new NEWSPAPERS[new_size];


	cout << " -Номер газеты для удаления: "; cin >> choice; choice--; cout << "\n\n";

	for (int i = 0; i < size; i++)
	{
		if (i != choice)
		{
			new_st[index] = st[i];
			index++;
		}
	}



	file = fopen("Newspapers.dat", "wb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		fwrite(new_st, sizeof(NEWSPAPERS), new_size, file);
		fclose(file);
	}

	cout << " - Газета успешно удалена из базы - \n\n";
	cout << "-|9|: Назад\n\n -> ";
	cin.get(); cin.get();
}




void output_Newspapers_admin(NEWSPAPERS *st, int size)
{
	system("cls");

	cout << "  |Удалить издание из базы| -> |Газета| -> \n\n";

	int ind = 1; int choice;
	for (int i = 0; i < size; i++)
	{
		cout << " Газета " << ind << ":" << "\n • " << st[i].name << "\n\n";
		ind++;
	}
	cout << "\n";
}