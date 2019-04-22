/**
 *  IFSC Campus Florian�polis
 *  Programa��o de Computadores 1 (Eng. Eletr�nica)
 *  Tarefa 1 - Calculadora b�sica de corrente alternada
 *  Autor: Guilherme Camargo Valese
 *
 *  Obs: Este programa � compilado somente no Windows
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

#define PI 3.141592654

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_selection, user_sub_selection; // Vari�veis de controle
    float R1, R2, X1, X2; // Armazena parte real e imagin�ria das imped�ncias

    //Vari�veis utilizadas para a op��o 'c' (c�lculo de reat�ncias)
    float Xl, Xc, C, L, freq;

    while(user_selection != 's')
    {
        system("cls");
        printf("     MENU PRINCIPAL\nDigite:\n<a> Associa��o de imped�ncias em S�rie\n<b> Associa��o de imped�ncias em Paralelo\n<c> C�lculo de reat�ncias\n<d> Conversor de imped�ncias P->R e R->P\n<e> Divisor de tens�o\n<f> Divisor de corrente\n<s> Sair\n");
        user_selection = getch();
        switch (user_selection)
        {
        case 'a':   // Submenu Associa��o de imped�ncias em s�rie
            do
            {
                system("cls");
                printf("ASSOCIA��O DE IMPED�NCIAS EM S�RIE\nDigite:\n<a> Entre com o valor da imped�ncia 1 (forma retangular)\n<b> Entre com o valor da imped�ncia 2 (forma retangular)\n<c> Apresentar imped�ncia equivalente\n<r> Retornar ao menu principal\n");
                user_sub_selection = getch();
                switch (user_sub_selection)
                {
                case 'a': // Solicita o valor da impedancia 1
                    printf("\nInforme o valor da imped�ncia 1 (forma retangular Z=R+jX)\nDigite o valor de R e confirme com a tecla Enter: ");
                    while(scanf("%f", &R1) != 1) // Armazena a parte real da impedancia
                    {
                        printf("\nInforme um valor v�lido!");
                        fflush(stdin);
                    }
                    printf("Digite o valor de X e confirme com a tecla Enter: ");
                    while(scanf("%f", &X1) != 1) // Armazena a parte imagin�ria da imped�ncia
                    {
                        printf("\nInforme um valor v�lido!");
                        fflush(stdin);
                    }
                    break;

                case 'b': // Solicita o valor da impedancia 2
                    printf("\nInforme o valor da imped�ncia 2 (forma retangular Z=R+jX)\nDigite o valor de R e confirme com a tecla Enter: ");
                    while(scanf("%f", &R2) != 1)
                    {
                        printf("\nInforme um valor v�lido!");
                        fflush(stdin);
                    }
                    printf("Digite o valor de X e confirme com a tecla Enter: ");
                    while(scanf("%f", &X2) != 1) // Armazena a parte imagin�ria da imped�ncia
                    {
                        printf("\nInforme um valor v�lido!");
                        fflush(stdin);
                    }
                    break;

                case 'c': // Apresenta o valor da impedancia equivalente
                    printf("\n A imped�ncia equivalente Zeq = %g + %gi Ohms\n Pressione qualquer tecla para prosseguir . . .", (R1+R2), (X1+X2));
                    getch(); // Aguarda alguma tecla ser pressionada para sair
                    break;

                }
            }
            while (user_sub_selection != 'r');

            break;  // Fim do submenu de imped�ncia s�rie

        case 'b':   // In�cio do submenu de imped�ncia em paralelo
            do
            {
                fflush(stdin);
                system("cls");
                printf("ASSOCIA��O DE IMPED�NCIAS EM PARALELO\nDigite:\n<a> Entre com o valor da imped�ncia 1 (forma polar)\n<b> Entre com o valor da imped�ncia 2 (forma polar)\n<c> Apresentar imped�ncia equivalente\n<r> Retornar ao menu principal\n");

                printf("\nAINDA EM IMPLEMENTA��O . . .");

                user_sub_selection = getch();
                switch (user_sub_selection)
                {
                case 'a': // Solicita o valor da imped�ncia 1

                    break;

                case 'b': // Solicita o valor da imped�ncia 2

                    break;

                case 'c': // Apresenta o resultado equivalente

                    break;
                }
            }
            while(user_sub_selection != 'r');  // Se o usu�rio digitar 'r', volta ao menu principal
            break;  // Fim do submenu de imped�ncia em paralelo

        case 'c':   // In�cio do submenu de c�lculo de reat�ncias
            do
            {
                fflush(stdin);
                system("cls");
                printf("C�LCULO DE REAT�NCIAS\nDigite:\n<a> Para calcular a reat�ncia capacitiva\n<b> Para calcular a reat�ncia indutiva\n<r> Retornar ao menu principal\n");
                user_sub_selection = getch();
                switch (user_sub_selection)
                {
                case 'a':   // C�lculo da reat�ncia capacitiva
                    printf("Informe o valor da frequ�ncia em Hertz e confirme com a tecla Enter.\nF= ");
                    while(scanf("%f", &freq) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor correto para a frequ�ncia.\nF=");
                    }
                    fflush(stdin);
                    printf("Informe o valor do capacitor em Faradays e confirme com a tecla Enter.\nC= ");
                    while(scanf("%f", &C) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor correto para a capacit�ncia.\nC=");
                    }
                    printf("\nReat�ncia capacitiva\n\t Xl= %.6fi \nPressione qualquer tecla para prosseguir . . .", 1/(2*PI*freq*C));
                    getch(); // Aguarda alguma tecla ser pressionada para sair
                    break;   // Fim do c�lculo da reat�ncia capacitiva

                case 'b':   // C�lculo da reat�ncia indutiva
                    printf("Informe o valor da frequ�ncia (Hz) e confirme com a tecla Enter\nF= ");
                    while(scanf("%f", &freq) != 1)
                    {
                        fflush(stdin);
                        printf("Informe um valor correto para a frequ�ncia.\nF=");
                    }
                    printf("Informe o valor do indutor (H) e confirme com a tecla Enter\nL= ");
                    fflush(stdin);
                    while(scanf("%f", &L) != 1)
                    {
                        fflush(stdin);
                        printf("Informe um valor correto para a indut�ncia.\nL=");
                    }
                    printf("Reat�ncia Indutiva\n\tXl=%.3fi Ohms \n Pressione qualquer tecla para prosseguir . . .", (2*PI*freq*L));
                    getch();
                    break; // Fim do c�lculo da reat�ncia indutiva
                }
            }
            while(user_sub_selection != 'r');  // Se o usu�rio digitar 'r' volta ao menu principal
            break;  // Fim do submenu de c�lculo de reat�ncias

        case 'e':   // Divisor de Tens�o
            do
            {
                system("cls");
                printf("DIVISOR DE TENS�O\nDigite:\n<a> Para definir a tens�o da fonte\n<b> Para definir o valor da imped�ncia Z1\n<c> Para definir o valor da imped�ncia Z2\n<r> Para retornar ao menu principal\n");
                user_sub_selection = getch();

            }
            while(user_sub_selection != 'r');
            break;  // Fim do divisor de tens�o

        default:
            if(user_selection != 's')
            {
                printf("Op��o inv�lida, tente novamente.");
                system("sleep 1");  // Aguarda 1 segundo antes de sair
            }
            break;
        }   // Fim dos submenus
    }   // Fim do menu principal
    return 0;
}
