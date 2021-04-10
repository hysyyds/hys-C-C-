#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
	int value;
	struct _Node* next;
} Node;
typedef struct _List {
	Node* head;
	Node* tail;
} List;
Node* AddList(List* PList, int value);
void ShowList(List* PList);
void DeleteListOne(List* PList, int value);
void DeleteAllList(List* PList);
Node* AddList(List* PList, int value) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->value = value;
	p->next = NULL;
	if (PList->tail) PList->tail->next=p;
	else PList->head = p;
	PList->tail = p;
	return p;
}
void ShowList(List* PList) {
	Node* p;
	for (p = PList->head; p; p = p->next) {
		printf("%d", p->value);
	}
}
void DeleteListOne(List* PList, int value) {
	Node* former, * later;
	for (later = PList->head, former = NULL; later; former = later, later = later->next) {
		if (later->value == value) {
			if (former) {
			former->next = later->next;
				if (later->next) {
				PList->tail = former;
				}
			}
			else {
			PList->head = later->next;
			}
			free(later);
			break;
		}
	}
}
void DeleteAllList(List* PList) {
	Node* p, * q;
	for (p = PList->head; p; p = q) {
		q = p->next;
		free(p);
	}
	PList->head = NULL;
	PList->tail = NULL;
}
int main(int argc, char** argv) {
	List list;
	list.head = NULL;
	list.tail = NULL;
	AddList(&list, 5);
	AddList(&list, 6);
	ShowList(&list);
	DeleteAllList(&list);
	return 0;
}