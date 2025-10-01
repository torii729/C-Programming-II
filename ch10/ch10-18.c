/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch10 PPT 예제 10-16 : 공용체를 이용한 RGB 색상 표현
	날짜 : 2025.10.01
*/

/*
    관련 개념:
    공용체(union)는 같은 메모리 공간을 공유한다.
    unsigned int color와 unsigned char rgb[4]는 같은 메모리를 가리킨다.
    따라서 rgb 배열에 값을 저장하면 color 값도 바뀐다.

    메모리 동작:
    rgb[0] = red, rgb[1] = green, rgb[2] = blue, rgb[3] = not used.
    각각의 바이트를 채워 넣으면 4바이트 정수 color 값이 자동으로 형성된다.
*/

#include <stdio.h>

typedef union color_t {
    unsigned int color; // 4바이트 정수(부호없음)
    unsigned char rgb[4]; // 1바이트씩 나눠 접근하려고 배열 선언
} COLOR_T;

int main(void)
{
    COLOR_T c1;

    c1.rgb[0] = 0xFF; // red
    c1.rgb[1] = 0xAB; // green
    c1.rgb[2] = 0x1F; // blue
    c1.rgb[3] = 0x00; // not used

    printf("rgb color = %08X\n", c1.color); // 32비트 정수값 출력

    return 0;
}
