#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_selection, user_sub_selection;

    while(user_selection != 's')
    {
        printf("\tMENU PRINCIPAL\nDigite:\n<a> Associa��o de imped�ncias em S�rie\n<b> Associa��o de imped�ncias em Paralelo\n<c> C�lculo de reat�ncias\n<d> Conversor de imped�ncias P->R e R->P\n<e> Divisor de tens�o\n<f> Divisor de corrente\n<s> Sair\n");
        fflush(stdin);
        scanf("%c", &user_selection);
    }
    return 0;
}
