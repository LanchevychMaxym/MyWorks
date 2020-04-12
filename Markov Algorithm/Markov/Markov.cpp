#include <iostream>
#include<vector>
#include<string>
using namespace std;

class NMA                                    //NormalMarkovAlgorithm
{

public:
	struct Rule                                          //�������� ��������� �������, � ��� ��� ���� ����� ���� � ������, ����� �� ���� � ������ �� �� ���������� � �������
	{
		string to_change;
		string changes;
		bool is_last;

		Rule() :to_change(""),changes(""),is_last(false){}
		Rule(string to_ch,string changes,bool isLast): to_change(to_ch),changes(changes),is_last(isLast){}
	};
	
	vector<Rule> rules;
	string to_convert;

	NMA():rules(),to_convert(""){}
	NMA(vector<Rule> rules,string to_convert):rules(rules),to_convert(to_convert){}
	
	string Convert()                                                                      //���� �-� ��������� ������ ������� �� ��������� �����
	{
		cout << to_convert << endl;
		for (int i = 0; i < rules.size(); i++)                                            //���������� �� �������� 
		{
			cout << "Checking " << i + 1 << " rule" << endl;
			int where_change = to_convert.find(rules.at(i).to_change);                    //�������� ���� ����� 
			if (where_change!=-1)                                                         //���� ��� ������� ���������� � � ����, �� ������ ��
			{
				to_convert.replace(where_change, rules.at(i).to_change.length(), rules.at(i).changes);
				cout << "Make " << i + 1 << " production" << endl;
				cout << to_convert << endl;
				if (!rules.at(i).is_last)                    //���� ���������� �� �������� �� ������� '�' ��� ���� ��� ���� ������������� ������� ������ ��������� ���� �������
				{
					i = -1;
				}
			}
		}
		return to_convert;
	}

};
void FirstTask()
{
	vector<NMA::Rule> rules;
	rules.push_back(NMA::Rule("xy", "yx", false));
	rules.push_back(NMA::Rule("xy", "", false));
	string to_convert = "xxyyxxyyxy";
	NMA a(rules,to_convert);
	cout << a.Convert() << endl;
}
void SecondTask()
{
	vector<NMA::Rule> rules;
	rules.push_back(NMA::Rule("yyx", "y", false));
	rules.push_back(NMA::Rule("xx", "y", false));
	rules.push_back(NMA::Rule("yyy", "x", true));
	string to_convert = "xxyyxxyyyxyyy";
	NMA a(rules, to_convert);
	cout << a.Convert() << endl;
}
void ThirdTask()
{
	vector<NMA::Rule> rules;
	rules.push_back(NMA::Rule("|+|", "||+", false));
	rules.push_back(NMA::Rule("+", "", true));
	string to_convert = "|||+||||";
	NMA a(rules, to_convert);
	cout << a.Convert() << endl;
}
void FourthTask()
{
	vector<NMA::Rule> rules;
	rules.push_back(NMA::Rule("*11", "T*1", false));
	rules.push_back(NMA::Rule("*1", "T", false));
	rules.push_back(NMA::Rule("1T", "T1F", false));
	rules.push_back(NMA::Rule("FT", "TF", false));
	rules.push_back(NMA::Rule("F1", "1F", false));
	rules.push_back(NMA::Rule("T1", "T", false));
	rules.push_back(NMA::Rule("TF", "F", false));
	rules.push_back(NMA::Rule("F", "1", false));
	rules.push_back(NMA::Rule("1", "1", true));
	
	string to_convert = "111*1111";
	NMA a(rules, to_convert);
	cout << a.Convert() << endl;
}
void FifthTask()
{
	vector<NMA::Rule> rules;
	rules.push_back(NMA::Rule("  ", " ", false));
	string to_convert = "bb  ba     ab  a";
	NMA a(rules, to_convert);
	cout << a.Convert() << endl;
}
void main()
{
	cout << "First task: " << endl;
	FirstTask();                                        //������� �-� �� ������������ ��������� ������� � 5-� �������
	cout << endl << "Second task: " << endl;
	SecondTask();
	cout << endl << "Third task: " << endl;
	ThirdTask();
	cout << endl << "Fourth task: " << endl;
	FourthTask();
	cout << endl << "Fifth task: " << endl;
	FifthTask();
	system("pause");
}