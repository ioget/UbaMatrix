
#include <stdio.h>
#include <stdlib.h>
#include<dos.h>

// Définition de la taille maximale des matrices
#define MAX 10

// Déclaration des fonctions
void array_Init(int mat[MAX][MAX], int n); // Initialiser une matrice avec les valeurs entrées par l'utilisateur
void array_Add(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n); // Additionner deux matrices et stocker le résultat dans une troisième matrice
void array_Sub(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n); // Soustraire deux matrices et stocker le résultat dans une troisième matrice
void array_Mul(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n); // Multiplier deux matrices et stocker le résultat dans une troisième matrice
void array_Print(int mat[MAX][MAX], int n); // Afficher une matrice à l'écran

// Fonction principale
int main()
{
    int n; // Dimension des matrices
    int mat1[MAX][MAX]; // Première matrice
    int mat2[MAX][MAX]; // Deuxième matrice
    int res[MAX][MAX]; // Matrice résultante

    printf("Entrez la dimension des matrices (entre 1 et %d): ",MAX);
    scanf("%d", &n); // Lecture de la dimension

    if (n < 1 || n > 10)
    {
        printf("Dimension invalide.\n");
        return 0;
    }

    printf("Entrez les valeurs de la premiere matrice:\n");
    array_Init(mat1, n);

    printf("Entrez les valeurs de la deuxieme matrice:\n");
    array_Init(mat2, n);

    system("cls");
     printf("-------------tab 1:------------\n");
     array_Print(mat1,n);
      printf("\n-------------tab 2:------------\n");
    array_Print(mat2,n);

     printf("\n------------- Resultat ------------\n");

    printf("\nLa somme des deux matrices est:\n");
    array_Add(mat1, mat2, res, n);
    array_Print(res, n);

    printf("\n\nLa difference des deux matrices est:\n");
    array_Sub(mat1, mat2, res, n);
    array_Print(res, n);

    printf("\n\nLa multilication des deux matrices est:\n");
    array_Mul(mat1, mat2, res, n);
    array_Print(res, n);



    return 0;
}


void array_Init(int mat[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Entrez la valeur de l'element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void array_Print(int mat[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("[%d]: ",mat[i][j]);
        }

    }
}



void array_Add(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void array_Sub(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j] - mat2[i][j]; //
        }
    }
}

void array_Mul(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = 0;
    }
  }


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
         res[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
}


