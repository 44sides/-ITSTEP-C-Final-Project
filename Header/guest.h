#pragma once
void menu_guest(int choice, BOOKS *Books_st, MAGAZINES *Magazines_st, NEWSPAPERS *Newspapers_st, ENCYCS *Encycs_st, DICTS *Dicts_st, int size_B, int size_M, int size_N, int size_E, int size_D, int mode, char user_name[], int month, char filename[])
{
	int size_B_month = 0, size_M_month = 0, size_N_month = 0, size_E_month = 0, size_D_month = 0;
	char *Phrase = new char[255]; char *Main_phrase = new char[100];
	char *phrase_month = new char[20];

	Main_phrase = main_phrase(user_name, mode);

guest:
	
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	SetColor(7, 0);

	cout << " |1|: ���������� � ���� ��������\n";
	cout << " |2|: ���������� � ������ �� ��������� �����\n";

	if (mode == 2)
	{
		cout << " |3|: ���� ����������\n";
		cout << " |4|: ���������\n";
	}

	cout << "\n-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
		goto guest_1;
	else if (choice == 2)
		goto guest_2;

	else if (choice == 0)
		goto exit;

	if (mode == 2)
	{
		if (choice == 3)
			goto sort;
		if (choice == 4)
			goto fav;
	}





	////////////////////////////////////////////// ���
guest_1:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ���� ��������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: �����\n";
	cout << " |2|: �������\n";
	cout << " |3|: ������\n";
	cout << " |4|: ������������\n";
	cout << " |5|: �������\n\n";

	cout << " |6|: ������� ���������� � ��������� �������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
		goto books;
	else if (choice == 2)
		goto magazines;
	else if (choice == 3)
		goto newspapers;
	else if (choice == 4)
		goto encycs;
	else if (choice == 5)
		goto dicts;

	else if (choice == 6)
	{
		inform_randomly(Books_st, Magazines_st, Newspapers_st, Encycs_st, Dicts_st, size_B, size_M, size_N, size_E, size_D);
		goto guest_1;
	}

	else if (choice == 9)
		goto guest;
	else if (choice == 0)
		goto exit;
	//////////////////////////////////////////////
	/////////////GUEST_1//////////#1/////////// ���
books:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ���� ��������| -> |�����| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ����� ����� �� ��������\n";
	cout << " |2|: ����� ����� �� ������\n";
	cout << " |3|: ����� ����� �� �����\n";
	cout << " |4|: ����� ����� �� ����� ���������\n";
	cout << " |5|: ����� ����� �� ��������� �������\n\n";

	cout << " |6|: ����� ��� �����\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���������� � ���� ��������| -> |�����| -> |����� ����� �� ��������| -> \n\n";
		find_Book_with_Name(Books_st, size_B, Main_phrase, Phrase);
		goto books;
	}
	else if (choice == 2)
	{
		Phrase = "  |���������� � ���� ��������| -> |�����| -> |����� ����� �� ������| -> \n\n";
		find_Book_with_Author(Books_st, size_B, Main_phrase, Phrase);
		goto books;
	}
	else if (choice == 3)
	{
		Phrase = "  |���������� � ���� ��������| -> |�����| -> |����� ����� �� �����| -> \n\n";
		find_Book_with_Genre(Books_st, size_B, Main_phrase, Phrase);
		goto books;
	}
	else if (choice == 4)
	{
		Phrase = "  |���������� � ���� ��������| -> |�����| -> |����� ����� �� ����� ���������| -> \n\n";
		find_Book_with_Language(Books_st, size_B, Main_phrase, Phrase);
		goto books;
	}
	else if (choice == 5)
	{
		Phrase = "  |���������� � ���� ��������| -> |�����| -> |����� ����� �� ��������� �������| -> \n\n";
		find_Book_with_Pages(Books_st, size_B, Main_phrase, Phrase);
		goto books;
	}
	else if (choice == 6)
	{
		Phrase = "  |���������� � ���� ��������| -> |�����| -> |����� ��� �����| -> \n\n";
		find_Book_all_S(Books_st, size_B, Main_phrase, Phrase, month);
		goto books;
	}

	else if (choice == 9)
		goto guest_1;
	else if (choice == 0)
		goto exit;
	/////////////GUEST_1///////////#1//////////
	/////////////GUEST_1///////////#2////////// ���
