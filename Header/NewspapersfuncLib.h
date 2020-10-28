#pragma once
/////////////GUEST_1//////////#2///////////
void find_Newspaper_with_Name(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[]);
void find_Newspaper_with_Topic(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[]);

void inform_about_newspaper(NEWSPAPERS *st, int index);
void which_inform_output_cycle_newspaper(NEWSPAPERS *st, int indexes[], int size, char Main_phrase[], char Phrase[]);
/////////////GUEST_1//////////////////////

/////////////GUEST_2/////////////////////
void find_Newspaper_with_Day(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[], int month);
void find_Newspaper_freshest(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[], int month);
void find_Newspaper_all(NEWSPAPERS *st, int size_, char Main_phrase[], char Phrase[], int month);
void find_Newspaper_all_S(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[], int month);
/////////////GUEST_2/////////////////////

/////////////SORTING/////////////////////
void Sort_Magazine_with_Name(MAGAZINES st[], int size, char Main_phrase[], char Phrase[]);
/////////////SORTING/////////////////////

///////////////////////INFUNCS///////////////////////////////////
void which_inform_output_cycle_newspaper(NEWSPAPERS *st, int indexes[], int size, char Main_phrase[], char Phrase[])
{
	size--; int c;

	cout << " - ���������� � ����� ������ ������� ����������?\n\n";
	cout << "-|9|: �����\n\n -> ";

	cin >> c; cin.get(); c--;

	while (c >= 0 && c <= size)
	{
		inform_about_newspaper(st, indexes[c]);

		system("cls");
		SetColor(8, 0);
		cout << Main_phrase << endl;
		cout << Phrase << endl;
		SetColor(7, 0);

		cout << " - ���������� � ����� ������ ������� ����������?\n\n";

		for (int i = 0; i <= size; i++)
			cout << " ������ " << i + 1 << ":" << "\n � " << st[indexes[i]].name << "\n\n";

		cout << "-|9|: �����\n\n -> ";
		cin >> c; cin.get(); c--;
	}
}
///////////////////////INFUNCS///////////////////////////////////
///////////////////////OUTPUT///////////////////////////////////
void inform_about_newspaper(NEWSPAPERS *st, int index)
{
	system("cls");
	cout << "===================================\n";
	cout << "��������: " << st[index].name << "\n\n";
	cout << "��������: " << st[index].topic << "\n\n\n";

	cout << "���� ������: " << st[index].Date_delivery.day << "." << st[index].Date_delivery.month << "." << st[index].Date_delivery.year << "\n";
	cout << "===================================\n\n";

	cout << "-|9|: �����\n\n -> ";
	cin.get();
}
///////////////////////OUTPUT///////////////////////////////////
/////////////GUEST_1///////////////////////
void find_Newspaper_with_Name(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);


	char name[75]; int index = 100; int c;
	cout << " �������� ������: "; cin.getline(name, 75); cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (stricmp(st[i].name, name) == 0)
		{
			cout << " ������:" << "\n � " << st[i].name << "\n\n";
			index = i;
		}
	}

	if (index == 100)
	{
		cout << " ������ �� ���� �������\n\n";
		cout << "-|9|: �����\n\n -> ";
		cin.get();
	}
	else
	{
		cout << " - ������� ���������� ���������� � ������?\n";
		cout << " |1|: ��\n";
		cout << " |2|: ���\n\n -> ";
		cin >> c; cin.get();

		if (c == 1)
			inform_about_newspaper(st, index);
	}
}


