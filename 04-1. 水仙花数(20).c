#include<stdio.h>

int main() {
	int x;//输入位数
	int temp_number1,temp_number2=1;//记录每位数的方次幂
	int sum=0;//记录方次幂之和
	int count=0,number=1,temp_number_;//计数器
	int temp_number;//记录最小的n位数
	scanf_s("%d", &x);
	//构造最小n位数
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

