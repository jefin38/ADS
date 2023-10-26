

#include <stdio.h>
void main()
{
int a[10], i, key,n;
printf("Enter array limit :");
scanf("%d",&n);
printf("Enter elements: ");
for (i=0; i<n; i++)
scanf("%d", &a[i]);
printf("Enter key to search: ");
scanf("%d", &key);
for (i=0; i<=9; i++)
if (key == a[i])
{
printf("element  found at location %d", i+1);
break;
}
if (i > 9)
printf("element not found.");
}
