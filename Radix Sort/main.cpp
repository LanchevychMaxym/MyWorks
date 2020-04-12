#include <iostream>
#include<vector>
#include<chrono>
#include<algorithm>

using namespace std;

template<typename T>
int Max(vector <T>array) {
	int max = array[0];
	for (int i = 0; i < array.size(); i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max; 
}

template<typename T>
vector<T> SortByNumeration(vector<T> arr, int digit_num)
{
	vector<T> counter_arr(10);
	vector<T> res(arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		counter_arr[(arr[i]/digit_num)%10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		counter_arr[i] += counter_arr[i - 1];
	}
	for (int i = arr.size()-1; i >= 0; i--)
	{
		res[counter_arr[(arr[i]/digit_num)%10]-1] = arr[i];
		counter_arr[(arr[i] / digit_num) % 10]--;
	}

	return res;
}


template<typename T>
vector<T> DigitSort(vector<T> arr)
{
	int max = Max(arr);
	for (int digit_num = 1; max/digit_num >0; digit_num*=10)
	{
		arr = SortByNumeration<T>(arr, digit_num);
	}
	return arr;
}


void main()
{
	//vector<int> vec = { 534,466,683,356,553,432,517,653,398,564,764,456,337,652,475,548,645,553,587,455,633,454,6876 };
	vector<int> vec;
	for (int i = 0; i < 10000; i++)
	{
		vec.push_back(rand() % 10000);
	}
	int c = 0;
	int n = vec.size();
	auto start1 = chrono::system_clock::now();
	for (int i = 0; i < n; i++)
	{
		
		c++;
	}
	auto end1 = chrono::system_clock::now();
	auto res1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();

	auto start2 = chrono::system_clock::now();
	vec = DigitSort<int>(vec);
	auto end2 = chrono::system_clock::now();
	auto res2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;

	cout << res2 / res1 << endl;




	system("pause");
}