#include<stdio.h>
void main()
{
int i, sum=0, a[10];
printf("enter the numbers");
for(i=0;i<5;i++)
{
scanf("%d",&a[i]);
sum=sum+a[i];
}
printf("the sum is %d",sum);

}
