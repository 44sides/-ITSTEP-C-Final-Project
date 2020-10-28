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
	cout << "  |������ ������� � ����| -> |�����| -> \n\n";

	cout << "===================================\n";
	cout << "��������: "; cin.getline(new_st[ind].name, 80); cout << "\n";
	cout << "�����: "; cin.getline(new_st[ind].author, 45); cout << "\n";
	cout << "����: "; cin.getline(new_st[ind].genre, 30); cout << "\n";
	cout << "����: "; cin.getline(new_st[ind].language, 40); cout << "\n";

	cout << "�������: "; cin >> new_st[ind].pages; cout << "\n\n";
	cout << "��� ����������: "; cin >> new_st[ind].year_publish; cout << "\n\n";

	cout << "���� ������: \n";
	cout << "-����: "; cin >> new_st[ind].Date_delivery.day;
	cout << "-�����: "; cin >> new_st[ind].Date_delivery.month;
	cout << "-���: "; cin >> new_st[ind].Date_delivery.year;
	cout << "===================================\n\n";


	file = fopen("Books.dat", "wb");

	if (file == NULL) 
		perror("������ �������� �����");
	else
	{
		fwrite(new_st, sizeof(BOOKS), size, file);
		fclose(file);
	}

	cout << " - ����� ����� ������� �������� � ���� - \n\n";
	cout << "-|9|: �����\n\n -> ";
	cin.get(); cin.get();
}



void remove_book(BOOKS *st, int size)
{
	output_Books_admin(st, size);

	FILE *file; int choice, index = 0;
	int	new_size = size - 1;

	BOOKS *new_st = new BOOKS[new_size];


	cout << " -����� ����� ��� ��������: "; cin >> choice; choice--; cout << "\n\n";

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
		perror("������ �������� �����");
	else
	{
		fwrite(new_st, sizeof(BOOKS), new_size, file);
		fclose(file);
	}

	cout << " - ����� ������� ������� �� ���� - \n\n";
	cout << "-|9|: �����\n\n -> ";
	cin.get(); cin.get();
}




void output_Books_admin(BOOKS *st, int size)
{
	system("cls");

	cout << "  |������� ������� �� ����| -> |�����| -> \n\n";

	int ind = 1; int choice;
	for (int i = 0; i < size; i++)
	{
		cout << " ����� " << ind << ":" << "\n � " << st[i].name << "\n\n";
		ind++;
	}
	cout << "\n";
}