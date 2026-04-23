#include <stdio.h>
#include <stdbool.h>

#define LEFT_TO_RIGHT true
#define RIGHT_TO_LEFT false

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int getMobile(int a[], bool dir[], int n) {
    int mobile_prev = 0, mobile = 0;

    for (int i = 0; i < n; i++) {
        if (dir[i] == RIGHT_TO_LEFT && i != 0) {
            if (a[i] > a[i - 1] && a[i] > mobile_prev) {
                mobile = i + 1;
                mobile_prev = a[i];
            }
        }

        if (dir[i] == LEFT_TO_RIGHT && i != n - 1) {
            if (a[i] > a[i + 1] && a[i] > mobile_prev) {
                mobile = i + 1;
                mobile_prev = a[i];
            }
        }
    }
    return mobile;
}

void printPermutation(int n) {
    int a[n];
    bool dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        printf("%d ", a[i]);
        dir[i] = RIGHT_TO_LEFT;
    }
    printf("\n");

    int mobile;

    while ((mobile = getMobile(a, dir, n)) != 0) {
        int pos = -1;


        for (int i = 0; i < n; i++) {
            if (a[i] == mobile) {
                pos = i;
                break;
            }
        }


        if (dir[pos] == RIGHT_TO_LEFT) {
            swap(&a[pos], &a[pos - 1]);
            bool temp = dir[pos];
            dir[pos] = dir[pos - 1];
            dir[pos - 1] = temp;
            pos = pos - 1;
        } else {
            swap(&a[pos], &a[pos + 1]);
            bool temp = dir[pos];
            dir[pos] = dir[pos + 1];
            dir[pos + 1] = temp;
            pos = pos + 1;
        }


        for (int i = 0; i < n; i++) {
            if (a[i] > mobile) {
                dir[i] = !dir[i];
            }
        }


        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printPermutation(n);

    return 0;
}
