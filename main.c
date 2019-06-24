#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*================================   GLOBAL VARIABLE DECLARATION   ================================*/

int i, j, choice, det;
int rowM1, columnM1;
int rowM2, columnM2;
int rowResult, columnResult;
char check;

/*================================   GLOBAL VARIABLE DECLARATION   ================================*/

/*================================   MATRIX DECLARATION   ================================*/

struct matrix1
{
    int a[20][20];
} m1;

struct matrix2
{
    int b[20][20];
} m2;

struct matrixResult
{
    int c[20][20];
} mResult;

/*================================   MATRIX DECLARATION   ================================*/

/*================================   MENU   ================================*/

int menu()
{
    printf("\nChoose matrix operation\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Determinant\n5. Invers\n6. Exit");
    printf("\n\nInput your choice : ");
    scanf("%d", &choice);
    return choice;
}

/*================================   MENU   ================================*/

/*================================   ORDER INPUT   ================================*/

void additionSubtractionOrderInput()
{
    printf("\n\nMATRIX ORDER INPUT");
    printf("\nInsert the amount of row : ");
    scanf("%d", &rowM1);
    printf("Insert the amount of column : ");
    scanf("%d", &columnM1);
}

void inputOrdo()
{
    printf("\n\nMATRIX 1 ORDER");
    printf("\nInsert the amount of row : ");
    scanf("%d", &rowM1);
    printf("Insert the amount of column : ");
    scanf("%d", &columnM1);
    printf("\nMATRIX 2 ORDER");
    printf("\nInsert the amount of row : ");
    scanf("%d", &rowM2);
    printf("Insert the amount of column : ");
    scanf("%d", &columnM2);
}

/*================================   ORDER INPUT   ================================*/

/*================================   MATRIX ORDER CONSTRUCTION   ================================*/

void additionSubtractionOrder()
{
    if (choice == 1 || choice == 2)
    {
        rowM2 = rowM1;
        columnM2 = columnM1;
        rowResult = rowM1;
        columnResult = columnM1;
    }
}

void multiplicationOrder()
{
    if (choice == 3)
    {
        rowResult = rowM1;
        columnResult = columnM2;
    }
}

/*================================   MATRIX ORDER CONSTRUCTION   ================================*/

/*================================   MATRIX ELEMENT INPUT   ================================*/

void inputMatriks1()
{
    printf("\n<--------------------- Matrix Element Input --------------------->\n");
    printf("\nInput your matrix element form a line\n");
    printf("\nMATRIX 1\n");
    for (i = 0; i < rowM1; i++)
    {
        for (j = 0; j < columnM1; j++)
        {
            printf("Data[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &m1.a[i][j]);
        }
    }
}

void inputMatriks2()
{
    printf("\nMATRIX 2\n");
    for (i = 0; i < rowM2; i++)
    {
        for (j = 0; j < columnM2; j++)
        {
            printf("Data[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &m2.b[i][j]);
        }
    }
}

/*================================   MATRIX ELEMENT INPUT   ================================*/

/*================================   OUTPUT MATRIX   ================================*/

void outputM1()
{
    printf("\n");
    for (i = 0; i < rowM1; i++)
    {
        for (j = 0; j < columnM1; j++)
        {
            printf("%d ", m1.a[i][j]);
        }
        printf("\n");
    }
}

void outputM2()
{
    printf("\n");
    for (i = 0; i < rowM2; i++)
    {
        for (j = 0; j < columnM2; j++)
        {
            printf("%d ", m2.b[i][j]);
        }
        printf("\n");
    }
}

void outputMResult()
{
    printf("\nRESULT MATRIX\n\n");
    for (i = 0; i < rowResult; i++)
    {
        for (j = 0; j < columnResult; j++)
        {
            printf("%d ", mResult.c[i][j]);
        }
        printf("\n");
    }
}
/*================================   OUTPUT MATRIX   ================================*/

/*================================   MATRIX OPERATION   ================================*/

void addition()
{
    for (i = 0; i < rowM1; i++)
    {
        for (j = 0; j < columnM1; j++)
        {
            mResult.c[i][j] = m1.a[i][j] + m2.b[i][j];
        }
    }
}

void subtraction()
{
    for (i = 0; i < rowM1; i++)
    {
        for (j = 0; j < columnM1; j++)
        {
            mResult.c[i][j] = m1.a[i][j] - m2.b[i][j];
        }
    }
}

/*================================   MATRIX OPERATION   ================================*/

/*================================   EXIT PROGRAM   ================================*/

void exitProgram()
{
    printf("\nAre you sure want to exit (Y/T) : ");
    fflush(stdin);
    scanf("%c", &check);
    if (check == 'Y' || check == 'y')
    {
        printf("\nThank you :)\n");
    }
    else if (check == 'T' || check == 't')
    {
        printf("\n");
        main();
    }
    else
    {
        exitProgram();
    }
}

/*================================   EXIT PROGRAM   ================================*/

/*================================   INVALID CHOICE   ================================*/

void invalidChoice()
{
    printf("\nInsert choice again ? (Y/N) : ");
    fflush(stdin);
    scanf("%c", &check);
    if (check == 'Y' || check == 'y')
    {
        printf("\n");
        main();
    }
    else if (check == 'N' || check == 'n')
    {
        printf("\nThank you :)\n");
    }
    else
    {
        invalidChoice();
    }
}

/*================================   INVALID CHOICE   ================================*/

int main()
{
    int i, j, choice;

    printf("<<<<<< =====================   MATRIX CALCULATOR   ===================== >>>>>>\n");

    choice = menu();
    switch (choice)
    {
    case 1:
        printf("\nYou choose addition operation");
        additionSubtractionOrderInput();
        additionSubtractionOrder();
        inputMatriks1();
        outputM1();
        inputMatriks2();
        outputM2();
        addition();
        outputMResult();
        printf("\n");
        main();
        break;
    case 2:
        printf("\nYou choose subtraction operation");
        additionSubtractionOrderInput();
        additionSubtractionOrder();
        inputMatriks1();
        outputM1();
        inputMatriks2();
        outputM2();
        subtraction();
        outputMResult();
        printf("\n");
        main();
        break;
    case 3:
        printf("This feature is still under development");
    // printf("\n\nYou choose multiplication operation");
    // printf("\nNote !!! : The amount of column of matrix 1 must equal to amount of row of matrix 2");
    // inputOrdo();
    // if (columnM1 == rowM2)
    // {
    //     inputMatriks1();
    //     outputM1();
    //     inputMatriks2();
    //     outputM2();
    //     //perkalian();
    // }
    // else
    // {
    //     printf("\nMatrix can't be operated");
    // }
    case 4:
    case 5:
    case 6:
        exitProgram();
        break;
    default:
        printf("\nSorry your choice is invalid\n");
        invalidChoice();
    }
    return 0;
}

// add random text
