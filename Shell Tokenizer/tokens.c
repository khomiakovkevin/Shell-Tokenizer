#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    while (1) {
	if (feof(stdin)) {
	    exit(0);
	}

	char str[100] = " ";
	char str2[100];
	memset(str2, 0, 100);

	int k = 0;

	printf("tokens$ ");

	fgets(str, 99, stdin);

	int len = strlen(str) - 1, a = 0, s = 0;

	for (int i = len - 1; i >= 0; i--) {
	    if ((a == 1) && (str[i] == '&')) {
		str2[k++] = '&';
		str2[k++] = '\n';
		a = 0;
		continue;
	    } else if (a == 1) {
		a = 0;
		str2[k++] = '\n';
	    }

	    if ((a == 2) && (str[i] == '|')) {
		str2[k++] = '|';
		str2[k++] = '\n';
		a = 0;
		continue;
	    } else if (a == 2) {
		a = 0;
		str2[k++] = '\n';
	    }

	    if ((s == 0) && (str[i] == ' ')) {
		continue;
	    }

	    if ((str[i] == '<') || (str[i] == '>') || (str[i] == ';')
		|| (str[i] == '&') || (str[i] == '|') || (str[i] == ' ')) {
		for (int j = 0; j < s; j++) {
		    str2[k++] = str[j + i + 1];

		}
		if ((str[i] != ' ') && (i == len - 1)) {
		    str2[k++] = str[i];

		} else if ((str[i + 1] == ' ') && (i != len - 1)) {
		    str2[k++] = str[i];

		} else if ((str[i] != ' ') && (i != len - 1)) {
		    str2[k++] = '\n';
		    str2[k++] = str[i];
		}
		if (str[i] == '&') {
		    a = 1;
		} else if (str[i] == '|') {
		    a = 2;
		} else {
		    str2[k++] = '\n';
		}
		s = 0;
	    } else {
		s++;
	    }
	}
	for (int j = 0; j < s; j++) {
	    str2[k++] = str[j];
	}

	printf("%s\n", str2);
	memset(str, 0, 100);
	memset(str2, 0, 100);

    }
    return 0;
}
