#include<stdio.h>
void main(){
int a1=0,a2=0,a3=0,i,j,temp,t=0;
printf("Enter the size of array 1: ");
scanf("%d",&a1);
printf("Enter the size of array 2: ");
scanf("%d",&a2);
a3=a1+a2;
int arr1[a1],arr2[a2],arr3[a3];

printf("Enter the elements of array 1: \n");
for(i=0;i<a1;i++){
	scanf("%d",&arr1[i]);
}

printf("Enter the elements of array 2: \n");
for(i=0;i<a2;i++){
	scanf("%d",&arr2[i]);
}
for(i=0;i<a1;i++){
	arr3[i]=arr1[i];
	t++;
}
for(i=0,j=t;i<a2 && j<a3;i++,j++){
	arr3[j]=arr2[i];
}
for(i=0;i<a3;i++){
	for(j=i+1;j<a3;j++){
		if(arr3[i]>arr3[j]){
			temp=arr3[i];
			arr3[i]=arr3[j];
			arr3[j]=temp;
		}
	}
}
printf("Display sorted and merged array \n");
for(i=0;i<a3;i++){
	printf("%d\t",arr3[i]);
}
}