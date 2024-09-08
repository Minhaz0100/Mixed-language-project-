#include<stdio.h>
int main ()
{
int a[3] [3], i, j,sum=0;
for(i=0; i<3; i++)// for row
{
for(j=0; j<3; j++){//for colum
scanf ("%d",&a[i] [j]);
}
}
for(i=0; i<3; i++)
{
for(j=0; j<3; j++){
printf ("%d", a[i] [j]);
sum=sum+a[i][j];
}
printf ("\n");
}float avarage=sum/9.0;
printf ("avarage is: %f" ,avarage);
return 0;
}