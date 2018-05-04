#include <iostream>

struct node_t {
	node_t * next;
	int value;
};

node_t * node_from_back(node_t * head, unsigned int idx) {
	if (head) {
		unsigned int count = 1;
		node_t * curr = head;

		while (curr->next) {
			curr = curr->next;
			++count;
		}
		curr = head;

		if (count - idx > 0) {
			unsigned int revers_idx = count - idx - 1;
			while (revers_idx) {
				curr = curr->next;
				--revers_idx;
			}
			return curr;
		}
		else {
			throw std::logic_error("big idx");
		}
	}
	return nullptr;
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
