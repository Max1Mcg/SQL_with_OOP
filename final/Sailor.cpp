#include "Sailor.h"
Sailor::Sailor(std::string date_of_birth, char gender, std::string nationality, std::string full_name, std::string rank, int experience, unsigned long long int id) {
	set_date_of_birth(date_of_birth);
	set_gender(gender);
	set_nationality(nationality);
	set_full_name(full_name);
	set_rank(rank);
	set_id(id);
	set_experience(experience);
}
void Sailor::set_rank(std::string rank) {
	this->rank = rank;
}
std::string Sailor::get_rank() {
	return rank;
}
void Sailor::set_experience(int experience) {
	this->experience = experience;
}
int Sailor::get_experience() {
	return experience;
}
Sailor::~Sailor() {

}
void Sailor::set_id(unsigned long long int id) {
	this->id = id;
}
unsigned long long int Sailor::get_id() {
	return id;
}
