#ifndef Infantryman_h
#define Infantryman_h
#include"Human.h"
#include"GroundTroops.h"
class Infantryman : public Human, public GroundTroops
{
public:
	Infantryman(std::string date_of_birth, char gender, std::string nationality, std::string full_name, std::string rank, int experience, unsigned long long int ID);
	~Infantryman();
	virtual void set_id(unsigned long long int id) override;
	virtual unsigned long long int get_id() override;
	virtual void set_rank(std::string rank) override;
	virtual std::string get_rank()override;
	virtual void set_experience(int experience)override;
	virtual int get_experience()override;
};
#endif 