magazines:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ���� ��������| -> |�������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ����� ������ �� ��������\n";
	cout << " |2|: ����� ������� �� ��������\n";
	cout << " |3|: ����� ������� �� ��������� �������\n\n";

	cout << " |4|: ����� ��� �������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���������� � ���� ��������| -> |�������| -> |����� ������ �� ��������| -> \n\n";
		find_Magazine_with_Name(Magazines_st, size_M, Main_phrase, Phrase);
		goto magazines;
	}
	else if (choice == 2)
	{
		Phrase = "  |���������� � ���� ��������| -> |�������| -> |����� ������� �� ��������| -> \n\n";
		find_Magazine_with_Topic(Magazines_st, size_M, Main_phrase, Phrase);
		goto magazines;
	}
	else if (choice == 3)
	{
		Phrase = "  |���������� � ���� ��������| -> |�������| -> |����� ������� �� ��������� �������| -> \n\n";
		find_Magazine_with_Pages(Magazines_st, size_M, Main_phrase, Phrase);
		goto magazines;
	}
	else if (choice == 4)
	{
		Phrase = "  |���������� � ���� ��������| -> |�������| -> |����� ��� �������| -> \n\n";
		find_Magazine_all_S(Magazines_st, size_M, Main_phrase, Phrase, month);
		goto magazines;
	}

	else if (choice == 9)
		goto guest_1;
	else if (choice == 0)
		goto exit;
	/////////////GUEST_1////////////#2/////////
	/////////////GUEST_1///////////#3////////// ���
newspapers:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;


	cout << "  |���������� � ���� ��������| -> |������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ����� ������ �� ��������\n";
	cout << " |2|: ����� ������ �� ��������\n\n";

	cout << " |3|: ����� ��� ������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���������� � ���� ��������| -> |������| -> |����� ������ �� ��������| -> \n\n";
		find_Newspaper_with_Name(Newspapers_st, size_N, Main_phrase, Phrase);
		goto newspapers;
	}
	else if (choice == 2)
	{
		Phrase = "  |���������� � ���� ��������| -> |������| -> |����� ������ �� ��������| -> \n\n";
		find_Newspaper_with_Topic(Newspapers_st, size_N, Main_phrase, Phrase);
		goto newspapers;
	}
	else if (choice == 3)
	{
		Phrase = "  |���������� � ���� ��������| -> |������| -> |����� ��� ������| -> \n\n";
		find_Newspaper_all_S(Newspapers_st, size_N, Main_phrase, Phrase, month);
		goto newspapers;
	}

	else if (choice == 9)
		goto guest_1;
	else if (choice == 0)
		goto exit;
	/////////////GUEST_1////////////#3/////////
	/////////////GUEST_1///////////#4////////// ���
