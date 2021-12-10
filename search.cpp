#include<iostream>
using namespace std;
typedef int KeyType;
#define SIZE_MAX 100

typedef struct {
	KeyType key;
}ElemType;

typedef struct {
	ElemType R[SIZE_MAX]; 
	int length;
}SSTable;

void Initkey(SSTable &ST) {//��ʼ��
	int n;
	cout << "������Ҫ���������ݣ�";
	cin >> n;
	cout << "����������";
	for (int i = 0; i < n; i++) {
		cin >> ST.R[i].key;
	}
	cout << "��ʼ���ɹ�" << endl;
	ST.length = n;
}

int Search_Bin(SSTable ST,KeyType key) {//�ǵݹ�
	int low = 0;
	int mid;
	int high = ST.length-1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == ST.R[mid].key) {
			return mid + 1;
		}
		else if (key < ST.R[mid].key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}	
	}
	if (low > high) {
		return -1;
	}
}

int BinarySearch(SSTable ST, KeyType key, int low, int high) {//�ݹ�
	int mid;
	if (low > high) {
		return -1;
	}
	else {
		mid = (low + high) / 2;
		if (key == ST.R[mid].key) {
			return mid + 1;
		}
		else if (key<ST.R[mid].key){
			return BinarySearch(ST, key, low, mid-1);
		}
		else {
			return BinarySearch(ST, key, mid + 1, high);
		}
	}
}

int main(){
	int key;
	SSTable st;
	Initkey(st);
	cout << "������Ҫ���ҵ����ݣ�";
	cin >> key;

	cout << "�ǵݹ飺" << endl;
	int index = Search_Bin(st, key);//�ǵݹ�
	if (index == -1) {
		cout << "����ʧ�ܣ�û�и�ֵ��" << endl;
	}
	else {
		cout << "�ڵ�" << index <<"λ" << endl;
	}
	
	/*cout << "�ݹ飺" << endl;
	int index = BinarySearch(st, key,0,st.length-1);//�ݹ�
	if (index == -1) {
		cout << "����ʧ�ܣ�û�и�ֵ��" << endl;
	}
	else {
		cout << "�ڵ�" << index << "λ" << endl;
	}
	*/
	return 0;
}