#include <iostream>
using namespace std;

const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// 하나의 세틀로 관리하기 -> 열거형
// 숫자를 지정 안하면 처음 값은 0으로 초기화된다
// 그 다음 값들은 이전 값 + 1
// 컴파일 단계에서 상수로 완전히 대체가 된다. 메모리를 안잡아 먹음
// 정수만 사용
// 0순위로 사용하자.
enum ENUM_RSP
{
	ENUM_ROCK = 1,
	ENUM_SCISSORS,
	ENUM_PAPER
};

// # -> 전처리 지시문
// #include <iostream> iostream이라는 파일을 찾아서 해당 팔일에 다 넣어주세요.
// 정수가 아니라도 사용할 수 있다. 
// 전처리 단계에서 처리된다. 디버그에서 무소용
// 지양하는게 좋다. 특히 상수로 만들 때
#define DEFINE_SCISSORS cout << "Hellow World" << endl;


int main()
{

	
	int input;
	
	int total = 0;
	int winCount = 0;
	srand(time(0));	// 시드 설정

	while (true)
	{
		cout << "가위(1) 바위(2) 보(3) 골라주세요" << endl;
		cout << "> ";
		// 사용자
		cin >> input;
		// 컴퓨터
		int computervValue = 1 + rand() % 3;	// rand() -> 0 ~ 32767

		auto a = &SCISSORS;

		if (total == 0) 
		{
			cout << "현재 승률 : 없음" << endl;
		}
		else
		{
			int winPercentage = (100 * winCount) / total;
			cout << "현재 승률 : " << winPercentage << endl;
		}
		
		if (input == SCISSORS) {
			switch (computervValue)
			{
			case SCISSORS:
				cout << "가위(플레이어) vs 가위(컴퓨터) 비겼습니다." << endl;
				break;
			case ROCK:
				cout << "가위(플레이어) vs 바위(컴퓨터) 졌습니다." << endl;
				total++;
				break;
			case PAPER:
				cout << "가위(플레이어) vs 보(컴퓨터) 이겼습니다." << endl;
				total++;
				winCount++;
				break;
			}
		}
		else if (input == ROCK) {
			switch (computervValue)
			{
			case SCISSORS:
				cout << "바위(플레이어) vs 가위(컴퓨터) 이겼습니다." << endl;
				total++;
				winCount++;
				break;
			case ROCK:
				cout << "바위(플레이어) vs 바위(컴퓨터) 비겼습니다." << endl;
				break;
			case PAPER:
				cout << "바위(플레이어) vs 보(컴퓨터) 졌습니다." << endl;
				total++;
				break;
			}
		}
		else if (input == PAPER) {
			switch (computervValue)
			{
			case SCISSORS:
				cout << "보(플레이어) vs 가위(컴퓨터) 졌습니다." << endl;
				total++;
				break;
			case ROCK:
				cout << "보(플레이어) vs 바위(컴퓨터) 이겼습니다." << endl;
				total++;
				winCount++;
				break;
			case PAPER:
				cout << "보(플레이어) vs 보(컴퓨터) 비겼습니다." << endl;
				break;
			}
		}
		
		
		cout << endl;
	}
	
	
}