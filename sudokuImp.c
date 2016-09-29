#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"

void criarArranjo(int matriz[3][3][9]){
	int i, j, k;
	for(k=0; k<9; k++)
	{	
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%d ", &matriz[i][j][k]);
			}
		}
	}
}

void imprimirArranjo(int matriz[3][3][9]){
	
	int i, j, k;

	for(k=0; k<9; k++)
	{
		printf("\n");
		for(i=0;i<3;i++)
		{	
			for(j=0;j<3;j++)
			{
				printf("%d ",matriz[i][j][k]);
			}
		}
	}
	printf("\n");
}
int testaSudoku(int matriz[3][3][9])
{
	int i, k=0, j, z, valinicial=0, qtnumeros[9], flag = 0, qtcerta = 0;

	for(i=0;i<9;i++)
		qtnumeros[i] = 0; //Zera o contador dos numeros

	while(k!=9)
	{	
		for(i=0; i<3; i++)
		{
			for(z=0; z<3; z++){
				for(j=0; j<3; j++)
				{	
					qtnumeros[matriz[i][j][k]-1]++;
					//printf("%d ",matriz[i][j][k]);				
				}
				if(z<2)
					k++;
				else{
					k = valinicial;
					//printf("\n");
				}
			}
			qtcerta++;
			for(j=0;j<9;j++){
				if(qtnumeros[j] != qtcerta){
					flag = 1;
					break;
				}
			}
		}
		if(i==3)
		{
			valinicial = valinicial+3;
			k = valinicial;
		}
	}

	qtcerta = k = valinicial = 0;
	for(j=0;j<9;j++)
		qtnumeros[j] = 0;

	while(k<=2){
		for(j=0;j<3;j++){
			for(z=0;z<3;z++){
				for(i=0;i<3;i++){
					qtnumeros[matriz[i][j][k]-1]++;
					//printf("%d ",matriz[i][j][k]);				
				}

				if(z<2){
					k = k + 3;
				}
				else{
					k = valinicial;
					//printf("\n");
				}
			}
			qtcerta++;
			for(i=0;i<9;i++){
				if(qtnumeros[i] != qtcerta){
					flag = 1;
				break;
				}
			}
		}
		if(j==3){
			valinicial++;
			k = valinicial;
		}
	}

	qtcerta = k = valinicial = 0;
	for(j=0;j<9;j++)
		qtnumeros[j] = 0;


	for(k=0;k<9;k++){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				qtnumeros[matriz[i][j][k]-1]++;
			}
		}
		qtcerta++;
		for(i=0;i<9;i++){
			if(qtnumeros[i] != qtcerta){
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

void geraSudoku(int matriz[3][3][9]){
	
	//Eu sei que tá feio, a gente tava testando mas nao da mais tempo. Perdoa nois

	int i, j, k, aux;
	
	srand(time(NULL));

	for(k=0;k<9;k++){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				matriz[i][j][k] = 0;
			}
		}
	}

	while(matriz[0][2][0] == 0){
		matriz[0][2][0] = rand() % 10;
	}
	
	while(matriz[1][0][0] == 0 || matriz[1][0][0] == matriz[0][2][0]){
		matriz[1][0][0] = rand() %10;
	}

	while(matriz[0][1][2] == 0 || matriz[0][1][2] == matriz[0][2][0]){
		matriz[0][1][2] = rand() % 10;
	}
	
	while(matriz[2][0][1] == 0 || matriz[2][0][1] == matriz[0][1][2]){
		matriz[2][0][1] = rand() % 10;
	}

	while(matriz[1][0][2] == 0 || matriz[1][0][2] == matriz[1][0][0]){
		matriz[1][0][2] = rand() % 10;
	}

	while(matriz[2][2][2] == 0 || matriz[2][2][2] == matriz[2][0][1] || matriz[2][2][2] == matriz[1][0][2]){
		matriz[2][2][2] = rand() % 10;
	}

	while(matriz[0][1][3] == 0){
		matriz[0][1][3] = rand() % 10;
	}

	while(matriz[2][1][3] == 0 || matriz[2][1][3] == matriz[0][1][3]){
		matriz[2][1][3] = rand() % 10;
	}

	while(matriz[1][0][4] == 0 || matriz[1][0][4] == matriz[2][0][1] || matriz[1][0][4] == matriz[1][1][5]){
		matriz[1][0][4] = rand() % 10;
	}

	while(matriz[0][2][4] == 0 || matriz[0][2][4] == matriz[0][1][3] || matriz[0][2][4] == matriz[0][1][2] ||
		  matriz[0][2][4] == matriz[1][0][4]){
		matriz[0][2][4] = rand() % 10;
	}

	while(matriz[1][1][5] == 0 || matriz[1][1][5] == matriz[1][0][4]){
		matriz[1][1][5] = rand() % 10;
	}

	while(matriz[0][2][5] == 0 || matriz[0][2][5] == matriz[1][1][5] || matriz[0][2][5] == matriz[2][2][2]){
		matriz[0][2][5] = rand() % 10;
	}

	while(matriz[0][0][6] == 0 || matriz[0][0][6] == matriz[1][0][0]){
		matriz[0][0][6] = rand() % 10;
	}

	while(matriz[0][1][7] == 0 || matriz[0][1][7] == matriz[0][0][6]){
		printf("OI\n");
		matriz[0][1][7] = rand() % 10;
	}
	while(matriz[1][2][7] == 0 || matriz[1][2][7] == matriz[0][1][7] || matriz[1][2][7] == matriz[0][2][4] ||
		  matriz[1][2][7] == matriz[0][1][2]){
		printf("OI2\n");
		matriz[1][2][7] = rand() % 10;
	}
	while(matriz[1][2][8] == 0 || matriz[1][2][8] == matriz[0][2][5] || matriz[1][2][8] == matriz[2][2][2] ||
		matriz[1][2][8 == matriz[1][2][7]]){
		printf("OI3\n");
		matriz[1][2][8] = rand() % 10;
	}


	for(k=0;k<9;k++){
		printf("\n");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(matriz[i][j][k] == 0){
					printf("x ");
				}
				else{
					printf("%d ", matriz[i][j][k]);
				}
			}
		}
	}	
}
