#include <stdio.h>
#include <stdlib.h>

/***
 IMPLEMENTADO POR -> LUCAS ARAÚJO GONÇALVES E MACKELE LOURRANE JUREMA DA SILVA
 ***/

void multiplicaAB(float *a, float *b, int n, int m, int p, int q)
{
    if (n == q && m == p) //condição de multiplicação de matrizes
    {
        float *res; //res(nxq)
        int i=0, j=0, k=0;
        res = (float *)malloc(n * q * sizeof(float)); //alocação da matriz resultante
        if (res != NULL)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < q; j++)
                {
                    res[(i * q) + j] = 0; // res[i][j] = 0 <=> pra n somar com lixo da memoria
                }
            }
            for (i = 0; i < n; i++)
            { //la
                for (j = 0; j < q; j++)
                {//cb
                    for (k = 0; k < m; k++) //n==q e m==p
                    {// ca  
                        res[i * q + j] += a[i * m + k] * b[k * q + j]; 
                        //res(nxq), res recebe na pos "[i][j]" o incremento da mult de linhas "a' com colunas 'b'
                        // res[i][j] += a[i][k] * b[k][j];
                    }
                }
            }

            //somente imprime a matriz res(nxq)
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < q; j++)
                {
                    printf("%.1f ", res[(i * q) + j]); // res[i][j]
                }
                printf("\n");
            }
        }
        free(res);//limpar o vetor dinamico da memoria
    }
    else
    {
        printf("Dimensoes incorretas\n");
    }
}
float *transpostacal(float *a, int n, int m, int flag) //matrizA(n x m) matrizT(m x n)
{
    float *matT;
    int i = 0, j = 0;
    matT = (float *)malloc(n * m * sizeof(float));
    if (matT != NULL)
    {
        // ocorre a atribuição da transposta
        for (i = 0; i < n; i++)
        { 
            for (j = 0; j < m; j++)
            {                                   
                matT[j * n + i] = a[i * m + j]; // matT[j][i]= a[i][j]
            }
        }
        if (flag == 1)
        {
            for (i = 0; i < m; i++) //matT[m][n]
            {
                for (j = 0; j < n; j++)
                {
                    printf("%.1f ", matT[i * n + j]);
                }
                printf("\n");
            }
        }
        return matT;
    }
    return 0;
}
void multplicaABT(float *a, float *b, int n, int m, int p, int q)
{
    if (n == p && m == q) // matriz a(nxm) * bT(qxp). Multi so existe se n==p e m==q
    {
        float *bT; //bT = matriz transposta de B, logo b(pxq) e bT(qxp)
        int i = 0, j = 0, k = 0;

        bT = (float *)malloc(q * p * sizeof(float *));
        if (bT != NULL)
        {
            bT = transpostacal(b, p, q, 0);
            multiplicaAB(a, bT, n, m, q, p);
        }
        free(bT);
    }
    else
    {
        printf("Dimensoes incorretas\n");
    }
}
float *alocarMatriz(int n, int m)
{
    float *matriz;
    int i = 0, j = 0;
    if (n > 0 && m > 0) // checar se matrizes  sao possiveis
    {
        matriz = (float *)malloc(n * m * sizeof(float)); //aloca todos os elemen da matriz
        if (matriz != NULL)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    printf("Matriz[%d][%d] = ", i, j);
                    scanf("%f", &matriz[i * m + j]); //  <=> &matriz[i][j] // aritimetica de ponteiros
                }
            }
        }
        return matriz;
    }

    printf("Nao conseguiu alocar os elementos da matriz");
    return 0;
}

void menu()
{
    printf("1 - Ler a matriz A\n");
    printf("2 - Ler a matriz B\n");
    printf("3 - MULTIPLICA A POR B\n");
    printf("4 - Calcula transposta de A\n");
    printf("5 - MULPLICA a matriz A pela transposta de B\n");
    printf("6 - SAIR\n");
}

int main(void)
{
    float *matrizA, *matrizB;
    int n = 0, m = 0, p = 0, q = 0, i = 0, j = 0;
    char op;
    while (op != '6')
    {
        system("CLS");
        menu();
        scanf("%c", &op);
        switch (op)
        {
        case '1':
            system("CLS");
            printf("Linhas: ");
            scanf("%d", &n);
            printf("\nColunas: ");
            scanf("%d", &m);
            matrizA = alocarMatriz(n, m);
            system("PAUSE");
            break;
        case '2':
            system("CLS");
            printf("Linhas: ");
            scanf("%d", &p);
            printf("\nColunas: ");
            scanf("%d", &q);
            matrizB = alocarMatriz(p, q);
            system("PAUSE");
            break;
        case '3':
            system("CLS");
            multiplicaAB(matrizA, matrizB, n, m, p, q);
            system("PAUSE");
            break;
        case '4':
            system("CLS");
            transpostacal(matrizA, n, m, 1);
            system("PAUSE");
            break;
        case '5':
            system("CLS");
            multplicaABT(matrizA, matrizB, n, m, p, q);
            system("PAUSE");
            break;
        }
    }
    free(matrizA);
    free(matrizB);
    return 0;
}