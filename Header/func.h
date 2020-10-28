#pragma once
void change_month(int const value);
void remove_user(int &size_users);

bool user_not(USERS *st, int size_st, char nick[], char password[]);
USERS *for_new_user(USERS *st, int size_st);

int count_size_Books_st();
int count_size_Magazines_st();
int count_size_Newspapers_st();
int count_size_Encycs_st();
int count_size_Dicts_st();
int count_size_Users_st(int mode);

BOOKS *fill_Books_st(int const size, int month);
MAGAZINES *fill_Magazines_st(int const size, int month);
NEWSPAPERS *fill_Newspapers_st(int const size, int month);
ENCYCS *fill_Encycs_st(int const size, int month);
DICTS *fill_Dicts_st(int const size, int month);
USERS *fill_Users_st(int const size, int mode);

char *set_month(int const month);
char *main_phrase(char user_name[50], int const mode);

void inform_randomly(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D);

///////////////////////////////FILLING///////////////////////////////////////////
int count_size_Books_st()
{
	BOOKS *st = new BOOKS[100];
	int size = 0;

	FILE *file = fopen("Books.dat", "rb");
	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		while (fread(&st[size], sizeof(BOOKS), 1, file))
			size++;
	}
	fclose(file);

	delete[] st;
	return size;
}

int count_size_Magazines_st()
{
	MAGAZINES *st = new MAGAZINES[100];
	int size = 0;

	FILE *file = fopen("Magazines.dat", "rb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		while (fread(&st[size], sizeof(MAGAZINES), 1, file))
			size++;
	}
	fclose(file);

	delete[] st;
	return size;
}

int count_size_Newspapers_st()
{
	NEWSPAPERS *st = new NEWSPAPERS[100];
	int size = 0;

	FILE *file = fopen("Newspapers.dat", "rb");
	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		while (fread(&st[size], sizeof(NEWSPAPERS), 1, file))
			size++;
	}
	fclose(file);

	delete[] st;
	return size;
}

int count_size_Encycs_st()
{
	ENCYCS *st = new ENCYCS[100];
	int size = 0;

	FILE *file = fopen("Encycs.dat", "rb");
	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		while (fread(&st[size], sizeof(ENCYCS), 1, file))
			size++;
	}
	fclose(file);

	delete[] st;
	return size;
}

int count_size_Dicts_st()
{
	DICTS *st = new DICTS[100];
	int size = 0;

	FILE *file = fopen("Dicts.dat", "rb");
	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		while (fread(&st[size], sizeof(DICTS), 1, file))
			size++;
	}
	fclose(file);

	delete[] st;
	return size;
}


int count_size_Users_st(int mode)
{
	USERS *st = new USERS[100];
	int size = 0;

	FILE *file;

	if (mode == 1)
		file = fopen("Users.dat", "rb");
	else if (mode == 2)
		file = fopen("Admins.dat", "rb");


	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		while (fread(&st[size], sizeof(USERS), 1, file))
			size++;
	}
	fclose(file);

	delete[] st;
	return size;
}





BOOKS *fill_Books_st(int const size, int month)
{
	BOOKS *st = new BOOKS[size];

	FILE *file = fopen("Books.dat", "rb");
	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		int i = 0;
		while (fread(&st[i], sizeof(BOOKS), 1, file))
			i++;
	}
	fclose(file);

	////
	if (month != 0)
	{
		int size_month = 0; int index = 0;

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
				size_month++;
		}

		BOOKS *st_month = new BOOKS[size_month];

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
			{
				st_month[index] = st[i];
				index++;
			}
		}

		return st_month;
	}

	return st;
}

MAGAZINES *fill_Magazines_st(int const size, int month)
{
	MAGAZINES *st = new MAGAZINES[size];

	FILE *file = fopen("Magazines.dat", "rb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		int i = 0;
		while (fread(&st[i], sizeof(MAGAZINES), 1, file))
			i++;
	}
	fclose(file);


	////
	if (month != 0)
	{
		int size_month = 0; int index = 0;

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
				size_month++;
		}

		MAGAZINES *st_month = new MAGAZINES[size_month];

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
			{
				st_month[index] = st[i];
				index++;
			}
		}

		return st_month;
	}

	return st;
}

