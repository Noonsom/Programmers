#include <string>
#include <vector>
#include <iostream>

using namespace std;


string solution(string new_id) {
	string answer = new_id;

	// 1단계 (모든 대문자를 대응되는 소문자로 치환합니다.)
	for (int i = 0; i < new_id.size(); i++)
	{
		answer[i] = tolower(new_id[i]);
	}

	// 2단계 (알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.)
	string temp;
	for (int i = 0; i < answer.size(); i++)
	{
		if ((answer[i] >= 'a' && answer[i] <= 'z') 
			|| answer[i] == '-' 
			|| answer[i] == '_' 
			|| answer[i] == '.'
			|| (answer[i] >= '0' && answer[i] <= '9'))
		{
			temp += answer[i];
		}
	}
	answer = temp;

	// 3단계 (마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.)
	for (int i = 1; i < answer.size(); i++)
	{
		if (answer[i] == '.' && answer[i - 1] == '.')
		{
			answer.erase(answer.begin() + i);
			--i;
		}
	}

	// 4단계 (마침표(.)가 처음이나 끝에 위치한다면 제거합니다.)
	if (answer[0] == '.') answer.erase(0,1);
	if (answer[answer.size()-1] == '.') answer.erase(answer.size()-1);

	// 5단계 (new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.)
	if (answer == "") answer = 'a';

	// 6단계 (길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다. 
	//       만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.)
	if (answer.size() > 15)
	{
		answer.erase(15, answer.size());
		if (answer[answer.size()-1] == '.') answer.erase(answer.size()-1);
	}
	
	// 7단계 (길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.)
	while (answer.size() <= 2)
	{
		answer += answer[answer.size() - 1];
	}

	return answer;
}


int main()	// 테스트용
{
	string A;

	cin >> A;
	cout << solution(A);
	return 0;
}
