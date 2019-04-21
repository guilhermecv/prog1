#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_selection, user_sub_selection;

    while(user_selection != 's')
    {
        printf("\tMENU PRINCIPAL\nDigite:\n<a> Associação de impedâncias em Série\n<b> Associação de impedâncias em Paralelo\n<c> Cálculo de reatâncias\n<d> Conversor de impedâncias P->R e R->P\n<e> Divisor de tensão\n<f> Divisor de corrente\n<s> Sair\n");
        fflush(stdin);
        scanf("%c", &user_selection);
    }
    return 0;
}
