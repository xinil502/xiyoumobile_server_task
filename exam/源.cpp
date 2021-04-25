#include "List.h"
#include "Stack.h"
#include "queue.h"


//∂”¡–
/*
int main() {
	Queue mq;
	init(&mq);
	int val;
	while (scanf_s("%d", &val), val != -1) {
		push(&mq, val);
	}
	show(&mq);
	for (int i = 0; i < 3; ++i) {
		pop(&mq);
	}
	show(&mq);
	shortest();
	return 0;
}
*/




//’ª
/*
int main() {
	Stack s;
	Stack m;
	init(&s);
	init(&m);
	int input;
	while (scanf_s("%d", &input), input != -1) {
		push(&s, &m, input);
	}
	for (int i = 0; i < 3; ++i) {
		show(&s);
		pop(&s, &m);
		getMin(&m);
	}
}
*/




//¡¥±Ì
/*
void main() {
	List list;
	init(&list);
	lastAdd(&list);
	show(&list);
	list = ff(&list, 3);
	show(&list);
}
*/