encycs:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ���� ��������| -> |������������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ����� ������������ �� ��������\n";
	cout << " |2|: ����� ������������ �� ��������\n";
	cout << " |3|: ����� ������������ �� ������������\n";
	cout << " |4|: ����� ������������ �� ��������� �������\n\n";

	cout << " |5|: ����� ��� ������������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���������� � ���� ��������| -> |������������| -> |����� ������������ �� ��������| -> \n\n";
		find_Encyc_with_Name(Encycs_st, size_E, Main_phrase, Phrase);
		goto encycs;
	}
	else if (choice == 2)
	{
		Phrase = "  |���������� � ���� ��������| -> |������������| -> |����� ������������ �� ��������| -> \n\n";
		find_Encyc_with_Topic(Encycs_st, size_E, Main_phrase, Phrase);
		goto encycs;
	}
	else if (choice == 3)
	{
		Phrase = "  |���������� � ���� ��������| -> |������������| -> |����� ������������ �� ������������| -> \n\n";
		find_Encyc_with_Publisher(Encycs_st, size_E, Main_phrase, Phrase);
		goto encycs;
	}
	else if (choice == 4)
	{
		Phrase = "  |���������� � ���� ��������| -> |������������| -> |����� ������������ �� ��������� �������| -> \n\n";
		find_Encyc_with_Pages(Encycs_st, size_E, Main_phrase, Phrase);
		goto encycs;
	}
	else if (choice == 5)
	{
		Phrase = "  |���������� � ���� ��������| -> |������������| -> |����� ��� ������������| -> \n\n";
		find_Encyc_all_S(Encycs_st, size_E, Main_phrase, Phrase, month);
		goto encycs;
	}

	else if (choice == 9)
		goto guest_1;
	else if (choice == 0)
		goto exit;
	/////////////GUEST_1////////////#4/////////
	/////////////GUEST_1///////////#5////////// ���
dicts:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ���� ��������| -> |�������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ����� ������� �� ��������\n";
	cout << " |2|: ����� ������� �� ������������\n\n";

	cout << " |3|: ����� ��� �������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���������� � ���� ��������| -> |�������| -> |����� ������� �� ��������| -> \n\n";
		find_Dict_with_Name(Dicts_st, size_D, Main_phrase, Phrase);
		goto dicts;
	}

	else if (choice == 2)
	{
		Phrase = "  |���������� � ���� ��������| -> |�������| -> |����� ������� �� ������������| -> \n\n";
		find_Dict_with_Publisher(Dicts_st, size_D, Main_phrase, Phrase);
		goto dicts;
	}
	else if (choice == 3)
	{
		Phrase = "  |���������� � ���� ��������| -> |�������| -> |����� ��� �������| -> \n\n";
		find_Dict_all_S(Dicts_st, size_D, Main_phrase, Phrase, month);
		goto dicts;
	}

	else if (choice == 9)
		goto guest_1;
	else if (choice == 0)
		goto exit;
	/////////////GUEST_1////////////#5/////////




















////////////////////////////////////////////// ���
guest_2:
	BOOKS *Books_month = fill_Books_st(size_B, month);
	MAGAZINES *Magazines_month = fill_Magazines_st(size_M, month);
	NEWSPAPERS *Newspapers_month = fill_Newspapers_st(size_N, month);
	ENCYCS *Encycs_month = fill_Encycs_st(size_E, month);
	DICTS *Dicts_month = fill_Dicts_st(size_D, month);

	for (int i = 0; i < size_B; i++)
	{
		if (Books_st[i].Date_delivery.month == month)
			size_B_month++;
	}

	for (int i = 0; i < size_M; i++)
	{
		if (Magazines_st[i].Date_delivery.month == month)
			size_M_month++;
	}

	for (int i = 0; i < size_N; i++)
	{
		if (Newspapers_st[i].Date_delivery.month == month)
			size_N_month++;
	}

	for (int i = 0; i < size_E; i++)
	{
		if (Encycs_st[i].Date_delivery.month == month)
			size_E_month++;
	}

	for (int i = 0; i < size_D; i++)
	{
		if (Dicts_st[i].Date_delivery.month == month)
			size_D_month++;
	}



	phrase_month = set_month(month);


guest_2_continue:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ������ �� ��������� �����| -> \n\n";
	SetColor(7, 0);
	
	cout << phrase_month;

	cout << " |1|: �����\n";
	cout << " |2|: �������\n";
	cout << " |3|: ������\n";
	cout << " |4|: ������������\n";
	cout << " |5|: �������\n\n";

	cout << " |6|: ������� ���������� � ��������� �������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
		goto books_delivery;
	else if (choice == 2)
		goto magazines_delivery;
	else if (choice == 3)
		goto newspapers_delivery;
	else if (choice == 4)
		goto encycs_delivery;
	else if (choice == 5)
		goto dicts_delivery;

	else if (choice == 6)
	{
		inform_randomly(Books_month, Magazines_month, Newspapers_month, Encycs_month, Dicts_month, size_B_month, size_M_month, size_N_month, size_E_month, size_D_month);
		goto guest_2_continue;
	}

	else if (choice == 9)
		goto guest;
	else if (choice == 0)
		goto exit;
