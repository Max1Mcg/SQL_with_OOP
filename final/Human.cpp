#include "Human.h"
void Human::set_date_of_birth(string date_of_birth) {
	this->date_of_birth = date_of_birth;
}
string Human::get_date_of_birth() {
	return date_of_birth;
}
void Human::set_gender(char gender) {
	this->gender = gender;
}
char Human::get_gender() {
	return gender;
}
void Human::set_nationality(string nationality) {
	this->nationality = nationality;
}
string Human::get_nationality() {
	return nationality;
}
void Human::set_full_name(string full_name) {
	this->full_name = full_name;
}
string Human::get_full_name() {
	return full_name;
}
