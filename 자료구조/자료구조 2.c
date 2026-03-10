#include <stdio.h>
#include <stdlib.h>


typedef struct Student /*구조체 태그*/ {
	char name[10];
	int score;
	/*필드*/
}Student; /*타입*/

void add(Student a) {
	a.score += 10;
	printf("2. %s : %d\n", a.name, a.score);
} /*이건 값에 의한 호출로 원본 값이 변하지 않음*/

Student add2(Student a) {
	a.score += 10;
	printf("4. %s : %d\n", a.name, a.score);
	return a;
}/*참초 호출 방법 1*/

void add3(Student *a) {
	(*a).score += 10;
	a->score += 10; /*간접 참조 연산자*/
	printf("6. %s : %d\n", (*a).name, (*a).score);
}/*참초 호출 방법 2 *와 . 중 먼저 연산되는건 .*/

int main() {
	Student s = { "Leo", 82 };
	printf("1. %s : %d\n", s.name, s.score);

	add(s);
	printf("3. %s : %d\n", s.name, s.score);

	s = add2(s);
	printf("5. %s : %d\n", s.name, s.score);

	add3(&s);
	printf("7. %s : %d\n", s.name, s.score);

	return 0;
}
