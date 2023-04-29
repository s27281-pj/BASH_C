#include <stdio.h>

int main() {
    char operator;
    float num1, num2, wynik;

    printf("Podaj operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Podaj dwie liczby oddzielone spacją: ");
    scanf("%f %f", &num1, &num2);

    switch(operator) {
        case '+':
            wynik = num1 + num2;
            printf("%.2f + %.2f = %.2f", num1, num2, wynik);
            break;

        case '-':
            wynik = num1 - num2;
            printf("%.2f - %.2f = %.2f", num1, num2, wynik);
            break;

        case '*':
            wynik = num1 * num2;
            printf("%.2f * %.2f = %.2f", num1, num2, wynik);
            break;

        case '/':
            wynik = num1 / num2;
            printf("%.2f / %.2f = %.2f", num1, num2, wynik);
            break;

        default:
            printf("Nieprawidłowy operator");
            break;
    }

    return 0;
}

