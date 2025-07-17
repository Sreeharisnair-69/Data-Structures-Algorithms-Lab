/*
Name: Sreehari Sreekumar Nair
Date: July 17, 2025
Purpose: Perform polynomial addition
*/


#include <stdio.h>
int main(){
  int size1, size2,max;
  printf("Enter the degree of first polynomial: ");
  scanf("%d",&size1);
  printf("Enter the degree of second polynomial: ");
  scanf("%d",&size2);
  
  if(size1>size2){
    max=size1;
  }
  else{
    max=size2;
  }
  
  int poly1[size1],poly2[size2];
  printf("Enter coefficients of first polynomial: \n");
  for(int i=0;i<=size1;i++){
    printf("Coefficient of x^%d: ",i);
    scanf("%d",&poly1[i]);
  }
  
  printf("\nEnter coefficients of second polynomial: \n");
  for(int i=0;i<=size2;i++){
    printf("Coefficient of x^%d: ",i);
    scanf("%d",&poly2[i]);
  }
  
  char x = 'x';
  printf("First polynomial:");
  for(int i=size1;i>=0;i--){
    if(i!=0){
      printf("%d%c^%d + ",poly1[i],x,i);
    }
    else{
      printf("%d%c^%d",poly1[i],x,i);
    }
  }
  printf("\n");
  
  printf("Second polynomial:");
  for(int i=size2;i>=0;i--){
    if(i!=0){
      printf("%d%c^%d + ",poly2[i],x,i);
    }
    else{
      printf("%d%c^%d",poly2[i],x,i);
  }
  }
  printf("\n");
  
  int poly3[max];
   for(int i=0;i<=max;i++){
    poly3[i]=poly1[i]+poly2[i];
  }
  
  printf("Resulting polynomial:");
  for(int i=max;i>=0;i--){
    if(i!=0){
      printf("%d%c^%d + ",poly3[i],x,i);
    }
    else{
      printf("%d%c^%d",poly3[i],x,i);
    }
  }
  printf("\n");
}
