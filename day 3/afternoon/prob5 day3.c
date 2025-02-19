#include <stdio.h>
#include <string.h>

int findSubstring(char str[], char sub[]) {
    char *pos = strstr(str, sub);
    return (pos != NULL) ? (pos - str) : -1;
}

int main() {
    char str[100], sub[100];

    printf("Enter main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Enter substring: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = 0;
    int index = findSubstring(str, sub);
    printf("Substring found at index: %d\n", index);

    return 0;
}