void find_Newspaper_with_Topic(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[])
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c;	int num = 1;
	int *indexes = new int[25]; int ind = 0;

	cout << " |1|: �������\n";
	cout << " |2|: �����\n";
	cout << " |3|: �������\n";
	cout << " |4|: ������������������\n\n";

	cout << "-|9|: �����\n\n -> ";

	cin >> c; cin.get();

	if (c >= 1 && c <= 4)
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
				if (stricmp(st[i].topic, "�������") == 0)
				{
					cout << " ������ " << num << ":" << "\n � " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_newspaper(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 2)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].topic, "�����") == 0)
				{
					cout << " ������ " << num << ":" << "\n � " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_newspaper(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 3)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].topic, "�������") == 0)
				{
					cout << " ������ " << num << ":" << "\n � " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_newspaper(st, indexes, ind, Main_phrase, Phrase);
		}
		else if (c == 4)
		{
			for (int i = 0; i < size; i++)
			{
				if (stricmp(st[i].topic, "������������������") == 0)
				{
					cout << " ������ " << num << ":" << "\n � " << st[i].name << "\n\n"; num++;
					indexes[ind] = i;
					ind++;
				}
			}
			which_inform_output_cycle_newspaper(st, indexes, ind, Main_phrase, Phrase);
		}
	}

	delete[] indexes;
}
/////////////GUEST_1///////////////////////




/////////////GUEST_2/////////////////////
void find_Newspaper_with_Day(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[], int month)
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c;
	int *indexes = new int[25]; int ind = 0; int num = 1;
	int day;

	cout << " ����: "; cin >> day; cin.get(); cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (st[i].Date_delivery.day == day && st[i].Date_delivery.month == month)
		{
			cout << " ������ " << ind + 1 << ":" << "\n � " << st[i].name << "\n\n";
			indexes[ind] = i;
			ind++;
		}
	}

	if (day > 31)
	{
		cout << " - ������...\n\n";
		cout << "-|9|: �����\n\n -> ";
		cin.get();
	}
	else if (ind == 0)
	{
		cout << " � ���� ���� ������ ������ �� ��������\n\n";
		cout << "-|9|: �����\n\n -> ";
		cin.get();
	}
	else
		which_inform_output_cycle_newspaper(st, indexes, ind, Main_phrase, Phrase);


	delete[] indexes;
}




void find_Newspaper_freshest(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[], int month)
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int c; int maxindex = 0;
	int max = st[0].Date_delivery.day;

	if (size == 0)
	{
		cout << " �� ������� ����� ����� �� ���� ��������\n\n" << endl;
		cout << "-|9|: �����\n\n -> ";
		cin.get();
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			if (max < st[i].Date_delivery.day)
			{
				max = st[i].Date_delivery.day;
				maxindex = i;
			}
		}

		cout << " ������:" << "\n � " << st[maxindex].name << ": |" << max << "." << month << "|" << "\n\n";


		cout << " - ������� ���������� ���������� � ������?\n";
		cout << " |1|: ��\n";
		cout << " |2|: ���\n\n -> ";
		cin >> c; cin.get();

		if (c == 1)
			inform_about_newspaper(st, maxindex);
	}
}



void find_Newspaper_all(NEWSPAPERS *st, int size_, char Main_phrase[], char Phrase[], int month)
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
		cout << " ������ " << ind + 1 << ":" << "\n � " << st[i].name << "\n\n";
		indexes[ind] = i;
		ind++;
	}

	which_inform_output_cycle_newspaper(st, indexes, ind, Main_phrase, Phrase);

	delete[] indexes;
}

void find_Newspaper_all_S(NEWSPAPERS *st, int size, char Main_phrase[], char Phrase[], int month)
{
	system("cls");
	SetColor(8, 0);
	cout << Main_phrase << endl;
	cout << Phrase << endl;
	SetColor(7, 0);

	int ind = 0;

	for (int i = 0; i < size; i++)
	{
		cout << " ������ " << ind + 1 << ":" << "\n � " << st[i].name << "\n\n";
		ind++;
	}

	cout << "-|9|: �����\n\n -> ";
	cin.get();
}
/////////////GUEST_2/////////////////////













/////////////SORTING/////////////////////
void Sort_Newspaper_with_Name(NEWSPAPERS st[], int size, char Main_phrase[], char Phrase[])
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

	for (int i = 1; i < size; i++) // ���������
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


	cout << "\n-|9|: �����\n\n -> ";
	cin.get();
}
/////////////SORTING/////////////////////