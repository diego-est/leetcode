#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <typename T>
using ptr = T*;
#include <memory>
using namespace std;

auto normalize(ptr<ListNode> p, int init) -> ptr<ListNode>
{
	if (p) {
		auto x = p->val;
		if (x + init > 9) {
			p->val = (x + init) % 10;
			p->next = normalize (p->next, (x + init) / 10);
		} else {
			p->val += init;
			p->next = normalize (p->next, 0);
		}
		return p;
	} else if (init == 0) {
		return nullptr;
	} else {
		return new ListNode(init);
	}
}

auto helper (ptr<ListNode> l1, ptr<ListNode> l2, int carry) -> ptr<ListNode>
{
	if (l1 && l2) {
		auto x = l1->val;
		l1->val = (x + l2->val + carry) % 10;
		l1->next = helper(l1->next, l2->next, (x + l2->val + carry) / 10);
		return l1;
	} else if (l1) {
		return normalize(l1, carry);
	} else if (l2) {
		return normalize(l2, carry);
	} else {
		if (carry > 0)
			return new ListNode(carry);
		else
			return nullptr;
	}
}

	auto addTwoNumbers(ListNode* l1, ListNode* l2) -> ptr<ListNode>
	{
		return helper(l1, l2, 0);
	}

auto print(ptr<ListNode> p) -> void
{
	if (p) {
		std::cout << ' ' << p->val << std::endl;
		print(p->next);
	}
}

auto main() -> int
{
	auto l11 = new ListNode(2);
	l11->next = new ListNode(4);
	l11->next->next = new ListNode(3);
	print(l11);
	std::cout << std::endl;
	auto l12 = new ListNode(5);
	l12->next = new ListNode (6);
	l12->next->next = new ListNode (4);
	print(l12);
	std::cout << std::endl;

	auto count = 7;
	auto l21 = new ListNode (9);
	auto p1 = l21;
	while (--count) {
		p1->next = new ListNode(9);
		p1 = p1->next;
	}
	print(l21);
	std::cout << std::endl;

	auto l22 = new ListNode (9);
	p1 = l22;
	count = 4;
	while (--count) {
		p1->next = new ListNode(9);
		p1 = p1->next;
	}
	print(l22);
	std::cout << std::endl;

	auto l31 = new ListNode(9);
	auto l32 = new ListNode(1);
	print (l31);
	std::cout << std::endl;
	print (l32);
	std::cout << std::endl;

	print (addTwoNumbers(l11, l12));
	std::cout << std::endl;
	print (addTwoNumbers(l21, l22));
	std::cout << std::endl;
	print(addTwoNumbers(l31,l32));
	std::cout << std::endl;
	return 0;
}

