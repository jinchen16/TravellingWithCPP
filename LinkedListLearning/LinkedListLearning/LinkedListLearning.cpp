#include <iostream>

using namespace std;

struct numeric_item {
	int value;
	numeric_item* next;
};

numeric_item* head = nullptr;

void print() {
	for (numeric_item* p = head; p != nullptr; p = p->next) {
		cout << p->value << " ";
	}

	cout << endl;
}

void add(int v, numeric_item** pp) {
	numeric_item* newp = new numeric_item;
	newp->value = v;
	newp->next = *pp;
	*pp = newp;
}

numeric_item** find(int v, numeric_item** pp) {
	while ((*pp) != nullptr && (*pp)->value != v) {
		pp = &((*pp)->next);
	}
	return pp;
}

int main()
{
	for (int i = 1; i < 10; i += 2) {
		add(i, &head);
	}
	print();

	numeric_item** pp;
	pp = find(7, &head);
	add(8, pp);
	print();

	add(0, find(-1, &head));
	print();

	while (head != nullptr) {
		numeric_item* p = head;
		head = head->next;
		cout << "deleting " << p->value << endl;
		delete p;
	}

	return 0;
}