NEWSPAPERS *fill_Newspapers_st(int const size, int month)
{
	NEWSPAPERS *st = new NEWSPAPERS[size];

	FILE *file = fopen("Newspapers.dat", "rb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		int i = 0;
		while (fread(&st[i], sizeof(NEWSPAPERS), 1, file))
			i++;
	}
	fclose(file);


	////
	if (month != 0)
	{
		int size_month = 0; int index = 0;

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
				size_month++;
		}

		NEWSPAPERS *st_month = new NEWSPAPERS[size_month];

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
			{
				st_month[index] = st[i];
				index++;
			}
		}

		return st_month;
	}

	return st;
}

ENCYCS *fill_Encycs_st(int const size, int month)
{
	ENCYCS *st = new ENCYCS[size];

	FILE *file = fopen("Encycs.dat", "rb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		int i = 0;
		while (fread(&st[i], sizeof(ENCYCS), 1, file))
			i++;
	}
	fclose(file);



	////
	if (month != 0)
	{
		int size_month = 0; int index = 0;

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
				size_month++;
		}

		ENCYCS *st_month = new ENCYCS[size_month];

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
			{
				st_month[index] = st[i];
				index++;
			}
		}

		return st_month;
	}

	return st;
}

DICTS *fill_Dicts_st(int const size, int month)
{
	DICTS *st = new DICTS[size];

	FILE *file = fopen("Dicts.dat", "rb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		int i = 0;
		while (fread(&st[i], sizeof(DICTS), 1, file))
			i++;
	}
	fclose(file);


	////
	if (month != 0)
	{
		int size_month = 0; int index = 0;

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
				size_month++;
		}

		DICTS *st_month = new DICTS[size_month];

		for (int i = 0; i < size; i++)
		{
			if (st[i].Date_delivery.month == month)
			{
				st_month[index] = st[i];
				index++;
			}
		}

		return st_month;
	}

	return st;
}


USERS *fill_Users_st(int const size, int mode)
{
	USERS *st = new USERS[size];

	FILE *file;

	if (mode == 1)
		file = fopen("Users.dat", "rb");
	else if (mode == 2)
		file = fopen("Admins.dat", "rb");


	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		int i = 0;
		while (fread(&st[i], sizeof(USERS), 1, file))
			i++;
	}

	fclose(file);
	return st;
}
///////////////////////////////FILLING///////////////////////////////////////////

bool user_not(USERS *st, int size_st, char nick[], char password[])
{
	for (int i = 0; i < size_st; i++)
	{
		if ((strcmp(nick, st[i].nick) == 0) && (strcmp(password, st[i].password) == 0))
			return true;
	}
	return false;
}




USERS *for_new_user(USERS *st, int size_st)
{
	size_st++;
	USERS *new_st = new USERS[size_st];

	for (int i = 0; i < size_st - 1; i++)
	{
		new_st[i] = st[i];
	}

	return new_st;
}















char *set_month(int const month)
{
	char *phrase = new char[20];

	if (month == 1)
		phrase = "      o| ЯНВАРЬ |o \n\n";
	if (month == 2)
		phrase = "      o| ФЕВРАЛЬ |o \n\n";
	if (month == 3)
		phrase = "      o| МАРТ |o \n\n";
	if (month == 4)
		phrase = "      o| АПРЕЛЬ |o \n\n";
	if (month == 5)
		phrase = "      o| МАЙ |o \n\n";
	if (month == 6)
		phrase = "      o| ИЮНЬ |o \n\n";
	if (month == 7)
		phrase = "      o| ИЮЛЬ |o \n\n";
	if (month == 8)
		phrase = "      o| АВГУСТ |o \n\n";
	if (month == 9)
		phrase = "      o| СЕНТЯБРЬ |o \n\n";
	if (month == 10)
		phrase = "      o| ОКТЯБРЬ |o \n\n";
	if (month == 11)
		phrase = "      o| НОЯБРЬ |o \n\n";
	if (month == 12)
		phrase = "      o| ДЕКАБРЬ |o \n\n";

	return phrase;
}

