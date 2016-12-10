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
		cout << "음료를 선택해주세요 " << "( " << machine.getinformation();
		cout << machine.totaldrinkcount() + 1 << ". 종료)" << endl;

		int diffMoney = 0;
		int nchoice = 0;
		do
		{
			cin >> nchoice;
			if (IsValidSelectDrink(machine.totaldrinkcount(), nchoice) == false)
			{
				cout << "잘못 선택하셨습니다." << endl;
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
			cout << "돈이 " << abs(diffMoney) << "원 부족 합니다." << endl;
			return NOT_ENOUGH_MONEY;
		}

		machine.sell(choicedrink);
		mymoney -= choicedrink->getprice();

		cout << "음료가 나왔습니다. 음료 구매로 남은 소비자 잔액은 " << mymoney << "원,";
		cout << "자판기 매출액은 " << machine.gettotalincome() << "원 입니다." << endl;

		cout << "종료 하시겠습니까? (y,n)";

		do
		{
			cin >> answer;
			if (IsValidAnswer(answer) == false)
			{
				cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
			}

		} while (IsValidAnswer(answer) != true);

	} while (StopBuying(answer) != true);
	
	return RETURN_EXIT;
}

auto main() -> int
{
	DrinkMachine machine;

	cout << "자판기 사장님이 되셨습니다." << endl;
	char answer = 0;
	do
	{
		cout << "음료 항목을 추가해주세요" << endl;
		string name = "";
		int price = 0;
		cin >> name >> price;
		machine.putdrink(name, price);

		cout << "음료를 계속 추가하시겠습니까? (y,n)";

		do
		{
			cin >> answer;
			if (IsValidAnswer(answer) == false)
			{
				cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
			}

		} while (IsValidAnswer(answer) != true);

	} while (DrinkAdding(answer) == true);

	cout << "소비자가 되셨습니다." << endl;

	int mymoney = 0;
	int diffMoney = 0;
	Drink* choicedrink = nullptr;
	do
	{
		cout << "소비자 돈을 셋팅해주세요( 0원 이상 10000원 이하의 수를 입력하세요)" << endl;
		do
		{
			cin >> mymoney;
			if (IsValidMoney(mymoney) == false)
			{
				cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
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
	cout << "종료 하셨습니다." << endl;

	return 1;
}