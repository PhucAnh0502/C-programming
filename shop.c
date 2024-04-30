#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct shop {
    char masanpham[10];
    int gia;
} shop;

typedef struct giohang {
    char ma[10];
    int soluong;
} giohang;

int main() {
    shop arr1[100];
    giohang arr2[100];
    char id[10];
    int count = 0;
    
    for (int i = 0; i < 100; i++) {
        scanf("%s", id);
        if (strcmp(id, "-1") == 0) {
            break;
        }
        scanf("%d", &arr1[i].gia);
        strcpy(arr1[i].masanpham, id);  
        count++;
    }
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", arr2[i].ma);
        scanf("%d", &arr2[i].soluong);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count; j++) {
            if (strcmp(arr1[j].masanpham, arr2[i].ma) == 0) {
                sum += arr1[j].gia * arr2[i].soluong; 
                break; 
            }
        }
    }    
    
    printf("%d", sum);
    
    return 0;
}
