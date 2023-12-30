#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int S();
int B();
char s[20];
int i;
void Accept() {
    printf("accept");
    _getch();
}

void reject() {
    printf("Reject");
    _getch();
}
int main() {

    printf("S->aSB\n");
    printf("S->b\n");
    printf("B->a\n");
    printf("B->bBa\n");
    printf("Enter the String:\n");
    scanf("%s", &s);
    i = 0; 
    S();
    /*if (s[i] == '\0') {
        Accept();

    }
    else {
        reject();
    }*/
    _getch();
    return 0;


}

int S() {
    if (s[i] == 'a') {
        i++;
        S();
        B();
    }
    else if (s[i] == 'b') {
        i++;
        Accept();
    }
    /*else {
        reject();
    }*/
    return 0;
}

int B() {
    if (s[i] == 'a') {
        i++;
    }
    else if (s[i] == 'b') {
        i++;
        B();
        if (s[i] == 'a') {
            i++;
        }
        else {
            reject();
        }
    }

    else {
        reject();
    }


    return 0;
}