//////////////////////////////////////////////
/////////////GUEST_2///////////#1////////// ���
books_delivery:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ������ �� ��������� �����| -> |�����| -> \n\n";
	SetColor(7, 0);
	cout << phrase_month;

	cout << " |1|: ����� ����� �� ��������\n";
	cout << " |2|: ����� ����� �� ������\n";
	cout << " |3|: ����� ����� �� �����\n";
	cout << " |4|: ����� ����� �� ����� ���������\n";
	cout << " |5|: ����� ����� �� ��������� �������\n\n";

	cout << " |6|: ����� �����, ���������� � ��������� ���� ������\n";
	cout << " |7|: ����� ��� �����\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";



	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�����| -> |����� ����� �� ��������| -> \n\n";
		find_Book_with_Name(Books_month, size_B_month, Main_phrase, Phrase);
		goto books_delivery;
	}
	if (choice == 2)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�����| -> |����� ����� �� ������| -> \n\n";
		find_Book_with_Author(Books_month, size_B_month, Main_phrase, Phrase);
		goto books_delivery;
	}
	else if (choice == 3)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�����| -> |����� ����� �� �����| -> \n\n";
		find_Book_with_Genre(Books_month, size_B_month, Main_phrase, Phrase);
		goto books_delivery;
	}
	else if (choice == 4) 
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�����| -> |����� ����� �� ����� ���������| -> \n\n";
		find_Book_with_Language(Books_month, size_B_month, Main_phrase, Phrase);
		goto books_delivery;
	}
	else if (choice == 5)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�����| -> |����� ����� �� ��������� �������| -> \n\n";
		find_Book_with_Pages(Books_month, size_B_month, Main_phrase, Phrase);
		goto books_delivery;
	}

	else if (choice == 6)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�����| -> |����� �����, ���������� � ��������� ���� ������| -> \n\n";
		find_Book_with_Day(Books_month, size_B_month, Main_phrase, Phrase, month);
		goto books_delivery;
	}
	else if (choice == 7)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�����| -> |����� ��� �����| -> \n\n";
		find_Book_all(Books_month, size_B, Main_phrase, Phrase, month);
		goto books_delivery;
	}

	else if (choice == 9)
		goto guest_2_continue;
	else if (choice == 0)
		goto exit;
/////////////GUEST_2///////////#1//////////
/////////////GUEST_2///////////#2////////// ���
magazines_delivery:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ������ �� ��������� �����| -> |�������| -> \n\n";
	SetColor(7, 0);
	cout << phrase_month;

	cout << " |1|: ����� ������ �� ��������\n";
	cout << " |2|: ����� ������� �� ��������\n";
	cout << " |3|: ����� ������� �� ��������� �������\n\n";

	cout << " |4|: ����� �������, ���������� � ��������� ���� ������\n";
	cout << " |5|: ����� ����� ������ ������\n";
	cout << " |6|: ����� ��� �������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� ������ �� ��������| -> \n\n";
		find_Magazine_with_Name(Magazines_month, size_M_month, Main_phrase, Phrase);
		goto magazines_delivery;
	}
	else if (choice == 2)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� ������� �� ��������| -> \n\n";
		find_Magazine_with_Topic(Magazines_month, size_M_month, Main_phrase, Phrase);
		goto magazines_delivery;
	}
	else if (choice == 3)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� ������� �� ��������� �������| -> \n\n";
		find_Magazine_with_Pages(Magazines_month, size_M_month, Main_phrase, Phrase);
		goto magazines_delivery;
	}

	else if (choice == 4)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� �������, ���������� � ��������� ���� ������| -> \n\n";
		find_Magazine_with_Day(Magazines_month, size_M_month, Main_phrase, Phrase, month);
		goto magazines_delivery;
	}
	else if (choice == 5)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� ����� ������ ������| -> \n\n";
		find_Magazine_freshest(Magazines_month, size_M_month, Main_phrase, Phrase, month);
		goto magazines_delivery;
	}
	else if (choice == 6)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� ��� �������| -> \n\n";
		find_Magazine_all(Magazines_month, size_M, Main_phrase, Phrase, month);
		goto magazines_delivery;
	}

	else if (choice == 9)
		goto guest_2_continue;
	else if (choice == 0)
		goto exit;
	/////////////GUEST_2////////////#2/////////
	/////////////GUEST_2///////////#3////////// ���
