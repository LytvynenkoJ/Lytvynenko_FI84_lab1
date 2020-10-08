#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "time.h"
#include <string>
#include "locale.h"
using namespace std;


string fN;
string sN;
int w = 7;
int k = 0;
auto start = chrono::steady_clock::now();
auto endtime = chrono::steady_clock::now();
double tim = 0.0;
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
unsigned long long int SB(unsigned long long int word, int length, unsigned long long val, int s)
{
	const auto mask = (1u << length) - 1;
	return (word & ~(mask << s)) | ((val & mask) << s);
};
unsigned long long int* obnul(unsigned long long int arr[], int c)
{
	for (int i = 0; i < c; i++)
	{
		arr[i] = 0;
	}
	return arr;
}
int high(unsigned long long int arr[], int c,int w1 = w)
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
	coun += w1 * (a - 1);
	for (int i = 0; i < w1; i++)
	{
		if (arr[c - a] / p(4*i) < 1)
		{
			coun += i;
			i = w1;
		}
		if (arr[c - a] / pow(16, i) >= 1 && i == w - 1) coun += w1;
	}
	return coun - 1;
}
void outArr(unsigned long long int arr[], int c, int w1 = w)
{
	int coun = high(arr, c, w1) + 1;
	if (w1 != w)coun += 1;
	if (coun % w1 != 0) coun = coun / w1 + 1;
	else coun = coun / w1;
	for (int i = 0; i < coun; i++)
	{
		if (i != 0 && arr[c - coun + i] / p(4 * (w1 - 1)) < 1)
		{
			cout << setfill('0') << setw(w1) << hex << arr[c - coun + i];
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
unsigned long long int* longAdd(unsigned long long int first[], unsigned long long int  second[], unsigned long long int summa[], int co, int w1=w)
{
	unsigned long long int temp = 0;
	unsigned long long int carry = 0;
	int coun = high(first, co,w1)>=high(second,co,w1)?high(first,co,w1)+1:high(second,co,w1)+1;
	if (coun % w1 != 0) coun = coun / w1 + 1;
	else coun = coun / w1;
	if (w1 != w) coun += 1;
	start = chrono::steady_clock::now();
	for (int i = 1; i < coun+2; i++)
	{
		temp = first[co - i] + second[co - i] + carry;
		unsigned long long int c = p(4*w1);
		summa[co - i] = mask(temp,4*w1);
		carry = temp / c;
	}
	endtime = chrono::steady_clock::now();
	return summa;
}
int LongCompare(unsigned long long int first[], unsigned long long int second[])
{
	int h1 = 0;
	int h2 = 0;
	h1 = high(first, t);
	h2 = high(second, t);
	if (h1 >= h2) k = h1 + 1;
	else k = h2 + 1;
	k% w == 0 ? k = k / w : k = k / w + 1;
	for (int i = k; i > 0; i--)
	{
		if (first[t - i] > second[t - i]) return 1;
		if (first[t - i] < second[t - i]) return 2;
	}
	return 0;
}
unsigned long long int* longDiff(unsigned long long int first[], unsigned long long int second[], unsigned long long int difference[t], int w1=w)
{
	long long int borrow = 0;
	long long int temp = 0;
	int k = 0;
	high(first, t, w1) > high(second, t, w1) ? k = high(first, t, w1) + 1 : k = high(second, t, w1) + 1;
	k% w1 == 0 ? k = k / w1 : k = k / w1 + 1;
	if (w1 != w) k = k + 1;
	start = chrono::steady_clock::now();
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
			difference[t - i] = temp + p(4*w1);
			borrow = 1;
		}
	}
	endtime = chrono::steady_clock::now();
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
	start = chrono::steady_clock::now();
	for (int i = 0; i < cou; i++)
	{
		temp = LongMulOneDigit(first, second[c - i - 1], i,c);
		mult = longAdd(mult, temp, mult, c);
	}
	endtime = chrono::steady_clock::now();
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
	unsigned long long int* s2 = new unsigned long long int[t];
	s2=obnul(s2,t);
	s = obnul(s, t);
	unsigned long long int* c = new unsigned long long int[t];
	c = obnul(c, t);
	int n = 1;
	for (int i = 0; i < t; i++)
	{
		c[i] = second[i];
	}
	r = obnul(r, t);
	for (int i = 0; i < t; i++)
	{
		r[i] = first[i];
	}
	r[t - 1] = first[t - 1] % 16;
	c[t - 1] = second[t - 1] % 16;
	int k = high(second, t)+1;
	for (int i = 1; i < k; i++)
	{
		if (i%w!=0)
		{
			int l = pow(16, (i % w)+1);
			c[t - i - 1] = second[t - n] % l;
			unsigned long long int cl = 0;
			l = pow(16, (i % w));
			cl = c[t - i - 1] % l;
			c[t - i - 1] -= cl;
			c[t - i - 1] /= pow(16,(i%w));
		}
		else
		{
			n++;
			c[t-i - 1] = second[t - n] % 16;
		}
	}
	k = high(first, t) + 1;
	n = 1;
	for (int i = 1; i < k; i++)
	{
		if (i % w != 0)
		{
			int l = pow(16, (i % w) + 1);
			r[t - i - 1] = first[t - n] % l;
			unsigned long long int cl = 0;
			l = pow(16, (i % w));
			cl = r[t - i - 1] % l;
			r[t - i - 1] -= cl;
			r[t - i - 1] /= pow(16, (i % w));
		}
		else
		{
			n++;
			r[t - i - 1] = first[t - n] % 16;
		}
	}
	for (int i = 0; i < t; i++)
	{
		s[i] = c[i];
	}	
	div = obnul(div, t);
	while (LongCompare(r, second) < 2)
	{
		for (int i = 0; i < t; i++)
		{
			c[i] = s[i];
		}
		int mp = high(r, t, 1) + 1;
		k = high(c, t, 1) + 1;
		int temp = 0;
		temp = mp - k;
		for (int i = 0; i < t - temp; i++)
		{
			c[i] = c[i + temp];
		}
		for (int i = 0; i < temp; i++)
		{
			c[t - i - 1] = 0;
		}
		if (LongCompare(r, c) == 2)
		{
			temp -= 1;
			if (temp < 0) return div;
			for (int i = t - 2; i > 0; i--)
			{
				c[i + 1] = c[i];
			}
			c[0] = 0;
		}
		r = longDiff(r, c, r, 1);
		s2[t - temp - 1] = 1;
		div = longAdd(div, s2, div, t, 1);
		s2 = obnul(s2, t);
	};
    delete[] s2;
	delete[] s;
	delete[] c;
	return div;
}
unsigned long long int* DivTwo(unsigned long long int arr[])
{
	int h1 = high(arr, t) + 1;
	if (h1 % w == 0) h1 = h1 / w;
	else h1 = h1 / w + 1;
	int s1 = 0;
	int s2 = 0;
	for (int i = 0; i < h1; i++)
	{
		s1 = arr[t - h1 + i] & 1;
		arr[t - h1 + i] = arr[t - h1 + i] >> 1;
		arr[t - h1 + i] = arr[t - h1 + i] | (s2 << (4 * w - 1));
		s2 = s1;
	}
	return arr;
}
unsigned long long int* NSD(unsigned long long int first[], unsigned long long int second[])
{
	unsigned long long int* nsd = new unsigned long long int[t];
	unsigned long long int* f = new unsigned long long int[t];
	unsigned long long int* s = new unsigned long long int[t];
	nsd = obnul(nsd, t);
	f = obnul(f, t);
	s = obnul(s, t);
	for (int i = 0; i < t; i++)
	{
		f[i] = first[i];
		s[i] = second[i];
	}
	nsd[t - 1] = 1;
	int k1 = 0, k2 = 0;
	k1 = high(f,t)+1;
	k2 = high(s,t)+1;
	while (mask(f[t - 1], 2) % 2 == 0 && mask(s[t - 1], 2) % 2 == 0 && k1!=-1 && k2!=-1)
	{
		DivTwo(f);
		DivTwo(s);
		nsd = LongMulOneDigit(nsd,2,0,t);
	}
	k1 = high(f, t) + 1;
	k2 = high(s, t) + 1;
	while (mask(f[t - 1], 2) % 2 == 0 && k1!=-1 && k2!=-1)
	{
		DivTwo(f);
	}
	k1 = high(f, t) + 1;
	k2 = high(s, t) + 1;
	while (k2!=-1)
	{
		while (mask(s[t - 1], 2) % 2 == 0 && k2 != -1)
		{
			DivTwo(s);
			k2 = high(s, t) + 1;
		}
		if (LongCompare(f,s)==1)
		{
			unsigned long long int* c = new unsigned long long int[t];
			for (int i = 0; i < t; i++)
			{
				c[i] = f[i];
				f[i] = s[i];
			}
			s = longDiff(c, s, s);
			delete[] c;
		}
		else
		{
			s = longDiff(s,f,s);
		}
		k1 = high(f, t) + 1;
		k2 = high(s, t) + 1;
	}
	nsd = LongMul(nsd, f, t);
	
	delete[] f;
	delete[] s;
	return nsd;
}
