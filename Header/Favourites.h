#pragma once
////////////////ADD_FAV//////////////////////////////////////////////////////////
void add_fav(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, char filename[], char Main_phrase[]);
void find_name(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, char name[], int &mode, int &index, int &report);
void add_edition(FAV *st, BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int mode, int index, int new_size, char filename[]);
////////////////ADD_FAV//////////////////////////////////////////////////////////

////////////////LOOK_FAV//////////////////////////////////////////////////////////
void look_fav(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, char filename[], char Main_phrase[]);
void cout_mod(int const mode);
int find_which_index(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, char name_f[], int mode);
////////////////LOOK_FAV//////////////////////////////////////////////////////////

////////////////REMOVE_FAV//////////////////////////////////////////////////////////
void remove_fav(char filename[], char Main_phrase[]);
////////////////REMOVE_FAV//////////////////////////////////////////////////////////


////////////////ADD_FAV//////////////////////////////////////////////////////////
void add_edition(FAV *st, BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int mode, int index, int new_size, char filename[])
{
	FAV *st_new = new FAV[new_size]; int index_new = new_size - 1;
	FILE *file;
	for (int i = 0; i < new_size - 1; i++)
		st_new[i] = st[i];

	st_new[index_new].mode = mode;


	if (mode == 1)
		strcpy(st_new[index_new].name, Books_st[index].name);

	if (mode == 2)
		strcpy(st_new[index_new].name, Magazines_st[index].name);

	if (mode == 3)
		strcpy(st_new[index_new].name, Newspapers_st[index].name);

	if (mode == 4)
		strcpy(st_new[index_new].name, Encycs_st[index].name);

	if (mode == 5)
		strcpy(st_new[index_new].name, Dicts_st[index].name);



	file = fopen(filename, "wb");
	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		fwrite(st_new, sizeof(FAV), new_size, file);
		fclose(file);
	}

	delete[] st_new;
}


void find_name(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, char name[], int &mode, int &index, int &report)
{
	for (int i = 0; i < size_B; i++)
	{
		if (stricmp(name, Books_st[i].name) == 0)
		{
			mode = 1;
			index = i;
			report = 1;

			cout << " - Книга: " << Books_st[i].name << endl;
			cout << " Добавить в избранное?" << endl << endl;
			break;
		}
	}


	for (int i = 0; i < size_M; i++)
	{
		if (stricmp(name, Magazines_st[i].name) == 0)
		{
			mode = 2;
			index = i;
			report = 1;

			cout << " - Журнал: " << Magazines_st[i].name << endl;
			cout << " Добавить в избранное?" << endl << endl;
			break;
		}
	}

	for (int i = 0; i < size_N; i++)
	{
		if (stricmp(name, Newspapers_st[i].name) == 0)
		{
			mode = 3;
			index = i;
			report = 1;

			cout << " - Газета: " << Newspapers_st[i].name << endl;
			cout << " Добавить в избранное?" << endl << endl;
			break;
		}
	}

	for (int i = 0; i < size_E; i++)
	{
		if (stricmp(name, Encycs_st[i].name) == 0)
		{
			mode = 4;
			index = i;
			report = 1;

			cout << " - Энциклопедия: " << Encycs_st[i].name << endl;
			cout << " Добавить в избранное?" << endl << endl;
			break;
		}
	}

	for (int i = 0; i < size_D; i++)
	{
		if (stricmp(name, Dicts_st[i].name) == 0)
		{
			mode = 5;
			index = i;
			report = 1;

			cout << " - Словарь: " << Dicts_st[i].name << endl;
			cout << " Добавить в избранное?" << endl << endl;
			break;
		}
	}


}



void add_fav(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, char filename[], char Main_phrase[])
{
	////////////////////COUNT SIZE/////////////////////////////
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << "  |Избранное| -> |Добавить издание| -> \n\n";
	SetColor(7, 0);

	FAV *st = new FAV[100];
	int size_st = 0;

	FILE *file = fopen(filename, "rb");
	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		while (fread(&st[size_st], sizeof(FAV), 1, file))
			size_st++;
	}
	fclose(file);
	////////////////////COUNT SIZE/////////////////////////////

	size_st++;

	int mode = 0, index = 0; int choice; int report = 0;
	char name[80];
	cout << " Название издания: "; cin.getline(name, 80); cout << "\n";

	find_name(Books_st, Magazines_st, Newspapers_st, Encycs_st, Dicts_st, size_B, size_M, size_N, size_E, size_D, name, mode, index, report);

	if (report == 0)
	{
		cout << " -Издание не было найдено\n\n";
		cout << "-|9|: Назад\n -> ";
		cin.get();
	}
	else
	{
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> choice; cin.get();

		if (choice == 1)
		{

			add_edition(st, Books_st, Magazines_st, Newspapers_st, Encycs_st, Dicts_st, mode, index, size_st, filename);

		}
		else
		{
			cout << "\n-|9|: Назад\n -> ";
			cin.get(); cin.get();
		}
	}



	delete[]st;
}
////////////////ADD_FAV//////////////////////////////////////////////////////////


////////////////LOOK_FAV//////////////////////////////////////////////////////////
void cout_mod(int const mode)
{
	if (mode == 1)
		cout << "Книга: ";
	if (mode == 2)
		cout << "Журнал: ";
	if (mode == 3)
		cout << "Газета: ";
	if (mode == 4)
		cout << "Энциклопедия: ";
	if (mode == 5)
		cout << "Словарь: ";
}



