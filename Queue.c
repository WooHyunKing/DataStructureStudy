#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
#define MAX_STRING 100

typedef struct { // �л� ����ü ����
    int student_number;
    char student_name[MAX_STRING];
    char student_address[MAX_STRING];
}student;

typedef struct {
    int front;
    int rear;
    student data[MAX_QUEUE_SIZE];
} Queue;

void init_queue(Queue* q) {
    q->front = q->rear = -1;
}

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int is_full(Queue* q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int is_empty(Queue* q) {
    return q->rear == q->front; // ������� 
}

void enqueue(Queue* q, student object) {
    if (is_full(q)) {
        error("OVERFLOW");
        return;
    }
    q->data[++q->rear] = object;  //rear���� ������Ų �� ��ȯ
}

student dequeue(Queue* q) {
    if (is_empty(q)) {
        error("UNDERFLOW");
    }
    return q->data[++q->front]; //front���� ������Ų �� ��ȯ
}

student peek(Queue* q) {
    if (is_empty(q)) {
        error("UNDERFLOW");
    }
    int index = q->front + 1; // front���� ��ȭ��Ű�� �ʱ� ���� ���� ���� ����
    return q->data[index];
}


int main() {

    student object = { 201820734,"King","Dongtan" };

    Queue q;

    init_queue(&q);

    enqueue(&q, object);

    student s = dequeue(&q);

    printf("student number:%d\n", s.student_number);
    printf("student name:%s\n", s.student_name);
    printf("student address:%s\n", s.student_address);

}