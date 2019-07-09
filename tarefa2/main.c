/**
 *	Programa��o de Computadores 1
 *	Tarefa 2 - Controle de estoque
 *  Professor: Marco Val�rio Miorim Villa�a
 *	Aluno: Guilherme Camargo Valese
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define MAX_VALUE   100         // Limite de posi��es reservadas para cadastro
#define INITIAL_POSITION 5      // Corresponde a posi��o final do cadastro base

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
void display_time();

int main()
{
    setlocale(LC_CTYPE, "portuguese");
    char user_sel; // Vari�vel de controle
    struct cadastro bar[MAX_VALUE] = {{"Kairos","Boitata", "10/07/2019", 12.00, 80},
        {"Wals","Tripel", "20/11/2019", 15.00, 50},
        {"Seasons","Moosaic", "01/02/2020", 22.50, 70},
        {"Brewdog","Punk Ipa", "19/07/2019", 21.00, 80},
        {"Basecamp","IPL", "05/07/2020", 45.00, 40}
    };
    clear_memory(bar);
    while(1)
    {
        system("cls");
        display_time();
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

        case '4':   // Alterar informa��es do produto
            change_product(bar);
            break;

        case '5':   // Verificar vencimento pr�ximo
            verify_validity(bar);
            break;

        case 'S':   // Sair do programa
            return 0;
            break;

        default:
            printf("\nOpcao inv�lida\n");
            system("pause");
            break;
        }
    }
    return 0;
}

/**
 * @brief Apaga as posi��es n�o utilizadas
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
 * @brief Encontra uma posi��o n�o utilizada
 */
int position_free(struct cadastro *bar_ptr)
{
    int pos = 0;
    while((bar_ptr+pos)->cervejaria[0] != '\0')
        pos++;
    if(pos == MAX_VALUE)
        return -1;
    else
        return pos;
}

/**
 * @brief Lista os produtos cadastrados
 */
void list_memory(struct cadastro *bar_ptr)
{
    int i=0;
    for(i=0; i<= MAX_VALUE; i++)
    {
        if((bar_ptr+i)->cervejaria[0] != '\0')
        {
            printf("\n--------- ID %d -----------", i);
            printf("\nCervejaria: %s ", (bar_ptr+i)->cervejaria);
            printf("\nProduto:    %s ", (bar_ptr+i)->nome);
            printf("\nValidade:   %s ", (bar_ptr+i)->validade);
            printf("\nValor       R$ %.2f",(bar_ptr+i)->valor);
            printf("\nEstoque:    %d\n", (bar_ptr+i)->qtd);
        }
    }
    printf("\n");
}

/**
 * @brief Cadastra um novo produto em uma posi��o livre
 */
void new_product(struct cadastro *bar_ptr)
{
    char user_sel;
    float temp_value;
    int temp_qtd, pos;
    while(1)
    {
        pos = position_free(bar_ptr);
        if(pos == -1)
        {
            printf("\nN�o existem posi��es dispon�veis para cadastro\n");
            system("pause");
            break;
        }
        else
        {
            fflush(stdin);
            printf("\nDigite o nome da cervejaria: ");
            gets((bar_ptr+pos)->cervejaria);
            printf("Digite o nome da cerveja: ");
            gets((bar_ptr+pos)->nome);
            printf("Informe a validade (dd/mm/aaaa): ");
            gets((bar_ptr+pos)->validade);
            printf("Informe o valor do produto: ");
            while(scanf("%f", &temp_value) != 1 || temp_value < 0)
            {
                fflush(stdin);
                printf("\nInforme um valor v�lido para o produto: ");
            }
            (bar_ptr+pos)->valor = temp_value;
            printf("Informe a quantidade em estoque: ");
            while(scanf("%d", &temp_qtd) != 1 || temp_qtd < 0)
            {
                fflush(stdin);
                printf("\nInforme uma quantidade v�lida: ");
            }
            (bar_ptr+pos)->qtd = temp_qtd;
            printf("\nDigite 'S' para realizar um novo cadastro.");
            fflush(stdin);
            user_sel = toupper(getchar());
            if(user_sel != 'S')
                break;
        }
    }
}

/**
 * @brief Exclui um produto do estoque
 */
void del_product(struct cadastro *bar_ptr)
{
    int del_position;
    list_memory(bar_ptr);
    printf("\nDigite o ID do produto que deseja excluir: ");
    while(scanf("%d", &del_position) != 1 || (del_position<0 || del_position > MAX_VALUE) || ((bar_ptr+del_position)->cervejaria[0] == '\0'))
    {
        fflush(stdin);
        printf("\nInforme um ID v�lido: ");
    }
    (bar_ptr+del_position)->cervejaria[0] = '\0';
    printf("Produto deletado!\n");
    system("pause");
}

