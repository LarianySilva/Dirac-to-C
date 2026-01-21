/*
Nesse segundo teste vai ser feita a adaptção para os mais simples exemplos de emanharamento 
*/
#include <stdio.h>
#include <math.h>

/*
produto de Kronecker =
operação entre matrizes/vetores que resulta em uma matriz maior dividida em blocos.
Nesse caso será em uma 2x2
*/

void calculaKronecker(double A[2][2], double B[2][2], double resultado[4][4]){
    for(int i=0; i<2; i++){  //Linha de A
        for(int j=0; j<2; j++){  //Coluna de A
            for(int k=0; k<2;k++){  //L de B
                for(int l=0; l<2;l++){ //C de B
                    // mapeamento para 4x4
                    resultado[i*2+k][j*2+l]=A[i][j] * B[k][l];
                }
            }
        }
    }
}
// AGOOOOOOOOOOOOOOOOOOOOOOORA

int main(){
double s= 1.0/sqrt(2.0);

// Matrizes antes trabalhadas de maneira sem modificação

double H[2][2] = {{s,s},{s,-s}}; //Prta hadamard
double I[2][2] = {{1.0,0.0},{0.0,1.0}}; //Matriz identidade

//Aplicar o Hadamard no 1° qubit 
double hI[4][4];
calculaKronecker(H, I, hI);

// |00> estado inicial 2 qubits

double qubit00[4] = {1.0,0.0,0.0,0.0};
double result[4] = {0.0,0.0,0.0,0.0};

//Será que vale mesmo o caldo de cana?

// multiplicação da matriz de estado inicial pela 4x4
for(int i=0; i<4;i++){
    for(int j=0;j<4;j++){
        result[i] += hI[i][j] * qubit00[j];
    }
}
printf("Resultado apos H x I:\n");
for(int i=0;i<4;i++){
    printf("Lugar [%d]: %.4f\n", i, result[i]);
}
// ACABA

/*
Aplicando a porta CNOT
A CNOT realiza uma operação simples: inverter o estado do qubit alvo (ou seja, aplica uma operação NOT quântica, que é a porta Pauli-X) se, e somente se, o qubit de controle estiver no estado |1⟩.
Nesse caso,adios kronecker.
*/

double  CNOT[4][4] ={
    {1.0,0.0,0.0,0.0},
    {0.0,1.0,0.0,0.0},
    {0.0,0.0,0.0,1.0},
    {0.0,0.0,1.0,0.0}
};

double estadoB[4]={0.0,0.0,0.0,0.0};

// CNOT no resultado anterior

for(int i=0;i<4;i++){
    for(int j=0; j<4;j++){
        estadoB[i] += CNOT[i][j] * result[j];
    }
}
printf("\n Supostamente Estado de Bell: \n");
for(int i=0;i<4;i++){
    printf("Lugar [%d]: %.4f\n",i,estadoB[i]);
}
return 0;
}