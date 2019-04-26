/**
 *  IFSC Campus Florianópolis
 *  Programação de Computadores 1 (Eng. Eletrônica)
 *  Tarefa 1 - Calculadora básica de corrente alternada
 *  Autor: Guilherme Camargo Valese
 *
 *  Obs: Este programa é compilado somente no Windows
 */
#include <complex.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592654

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_selection, user_sub_selection; // Variáveis de controle
    float R1, R2, X1, X2; // Armazena parte real e imaginária das impedâncias

    //Variáveis utilizadas para a opção 'c' (cálculo de reatâncias)
    float C, L, freq;

    while(user_selection != 'S')
    {
        system("cls");
        printf("     MENU PRINCIPAL\nDigite:\n<a> Associação de impedâncias em Série\n<b> Associação de impedâncias em Paralelo\n<c> Cálculo de reatâncias\n<d> Conversor de impedâncias P->R e R->P\n<e> Divisor de tensão\n<f> Divisor de corrente\n<s> Sair\n");
        fflush(stdin);
        user_selection = toupper(getch());
        switch (user_selection)
        {
        case 'A':   // Submenu Associação de impedâncias em série
            do
            {
                system("cls");
                printf("ASSOCIAÇÃO DE IMPEDÂNCIAS EM SÉRIE\nDigite:\n<a> Entre com o valor da impedância 1 (forma retangular)\n<b> Entre com o valor da impedância 2 (forma retangular)\n<c> Apresentar impedância equivalente\n<r> Retornar ao menu principal\n");
                fflush(stdin);
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A': // Solicita o valor da impedancia 1
                    printf("\nInforme o valor da impedância 1 (forma retangular Z=R+jX)\nDigite o valor de R e confirme com a tecla Enter: ");
                    while(scanf("%f", &R1) != 1) // Armazena a parte real da impedancia
                    {
                        printf("\nInforme um valor válido!\nR: ");
                        fflush(stdin);
                    }
                    printf("Digite o valor de X e confirme com a tecla Enter: ");
                    while(scanf("%f", &X1) != 1) // Armazena a parte imaginária da impedância
                    {
                        printf("\nInforme um valor válido!\nX: ");
                        fflush(stdin);
                    }
                    break;

                case 'B': // Solicita o valor da impedancia 2
                    printf("\nInforme o valor da impedância 2 (forma retangular Z=R+jX)\nDigite o valor de R e confirme com a tecla Enter: ");
                    while(scanf("%f", &R2) != 1)
                    {
                        printf("\nInforme um valor válido!\nR: ");
                        fflush(stdin);
                    }
                    printf("Digite o valor de X e confirme com a tecla Enter: ");
                    while(scanf("%f", &X2) != 1) // Armazena a parte imaginária da impedância
                    {
                        printf("\nInforme um valor válido!\nX: ");
                        fflush(stdin);
                    }
                    break;

                case 'C': // Apresenta o valor da impedancia equivalente
                    printf("\n A impedância equivalente Zeq = %g + %gi Ohms\n", (R1+R2), (X1+X2));
                    system("pause");
                    break;
                        
                default:
                    if(user_sub_selection != 'R')
                    {
                         printf("Opção inválida.");
                         system("sleep 1");
                    }
                    break;
                        
                }
            }
            while (user_sub_selection != 'R');
            break;  // Fim do submenu de impedância série

        case 'B':   // Início do submenu de impedância em paralelo
            do
            {
                fflush(stdin);
                system("cls");
                printf("ASSOCIAÇÃO DE IMPEDÂNCIAS EM PARALELO\nDigite:\n<a> Entre com o valor da impedância 1 (forma polar)\n<b> Entre com o valor da impedância 2 (forma polar)\n<c> Apresentar impedância equivalente\n<r> Retornar ao menu principal\n");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A': // Solicita o valor da impedância 1
                    
                    break;

                case 'B': // Solicita o valor da impedância 2

                    break;

                case 'C': // Apresenta o resultado equivalente

                    break;
                
                default:
                    if(user_sub_selection != 'R')
                    {
                        printf("Opção Inválida.");
                        system("sleep 1");
                    }
                    break;
                }
            }
            while(user_sub_selection != 'R');  // Se o usuário digitar 'r', volta ao menu principal
            break;  // Fim do submenu de impedância em paralelo

        case 'C':   // Início do submenu de cálculo de reatâncias
            do
            {
                fflush(stdin);
                system("cls");
                printf("CÁLCULO DE REATÂNCIAS\nDigite:\n<a> Para calcular a reatância capacitiva\n<b> Para calcular a reatância indutiva\n<r> Retornar ao menu principal\n");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A':   // Cálculo da reatância capacitiva
                    printf("Informe o valor da frequência em Hertz e confirme com a tecla Enter.\nF= ");
                    while(scanf("%f", &freq) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor correto para a frequência.\nF=");
                    }
                    fflush(stdin);
                    printf("Informe o valor do capacitor em Faradays e confirme com a tecla Enter.\nC= ");
                    while(scanf("%f", &C) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor correto para a capacitância.\nC=");
                    }
                    printf("\nReatância capacitiva\n\t Xl= %.6fi \n", 1/(2*PI*freq*C));
                    system("pause");
                    break;   // Fim do cálculo da reatância capacitiva

                case 'B':   // Cálculo da reatência indutiva
                    printf("Informe o valor da frequência (Hz) e confirme com a tecla Enter\nF= ");
                    while(scanf("%f", &freq) != 1)
                    {
                        fflush(stdin);
                        printf("Informe um valor correto para a frequência.\nF=");
                    }
                    printf("Informe o valor do indutor (H) e confirme com a tecla Enter\nL= ");
                    fflush(stdin);
                    while(scanf("%f", &L) != 1)
                    {
                        fflush(stdin);
                        printf("Informe um valor correto para a indutância.\nL=");
                    }
                    printf("Reatância Indutiva\n\tXl=%.3fi Ohms \n", (2*PI*freq*L));
                    system("pause");
                    break; // Fim do cálculo da reatância indutiva
                        
                    default:
                        if(user_sub_selection != 'R')
                        {
                            printf("Opção inválida");
                            system("sleep 1");
                        }
                        break;
                }
            }
            while(user_sub_selection != 'R');  // Se o usuário digitar 'r' volta ao menu principal
            break;  // Fim do submenu de cálculo de reatâncias

            case 'D': // Conversão de Impedâncias
                do
                {
                    system("cls");
                    printf("CONVERSÃO DE IMPEDÂNCIAS\nDigite:\n<a> Conversão polar -> retangular\n<b> Conversão retangular -> polar\n<r> Para retornar ao menu principal."); 
                    user_sub_selection = toupper(getch());
                }
                while(user_sub_selection != 'R');
                break; // Fim do submenu de conversão de impedâncias
        case 'E':   // Divisor de Tensão
            do
            {
                system("cls");
                printf("DIVISOR DE TENSÃO\nDigite:\n<a> Para definir a tensão da fonte\n<b> Para definir o valor da impedância Z1\n<c> Para definir o valor da impedância Z2\n<r> Para retornar ao menu principal\n");
                user_sub_selection = toupper(getch());

            }
            while(user_sub_selection != 'R');
            break;  // Fim do divisor de tensão

        default:
            if(user_selection != 'S')
            {
                printf("Opção inválida, tente novamente.\n");
                system("sleep 1");  // Aguarda 1 segundo antes de sair
            }
            break;
        }   // Fim dos submenus
    }   // Fim do menu principal
    return 0;
}
