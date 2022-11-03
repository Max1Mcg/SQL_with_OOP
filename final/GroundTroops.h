#pragma once
#include"Army.h"
class GroundTroops : public Army
{
protected:
	std::set<std::string>ranks{ "soldier", "corporal", "lance_sergeant", "sergeant", "staff_sergeant", "sergeant_major", "ensign", "lieutenant", "senior_lieutenant", "captain", "major", "lieutenant_colonel", "colonel", "major_general", "lieutenant_general", "colonel_general" };//звания по возрастанию
};
