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
	// 즐거웠다 내 펫 :(
	// 스택에 올라가 있는 녀석을 delete한다는 이상한 코드
	if (_pet != nullptr)
		delete _pet;
}

