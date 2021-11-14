#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef struct BiTNode {
	char data;
	struct BiTNode* lch, * rch;
}BiTNode, *BiTree;

typedef struct {
	BiTNode* base;
	BiTNode* top;
	int stacksize;
}SqStack;

int InitStack(SqStack& S) {//��ʼ��ջ
	S.base = new BiTNode[MAXSIZE];
	if (!S.base) {
		return 0;
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return 1;
}

bool StackEmpty(SqStack S) {//�ж�ջ�Ƿ�Ϊ��
	if (S.top == S.base) {
		return true;
	}
	else {
		return false;
	}
}

void Push(SqStack& S,BiTNode &e) {//��ջ
	if (S.top - S.base == S.stacksize) {
		cout << "error" << endl;
	}
	*S.top++ = e;
}

void Pop(SqStack& S, BiTNode &e) {//��ջ
	if (S.top == S.base) {
		cout << "error" << endl;
	}
	e = *--S.top;
}

void CreateBiTree(BiTree& T) {//����������
	char ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lch);
		CreateBiTree(T->rch);
	}
}

void InOrderTraverse(BiTree T) {//�ݹ�ʵ���������������
	if (T) {
		InOrderTraverse(T->lch);
		cout << T->data;
		InOrderTraverse(T->rch);
	}
}


void InOrderTraverse2(BiTree T) {//ջʵ���������������
	SqStack S;
	InitStack(S);

	BiTree p = T;
	BiTNode q;
	while(p||!StackEmpty(S)){
		if (p) {
			Push(S,*p);
			p = p->lch;
		}
		else {
			Pop(S, q);
			cout << q.data;
			p = q.rch;
		}
	}
}


int Depth(BiTree T) {//��������������
	int m, n;
	if (T == NULL) {
		return 0;
	}
	else {
		m = Depth(T->lch);
		n = Depth(T->rch);
		if (m > n) {
			return m + 1;
		}
		else {
			return n + 1;
		}
	}
}

int NodeCount(BiTree T) {//���������
	if (T == NULL) {
		return 0;
	}
	else {
		return NodeCount(T->lch) + NodeCount(T->rch) + 1;
	}
}

int main() {
	BiTree bt=NULL;
	cout << "�������ַ���";
	CreateBiTree(bt);
	cout << "ջʵ�����������������";
	InOrderTraverse2(bt);

	cout << endl;
	cout << "�Ķ����������Ϊ��" ;
	int deph = Depth(bt);
	cout << deph << endl;

	cout << "�Ķ������Ľ�����Ϊ��" ;
	int count = NodeCount(bt);
	cout << count << endl;
	//ABC##DE#G##F###
}