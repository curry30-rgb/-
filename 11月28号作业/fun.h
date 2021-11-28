#pragma once
#include<iostream>
using namespace std;
#define MaxInt 0
#define MVNum 100
typedef char VerTexType;  //���������Ϊ�ַ���
typedef int ArcType;  //Ȩֵ����Ϊint��

typedef struct {
	int base[100];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue &Q) {
	Q.front = 0;
	Q.rear = 0;
}

void EnQueue(SqQueue& Q,int e) {
	Q.base[Q.rear] = e;
	Q.rear += 1;
}

int DeQueue(SqQueue& Q) {
	int e;
	e = Q.base[Q.front];
	Q.front += 1;
	return e;
}

void TravelQueue(SqQueue Q) {
	for (int i =Q.front; i < Q.rear; i++) {
		cout << Q.base[i] << " ";
	}
}

bool QueueEmpty(SqQueue Q) {
	if (Q.front = Q.rear) {
		return false;
	}
	else {
		return true;
	}
}

typedef struct {
	VerTexType vexs[MVNum]; //��������
	ArcType arcs[MVNum][MVNum]; //�ڽӾ���
	int vexnum, arcnum;
}AMGraph;

int LocateVex(AMGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return -1;
}

void CreateUDN(AMGraph& G) {
	cout << "���붥�����ͱ�����";
	cin >> G.vexnum >> G.arcnum;

	cout << "�������붥���ַ���";
	for (int i = 0; i < G.vexnum; i++) {//����vexs�������ݣ�������������ַ�
		cin >> G.vexs[i];
	}

	for (int i = 0; i < G.vexnum; i++) {//�Ȱ�arcs�����ʼ��Ϊ���ֵ
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}

	cout << "����һ���������Ķ����Ȩֵ��" << endl;
	for (int k = 0; k < G.arcnum; k++) {//�����ڽӾ���
		VerTexType v1, v2;
		
		cin >> v1 >> v2;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = G.arcs[i][j];
	}
}

void TraveralAMGraph(AMGraph G) {
	cout << "����ڽӾ���ĸ��и��У�" << endl;
	cout << '\t';
	for (int i = 0; i < G.vexnum; i++) {
		cout << '\t' << G.vexs[i];
	}
	cout << endl << endl << endl << endl;

	for (int i = 0; i < G.vexnum; i++) {
		cout << '\t' << G.vexs[i];
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j] != 0) {
				cout << '\t' << G.arcs[i][j];
			}
			else {
				cout << '\t' << "0";
			}
		}
		cout << endl << endl << endl << endl;
	}
}
bool visited1[MVNum];
void DFS_AM(AMGraph G, int v) {//�ӵ�v�������������
	cout << G.vexs[v] << " ";
	visited1[v] = true;
	for (int w = 0; w < G.vexnum; w++) {
		if ((G.arcs[v][w] != 0) && (!visited1[w])) {
			DFS_AM(G, w);
		}
	}
}

int NextAdjVex(AMGraph G, int v, int w) {//����v�����w����һ���ڽӵ�
	for (int i = w; i < G.vexnum; i++) {
		if ((G.arcs[v][i] != 0) && (visited1[i] == false)) {
			return i;
		}
	}
	return -1;
}

int visited2[100];
void BFsTraverse(AMGraph G){
	SqQueue q;
	InitQueue(q);

	EnQueue(q, 0);
	visited2[0] = true;

	
	int v, n = 0, i = 0;
	while (q.rear - q.front != G.vexnum) {
		for (int j = 0; j < G.vexnum; j++) {
			if ((G.arcs[i][j] != 0) && (visited2[j] == false)) {
				/*v = DeQueue(q);
				cout << G.vexs[v] << " ";*/
				EnQueue(q, j);
				visited2[j] = true;
			}
		}
		i=q.base[n];
		n++;
	}


	for (int i = q.front; i < q.rear; i++) {
		cout << G.vexs[q.base[i]] << " ";
	}
}