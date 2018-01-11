#include "stdafx.h"
#include <iostream>
#include <utility>
#include <ctime>

using namespace std;

void zadanie_mas(int mas[4][4])
{
	for (int k = 0; k < 16;)
	{
		int i = rand() % 4;
		int j = rand() % 4;
		if (mas[i][j] == 0) 
		{
			mas[i][j] = k;
			k++;
		}
	}
}

void vivod(int mas[4][4])
{
	for (int i = 0; i < 4; i++) 
	{
		cout << " +----+----+----+----+" << endl;
		for (int j = 0; j < 4; j++) 
		{
			if (mas[i][j] < 10) 
			{
				if (mas[i][j] == 0)
					cout << " | " << " ";
				else cout << " | " << "0" << mas[i][j];
			}
			else cout << " | " << mas[i][j];
			if (mas[i][j] == 0)
				cout << " ";
		}
		cout << " | " << endl;
	}
	cout << " +----+----+----+----+" << endl;
}

bool proverka_win(int mas[4][4])
{
	int k = 0;
	for (int i = 0; i < 4; i++) 
	{
		if (k == 14)
		{ 
			break; 
		}
		for (int j = 0; j < 4; j++) 
		{
			if (k == 14) 
			{
				break; 
			}
			if (j < 3) 
			{
				if (mas[i][j] < mas[i][j + 1]) 
				{
					k++;
				}
				else 
				{
					return false;
				}
			}
			else 
			{
				if (mas[i][j] < mas[i + 1][0]) 
				{
					k++;
				}
				else 
				{
					return false;
				}
			}
		}
	}
	return true;
}

void down(int mas[4][4])
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			if (mas[i][j] == 0) 
			{
				if (i != 0) 
				{
					swap(mas[i][j], mas[i - 1][j]);
					vivod(mas);
					break;
				}
				else 
				{
					cout << "Error" << endl;
					break;
				}
			}
		}
	}
}

void up(int mas[4][4])
{
	int ex = 0;
	for (int i = 0; i < 4; i++) 
	{
		if (ex == 1) 
		{ 
			break; 
		}
		for (int j = 0; j < 4; j++) 
		{
			if (ex == 1) 
			{
				break; 
			}
			if (mas[i][j] == 0) 
			{
				if (i != 3) 
				{
					swap(mas[i + 1][j], mas[i][j]);
					vivod(mas);
					ex = 1;
					break;
				}
				else 
				{
					cout << "Error" << endl;
					ex = 1;
					break;
				}
			}
		}
	}
}

void left(int mas[4][4])
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			if (mas[i][j] == 0)
			{
				if (j != 3) 
				{
					swap(mas[i][j], mas[i][j + 1]);
					vivod(mas);
					break;
				}
				else 
				{
					cout << "Error" << endl;
					break;
				}
			}
		}
	}
}

void right(int mas[4][4])
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			if (mas[i][j] == 0) 
			{
				if (j != 0) 
				{
					swap(mas[i][j], mas[i][j - 1]);
					vivod(mas);
					break;
				}
				else 
				{
					cout << "Error" << endl;
					break;
				}
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int mas[4][4] = { { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
	};
	zadanie_mas(mas);
	vivod(mas);
	char op;
	while (cin >> op) 
	{
		if (op == 'j') 
		{
			down(mas);
			if (proverka_win(mas))
			{
				cout << "Perfect!" << endl;
				return -1;
			}
		}
		if (op == 'k') 
		{
			up(mas);
			if (proverka_win(mas)) 
			{
				cout << "Perfect!" << endl;
				return -1;
			}
		}
		if (op == 'h') 
		{
			left(mas);
			if (proverka_win(mas)) 
			{
				cout << "Perfect!" << endl;
				return -1;
			}
		}
		if (op == 'l') 
		{
			right(mas);
			if (proverka_win(mas)) 
			{
				cout << "Perfect!" << endl;
				return -1;
			}
		}
		if (op == 'q') 
		{
			cout << "Game over" << endl;
			return -1;
		}
		if (op != 'q' && op != 'h' && op != 'j' && op != 'k' && op != 'l')
		{
			cout << "Error op" << endl;
		}
	}
	if (proverka_win(mas)) 
	{
		cout << "Perfect!" << endl;
		return -1;
	}
	return 0;
}
