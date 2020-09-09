#include "Header.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	
	cout << "Ââåäèòå 1-å ÷èñëî:   ";
	cin >> fN;
	int* summa = new int[t+1];
	int* difference = new int[t];
	int* first = new int[t];
	int* second = new int[t];
	summa[t] = 0;
	summa = obnul(summa);
	first = obnul(first);
	second = obnul(second);
	first = strToArr(fN);
	cout << "Ââåäèòå 2-å ÷èñëî:   ";
	cin >> sN;
	second = strToArr(sN);
	fN.size() >= sN.size() ? k = fN.size() : k = sN.size();
	k% w == 0 ? k = k / w : k = k / w + 1;
	summa = longAdd(first,second,summa);
	delete[] summa;
	delete[] first;
	delete[] second;
	return 0;
}
