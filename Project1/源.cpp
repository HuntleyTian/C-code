#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <limits.h>

int GetMid(int* a, int left, int right) {
    int mid = (left + right) / 2;
    if (a[mid] >= a[left]) {
        if (a[right] >= a[mid]) {
            return mid;
        }
        else {
            if (a[right] >= a[left]) {
                return right;
            }
            else {
                return left;
            }
        }
    }
    else {
        if (a[right] >= a[left]) {
            return left;
        }
        else {
            if (a[right] >= a[mid]) {
                return right;
            }
            else {
                return mid;
            }
        }
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Quicksort(int *a,int left,int right){
    if (left >= right) {
        return;
    }
    int index = GetMid(a,left, right);
    swap(&a[left], &a[index]);
    int key = left;
    int purv = left;
    int cur = left + 1;

    while (cur <= right) {
        if (a[cur] < a[key]) {
            purv++;
            swap(&a[cur], &a[purv]);
        }
        cur++;
    }
    swap(&a[purv], &a[key]);
    Quicksort(a, left, purv - 1);
    Quicksort(a, purv + 1, right);
}

int a[2000000];
int main() {
    
    int n,m;
    scanf("%d%d", &n,&m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    Quicksort(a, 0, m-1);
 
   

    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}