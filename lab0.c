#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 16

char** arr;
int n = 0;


void append(){
    printf("\ninput string: ");

    n++;
    int str_size = BUF;
    int k = 0;
    char* str = (char*)malloc(sizeof(char)*str_size);

    for (; 1; k++) {
        char sym = (char)getchar();

        if (k+1 > str_size){
            str_size *= 2;
            str = (char*)realloc(str, sizeof(char)*str_size);
        }

        if (sym == '\n'){
            str[k] = '\0';

            break;
        }

        str[k] = sym;
    }

    arr = (char**)realloc(arr, sizeof(char*)*n);
    arr[n-1] = (char*)malloc(sizeof(char)*(k+1));
    strcpy(arr[n-1], str);
    free(str);
}



void pop(){
    int idx;
    printf("\ninput index of string what should be deleted:");
    scanf("%i", &idx);

    if (!n){
        printf("\nthere is nothing to delete\n");

        return;
    }

    n--;
    idx--;

    if (idx > n){
        printf("\nstring with this number are not exist\n");

        return;
    }

    for (; idx < n; idx++) {
        free(arr[idx]);
        arr[idx] = (char*)malloc(sizeof(char)*strlen(arr[idx+1]));
        strcpy(arr[idx], arr[idx+1]);
    }

    arr = (char**)realloc(arr, sizeof(char*)*n);
}


void print_all(){
    if (!n){
        printf("nothing to print\n");

        return;
    }

    for(int i = 0; i < n; i++) printf("%i) %s\n", i+1, arr[i]);

    printf("\n");
}


int main() {
    while(1) {
        int command;
        printf("Menu:\n1. Add string\n2. Delete string\n3. Print all strings\n4. Exit\n\nInput command:");
        scanf("%i", &command);

        if (command == 4){
            printf("\nend of work");

            break;
        }

        if (command == 1){
            getchar();
            append();

            continue;
        }

        if (command == 2){
            pop();

            continue;
        }

        if (command == 3){
            print_all();

            continue;
        }


        printf("\nunknown command, try again\n\n");
    }

    return 0;
}
