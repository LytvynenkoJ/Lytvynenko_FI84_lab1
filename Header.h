#pragma once
#include <iostream>
#include <iomanip>
#include "time.h"
#include <string>
#include "locale.h"
using namespace std;


string fN;
string sN;
int w = 2;
int k = 0;
const int t = 100;
int* obnul(int arr[t])
{
	for (int i = 0; i < t; i++)
	{
		arr[i] = 0;
	}
	return arr;
}
int stringTo16(char letter)
{
	switch (letter)
	{
	case '0': return 0;
	case '1':return 1;
	case '2':return 2;
	case '3':return 3;
	case '4':return 4;
	case '5':return 5;
	case '6':return 6;
	case '7':return 7;
	case '8':return 8;
	case '9':return 9;
	case 'a':return 10;
	case 'b':return 11;
	case 'c':return 12;
	case 'd':return 13;
	case 'e':return 14;
	case 'f':return 15;
	}
	return -1;
}
int* strToArr(string num)
{
	int Number1 = 0;
	int* arr = new int[t];
	arr = obnul(arr);
	int c = 0;
	for (int i = 1; i < num.size() + 1; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (stringTo16(num[num.size() - i]) >= 0)
			{
				Number1 = Number1 + stringTo16(num[num.size() - i]) * pow(16, j);
				if (i == num.size())
				{
					j = w;
					if (i % w != 0) { c++; }
				}
				i++;
			}
			else
			{
				cout << "Error 404: Âû ââåëè íåêîððåêòíîå çíà÷åíèå" << endl;
				exit(0);
			}
		}
		i--;
		if (c == 0) arr[t - i / w] = Number1;
		else arr[t - i / w - 1] = Number1;
		Number1 = 0;
	}
	return arr;
}
int* longAdd(int first[t], int  second[t], int summa[t + 1])
{
	int temp = 0;
	int carry = 0;

	for (int i = 1; i < k + 1; i++)
	{
		temp = first[t - i] + second[t - i] + carry;
		int c = pow(16, w);
		summa[t + 1 - i] = temp % c;
		carry = temp / c;
	}
	cout << endl;
	cout << "Âàø îòâåò (ñóììà):   ";
	for (int i = 0; i < k; i++)
	{
		if (i != 0 && summa[t - k + i + 1] / pow(16, w - 1) < 1)
		{
			cout << setfill('0') << setw(w) << hex << summa[t - k + i + 1];
		}
		else cout << hex << summa[t - k + i + 1];
	}
	return summa;
}
int LongCompare(int first[t], int second[t]) 
{
	for (int i = k; i > 0; i--)
	{
		if (first[t - i] > second[t - i]) return 1;
		if (first[t - i] < second[t - i]) return 2;
	}
	return 0;
}
