#pragma once
#include<vector>
#include"Army.h"
#include"Sailor.h"
#include"Pilot.h"
#include"Infantryman.h"
#include"Type.h"
#include <stdlib.h>
#include<iomanip>
class System
{
	vector<pair<void*, Army::types>>database;
public:
	enum classes {
		sailor,
		pilot,
		infantryman
	};
	void add();
	void show_all();
	template<class T>
	void print_obj(T temp);
	void edit();
	template<class T>
	void edit_(T arg);
	void search();
	void del();
	template<class T>
	void all_more(T arg, string field, string value);
	template<class T>
	void all_less(T arg, string field, string value);
	template<class T>
	void all_equal(T arg, string field, string value);
	template<class T>
	void all_cont(T arg, string field, string value);
	template<class T>
	void all_ends(T arg, string field, string value);
	template<class T>
	void all_start(T arg, string field, string value);
	void print_table();
};
