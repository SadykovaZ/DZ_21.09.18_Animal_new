#include<iostream>
#include<string>
#include<fstream>

using namespace std;
string type[3] = { "�����", "����", "�������" };
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

		cout << " 0 - �����; \n 1 - ����; \n 2 - �������;" << endl;
		cin >> t_index;
		cout << "������� ����: ";
		cin >> color;
		cout << "������� ��������: ";
		cin >> skorost_peredvij;

		switch (t_index)
		{
		case 0:
			cout << "������� ��� �����: ";
			cin >> name;
			cout << "������� �������� ������: ";
			cin >> skorost_poleta;
			break;
		case 1:
			cout << "������� ��� �����: ";
			cin >> name;
			cout << "�������� �������������? ( 1 - ��, 0 - ���) ";
			cin >> parnokop;
			break;
		case 2:
			cout << "������� ��� ��������: ";
			cin >> name;
			cout << "������� IQ: ";
			cin >> IQ;
			break;
		}

	}
	void print()
	{
		cout << type[t_index] << endl;
		cout << "����: ";
		cout << color<<" ";
		cout << "�������� ������������: ";
		cout << skorost_peredvij<<" ";

		switch (t_index)
		{
		case 0:
			cout << "��� �����: " << name << " ";
			cout << "�������� ������  = " << skorost_poleta << endl;
			break;
		case 1:
			cout << "��� �����: " << name << " ";
			if (parnokop)
				cout << "�������������. " << endl;
			else
				cout << "�� �������������. " << endl;
			break;
		case 2:
			cout << "��� ��������: " << name << " ";
			cout << "IQ = " << IQ << endl;
			break;
		}

	}

};
void search_by_name(Animal* a)
{
	string poisk;
	cout << "������� ��� ��������� ������� ������ ��������: ";
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
	cout << "����� ��� ������ ����� : " << endl;
	cout << " 0 - �����; \n 1 - ����; \n 2 - �������;" << endl;
	int x;
	cin >> x;
	double p_a;
	bool pp;
	int p_iq;

	switch (x)
	{
	case 0:
		cout << "������� �������� ������: ";
		cin >> p_a;
		break;
	case 1:
		cout << "�������� �������������? ( 1 - ��, 0 - ���) ";
		cin >> pp;
		break;
	case 2:
		cout << "������� IQ: ";
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
		cout << "����: " << endl;
		cout << " 1 - ������,\n 2 - ��������������,\n 3 - �����" << endl;
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
		cout << " 1 - ���������� or 0 - �����" << endl;
		cin >> n1;
		if (n1 == 0)
			break;
	}


	delete[] a;

	system("pause");
	return 0;
}

