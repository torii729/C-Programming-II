/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 17. 노래 정보 관리 프로그램에 검색 기능을 추가한다. 곡명 또는 가수명을 입력받아서
        해당 노래 정보를 찾아서 출력하는 프로그램을 작성하라. 일치하는 노래가 여러 곡이면 모두 출력.
	날짜 : 2025.10.01
*/

/*
    메모리 동작:
    SONG 구조체 배열 list는 각 노래의 제목, 가수, 장르, 재생 시간을 저장한다.
    key 문자열을 입력받아 각 노래의 title과 artist에 대해 부분 검색을 수행한다.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 30 // 문자열 크기

typedef struct {
    char title[SIZE];  // 노래 제목
    char artist[SIZE]; // 가수 이름
    char genre[SIZE];  // 장르
    int time; // 재생 시간(초)
} SONG;

void run_song();

// 기능명: main. 프로그램 실행 시작
// 내용: run_song 함수를 호출하여 노래 검색 기능을 실행한다.
// 입력: 없음
// 출력: 없음
// 오류: 없음
int main()
{
    run_song();
    return 0; // 정상 종료
}

// 기능명: run_song. 노래 검색 기능
// 내용: 노래 목록을 준비하고, 사용자가 입력한 키워드를 제목과 가수명에서 검색하여 결과를 출력한다.
// 입력: 표준 입력(검색 키워드). 종료 조건은 "." 입력
// 출력: 검색된 노래 정보(title, artist, genre, time)
// 오류: 없음
void run_song()
{
    SONG list[4] = {
        {"I'm Fine", "방탄소년단", "hip-hop", 209},
        {"봄날", "방탄소년단", "hip-hop", 274},
        {"Awake", "방탄소년단", "ballad", 226},
        {"별 보러 가자", "박보검", "ballad", 316}
    };

    char key[SIZE];

    while (1)
    {
        printf("검색(. 입력 시 종료) : ");
        scanf_s("%s", key, sizeof(key));

        if (!strcmp(key, "."))
        {
            break; // 종료 조건
        }

        for (int i = 0; i < 4; i++)
        {
            if (strstr(list[i].title, key) || strstr(list[i].artist, key))
            {
                printf("%s %s %s %d초\n", list[i].title, list[i].artist, list[i].genre, list[i].time);
            }
        }
    }
}
