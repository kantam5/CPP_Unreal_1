#pragma once

// 전방선언  함수 미리 선언 비슷
// 헤더파일에서 클래스 쓸 떄
class Player;
class Field;

// is-a
// has-a
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	Player* _player;
	Field* _field;
};

