#pragma once
#include <iostream>
#include <iomanip>
#include "time.h"
#include <string>
#include "locale.h"
using namespace std;


string fN;
string sN;
int w = 4;
int k = 0;
const int t = 100;

int* obnul(int arr[], int c)
{
	for (int i = 0; i < c; i++)
	{
		arr[i] = 0;
	}
	return arr;
}
int high(int arr[], int c)
{
	int coun = 0;
	int a = 0;
	for (int i = 0; i < c; i++)
	{
		if (arr[i] != 0)
		{
			a = c - i;
			i = c;
		}
	}
	if (a == 0) return -2;
	coun += w * (a - 1);
	for (int i = 0; i < w; i++)
	{
		if (arr[c - a] / pow(16, i) < 1)
		{
			coun += i;
			i = w;
		}
		if (arr[c - a] / pow(16, i) >= 1 && i == w - 1) coun += w;
	}
	return coun - 1;
}
void outArr(int arr[], int c)
{
	int coun = high(arr, c) + 1;
	if (coun % w != 0) coun = coun / w + 1;
	else coun = coun / w;
	for (int i = 0; i < coun; i++)
	{
		if (i != 0 && arr[c - coun + i] / pow(16, w - 1) < 1)
		{
			cout << setfill('0') << setw(w) << hex << arr[c - coun + i];
		}
		else cout << hex << arr[c - coun + i];
	}
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
	arr = obnul(arr,t);
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
				cout << "Error 404: Вы ввели некорректное значение" << endl;
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
int* longAdd(int first[], int  second[], int summa[], int co)
{
	int temp = 0;
	int carry = 0;
	int coun = high(first, co)>=high(second,co)?high(first,co)+1:high(second,co)+1;
	if (coun % w != 0) coun = coun / w + 1;
	else coun = coun / w;
	for (int i = 1; i < coun+1; i++)
	{
		temp = first[co - i] + second[co - i] + carry;
		int c = pow(16, w);
		summa[co - i] = temp % c;
		carry = temp / c;
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
int* longDiff(int first[t],int second[t], int difference[t])
{
	int borrow = 0;
	int temp = 0;
	for (int i = 1; i < k + 1; i++)
	{
		temp = first[t - i] - second[t - i] - borrow;
		if (temp >= 0)
		{
			difference[t - i] = temp;
			borrow = 0;
		}
		else
		{
			difference[t - i] = temp + pow(16, w);
			borrow = 1;
		}
	}
	return difference;
}
int* LongMulOneDigit(int first[t], int digit, int shift) 
{
	int* m = new int[2*t];
	m = obnul(m,2*t);
	unsigned long int temp = 0;
	int carry = 0;
	for (int i = 1; i <= high(first,t)/w+2; i++)
	{
		temp = first[t - i] * digit + carry;
		int c = pow(16,w);
		m[2 * t - i - shift] = temp % c;
		carry = temp / c;
	}
	return m;
}
int* LongMul(int first[], int second[], int c)
{
	int* temp = new int[2 * c];
	int* mult = new int[2 * c];
	mult = obnul(mult, 2 * c);
	temp = obnul(temp, 2 * c);
	int cou = high(second, c) + 1;
	if (cou % w != 0) cou = cou / w + 1;
	else cou = cou / w;
	for (int i = 0; i < cou; i++)
	{
		temp = LongMulOneDigit(first, second[c - i - 1], i);
		mult = longAdd(mult, temp, mult, 2 * c);
	}
	return mult;
}
