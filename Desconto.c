#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- FUNÇÕES AUXILIARES ---

void limpar_buffer() { // Garante que o buffer seja limpo completamente
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

double ler_valor() {
    char entrada[50], limpo[50];
    int j = 0;
    if (scanf("%s", entrada) != 1) return 0;
    limpar_buffer(); // Limpa logo após ler a string
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] == ',') limpo[j++] = '.'; 
        else if (entrada[i] == '.') continue;    
        else if ((entrada[i] >= '0' && entrada[i] <= '9') || entrada[i] == '-') {
            limpo[j++] = entrada[i];
        }
    }
    limpo[j] = '\0';
    return atof(limpo);
}

void imprimir_moeda(const char* label, double valor) {
    char temp[50], final[60];
    sprintf(temp, "%.2f", valor); 
    char *ponto = strchr(temp, '.');
    int tamanho_inteiro = (int)(ponto - temp);
    int j = 0;

    for (int i = 0; i < tamanho_inteiro; i++) {
        if (i > 0 && (tamanho_inteiro - i) % 3 == 0) final[j++] = '.';
        final[j++] = temp[i];
    }
    final[j++] = ',';
    final[j++] = ponto[1];
    final[j++] = ponto[2];
    final[j++] = '\0';
    printf("%-27s R$ %s\n", label, final);
}

// --- TUTORIAL ATUALIZADO ---

void exibir_tutorial() {
    limpar_tela();
    printf("==================================================================\n");
    printf("                 GUIA DE OPERACAO E EXEMPLOS                   \n");
    printf("==================================================================\n\n");
    
    printf("1. PORCENTAGEM DE DESCONTO (%%):\n");
    printf("   Ideal quando a negociacao e baseada em uma margem fixa.\n");
    printf("   Ex: Produto de 23.000 com 15%% aplicado diretamente.\n\n");

    printf("2. MODO: VALOR FINAL (líquido):\n");
    printf("   Ideal para 'fechar' um valor redondo de venda.\n");
    printf("   Ex: Venda de 23.000 que voce deseja reduzir para 19.500.\n\n");

    printf("3. VALOR NOMINAL DO DESCONTO:\n");
    printf("   Ideal quando voce sabe exatamente quanto pode tirar do preco.\n");
    printf("   Ex: Venda de 23.000 onde voce concede 7.000 de desconto bruto.\n\n");

    printf("COMO DIGITAR OS VALORES:\n");
    printf("   - Use virgula para centavos (ex: 1500,50)\n");
    printf("   - Pontos de milhar sao opcionais (ex: 23.000 ou 23000)\n\n");
    printf("==================================================================\n");
    printf("Pressione [ENTER] para voltar ao menu principal...");
    
	// Removido o limpar_buffer daqui pois ele ja foi chamado no main ou ler_valor
	getchar();
}

// --- LOGICA DE CALCULO ---

void executar_caso(int tipo) {
    double valor_total, desconto_perc, valor_total_c_desc, valor_entrada, v_bruto_desconto;
    int qtd_parcelas;

    limpar_tela();
    if (tipo == 1) printf("--- MODO: PORCENTAGEM DE DESCONTO (%%) ---\n");
    else if (tipo == 2) printf("--- MODO: VALOR FINAL (líquido) ---\n");
    else printf("--- MODO: VALOR NOMINAL DO DESCONTO ---\n");

    printf("Valor Total Original: "); valor_total = ler_valor();

    if (tipo == 1) {
        printf("Percentual de Desconto (%%): "); desconto_perc = ler_valor();
        valor_total_c_desc = valor_total * (1 - (desconto_perc / 100));
    } else if (tipo == 2) {
        printf("Valor Total com Desconto: "); valor_total_c_desc = ler_valor();
        desconto_perc = (1 - (valor_total_c_desc / valor_total)) * 100;
    } else {
        printf("Valor do Desconto a Aplicar: "); v_bruto_desconto = ler_valor();
        valor_total_c_desc = valor_total - v_bruto_desconto;
        desconto_perc = (v_bruto_desconto / valor_total) * 100;
    }

    printf("Valor da Entrada (Pago): "); valor_entrada = ler_valor();
    printf("Qtd Parcelas: "); 
    scanf("%d", &qtd_parcelas);
    limpar_buffer();

    double fator = valor_total_c_desc / valor_total;
    double entrada_s_desc = valor_entrada / (fator > 0 ? fator : 1);
    double parcela_c_desc = (valor_total_c_desc - valor_entrada) / (qtd_parcelas > 0 ? qtd_parcelas : 1);
    double parcela_s_desc = parcela_c_desc / (fator > 0 ? fator : 1);

    printf("\n==========================================\n");
    printf("            RESULTADOS FINAIS             \n");
    printf("==========================================\n");
    imprimir_moeda("Valor total (calculado):", ((parcela_s_desc * qtd_parcelas) + entrada_s_desc));
    imprimir_moeda("Valor liquido:", valor_total_c_desc);
    printf("\n");
    imprimir_moeda("Desconto Aplicado (R$):", (valor_total - valor_total_c_desc));
    printf("%-27s %.2f%%\n", "Desconto Aplicado (%):", desconto_perc);
    printf("\n");
    imprimir_moeda("Entrada s/ Desconto:", entrada_s_desc);
    imprimir_moeda("Desconto na Entrada:", entrada_s_desc - valor_entrada);
    imprimir_moeda("Entrada c/ Desconto:", valor_entrada);
    printf("\n");
    imprimir_moeda("Parcela s/ Desconto:", parcela_s_desc);
    imprimir_moeda("Desconto na Parcela:", parcela_s_desc - parcela_c_desc);
    imprimir_moeda("Parcela c/ Desconto:", parcela_c_desc);
    printf("==========================================\n");
    
    printf("\nPressione [ENTER] para voltar...");
    getchar(); // Aqui agora funciona com um toque pois o buffer está limpo
}

int main() {
    int opcao = -1;
    while (opcao != 0) {
        limpar_tela();
        printf("===================================\n");
        printf("        MONTAR FINANCEIRO\n");
        printf("===================================\n");
        printf("[1] Porcentagem de desconto (%%)\n");
        printf("[2] Valor final (líquido)\n");
        printf("[3] Valor nominal do desconto\n");
        printf("[4] Tutorial\n");
        printf("[0] Sair\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            continue;
        }
        limpar_buffer(); // <--- LIMPEZA IMEDIATA APÓS O SCANF DA OPÇÃO

        if (opcao >= 1 && opcao <= 3) {
            executar_caso(opcao);
        } else if (opcao == 4) {
            exibir_tutorial();
        }
    }
    return 0;
}