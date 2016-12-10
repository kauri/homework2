#pragma once
#include <string>
#include <vector>
using namespace std;

class Drink
{
public:
	Drink() : price_(0), name_("") {}
	Drink(const std::string& name, int price);
	~Drink() {}


	const std::string& getname();
	void setname(const std::string& name);

	int getprice() const;
	void setprice(int price);

private:
	int price_;
	std::string name_;
};


class DrinkMachine
{
public:
	DrinkMachine() {}
	~DrinkMachine();
		
	int putdrink(const string& name, int price);
	bool popdrink(const string & name, Drink ** outdrink);	
	bool getdrink(int pos, Drink** outdrink);
	const string& getinformation();
	int totaldrinkcount();
	int sell(const Drink* drink);
	int gettotalincome();
	
private:
	vector<Drink*> drinks_;
	int totalincome_;
	string info_;
};