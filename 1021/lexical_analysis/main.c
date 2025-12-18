#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 100

// Array of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "inline", "int", "long", "register", "restrict", "return", "short",
    "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof",
    "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary", "_Noreturn",
    "_Static_assert", "_Thread_local"
};

const char *operators[] = {
    "+", "-", "*", "/", "%", "<", ">", "=", "==", "!=", ">=", "=<"
};

const int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
const int num_operators = sizeof(operators) / sizeof(operators[0]);

// Check if a string is a C keyword
int is_keyword(const char *word) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Check if a string is a C operator
int is_operator(const char *word) {
    for (int i = 0; i < num_operators; i++) {
        if (strcmp(word, operators[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char filename[100];
    char word[MAX_WORD];
    FILE *fp;
    int i;
    char ch;

    printf("Enter the filename: ");
    scanf("%99s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("C keywords in the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch) || ch == '_') {
            i = 0;
            word[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_')) {
                if (i < MAX_WORD - 1)
                    word[i++] = ch;
            }
            word[i] = '\0';
            if (is_keyword(word)) {
                printf("%s\n", word);
            }
            // If the last read character is not part of a word, put it back for next iteration
            if (ch != EOF)
                ungetc(ch, fp);
        }
    }
    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("Operators are:\n");
    while ((ch = fgetc(fp)) != EOF) {
        // Check for one or two character operators
        if (ch == '+' || ch == '-' || ch == '=' || ch == '*' ||
            ch == '/' || ch == '>' || ch == '<' || ch == '%' || ch == '!') {
            i = 0;
            word[i++] = ch;
            word[i] = '\0';

            // Peek next character for possible two-character operator
            int next_ch = fgetc(fp);
            if (next_ch != EOF) {
                word[i++] = next_ch;
                word[i] = '\0';
                if (is_operator(word)) {
                    printf("%s\n", word);
                } else {
                    word[i-1] = '\0';
                    if (is_operator(word)) {
                        printf("%s\n", word);
                    }
                    // If not a two-character operator, put back the character
                    ungetc(next_ch, fp);
                }
            } else {
                word[i] = '\0';
                if (is_operator(word)) {
                    printf("%s\n", word);
                }
            }
        }
    }
    fclose(fp);

    return 0;
}
