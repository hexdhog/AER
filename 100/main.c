#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int tonum(char *digits, unsigned int len) {
    unsigned int i = 0, res = 0;
    for (i = 0; i < len; i++) res += digits[i] * pow(10, len-i-1);
    return res;
}

void todigits(unsigned int n, char *digits, unsigned int len) {
    unsigned int i = 0;
    for (i = 0; i < len; i++) {
        digits[i] = n % 10;
        n /= 10;
    }
}

void sort(char *arr, unsigned int len) {
    unsigned int i = 0;
    char tmp = 0;
    for (i = 0; i < len-1; i++) {
        unsigned int j = 0;
        for (j = 0; j < len-1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

unsigned int kaprekar(char *digits, unsigned int len) {
    sort(digits, len);
    unsigned int i = 0, high = 0, low = 0;
    for (i = 0; i < len; i++) {
        low += digits[i] * pow(10, len-i-1);
        high += digits[i] * pow(10, i);
    }
    return high - low;
}

bool repdigits(char *digits, unsigned int len) {
    unsigned int i = 0;
    for (i = 0; i < len-1; i++) if (digits[i] != digits[i+1]) return false;
    return true;
}

int main(int argc, char **argv) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nch = 0;

    if ((nch = getline(&line, &len, stdin)) < 0) return -1;
    unsigned int cnt = atoi(line), i = 0;

    for (i = 0; i < cnt; i++) {
        if ((nch = getline(&line, &len, stdin)) < 0) return -1;
        unsigned int l = nch - 1;
        char *digits = line;

        int j = 0;
        for (j = 0; j < l; j++) digits[j] -= '0';

        unsigned int num = 0, iter = 0;
        if (repdigits(digits, l)) {
            iter = 8;
        } else if (tonum(digits, l) != 6174) {
            iter = 1;
            while ((num = kaprekar(digits, l)) != 6174) {
                todigits(num, digits, l);
                iter++;
            }
        }
        printf("%d\n", iter);
    }

    return 0;
}
