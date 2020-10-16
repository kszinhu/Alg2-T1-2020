/*
BANCO - ILHAS WEBLANDS [\] AlgII - T1 - 2020
> Cassiano Rodrigues e João Pedro Vieira Rodrigues
SENHA: andreas2
> 15/09/2020 
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define ESC 27
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define F6 64
#define F7 65
#define F8 66
#define F9 67
#define F10 68
#define F11 133
#define F12 134
// '0' (F1>F10) [] '224' (F11-F12)
#define BAIXO 80
#define CIMA 72
#define ENTER 13
#define DIREITA 77
#define ESQUERDA 75

// --------------------
// FUNÇÕES VISUAIS
// --------------------

void show_console_cursor(bool show)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}
/* >>----<< */
void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x - 1, y - 1});
    /* Função pega na Internet */
}
/* >>----<< */
int setcolor(char color)
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h, color);
    /* Função pega na Internet -- */
}
/* >>----<< */
void preenchimento(int xmin, int xmax, int ymin, int ymax, int cor)
{
    int i, j;
    setcolor(cor);
    gotoxy(xmin, ymax);
    for (i = xmin; i < (xmax); i++)
    {
        printf("%c", 219);
    }
    for (i = 1; i < (ymax); i++)
    {
        gotoxy((xmin), (ymin + i));
        for (j = 0; j < (xmax - xmin); j++)
        {
            printf("%c", 219);
        }
    }
    setcolor(7);
    gotoxy(1, 1);
}
/* >>----<< */
void caixa(int xmin, int xmax, int ymin, int ymax, int cor)
{
    setcolor(cor);
    int i, j;
    gotoxy(xmin, ymax);
    for (i = xmin; i <= xmax; i++)
    {
        printf("%c", 219);
    }
    for (i = 0; i <= (ymax - 1); i++)
    {
        if (i == 1)
        {
            gotoxy(xmin - 1, ymin);
            printf("%c", 219);
        }
        if ((ymin + i) <= ymax)
        {
            gotoxy((xmin - 1), (ymin + i));
            printf("%c", 219);
        }
        if (i == (ymax - 2))
        {
            gotoxy(xmax + 1, ymin);
            printf("%c ", 219);
        }
    }
    for (i = 1; i < (ymax - 1); i++)
    {
        if (i == 1)
        {
            gotoxy(xmin - 1, ymax);
            printf("%c", 219);
        }
        if ((ymax - i) >= ymin)
        {
            gotoxy((xmax + 1), (ymin + i));
            printf("%c", 219);
        }
        if (i == (ymax - 2))
        {
            gotoxy((xmax + 1), ymax);
            printf("%c", 219);
        }
    }
    gotoxy(xmin, ymin);
    for (i = xmin; i <= xmax; i++)
    {
        printf("%c", 219);
    }
    setcolor(7);
}
/* >>----<< */
void APAGAR(int xmin, int xmax, int ymin, int ymax)
{
    int i, j;
    gotoxy(1, 1);
    for (i = xmin; i <= ymax; i++)
    {
        for (j = ymin; j <= xmax; j++)
        {
            gotoxy(xmin + j, ymin + i);
            printf("%c", 0);
        }
    }
    gotoxy(1, 1);
}
/* >>----<< */
void dados()
{
    system("cls");

    caixa(2, 75, 2, 41, 7);
    caixa(33, 42, 33, 39, 7);
    caixa(10, 67, 3, 31, 7);

    gotoxy(5, 20);
    printf("%c%c%c%c", 220, 220, 220, 220);
    gotoxy(69, 20);
    printf("%c%c%c%c", 220, 220, 220, 220);

    gotoxy(10, 10);
    printf("NOME: Andrea Carla Goncalves Vianna");
    gotoxy(10, 12);
    printf("DATA DE NASCIMENTO: 08/05/1968");
    gotoxy(10, 14);
    printf("DATA DE VINCULO: 30/02/2000");
    gotoxy(10, 16);
    printf("NUMERO DA CONTA: 40028922-07");
    gotoxy(50, 10);
    printf(".----------.");
    gotoxy(50, 11);
    printf("|          |");
    gotoxy(50, 12);
    printf("|          |");
    gotoxy(50, 13);
    printf("|          |");
    gotoxy(50, 14);
    printf("|          |");
    gotoxy(50, 15);
    printf("|          |");
    gotoxy(50, 16);
    printf("'----------'");

    gotoxy(30, 29);
    printf("[PRESSIONE ALGUMA SETA PARA VOLTAR]");

    getch();
}
/* >>----<< */
void menu()
{
    int tecla, x = 34, y = 7, opcao = 1;
    system("cls");
    gotoxy(30, 4);
    printf("[BANCO DE WEBLANDS]");
    gotoxy(8, 5);
    printf("                                #@@@@@@@");
    gotoxy(8, 6);
    printf("                              @@/        @@");

    gotoxy(8, 7);
    printf("                        @@@@@            @&");
    gotoxy(8, 8);
    printf("                      .@                @   .@,");
    gotoxy(8, 9);
    printf("                   @@@@@,    @        @@     (@");
    gotoxy(8, 10);
    printf("                   @@@@@@@   ,       @     @@@");
    gotoxy(8, 11);
    printf("                      @@@@@@@@@    @@*@@@&");
    gotoxy(8, 12);
    printf("                        @@@&      (@@@");
    gotoxy(8, 13);
    printf("                      ,@  .@@@@@@@@@. @");
    gotoxy(8, 14);
    printf("                     .@@/   @    &@  @@@");
    gotoxy(8, 15);
    printf("                  @@@     &        @    &@@");
    gotoxy(8, 16);
    printf("               .@@                   #     @@&");
    gotoxy(8, 17);
    printf("             &@&            @@ ,@@           .@&");
    gotoxy(8, 18);
    printf("           /@@            @@@@@@@@@@@           @@");
    gotoxy(8, 19);
    printf("          @@            @@@ @@  @@               ,@#");
    gotoxy(8, 20);
    printf("        .@,             /@@@@@  @@                 @@");
    gotoxy(8, 21);
    printf("       *@                 *@@@@@@@@@@               @@");
    gotoxy(8, 22);
    printf("       @#                   ,@@ @@*%%@@.             .@");
    gotoxy(8, 23);
    printf("      /@                  %%, @@ @@%% @@@              @#");
    gotoxy(8, 24);
    printf("      *@                @@@@@@@@@@@@@@               @(");
    gotoxy(8, 25);
    printf("       @@                    @@@&@@             (   .@");
    gotoxy(8, 26);
    printf("        @@                                     @    @");
    gotoxy(8, 27);
    printf("         @@@        .                       @@    @@");
    gotoxy(8, 28);
    printf("            &@@#      @@@.              @@@@@@@@@");
    gotoxy(8, 29);
    printf("                 %%@@@@@#   @@@@@@@@@@@@#");

    do
    {
        gotoxy(10, 32);
        printf("Horario: %s", __TIME__);
        gotoxy(45, 32);
        printf("[PRESSIONE ESC PARA SAIR]");
        caixa(2, 75, 2, 41, 7);
        caixa(33, 42, 33, 39, 7);
        caixa(10, 67, 3, 31, 7);

        gotoxy(5, 20);
        printf("%c%c%c%c", 220, 220, 220, 220);
        gotoxy(69, 20);
        printf("%c%c%c%c", 220, 220, 220, 220);
        gotoxy(19, 30);
        printf("UTILIZE AS SETAS PARA MOVIMENTAR NO MENU");
        tecla = getch();
        gotoxy(22, 4);
        printf("                                 ");
        switch (tecla)
        {
        case DIREITA:
            opcao++;
            break;

        case ESQUERDA:
            opcao--;
            break;
        case ENTER:
            if (opcao == 1)
            {
                dados();
            }
            if (opcao == 2)
            {
                sacar();
            }
            else if (opcao == 3)
            {
                cheque();
            }
            break;
        }
        if (opcao == 4)
        {
            opcao = 1;
        }
        if (opcao == 0)
        {
            opcao = 3;
        }
        if (opcao == 1)
        {
            system("cls");
            gotoxy(30, 4);
            printf("[   MEUS DADOS   ]"); /* Colocar desenho do MSN */
            gotoxy(22, 5);
            printf("               _..oooo._");
            gotoxy(22, 6);
            printf("           _od88888888888bo.");
            gotoxy(22, 7);
            printf("         d=====88888888=8888b.");
            gotoxy(22, 8);
            printf("      .d==============8888888b.");
            gotoxy(22, 9);
            printf("    d888888==8===8888888######b");
            gotoxy(22, 10);
            printf("   d8888888888888888888########b");
            gotoxy(22, 11);
            printf("  d88888#####888888##8##########");
            gotoxy(22, 12);
            printf(" 88888#########################b");
            gotoxy(22, 13);
            printf(" Y88############################");
            gotoxy(22, 14);
            printf("Y8#####'Y###`###''__Y#########");
            gotoxy(22, 15);
            printf(" Y####b\\ /'' `' ,/ .\\'#######P");
            gotoxy(22, 16);
            printf("  \"####b. /d     b.|  #######");
            gotoxy(22, 17);
            printf("     \"Y#b \"P    .\"#\" d######P");
            gotoxy(22, 18);
            printf("      d##'`'(    ~~  ####### ");
            gotoxy(22, 19);
            printf("     d##'    _,     d######P");
            gotoxy(22, 20);
            printf("    m###b.         d######P");
            gotoxy(22, 21);
            printf("    p#####m_     _.######P");
            gotoxy(22, 22);
            printf("    '####PY#~---~  ####\"P");
            gotoxy(22, 23);
            printf("     \"Y\"     |     |");
            gotoxy(22, 24);
            printf("           _-|     |,_ ");
            gotoxy(22, 25);
            printf("         ,'|(' _.-'   `-");
            gotoxy(22, 26);
            printf("        /  .--~        /");
            gotoxy(22, 27);
            printf("       | ,'   `.     ,'");
            gotoxy(22, 28);
            printf("        \\       \\  ,'");
            gotoxy(22, 29);
            printf("        '---...__,`");
        }
        else if (opcao == 2)
        {
            system("cls");

            caixa(2, 75, 2, 41, 7);
            caixa(33, 42, 33, 39, 7);
            caixa(10, 67, 3, 31, 7);

            gotoxy(30, 4);
            printf("[ SACAR DINHEIRO ]"); /* Colocar o desenho de uma nota */
            gotoxy(23, 14);
            printf(".------------------------------.");
            gotoxy(23, 15);
            printf("|                              |");
            gotoxy(23, 16);
            printf("|            .-----.           |");
            gotoxy(23, 17);
            printf("|           /  BT$  \\          |");
            gotoxy(23, 18);
            printf("|           \\_______/          |");
            gotoxy(23, 19);
            printf("|                              |");
            gotoxy(23, 20);
            printf("'------------------------------'");
        }
        else if (opcao == 3)
        {
            system("cls");

            caixa(2, 75, 2, 41, 7);
            caixa(33, 42, 33, 39, 7);
            caixa(10, 67, 3, 31, 7);

            gotoxy(30, 4);
            printf("[PREENCHER CHEQUE]"); /* Colocar o desenho de uma caneta/lápis */
            gotoxy(2, 7);
            printf("                ,");
            gotoxy(2, 8);
            printf("              .%%  *(*");
            gotoxy(2, 9);
            printf("              # %%   ,/(");
            gotoxy(2, 10);
            printf("                %% #.  ./(.");
            gotoxy(2, 11);
            printf("                 %%.(*   ///");
            gotoxy(2, 12);
            printf("                   /(/*   */(");
            gotoxy(2, 13);
            printf("                       #*#   ,//,");
            gotoxy(2, 14);
            printf("                          */.  .&@@");
            gotoxy(2, 15);
            printf("                            .(@((@@@@");
            gotoxy(2, 16);
            printf("                               &@#(%%@@&,");
            gotoxy(2, 17);
            printf("                                 #&%%(%%@@@#");
            gotoxy(2, 18);
            printf("                                   *@&%%@@@@&");
            gotoxy(2, 19);
            printf("                                      &@%%#@@@@.");
            gotoxy(2, 20);
            printf("                                        %%@&%%@@@@/");
            gotoxy(2, 21);
            printf("                                          /@@(@@@@#");
            gotoxy(2, 22);
            printf("                                             @@&@@@@%%");
            gotoxy(2, 23);
            printf("                                               #@@@@@@&");
            gotoxy(2, 24);
            printf("                                                  @@@@@@&");
            gotoxy(2, 25);
            printf("                                                    *@*/((,");
            gotoxy(2, 26);
            printf("                                                       *//((,");
            gotoxy(2, 27);
            printf("                                                          *##(");
        }
    } while (tecla != ESC);
    system("cls");
    tela_final();
}
/* >>----<< */
void caixa_eletronico()
{
    gotoxy(22, 4);
    printf("[   DIGITE A SENHA CADASTRADA   ]");
    gotoxy(5, 20);
    printf("%c%c%c%c", 220, 220, 220, 220);
    gotoxy(69, 20);
    printf("%c%c%c%c", 220, 220, 220, 220);
    gotoxy(31, 27);
    putchar('[');
    gotoxy(44, 27);
    putchar(']');
    gotoxy(15, 8);
    printf("888~~\\       e      888b    |  e88~-_    ,88~-_  ");
    gotoxy(15, 9);
    printf("888   |     d8b     |Y88b   | d888   \\  d888   \\ ");
    gotoxy(15, 10);
    printf("888 _/     /Y88b    | Y88b  | 8888     88888    |");
    gotoxy(15, 11);
    printf("888  \\    /  Y88b   |  Y88b | 8888     88888    |");
    gotoxy(15, 12);
    printf("888   |  /____Y88b  |   Y88b| Y888   /  Y888   / ");
    gotoxy(15, 13);
    printf("888__/  /      Y88b |    Y888  \"88_-~    `88_-~  ");

    caixa(2, 75, 2, 41, 7);
    caixa(33, 42, 33, 39, 7);
    caixa(10, 67, 3, 31, 7);

    //senha da conta -> andreas2
    /* Colocar desenho do MSN */

    char senha[10];
    int i, j;

    for (i = 0; i < 8; i++)
    {
        senha[i] = getch();
        gotoxy(34 + i, 27);
        printf("*");
    }

    if (senha[0] == 'a' && senha[1] == 'n' && senha[2] == 'd' && senha[3] == 'r' && senha[4] == 'e' && senha[5] == 'a' && senha[6] == 's' && senha[7] == '2')
    {
        menu();
    }
    else
    {
        system("cls");
        tela_final();
    }
}
/* >>----<< */
void tela_final()
{
    gotoxy(15, 8);
    printf("888~~\\       e      888b    |  e88~-_    ,88~-_  ");
    gotoxy(15, 9);
    printf("888   |     d8b     |Y88b   | d888   \\  d888   \\ ");
    gotoxy(15, 10);
    printf("888 _/     /Y88b    | Y88b  | 8888     88888    |");
    gotoxy(15, 11);
    printf("888  \\    /  Y88b   |  Y88b | 8888     88888    |");
    gotoxy(15, 12);
    printf("888   |  /____Y88b  |   Y88b| Y888   /  Y888   / ");
    gotoxy(15, 13);
    printf("888__/  /      Y88b |    Y888  \"88_-~    `88_-~  ");
    gotoxy(21, 16);
    printf("> Algoritmo realizado pelos alunos <\n");
    gotoxy(22, 24);
    printf("%c Cassiano Henrique Aparecido Rodrigues", 175);
    gotoxy(22, 25);
    printf("%c Joao Pedro Vieira Rodrigues", 175);
    gotoxy(20, 29);
    printf("[PRESSIONE QUALQUER TECLA PARA SAIR]");
    getch();
    exit(1);
}

