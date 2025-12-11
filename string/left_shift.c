#include<stdio.h>
#include<string.h>
#define SLEN 105

void reverse(char arr[],int start,int end){
    while (start<end){
        char ch=arr[start];
        arr[start]=arr[end];
        arr[end]=ch;
        start++;
        end--;
    }
}
// 3 steps reverse algorithm: 
//arr=[A][B], [A_r]=reverse([A]), [B_r]=reverse([B])
//[B][A]=reverse([A_r][B_r])
void left_shift(char *arr,int n){
    int len=strlen(arr);
    if (n>len) n%=len;
    else if (n==len) return;
    reverse(arr,0,n-1);             //reverse A
    reverse(arr,n,len-1);           //reverse B
    reverse(arr,0,len-1);           //reverse A
}

int main()
{
    char arr[SLEN];
    int n;
    fgets(arr,SLEN,stdin);
    scanf("%d",&n);
    arr[strcspn(arr,"\n")]='\0';
    left_shift(arr,n);
    puts(arr);
    return 0;
}
