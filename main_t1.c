#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1024

char *eng_uzun(char *s, int *uzunlik) {
    if (s == NULL || uzunlik == NULL) return NULL;

    char *best_start = NULL;
    int max_len = 0;
    char *curr_start = NULL;
    int curr_len = 0;

    while (*s != '\0') {
        if (!isspace((unsigned char)*s)) {
            if (curr_len == 0) {
                curr_start = s;
            }
            curr_len++;
        } else {
            if (curr_len > max_len) {
                max_len = curr_len;
                best_start = curr_start;
            }
            curr_len = 0;
        }
        s++;
    }

    if (curr_len > max_len) {
        max_len = curr_len;
        best_start = curr_start;
    }

    *uzunlik = max_len;
    return best_start;
}

int sozlarni_sanash(const char *s) {
    int count = 0;
    int in_word = 0;

    while (*s) {
        if (!isspace((unsigned char)*s)) {
            if (!in_word) {
                in_word = 1;
                count++;
            }
        } else {
            in_word = 0;
        }
        s++;
    }
    return count;
}

int main(void) {
    char matn[MAX_LEN];

    printf("Satrni kiriting: ");
    if (fgets(matn, sizeof(matn), stdin) == NULL) {
        printf("Xatolik: Ma'lumot kiritilmadi!\n");
        return 1;
    }

    size_t len = strlen(matn);
    if (len > 0 && matn[len - 1] == '\n') {
        matn[len - 1] = '\0';
    }

    if (strlen(matn) == 0) {
        printf("Xatolik: Satr bo'sh bo'lishi mumkin emas!\n");
        return 1;
    }

    int sozlar_soni = sozlarni_sanash(matn);
    int max_uzunlik = 0;
    char *p_eng_uzun = eng_uzun(matn, &max_uzunlik);

    printf("\n--- NATIJALAR ---\n");
    printf("Satrdagi so'zlar soni: %d\n", sozlar_soni);

    if (p_eng_uzun != NULL && max_uzunlik > 0) {
        printf("Eng uzun so'z: %.*s\n", max_uzunlik, p_eng_uzun);
        printf("Eng uzun so'z uzunligi: %d\n", max_uzunlik);
        printf("Eng uzun so'z boshlangan xotira manzili: %p\n", (void*)p_eng_uzun);
    } else {
        printf("So'zlar topilmadi.\n");
    }

    return 0;
}
