#include <stdio.h>
#include <string>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int solution(const char* s) {
	int answer = 0;
	int i = 0;
	string Result = "";

	while (i <= 50)	// 지문에서 주어준 최대 s 길이만큼 반복
	{
		if (s[i] == NULL)	// 만약 현재 s[i]값이 빈 공간(없는 값)이라면 현재 값을 Return할 것
		{
			answer = stoi(Result);	// Result 문자열 값을 stoi 함수로 정수로 변환
			return answer;
		}

		if (s[i] >= '0' && s[i] <= '9')	// 만약 현재 s[i]값이 문자가 아닌 0~9 사이의 숫자 값이라면 값을 저장하고 Continue 할 것!
		{
			Result += s[i];	// 숫자 문자를 Result 문자열 값에 저장
			i++;
			continue;	// 반복문 재시작
		}
		else {
			switch (s[i])	// 현재 s[i]값 스위치 시작
			{
			case 'z':	// 값이 "z"일 경우 Zero를 의미한다.
				Result += '0';	// 0값을 문자열 값에 저장한다.
				i = i + 4;	// 'zero' 문자열 수 만큼 i값 추가!
				break;

			case 'o':	// 값이 "o"일 경우 One을 의미한다.
				Result += '1';	// 1값을 문자열 값에 저장한다.
				i = i + 3;	// "one" 문자열 수 만큼 i값 추가!
				break;

			case 't':	// T의 경우 "Two", "Three" 두가지의 경우가 있다.
				if (s[i + 1] == 'w')	// 바로 다음 문자가 w인지 확인한다. (w일 경우 Two를 의미한다.)
				{
					Result += '2';	// 2값을 문자열 값에 저장한다.
					i = i + 3;	// "Two" 문자열 수 만큼 i값 추가! 
					break;
				}
				else  // 이하 코드는 위와 동일하게 진행된다.
				{
					Result += '3';
					i = i + 5;
					break;
				}

			case 'f':
				if (s[i + 1] == 'o')	// four (4)
				{
					Result += '4';
					i = i + 4;
					break;
				}
				else
				{
					Result += '5';	// five (5)
					i = i + 4;
					break;
				}

			case 's':
				if (s[i + 1] == 'i')	// Six (6)
				{
					Result += '6';
					i = i + 3;
					break;
				}
				else
				{
					Result += '7';	// Seven (7)
					i = i + 5;
					break;
				}

			case 'e':	// Eight (8)
				Result += '8';
				i = i + 5;
				break;

			case 'n':	// Nine (9)
				Result += '9';
				i = i + 4;
				break;
			}
		}
	}

	answer = stoi(Result);
	return answer;
}

// 테스트용 메인 함수
int main()
{
	cout << solution("2three45sixseven");	// 프로그래머스 예시 입출력 3번으로 시험

	return 0;
}