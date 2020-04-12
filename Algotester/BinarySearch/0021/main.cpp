#include<iostream>
using namespace std;
double BinarySearch(int arr[], int N, int M)
{
	double left = 0;
	double right = 1000000000;
	double midd = 0;//довжина галстука на яку ділимо
	int sum = 0;
	while (1)
	{
		midd = (left + right) / 2;
		for (int i = 0; i < N; i++)
		{
			sum += (arr[i] / midd);
		}
		if (sum < M)
		{
			right = midd;
			sum = 0;
		}
		else
		{
			left = midd;
			sum = 0;
		}

		if (right - left < 0.000001)
			return midd;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int *arr=new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	cout << BinarySearch(arr, n, m) << endl;

	system("pause");
	return 0;
}
