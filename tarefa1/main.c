#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_selection, user_sub_selection; // Vari�veis de controle
    float R1, R2, X1, X2; // Armazena parte real e imagin�ria das imped�ncias
    /*
     * Vari�veis utilizadas para a op��o 'c' (c�lculo de reat�ncias)
     */
    float Xl, Xc, freq;

    while(user_selection != 's')
    {
        system("cls");
        printf("\tMENU PRINCIPAL\nDigite:\n<a> Associa��o de imped�ncias em S�rie\n<b> Associa��o de imped�ncias em Paralelo\n<c> C�lculo de reat�ncias\n<d> Conversor de imped�ncias P->R e R->P\n<e> Divisor de tens�o\n<f> Divisor de corrente\n<s> Sair\n");
        fflush(stdin);
        scanf("%c", &user_selection);
        switch (user_selection)
        {
        case 'a':   // Submenu Associa��o de imped�ncias em s�rie
            while (user_sub_selection != 'r')
            {
                system("cls");
                fflush(stdin);
                printf("ASSOCIA��O DE IMPED�NCIAS EM S�RIE\nDigite:\n<a> Entre com o valor da imped�ncia 1 (forma retangular)\n<b> Entre com o valor da imped�ncia 2 (forma retangular)\n<c> Apresentar imped�ncia equivalente\n<r> Retornar ao menu principal\n");
                scanf("%c", &user_sub_selection);
                switch (user_sub_selection)
                {
                case 'a': // Solicita o valor da impedancia 1
                    printf("\nInforme o valor da imped�ncia 1 (forma retangular Z=R+jX)\nEntre com o valor de R: ");
                    while(scanf("%f", &R1) != 1) // Armazena a parte real da impedancia
                    {
                        printf("\nInforme um valor v�lido!");
                        fflush(stdin);
                    }
                    printf("Entre com o valor de X: ");
                    while(scanf("%f", &X1) != 1) // Armazena a parte imagin�ria da imped�ncia
                    {
                        printf("\nInforme um valor v�lido!");
                        fflush(stdin);
                    }
                    break;

                case 'b': // Solicita o valor da impedancia 2
                    printf("\nInforme o valor da imped�ncia 2 (forma retangular Z=R+jX)\nEntre com o valor de R: ");
                    while(scanf("%f", &R2) != 1)
                    {
                        printf("\nInforme um valor v�lido!");
                        fflush(stdin);
                    }
                    printf("Entre com o valor de X: ");
                    while(scanf("%f", &X2) != 1) // Armazena a parte imagin�ria da imped�ncia
                    {
                        printf("\nInforme um valor v�lido!");
                        fflush(stdin);
                    }
                    break;

                case 'c': // Apresenta o valor da impedancia equivalente
                    printf("\n A imped�ncia equivalente Zeq = %g + j%g Ohms\n Pressione qualquer tecla para prosseguir", (R1+R2), (X1+X2));
                    fflush(stdin);
                    while(scanf("%c", &user_selection)!=1); // Aguarda alguma tecla ser pressionada para sair
                    break;
                }

            }
            break;  // Fim do submenu de imped�ncia s�rie

        case 'b':   // In�cio do submenu de imped�ncia em paralelo
            while(user_sub_selection != 'r') // Se o usu�rio digitar 'r', volta ao menu principal
            {
                fflush(stdin);
                system("cls");
                printf("ASSOCIA��O DE IMPED�NCIAS EM PARALELO\nDigite:\n<a> Entre com o valor da imped�ncia 1 (forma polar)\n<b> Entre com o valor da imped�ncia 2 (forma polar)\n<c> Apresentar imped�ncia equivalente\n<r> Retornar ao menu principal\n");
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
            break;  // Fim do submenu de imp�ncia em paralelo

        case 'c':   // In�cio do submenu de c�lculo de reat�ncias

            break;  // Fim do submenu de c�lculo de reat�ncias

        default:
            break;
        }
    }
    return 0;
}
