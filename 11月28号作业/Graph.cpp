#include<iostream>
#include"fun.h"

int main() {

	AMGraph ag;
	CreateUDN(ag);

	TraveralAMGraph(ag);

	//BFsTraverse(ag);

	cout << "������ӵڼ������������";
	int index;
	cin >> index;
	DFS_AM(ag, index);

	return 0;
}