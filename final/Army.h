#pragma once
#include<iostream>
#include<string>
#include<set>
using namespace std;
class Army
{
protected:
	unsigned long long int id;
	int experience;
	std::string rank;
public:
	enum types {
		SAILOR,
		PILOT,
		INFANTRYMAN
	};
	virtual void set_id(unsigned long long int id) = 0;
	virtual unsigned long long int get_id() = 0;
	virtual void set_rank(std::string rank) = 0;
	virtual std::string get_rank() = 0;
	virtual void set_experience(int experience) = 0;
	virtual int get_experience() = 0;
};