/**
 * @brief Verifica a validade dos produtos em estoque
 */
void verify_validity(struct cadastro *bar_ptr)
{
    int i=0;
    int year_val, mon_val, day_val;
    struct tm * timeinfo;
    time_t rawtime;
    time(&rawtime);
    timeinfo = localtime (&rawtime);
    printf("\nProdutos pr�ximos ou fora do prazo de validade");
    for(i=0; i<=MAX_VALUE; i++)
    {
        sscanf((bar_ptr+i)->validade, "%d/%d/%d", &day_val, &mon_val, &year_val);
        year_val = year_val - (timeinfo->tm_year+1900);
        if(year_val == 1 && (timeinfo->tm_mon+1) == 12 && mon_val == 1 && (bar_ptr+i)->cervejaria[0] != '\0')
        {
            printf("\n--------- ID %d -----------", i);
            printf("\nCervejaria: %s ", (bar_ptr+i)->cervejaria);
            printf("\nProduto:    %s ", (bar_ptr+i)->nome);
            printf("\nValidade:   %s ", (bar_ptr+i)->validade);
            printf("\nValor       R$ %.2f",(bar_ptr+i)->valor);
            printf("\nEstoque:    %d\n", (bar_ptr+i)->qtd);
        }
        else if(year_val == 0 && mon_val-(timeinfo->tm_mon+1) <= 1 && (bar_ptr+i)->cervejaria[0] != '\0')
        {
            printf("\n--------- ID %d -----------", i);
            printf("\nCervejaria: %s ", (bar_ptr+i)->cervejaria);
            printf("\nProduto:    %s ", (bar_ptr+i)->nome);
            printf("\nValidade:   %s ", (bar_ptr+i)->validade);
            printf("\nValor       R$ %.2f",(bar_ptr+i)->valor);
            printf("\nEstoque:    %d\n", (bar_ptr+i)->qtd);
        }
    }
    printf("\n");
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
        printf("\nALTERA��O DE CADASTRO\nDigite:\n<1> Para alterar o valor\n<2> Para alterar a quantidade em estoque\n<R> Para retornar ao menu principal");
        user_sel = toupper(getch());
        switch (user_sel)
        {
        case '1':   // Altera o valor de venda
            system("cls");
            list_memory(bar_ptr);
            printf("\nAltera��o de valor, digite o ID do produto:");
            while(scanf("%d", &pos) != 1 || (pos < 0 || pos > MAX_VALUE) || ((bar_ptr+pos)->cervejaria[0] == '\0'))
            {
                fflush(stdin);
                printf("\nInforme um ID v�lido: ");
            }
            printf("Informe o novo valor: ");
            while(scanf("%f", &temp_value) != 1 || temp_value < 0)
            {
                fflush(stdin);
                printf("\nDigite um valor correto para o produto: ");
            }
            printf("Digite 'S' para confirmar altera��o no valor de %.2f para %.2f ", bar_ptr[pos].valor, temp_value);
            fflush(stdin);
            user_sub_sel = toupper(getchar());
            if(user_sub_sel == 'S')
            {
                (bar_ptr+pos)->valor = temp_value;
                printf("\nOpera��o conclu�da.\n");
                system("pause");
            }
            else
            {
                printf("\nOpera��o cancelada pelo usu�rio.\n");
                system("pause");
            }
            break;

        case '2':   // Altera a quantidade em estoque
            system("cls");
            list_memory(bar_ptr);
            printf("\nAltera��o de estoque, digite o ID do produto:");
            while(scanf("%d", &pos) != 1 || (pos<0 || pos > MAX_VALUE) || ((bar_ptr+pos)->cervejaria[0] == '\0'))
            {
                fflush(stdin);
                printf("\nInforme um ID v�lido: ");
            }
            printf("Informe a nova quantidade: ");
            while((scanf("%d", &temp_qtd) != 1) || temp_qtd < 0)
            {
                fflush(stdin);
                printf("\nInforme um quantidade v�lida: ");
            }
            (bar_ptr+pos)->qtd = temp_qtd;
            break;

        default:
            if(user_sel != 'R')
            {
                printf("\nOp��o inv�lida.\n");
                system("pause");
            }
            break;
        }
    }
    while(user_sel != 'R');
}

/**
 * @brief Exibe a data atual
 */
void display_time()
{
    struct tm * timeinfo;
    time_t rawtime;
    time(&rawtime);
    timeinfo = localtime (&rawtime);
    printf ("\t%s", asctime(timeinfo));
}
