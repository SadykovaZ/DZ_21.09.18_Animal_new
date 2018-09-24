#include<iostream>
#include<string>
#include<fstream>

using namespace std;
string type[3] = { "Птица", "Скот", "Человек" };
ifstream my_file;
int t;

struct Animal
{
	int t_index;
	int skorost_peredvij;
	string color;
	string name;
	union
	{
		double skorost_poleta;
		bool parnokop;
		int IQ;
	};
	void add()
	{
		my_file >> t_index;
		my_file >> color;
		my_file >> skorost_peredvij;
		switch (t_index)
		{
		case 0:

			my_file >> name;
			my_file >> skorost_poleta;
			break;
		case 1:

			my_file >> name;
			my_file >> parnokop;
			break;
		case 2:

			my_file >> name;
			my_file >> IQ;
			break;
		}

	}
	void fill()
	{

		cout << " 0 - Птица; \n 1 - Скот; \n 2 - Человек;" << endl;
		cin >> t_index;
		cout << "Введите цвет: ";
		cin >> color;
		cout << "Введите скорость: ";
		cin >> skorost_peredvij;

		switch (t_index)
		{
		case 0:
			cout << "Введите вид птицы: ";
			cin >> name;
			cout << "Введите скорость полета: ";
			cin >> skorost_poleta;
			break;
		case 1:
			cout << "Введите вид скота: ";
			cin >> name;
			cout << "Животное парнокопытное? ( 1 - да, 0 - нет) ";
			cin >> parnokop;
			break;
		case 2:
			cout << "Введите имя человека: ";
			cin >> name;
			cout << "Введите IQ: ";
			cin >> IQ;
			break;
		}

	}
	void print()
	{
		cout << type[t_index] << endl;
		cout << "Цвет: ";
		cout << color<<" ";
		cout << "Скорость передвижения: ";
		cout << skorost_peredvij<<" ";

		switch (t_index)
		{
		case 0:
			cout << "Вид птицы: " << name << " ";
			cout << "Скорость полета  = " << skorost_poleta << endl;
			break;
		case 1:
			cout << "Вид скота: " << name << " ";
			if (parnokop)
				cout << "Парнокопытное. " << endl;
			else
				cout << "Не парнокопытное. " << endl;
			break;
		case 2:
			cout << "Имя человека: " << name << " ";
			cout << "IQ = " << IQ << endl;
			break;
		}

	}

};
void search_by_name(Animal* a)
{
	string poisk;
	cout << "Введите вид животного которое хотите поменять: ";
	cin >> poisk;
	for (int i = 0; i < t; i++)
	{
		if (a[i].name == poisk)
		{
			a[i].fill();
			break;
		}
	}
}
void search1(Animal *a)
{
	cout << "Какой вид хотите найти : " << endl;
	cout << " 0 - Птица; \n 1 - Скот; \n 2 - Человек;" << endl;
	int x;
	cin >> x;
	double p_a;
	bool pp;
	int p_iq;

	switch (x)
	{
	case 0:
		cout << "Введите скорость полета: ";
		cin >> p_a;
		break;
	case 1:
		cout << "Животное парнокопытное? ( 1 - да, 0 - нет) ";
		cin >> pp;
		break;
	case 2:
		cout << "Введите IQ: ";
		cin >> p_iq;
		break;
	}

	for (int i = 0; i < t; i++)
	{
		switch (x)
		{
		case 0:

			if (a[i].skorost_poleta == p_a)
			{
				cout << a[i].name << " ";
				cout << endl;
			}
			break;
		case 1:

			if (a[i].parnokop == pp)
			{
				cout << a[i].name << " ";
				cout << endl;
			}
			break;
		case 2:

			if (a[i].IQ == p_iq)
			{
				cout << a[i].name << " ";
				cout << endl;
			}
			break;
		}
		
	}

}

int main()
{

	setlocale(LC_ALL, "Rus");
	my_file.open("in.txt", ios::in);

	my_file >> t;
	Animal * a;
	a = new Animal[t];

	for (int i = 0; i < t; i++)
	{
		a[i].add();
	}
	while (true)
	{
		cout << "Меню: " << endl;
		cout << " 1 - Печать,\n 2 - Редактирование,\n 3 - Поиск" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			for (int i = 0; i < t; i++)
			{
				a[i].print();
			}
			break;
		case 2: search_by_name(a);
			break;
		case 3: search1(a);
			break;
		}
		int n1;
		cout << endl;
		cout << " 1 - Продолжить or 0 - Выход" << endl;
		cin >> n1;
		if (n1 == 0)
			break;
	}


	delete[] a;

	system("pause");
	return 0;
}

