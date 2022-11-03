#pragma once
#include"Sailor.h"
#include"Pilot.h"
#include"Infantryman.h"
#include"Army.h"

//вспомогательная структура для хранения нужного типа
struct Type
{
	Sailor* obj1;
	Pilot* obj2;
	Infantryman* obj3;
	void set(pair<void*, Army::types> temp) {
		obj1 = nullptr;
		obj2 = nullptr;
		obj3 = nullptr;
		switch (temp.second) {
		case Army::types::SAILOR:
			obj1 = (Sailor*)(temp.first);
			break;
		case Army::types::PILOT:
			obj2 = (Pilot*)(temp.first);
			break;
		case Army::types::INFANTRYMAN:
			obj3 = (Infantryman*)(temp.first);
			break;
		}
	}
};
