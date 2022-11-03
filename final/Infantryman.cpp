#include "Infantryman.h"
Infantryman::Infantryman(std::string date_of_birth, char gender, std::string nationality, std::string full_name, std::string rank, int experience, unsigned long long int id) {
	set_date_of_birth(date_of_birth);
	set_gender(gender);
	set_nationality(nationality);
	set_full_name(full_name);
	set_rank(rank);
	set_id(id);
	set_experience(experience);
}
void Infantryman::set_rank(std::string rank) {
	this->rank = rank;
}
std::string Infantryman::get_rank() {
	return rank;
}
void Infantryman::set_experience(int experience) {
	this->experience = experience;
}
int Infantryman::get_experience() {
	return experience;
}
Infantryman::~Infantryman() {

}
void Infantryman::set_id(unsigned long long int id) {
	this->id = id;
}
unsigned long long int Infantryman::get_id() {
	return id;
}
