#pragma once
#include<iostream>
#include<string>
#include<set>
using namespace std;

//абстрактный класс, представляющий армию
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
	//метод для установки id военнослужащего
	virtual void set_id(unsigned long long int id) = 0;
	//метод для получения id военнослужащего
	virtual unsigned long long int get_id() = 0;
	//метод для установки ранга военнослужащего
	virtual void set_rank(std::string rank) = 0;
	//метод для получения ранга военнослужащего
	virtual std::string get_rank() = 0;
	//метод для установки опыта военнослужащего
	virtual void set_experience(int experience) = 0;
	//метод для получения опыта военнослужащего
	virtual int get_experience() = 0;
};
