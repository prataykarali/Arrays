#include <stdio.h>
#define MAX 100

void nge(int a[], int n, int b[]) {
    int st[MAX], t=-1;
    for(int i=0;i<n;i++){
        while(t!=-1 && a[i]>a[st[t]]) b[st[t--]]=a[i];
        st[++t]=i;
    }
    while(t!=-1) b[st[t--]]=-1;
}

int main() {
    int a[]={4,5,2,25}, n=4, b[4];
    nge(a,n,b);
    for(int i=0;i<n;i++) printf("%d ",b[i]);
    printf("\n");
    return 0;
}
