#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;


typedef struct _Node{
	int data;
	struct _Node *next;
}Node;


Node* creatList(int n)
{
	Node* head = (Node*)malloc(sizeof(Node));
	Node* ptr = head;
	int num;
	cin >> num;
	head -> data = num;
		for(int i = 0; i < n-1; i++)
		{
			Node* newnode = (Node*)malloc(sizeof(Node));
			cin >> num;
			newnode -> data = num;
			newnode -> next = NULL;
			head -> next = newnode;
			head = newnode; 
		}
	return ptr;
}

Node* reverse(int n, Node* ptr)
{
	Node* now = ptr;
	now = now -> next;
	ptr -> next = NULL;
	Node* follow = now -> next; 
		for(int i = 0; i < n-2; i++)
		{		
			now -> next = ptr;
			ptr = now;
			now = follow;
			follow = follow -> next;	
		}
	
	
	now -> next = ptr;
	return now;
}


void printList(int n, Node* head)
{
	Node* now = head;
	Node* freenode;
	if(n > 1)
	{
		for(int i = 0; i < n; i++)
		{
			cout << now->data << " ";
			freenode = now;
			now = now -> next;
			free(freenode);
		}
	}

	//printf("\n");
	//free(head);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int M, N, K;
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> N >> K;
		
		for(int j = 0; j < N/K; j++)
		{
			if(K > 1)
			{
				Node* head = creatList(K);
				head = reverse(K, head);
				printList(K, head);
			}
			else
			{
				int num;
				cin >> num;
				cout << num << " ";
			}
			
		}
		//if(K == 1) printf("\n");
		//printf("here\n");
		if(N % K != 0)
		{
			for(int j = 0; j < N-K*(N/K); j++)
			{
				int numleft;
				cin >> numleft;
				cout << numleft << " ";
			} 
		}	
		//printf(" %d", i);	
		//cout << "here";
		cout << endl;
	}
	
}