newspapers_delivery:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ������ �� ��������� �����| -> |������| -> \n\n";
	SetColor(7, 0);
	cout << phrase_month;

	cout << " |1|: ����� ������ �� ��������\n";
	cout << " |2|: ����� ������ �� ��������\n\n";

	cout << " |3|: ����� ������, ���������� � ��������� ���� ������\n";
	cout << " |4|: ����� ����� ������ ������\n";
	cout << " |5|: ����� ��� ������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();
	 
	if (choice == 1)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������| -> |����� ������ �� ��������| -> \n\n";
		find_Newspaper_with_Name(Newspapers_month, size_N_month, Main_phrase, Phrase);
		goto newspapers_delivery;
	}
	else if (choice == 2)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������| -> |����� ������ �� ��������| -> \n\n";
		find_Newspaper_with_Topic(Newspapers_month, size_N_month, Main_phrase, Phrase);
		goto newspapers_delivery;
	}

	else if (choice == 3)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������| -> |����� ������, ���������� � ��������� ���� ������| -> \n\n";
		find_Newspaper_with_Day(Newspapers_month, size_N_month, Main_phrase, Phrase, month);
		goto newspapers_delivery;
	}
	else if (choice == 4)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������| -> |����� ����� ������ ������| -> \n\n";
		find_Newspaper_freshest(Newspapers_month, size_N_month, Main_phrase, Phrase, month);
		goto newspapers_delivery;
	}
	else if (choice == 5)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������| -> |����� ��� ������| -> \n\n";
		find_Newspaper_all(Newspapers_month, size_N, Main_phrase, Phrase, month);
		goto newspapers_delivery;
	}

	else if (choice == 9)
		goto guest_2_continue;
	else if (choice == 0)
		goto exit;
	/////////////GUEST_2////////////#3/////////
	/////////////GUEST_2///////////#4////////// ���
encycs_delivery:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ������ �� ��������� �����| -> |������������| -> \n\n";
	SetColor(7, 0);
	cout << phrase_month;
	

	cout << " |1|: ����� ������������ �� ��������\n";
	cout << " |2|: ����� ������������ �� ��������\n";
	cout << " |3|: ����� ������������ �� ������������\n";
	cout << " |4|: ����� ������������ �� ��������� �������\n\n";

	cout << " |5|: ����� ������������, ���������� � ��������� ���� ������\n";
	cout << " |6|: ����� ��� ������������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������������| -> |����� ������������ �� ��������| -> \n\n";
		find_Encyc_with_Name(Encycs_month, size_E_month, Main_phrase, Phrase);
		goto encycs_delivery;
	}
	if (choice == 2)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������������| -> |����� ������������ �� ��������| -> \n\n";
		find_Encyc_with_Topic(Encycs_month, size_E_month, Main_phrase, Phrase);
		goto encycs_delivery;
	}
	if (choice == 3)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������������| -> |����� ������������ �� ������������| -> \n\n";
		find_Encyc_with_Publisher(Encycs_month, size_E_month, Main_phrase, Phrase);
		goto encycs_delivery;
	}
	if (choice == 4)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������������| -> |����� ������������ �� ��������� �������| -> \n\n";
		find_Encyc_with_Pages(Encycs_month, size_E_month, Main_phrase, Phrase);
		goto encycs_delivery;
	}

	else if (choice == 5)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������������| -> |����� ������������, ���������� � ��������� ���� ������| -> \n\n";
		find_Encyc_with_Day(Encycs_month, size_E_month, Main_phrase, Phrase, month);
		goto encycs_delivery;
	}
	else if (choice == 6)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |������������| -> |����� ��� ������������| -> \n\n";
		find_Encyc_all(Encycs_month, size_E, Main_phrase, Phrase, month);
		goto encycs_delivery;
	}

	else if (choice == 9)
		goto guest_2_continue;
	else if (choice == 0)
		goto exit;
	/////////////GUEST_2////////////#4/////////
	/////////////GUEST_2///////////#5////////// ���
