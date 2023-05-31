#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Funkcja obsługująca sygnał SIGINT (Ctrl+C)
void sigint_handler(int signum) {
    printf("Otrzymano sygnał SIGINT\n");
    // Domyślna obsługa sygnału (zakończenie programu)
    exit(signum);
}

// Funkcja obsługująca sygnał SIGUSR1 (przez polecenie kill)
void sigusr1_handler(int signum) {
    printf("Otrzymano sygnał SIGUSR1\n");
    // Własna obsługa sygnału
    printf("Własna obsługa sygnału SIGUSR1\n");
}

int main(int argc, char *argv[]) {
    // Sprawdzenie argumentów wywołania programu
    if (argc != 2) {
        printf("Użycie: %s [opcja]\n", argv[0]);
        return 1;
    }

    // Pobranie wartości opcji obsługi sygnałów
    int option = atoi(argv[1]);

    // Instalacja obsługi sygnału SIGINT (Ctrl+C)
    signal(SIGINT, sigint_handler);

    // Obsługa sygnału SIGUSR1 (przez polecenie kill)
    signal(SIGUSR1, sigusr1_handler);

    // Wykonanie odpowiedniej operacji zależnie od opcji
    switch (option) {
        case 1:
            printf("Wybrano opcję wykonania operacji domyślnej\n");
            break;
        case 2:
            printf("Wybrano opcję ignorowania sygnałów\n");
            signal(SIGINT, SIG_IGN); // Ignorowanie sygnału SIGINT
            signal(SIGUSR1, SIG_IGN); // Ignorowanie sygnału SIGUSR1
            break;
        case 3:
            printf("Wybrano opcję przechwycenia i własnej obsługi sygnału\n");
            break;
        default:
            printf("Nieprawidłowa opcja\n");
            return 1;
    }

    // Wysyłanie sygnałów do programu
    printf("Uruchomiono program. PID: %d\n", getpid());
    printf("Wysyłanie sygnałów: SIGINT (Ctrl+C) oraz SIGUSR1 (przez polecenie kill)\n");
    printf("Aby zakończyć program, użyj Ctrl+C\n");

    while (1) {
        sleep(1);
    }

    return 0;
}
