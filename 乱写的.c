#include<stdio.h>
#include<math.h>

int main(int argc, char** argv) {
	int data1, data2;
	int signal = 0;
	char op;
	double result;
	scanf("%d%c%d%lf",&data1, &op,&data2,&result);
	switch (op)
	{case '+':
		if (fabs(data1 + data2 - result) < 1e-6) {
			signal = 1;
		}break;
	case '-':if (fabs(data1 - data2 - result) < 1e-7) {
		signal = 1;
	}break;
	case '*':if (fabs(data1 * data2 - result) < 1e-7) {
		signal = 1;
	}break;
	case '/':if (fabs(1.0*data1 / data2 - result) < 1e-7) {
		signal = 1;
	}break;
	default:
		break;
	}
	if (signal) {
		printf("perfect!!!");
	}
	else printf("error");
	return 0;
}