dicts_delivery:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������� � ������ �� ��������� �����| -> |�������| -> \n\n";
	SetColor(7, 0);
	cout << phrase_month;

	cout << " |1|: ����� ������� �� ��������\n";
	cout << " |2|: ����� ������� �� ������������\n\n";

	cout << " |3|: ����� �������, ���������� � ��������� ���� ������\n";
	cout << " |4|: ����� ��� �������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� ������� �� ��������| -> \n\n";
		find_Dict_with_Name(Dicts_month, size_D_month, Main_phrase, Phrase);
		goto dicts_delivery;
	}
	else if (choice == 2)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� ������� �� ������������| -> \n\n";
		find_Dict_with_Publisher(Dicts_month, size_D_month, Main_phrase, Phrase);
		goto dicts_delivery;
	}

	else if (choice == 3)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� �������, ���������� � ��������� ���� ������| -> \n\n";
		find_Dict_with_Day(Dicts_month, size_D_month, Main_phrase, Phrase, month);
		goto dicts_delivery;
	}
	else if (choice == 4)
	{
		Phrase = "  |���������� � ������ �� ��������� �����| -> |�������| -> |����� ��� �������| -> \n\n";
		find_Dict_all(Dicts_month, size_D, Main_phrase, Phrase, month);
		goto dicts_delivery;
	}

	else if (choice == 9)
		goto guest_2_continue;
	else if (choice == 0)
		goto exit;
/////////////GUEST_2////////////#5/////////









/////////////SORTING/////////////////////
sort:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���� ����������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: �����\n";
	cout << " |2|: �������\n";
	cout << " |3|: ������\n";
	cout << " |4|: ������������\n";
	cout << " |5|: �������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
		goto books_sort;
	else if (choice == 2)
		goto magazines_sort;
	else if (choice == 3)
		goto newspapers_sort;
	else if (choice == 4)
		goto encycs_sort;
	else if (choice == 5)
		goto dicts_sort;

	else if (choice == 9)
		goto guest;
	else if (choice == 0)
		goto exit;




books_sort:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���� ����������| -> |�����| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ������������� �� �������� (�-�)\n";
	cout << " |2|: ������������� �� ��������� (MIN-MAX)\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���� ����������| -> |�����| -> |������������� �� �������� (�-�)| -> \n\n";
		Sort_Book_with_Name(Books_st, size_B, Main_phrase, Phrase);
		goto books_sort;
	}
	else if (choice == 2)
	{
		Phrase = "  |���� ����������| -> |�����| -> |������������� �� ��������� (MIN-MAX)| -> \n\n";
		Sort_Book_with_Pages(Books_st, size_B, Main_phrase, Phrase);
		goto books_sort;
	}

	else if (choice == 9)
		goto sort;
	else if (choice == 0)
		goto exit;

