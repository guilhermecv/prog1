/**
 *	Programação de Computadores 1
 *	Tarefa 2 - Controle de estoque
 *	Autor: Guilherme Camargo Valese
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_VALUE   100
#define INITIAL_POSITION 5

struct cadastro
{
    char cervejaria[30];
    char nome[30];
    char validade[10];
    float valor;
    int qtd;
};

void clear_memory(struct cadastro *);
int position_free(struct cadastro *);
void list_memory(struct cadastro *);
void new_product(struct cadastro *);
void del_product(struct cadastro *);
void verify_validity(struct cadastro *);
void change_product(struct cadastro *);

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_sel; // Variável de controle
    struct cadastro bar[MAX_VALUE] = {{"Kairos","Boitata", "10/07/2019", 12.00, 80},
        {"Wals","Tripel", "20/11/2019", 15.00, 50},
        {"Seasons","Moosaic", "01/02/2020", 22.50, 70},
        {"Brewdog","Punk Ipa", "19/07/2019", 21.00, 80},
        {"Basecamp","IPL", "05/07/2020", 45.00, 40}
    };
    clear_memory(bar);
    struct tm * timeinfo;
    time_t rawtime;
    time(&rawtime);
    timeinfo = localtime (&rawtime);

    char sys_date[30];
    char sys_date_temp[5];
    char validade[] = "10/08/2019";

    /** Teste com a data */
    if(timeinfo->tm_mday < 10)
        strcat(sys_date, "0");
    itoa(timeinfo->tm_mday, sys_date_temp, 10);
    strcat(sys_date, sys_date_temp);
    strcat(sys_date, "/");
    if(timeinfo->tm_mon < 10)
        strcat(sys_date, "0");
    itoa(timeinfo->tm_mon+2, sys_date_temp, 10);
    strcat(sys_date, sys_date_temp);
    strcat(sys_date, "/");
    itoa(timeinfo->tm_year+1900, sys_date_temp, 10);
    strcat(sys_date, sys_date_temp);

    printf(" %d", strcmp(sys_date, validade));
    printf("Data: %s", sys_date);
    system("pause");

    while(1)
    {
        system("cls");
        if(timeinfo->tm_mday < 10)
            printf("0%d/", timeinfo->tm_mday);
        else
            printf("%d/", timeinfo->tm_mday);
        if(timeinfo->tm_mon < 10)
            printf("0%d", timeinfo->tm_mon+1);
        else
            printf("%d", timeinfo->tm_mon+1);
        printf("/%d\n", timeinfo->tm_year+1900);

       // printf ("%s", asctime(timeinfo));
        printf("\nDigite:\n<1> Listar as cervejas em estoque\n<2> Cadastrar novo produto\n<3> Interromper a venda de um produto\n<4> Alterar um item no estoque\n<5> Verificar vencimento proximo\n<S> Para sair do programa\n");
        user_sel = toupper(getch());
        switch (user_sel)
        {
        case '1':   // Listar as cervejas em estoque
            list_memory(bar);
            system("pause");
            break;
        case '2':   // Novo cadastro
            new_product(bar);
            break;

        case '3':   // Interromper venda
            del_product(bar);
            break;

        case '4':   // Alterar informações do produto
            change_product(bar);
            break;

        case '5':   // Verificar vencimento próximo
            verify_validity(bar);
            break;

        case 'S':   // Sair do programa
            return 0;
            break;

        default:
            printf("\nOpcao inválida\n");
            system("pause");
            break;
        }
    }
    return 0;
}

/**
 * @brief Apaga todas as posições não utilizadas
 */
void clear_memory(struct cadastro *bar_ptr)
{
    int i;
    for (i=INITIAL_POSITION; i<=MAX_VALUE; i++)
    {
        (bar_ptr+i)->cervejaria[0] = '\0';
    }
}

/**
 * @brief Encontra uma posição não utilizada
 */
int position_free(struct cadastro *bar_ptr)
{
    int pos = 0;
    while((bar_ptr+pos)->cervejaria[0] != '\0')
        pos++;
    return pos;
}

/**
 * @brief Lista os produtos cadastrados
 */
