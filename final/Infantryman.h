#ifndef Infantryman_h
#define Infantryman_h
#include"Human.h"
#include"GroundTroops.h"

//класс для описания человека-пехотинца
class Infantryman : public Human, public GroundTroops
{
public:
	//конструктор
	Infantryman(std::string date_of_birth, char gender, std::string nationality, std::string full_name, std::string rank, int experience, unsigned long long int ID);
	//деструктор
	~Infantryman();
	//реализация виртуального метода установки id
	virtual void set_id(unsigned long long int id) override;
	//реализация виртуального метода получения id
	virtual unsigned long long int get_id() override;
	//реализация виртуального метода установки ранга
	virtual void set_rank(std::string rank) override;
	//реализация виртуального метода получения ранга
	virtual std::string get_rank()override;
	//реализация виртуального метода установки опыта
	virtual void set_experience(int experience)override;
	//реализация виртуального метода получения опыта
	virtual int get_experience()override;
};
#endif 

