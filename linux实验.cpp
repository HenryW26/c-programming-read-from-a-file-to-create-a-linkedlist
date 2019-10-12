#include<stdio.h>
#include <malloc.h>

const char* path = "stu_Info.txt";


typedef struct stuInfo {
	char stuName[10];
	int Age;
}ElemType;

typedef struct node {
	ElemType data;
	struct node* next;
}ListNode, * ListPtr;

struct node* CreateList();
int PrintList(ListPtr head);
int InsertList(ListPtr head);


int main(int argc, char argv[]) {
	struct node* ListHead = NULL;

	while (1) {
		printf("1 Create List\n");
		printf("2 Printf List\n");
		printf("3 Insert List\n");
		printf("4 Quit\n");
		fflush(stdin);
		char command = getchar();
		fflush(stdin);
		switch (command) {
		case '1':ListHead = CreateList();
			break;
		case '2':PrintList(ListHead);
			break;
		case '3':InsertList(ListHead);
			break;
		case '4':return 0;
		}
	}
	return 0;
}
struct node* CreateList() {
	FILE* fp = fopen(path, "r");
	if (fp == NULL) {
		perror("fopen");
		return 0;
	}
	ListPtr head = (ListPtr)malloc(sizeof(ListNode));//创建头结点
	ListPtr newnode = NULL;
	ListPtr tail = NULL;
	tail = head;

	while (!feof(fp)) {
		newnode = (ListPtr)malloc(sizeof(ListNode));
		fscanf(fp, "%s\t%d", newnode->data.stuName, &newnode->data.Age);
		tail->next = newnode;
		tail = newnode;

	}
	tail->next = NULL;
	fclose(fp);
	return head;
}

int PrintList(ListPtr head) {
	ListPtr p = head->next;
	while (p != NULL) {
		printf("%s\t%d\n", p->data.stuName, p->data.Age);
		p = p->next;
	}
	return 0;
}

int InsertList(ListPtr head) {
	ListPtr newnode;
	ListPtr pre;
	pre = head;
	while (pre->next != NULL)
	{
		pre = pre->next;
	}
	newnode = (ListPtr)malloc(sizeof(ListNode));
	printf("Enter name and age:");
	scanf("%s%d", newnode->data.stuName, &newnode->data.Age);
	newnode->next = pre->next;
	pre->next = newnode;
	return 0;
}