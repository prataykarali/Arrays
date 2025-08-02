#include<stdio.h>
main(){
int r,c,i,j;
printf("Enter row and col");
scanf("%d%d",&r,&c);
int a[r][c];
for(i=0;i<r;i++){
	for(j=0;j<c;j++){
		printf("Enter element");
		scanf("%d",&a[i][j]);
	}
}
int b[r][c];
for(j=0;j<c;j++){
	for(i=r-1;i>=0;i--){
		b[c-i-1][j]=a[j][i];
	}
}
for(i=0;i<r;i++){
	for(j=0;j<c;j++){
		printf("%d ",b[i][j]);
	}
	printf("\n");
}
}