#ifndef __TIMING_H__
#define __TIMING_H__
typedef struct time {
	int day, month, year;
}Stime;
Stime* gettime(Stime* p);//�û����뵱ǰʱ��dd-mm-yy
int daysofmonth(const Stime* p);//��ȡ��ǰ�·�����
int leapyear(const Stime* p);//�ж��Ƿ�Ϊ����
Stime* tomorrow(Stime* p);//����
#endif