// --------------------
// FUNÇÕES OPERADORAS
// --------------------

char moetoext(char valor[16], char texto[1000])
{
    if ((valor[0] != '0' || valor[1] != '0' || valor[2] != '0' || valor[3] != '0' || valor[4] != '0' || valor[5] != '0' || valor[6] != '0' || valor[7] != '0' || valor[8] != '0' || valor[9] != '0' || valor[10] != '0' || valor[11] != '0') && (valor[12] != '0' || valor[13] != '0'))
        strcat(texto, " e ");
    if (valor[12] == '1')
    {
        switch (valor[13])
        {
        case '0':
            strcat(texto, "dez ");
            break;
        case '1':
            strcat(texto, "onze ");
            break;
        case '2':
            strcat(texto, "doze ");
            break;
        case '3':
            strcat(texto, "treze ");
            break;
        case '4':
            strcat(texto, "quatorze ");
            break;
        case '5':
            strcat(texto, "quinze ");
            break;
        case '6':
            strcat(texto, "dezesseis ");
            break;
        case '7':
            strcat(texto, "dezessete ");
            break;
        case '8':
            strcat(texto, "dezoito ");
            break;
        case '9':
            strcat(texto, "dezenove ");
            break;
        }
    }
    else
    {
        switch (valor[12])
        {
        case '2':
            strcat(texto, "vinte ");
            break;
        case '3':
            strcat(texto, "trinta ");
            break;
        case '4':
            strcat(texto, "quarenta ");
            break;
        case '5':
            strcat(texto, "cinquenta ");
            break;
        case '6':
            strcat(texto, "sessenta ");
            break;
        case '7':
            strcat(texto, "setenta ");
            break;
        case '8':
            strcat(texto, "oitenta ");
            break;
        case '9':
            strcat(texto, "noventa ");
            break;
        }
        if (valor[12] != '0' && valor[13] != '0')
            strcat(texto, "e ");
        switch (valor[13])
        {
        case '1':
            strcat(texto, "um ");
            break;
        case '2':
            strcat(texto, "dois ");
            break;
        case '3':
            strcat(texto, "tres ");
            break;
        case '4':
            strcat(texto, "quatro ");
            break;
        case '5':
            strcat(texto, "cinco ");
            break;
        case '6':
            strcat(texto, "seis ");
            break;
        case '7':
            strcat(texto, "sete ");
            break;
        case '8':
            strcat(texto, "oito ");
            break;
        case '9':
            strcat(texto, "nove ");
            break;
        }
    }
    if (valor[12] == '0' && valor[13] == '1')
        strcat(texto, "CentBits");
    else if (valor[12] != '0' || valor[13] != '0')
        strcat(texto, "CentBits");
}
/* >>----<< */
char numtoext(int casa, char valor[16], char texto[300], char pl[8], char si[7])
{
    int b, c;
    for (b = 0, c = 0; b < casa; b++)
    {
        if (valor[b] != '0')
        {
            c = 1;
        }
    }
    if (c == 1)
    {
        strcat(texto, " ");
    }
    b = casa + 1;
    c = casa + 2;
    if (valor[casa] == '1' && valor[b] == '0' && valor[c] == '0')
        strcat(texto, "cem ");
    else
    {
        switch (valor[casa])
        {
        case '1':
            strcat(texto, "cento ");
            break;
        case '2':
            strcat(texto, "duzentos ");
            break;
        case '3':
            strcat(texto, "trezentos ");
            break;
        case '4':
            strcat(texto, "quatrocentos ");
            break;
        case '5':
            strcat(texto, "quinhentos ");
            break;
        case '6':
            strcat(texto, "seiscentos ");
            break;
        case '7':
            strcat(texto, "setecentos ");
            break;
        case '8':
            strcat(texto, "oitocentos ");
            break;
        case '9':
            strcat(texto, "novecentos ");
            break;
        }
        if ((valor[casa] != '0' && valor[b] != '0') && valor[c] != '0')
            strcat(texto, "e ");
        if (valor[b] == '1')
        {
            switch (valor[c])
            {
            case '0':
                strcat(texto, "dez ");
                break;
            case '1':
                strcat(texto, "onze ");
                break;
            case '2':
                strcat(texto, "doze ");
                break;
            case '3':
                strcat(texto, "treze ");
                break;
            case '4':
                strcat(texto, "catorze ");
                break;
            case '5':
                strcat(texto, "quinze ");
                break;
            case '6':
                strcat(texto, "dezesseis ");
                break;
            case '7':
                strcat(texto, "dezessete ");
                break;
            case '8':
                strcat(texto, "dezoito ");
                break;
            case '9':
                strcat(texto, "dezenove ");
                break;
            }
        }
        else
        {
            switch (valor[b])
            {
            case '2':
                strcat(texto, "vinte ");
                break;
            case '3':
                strcat(texto, "trinta ");
                break;
            case '4':
                strcat(texto, "quarenta ");
                break;
            case '5':
                strcat(texto, "cinquenta ");
                break;
            case '6':
                strcat(texto, "sessenta ");
                break;
            case '7':
                strcat(texto, "setenta ");
                break;
            case '8':
                strcat(texto, "oitenta ");
                break;
            case '9':
                strcat(texto, "noventa ");
                break;
            }
            if ((valor[casa] != '0' && valor[b] != '0') && valor[c] != '0')
                strcat(texto, "e ");
            switch (valor[c])
            {
            case '1':
                strcat(texto, "um ");
                break;
            case '2':
                strcat(texto, "dois ");
                break;
            case '3':
                strcat(texto, "tres ");
                break;
            case '4':
                strcat(texto, "quatro ");
                break;
            case '5':
                strcat(texto, "cinco ");
                break;
            case '6':
                strcat(texto, "seis ");
                break;
            case '7':
                strcat(texto, "sete ");
                break;
            case '8':
                strcat(texto, "oito ");
                break;
            case '9':
                strcat(texto, "nove ");
                break;
            }
        }
    }
    if (valor[casa] == '0' && valor[b] == '0' && valor[c] == '1')
    {
        strcat(texto, si);
    }
    else if (valor[casa] != '0' || valor[b] != '0' || valor[c] != '0')
    {
        strcat(texto, pl);
    }
}
/* >>----<< */
void sacar()
{
    system("cls"); /* Limpar para testes */

    caixa(2, 75, 2, 41, 7);
    caixa(33, 42, 33, 39, 7);
    caixa(10, 67, 3, 31, 7);
    gotoxy(5, 20);
    printf("%c%c%c%c", 220, 220, 220, 220);
    gotoxy(69, 20);
    printf("%c%c%c%c", 220, 220, 220, 220);

    char valor[15];
    long long unsigned quantia, quant, n100, n50, n20, n10, n5, n2, n1, m50, m25, m10, m5, m1;
    int aux = 11, i, j, k;
    gotoxy(24, 6);
    printf("[VALOR MAXIMO B$ 9.999.999,99]");
    gotoxy(32, 7);
    printf("B$ 0.000.000,00");
    gotoxy(35, 7); //3
    for (i = 0; i < 1; i++)
    {
        valor[i] = getch();
        printf("%c", valor[i]);
    }
    gotoxy(37, 7); //2
    for (i = 0; i < 3; i++)
    {
        valor[(i + 1)] = getch();
        printf("%c", valor[(i + 1)]);
    }
    gotoxy(41, 7); //4
    for (i = 0; i < 3; i++)
    {
        valor[(i + 4)] = getch();
        printf("%c", valor[(i + 4)]);
    }
    gotoxy(45, 7); //4
    for (i = 0; i < 2; i++)
    {
        valor[(i + 7)] = getch();
        printf("%c", valor[(i + 7)]);
    }

    quant = (atoi(valor));
    n100 = quant / 10000;
    quant = quant % 10000;

    n50 = quant / 5000;
    quant = quant % 5000;

    n20 = quant / 2000;
    quant = quant % 2000;

    n10 = quant / 1000;
    quant = quant % 1000;

    n5 = quant / 500;
    quant = quant % 500;

    n2 = quant / 200;
    quant = quant % 200;

    n1 = quant / 100;
    quant = quant % 100;

    m50 = quant / 50;
    quant = quant % 50;

    m25 = quant / 25;
    quant = quant % 25;

    m10 = quant / 10;
    quant = quant % 10;

    //----------------------------------------
    gotoxy(23, 9);
    printf("[AGUARDE A CONTAGEM DAS CEDULAS]\n");
    for (i = 0; i <= 100; i++)
    {
        gotoxy(38, 15);
        printf("%d%%  ", i);
        fflush(stdout);
        gotoxy(29, 16);
        for (j = 0; j < i % 20; j++)
        {
            printf("%c", 220);
        }
        fflush(stdout);
        Sleep(50);
        printf("\r");
        gotoxy(29, 16);
        for (k = 0; k < 25; k++)
        {

            printf(" ");
        }
        printf("\r");
    }
    gotoxy(38, 15);
    printf("    ");
    gotoxy(11, aux);
    printf("NOTAS:\n");
    aux += 2;
    gotoxy(11, aux);
    if (n100 != 0)
    {
        aux++;
        printf("%llu nota(s) de Bt$ 100.00\n", n100);
    }
    gotoxy(11, aux);
    if (n50 != 0)
    {
        aux++;
        printf("%llu nota(s) de Bt$ 50.00\n", n50);
    }
    gotoxy(11, aux);
    if (n20 != 0)
    {
        aux++;
        printf("%llu nota(s) de Bt$ 20.00\n", n20);
    }
    gotoxy(11, aux);
    if (n10 != 0)
    {
        aux++;
        printf("%llu nota(s) de Bt$ 10.00\n", n10);
    }
    gotoxy(11, aux);
    if (n5 != 0)
    {
        aux++;
        printf("%llu nota(s) de Bt$ 5.00\n", n5);
    }
    gotoxy(11, aux);
    if (n2 != 0)
    {
        aux++;
        printf("%llu nota(s) de Bt$ 2.00\n", n2);
    }
    aux++;
    gotoxy(11, aux);
    printf("MOEDAS:\n");
    aux += 2;
    gotoxy(11, aux);
    if (n1 != 0)
    {
        aux++;
        printf("%llu moeda(s) de Bt$ 1.00\n", n1);
    }
    gotoxy(11, aux);
    if (m50 != 0)
    {
        aux++;
        printf("%llu moeda(s) de Bt$ 0.50\n", m50);
    }
    gotoxy(11, aux);
    if (m25 != 0)
    {
        aux++;
        printf("%llu moeda(s) de Bt$ 0.25\n", m25);
    }
    gotoxy(11, aux);
    if (m10 != 0)
    {
        aux++;
        printf("%llu moeda(s) de Bt$ 0.10\n", m10);
    }
    gotoxy(11, aux);
    if (quant != 0)
    {
        aux++;
        printf("%llu moeda(s) de Bt$ 0.01\n", quant);
    }

    gotoxy(30, 29);
    printf("[PRESSIONE ALGUMA SETA PARA VOLTAR]");
    getch();
}
/* >>----<< */
void cheque()
{
    system("cls");

    caixa(2, 75, 2, 41, 7);
    caixa(33, 42, 33, 39, 7);
    caixa(10, 67, 3, 31, 7);
    gotoxy(5, 20);
    printf("%c%c%c%c", 220, 220, 220, 220);
    gotoxy(69, 20);
    printf("%c%c%c%c", 220, 220, 220, 220);

    char nota[16], extenso[200];
    int i, b, cont = 0, aux = 0, aux1 = 0;
    memset(extenso, 0, (sizeof(extenso)));
    gotoxy(20, 6);
    //Nove bilhões, novecentos e noventa e nove milhões, novecentos e noventa e nove mil, novecentos e noventa e nove bits, noventa e nove centbits.
    printf("[VALOR MAXIMO B$ 999.999.999.999,99]");
    gotoxy(28, 7);
    printf("B$ 000.000.000.000,00");
    gotoxy(31, 7);
    for (i = 0; i < 3; i++)
    {
        nota[i] = getch();
        printf("%c", nota[i]);
    }
    gotoxy(35, 7);
    for (i = 0; i < 3; i++)
    {
        nota[(i + 3)] = getch();
        printf("%c", nota[(i + 3)]);
    }
    gotoxy(39, 7);
    for (i = 0; i < 3; i++)
    {
        nota[(i + 6)] = getch();
        printf("%c", nota[(i + 6)]);
    }
    gotoxy(43, 7);
    for (i = 0; i < 3; i++)
    {
        nota[(i + 9)] = getch();
        printf("%c", nota[(i + 9)]);
    }
    gotoxy(47, 7);
    for (i = 0; i < 2; i++)
    {
        nota[(i + 12)] = getch();
        printf("%c", nota[(i + 12)]);
    }

    numtoext(0, nota, extenso, "bilhoes", "bilhao");
    numtoext(3, nota, extenso, "milhoes", "milhao");
    numtoext(6, nota, extenso, "mil", "mil");
    numtoext(9, nota, extenso, "Bits", "Bits");
    moetoext(nota, extenso);

    extenso[0] = toupper(extenso[0]);
    gotoxy(12, 15);
    for (i = 0, aux1 = 1; i <= strlen(extenso); aux1++, i++)
    {
        if (aux1 == 56 && i == 55)
        {
            printf("-");
            gotoxy(10, 16 + aux);
            aux++;
            aux1 = 0;
        }
        else if (aux1 == 57 && i > 55)
        {
            printf("-");
            gotoxy(10, 16 + aux);
            aux++;
            aux1 = 0;
        }
        printf("%c", extenso[i]);
    }

    gotoxy(25, 22);
    printf("Andrea Carla Goncalves Vianna");
    gotoxy(34, 27);
    printf("%s", __DATE__);
    gotoxy(30, 29);
    printf("[PRESSIONE ALGUMA SETA PARA VOLTAR]");
    getch();
}

main()
{
    caixa_eletronico();
}