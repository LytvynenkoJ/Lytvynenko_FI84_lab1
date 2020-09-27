#pragma once
#include <iostream>
#include <iomanip>
#include "time.h"
#include <string>
#include "locale.h"
using namespace std;


string fN;
string sN;
int w = 7;
int k = 0;
const int t = 10000;
unsigned long long int* r = new unsigned long long int[t];


int p(int n)
{
	return 1u << n;
}
long long int mask(long long int a, int n)
{
	return a & ((1u << n) - 1);
}
unsigned long long int GHB(unsigned long long int word, int length) 
{
	int s = w * 4 - length;
	return (word >> s) & ((1u << length) - 1);
}
unsigned long long int SB(unsigned long long int word, int length,unsigned long long val, int s)
{
	const auto mask = (1u << length) - 1;
	return (word & ~(mask << s)) | ((val & mask) << s);
}
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
		if (arr[c - a] / p(4*i) < 1)
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
		if (i != 0 && arr[c - coun + i] / p(4*(w - 1)) < 1)
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
				Number1 = Number1 + stringTo16(num[num.size() - i]) * p(4*j);
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
	for (int i = 1; i < coun+2; i++)
	{
		temp = first[co - i] + second[co - i] + carry;
		unsigned long long int c = p(4*w);
		summa[co - i] = mask(temp,4*w);
		carry = temp / c;
	}
	return summa;
}
int LongCompare(unsigned long long int first[t], unsigned long long int second[t])
{
	high(first, t) > high(second, t) ? k = high(first, t)+1 : k = high(second, t)+1;
	k% w == 0 ? k = k / w : k = k / w + 1;
	for (int i = k; i > 0; i--)
	{
		if (first[t - i] > second[t - i]) return 1;
		if (first[t - i] < second[t - i]) return 2;
	}
	return 0;
}
unsigned long long int* longDiff(unsigned long long int first[t], unsigned long long int second[t], unsigned long long int difference[t])
{
	long long int borrow = 0;
	long long int temp = 0;
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
			difference[t - i] = temp + p(4*w);
			borrow = 1;
		}
	}
	return difference;
}
unsigned long long int* LongMulOneDigit(unsigned long long int first[], int digit, int shift,int co)
{
	unsigned long long int* m = new unsigned long long int[co];
	m = obnul(m,co);
	long long int temp = 0;
	long long int carry = 0;
	for (int i = 1; i <= high(first,co)/w+2; i++)
	{
		temp = first[co - i] * digit + carry;
		unsigned long long int c = p(4*w);
		m[co - i - shift] = mask(temp,4*w);
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
			temp = c / p(4*(w - 1 - j));
			power = LongMul(power, d[temp], t);
			//outArr(power, t);
			//cout << endl;
			if (i!=0 && j!=w-1)
			{
				for (int g = 0; g < 4; g++)
				{
					power = LongMul(power, power, t);
					//outArr(power, t);
					//cout << endl;
				}
			}
			c = c - temp * p(4*( w - 1 - j));
		}
	}
	return power;
}
void ShiftL(unsigned long long int s[],int n) 
{
	unsigned long long int* sh = new unsigned long long[t];
	sh = obnul(sh, t);
	unsigned long long int mHTL = 0;
	unsigned long long int mLTH = 0;
	int k = high(s,t)+1;
	k % w == 0 ? k /= w : k = k / w + 1;
	for (int i = 1; i < k+2; i++)
	{
		mHTL = GHB(s[t - i], n);
		s[t - i] = s[t - i] << n;
		sh[t - i] = mask(s[t-i],4*w);
		sh[t - i] = SB(sh[t - i], n, mLTH, 0);
		mLTH = mHTL;
	}
	delete[] sh;
}
unsigned long long int* Division(unsigned long long int first[], unsigned long long int second[])
{
	unsigned long long int* div = new unsigned long long int[t];
	unsigned long long int* s = new unsigned long long int[t];
	unsigned long long int* c = new unsigned long long int[t];
	c = obnul(c, t);
	div = obnul(div, t);
	r = obnul(r, t);
	int k = high(second, t);
	r = first;
	while (LongCompare(r, second) < 2)
	{
		obnul(c, t);
		int mp = high(r, t);
		int temp = mp - k;
		for (int i = 0; i < t; i++)
		{
			c[i] = second[i];
		}
		if (temp < 4 * w)
		{
			ShiftL(c, temp);
		}
		else
		{
			int i = temp;
			while (i > 0)
			{
				if (i >= 4 * w)
				{
					int q = i / w;
					for (int j = 1; j < t; j++)
					{
						c[j - q] = c[j];
					}
					for (int j = 0; j < q; j++)
					{
						c[t - j - 1] = 0;
					}
					i = i - 4 * q * w;
				}
				else
				{
					ShiftL(c, i);
					i = 0;
				}
			}
		}
		if (LongCompare(r, c) == 2)
		{
			system("pause");
			temp = temp - 1;
			for (int i = 0; i < t; i++)
			{
				c[i] = second[i];
			}
			if (temp < 4 * w)
			{
				ShiftL(c, temp);
			}
			else
			{
				int i = temp;
				while (i > 0)
				{
					if (i >= 4 * w)
					{
						int q = i / w;
						for (int j = 1; j < t; j++)
						{
							c[j - q] = c[j];
						}
						for (int j = 0; j < q; j++)
						{
							c[t - j - 1] = 0;
						}
						i = i - 4 * q * w;
					}
					else
					{
						ShiftL(c, i);
						i = 0;
					}
				}
			}
		}
		r = longDiff(r, c, r);
		s = obnul(s, t);
		s[t - 1] = 1;
		if (temp < 4 * w)
		{
			ShiftL(s, temp);
		}
		else
		{
			int i = temp;
			while (i > 0)
			{
				if (i >= 4 * w)
				{
					int q = i / w;
					for (int j = 1; j < t; j++)
					{
						c[j - q] = c[j];
					}
					for (int j = 0; j < q; j++)
					{
						c[t - j - 1] = 0;
					}
					i = i - 4 * q * w;
				}
				else
				{
					ShiftL(s, i);
					i = 0;
				}
			}
		}
		div = longAdd(div, s, div, t);
	}
	delete[] s;
	delete[] c;
	return div;
}
