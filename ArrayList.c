#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {

	int list[MAX_LIST_SIZE];
	int length;

}ArrayListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L) {
	L->length = 0;
}

int is_empty(ArrayListType* L) {
	return L->length == 0;
}

int is_full(ArrayListType* L) {
	return L->length == MAX_LIST_SIZE;
}

void display(ArrayListType* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d\n", L->list[i]);
	}
}

void add(ArrayListType* L, int position, element item) {

	if (!is_full(L) && (position >= 0) && (position<=L->length)) {
		int i;
		for (i = (L->length - 1); i >= position; i--) {
			L->list[i+1] = L->list[i];
		}
		L->list[position] = item;
		L->length++;

	}
}

element delete(ArrayListType* L, int position) {
	//position : 삭제하고자 하는 위치
	//반환 값 : 삭제되는 자료
	int i;
	element item;

	if (position<0 || position>=L->length) error("위치 오류");

	item = L->list[position];

	for (i = position; i < (L->length - 1); i++) {
		L->list[i] = L->list[i + 1];
	}

	L->length--;
	return item;
}

int main() {

	ArrayListType list;
	ArrayListType* plist;

	//ArrayListType의 구조체를 정적으로 생성하고 이 구조체를 가리키는 포인터를
	//함수의 매개변수로 전달한다.

	init(&list);
	add(&list, 0, 10);
	add(&list, 0, 20);
	add(&list, 0, 30);
	display(&list);

	//ArrayListType의 구조체를 동적으로 생성하고 이 구조체를 가리키는 포인터를
	//함수의 매개 변수로 전달한다.
	
	plist = (ArrayListType*)malloc(sizeof(ArrayListType));
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);

	free(plist);

	return 0;
}