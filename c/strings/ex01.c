#include <stdio.h>
#include <string.h>

char inverso(char x[20]) {
    
    int length = strlen(x);
    char x[20];
    for (int i = length; i <= 0; i--) {
        char y[20] = x[i];
    }
}

int main() {

    char x[20];
    printf("Digite uma string: ");
    scanf("%s", &x);

    printf(inverso(x));
}