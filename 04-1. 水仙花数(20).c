#include<stdio.h>

int main() {
	int x;//����λ��
	int temp_number1,temp_number2=1;//��¼ÿλ���ķ�����
	int sum=0;//��¼������֮��
	int count=0,number=1,temp_number_;//������
	int temp_number;//��¼��С��nλ��
	scanf_s("%d", &x);
	//������Сnλ��
	while (count +1!= x ) {
		number *= 10;
			count++;
	}
	//
	count = 0;
	temp_number = number;
	temp_number_ = number;
	while (temp_number_ / 10 != temp_number) {
		number = temp_number_;
		while (number != 0) {
			
			temp_number1 = number % 10;
			do {
				temp_number2 *= temp_number1;
				count++;
			} while (count != x);
			number /= 10;
			count = 0;
			sum += temp_number2;
			temp_number2 = 1;
		}
		if (sum == temp_number_) {
			printf("%d\n", temp_number_);
		}
		sum = 0;
		temp_number_++;
	}
	return 0;
}

