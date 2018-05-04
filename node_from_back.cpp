#include <iostream>

struct node_t {
	node_t * next;
	int value;
};

node_t * node_from_back(node_t * head, unsigned int idx) {
	if (!head) {
		return nullptr;
	}

	unsigned int count = 1;
	node_t * curr = head;

	while (curr->next) {
		curr = curr->next;
		++count;
	}

	curr = head;

	if (count - idx > 0) {
		count = count - idx;
		while (count > 1) {
			curr = curr->next;
			--count;
		}
	}
	else {
		throw std::out_of_range("big idx");
	}
	return curr;
}

bool has_cycle(node_t * head) {
	if (!head) {
		throw std::logic_error("empty head");
	}
	node_t * curr = head;
	node_t * son = head;
	while (curr->next) {
		son = curr;
		while (son->next) {
			
			if (son->next == curr) {
				return true;
			}
			
			son = son->next;
		}
		curr = curr->next;
	}
	return false;
}

int main()
{
	node_t * root = new node_t;
	root->next = nullptr;
	root->value = 1;
	node_t * a = node_from_back(root, 0);
	std::cout << a->value;

	std::cin.get();
    return 0;
}
