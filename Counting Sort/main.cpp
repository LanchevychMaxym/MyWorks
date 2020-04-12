#include<iostream>
#include<vector>
#include<chrono>

using namespace std;
//
//template<typename T>
//vector<T> SortByNumeration(vector<T> arr)
//{
//	int n = arr.size();
//	vector<T> res(n);
//	int pos = 0;
//	int same = 0;
//	for (int i = 0; i <n ; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i] > arr[j] )
//				pos++;
//			if (arr[i] == arr[j] && i != j && j<i)
//				same++;
//		}
//		res[pos+same] = arr[i];
//		same = 0;
//		pos = 0;
//	}
//
//	return res;
//}

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
vector<T> SortByNumeration(vector<T> arr)
{
	int n = Max(arr);
	vector<T> counter_arr(n + 1);
	vector<T> res(arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		counter_arr[arr[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		counter_arr[i] += counter_arr[i - 1];
	}
	for (int i = arr.size(); i >= 1; i--)
	{
		res[counter_arr[arr[i - 1]] - 1] = arr[i - 1];
		counter_arr[arr[i - 1]]--;
	}

	return res;
}

void main()
{
	//vector<int> vec = { 0,4,6,3,5,4,5,6,3,5,76,4,3,6,4,5,6,55,5,45,6,454};
	vector<int> vec;
	for (int i = 0; i < 10000; i++)
	{
		vec.push_back(rand() % 10000);
	}
	int c = 0;
	int n = vec.size();
	auto start1 = chrono::system_clock::now();
	for (int i = 0; i <n; i++)
	{
		
		c++;
	}
	auto end1 = chrono::system_clock::now();
	auto res1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();

	auto start2 = chrono::system_clock::now();
	vec = SortByNumeration<int>(vec);
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
