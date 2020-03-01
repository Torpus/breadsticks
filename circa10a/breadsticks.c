#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int result = 0;
    char *ptr;
    char str[20];

    regex_t regex;
    regcomp(&regex, "breadsticks", 0);

    fp = fopen(argv[1], "r");

    while ((read = getline(&line, &len, fp)) != -1) {
        if (!regexec(&regex, line, 0, NULL, 0)) {
            strcpy (str, line);
            strtok_r (str, " ", &ptr);
            result += atoi(ptr);
        }
    }

    printf("%d\n", result);
    exit(EXIT_SUCCESS);
}