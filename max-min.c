#include<stdio.h>
int main(){
	int i, n, max, min, pos, post, arr[100];
	min=arr[0];
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("\nArray [%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("\nPrinted Array: ");
	for(i=0; i<n; i++){
	printf("%d ", arr[i]);
}

for(i=0; i<n; i++){
	if(arr[i]>max){
		max=arr[i];
		pos=i;
	}
}
	printf("\nThe maximum element is %d at %d", max, pos);
	
	for(i=0; i<n; i++){
	if(arr[i]<min){
		min=arr[i];
		post=i;
	}
}
	printf("\nThe minimum element is %d at %d", min, post);
	return 0;
}
