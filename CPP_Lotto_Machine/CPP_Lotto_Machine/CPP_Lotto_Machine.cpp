#include <iostream>
using namespace std;

// 로또 번호 생성기

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int min = i;
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[min])
			{
				min = j;
			}
		}
		if (i != min)
			Swap(numbers[i], numbers[min]);
	}
}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));

	int count = 0;
	while (count != 6)
	{
		int randValue = 1 + rand() % 45;

		// 이미 찾은 값인지?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				// 이미 찾은 값
				found = true;
				break;
			}
		}
		// 못 찾았으면 추가
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}
	Sort(numbers, 6);
}

int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);
	
	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6];

	// 3) 로또 번호 생성기
	ChooseLotto(numbers);
	//Sort(numbers, sizeof(numbers) / sizeof(int));	// sizeof(numbers) / sizeof(int) -> 배열의 크기
	
	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}
	

	return 0;
}