#include "Drink.h"

Drink::Drink(const std::string & name, int price)
{
	name_ = name;
	price_ = price;
}

const std::string & Drink::getname()
{
	return name_;
}

void Drink::setname(const std::string & name)
{
	name_ = name;
}

int Drink::getprice() const
{
	return price_;
}

void Drink::setprice(int price)
{
	price_ = price;
}


DrinkMachine::~DrinkMachine()
{
	totalincome_ = 0;
	for (auto drink : drinks_)
	{
		delete drink;
	}
}

int DrinkMachine::putdrink(const string & name, int price)
{
	Drink* pdrink = new Drink(name, price);
	drinks_.push_back(pdrink);
	return 1;
}

bool DrinkMachine::popdrink(const string & name, Drink** outdrink)
{
	for each(auto drink in drinks_)
	{
		if (drink == nullptr)
			continue;
		if (drink->getname() == name)
		{
			*outdrink = drink;
			return true;
		}
	}

	return false;
}

bool DrinkMachine::getdrink(int pos, Drink ** outdrink)
{
	if ((size_t)pos-1 >= drinks_.size())
		return false;

	*outdrink = drinks_[pos - 1];

	return true;
}

const string & DrinkMachine::getinformation()
{
	info_.clear();
	int count = 1;
	for each(auto drink in drinks_)
	{
		info_.append(to_string(count));
		info_.append(" : ");
		info_.append(drink->getname());
		info_.append(" ");
		info_.append(to_string(drink->getprice()));
		info_.append(" ");
		count += 1;
	}

	return info_;
}

int DrinkMachine::totaldrinkcount()
{
	return drinks_.size();
}

int DrinkMachine::sell(const Drink * drink)
{
	if (drink == nullptr)
		return 0;

	totalincome_ += drink->getprice();
	return true;
}

int DrinkMachine::gettotalincome()
{
	return totalincome_;
}
