#include <iostream>
using namespace std;


class Queue
{
	int* arr;
	int size = 0;

public:
	Queue& operator << (int n);
	Queue& operator >> (int& n);
	bool operator !();
};


Queue& Queue::operator << (int n) {
	if (this->size == 0)		//���� ���ʷ� << �� ��, �������� �迭 �Ҵ�
		this->arr = new int[10];

	else if (this->size % 10 == 0)		//size�� 10�� ����� �� ���� �迭 ũ�� 10���� �÷���
	{
		int* temp = new int[this->size];		//arr�� �ӽ� �迭�� temp�� �Ű��� ��,
		for (int i = 0; i < this->size; i++)
			temp[i] = this->arr[i];

		delete[] this->arr;		// ������ �޸𸮸� �����ְ�
		this->arr = new int[this->size + 10];			//���ο� �迭�� �����ϰ�, ��Ҹ� �����Ѵ�.


		for (int i = 0; i < this->size; i++)
			this->arr[i] = temp[i];

		delete[] temp;			// temp�� �޸𸮸� �ٽ� �����ϰ�, 
	}
	this->arr[this->size] = n;		//n�� ��ҷ� �߰���s��.
	this->size++;

	return *this;
}


Queue& Queue::operator >>(int& n) {

	int* temp = new int[this->size];
	n = this->arr[0];
	for (int i = 1; i < this->size; i++)
		temp[i - 1] = this->arr[i];

	delete[] this->arr;
	this->size--;
	this->arr = new int[this->size];

	for (int i = 0; i < this->size; i++)
		this->arr[i] = temp[i];

	delete[] temp;
	return *this;
}


bool Queue::operator!() {
	if (this->size != 0)
		return false;

	else
		return true;
}


void main() {
	Queue queue;
	queue << 3 << 5 << 10;
	while (true) {
		if (!queue)
			break;

		int x;
		queue >> x;
		cout << x << ' ';
	}

	cout << endl;
}