// C++
// Two-dimensionalArray.cpp - Программа, которая создаёт двумерный масссив, 
//							  заполняет его рандомными числами и производит над ним несколько действий

// подключение необходимых библиотек
#include <iostream>
#include <ctime>

// подключение пространства имён
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	// здесь объявляются константы и переменные:
	const int ROW = 10;
	const int COL = 10;
	int newrand = 0;
	bool alreadyhere = false;
	int arr[ROW][COL];

	// здесь программа спощью циклов заполняет массив случайными цислами:
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

	// здесь программа выводит весь двумерный массив ввиде сетки:
	cout << endl;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << '\n' << '\n';
	}

	// здесь прогграмма находит и выводит наименьшее число в массиве:
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
	cout << "Наименьшее число в массиве это: " << nmch << '\n' << "Оно находиться в " << ++rnmch << "-ой строке и в " << ++cnmch << "-ой колонке;" << '\n' << '\n';

	// здесь прогграмма находит и выводит наибольшее число в массиве:
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

	cout << "Наибольшее число в массиве это: " << nbch << '\n' << "Оно находиться в " << ++rnbch << "-ой строке и в " << ++cnbch << "-ой колонке;" << '\n' << '\n';

	// корректное завершение программы:
	system("pause");
	return 0;
}