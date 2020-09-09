#include "Header.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	
	cout << "¬ведите 1-е число:   ";
	cin >> fN;
	int* summa = new int[t+1];
	int* difference = new int[t];
	int* first = new int[t];
	int* second = new int[t];
	summa[t] = 0;
	//difference = obnul(difference);
	summa = obnul(summa);
	first = obnul(first);
	second = obnul(second);
	first = strToArr(fN);
	cout << "¬ведите 2-е число:   ";
	cin >> sN;
	second = strToArr(sN);
	fN.size() >= sN.size() ? k = fN.size() : k = sN.size();
	k% w == 0 ? k = k / w : k = k / w + 1;
	summa = longAdd(first,second,summa);



	//разность не работает!!!!
	/*int borrow = 0;
	int temp = 0;
	for (int i = 1; i < k+1; i++)
	{
		temp = first[t - i] - second[t - i] - borrow;
		if (temp>=0)
		{
			difference[t - i] = temp;
			borrow = 0;
		}
		else
		{
			difference[t - i] = temp + pow(16,w);
			borrow = 1;
		}
	}
	cout << "¬аш ответ (разность):   ";
	for (int i = 0; i < k; i++)
	{
		//if (i != 0 && difference[t - k + i] / pow(16, w - 1) < 1)
		//{
		//	cout << setfill('0') << setw(w) << hex << difference[t - k + i];
		//}
		//else 
		cout << difference[t - k + i];
	}

	delete[] difference;*/
	delete[] summa;
	delete[] first;
	delete[] second;
	return 0;
}