int find_which_index(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, char name_f[], int mode)
{
	int index;

	if (mode == 1)
	{
		for (int i = 0; i < size_B; i++)
		{
			if (strcmp(name_f, Books_st[i].name) == 0)
			{
				index = i;
				break;
			}
		}
	}
	if (mode == 2)
	{
		for (int i = 0; i < size_M; i++)
		{
			if (strcmp(name_f, Magazines_st[i].name) == 0)
			{
				index = i;
				break;
			}
		}
	}
	if (mode == 3)
	{
		for (int i = 0; i < size_N; i++)
		{
			if (strcmp(name_f, Newspapers_st[i].name) == 0)
			{
				index = i;
				break;
			}
		}
	}
	if (mode == 4)
	{
		for (int i = 0; i < size_E; i++)
		{
			if (strcmp(name_f, Encycs_st[i].name) == 0)
			{
				index = i;
				break;
			}
		}
	}
	if (mode == 5)
	{
		for (int i = 0; i < size_D; i++)
		{
			if (strcmp(name_f, Dicts_st[i].name) == 0)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}





void look_fav(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, char filename[], char Main_phrase[])
{
	int choice; int index; int counter = 1;

	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << "  |Избранное| -> |Посмотреть избранное| -> \n\n";
	SetColor(7, 0);

	FILE *file;
	FAV *st_fav = new FAV[100]; int size_st = 0;

	file = fopen(filename, "rb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		while (fread(&st_fav[size_st], sizeof(FAV), 1, file))
		{
			cout << "===================================  №" << counter << endl;
			cout << " - "; cout_mod(st_fav[size_st].mode); cout << st_fav[size_st].name << endl;
			cout << "===================================" << endl << endl;
			size_st++; counter++;
		}
		fclose(file);
	}

	cout << "\n Информацию о каком издании хотите посмотреть?\n\n";
	cout << "\n-|9|: Назад\n\n -> ";
	cin >> choice;
	
	if (choice == 0)
	{
		goto e;
	}
	else
	{
		cin.get();
 		choice--;
	}


	while (choice <= size_st - 1)
	{

		index = find_which_index(Books_st, Magazines_st, Newspapers_st, Encycs_st, Dicts_st, size_B, size_M, size_N, size_E, size_D, st_fav[choice].name, st_fav[choice].mode);

		if (st_fav[choice].mode == 1)
			inform_about_book(Books_st, index);
		if (st_fav[choice].mode == 2)
			inform_about_magazine(Magazines_st, index);
		if (st_fav[choice].mode == 3)
			inform_about_newspaper(Newspapers_st, index);
		if (st_fav[choice].mode == 4)
			inform_about_encyc(Encycs_st, index);
		if (st_fav[choice].mode == 5)
			inform_about_dict(Dicts_st, index);

		counter = 1;
		system("cls");
		SetColor(8, 0);
		cout << Main_phrase << endl;
		cout << "  |Избранное| -> |Посмотреть избранное| -> \n\n";
		SetColor(7, 0);
		for (int i = 0; i < size_st; i++)
		{
			cout << "===================================  №" << counter << endl;
			cout << " - "; cout_mod(st_fav[i].mode); cout << st_fav[i].name << endl;
			cout << "===================================" << endl << endl;
			counter++;
		}

		cout << "\n Информацию о каком издании хотите посмотреть?\n\n";
		cout << "\n-|9|: Назад\n\n -> ";
		cin >> choice; cin.get(); 		choice--;

	}


e:
	delete[] st_fav;
}
////////////////LOOK_FAV//////////////////////////////////////////////////////////



////////////////REMOVE_FAV//////////////////////////////////////////////////////////
void remove_fav(char filename[], char Main_phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << "  |Избранное| -> |Удалить издание| -> \n\n";
	SetColor(7, 0);

	int new_size;

	FAV *st = new FAV[100];
	int size_st = 0, counter = 1, choice, new_ind = 0;

	FILE *file = fopen(filename, "rb");
	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		while (fread(&st[size_st], sizeof(FAV), 1, file))
		{
			cout << "===================================  №" << counter << endl;
			cout << " - "; cout_mod(st[size_st].mode); cout << st[size_st].name << endl << endl;
			size_st++; counter++;
		}
	}
	fclose(file);

	if (size_st == 0)
	{
		cout << " - Вы еще ничего не добавляли в избранное \n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
	}
	else
	{
		new_size = size_st - 1;
		FAV *new_st = new FAV[new_size];

		cout << "\n Номер для удаления: "; cin >> choice; cin.get(); choice--; cout << "\n\n";

		for (int i = 0; i < size_st; i++)
		{
			if (i != choice)
			{
				new_st[new_ind] = st[i];
				new_ind++;
			}
		}



		file = fopen(filename, "wb");
		if (file == NULL)
			perror("Ошибка открытия файла");
		else
			fwrite(new_st, sizeof(FAV), new_size, file);
		fclose(file);


		cout << " - Издание успешно удалено из базы - \n\n";
		cout << "-|9|: Назад\n\n -> ";
		cin.get();
		delete[] new_st;
	}
	delete[] st;
}
////////////////REMOVE_FAV//////////////////////////////////////////////////////////