#include<iostream>
#include<math.h>

using namespace std;

bool CheckPrimary(int &Num)
{
	if (Num <=1)
		return false;
	for (int i = 2; i*i <= Num; i++)
	{
		if (Num % i == 0)
			return false;
	}

	return true;
}

int main()
{
	int entry;
	cout << "Enter Num:";
	cin >> entry;
	cout << CheckPrimary(entry) << endl;
	system("pause");
}
