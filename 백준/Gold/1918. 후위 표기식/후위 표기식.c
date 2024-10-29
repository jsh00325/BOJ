#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char stack[100];
int head;

int priority(char o) {
	if (o == '(' || o == ')') return 0;
	else if (o == '*' || o == '/') return 1;
	else if (o == '+' || o == '-') return 2;
	else return -1;
}
void push(char o) { stack[head++] = o; }
char pop() { return stack[--head]; }
char top() { return stack[head - 1]; }
bool empty() { return head == 0; }

int main() {
	char str[101]; scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (priority(str[i]) == -1) printf("%c", str[i]);
		else if (str[i] == '(') push(str[i]);
		else if (str[i] == ')') {
			while (top() != '(') {
				printf("%c", pop());
			}
			pop();
		}
		else {
			if (empty() || top() == '(') push(str[i]);
			else if (priority(top()) > priority(str[i])) push(str[i]);
			else {
				while (!empty() && top() != '(') {
					if (priority(top()) <= priority(str[i])) printf("%c", pop());
					else break;
				}
				push(str[i]);
			}
		}
	}
	while (!empty()) {
		printf("%c", pop());
	}
}