/*
Teste de código de produto de porta Hadamard, adaptando código feito no octave para a linguagem C de maneira simplificada.
*/

#include <stdio.h>
// funções matemáticas básicas.
#include <math.h>

int main(){
  double s = 1.0 /sqrt(2.0);
//-----números de ponto flutuante (decimais)--------

// Matriz Hadamard

 /*
 [x]- quantidade de linhas
 [y]- "" de colunas
 */ 
double H[2][2] = {
    {s,s},{s,-s}
};
// estado 0
double qubit0[2] = {1.0,0.0};
double result[2] = {0.0,0.0};

/*
Multiplicando =
Será feito um loop para percorrer as linhas da matriz no externo, enquanto no interno será um loop que vai percorrer as colunas e elementos do vetor.
*/ 
for (int i = 0; i<2;i++){
    for(int j = 0; j<2;j++){
        // produto matrcial
        result[i] += H[i][j] * qubit0[j];
    }
}

printf("Resultado de H * |0> em C:\n");
printf("|psi> = [ %f ]\n", result[0]);
printf("|psi> = [ %f ]\n", result[1]);

return 0;

}