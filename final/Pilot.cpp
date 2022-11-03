#include "Pilot.h"
Pilot::Pilot(std::string date_of_birth, char gender, std::string nationality, std::string full_name, std::string rank, int experience, unsigned long long int id) {
	set_date_of_birth(date_of_birth);
	set_gender(gender);
	set_nationality(nationality);
	set_full_name(full_name);
	set_rank(rank);
	set_id(id);
	set_experience(experience);
}
void Pilot::set_rank(std::string rank) {
	this->rank = rank;
}
std::string Pilot::get_rank() {
	return rank;
}
void Pilot::set_experience(int experience) {
	this->experience = experience;
}
int Pilot::get_experience() {
	return experience;
}
Pilot::~Pilot() {

}
void Pilot::set_id(unsigned long long int id) {
	this->id = id;
}
unsigned long long int Pilot::get_id() {
	return id;
}
