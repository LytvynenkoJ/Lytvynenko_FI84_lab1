#pragma once
#include <iostream>
#include <iomanip>
#include "time.h"
#include <string>
#include "locale.h"
using namespace std;


string fN;
string sN;
int w = 8;
int k = 0;
const int t = 10000;

unsigned long long int* obnul(unsigned long long int arr[], int c)
{
	for (int i = 0; i < c; i++)
	{
		arr[i] = 0;
	}
	return arr;
}
int high(unsigned long long int arr[], int c)
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
void outArr(unsigned long long int arr[], int c)
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
	case 'A':return 10;
	case 'a':return 10;
	case 'B':return 11;
	case 'b':return 11;
	case 'C':return 12;
	case 'c':return 12;
	case 'D':return 13;
	case 'd':return 13;
	case 'E':return 14;
	case 'e':return 14;
	case 'F':return 15;
	case 'f':return 15;
	}
	return -1;
}
unsigned long long int* strToArr(string num)
{
	unsigned long long int Number1 = 0;
	unsigned long long int* arr = new unsigned long long int[t];
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
unsigned long long int* longAdd(unsigned long long int first[], unsigned long long int  second[], unsigned long long int summa[], int co)
{
	unsigned long long int temp = 0;
	unsigned long long int carry = 0;
	int coun = high(first, co)>=high(second,co)?high(first,co)+1:high(second,co)+1;
	if (coun % w != 0) coun = coun / w + 1;
	else coun = coun / w;
	for (int i = 1; i < coun+1; i++)
	{
		temp = first[co - i] + second[co - i] + carry;
		unsigned long long int c = pow(16, w);
		summa[co - i] = temp % c;
		carry = temp / c;
	}
	return summa;
}
int LongCompare(unsigned long long int first[t], unsigned long long int second[t])
{
	for (int i = k; i > 0; i--)
	{
		if (first[t - i] > second[t - i]) return 1;
		if (first[t - i] < second[t - i]) return 2;
	}
	return 0;
}
unsigned long long int* longDiff(unsigned long long int first[t], unsigned long long int second[t], unsigned long long int difference[t])
{
	unsigned long long int borrow = 0;
	unsigned long long int temp = 0;
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
unsigned long long int* LongMulOneDigit(unsigned long long int first[], int digit, int shift,int co)
{
	unsigned long long int* m = new unsigned long long int[co];
	m = obnul(m,co);
	unsigned long long int temp = 0;
	unsigned long long int carry = 0;
	for (int i = 1; i <= high(first,co)/w+2; i++)
	{
		temp = first[co - i] * digit + carry;
		unsigned long long int c = pow(16,w);
		m[co - i - shift] = temp % c;
		carry = temp / c;
	}
	return m;
}
unsigned long long int* LongMul(unsigned long long int first[], unsigned long long int second[], int c)
{
	unsigned long long int* temp = new unsigned long long int[c];
	unsigned long long int* mult = new unsigned long long int[c];
	mult = obnul(mult, c);
	temp = obnul(temp, c);
	int cou = high(second, c) + 1;
	if (cou % w != 0) cou = cou / w + 1;
	else cou = cou / w;
	for (int i = 0; i < cou; i++)
	{
		temp = LongMulOneDigit(first, second[c - i - 1], i,c);
		mult = longAdd(mult, temp, mult, c);
	}
	return mult;
}
unsigned long long int* LongPow(unsigned long long int first[], unsigned long long int second[])
{
	unsigned long long int* power = new unsigned long long int[t];
	power = obnul(power,t);
	power[t - 1] = 1;
	unsigned long long int** d = new unsigned long long int* [16];
	for (int i = 0; i < 16; i++)
	{
		d[i] = new unsigned long long int[t];
		d[i] = obnul(d[i], t);
	}
	d[0][t - 1] = 1;
	for (int i = 0; i < t; i++)
	{
		d[1][i] = first[i];
	}
	for (int i = 2; i < 16; i++)
	{
		d[i] = LongMul(first, d[i - 1], t);
	}
	int a = high(second, t) + 1;
	cout << a << endl;
	int cou = 0;
	if (a % w != 0) cou = a / w + 1;
	else cou = a / w;
	int c = 0;
	for (int i = cou; i > 0; i--)
	{
		int temp = 0;
		c = second[t - i];
		for (int j = 0; j < w; j++)
		{
			temp = c / pow(16, w - 1 - j);
			power = LongMul(power, d[temp], t);
			if (i!=0 && j!=w-1)
			{
				for (int g = 0; g < 4; g++)
				{
					power = LongMul(power, power, t);
				}
			}
			c = c - temp * pow(16, w - 1 - j);
		}
	}
	return power;
}
