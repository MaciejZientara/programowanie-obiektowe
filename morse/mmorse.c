#include <stdio.h>
#include <stdlib.h>
#include "morse.h"

int main(){
    init();
    int t;
    printf("szyfrowanie - 0, odszyfrowanie - 1\n");
    scanf("%d",&t);
    if(t==0){
        char x;
        while((x=getchar())!=EOF){
            if(x=='\n'){
                printf("\n");
                continue;
            }
            if(x-'a'>=0 && x-'z'<=0)
                printf("%s ",szyfr[x-'a']);
            else
                if(x-'0'>=0 && x-'9'<=0)
                    printf("%s ",szyfr[x-'0'+26]);
                else
                    printf("& ");
        }
    }
    if(t==1){
        struct trie *g=T;
        char x;
        while((x=getchar())){
            //printf("x=%c\n",x);
            if(x==EOF)
                return 0;
            if(x==' ' || x=='\n'){
                if(g->l!=0){
                    printf("%c",g->l);
                    g=T;
                }
            }
            if(x=='.'){
                if(g->dot!=NULL)
                    g=g->dot;
                else{
                    printf("error\n");
                    break;
                }
            }
            if(x=='-'){
                if(g->line!=NULL)
                    g=g->line;
                else{
                    printf("error\n");
                    break;
                }
            }
        }
    }
}