magazines_sort:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���� ����������| -> |�������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ������������� �� �������� (�-�)\n";
	cout << " |2|: ������������� �� ��������� (MIN-MAX)\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���� ����������| -> |�������| -> |������������� �� �������� (�-�)| -> \n\n";
		Sort_Magazine_with_Name(Magazines_st, size_M, Main_phrase, Phrase);
		goto magazines_sort;
	}
	else if (choice == 2)
	{
		Phrase = "  |���� ����������| -> |�������| -> |������������� �� ��������� (MIN-MAX)| -> \n\n";
		Sort_Magazine_with_Pages(Magazines_st, size_M, Main_phrase, Phrase);
		goto magazines_sort;
	}

	else if (choice == 9)
		goto sort;
	else if (choice == 0)
		goto exit;

newspapers_sort:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���� ����������| -> |������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ������������� �� �������� (�-�)\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���� ����������| -> |������| -> |������������� �� �������� (�-�)| -> \n\n";
		Sort_Newspaper_with_Name(Newspapers_st, size_N, Main_phrase, Phrase);
		goto newspapers_sort;
	}


	else if (choice == 9)
		goto sort;
	else if (choice == 0)
		goto exit;

encycs_sort:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���� ����������| -> |������������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ������������� �� �������� (�-�)\n";
	cout << " |2|: ������������� �� ��������� (MIN-MAX)\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���� ����������| -> |������������| -> |������������� �� �������� (�-�)| -> \n\n";
		Sort_Encyc_with_Name(Encycs_st, size_E, Main_phrase, Phrase);
		goto encycs_sort;
	}
	else if (choice == 2)
	{
		Phrase = "  |���� ����������| -> |������������| -> |������������� �� ��������� (MIN-MAX)| -> \n\n";
		Sort_Encyc_with_Pages(Encycs_st, size_E, Main_phrase, Phrase);
		goto encycs_sort;
	}

	else if (choice == 9)
		goto sort;
	else if (choice == 0)
		goto exit;

dicts_sort:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���� ����������| -> |�������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: ������������� �� �������� (�-�)\n";
	cout << " |2|: ������������� �� ��������� (MIN-MAX)\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		Phrase = "  |���� ����������| -> |�������| -> |������������� �� �������� (�-�)| -> \n\n";
		Sort_Dict_with_Name(Dicts_st, size_D, Main_phrase, Phrase);
		goto dicts_sort;
	}
	else if (choice == 2)
	{
		Phrase = "  |���� ����������| -> |�������| -> |������������� �� ��������� (MIN-MAX)| -> \n\n";
		Sort_Dict_with_Pages(Dicts_st, size_D, Main_phrase, Phrase);
		goto dicts_sort;
	}

	else if (choice == 9)
		goto sort;
	else if (choice == 0)
		goto exit;
/////////////SORTING/////////////////////


/////////////FAVOURITES/////////////////////
fav:
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;

	cout << "  |���������| -> \n\n";
	SetColor(7, 0);

	cout << " |1|: �������� �������\n";
	cout << " |2|: ������� �������\n";
	cout << " |3|: ���������� ���������\n\n";

	cout << "-|9|: �����\n";
	cout << "-|0|: EXIT\n\n -> ";

	cin >> choice; cin.get();

	if (choice == 1)
	{
		add_fav(Books_st, Magazines_st, Newspapers_st, Encycs_st, Dicts_st, size_B, size_M, size_N, size_E, size_D, filename, Main_phrase);
		goto fav;
	}
	else if (choice == 2)
	{
		remove_fav(filename, Main_phrase);
		goto fav;
	}
	else if (choice == 3)
	{
		look_fav(Books_st, Magazines_st, Newspapers_st, Encycs_st, Dicts_st, size_B, size_M, size_N, size_E, size_D, filename, Main_phrase);
		goto fav;
	}

	else if (choice == 9)
		goto guest;
	else if (choice == 0)
		goto exit;
/////////////FAVOURITES/////////////////////



exit:
	system("cls");
	cout << " - �� ��������, ������� �������� ����� � ����� ����������!\n";
}
