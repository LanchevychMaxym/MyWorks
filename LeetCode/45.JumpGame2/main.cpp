#include<vector>
#include<iostream>
using namespace std;

void main()
{
	vector<int> mas = { 2,3,0,1,4 };
if (mas.size() == 1)
{
	cout << 0 << endl;
	return;
}
if (mas.size()-1 <= mas[0])
{
	cout << 1 << endl;
	return;
}
int count = 0;
int current = 0;
int max_jump = 0;

for (int i = 0; i < mas.size()-1;)
{
	if (mas[i]+i>=mas.size()-1)
	{
		count++;
		break;
	}
	max_jump = 0;
	for (int j = i; j <= mas.at(i)+i; j++)
	{
		if (max_jump <= mas[j] + j)
		{
			current = j;
			max_jump = mas[j] + j;
		}
	}
	count++;
	i = current;
}
cout << count << endl;
return;
	

	system("pause");
}
class Solution 
{
public:
	int jump(vector<int>& mas) 
	{
		if (mas.size() == 1)
		{
			return 0;
		}
		if (mas.size() - 1 <= mas[0])
		{

			return 1;
		}
		int count = 0;
		int current = 0;
		int max_jump = 0;

		for (int i = 0; i < mas.size() - 1;)
		{
			if (mas[i] + i >= mas.size() - 1)
			{
				count++;
				break;
			}
			max_jump = 0;
			for (int j = i; j <= mas.at(i) + i; j++)
			{
				if (max_jump <= mas[j] + j)
				{
					current = j;
					max_jump = mas[j] + j;
				}
			}
			count++;
			i = current;
		}
		return count;
	}
};