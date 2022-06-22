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
	if (this->size == 0)		//만약 최초로 << 할 시, 동적으로 배열 할당
		this->arr = new int[10];

	else if (this->size % 10 == 0)		//size가 10의 배수일 때 마다 배열 크기 10개씩 늘려서
	{
		int* temp = new int[this->size];		//arr를 임시 배열인 temp에 옮겨준 후,
		for (int i = 0; i < this->size; i++)
			temp[i] = this->arr[i];

		delete[] this->arr;		// 기존에 메모리를 없애주고
		this->arr = new int[this->size + 10];			//새로운 배열을 생성하고, 요소를 복사한다.


		for (int i = 0; i < this->size; i++)
			this->arr[i] = temp[i];

		delete[] temp;			// temp의 메모리를 다시 삭제하고, 
	}
	this->arr[this->size] = n;		//n을 요소로 추가한s다.
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