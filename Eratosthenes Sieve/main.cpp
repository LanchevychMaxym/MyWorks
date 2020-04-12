#include<iostream>
#include<math.h>
#include<vector>
#define N 1000000
using namespace std;

vector<bool> mas(N, true);

bool Eratosphen(int& Num)
{
	if (Num <= 1)
		return false;
	for (unsigned long long i = 2; i*i < N; i++)
	{
		if (mas[i]==true)
		{
			unsigned long long j = i*i;
			while (j < N)
			{
				mas[j] = false;
				j += i;
			}
		}
	}
	if (mas[Num] == true)
		return true;
	else
		return false;
}

int main()
{
	int entry;
	cout << "Enter Num:";
	cin >> entry;
	cout << Eratosphen(entry) << endl;
	system("pause");
}