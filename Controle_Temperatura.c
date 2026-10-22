#include <stdio.h>
#include <locale.h>
#include <windows.h>
#define MAX_DIAS 31

int main() {
    setlocale(LC_ALL, "Portuguese");

// Estrutura de armazenamento
    float temperaturas[MAX_DIAS];
    float estatisticas[3];
int dias_no_mes = 0;
    float soma = 0.0;
    float maior = 0.0;
    float menor = 0.0;

printf("=====================================================\n");
printf("        SISTEMA DE MONITORAMENTO CLIMATICO           \n");
printf("=====================================================\n\n");

// validação e leitura da quantidade de dias
while (dias_no_mes < 28 || dias_no_mes > MAX_DIAS) {
    printf("Informe a quantidade de dias do mes a registrar (28 a %d) ou [0 para sair]: ", MAX_DIAS);
if (scanf("%d", &dias_no_mes) != 1) {
while (getchar() != '\n');
    printf("[ERRO] Entrada invalida! Por favor, digite um numero inteiro.\n");
continue;
}

// checagem de opção para encerrar o programa
if (dias_no_mes == 0) {
    printf("Programa encerrado pelo usuario.\n");
    return 0;
}

if (dias_no_mes < 28 || dias_no_mes > MAX_DIAS) {
    printf("[ERRO] Quantidade fora do limite permitido (28 a %d)!\n", MAX_DIAS);
    }
}
    printf("\n--- LEITURA DAS TEMPERATURAS DIARIAS ---\n");

// laço de repetição 1
for (int i = 0; i < dias_no_mes; i++) {
    printf("Digite a temperatura do Dia %02d (C): ", i + 1);
        
while (scanf("%f", &temperaturas[i]) != 1) {
while (getchar() != '\n');
    printf("[ERRO] Digite um valor numerico valido para a temperatura (C): ");
    }
}

// laço de repetição 2
maior = temperaturas[0];
menor = temperaturas[0];
soma = 0.0;

for (int i = 0; i < dias_no_mes; i++) {
    soma += temperaturas[i];

if (temperaturas[i] > maior) {
    maior = temperaturas[i];
    }

if (temperaturas[i] < menor) {
    menor = temperaturas[i];
    }
}

estatisticas[0] = soma / dias_no_mes; // Média
estatisticas[1] = maior;              // Máxima
estatisticas[2] = menor;              // Mínima

// relatório final
printf("\n=====================================================\n");
printf("              RELATORIO CLIMATICO MENSAL             \n");
printf("=====================================================\n");
printf("Dia\t| Temperatura Registrada\n");
printf("-----------------------------------------------------\n");

for (int i = 0; i < dias_no_mes; i++) {
        printf("Dia %02d\t| %.1f C\n", i + 1, temperaturas[i]);
}

printf("-----------------------------------------------------\n");
printf("Media Mensal:      %.1f C\n", estatisticas[0]);
printf("Maior Temperatura: %.1f C (Pico de Calor)\n", estatisticas[1]);
printf("Menor Temperatura: %.1f C (Dia Mais Frio)\n", estatisticas[2]);
printf("=====================================================\n");

// alertas de variação brusca de temperatura
printf("\n--- ANALISE DE VARIACOES BRUSCAS ---\n");
    int variacoes_encontradas = 0;

    for (int i = 1; i < dias_no_mes; i++) {
        float diferenca = temperaturas[i] - temperaturas[i - 1];

    if (diferenca < 0) {
        diferenca = -diferenca;
    }

    if (diferenca >= 5.0) {
        printf("[ALERTA] Oscilacao de %.1f C entre o Dia %02d (%.1f C) e o Dia %02d (%.1f C)!\n",
        diferenca, i, temperaturas[i - 1], i + 1, temperaturas[i]);
        variacoes_encontradas++;
    }
}

if (variacoes_encontradas == 0) {
    printf("Nenhuma variacao brusca (>= 5.0 C) foi detectada no periodo.\n");
}

    printf("\nProcessamento concluido com sucesso.\n");
    return 0;
}