#pragma once
#include"Army.h"

//абстрактный класс для описания рангов ВМФ
class Navy : public Army
{
protected:
	std::set<std::string>ranks{ "sailor", "senior_sailor", "petty_officer_2_articles", "petty_officer_1_articles", "chief_petty_officer", "chief_petty_officer", "midshipman", "senior_warrant_officer", "ensign", "lieutenant", "senior_lieutenant", "captain-lieutenant", "rank_3_captain", "rank_2_captain", "rank_1_captain", "rear-admiral", "vice-admiral", "admiral", "admiral_of_the_fleet" };//заполнить
};