char *main_phrase(char user_name[50], int const mode)
{
	char *Main_phrase = new char[100];

	if (mode == 1)
		Main_phrase = "    |•| ПРОФИЛЬ 'ГОСТЬ' |•| \n";
	else
	{
		strcpy(Main_phrase, "    |•| ПРОФИЛЬ '");

		strcat(Main_phrase, user_name);

		strcat(Main_phrase, "' |•| \n");
	}

	return Main_phrase;
}


void inform_randomly(BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D)
{
	int num = 0;
	int randnum;

	num = rand() % 5;

	if (num == 0 && size_B > 0)
	{
		randnum = rand() % size_B;
		cout << "\n\n Книга: " << Books_st[randnum].name << "\n";

		cout << " - Желаете посмотреть информацию о книге?\n";
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> num; cin.get();

		if (num == 1)
			inform_about_book(Books_st, randnum);
	}
	else if (num == 1 && size_M > 0)
	{
		randnum = rand() % size_M;
		cout << "\n\n Журнал: " << Magazines_st[randnum].name << "\n";

		cout << " - Желаете посмотреть информацию о журнале?\n";
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> num; cin.get();

		if (num == 1)
			inform_about_magazine(Magazines_st, randnum);
	}
	else if (num == 2 && size_N > 0)
	{
		randnum = rand() % size_N;
		cout << "\n\n Газета: " << Newspapers_st[randnum].name << "\n";

		cout << " - Желаете посмотреть информацию о газете?\n";
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> num; cin.get();

		if (num == 1)
			inform_about_newspaper(Newspapers_st, randnum);
	}
	else if (num == 3 && size_E > 0)
	{
		randnum = rand() % size_E;
		cout << "\n\n Энциклопедия: " << Encycs_st[randnum].name << "\n";

		cout << " - Желаете посмотреть информацию о энциклопедии?\n";
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> num; cin.get();

		if (num == 1)
			inform_about_encyc(Encycs_st, randnum);
	}
	else if (num == 4 && size_D > 0)
	{
		randnum = rand() % size_D;
		cout << "\n\n Словарь: " << Dicts_st[randnum].name << "\n";

		cout << " - Желаете посмотреть информацию о словаре?\n";
		cout << " |1|: Да\n";
		cout << " |2|: Нет\n\n -> ";
		cin >> num; cin.get();

		if (num == 1)
			inform_about_dict(Dicts_st, randnum);
	}
}






/////////////////////ADMIN/////////////////////////
void change_month(int const value)
{
	FILE *file = fopen("month.txt", "w");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
		fprintf(file, "%d", value);
	fclose(file);

	cout << " - Значение успешно изменено -\n\n";
	cout << "-|9|: Назад\n\n -> ";

	cin.get();
}


void remove_user(int &size_users)
{
	USERS *st = new USERS[size_users];

	int new_size, ind_rem, index = 0, counter = 1;
	char remove_name[70];

	FILE *file = fopen("Users.dat", "rb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
	{
		for (int i = 0; i < size_users; i++)
		{
			fread(&st[i], sizeof(USERS), 1, file);
			cout << "====================Пользователь №" << counter << endl;
			cout << "NAME: " << st[i].nick << endl;
			cout << endl;
			counter++;
		}
	}

	fclose(file);


	cout << "\n Логин пользователя: "; cin.getline(remove_name, 50); cout << "\n";


		for (int i = 0; i < size_users; i++)
		{
			if (strcmp(st[i].nick, remove_name) == 0)
				ind_rem = i;
		}



	new_size = size_users - 1;
	USERS *new_st = new USERS[new_size];

	for (int i = 0; i < size_users; i++)
	{
		if (i != ind_rem)
		{
			new_st[index] = st[i];
			index++;
		}
	}

	file = fopen("Users.dat", "wb");

	if (file == NULL)
		perror("Ошибка открытия файла");
	else
		fwrite(new_st, sizeof(USERS), new_size, file);
	fclose(file);

	size_users--;


	strcat(remove_name, ".dat");
	remove(remove_name);

	cout << " - Пользователь успешно удален -\n\n";
	cout << "-|9|: Назад\n\n -> ";

	cin.get();
}
/////////////////////ADMIN/////////////////////////
