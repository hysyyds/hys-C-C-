#include<iostream>
template<class T>
class queue {
	T* data;
public:
	int head, tail,capcity,block,movetarget;
	queue();
	void Push_Back(T a);
	void Show();
	void QCl();
	void ExitQueue();
	T& operator[](int tar)const;
};
//��ʼ������
template<class T>
queue<T>::queue() {
	this->head = 0; this->tail = 0;
	this->block = 1;
	this->data = new T[block];
	this->capcity = block;
	this->movetarget = 0;
}
//���
template<class T>
void queue<T>::Push_Back(T a){
	if (tail+movetarget>=capcity) {
		capcity += block;
		T* temp = new T[capcity];
		int i,j=0;
		for (i = head; i < tail; i++) {
			temp[j++] = data[i+ movetarget];
		}
		movetarget -= head;
		delete[]data;
		data = temp;
		data[tail++ + movetarget] = a;
	}
	else {
		data[tail++ + movetarget] = a;
	}
}
//չʾ��������
template<class T>
void queue<T>::Show() {
	int i;
	for (i = head; i < tail; i++) {
		std::cout << this->data[i+movetarget] << " ";
	}
}
//������������
template<class T>
void queue<T>::QCl() {
	delete[]data;
	head = 0;
	tail = 0;
	capcity = 0;
	movetarget = 0;
	block = 0;
}
//����
template <class T>
void queue<T>::ExitQueue() {
	if (head < tail) {
		head++;
	}
	else std::cout << "�����ѳ���";
}
//[]���ش��������һ��
template<class T>
T& queue<T>::operator[](int tar)const {
	if (tar >= head && tar < tail) {
		return data[tar + movetarget];
	}
	else {
		std::cout << "Error using of []"<<std::endl;
		return data[head+movetarget];
	}
}
int main(int argc, char** argv) {
	queue<int> q1;
	q1.Push_Back(1);
	q1.ExitQueue();
	q1.Show();
	q1.Push_Back(2);
	q1.Push_Back(3);
	q1.Show();
	std::cout << std::endl << q1[0] << q1[2];
	q1.QCl();
	return 0;
}