void list_memory(struct cadastro *bar_ptr)
{
    int i=0;
    for(i=0; i< MAX_VALUE; i++)
    {
        if((bar_ptr+i)->cervejaria[0] != '\0')
        {
            printf("\nID: %d ", i);
            printf("%s ", (bar_ptr+i)->cervejaria);
            printf("%s ", (bar_ptr+i)->nome);
            printf("%s ", (bar_ptr+i)->validade);
            printf("%.2f ",(bar_ptr+i)->valor);
            printf("%d", (bar_ptr+i)->qtd);
        }
    }
    printf("\n");
}

/**
 * @brief Cadastra um novo produto em uma posição livre
 */
void new_product(struct cadastro *bar_ptr)
{
    char user_sel;
    float temp_value;
    int temp_qtd;
    while(1)
    {
        int pos = position_free(bar_ptr);
        fflush(stdin);
        printf("Digite o nome da cervejaria: ");
        gets((bar_ptr+pos)->cervejaria);
        printf("Digite o nome da cerveja: ");
        gets((bar_ptr+pos)->nome);
        printf("Informe a validade (dd/mm/aaaa): ");
        gets((bar_ptr+pos)->validade);
        printf("Informe o valor do produto: ");
        scanf("%f", &temp_value);
        (bar_ptr+pos)->valor = temp_value;
        printf("Informe a quantidade em estoque: ");
        scanf("%d", &temp_qtd);
        (bar_ptr+pos)->qtd = temp_qtd;
        printf("\nDigite 'S' para realizar um novo cadastro.");
        user_sel = toupper(getch());
        if(user_sel != 'S')
            break;
    }
}

/**
 * @brief Exclui um produto do estoque
 */
void del_product(struct cadastro *bar_ptr)
{
    int del_position = 0;
    list_memory(bar_ptr);
    printf("\nInforme o ID do produto que deseja excluir: ");
    while(scanf("%d", &del_position) != 1)
    {
        fflush(stdin);
        printf("\nInforme um ID válido.");
    }
    if(del_position >= MAX_VALUE)
    {
        printf("\nID não encontrado, tente novamente: ");
        system("pause");
    }
    else
    {
        (bar_ptr+del_position)->cervejaria[0] = '\0';
        printf("Produto deletado!\n");
        system("pause");
    }
}

/**
 * @brief Verifica a validade dos produtos em estoque
 */
void verify_validity(struct cadastro *bar_ptr)
{
    int i=0;
    printf("Produtos próximos do vencimento:");
    for(i=0; i<MAX_VALUE; i++)
    {

    }
    system("pause");
}

/**
 * @brief Altera o valor ou quantidade de um produto em estoque
 */
void change_product(struct cadastro *bar_ptr)
{
    char user_sel, user_sub_sel;
    float temp_value;
    int temp_qtd, pos;
    do
    {
        system("cls");
        printf("\nALTERAÇÃO DE CADASTRO\nDigite:\n<1> Para alterar o valor\n<2> Para alterar a quantidade em estoque\n<S> Para retornar ao menu principal");
        user_sel = toupper(getch());
        switch (user_sel)
        {
        case '1':   // Altera o valor de venda
            system("cls");
            list_memory(bar_ptr);
            printf("\nAlteração de valor, digite o ID do produto:");
            while(scanf("%d", &pos) != 1)
            {
                fflush(stdin);
                printf("\nInforme um ID válido:");
            }
            while(pos >= MAX_VALUE)
            {
                fflush(stdin);
                printf("\nID não encontrado, tente novamente: ");
                scanf("%d", &pos);
            }
            printf("Informe o novo valor: ");
            scanf("%f", &temp_value);
            printf("Digite 'S' para confirmar alteração no valor de %.2f para %.2f", bar_ptr[pos].valor, temp_value);
            user_sub_sel = toupper(getch());
            if(user_sub_sel == 'S')
            {
                (bar_ptr+pos)->valor = temp_value;
                printf("\nOperação concluída.\n");
                system("pause");
            }
            else
            {
                printf("\nOperação cancelada pelo usuário.\n");
                system("pause");
            }

            break;

        case '2':   // Altera a quantidade em estoque
            system("cls");
            list_memory(bar_ptr);
            printf("\nAlteração de estoque, digite o ID do produto:");
            scanf("%d", &pos);
            printf("Informe a nova quantidade: ");
            scanf("%d", &temp_qtd);
            (bar_ptr+pos)->qtd = temp_qtd;
            break;

        default:
            if(user_sel != 'S')
            {
                printf("\nOpção inválida.");
                system("pause");
            }
            break;
        }
    }
    while(user_sel != 'S');
}
