#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Given a square matrix, calculate the absolute difference between the sums of its diagonals.

/*Primeiramente usei ponteiro de ponteiro pois tive que criar uma variável que apontasse para as colunas da matriz
e posteriormente apontasse para as linhas*/

int **MAT(int n){
	int **MATRIX;
	int i;
	MATRIX = (int **)malloc(sizeof(int *)*n);//Alocação de ponteiro de ponteiro multiplicando o número de linhas

    //Laço para a alocação das colunas
	for(i = 0; i < n; i++){
		MATRIX[i] = (int *)malloc(sizeof(int)*n);
	}

	//Laço para o usuário atribuir valores em cada posição da matriz
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &MATRIX[i][j]);
		}
	}
	return MATRIX;

}
int diagonalDifference( int **M, int n){

	int principalDiagonal = 0; //inicia com 0
    for(int i = 0; i < n; i++)
        principalDiagonal += M[i][i];

    //Soma da diagonal secundária
    int secondaryDiagonal = 0;
    for(int i = 0; i < n; i++)
        secondaryDiagonal += M[i][n - i - 1];

    /*Cálculo da diferença entre a diagonal principal e a secundária
    Como o desafio pede o valor absoluto, acabei utilizando a função abs da própria linguaguem*/
    int diff = abs(principalDiagonal - secondaryDiagonal);

    return diff;
}
int main()
{
	int **Mat; // criando a matriz ponteiro de ponteiro
	int printa;
	int n;
	printf("Order of matrix: ");
	scanf("%d", &n);

    // Declarei a variável n que irá receber o valor da ordem da matriz digitada pelo usuário

    Mat = MAT(n); //passando a matriz como parâmetro

    printa = diagonalDifference(Mat,n);

    printf("\nDifference: %d\n", printa); //Printa na tela do usuário o valor final da diferença

    return 0;

}
