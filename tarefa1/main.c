/**
 * IFSC Câmpus Florianópolis
 * Programação de Computadores 1 (Eng. Eletrônica)
 * Tarefa 1 - Calculadora básica de corrente alternada
 * Professor: Marco Villaça
 * Aluno: Guilherme Camargo Valese
 */
#include <complex.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>    // Utilizada para 'Sleep()'

#define PI 3.14159265

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_selection, user_sub_selection;             // Variáveis de controle do menu e submenu
    float C, L, freq;                                    // Variáveis utilizadas para a opção 'c' (cálculo de reatâncias)
    float mod_temp, ang_temp, real_temp, imag_temp;      // Variáveis temporárias
    double complex z1,z2,v,i,vout,iout;

    while(1)
    {
        system("cls");  // Limpa a tela
        printf("------------- MENU PRINCIPAL -------------\n"
               "Digite e letra correspondente:\n"
               "<a> Associação de impedâncias em Série\n"
               "<b> Associação de impedâncias em Paralelo\n"
               "<c> Cálculo de reatâncias\n"
               "<d> Conversor de impedâncias P->R e R->P\n"
               "<e> Divisor de tensão\n"
               "<f> Divisor de corrente\n"
               "<s> Sair\n");   // Exibe o menu principal
        fflush(stdin);
        user_selection = toupper(getch());  // passa para letra maiúscula o que for digitado
        switch (user_selection)
        {
        case 'A':   /** Impedâncias em série */
            do
            {
                system("cls");
                printf("ASSOCIAÇÃO DE IMPEDÂNCIAS EM SÉRIE\n"
                       "Digite:\n"
                       "<a> Entre com o valor da impedância 1 (forma retangular)\n"
                       "<b> Entre com o valor da impedância 2 (forma retangular)\n"
                       "<c> Apresentar impedância equivalente\n"
                       "<r> Para retornar ao menu principal\n");
                fflush(stdin);
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A': // Solicita o valor da impedancia 1
                    printf("\nInforme o valor da impedância 1 (forma retangular Z=R+jX)\nDigite o valor de R e confirme com a tecla Enter: ");
                    while(scanf("%f", &real_temp) != 1) // Armazena a parte real da impedancia
                    {
                        printf("\nInforme um valor válido!\nR: ");
                        fflush(stdin);
                    }
                    printf("Digite o valor de X e confirme com a tecla Enter: ");
                    while(scanf("%f", &imag_temp) != 1) // Armazena a parte imaginária da impedância
                    {
                        printf("\nInforme um valor válido!\nX: ");
                        fflush(stdin);
                    }
                    z1 = real_temp + imag_temp * I;     // Forma a impedância Z1
                    break;

                case 'B': // Solicita o valor da impedancia 2
                    printf("\nInforme o valor da impedância 2 (forma retangular Z=R+jX)\nDigite o valor de R e confirme com a tecla Enter: ");
                    while(scanf("%f", &real_temp) != 1)
                    {
                        printf("\nInforme um valor válido!\nR: ");
                        fflush(stdin);
                    }
                    printf("Digite o valor de X e confirme com a tecla Enter: ");
                    while(scanf("%f", &imag_temp) != 1) // Armazena a parte imaginária da impedância
                    {
                        printf("\nInforme um valor válido!\nX: ");
                        fflush(stdin);
                    }
                    z2 = real_temp + imag_temp * I;     // Forma a impedância Z2
                    break;

                case 'C': // Apresenta o valor da impedancia equivalente
                    printf("\n A impedância equivalente Zeq = %g %+gi Ohms\n", creal(z1+z2), cimag(z1+z2));
                    system("pause");
                    break;

                default:
                    if(user_sub_selection != 'R')
                    {
                        printf("Opção inválida.");
                        Sleep(1000);
                    }
                    break;
                }
            }
            while (user_sub_selection != 'R');
            break;  /** Fim do submenu de impedância série */

        case 'B':   /** Impedâncias em paralelo */
            do
            {
                fflush(stdin);
                system("cls");
                printf("ASSOCIAÇÃO DE IMPEDÂNCIAS EM PARALELO\n"
                       "Digite:\n"
                       "<a> Entre com o valor da impedância 1 (forma retângular)\n"
                       "<b> Entre com o valor da impedância 2 (forma retângular)\n"
                       "<c> Apresentar impedância equivalente\n"
                       "<r> Para retornar ao menu principal\n");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A': // Solicita o valor da impedância 1
                    printf("Informe o valor da impedância Z1\n->Parte real: ");
                    while(scanf("%f", &real_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    printf("->Parte imaginária: ");
                    while(scanf("%f", &imag_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    z1 = real_temp + imag_temp * I;     // Forma a impedância Z1
                    break;

                case 'B': // Solicita o valor da impedância 2
                    printf("Informe o valor da impedância Z2\n->Parte real: ");
                    while(scanf("%f", &real_temp) != 1)
                    {
                        fflush(stdin);
                        printf("Informe um valor válido: ");
                    }
                    printf("->Parte imaginária: ");
                    while(scanf("%f", &imag_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    z2 = real_temp + imag_temp * I;     // Forma a impedância Z2
                    break;

                case 'C': // Apresenta o resultado equivalente
                    printf("\nA impedancia equivalente vale %g %+gi Ohms\n", creal((z1*z2)/(z1+z2)), cimag((z1*z2)/(z1+z2)));
                    system("pause");
                    break;

                default:
                    if(user_sub_selection != 'R')
                    {
                        printf("Opção Inválida.");
                        Sleep(1000);
                    }
                    break;
                }
            }
            while(user_sub_selection != 'R'); // Se o usuário digitar 'R', volta ao menu principal
            break;  /** Fim do submenu de impedância em paralelo */

        case 'C':   /** Cálculo de reatâncias */
            do
            {
                fflush(stdin);
                system("cls");
                printf("CÁLCULO DE REATÂNCIAS\n"
                       "Digite:\n"
                       "<a> Para calcular a reatância capacitiva\n"
                       "<b> Para calcular a reatância indutiva\n"
                       "<r> Para retornar ao menu principal\n");
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
                    printf("\nReatância capacitiva\n\t Xc = %gi Ohms \n\n", 1/(2*PI*freq*C));
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
                    printf("\nReatância Indutiva\n\tXl = %gi Ohms \n\n", (2*PI*freq*L));
                    system("pause");
                    break; // Fim do cálculo da reatância indutiva

                default:
                    if(user_sub_selection != 'R')
                    {
                        printf("Opção inválida");
                        Sleep(1000);
                    }
                    break;
                }
            }
            while(user_sub_selection != 'R'); // Se o usuário digitar 'R' volta ao menu principal
            break;  /** Fim do submenu de cálculo de reatâncias */

        case 'D': /** Conversão de Impedâncias */
            do
            {
                system("cls");
                printf("CONVERSÃO DE IMPEDÂNCIAS\n"
                       "Digite:\n<a> Conversão polar -> retangular\n"
                       "<b> Conversão retangular -> polar\n"
                       "<r> Para retornar ao menu principal\n");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A':
                    printf("\n\nConversão de forma polar para retangular\nInforme o módulo da impedância: ");
                    while(scanf("%f", &mod_temp) != 1)
                    {
                        printf("\nInforme um valor válido para o módulo da impedância: ");
                        fflush(stdin);
                    }
                    printf("Informe o valor do ângulo da impedância (em graus): ");
                    while(scanf("%f", &ang_temp) != 1)
                    {
                        printf("\nInforme um valor válido para o ângulo da impedância: ");
                        fflush(stdin);
                    }
                    ang_temp = ang_temp*PI/180;              // Converte graus para radianos
                    real_temp = mod_temp*cos(ang_temp);    // Obtem a parte real
                    imag_temp = mod_temp*sin(ang_temp);    // Obtem a parte imaginária

                    printf("\nA impedância vale %.3f %+.3fi Ohms na forma retangular.\n", real_temp, imag_temp);
                    system("pause");
                    break;

                case 'B':
                    printf("\n\nConversão de forma retangular para polar\nInforme a parte real da impedância e confirme com enter: ");
                    while(scanf("%f", &real_temp) != 1)
                    {
                        printf("\nInforme um valor válido para a parte real da impedância: ");
                        fflush(stdin);
                    }
                    printf("Informe o valor da parte imaginária da impedância e confirme com enter: ");
                    while(scanf("%f", &imag_temp) != 1)
                    {
                        printf("\nInforme um valor válido para a parte imaginária da impedância: ");
                        fflush(stdin);
                    }
                    mod_temp = sqrt((real_temp*real_temp)+(imag_temp*imag_temp));   // Obtem o módulo da impedância
                    ang_temp = atan(imag_temp/real_temp)*(180/PI);                  // Obtem o argumento da impedância
                    printf("\nA impedancia na forma polar vale \n\tZ = %g|_%-g\n", mod_temp, ang_temp);
                    system("pause");    // Aguarda o usuário pressionar alguma tecla para voltar ao submenu
                    break;
                case 'R':
                    break;

                default:
                    if(user_sub_selection != 'R')
                    {
                        printf("Opção inválida");
                        Sleep(1000);
                    }
                    break;
                }
            }
            while(user_sub_selection != 'R'); // Se o usuário digitar 'R' volta ao menu principal
            break; /** Fim do submenu de conversão de impedâncias */

        case 'E':   /** Divisor de Tensão */
            do
            {
                system("cls");
                printf("DIVISOR DE TENSÃO\n"
                       "Digite:\n"
                       "<a> Para definir a tensão da fonte\n"
                       "<b> Para definir o valor das impedâncias Z1 e Z2\n"
                       "<c> Para apresentar o resultado\n"
                       "<r> Para retornar ao menu principal\n");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A':
                    printf("Informe o valor da fonte na forma polar\n->Módulo: ");
                    while(scanf("%f", &mod_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    printf("->Ângulo: ");
                    while(scanf("%f", &ang_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    ang_temp = (ang_temp*PI)/180;   // Converte para radianos
                    v = mod_temp*cos(ang_temp) + (mod_temp*sin(ang_temp))*I;    // Passa o valor da fonte para retangular
                    break;

                case 'B':
                    printf("Informe o valor da impedância Z1 na forma retangular\n-> Parte real: ");
                    while(scanf("%f", &real_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    printf("-> Parte imaginária: ");
                    while(scanf("%f", &imag_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    z1 = real_temp + imag_temp*I;
                    printf("Informe o valor da impedância Z2 na forma retangular\n-> Parte real: ");
                    while(scanf("%f", &real_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    printf("-> Parte imaginária: ");
                    while(scanf("%f", &imag_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    z2 = real_temp + imag_temp*I;
                    break;

                case 'C':
                    vout = (z1/(z1+z2))*v;   // Calcula a tensão sobre Z1
                    printf("\nA queda de tensão nas impedâncias vale\n\tVZ1 = %g %+gi V", creal(vout), cimag(vout));
                    vout = (z2/(z1+z2))*v;   // Calcula a tensão sobre Z2
                    printf("\n\tVZ2 = %g %+gi V\n
                           ", creal(vout), cimag(vout));
                           system("pause");
                           break;

                       default:
                               if(user_sub_selection != 'R')
                    {
                        printf("Opção inválida");
                            Sleep(1000);
                        }
                    break;
                }
            }
            while(user_sub_selection != 'R'); // Se o usuário digitar 'R' volta ao menu principal
            break;  /** Fim do submenu de divisor de tensão */

        case 'F':   /** Divisor de corrente */
            do
            {
                system("cls");
                printf("DIVISOR DE CORRENTE\nDigite:\n"
                       "<a> Para definir o valor da corrente\n"
                       "<b> Para definir o valor das impedâncias\n"
                       "<c> Para apresentar o resultado\n"
                       "<r> Para retornar ao menu principal\n");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A':
                    printf("Informe o valor da corrente na forma polar\n-> Módulo: ");
                    while(scanf("%f", &mod_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    printf("-> Ângulo: ");
                    while(scanf("%f", &ang_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    ang_temp = (ang_temp*PI)/180;   // Converte para radianos
                    i = mod_temp*cos(ang_temp) + (mod_temp*sin(ang_temp))*I;    // Passa o valor da fonte para retangular
                    break;

                case 'B':
                    printf("Informe o valor da impedância Z1 na forma retangular\n-> Parte real: ");
                    while(scanf("%f", &real_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    printf("-> Parte imaginária: ");
                    while(scanf("%f", &imag_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    z1 = real_temp + imag_temp*I;
                    printf("Informe o valor da impedância Z2 na forma retangular\n-> Parte real: ");
                    while(scanf("%f", &real_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    printf("-> Parte imaginária: ");
                    while(scanf("%f", &imag_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor válido: ");
                    }
                    z2 = real_temp + imag_temp*I;
                    break;

                case 'C':
                    iout = (z2/(z1+z2))*i;  // Calcula a corrente que circula por Z1
                    printf("\nA corrente em cada impedância vale\n\tiZ1 = %g %+gi A", creal(iout), cimag(iout));
                    iout = (z1/(z1+z2))*i;  // Calcula a corrente que circula por Z2
                    printf("\n\tiZ2 = %g %+gi A\n");
                    system("pause");
                    break;

                default:
                    if(user_sub_selection != 'R')
                    {
                        printf("Opção Inválida.");
                        Sleep(1000);
                    }
                    break;
                }
            }
            while(user_sub_selection != 'R'); // Se o usuário digitar 'R' volta ao menu principal
            break;  /** Fim do submenu de divisor de corrente */

        case 'S':   // Encerra a execução do programa se o usuário digitar 'S'
            return 0;
            break;

        default:    // Se o usuário digitar algo diferente do especificado, informa que esta opção é inválida
            printf("Opção inválida, tente novamente.\n");
            Sleep(500);    // Aguarda 500 ms e retorna para o início do laço
            break;
        }
    }
    return 0;
}
