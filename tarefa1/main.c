#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_selection, user_sub_selection; // Variáveis de controle
    float R1, R2, X1, X2; // Armazena parte real e imaginária das impedâncias
    /*
     * Variáveis utilizadas para a opção 'c' (cálculo de reatâncias)
     */
    float Xl, Xc, freq;

    while(user_selection != 's')
    {
        system("cls");
        printf("\tMENU PRINCIPAL\nDigite:\n<a> Associação de impedâncias em Série\n<b> Associação de impedâncias em Paralelo\n<c> Cálculo de reatâncias\n<d> Conversor de impedâncias P->R e R->P\n<e> Divisor de tensão\n<f> Divisor de corrente\n<s> Sair\n");
        fflush(stdin);
        scanf("%c", &user_selection);
        switch (user_selection)
        {
        case 'a':   // Submenu Associação de impedâncias em série
            while (user_sub_selection != 'r')
            {
                system("cls");
                fflush(stdin);
                printf("ASSOCIAÇÃO DE IMPEDÂNCIAS EM SÉRIE\nDigite:\n<a> Entre com o valor da impedância 1 (forma retangular)\n<b> Entre com o valor da impedância 2 (forma retangular)\n<c> Apresentar impedância equivalente\n<r> Retornar ao menu principal\n");
                scanf("%c", &user_sub_selection);
                switch (user_sub_selection)
                {
                case 'a': // Solicita o valor da impedancia 1
                    printf("\nInforme o valor da impedância 1 (forma retangular Z=R+jX)\nEntre com o valor de R: ");
                    while(scanf("%f", &R1) != 1) // Armazena a parte real da impedancia
                    {
                        printf("\nInforme um valor válido!");
                        fflush(stdin);
                    }
                    printf("Entre com o valor de X: ");
                    while(scanf("%f", &X1) != 1) // Armazena a parte imaginária da impedância
                    {
                        printf("\nInforme um valor válido!");
                        fflush(stdin);
                    }
                    break;

                case 'b': // Solicita o valor da impedancia 2
                    printf("\nInforme o valor da impedância 2 (forma retangular Z=R+jX)\nEntre com o valor de R: ");
                    while(scanf("%f", &R2) != 1)
                    {
                        printf("\nInforme um valor válido!");
                        fflush(stdin);
                    }
                    printf("Entre com o valor de X: ");
                    while(scanf("%f", &X2) != 1) // Armazena a parte imaginária da impedância
                    {
                        printf("\nInforme um valor válido!");
                        fflush(stdin);
                    }
                    break;

                case 'c': // Apresenta o valor da impedancia equivalente
                    printf("\n A impedância equivalente Zeq = %g + j%g Ohms\n Pressione qualquer tecla para prosseguir", (R1+R2), (X1+X2));
                    fflush(stdin);
                    while(scanf("%c", &user_selection)!=1); // Aguarda alguma tecla ser pressionada para sair
                    break;
                }

            }
            break;  // Fim do submenu de impedância série

        case 'b':   // Início do submenu de impedância em paralelo
            while(user_sub_selection != 'r') // Se o usuário digitar 'r', volta ao menu principal
            {
                fflush(stdin);
                system("cls");
                printf("ASSOCIAÇÃO DE IMPEDÂNCIAS EM PARALELO\nDigite:\n<a> Entre com o valor da impedância 1 (forma polar)\n<b> Entre com o valor da impedância 2 (forma polar)\n<c> Apresentar impedância equivalente\n<r> Retornar ao menu principal\n");
                scanf("%c", &user_sub_selection);
                switch (user_sub_selection)
                {
                case 'a': // Solicita o valor da impedancia 1

                    break;

                case 'b': // Solicita o valor da impedancia 2

                    break;

                case 'c': // Apresenta o resultado equivalente

                    break;
                }
            }
            break;  // Fim do submenu de impância em paralelo

        case 'c':   // Início do submenu de cálculo de reatâncias

            break;  // Fim do submenu de cálculo de reatâncias

        default:
            break;
        }
    }
    return 0;
}
