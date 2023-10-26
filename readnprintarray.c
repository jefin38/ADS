#include<stdio.h>
void main()
{
int i,n, a[10];
printf("Enter the limit:");
scanf("%d",&n);
printf("enter the numbers");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("The array is:\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}
