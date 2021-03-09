#include <iostream>
using namespace std;

int main()
{
	int input;
	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;
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