#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"

int main()
{
	int opcao, matriz[3][3][9], maleatorio[3][3][9];

	printf("TDA - SUDOKU\n");
	printf("Opções:\n");
	printf("1- Criar Arranjo\n");
	printf("2- Verificar Arranjo\n");
	printf("3- Gerar um problema aleatório\n");
	printf("4- Solucionar um problema\n");
	printf("5- Imprimir Arranjo\n");
	
	while(1)
	{
		scanf("%d", &opcao);
		if(opcao == 0)
			break;
		switch(opcao)
		{
			case 1:
			{
				criarArranjo(matriz);
				break;
			}
			case 2:
			{
				if(testaSudoku(matriz) == 0)
					printf("\nÉ um Sudoku valido\n");
				else
					printf("\nNão é um Sudoku valido\n");
			}
			break;

			case 3:
				geraSudoku(maleatorio);
			break;

			case 4:
			break;

			case 5:
			{
				imprimirArranjo(matriz);
				printf("\n");
				break;
			}
			
		}
	}
	return 0;
}