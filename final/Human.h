#ifndef Human_h
#define Human_h
#include<iostream>
#include<string>
#include<tuple>
using namespace std;
class Human
{
protected:
	string date_of_birth;//[dd.mm.yyyy.]
	char gender;//[m/f]
	string nationality;//[nationality]
	string full_name;//[Surname Name Patronymic]
public:
	void set_date_of_birth(string date_of_birth);
	string get_date_of_birth();
	void set_gender(char gender);
	char get_gender();
	void set_nationality(string nationality);
	string get_nationality();
	void set_full_name(string full_name);
	string get_full_name();
};
#endif // !Human_h
