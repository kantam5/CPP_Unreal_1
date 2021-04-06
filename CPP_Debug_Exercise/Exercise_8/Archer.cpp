#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) : _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp)
{
}

Archer::~Archer()
{
	// ��ſ��� �� �� :(
	// ���ÿ� �ö� �ִ� �༮�� delete�Ѵٴ� �̻��� �ڵ�
	if (_pet != nullptr)
		delete _pet;
}

