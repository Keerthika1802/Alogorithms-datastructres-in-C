#include<stdio.h>
int gcd(int a,int b);
int q,r1,r2,r,a,b,result;
int main(){

printf("Enter a value:\n");
scanf("%d",&a);
printf("Enter b value:\n");
scanf("%d",&b);
if(a>b){
r1=a;
r2=b;
}
else{
r1=b;
r2=a;
}
result=gcd(r1,r2);
printf("the GCD of %d and %d is : %d\n",a,b,result);
}
int gcd(int r1,int r2){
while(r2>0){
q=r1/r2;
r=r1-q*r2;
r1=r2;
r2=r;
}
return r1;
}
