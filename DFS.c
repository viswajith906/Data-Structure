#include<stdio.h>
#include<stdlib.h>
#define size 3
int adjmtx[size][size],dfsstack[size],visited[size],s;
int top=-1,data,v,i,j;
int push(int v){
    if(top==(size-1)){
        printf("Stack is full");
        exit(1);
    }
    top++;
    dfsstack[top]=v;
}
int pop(){
    if(top==-1){
        printf("Stack is empty");
        exit(1);
    }
    data=dfsstack[top];
    top--;
    return data;
}
int dfs(int s){
    push(s);
    visited[s]=1;
    printf("\n DFS order of stack is :");
    while(top != -1){
        v=pop();
        printf("%d",v);
        for(i=0;i<size;i++){
            if(adjmtx[v][i]==1){
                if(visited[i] != 1){
                    push(i);
                    visited[i]=1;
                }
            }
        }
    }
}
int main(){
    printf("Enter start vertex: ");
    scanf("%d",&s);
    printf("\n Enter adjmtx: \n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%d",&adjmtx[i][j]);
        }
    }
    dfs(s);
    
}