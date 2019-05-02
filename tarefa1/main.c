/**
 * @brief Calculadora básica de corrente alternada
 *
 * @author Guilherme Camargo Valese
 *
 */

#include <complex.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>    // Utilizada para 'Sleep()'

/** CORRIGIR AS VARIÁVEIS (NÃO UTILIZAR STRUCT!!!) */

#define PI 3.14159265   // Talvez utilizar M_PI definido em 'math.h'

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_selection, user_sub_selection;                    // Variáveis de controle do menu e submenu

    float C, L, freq;                                           // Variáveis utilizadas para a opção 'c' (cálculo de reatâncias)
    float z_mod_temp, z_ang_temp, z_real_temp, z_imag_temp;     // Variáveis temporárias
    double complex z1,z2;                                       // Armazena as impedâncias Z1 e Z2 na forma complexa

    while(1)
    {
        system("cls");
        printf("     MENU PRINCIPAL\nDigite:\n<a>Associação de impedâncias em Série\n<b> Associação de impedâncias em Paralelo\n<c> Cálculo de reatâncias\n<d> Conversor de impedâncias P->R e R->P\n<e> Divisor de tensão\n<f> Divisor de corrente\n<s> Sair\n");
        fflush(stdin);
        user_selection = toupper(getch());  // passa para letra maiúscula o que for digitado
        switch (user_selection)
        {
        case 'A':   /** Impedâncias em série */
            do
            {
                system("cls");
                printf("ASSOCIAÇÃO DE IMPEDÂNCIAS EM SÉRIE\nDigite:\n<a> Entre com o valor da impedância 1 (forma retangular)\n<b> Entre com o valor da impedância 2 (forma retangular)\n<c> Apresentar impedância equivalente\n<r> Para retornar ao menu principal\n");
                fflush(stdin);
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A': // Solicita o valor da impedancia 1
                    printf("\nInforme o valor da impedância 1 (forma retangular Z=R+jX)\nDigite o valor de R e confirme com a tecla Enter: ");
                    while(scanf("%f", &z_real_temp) != 1) // Armazena a parte real da impedancia
                    {
                        printf("\nInforme um valor válido!\nR: ");
                        fflush(stdin);
                    }
                    printf("Digite o valor de X e confirme com a tecla Enter: ");
                    while(scanf("%f", &z_imag_temp) != 1) // Armazena a parte imaginária da impedância
                    {
                        printf("\nInforme um valor válido!\nX: ");
                        fflush(stdin);
                    }
                    z1 = z_real_temp + z_imag_temp * I;
                    break;

                case 'B': // Solicita o valor da impedancia 2
                    printf("\nInforme o valor da impedância 2 (forma retangular Z=R+jX)\nDigite o valor de R e confirme com a tecla Enter: ");
                    while(scanf("%f", &z_real_temp) != 1)
                    {
                        printf("\nInforme um valor válido!\nR: ");
                        fflush(stdin);
                    }
                    printf("Digite o valor de X e confirme com a tecla Enter: ");
                    while(scanf("%f", &z_imag_temp) != 1) // Armazena a parte imaginária da impedância
                    {
                        printf("\nInforme um valor válido!\nX: ");
                        fflush(stdin);
                    }
                    z2 = z_real_temp + z_imag_temp * I;
                    break;

                case 'C': // Apresenta o valor da impedancia equivalente
                    printf("\n A impedância equivalente Zeq = %g %+gi Ohms\n", creal(z1+z2), cimag(z1+z2));
                    system("pause");
                    break;

                case 'R':
                    continue;
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

        case 'B':   /** Impedâncias em paralelo (FINALIZAR !!!) */
            do
            {
                fflush(stdin);
                system("cls");
                printf("ASSOCIAÇÃO DE IMPEDÂNCIAS EM PARALELO\nDigite:\n<a> Entre com o valor da impedância 1 (forma polar)\n<b> Entre com o valor da impedância 2 (forma polar)\n<c> Apresentar impedância equivalente\n<r> Para retornar ao menu principal\n");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A': // Solicita o valor da impedância 1
                   /* printf("Informe o valor da impedância Z1\n->Módulo: ");
                    while(scanf("%f", &z_mod_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor correto para o módulo: ");
                    }
                    printf("->Ângulo (em graus): ");
                    while(scanf("%f", &z_ang_temp) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor correto para o ângulo: ");
                    }*/
                    break;

                case 'B': // Solicita o valor da impedância 2
                /*    printf("Informe o valor da impedância Z2\n->Módulo: ");
                    while(scanf("%f", &z_mod_2) != 1)
                    {
                        fflush(stdin);
                        printf("Informe um valor correto para o módulo");
                    }
                    printf("->Ângulo (em graus): ");
                    while(scanf("%f", &z_ang_2) != 1)
                    {
                        fflush(stdin);
                        printf("\nInforme um valor correto para o ângulo: ");
                    }*/
                    break;

                case 'C': // Apresenta o resultado equivalente
                 /*   z.ang_1 = z.ang_1*PI/180;           // Converte graus para radianos
                    z.ang_2 = z.ang_2*PI/180;           // Converte graus para radianos
                    z.real_1 = z.mod_1*cos(z.ang_1);    // Obtem a parte real de Z1
                    z.imag_1 = z.mod_1*sin(z.ang_1);    // Obtem a parte imaginária de Z1
                    z.real_2 = z.mod_2*cos(z.ang_2);    // Obtem a parte real de Z2
                    z.imag_2 = z.mod_2*sin(z.ang_2);    // Obtem a parte imaginária de Z2

                    z.mod_1 = (z.mod_1*z.mod_2)/(sqrt(pow((z.real_1+z.real_2),2)+pow((z.imag_1+z.imag_2),2)));   // Divide os módulos
                    z.ang_temp = atan((z.real_1*z.real_2)/(z.imag_1*z.imag_2));    // Obtem o angulo da impedância
                    z.ang_1 = ((z.ang_1+z.ang_2)-z.ang_temp)*180/PI;               // Obtem o angulo resultante

                    printf("\nA impedância equivalente vale\n\tZeq = %g|_%-g \n", z.mod_1, z.ang_1);*/
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
                printf("CÁLCULO DE REATÂNCIAS\nDigite:\n<a> Para calcular a reatância capacitiva\n<b> Para calcular a reatância indutiva\n<r> Para retornar ao menu principal\n");
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
                    printf("\nReatância capacitiva\n\t Xc= %.6fi Ohms \n\n", 1/(2*PI*freq*C));
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
                    printf("\nReatância Indutiva\n\tXl=%.3fi Ohms \n\n", (2*PI*freq*L));
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
                printf("CONVERSÃO DE IMPEDÂNCIAS\nDigite:\n<a> Conversão polar -> retangular\n<b> Conversão retangular -> polar\n<r> Para retornar ao menu principal\n");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
                case 'A':
                    printf("\n\nConversão de forma polar para retangular\nInforme o módulo da impedância: ");
                    while(scanf("%f", &z_mod_temp) != 1)
                    {
                        printf("\nInforme um valor válido para o módulo da impedância: ");
                        fflush(stdin);
                    }
                    printf("Informe o valor do ângulo da impedância (em graus): ");
                    while(scanf("%f", &z_ang_temp) != 1)
                    {
                        printf("\nInforme um valor válido para o ângulo da impedância: ");
                        fflush(stdin);
                    }
                    z_ang_temp = z_ang_temp*PI/180;              // Converte graus para radianos
                    z_real_temp = z_mod_temp*cos(z_ang_temp);    // Obtem a parte real
                    z_imag_temp = z_mod_temp*sin(z_ang_temp);    // Obtem a parte imaginária

                    printf("\nA impedância vale %.3f %+.3fi na forma retangular.\n", z_real_temp, z_imag_temp);
                    system("pause");
                    break;
                case 'B':
                    printf("\n\nConversão de forma retangular para polar\nInforme a parte real da impedância e confirme com enter: ");
                    while(scanf("%f", &z_real_temp) != 1)
                    {
                        printf("\nInforme um valor válido para a parte real da impedância: ");
                        fflush(stdin);
                    }
                    printf("Informe o valor da parte imaginária da impedância e confirme com enter: ");
                    while(scanf("%f", &z_imag_temp) != 1)
                    {
                        printf("\nInforme um valor válido para a parte imaginária da impedância: ");
                        fflush(stdin);
                    }
                    z_mod_temp = sqrt(pow(z_real_temp,2)+pow(z_imag_temp,2));    // Obtem o módulo da impedância
                    z_ang_temp = atan(z_real_temp/z_imag_temp);                  // Obtem o angulo da impedância
                    z_ang_temp = z_ang_temp*180/PI;                           // Converte para graus
                    printf("\nA impedancia na forma polar vale Z=%.3f|_%-.3f\n", z_mod_temp, z_ang_temp);
                    system("pause");    // Aguarda o usuário pressionar alguma tecla para voltar ao submenu
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

        case 'E':   /** Divisor de Tensão (FINALIZAR) */
            do
            {
                system("cls");
                printf("DIVISOR DE TENSÃO\nDigite:\n<a> Para definir a tensão da fonte\n<b> Para definir o valor das impedâncias Z1 e Z2\n<c> Para apresentar o resultado\n<r> Para retornar ao menu principal\n");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {

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

        case 'F':   /** Divisor de corrente (FINALIZAR) */
            do
            {
                system("cls");
                printf("DIVISOR DE CORRENTE\nDigite:\n<r> Para retornar ao menu principal");
                user_sub_selection = toupper(getch());
                switch (user_sub_selection)
                {
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

        case 'S':   // Encerra a execução do programa se o usuário digitar 'R'
            return 0;
            break;

        default:    // Se o usuário digitar algo diferente do especificado, informa que esta opção é inválida
            printf("Opção inválida, tente novamente.\n");
            Sleep(500);    // Aguarda 500 ms
            break;
        }
    }
    return 0;
}
