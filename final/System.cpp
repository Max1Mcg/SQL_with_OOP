#include "System.h"
#include <stdlib.h>
void System::del() {
	int id;
	bool find = false;
	cout << "Введите id" << endl;
	cin >> id;
	for (auto iter = database.begin(); iter != database.end(); iter++) {
		switch ((*iter).second) {
		case Army::SAILOR:
			if (id == ((Sailor*)((*iter).first))->get_id()) {
				database.erase(iter);
				find = true;
			}
			break;
		case Army::PILOT:
			if (id == ((Pilot*)((*iter).first))->get_id()) {
				database.erase(iter);
				find = true;
			}
			break;
		case Army::INFANTRYMAN:
			if (id == ((Infantryman*)((*iter).first))->get_id()) {
				database.erase(iter);
				find = true;
			}
			break;
		}
		if (find) {
			break;
		}
	}
	if (!find) {
		cout << "ID указан неверно!" << endl;
	}
}
void System::add() {
	string type, data, nat, fio, rank;
	char gender;
	int exp, number;
	cout << "Введите тип военнослужащего[sailor/pilot/infantryman]" << endl;
	cin >> type;
	cout << "Введите дату рождения военнослужащего[dd.mm.yyyy.]" << endl;
	cin >> data;
	cout << "Введите пол военнослужащего[m/f]" << endl;
	cin >> gender;
	cout << "Введите национальность военнослужащего[nationality]" << endl;
	cin >> nat;
	cout << "Введите ФИО военнослужащего[Surname Name Patronymic]" << endl;
	cin.ignore(1);
	getline(cin, fio);
	cout << "Введите ранг военнослужащего[rank]" << endl;
	cin >> rank;
	cout << "Введите опыт военнослужащего[exp]" << endl;
	cin >> exp;
	cout << "Введите номер военного билета военнослужащего[number]" << endl;
	cin >> number;
	if (type == "sailor") {
		database.push_back(make_pair(new Sailor(data, gender, nat, fio, rank, exp, number), Army::types::SAILOR));
	}
	else if (type == "pilot") {
		database.push_back(make_pair(new Pilot(data, gender, nat, fio, rank, exp, number), Army::types::PILOT));
	}
	else if (type == "infantryman") {
		database.push_back(make_pair(new Infantryman(data, gender, nat, fio, rank, exp, number), Army::types::INFANTRYMAN));
	}
}
void System::show_all() {
	print_table();
	for (auto iter = database.begin(); iter != database.end(); iter++) {
		switch ((*iter).second) {
		case Army::SAILOR:
			print_obj((Sailor*)((*iter).first));
			break;
		case Army::PILOT:
			print_obj((Pilot*)((*iter).first));
			break;
		case Army::INFANTRYMAN:
			print_obj((Infantryman*)((*iter).first));
			break;
		}
	}
}
template<class T>
void System::print_obj(T temp) {//вся инфо
	cout << setw(10) << temp->get_id();
	cout << setw(20) << temp->get_date_of_birth();
	cout << setw(30) << temp->get_full_name();
	cout << setw(9) << temp->get_gender();
	cout << setw(27) << temp->get_rank();
	cout << setw(20) << temp->get_nationality();
	cout << setw(15) << temp->get_experience() << endl;
}
void System::edit() {
	int id;
	bool find = false;
	cout << "Введите id" << endl;
	cin >> id;
	for (auto iter = database.begin(); !find && iter != database.end(); iter++) {
		switch ((*iter).second) {
		case Army::SAILOR:
			if (id == ((Sailor*)((*iter).first))->get_id()) {
				edit_(((Sailor*)((*iter).first)));
				find = true;
			}
			break;
		case Army::PILOT:
			if (id == ((Pilot*)((*iter).first))->get_id()) {
				edit_(((Pilot*)((*iter).first)));
				find = true;
			}
			break;
		case Army::INFANTRYMAN:
			if (id == ((Infantryman*)((*iter).first))->get_id()) {
				edit_(((Infantryman*)((*iter).first)));
				find = true;
			}
			break;
		}
	}
	if (!find) {
		cout << "ID указан неверно!" << endl;
	}
}
template<class T>
void System::edit_(T arg) {
	int move;
	string n_value;
	cout << "Выберите поле для изменения" << endl;// date_of_birth,  gender,  nationality, full_name, rank, experience,  ID
	cout << "1 - дата рождения" << endl;
	cout << "2 - гендер" << endl;
	cout << "3 - национальность" << endl;
	cout << "4 - ФИО" << endl;
	cout << "5 - ранг" << endl;
	cout << "6 - опыт" << endl;
	cout << "7 - ID" << endl;
	cin >> move;
	cout << "Введите новое значение" << endl;
	cin >> n_value;
	switch (move) {
	case 1:
		arg->set_date_of_birth(n_value);
		break;
	case 2:
		arg->set_gender(n_value[0]);//т.к. char
		break;
	case 3:
		arg->set_nationality(n_value);
		break;
	case 4:
		arg->set_full_name(n_value);
		break;
	case 5:
		arg->set_rank(n_value);
		break;
	case 6:
		arg->set_experience(stoi(n_value));
		break;
	case 7:
		arg->set_id(stoi(n_value));
		break;
	default:
		cout << "Действие введено неверно!" << endl;
	}
}
void System::search() {
	cout << "Введите класс[infatryman/pilot/sailor]" << endl;
	string c_n, field, value;
	Army::types class_name;
	int parameter;
	cin.ignore(1);
	getline(cin, c_n);
	if (c_n == "infatryman") {
		class_name = Army::types::INFANTRYMAN;
	}
	else if (c_n == "pilot") {
		class_name = Army::types::PILOT;
	}
	else if (c_n == "sailor") {
		class_name = Army::types::SAILOR;
	}
	cout << "Введите название поля в классе[date_of_birth/gender/nationality/full_name/id/experience/rank]" << endl;
	getline(cin, field);
	cout << "Выберите действие" << endl;
	cout << "1 - оператор '>'" << endl;
	cout << "2 - оператор '<'" << endl;
	cout << "3 - оператор '='" << endl;
	cout << "4 - содержит ..." << endl;
	cout << "5 - заканчивается на ..." << endl;
	cout << "6 - начинается с ..." << endl;
	cin >> parameter;
	cout << "Введите значение" << endl;
	cin >> value;
	Type type;//структура, хранящая элементы 3х классов
	switch (parameter) {
	case 1:
		print_table();
		for (auto iter = database.begin(); iter != database.end(); iter++) {
			if ((*iter).second == class_name) {
				type.set(*iter);
				if (type.obj1 != nullptr) {
					all_more(type.obj1, field, value);
				}
				else if (type.obj2 != nullptr) {
					all_more(type.obj2, field, value);
				}
				else if (type.obj3 != nullptr) {
					all_more(type.obj3, field, value);
				}
			}
		}
		break;
	case 2:
		print_table();
		for (auto iter = database.begin(); iter != database.end(); iter++) {
			if ((*iter).second == class_name) {
				type.set(*iter);
				if (type.obj1 != nullptr) {
					all_less(type.obj1, field, value);
				}
				else if (type.obj2 != nullptr) {
					all_less(type.obj2, field, value);
				}
				else if (type.obj3 != nullptr) {
					all_less(type.obj3, field, value);
				}
			}
		}
		break;
	case 3:
		print_table();
		for (auto iter = database.begin(); iter != database.end(); iter++) {
			if ((*iter).second == class_name) {
				type.set(*iter);
				if (type.obj1 != nullptr) {
					all_equal(type.obj1, field, value);
				}
				else if (type.obj2 != nullptr) {
					all_equal(type.obj2, field, value);
				}
				else if (type.obj3 != nullptr) {
					all_equal(type.obj3, field, value);
				}
			}
		}
		break;
	case 4:
		print_table();
		for (auto iter = database.begin(); iter != database.end(); iter++) {
			if ((*iter).second == class_name) {
				type.set(*iter);
				if (type.obj1 != nullptr) {
					all_cont(type.obj1, field, value);
				}
				else if (type.obj2 != nullptr) {
					all_cont(type.obj2, field, value);
				}
				else if (type.obj3 != nullptr) {
					all_cont(type.obj3, field, value);
				}
			}
		}
		break;
	case 5:
		print_table();
		for (auto iter = database.begin(); iter != database.end(); iter++) {
			if ((*iter).second == class_name) {
				type.set(*iter);
				if (type.obj1 != nullptr) {
					all_ends(type.obj1, field, value);
				}
				else if (type.obj2 != nullptr) {
					all_ends(type.obj2, field, value);
				}
				else if (type.obj3 != nullptr) {
					all_ends(type.obj3, field, value);
				}
			}
		}
		break;
	case 6:
		print_table();
		for (auto iter = database.begin(); iter != database.end(); iter++) {
			if ((*iter).second == class_name) {
				type.set(*iter);
				if (type.obj1 != nullptr) {
					all_start(type.obj1, field, value);
				}
				else if (type.obj2 != nullptr) {
					all_start(type.obj2, field, value);
				}
				else if (type.obj3 != nullptr) {
					all_start(type.obj3, field, value);
				}
			}
		}
		break;
	default:
		cout << "Действие введено неверно, попробуйте ещё раз";
	}
}
template<class T>
void System::all_more(T arg, string field, string value) {//>
	if (field == "id" && (arg->get_id() > stoi(value))) {
		print_obj(arg);
	}
	else if (field == "experience" && (arg->get_experience() > stoi(value))) {
		print_obj(arg);
	}
}
template<class T>
void System::all_less(T arg, string field, string value) {//<
	if (field == "id" && (arg->get_id() < stoi(value))) {
		print_obj(arg);
	}
	else if (field == "experience" && (arg->get_experience() < stoi(value))) {
		print_obj(arg);
	}
}
template<class T>
void System::all_equal(T arg, string field, string value) {//=
	if (field == "date_of_birth" && arg->get_date_of_birth() == value) {
		print_obj(arg);
	}
	else if (field == "full_name" && arg->get_full_name() == value) {
		print_obj(arg);
	}
	else if (field == "gender" && arg->get_gender() == value[0] && value.size() == 1) {
		print_obj(arg);
	}
	else if (field == "nationality" && arg->get_nationality() == value) {
		print_obj(arg);
	}
	else if (field == "id" && to_string(arg->get_id()) == value) {
		print_obj(arg);
	}
	else if (field == "experience" && to_string(arg->get_experience()) == value) {
		print_obj(arg);
	}
	else if (field == "rank" && arg->get_rank() == value) {
		print_obj(arg);
	}
}
template<class T>
void System::all_cont(T arg, string field, string value) {//contains
	if (field == "date_of_birth" && ((arg->get_date_of_birth().find(value)) != string::npos)) {
		print_obj(arg);
	}
	else if (field == "full_name" && ((arg->get_full_name().find(value)) != string::npos)) {
		print_obj(arg);
	}
	else if (field == "gender" && arg->get_gender() == value[0] && value.size() == 1) {
		print_obj(arg);
	}
	else if (field == "nationality" && ((arg->get_nationality().find(value)) != string::npos)) {
		print_obj(arg);
	}
	else if (field == "id" && ((to_string(arg->get_id()).find(value)) != string::npos)) {
		print_obj(arg);
	}
	else if (field == "experience" && ((to_string(arg->get_experience()).find(value)) != string::npos)) {
		print_obj(arg);
	}
	else if (field == "rank" && ((arg->get_rank().find(value)) != string::npos)) {
		print_obj(arg);
	}
}
template<class T>
void System::all_ends(T arg, string field, string value) {//ends with
	if (field == "date_of_birth" && (((arg->get_date_of_birth().rfind(value)) + value.size()) == arg->get_date_of_birth().size())) {
		print_obj(arg);
	}
	else if (field == "full_name" && (((arg->get_full_name().rfind(value)) + value.size()) == arg->get_full_name().size())) {
		print_obj(arg);
	}
	else if (field == "gender" && arg->get_gender() == value[0] && value.size() == 1) {//char
		print_obj(arg);
	}
	else if (field == "nationality" && (((arg->get_nationality().rfind(value)) + value.size()) == arg->get_nationality().size())) {
		print_obj(arg);
	}
	else if (field == "id" && (((to_string(arg->get_id()).rfind(value)) + value.size()) == to_string(arg->get_id()).size())) {
		print_obj(arg);
	}
	else if (field == "experience" && (((to_string(arg->get_experience()).rfind(value)) + value.size()) == to_string(arg->get_experience()).size())) {
		print_obj(arg);
	}
	else if (field == "rank" && (((arg->get_rank().rfind(value)) + value.size()) == arg->get_rank().size())) {
		print_obj(arg);
	}
}
template<class T>
void System::all_start(T arg, string field, string value) {//start with
	if (field == "date_of_birth" && (arg->get_date_of_birth().find(value) == 0)) {
		print_obj(arg);
	}
	else if (field == "full_name" && (arg->get_full_name().find(value) == 0)) {
		print_obj(arg);
	}
	else if (field == "gender" && arg->get_gender() == value[0] && value.size() == 1) {
		print_obj(arg);
	}
	else if (field == "nationality" && (arg->get_nationality().find(value) == 0)) {
		print_obj(arg);
	}
	else if (field == "id" && (to_string(arg->get_id()).find(value) == 0)) {
		print_obj(arg);
	}
	else if (field == "experience" && (to_string(arg->get_experience()).find(value) == 0)) {
		print_obj(arg);
	}
	else if (field == "rank" && (arg->get_rank().find(value) == 0)) {
		print_obj(arg);
	}
}
void System::print_table() {
	cout << setw(10) << "ID";
	cout << setw(20) << "Data of birthday";
	cout << setw(30) << "FIO";
	cout << setw(9) << "Gender";
	cout << setw(27) << "Rank";
	cout << setw(20) << "Nationality";
	cout << setw(15) << "Experience" << endl;
}
