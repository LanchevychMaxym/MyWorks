#include <iostream>
#include<vector>
#include<string>
using namespace std;

class NMA                                    //NormalMarkovAlgorithm
{

public:
	struct Rule                                          //визначив структуру Правило, в якій маю змінні стрінг який я заміняю, стрінг на який і відмітка чи ця підстановка є кінцевою
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
	
	string Convert()                                                                      //дана ф-я застосовує введені правила до введеного слова
	{
		cout << to_convert << endl;
		for (int i = 0; i < rules.size(); i++)                                            //проходжуся по правилах 
		{
			cout << "Checking " << i + 1 << " rule" << endl;
			int where_change = to_convert.find(rules.at(i).to_change);                    //знаходжу місце заміни 
			if (where_change!=-1)                                                         //якщо ліва частина підстановки є у слові, то заміняю її
			{
				to_convert.replace(where_change, rules.at(i).to_change.length(), rules.at(i).changes);
				cout << "Make " << i + 1 << " production" << endl;
				cout << to_convert << endl;
				if (!rules.at(i).is_last)                    //якщо підстановка не заключна то занулюю 'і' для того щоб після застосованого правила заново перевіряти інші правила
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
	FirstTask();                                        //створив ф-ї які демонструють виконання кожного з 5-и завдань
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