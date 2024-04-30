#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menu(){
    system("cls");
    printf("Chon chuc nang: \n");
    printf("chuc nang 1: \n");
    printf("chuc nang 2: \n");
    printf("chuc nang 3: \n");
    int cn;
    scanf("%d", &cn);
    return cn;
}

void chuc_nang_1(){
    system("cls");
    int a,b;
    scanf("%d %d", &a,&b);
    printf("%d", a+b);
    getch();
}

int main(){
    while(1){
         int cn = menu();
         switch(cn){
        case 1:
            chuc_nang_1();
            break;
        case 2:
            exit(0);
         }
    }
}
