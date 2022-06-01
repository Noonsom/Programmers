#include <string>
#include <vector>
#include <iostream>

using namespace std;


string solution(string new_id) {
	string answer = new_id;

	// 1�ܰ�
	for (int i = 0; i < new_id.size(); i++)
	{
		answer[i] = tolower(new_id[i]);
	}

	// 2�ܰ�
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

	// 3�ܰ�
	for (int i = 1; i < answer.size(); i++)
	{
		if (answer[i] == '.' && answer[i - 1] == '.')
		{
			answer.erase(answer.begin() + i);
			--i;
		}
	}

	// 4�ܰ�
	if (answer[0] == '.') answer.erase(0,1);
	if (answer[answer.size()-1] == '.') answer.erase(answer.size()-1);

	// 5�ܰ�
	if (answer == "") answer = 'a';

	// 6�ܰ�
	if (answer.size() > 15)
	{
		answer.erase(15, answer.size());
		if (answer[answer.size()-1] == '.') answer.erase(answer.size()-1);
	}
	
	// 7�ܰ�
	while (answer.size() <= 2)
	{
		answer += answer[answer.size() - 1];
	}

	return answer;
}


int main()
{
	string A;

	cin >> A;
	cout << solution(A);
	return 0;
}
