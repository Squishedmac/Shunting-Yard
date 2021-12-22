#include<iostream>
#include<stack>
#include<sstream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

int pres(char op)
{
	if (op == '+'||op=='-')
	{
		return 1;
	}
	else if (op=='*'||op=='/')
	{
		return 2;
	}
	else if (op == '^')
	{
		return 3;
	}
	else
	return 0;
}

void main()
{
	int i= 0;
	string expres="3*x^x/(4+x)";
	//cin >> expres;
	vector<char>token;
	stack<char>oper;
	queue<char> num;
	for ( i = 0; i < expres.size(); i++)
	{


		token.push_back(expres[i]);
	}
	i = 0;
	while (i != token.size())
	{

		if (isdigit(token[i]))
			num.push(token[i]);
		else if (token[i] == '(')
			oper.push(token[i]);
		else if (isalpha(token[i]))
			num.push(token[i]);
		else if (token[i] == ')')
		{
			while (oper.top() != '(' && oper.empty() == false)
			{
				int val = oper.top();
				oper.pop();
				num.push(val);
			}
			if (oper.top() == '(')
				oper.pop();
		}
		else

		{
			
			if (oper.empty() == false)
			{
				int a = pres(oper.top());
				int b = pres(token[i]);

				if (oper.top() == '(')
					oper.push(token[i]);
				else if (pres(oper.top()) < pres(token[i]))
					oper.push(token[i]);
				else
				{
					while (oper.top() != '(' && oper.empty() == false && pres(oper.top()) >= pres(token[i]))
					{
						int val1 = oper.top();
						oper.pop();
						num.push(val1);
						oper.push(token[i]);
						break;
					}
				}
			}
			else
				oper.push(token[i]);
		}
		i=i+1;
	}
	while (oper.empty() == false)
	{
		int val3 = oper.top();
		num.push(val3);
		oper.pop();
	}
	while (!num.empty())
	{
		cout << num.front();
		num.pop();
	}
}