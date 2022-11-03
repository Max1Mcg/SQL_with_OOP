#pragma once
#include"Human.h"
#include"Navy.h"

//класс, реализующий человека-моряка
class Sailor : public Human, public Navy
{
public:
	//конструктор
	Sailor(std::string date_of_birth, char gender, std::string nationality, std::string full_name, std::string rank, int experience, unsigned long long int ID);
	//деструктор
	~Sailor();
	//реализация метода по установки id
	virtual void set_id(unsigned long long int id) override;
	//реализация метода по получению id
	virtual unsigned long long int get_id() override;
	//реализация метода по установке ранга
	virtual void set_rank(std::string rank) override;
	//реализация метода по получению ранга
	virtual std::string get_rank()override;
	//реализация метода по установке опыта
	virtual void set_experience(int experience)override;
	//реализация метода по получению опыта
	virtual int get_experience()override;
};
