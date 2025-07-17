#include <stdio.h>
int main(){
  int size1, size2;
  printf("Enter the sizes of first and second polynomials: ");
  scanf("%d %d",&size1,&size2);
  
  int poly1[size1],poly2[size2];
  printf("Enter coefficients of first polynomial: ");
  for(int i=0;i<size1;i++){
    scanf("%d ",&poly1[i]);
  }
  
  printf("Enter coefficients of second polynomial: ");
  for(int i=0;i<size2;i++){
    scanf("%d ",&poly2[i]);
  }
  
  int size3=size1+size2;
  int poly3[size3] = {0};
  for(int i=0;i<size1;i++){
    poly3[i]+=poly1[i];
  }
  
   for(int i=0;i<size2;i++){
    poly3[i]+=poly2[i];
  }
  
   for(int i=0;i<size2;i++){
    printf("%d ",poly3[i]);
  }
