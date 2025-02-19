#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        // Swap characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseWords(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = 0;

    // Reverse each word in the sentence
    while (end <= length) {
        // Find the end of the current word
        if (str[end] == ' ' || str[end] == '\0') {
            reverseString(str + start, end - start);
            start = end + 1; // Move to the start of the next word
        }
        end++;
    }
}

int main() {
    char str[100]; // Assuming the input sentence will not exceed 99 characters
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;

    reverseWords(str);
    printf("Reversed Sentence: %s\n", str);

    return 0;
}
