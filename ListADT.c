#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <limits.h>

#define FALSE 0
#define TRUE 1

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct LinkedListType{
	ListNode * head;
	int length;
}LinkedListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(LinkedListType* list) {
	if (list == NULL)return;
	list->length = 0;
	list->head = NULL;
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) { //공백 리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { //p가 NULL이면 첫 번째 노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	}
	else { //p 다음에 삽입
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	if (p == NULL) {
		*phead = (*phead)->link;
	}
	else {
		p->link = removed->link;
	}

	free(removed);
}

int is_empty(LinkedListType* list) {
	if (list->head == NULL)return 1;
	else return 0;
}

int get_length(LinkedListType* list) {
	return list->length;
}

ListNode* get_node_at(LinkedListType* list, int pos) {
	//리스트 안에서 pos 위치의 노드를 반환한다

	int i;
	ListNode* tmp_node = list->head;

	if (pos < 0)return NULL;

	for (i = 0; i < pos; i++) {
		tmp_node = tmp_node->link;
	}
	
	return tmp_node;
}

void add(LinkedListType* list, int position, element data) {
	//주어진 위치에 데이터를 삽입한다

	ListNode* p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		
		if (node == NULL)error("메모리 할당 에러");
		
		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}

}

void add_last(LinkedListType* list, element data) {
	add(list, get_length(list), data);
}

void add_first(LinkedListType* list, element data) {
	add(list, 0, data);
}

void delete(LinkedListType* list, int pos) {
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		ListNode* p = get_node_at(list, pos - 1);
		ListNode* removed = get_node_at(list, pos);
		remove_node(&(list->head), p, removed);
		list->length--;
	}
}

element get_entry(LinkedListType* list, int pos) {
	ListNode* p;
	if (pos >= list->length)error("위치 오류");

	p = get_node_at(list, pos);

	return p->data;
}

void clear(LinkedListType* list) {
	for (int i = 0; i < list->length; i++) {
		delete(list, i);
	}
}

void display(LinkedListType* list) {
	
	ListNode* node = list->head;
	printf("( ");

	for (int i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}

	printf(" )\n");
}

int is_in_list(LinkedListType* list, element item) {
	ListNode* p;
	p = list->head;

	while ((p != NULL)) {
		if (p->data == item)
			break;
		p = p->link;
	}

	if (p == NULL)return FALSE;
	else return TRUE;
}



int main() {

	LinkedListType list1;

	init(&list1);

	add(&list1, 0, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);

	//list1 = (10,20,30,40)
	display(&list1);

	//list1 = (10,20,30)
	delete(&list1, 3);
	display(&list1);

	//list1=(20,30)
	delete(&list1, 0);
	display(&list1);

	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "성공" : "실패");
	printf("%d\n", get_entry(&list1, 0));

	return 0;
}