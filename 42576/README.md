# ✍️ 완주하지 못한 선수 (42576) 
- [프로그래머스 문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42576)
- 해시 문제
- 난이도 : Lv.1
- 풀이 언어 : <img src="https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white"/></a>

## ⚒️ [문제 설명]
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

## ⚠️ [제한 사항]
* 마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
* completion의 길이는 participant의 길이보다 1 작습니다.
* 참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
* 참가자 중에는 동명이인이 있을 수 있습니다.

## 💬 입출력 예
| participant | completion | return | 
| :--- | :--- | :--- |
| ["leo", "kiki", "eden"] | ["eden", "kiki"] | "leo" | 
| ["marina", "josipa", "nikola", "vinko", "filipa"]	| ["josipa", "filipa", "marina", "nikola"] | "vinko" |
|["mislav", "stanko", "mislav", "ana"]	| ["stanko", "ana", "mislav"]	| "mislav" |

## 🤔 풀이 과정
 처음에는 Participant에 있는 값을 하나씩 Completion과 대조하여,  
 없는 값을 찾는 반복문이였으나, 정확성만 통과하고 효율성에서 오답처리가 되었다.  
  
  Vector 형식의 Sort(정렬) 기법을 찾아봤고, 문자열 정렬 이후 Participant와 Completion을 대조하여  
  겹지지 않는 값을 찾아내는 반복문으로 다시 만들었다. 코드에도 주석으로 처리는 해 놓았고, 생각보다 이런 효율성이 중요하다는걸 새삼 깨닫게 되었다.
