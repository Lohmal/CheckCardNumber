#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void Errors(string a, int* c);
int Num1(string num);
int Num2(string num);
int main()
{
	string cardNumber;
	int passed,count = 0;
	while (true)
	{
		cout << "Card number : ";
		cin >> cardNumber;
		Errors(cardNumber, &count);
		if (count == 1)
		{
			_getch();
			system("cls");
		}
		else
		{
			passed=Num1(cardNumber)+Num2(cardNumber);
			if (passed%10==0)
			{
				cout << "Card is valid" << endl;
				_getch();
				break;
			}
			else
			{
				cout << "Card is invalid" << endl;
				_getch();
				system("cls");
			}
		}
	}
}
int Num1(string num)
{
	int number1, sum1 = 0;
	for (int i = 0; i < num.length(); i = i + 2)
	{
		number1 = (num[i] - '0')*2;
		if (number1 >9)
		{
			int a = number1 / 10;
			int b = number1 % 10;
			sum1 += (a + b);
		}
		else
		{
			sum1 += number1;
		}
	}
	return sum1;
}
int Num2(string num)
{
	int number2,sum2=0;
	for (int i = 1; i < num.length(); i=i+2)
	{
		number2 = num[i] - '0';
		sum2 += number2;
	}
	return sum2;
}
void Errors(string a, int* c)
{

	if (a.length() != 16)
	{
		cout << "You entered a missing or extra number." << endl;
		*c = 1;
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (!isdigit(a[i]))
		{
			cout << "You entered an incorrect character." << endl;
			*c = 1;
			break;
		}
	}
}
