#include <iostream>
#include <string>
#include "Drink.h"
#include "main.h"
using namespace std;

bool IsValidAnswer(char input)
{
	if (input == 'y')
		return true;
	if (input == 'n')
		return true;
	return false;
}

bool IsValidMoney(int input)
{
	if (input > 0 && input < 10000)
		return true;
	return false;
}

bool DrinkAdding(char input)
{
	if (input == 'y')
		return true;

	return false;
}

bool StopBuying(char input)
{
	if (input == 'y')
		return true;
	return false;
}

bool IsValidSelectDrink(int totalCount, int input)
{
	if (input <= 0)
		return false;

	if (totalCount + 1 < input)
		return false;

	return true;
}

const int RETURN_EXIT = 1;
const int NOT_ENOUGH_MONEY = 2;

int BuyDrink(int& mymoney, DrinkMachine& machine)
{
	char answer;
	do
	{
		cout << "���Ḧ �������ּ��� " << "( " << machine.getinformation();
		cout << machine.totaldrinkcount() + 1 << ". ����)" << endl;

		int diffMoney = 0;
		int nchoice = 0;
		do
		{
			cin >> nchoice;
			if (IsValidSelectDrink(machine.totaldrinkcount(), nchoice) == false)
			{
				cout << "�߸� �����ϼ̽��ϴ�." << endl;
			}

		} while (IsValidSelectDrink(machine.totaldrinkcount(), nchoice) == false);

		if (machine.totaldrinkcount() + 1 == nchoice)
			return RETURN_EXIT;

		Drink* choicedrink = nullptr;
		if (machine.getdrink(nchoice, &choicedrink) == true)
		{
			diffMoney = mymoney - choicedrink->getprice();
		}

		if (diffMoney < 0)
		{
			cout << "���� " << abs(diffMoney) << "�� ���� �մϴ�." << endl;
			return NOT_ENOUGH_MONEY;
		}

		machine.sell(choicedrink);
		mymoney -= choicedrink->getprice();

		cout << "���ᰡ ���Խ��ϴ�. ���� ���ŷ� ���� �Һ��� �ܾ��� " << mymoney << "��,";
		cout << "���Ǳ� ������� " << machine.gettotalincome() << "�� �Դϴ�." << endl;

		cout << "���� �Ͻðڽ��ϱ�? (y,n)";

		do
		{
			cin >> answer;
			if (IsValidAnswer(answer) == false)
			{
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���" << endl;
			}

		} while (IsValidAnswer(answer) != true);

	} while (StopBuying(answer) != true);
	
	return RETURN_EXIT;
}

auto main() -> int
{
	DrinkMachine machine;

	cout << "���Ǳ� ������� �Ǽ̽��ϴ�." << endl;
	char answer = 0;
	do
	{
		cout << "���� �׸��� �߰����ּ���" << endl;
		string name = "";
		int price = 0;
		cin >> name >> price;
		machine.putdrink(name, price);

		cout << "���Ḧ ��� �߰��Ͻðڽ��ϱ�? (y,n)";

		do
		{
			cin >> answer;
			if (IsValidAnswer(answer) == false)
			{
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���" << endl;
			}

		} while (IsValidAnswer(answer) != true);

	} while (DrinkAdding(answer) == true);

	cout << "�Һ��ڰ� �Ǽ̽��ϴ�." << endl;

	int mymoney = 0;
	int diffMoney = 0;
	Drink* choicedrink = nullptr;
	do
	{
		cout << "�Һ��� ���� �������ּ���( 0�� �̻� 10000�� ������ ���� �Է��ϼ���)" << endl;
		do
		{
			cin >> mymoney;
			if (IsValidMoney(mymoney) == false)
			{
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���" << endl;
			}
		} while (IsValidMoney(mymoney) != true);

		int returnCode = BuyDrink(mymoney, machine);
		if (returnCode == RETURN_EXIT)
		{
			break;
		}
		else if (returnCode == NOT_ENOUGH_MONEY)
		{
			continue;
		}

	} while (true);

	mymoney = 0;
	cout << "���� �ϼ̽��ϴ�." << endl;

	return 1;
}