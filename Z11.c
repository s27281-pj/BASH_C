#include <stdio.h>

int main() {
    int n;
    float sum = 0, num;

    printf("Podaj ilość liczb do zsumowania: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Podaj liczbę nr %d: ", i+1);
        scanf("%f", &num);
        sum += num;
    }

    printf("Suma podanych liczb wynosi: %f\n", sum);

    return 0;
}
