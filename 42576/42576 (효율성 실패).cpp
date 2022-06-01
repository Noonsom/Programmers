#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	bool Check = false;
	
	for (int i = 0; i < participant.size() - 1; i++)
	{
		Check = false;

		for (int j = 0; j < completion.size();)
		{
			if (participant[i] == completion[j])
			{
				Check = true;
				completion.erase(completion.begin()+j);
				break;
			}
			j++;
		}

		if (Check == false)
		{
			answer = participant[i];
			break;
		}
	}

	return answer;
}

int main()
{
	vector<string> p = { "mislav", "stanko", "mislav", "ana", "mislay" };
	vector<string> c = { "stanko", "ana", "mislav" ,"mislay" };

	cout << solution(p, c);

	return 0;
}
