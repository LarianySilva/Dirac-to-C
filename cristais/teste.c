#include <stdio.h>
#include <math.h>

int main() {
    int N = 50; // Define o tamanho da grade (50x50 moléculas)
    
    // ACria um arquivo de texto para com os dados simulados
    FILE *f = fopen("dados_cristal.txt", "w");

    // Verifica se o arquivo foi aberto corretamente para evitar erros de sistema
    if (f == NULL) {
        printf("Erro ao criar o ficheiro!\n");
        return 1;
    }

    // Loop duplo para percorrer cada "ponto" do espaço (i=linha, j=coluna)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            /* CÁLCULO :
               Calcula o ângulo (orientação) de cada molécula em relação ao centro.
               atan2(y, x) cria um campo radial, que é a base de um defeito topológico. */
            double angulo = atan2(j - N/2, i - N/2);
            
            // Escreve o valor do ângulo no arquivo de texto seguido de um espaço
            fprintf(f, "%f ", angulo);
        }
        //  Pula uma linha no arquivo de texto
        fprintf(f, "\n");
    }

    // Fecha o arquivo para salvar os dados no disco
    fclose(f);
    printf("Sucesso: Ficheiro 'dados_cristal.txt' gerado!\n");
    return 0;
}