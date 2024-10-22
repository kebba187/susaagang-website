#include <iostream>
#include namespace std;
int main()
{
    short int A=0xf9,B036,i=5;
    i+=A^B;
    for(int i=0; i<3;i++);
    i++;
    printf("%o \t %d\t%d",A^B,A,i);

}