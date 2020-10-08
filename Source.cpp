#include "Header.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	
	cout << "Введите 1-е число:   ";
	cin >> fN;
	unsigned long long int* summa = new unsigned long long int[t];
	unsigned long long int* difference = new unsigned long long int[t];
	unsigned long long int* mult = new unsigned long long int[t];
	unsigned long long int* first = new unsigned long long int[t];
	unsigned long long int* second = new unsigned long long int[t];
	unsigned long long int* div = new unsigned long long int[t];
	unsigned long long int* nsd = new unsigned long long int[t];
	unsigned long long int* nsk = new unsigned long long int[t];
	nsk = obnul(nsk, t);
	nsd = obnul(nsd, t);
	div = obnul(div, t);
	difference = obnul(difference,t);
	summa = obnul(summa,t);
	mult = obnul(mult,t);
	first = obnul(first,t);
	second = obnul(second,t);
	first = strToArr(fN);
	cout << "Введите 2-е число:   ";
	cin >> sN;
	second = strToArr(sN);
	unsigned long long int* power = new unsigned long long int[t];
	obnul(power, t);
	fN.size() >= sN.size() ? k = fN.size() : k = sN.size();
	k% w == 0 ? k = k / w : k = k / w + 1;
	summa = longAdd(first,second,summa,t);
	cout << "Сумма:   ";
	outArr(summa, t);
	cout << endl;
	if(LongCompare(first, second)==0)
		cout << "Значения одинаковы" << endl;
	if (LongCompare(first, second) == 1)
		cout << "Первое число больше второго" << endl;
	if (LongCompare(first, second) == 2)
		cout << "Второе число больше первого" << endl;
	if (LongCompare(first, second) <= 1)
	{
		cout << "Разность 2-х чисел:  ";
		difference = longDiff(first, second, difference);
		outArr(difference, t);
		cout << endl;
	}
	else
	{
		cout << "Разность 2-х чисел:  -";
		difference = longDiff(second, first, difference);
		outArr(difference, t);
		cout << endl;
	}
	mult = LongMul(first, second, t);
	cout << "Произведение:   ";
	outArr(mult, t);
	cout << endl;
	if (high(first, t) >= 0) cout << "Степень страшего розряда 1-ого числа: " << dec << high(first, t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	if (high(second, t) >= 0) cout << "Степень страшего розряда второго числа: " << dec << high(second, t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	if (high(summa, t) >= 0) cout << "Степень страшего розряда суммы: " << dec << high(summa, t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	if (high(difference, t) >= 0) cout << "Степень страшего розряда разности: " << dec << high(difference, t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	if (high(mult, t) >= 0) cout << "Степень страшего розряда произведения: " << dec << high(mult, t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	power = LongPow(first,second);
	cout << "Степень:   ";
	outArr(power, t);
	cout << endl;
	div = Division(first, second);
	cout << "Целая часть от деления:   ";
	outArr(div, t, 1);
	cout << endl;
	cout << "Остаток от деления:   ";
	outArr(r, t, 1);
	cout << endl;
	nsd = NSD(first, second);
	cout << "НОД 2-х чисел :    ";
	outArr(nsd,t);
	cout << endl;
	nsk = NSK(first, second);
	cout << "НОК 2-х чисел :    ";
	outArr(nsk, t, 1);
	cout << endl;
	
	delete[] nsk;
	delete[] nsd;
	delete[] div;
	delete[] power;
	delete[] difference;
	delete[] summa;
	delete[] mult;
	delete[] first;
	delete[] second;
	return 0;
}
