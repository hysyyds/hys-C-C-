#include<stdio.h>
#include<string.h>
#include<stdlib.h>

size_t mylen(char const* p) {//不知道有没有指针版本
    int idx=0;
    while (p[idx] != '\0') {
        idx++;
    }
    return idx;
}
int mycmp(char const* p1, char const* p2) {
    while (*p1==*p2&& *p1!='\0') {
        p1++;
        p2++;
    }
    return(*p1-*p2);
}
char* mycpy(char* p1, char const* p2) {
    char* ret;
    ret = p1;
    while (*p2) {
        *p1++ = *p2++;
    }
    *p1 = '\0';//容易忘
    return ret;
}
char* mycat(char* p1, char const* p2) {
    char* ret;
    ret = p1;
    p1 = &p1[strlen(p1)];
    while (*p2) {
        *p1++ = *p2++;
    }
    *p1 = '\0';
    return ret;
}
int main()
{
    char a[50] = "hello,";
    char b[] = "world";
    printf("%s", mycat(a, b));
    return 0;
}