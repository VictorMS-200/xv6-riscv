#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void trabalho() {
    int pid = getpid();

    // Inicia o contador de ticks
    int start_time = uptime();

    // Realiza uma tarefa pesada
    long soma = 0;
    long maximo = 5000000000; 
    for (long i = 0; i < maximo; i++) {
        soma = soma + 1;
    }

    // Termina o contador de ticks
    int end_time = uptime();

    int contador = getruncount(); // Obtém o número de execuções do processo

    int total_time = end_time - start_time;
    
    printf("O processo %d terminou em %d ticks com %d execuções.\n", pid, total_time, contador);
    exit(0);
}

int main(void) {
    int numero_processos = 10;

    // Cria os processos filhos
    for (int i = 0; i < numero_processos; i++) {
        int pid = fork();
        if (pid == 0) {
            trabalho();
        }
    }
    // Espera todos os processos filhos terminarem
    for (int i = 0; i < numero_processos; i++) {
        wait(0);
    }
    return 0;
}