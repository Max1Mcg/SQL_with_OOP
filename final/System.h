#pragma once
#include<vector>
#include"Army.h"
#include"Sailor.h"
#include"Pilot.h"
#include"Infantryman.h"
#include"Type.h"
#include <stdlib.h>
#include<iomanip>

//класс, представляющий аналог операций с БД
class System
{
	//элементы в БД
	vector<pair<void*, Army::types>>database;
public:
	enum classes {
		sailor,
		pilot,
		infantryman
	};
	//добавление элемента
	void add();
	//вывод элемента
	void show_all();
	//вывод конкретного объекта
	template<class T>
	void print_obj(T temp);
	//редактирование БД
	void edit();
	//редактирование конкретного элемента
	template<class T>
	void edit_(T arg);
	//поиск элемента
	void search();
	//удаление элемента
	void del();
	//оператор > для поиска
	template<class T>
	void all_more(T arg, string field, string value);
	//оператор < для поиска
	template<class T>
	void all_less(T arg, string field, string value);
	//оператор == для поиска
	template<class T>
	void all_equal(T arg, string field, string value);
	//оператор подсчёта 
	template<class T>
	void all_cont(T arg, string field, string value);
	//оператор проверки на окончания значений в поле для поиска
	template<class T>
	void all_ends(T arg, string field, string value);
	//оператор для проверки полей на начало с переданного значения
	template<class T>
	void all_start(T arg, string field, string value);
	//вывод таблица
	void print_table();
};
