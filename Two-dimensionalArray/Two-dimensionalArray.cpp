// C++
// Two-dimensionalArray.cpp - ���������, ������� ������ ��������� �������, 
//							  ��������� ��� ���������� ������� � ���������� ��� ��� ��������� ��������

// ����������� ����������� ���������
#include <iostream>
#include <ctime>

// ����������� ������������ ���
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	// ����� ����������� ��������� � ����������:
	const int ROW = 10;
	const int COL = 10;
	int newrand = 0;
	bool alreadyhere = false;
	int arr[ROW][COL];

	// ����� ��������� ������ ������ ��������� ������ ���������� �������:
	bool brk = false;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; )
		{
			newrand = rand() % 100000;
			for (int k = 0; k <= i; k++)
			{
				alreadyhere = false;
				for (int y = 0; y < j; y++)
				{
					if (newrand == arr[k][y])
					{
						alreadyhere = true;
						brk = true;
						break;
					}
				}
				if (brk == true)
				{
					break;
				}
			}
			if (alreadyhere == false)
			{
				arr[i][j] = newrand;
				j++;
			}
		}
	}

	// ����� ��������� ������� ���� ��������� ������ ����� �����:
	cout << endl;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << '\n' << '\n';
	}

	// ����� ���������� ������� � ������� ���������� ����� � �������:
	int cnmch;
	int rnmch;
	int nmch = arr[0][0];

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] < nmch)
			{
				nmch = arr[i][j];

				rnmch = i;
				cnmch = j;
			}
		}
	}

	cout << '\n' << '\n';
	cout << "���������� ����� � ������� ���: " << nmch << '\n' << "��� ���������� � " << ++rnmch << "-�� ������ � � " << ++cnmch << "-�� �������;" << '\n' << '\n';

	// ����� ���������� ������� � ������� ���������� ����� � �������:
	int cnbch;
	int rnbch;
	int nbch = arr[0][0];

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] > nbch)
			{
				nbch = arr[i][j];

				rnbch = i;
				cnbch = j;
			}
		}
	}

	cout << "���������� ����� � ������� ���: " << nbch << '\n' << "��� ���������� � " << ++rnbch << "-�� ������ � � " << ++cnbch << "-�� �������;" << '\n' << '\n';

	// ���������� ���������� ���������:
	system("pause");
	return 0;
}