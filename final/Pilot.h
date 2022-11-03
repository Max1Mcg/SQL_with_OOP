#pragma once
#include"AerospaceForces.h"
#include"Human.h"

//класс, представляющий описание для человека, являющегося пилотом
class Pilot : public Human, public AerospaceForces
{
public:
	//конструктор
	Pilot(std::string date_of_birth, char gender, std::string nationality, std::string full_name, std::string rank, int experience, unsigned long long int ID);
	//деструктор
	~Pilot();
	//реализация метода по установке id
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
