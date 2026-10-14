#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int osish_bo_yicha(int a, int b) {
    return a - b;
}

int kamayish_bo_yicha(int a, int b) {
    return b - a;
}

int modul_bo_yicha(int a, int b) {
    return abs(a) - abs(b);
}

void saralash(int *arr, int n, int (*cmp)(int, int)) {
    if (arr == NULL || cmp == NULL) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cmp(*(arr + j), *(arr + j + 1)) > 0) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void chop_etish(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main(void) {
    int n;
    printf("Massiv o'lchamini kiriting: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Xatolik: Massiv o'lchami musbat son bo'lishi kerak!\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Xatolik: Xotira ajratishda xatolik yuz berdi!\n");
        return 1;
    }

    printf("%d ta elementni kiriting:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
            printf("Xatolik: Noto'g'ri qiymat kiritildi!\n");
            free(arr);
            return 1;
        }
    }

    printf("\nBoshlang'ich massiv: ");
    chop_etish(arr, n);

    saralash(arr, n, osish_bo_yicha);
    printf("O'sish bo'yicha saralangan: ");
    chop_etish(arr, n);

    saralash(arr, n, kamayish_bo_yicha);
    printf("Kamayish bo'yicha saralangan: ");
    chop_etish(arr, n);

    saralash(arr, n, modul_bo_yicha);
    printf("Modul bo'yicha saralangan: ");
    chop_etish(arr, n);

    free(arr);
    arr = NULL;

    return 0;
}
