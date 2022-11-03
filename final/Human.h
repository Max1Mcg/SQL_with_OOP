#ifndef Human_h
#define Human_h
#include<iostream>
#include<string>
#include<tuple>
using namespace std;

//класс для описания человека
class Human
{
protected:
	string date_of_birth;//[dd.mm.yyyy.]
	char gender;//[m/f]
	string nationality;//[nationality]
	string full_name;//[Surname Name Patronymic]
public:
	//метод для установки даты рождения человека
	void set_date_of_birth(string date_of_birth);
	//метод для получения даты рождения человека
	string get_date_of_birth();
	//метод для установки пола человека
	void set_gender(char gender);
	//метод для получения пола человека
	char get_gender();
	//метод для установки национальности человека
	void set_nationality(string nationality);
	//метод для олучения национальности человека
	string get_nationality();
	//метод для установки ФИО человека
	void set_full_name(string full_name);
	//метод для получения ФИО человека
	string get_full_name();
};
#endif // !Human_h
