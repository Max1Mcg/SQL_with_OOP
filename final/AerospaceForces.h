#pragma once
#include"Army.h"

//класс-наследник воздушных войск, реализующий свои ранги
class AerospaceForces : public Army
{
protected:
	std::set<std::string>ranks{ "soldier", "corporal", "lance_sergeant", "sergeant", "staff_sergeant", "sergeant_major", "ensign", "lieutenant", "senior_lieutenant", "captain", "major", "lieutenant_colonel", "colonel", "major_general", "lieutenant_general", "colonel_general" };
};
