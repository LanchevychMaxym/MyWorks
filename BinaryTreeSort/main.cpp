#include<iostream>
#include<vector>
#include<chrono>

using namespace std;


class BTS
{
public:
	struct Node
	{
		int key;
		int index;
		struct Node* left, * right;
	};
	vector<int> arr;
	vector<int> indexes;
	Node* root;
public:
	BTS(){}
	BTS(vector<int> arrey) 
	{
		arr = arrey;
		root = NULL;
		root = insert(root, arr[0],0);
		for (int i = 1; i < arr.size(); i++)
			insert(root, arr[i],i);
	}

	Node* newNode(int item,int index)
	{
		struct Node* temp = new Node;
		temp->key = item;
		temp->index = index;
		temp->left = temp->right = NULL;
		return temp;
	}


	void storeSorted(Node* root, int& i)
	{
		if (root != NULL)
		{
			storeSorted(root->left, i);
			arr[i++] = root->key;
			indexes.push_back(root->index);
			storeSorted(root->right, i);
		}
	}


	Node* insert(Node* node, int key, int index)
	{
		if (node == NULL) return newNode(key,index);

		if (key < node->key)
			node->left = insert(node->left, key,index);
		else if (key >= node->key)
			node->right = insert(node->right, key,index);

		return node;
	}

	void treeSort()
	{
		int i = 0;
		storeSorted(root, i);
	}

	vector<int> getArr()
	{
		return arr;
	}
};




int main()
{
	
	vector<int> arr = { 5, 4, 7, 2, 11,54,6,4543,6,45,335,5,6,3,345,6,4,2,0,65 };
	int c = 0;
	int n = arr.size();
	auto start1 = chrono::system_clock::now();
	for (int i = 0; i < n; i++)
	{
		c++;
	}
	auto end1 = chrono::system_clock::now();
	int res1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();

	auto start2 = chrono::system_clock::now();
	BTS tree(arr);
	tree.treeSort();
	auto end2 = chrono::system_clock::now();
	int res2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();

	auto start3 = chrono::system_clock::now();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c++;
		}
		c++;
	}
	auto end3 = chrono::system_clock::now();
	int res3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3).count();
	

	arr = tree.getArr();

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << tree.indexes[i] << " ";
	cout << endl;
	cout << res2/res1 << " " << res2/res3 << endl;
	return 0;
}
