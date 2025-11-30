#include <stdio.h>

// Esta estrutura agrupa dados relacionados (nome, cor do exército e tropas)
// em uma única unidade lógica.
typedef struct {
    char nome[30];    // Nome do território (máximo 29 caracteres + '\0')
    char cor[10];     // Cor do exército (máximo 9 caracteres + '\0')
    int tropas;       // Quantidade de tropas no território
} Territorio;

// Constante para o número de territórios a serem cadastrados
#define NUM_TERRITORIOS 5

int main() {
    Territorio	base_de_territorios[NUM_TERRITORIOS];
	int			i;

	i = 0;
    
    printf("--- Sistema de Cadastro de Territórios ---\n");
    printf("Por favor, cadastre os dados de %d territórios.\n", NUM_TERRITORIOS);
    printf("-------------------------------------------------\n\n");

    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf(">>> Cadastro do Território %d de %d <<<\n", i + 1, NUM_TERRITORIOS);
        
        // Entrada do Nome
        printf("Nome do território (máx. 29 caracteres): ");
        // Uso de scanf para ler a string. É importante notar que scanf("%s", ...) 
        // para strings para no primeiro espaço em branco.
        // O & comercial não é necessário para vetores de char.
        scanf("%29s", base_de_territorios[i].nome);
        
        // Entrada da Cor do Exército
        printf("Cor do exército (máx. 9 caracteres): ");
        scanf("%9s", base_de_territorios[i].cor);
        
        // Entrada da Quantidade de Tropas
        printf("Quantidade de tropas: ");
        if (scanf("%d", &base_de_territorios[i].tropas) != 1) {
            // Tratamento básico de erro para leitura de inteiro
            printf("Erro na leitura das tropas. Saindo.\n");
            return 1;
        }
        
        printf("-------------------------------------------------\n");
    }

    // Exibição dos Dados
    printf("\n--- Dados dos Territórios Cadastrados ---\n");
    
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("\n== Território %d ==\n", i + 1);
        printf("  Nome:    %s\n", base_de_territorios[i].nome);
        printf("  Cor:     %s\n", base_de_territorios[i].cor);
        printf("  Tropas:  %d\n", base_de_territorios[i].tropas);
    }
    
    printf("\n--------------------------------------------\n");
    printf("Cadastro e exibição concluídos com sucesso!\n");

    return 0;
}
