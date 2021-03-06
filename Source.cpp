#include "Header.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	
	cout << "Введите 1-е число:   ";
	cin >> fN;
	string N;
	unsigned long long int* summa = new unsigned long long int[t];
	unsigned long long int* difference = new unsigned long long int[t];
	unsigned long long int* mult = new unsigned long long int[t];
	unsigned long long int* first = new unsigned long long int[t];
	unsigned long long int* second = new unsigned long long int[t];
	unsigned long long int* div = new unsigned long long int[t];
	unsigned long long int* nsd = new unsigned long long int[t];
	unsigned long long int* nsk = new unsigned long long int[t];
	unsigned long long int* mu = new unsigned long long int[t];
	unsigned long long int* mod = new unsigned long long int[t];
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
	cout << dec << "Время работы суммы в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
	if(LongCompare(first, second)==0)
		cout << "Значения одинаковы" << endl;
	if (LongCompare(first, second) == 1)
		cout << "Первое число больше второго" << endl;
	if (LongCompare(first, second) == 2)
		cout << "Второе число больше первого" << endl;
	cout << endl;
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
	cout << dec << "Время работы разности в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
	mult = LongMul(first, second, t);
	cout << "Произведение:   ";
	outArr(mult, t);
	cout << endl;
	cout << dec << "Время работы произведения в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
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
	cout << endl;
	div = Division(first, second);
	cout << "Целая часть от деления:   ";
	outArr(div,t,1);
	cout << endl;
	cout << "Остаток от деления:   ";
	outArr(r, t,1);
	cout << endl;
	cout << dec << "Время работы деления в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
	nsd = NSD(first, second);
	cout << "НОД 2-х чисел :    ";
	outArr(nsd,t);
	cout << endl;
	nsk = NSK(first, second);
	cout << "НОК 2-х чисел :    ";
	outArr(nsk, t, 1);
	cout << endl << endl;;
	r = obnul(r, t);
	mod = obnul(mod,t);
	cout << "Введите модуль:   ";
	cin >> N;
	mod = strToArr(N);
	mu = obnul(mu, t);
	mu = Mu(mod);
	cout << "Сумма по модулю:    ";
	ModAdd(summa,mod);
	outArr(r, t, 1);
	cout << endl;
	cout << dec << "Время работы cуммы по модулю в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl;
	Sleep(1000);
	Barrett(summa, mod, mu);
	cout << "Сумма с помощью Барретта:    ";
	outArr(r,t);
	cout << endl;
	cout << dec << "Время работы cуммы по Барретту в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
	
	cout << "Разность по модулю:    ";
	ModDiff(difference, mod);
	outArr(r, t, 1);
	cout << endl;
	cout << dec << "Время работы разности по модулю в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl;
	Sleep(1000);
	Barrett(difference, mod, mu);
	cout << "Разности с помощью Барретта:    ";
	outArr(r, t);
	cout << endl;
	cout << dec << "Время работы разности по Барретту в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	mod = obnul(mod,t);
	cout << "Введите модуль:   ";
	cin >> N;
	mod = strToArr(N);
	mu = Mu(mod);
	cout << "Произведение по модулю:    ";
	ModMult(mult, mod);
	outArr(r, t, 1);
	cout << endl;
	//outArr(mult, t);
	//cout << endl;
	cout << dec << "Время работы произведения по модулю в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl;
	Sleep(1000);
	Barrett(mult, mod, mu);
	cout << "Произведение c помощью Барретта:    ";
	outArr(r, t);
	cout << endl;
	cout << dec << "Время работы произведения по Барретту в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
	
	// проверка (A+B)*C=A*C+B*C
	mod = obnul(mod, t);
	cout << "Введите 3-е число:   ";
	cin >> N;
	mod = strToArr(N);
	Chek(first, second, mod);
	
	cout << "Степень по схеме Горнера:   ";
	power = LongPowHorner(first,second);
	outArr(power,t);
	cout << endl;
	cout << dec << "Время работы степени по схеме Горнера в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
	cout << "Степень оконным методом:    ";
	power = obnul(power,t);
	power = LongPow(first, second);
	outArr(power, t);
	cout << endl;
	cout << dec << "Время работы степени оконным методом в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
	
	N.clear();
	mod = obnul(mod,t);
	cout << "Введите модуль:   ";
	cin >> N;
	mod = strToArr(N);
	mu = obnul(mu, t);
	mu = Mu(mod);
	power = obnul(power, t);
	power = ModPow(first, second, mod, mu);
	cout << "Степень по модулю:   ";
	outArr(power, t);
	cout << endl;
	cout << dec << "Время работы степени по модулю в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl;

	delete[] mod;
	delete[] mu;
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
