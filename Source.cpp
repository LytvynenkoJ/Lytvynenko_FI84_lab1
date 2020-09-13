#include "Header.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	
	cout << "Введите 1-е число:   ";
	cin >> fN;
	int* summa = new int[t];
	int* difference = new int[t];
	int* mult = new int[2*t+1];
	int* first = new int[t];
	int* second = new int[t];
	difference = obnul(difference,t);
	summa = obnul(summa,t);
	mult = obnul(mult,2*t+1);
	first = obnul(first,t);
	second = obnul(second,t);
	first = strToArr(fN);
	cout << "Введите 2-е число:   ";
	cin >> sN;
	second = strToArr(sN);
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
	outArr(mult, 2 * t);
	cout << endl;
	if (high(first, t) >= 0) cout << "Степень страшего розряда 1-ого числа: " << dec << high(first, t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	if (high(second, t) >= 0) cout << "Степень страшего розряда второго числа: " << dec << high(second, t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	if (high(summa, t) >= 0) cout << "Степень страшего розряда суммы: " << dec << high(summa, t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	if (high(difference, t) >= 0) cout << "Степень страшего розряда разности: " << dec << high(difference, t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	if (high(mult, 2*t) >= 0) cout << "Степень страшего розряда произведения: " << dec << high(mult, 2*t) << endl;
	else cout << "Я не знаю какой номер старшего НЕНУЛЕВОГО розряда у НУЛЯ" << endl;
	delete[] difference;
	delete[] summa;
	delete[] mult;
	delete[] first;
	delete[] second;
	return 0;
}
