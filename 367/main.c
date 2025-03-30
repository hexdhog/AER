#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (a < b ? b : a)
#define ARR_CNT_MAX 1000

int arr[ARR_CNT_MAX] = {};
int vis[ARR_CNT_MAX] = {};

int closest(int *arr, int *vis, int n, int p) {
    int i = 0;
    int l = ARR_CNT_MAX, idx = ARR_CNT_MAX;
    for (i = 0; i < n; i++) {
        if (vis[i] == 1) continue;
        int d = arr[i] - p;
        int D = abs(d), L = abs(l);
        if (D > L) continue;
        l = D == L ? max(d, l) : d;
        idx = i;
    }
    return idx;
}

int main(int argc, char **argv) {
    char *line = NULL;
    size_t len = 0;
    int scnt = 0;

    while ((scnt = getline(&line, &len, stdin)) >= 0) {
        int cnt = atoi(line);
        int i = 0;
        for (i = 0; i < cnt; i++) {
            if (getline(&line, &len, stdin) < 0) return -1;
            int p = atoi(strtok(line, " "));
            int n = atoi(strtok(NULL, " "));

            if (getline(&line, &len, stdin) < 0) return -1;
            int j = 0;
            for (j = 0; j < n; j++) {
                arr[j] = atoi(strtok(j == 0 ? line : NULL, " "));
                vis[j] = 0;
            }

            // printf("p: %d; n: %d\n", p, n);
            // printf("doors: ");
            // for (j = 0; j < n; j++) printf("%d ", arr[j]);
            // printf("\n");

            // printf("closest: %d\n", closest(arr, vis, n, p));
            for (j = 0; j < n; j++) {
                int pos = closest(arr, vis, n, p);
                vis[pos] = 1;
                printf("%d ", arr[pos]);
            }
            printf("\n");

            // printf("\n");
        }
    }

    return 0;
}
