#include<stdio.h>

int main()
{
int ch;
    printf("enter the value");
    scanf("%d", & ch) ;
    if(ch== 'a' || ch== 'e' || ch== 'i' || ch== 'o' || ch== 'u') {
    printf("vowel \n");
    }else{
    printf("cosonet");
    }
    
    return 0;
}