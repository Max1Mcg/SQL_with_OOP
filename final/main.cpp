#include <iostream>
#include <cmath>
#include<vector>
#include<ctime>
#include<string>
#include<functional>
#include<map>
#include<set>
#include<iomanip>
#include<cassert>
#include<tuple>
#include<algorithm>
#include<stack>
#include<queue>
#include<sstream>
#include<windows.h>
#include"Army.h"
#include"AerospaceForces.h"
#include"Pilot.h"
#include"System.h"
using namespace std;

//вывод истории запросов
void show_requests(const vector<int>& requests) {
    cout << "Все запросы в хронологическом порядке" << endl;
    for (auto iter = requests.begin(); iter != requests.end(); iter++) {
        cout << *iter << endl;
    }
}

//консольное меню
void menu() {
    System system;
    bool work = true;
    int move;
    vector<int>requests;
    while (work) {
        cout << "выберите действие" << endl;
        cout << "-1 - вывод иерархии классов" << endl;
        cout << "0 - выход из приложения" << endl;
        cout << "1 - добавить военнослужащего в систему" << endl;
        cout << "2 - редактировать данные для военнослужащего по id" << endl;
        cout << "3 - удаление военнослужащего по id" << endl;
        cout << "4 - вывод всех объектов в системе" << endl;
        cout << "5 - запросы по поиску в полях объектов класса" << endl;
        cout << "6 - вывод списка всех запросов" << endl;
        cin >> move;
        requests.push_back(move);
        switch (move) {
        case -1:
            cout << "System - класс, хранящий в себе все данные" << endl;
            cout << "AerospaceForces(abstract), Navy(abstract), GroundTroops(abstract) ----> Army(abstract)" << endl;
            cout << "Pilot ----> AerospaceForces(abstract), Human" << endl;
            cout << "Sailor ----> Navy(abstract), Human" << endl;
            cout << "Infantryman ----> GroundTroops(abstract), Human" << endl;
            break;
        case 0:
            cout << "Спасибо за использование!" << endl;
            work = false;
            break;
        case 1:
            system.add();
            break;
        case 2:
            system.edit();
            break;
        case 3:
            system.del();
            break;
        case 4:
            system.show_all();
            break;
        case 5:
            system.search();
            break;
        case 6:
            show_requests(requests);
            break;
        default:
            cout << "Действие введено неверно, попробуйте ещё раз" << endl;
        }
    }
}

//точка входа в программу
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
}
