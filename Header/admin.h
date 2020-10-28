#pragma once
void menu_admin(int choice, BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, int &size_users)
{
admin:
	system("cls");

	cout << " |1|: ������ ������� � ����\n";
	cout << " |2|: ������� ������� �� ����\n";
	cout << " |3|: �������� �������� MONTH\n";
	cout << " |4|: ������� ������������\n";

	cout << "\n-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
		goto add;
	else if (choice == 2)
		goto remove;
	else if (choice == 3)
	{
		int new_value;
		system("cls"); 
		cout << "  |�������� �������� MONTH| -> \n\n";
		cout << " ����� ��������: "; cin >> new_value; cin.get(); cout << "\n";
		change_month(new_value);
		goto admin;
	}
	else if (choice == 4)
	{
		system("cls");
		cout << "  |������� ������������| -> \n\n";
		remove_user(size_users);
		goto admin;
	}

	else if (choice == 0)
		goto exit;


	////////////////////////////////////////////// ���
add:
	system("cls");

	cout << "  |������ ������� � ����| -> \n\n";

	cout << " |1|: �����\n";
	cout << " |2|: ������\n";
	cout << " |3|: ������\n";
	cout << " |4|: ������������\n";
	cout << " |5|: �������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		add_book(Books_st, size_B);
		goto add;
	}
	else if (choice == 2)
	{
		add_magazine(Magazines_st, size_M);
		goto add;
	}
	else if (choice == 3)
	{
		add_newspaper(Newspapers_st, size_N);
		goto add;
	}
	else if (choice == 4)
	{
		add_encyc(Encycs_st, size_E);
		goto add;
	}
	else if (choice == 5)
	{
		add_dict(Dicts_st, size_D);
		goto add;
	}

	else if (choice == 9)
		goto admin;
	else if (choice == 0)
		goto exit;
	//////////////////////////////////////////////













	////////////////////////////////////////////// ���
remove:
	system("cls");

	cout << "  |������� ������� �� ����| -> \n\n";

	cout << " |1|: �����\n";
	cout << " |2|: ������\n";
	cout << " |3|: ������\n";
	cout << " |4|: ������������\n";
	cout << " |5|: �������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		remove_book(Books_st, size_B);
		goto remove;
	}
	else if (choice == 2)
	{
		remove_magazine(Magazines_st, size_M);
		goto remove;
	}
	else if (choice == 3)
	{
		remove_newspaper(Newspapers_st, size_N);
		goto remove;
	}
	else if (choice == 4)
	{
		remove_encyc(Encycs_st, size_E);
		goto remove;
	}
	else if (choice == 5)
	{
		remove_dict(Dicts_st, size_D);
		goto remove;
	}

	else if (choice == 9)
		goto admin;
	else if (choice == 0)
		goto exit;
	//////////////////////////////////////////////


exit:
	system("cls");
	cout << " - �� ����� �� �����-������\n";
}