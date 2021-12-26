#include<iostream>
#include<stack>
#include<sstream>
#include<queue>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

float evaluate(float a, float b, char c)
{
	if (c == '+')
		return a+b;
	else if (c == '-')
		return b-a;
	else if (c == '*')
		return a*b;
	else if (c == '/')
		return b/a;
	else if (c == '^')
		return pow(b,a);
	else
		return 0;
}

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
	string expres;
	cin >> expres;
	vector<char>token;
	stack<char>oper;
	vector<char> num;
	for ( i = 0; i < expres.size(); i++)
	{


		token.push_back(expres[i]);
	}
	i = 0;
	while (i != token.size())
	{

		if (isdigit(token[i]))
		{
			num.push_back(token[i]);
		}
		else if (token[i] == '(')
			oper.push(token[i]);
		else if (isalpha(token[i]))
			num.push_back(token[i]);
		else if (token[i] == ')')
		{
			while (oper.top() != '(' && oper.empty() == false)
			{
				int val = oper.top();
				oper.pop();
				num.push_back(val);
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
				else if (a < b)
					oper.push(token[i]);
				else
				{
					while (oper.empty() == false && oper.top() != '('   && a >= b)
					{
						int val1 = oper.top();
						oper.pop();
						num.push_back(val1);
						

					}
					oper.push(token[i]);
				}
			}
			else
				oper.push(token[i]);
		}
		i=i+1;
	}


	while (oper.empty() == false)
	{
		char val3 = oper.top();
		num.push_back(val3);
		oper.pop();
	}
	stack<float> f1;
	float upper=3, lower=2;
	int n=30;
	cin >> lower >> upper;
	cout << "around 10 \n";
	float sum = 0;
	float h = (upper - lower) / n;
	for (int j = 0; j <= n; j++)
	{
		for (int i = 0; i < num.size(); i++)
		{
			if (isdigit(num[i]))
			{
				f1.push(num[i] - '0');
			}
			else if (num[i] == 'x')
			{
				f1.push(lower + (j * h));
				
			}
			else
			{
				float temp = f1.top();
				f1.pop();
				float c = evaluate(temp, f1.top(), num[i]);
				f1.pop();
				f1.push(c);
			}
		}
		if (j == n||j==0)
			sum = sum + f1.top();

		else if (j % 2 == 0)
			sum = sum + (2*f1.top());
		else
			sum = sum + (4 * f1.top());
	}
	cout << sum*(h/3);
	

} 
