#pragma once
void add_encyc(ENCYCS *st, int size);
void remove_encyc(ENCYCS *st, int size);

void output_Encycs_admin(ENCYCS *st, int size);


void add_encyc(ENCYCS *st, int size)
{
	FILE *file;
	size++; int ind = size - 1;

	ENCYCS *new_st = new ENCYCS[size];

	for (int i = 0; i < size - 1; i++)
	{
		new_st[i] = st[i];
	}


	system("cls");

	cout << "  |Внести издание в базу| -> |Энциклопедия| -> \n\n";

	cout << "===================================\n";
	cout << "НАЗВАНИЕ: "; cin.getline(new_st[ind].name, 80); cout << "\n";
	cout << "ТЕМАТИКА: "; cin.getline(new_st[ind].topic, 45); cout << "\n";
	cout << "ИЗДАТЕЛЬСТВО: "; cin.getline(new_st[ind].publisher, 70); cout << "\n";

	cout << "СТРАНИЦ: "; cin >> new_st[ind].pages; cout << "\n\n";

	cout << "ДАТА ЗАВОЗА: \n";
	cout << "-День: "; cin >> new_st[ind].Date_delivery.day;
	cout << "-Месяц: "; cin >> new_st[ind].Date_delivery.month;
	cout << "-Год: "; cin >> new_st[ind].Date_delivery.year;
	cout << "===================================\n\n";


	file = fopen("Encycs.dat", "wb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		fwrite(new_st, sizeof(ENCYCS), size, file);
		fclose(file);
	}

	cout << " - Новая энциклопедия успешно записана в базу - \n\n";
	cout << "-|9|: Назад\n\n -> ";
	cin.get(); cin.get();
}



void remove_encyc(ENCYCS *st, int size)
{
	output_Encycs_admin(st, size);

	FILE *file; int choice, index = 0;
	int	new_size = size - 1;

	ENCYCS *new_st = new ENCYCS[new_size];


	cout << " -Номер энциклопедии для удаления: "; cin >> choice; choice--; cout << "\n\n";

	for (int i = 0; i < size; i++)
	{
		if (i != choice)
		{
			new_st[index] = st[i];
			index++;
		}
	}



	file = fopen("Encycs.dat", "wb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		fwrite(new_st, sizeof(ENCYCS), new_size, file);
		fclose(file);
	}

	cout << " - Энциклопедия успешно удалена из базы - \n\n";
	cout << "-|9|: Назад\n\n -> ";
	cin.get(); cin.get();
}




void output_Encycs_admin(ENCYCS *st, int size)
{
	system("cls");

	cout << "  |Удалить издание из базы| -> |Энциклопедия| -> \n\n";

	int ind = 1; int choice;
	for (int i = 0; i < size; i++)
	{
		cout << " Энциклопедия " << ind << ":" << "\n • " << st[i].name << "\n\n";
		ind++;
	}
	cout << "\n";
}