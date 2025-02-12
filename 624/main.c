#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[100] = {};

int main(int argc, char **argv) {
	char *line = NULL;
	size_t len = 0;
	ssize_t cnt = 0;

	while (1) {
		if ((cnt = getline(&line, &len, stdin)) < 0) return -1;
		int n = atoi(line);
		if (n == 0) break;

		memset(table, 0, sizeof(table) / sizeof(*table));

		if ((cnt = getline(&line, &len, stdin)) < 0) return -1;

		char *s = strtok(line, " ");
		int i = 0, m = 0, c = 0;
		for (i = 0; i < n; i++) {
			int idx = atoi(s) - 1;
			if (table[idx]) {
				table[idx] = 0;
				c--;
			} else {
				table[idx] = 1;
				c++;
			}
			if (c > m) m = c;
			s = strtok(NULL, " ");
		}
		printf("%d\n", m);
	}

	return 0;
}
