#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";	// 최종 결과값 (문제 제공)값 할당용 변수

	sort(participant.begin(), participant.end());	// Participant 오름차순으로 정렬
	sort(completion.begin(), completion.end());		// Completion 오름차순으로 정렬

	for (int i = 0; i < participant.size() - 1; i++)	// Participant 배열 수 만큼 반복
	{
		if (participant[i] == completion[i]) continue;	// 만약 정렬 된 Participant와 Completion 값이 같다면 컨티뉴
		else											// Completion과 다르다면 완주하지 못한 사람
		{
			answer = participant[i];					// 최종 결과값 할당
			return answer;								// 종료
		}
	}

	answer = participant[participant.size() - 1];		// Completion에 미완주자가 없는 경우, Participant 마지막 값이 미완주자로 처리
	return answer;	// 종료
}

int main()	// 테스트용ㅁ
{
	vector<string> p = { "mislav", "stanko", "mislav", "ana" };
	vector<string> c = { "stanko", "ana", "mislav" };

	cout << solution(p, c);

	return 0;
}