#include "lib.h"

#include "BooksfuncLib.h"
#include "MagazinesfuncLib.h"
#include "NewspapersfuncLib.h"
#include "EncycsfuncLib.h"
#include "DictsfuncLib.h"

#include "BooksfuncAdmin.h"
#include "MagazinesfuncAdmin.h"
#include "NewspapersfuncAdmin.h"
#include "EncycsfuncAdmin.h"
#include "DictsfuncAdmin.h"

#include "Favourites.h"

#include "func.h"

#include "guest.h"
#include "admin.h"


void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned rand_value = 11;
	srand(time(0));

	FILE *file; int month = 0; char name_reg[90];
	char user_name[50], user_password[50], admin_name[50], admin_password[50]; int admin_logIn_counter = 0; int mesyac; char filename[90];

	int size_Books_st = count_size_Books_st(), size_Magazines_st = count_size_Magazines_st(), size_Newspapers_st = count_size_Newspapers_st(),
		size_Encycs_st = count_size_Encycs_st(), size_Dicts_st = count_size_Dicts_st(), size_Users_st = count_size_Users_st(1), size_Admins_st = count_size_Users_st(2);

	BOOKS *Books_st = fill_Books_st(size_Books_st, 0);
	MAGAZINES *Magazines_st = fill_Magazines_st(size_Magazines_st, 0);
	NEWSPAPERS *Newspapers_st = fill_Newspapers_st(size_Newspapers_st, 0);
	ENCYCS *Encycs_st = fill_Encycs_st(size_Encycs_st, 0);
	DICTS *Dicts_st = fill_Dicts_st(size_Dicts_st, 0);
	USERS *Users_st = fill_Users_st(size_Users_st, 1);
	USERS *Admins_st = fill_Users_st(size_Admins_st, 2);


	int choice;
start:
	cout << " - Здравствуйте, Вас приветствует помощник библиотекаря, чего желаете?: \n\n";
	cout << " |1|: Войти как гость\n\n";
	cout << " |2|: Войти как зарегистрированный\n";
	cout << " |3|: Зарегистрироваться\n\n";
	cout << " |4|: Войти как администратор\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		file = fopen("month.txt", "r");

		if (file == NULL)
			perror("Ошибка открытия файла");
		else
			fscanf(file, "%d", &mesyac);
		fclose(file);

		menu_guest(choice, Books_st, Magazines_st, Newspapers_st, Encycs_st, Dicts_st, size_Books_st, size_Magazines_st, size_Newspapers_st, size_Encycs_st, size_Dicts_st, choice, user_name, mesyac, filename);
	}
	if (choice == 2)
	{
		cout << "\n • Логин: "; cin.getline(user_name, 50); cout << "\n";
		cout << " • Пароль: "; cin.getline(user_password, 50); cout << "\n";

		cout << ". ";
		Sleep(600);
		cout << ".. ";
		Sleep(600);
		cout << "... ";
		Sleep(600);
		cout << ".... ";
		Sleep(600);

		system("cls");
		if (user_not(Users_st, size_Users_st, user_name, user_password))
		{
			strcpy(filename, user_name); strcat(filename, ".dat");
			cout << " - Добро пожаловать! - \n\n";

			cout << ". ";
			Sleep(800);
			cout << ".. ";
			Sleep(800);
			cout << "... ";
			Sleep(880);
			cout << ".... ";
			Sleep(800);


			file = fopen("month.txt", "r");

			if (file == NULL)
				perror("Ошибка открытия файла");
			else
				fscanf(file, "%d", &mesyac);
			fclose(file);

			menu_guest(choice, Books_st, Magazines_st, Newspapers_st, Encycs_st, Dicts_st, size_Books_st, size_Magazines_st, size_Newspapers_st, size_Encycs_st, size_Dicts_st, choice, user_name, mesyac, filename);
		}
		else
		{
			cout << " - Неверный пароль или логин не существует! - \n";
			cout << ". ";
			Sleep(800);
			cout << ".. ";
			Sleep(800);
			cout << "... ";
			Sleep(880);
			cout << ".... ";
			Sleep(800);
			system("cls");
			goto start;
		}
	}
	if (choice == 3)
	{
		cout << "\n - Чтобы получить доступ к МЕНЮ СОРТИРОВКИ и ИЗБРАННОЕ, необходимо сначала зарегистрироваться.\n - Пожалуйста, укажите ваш логин и пароль в форме ниже: \n\n";

		Users_st = for_new_user(Users_st, size_Users_st);

		cout << " • Логин: "; cin.getline(name_reg, 50); cout << "\n";		strcpy(Users_st[size_Users_st].nick, name_reg);
		cout << " • Пароль: "; cin.getline(Users_st[size_Users_st].password, 50); cout << "\n";

		size_Users_st++;


		strcpy(filename, name_reg);
		strcat(filename, ".dat");

		file = fopen(filename, "wb");
		fclose(file);


		file = fopen("Users.dat", "wb");

		if (file == NULL)
			perror("Ошибка открытия файла");
		else
		{
			fwrite(Users_st, sizeof(USERS), size_Users_st, file);
			fclose(file);
		}
	}
	if (choice == 4 && admin_logIn_counter != 3)
	{
		cout << "\n Если после 3 попытки Вы не сможете войти, форма входа в админ-панель будет заблокирована!\n";
		cout << "\n • Login: "; cin.getline(admin_name, 50); cout << "\n";
		cout << " • Password: "; cin.getline(admin_password, 50); cout << "\n";

		cout << ". ";
		Sleep(600);
		cout << ".. ";
		Sleep(600);
		cout << "... ";
		Sleep(600);
		cout << ".... ";
		Sleep(600);
		system("cls");

		if (user_not(Admins_st, size_Admins_st, admin_name, admin_password) && admin_logIn_counter != 3)
		{
			cout << " - Добро пожаловать в админ-панель! - \n\n";

			cout << ". ";
			Sleep(800);
			cout << ".. ";
			Sleep(800);
			cout << "... ";
			Sleep(880);
			cout << ".... ";
			Sleep(800);
			
			menu_admin(choice, Books_st, Magazines_st, Newspapers_st, Encycs_st, Dicts_st, size_Books_st, size_Magazines_st, size_Newspapers_st, size_Encycs_st, size_Dicts_st, size_Users_st);
		}
		else
		{
			admin_logIn_counter++;
			cout << " - Ошибка! - \n У вас осталось " << 3 - admin_logIn_counter << " попытка(и)\n";
			cout << ". ";
			Sleep(870);
			cout << ".. ";
			Sleep(870);
			cout << "... ";
			Sleep(870);
			cout << ".... ";
			Sleep(870);
			system("cls");
			goto start;
		}
	}
	else if(admin_logIn_counter == 3)
	{
		cout << "\n - Вы ввели пароль неправильно 3 раза! Форма входа в админ-панель заблокирована! - \n";
		cout << ". ";
		Sleep(900);
		cout << ".. ";
		Sleep(900);
		cout << "... ";
		Sleep(900);
		cout << ".... ";
		Sleep(900);
		system("cls");
		goto start;
	}
	
}

