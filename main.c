#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "struct.h"
#include <string.h>
#include <conio.h>
#include <time.h>
#include "windows.h"

/*Variáveis Globais*/
 struct Veiculo Carro[24];
 struct Cliente Cli[100];
 struct Financeiro Fin[100];
 int x,y,xa;
 char DataAtual[100];
 char DataPrevista[100];
 char DataDevolucao[100];
 char HoraDevolucao[100];

 char Diferenca[100];

 int dif, menu;

 float VlrB, VlrDia, VlrSeg, VlrDesc, VlrTotal;

 menu = 0;

int main()
{
     x = 0;
     y = 0;
     xa = 0;
    setlocale(LC_ALL,"Portuguese");

CriaCarro(Carro);

criacliteste(Cli);

MenuRentCar2();

Menu();

}

void CalculaData(int dias) {

    char hora[100];
    int horaD;
    time_t sec, agora;
    horaD = 24;

    /*RECUPERA A HORA ATUAL*/
    agora = time(NULL);
    strftime(DataAtual, sizeof(DataAtual), "%d/%m/%Y", localtime(&agora));

    horaD = horaD * dias;

    /* ZERA A STRUCT TODA */
    struct tm tm = { 0 };

    /*QUEBRA A DATA E JOGA NA STRUCT CRIADA*/
    if (sscanf(DataAtual, "%d/%d/%d - %H:%M:%S", &tm.tm_mday, &tm.tm_mon, &tm.tm_year, tm.tm_hour, tm.tm_min, tm.tm_sec) < 3) {
        fprintf(stderr, "Erro de formatação ao ler data %s\n", DataAtual);
        exit(1);
    }

    tm.tm_mon --;
    tm.tm_year -= 1900;

    sec = mktime(&tm);

    sec = sec / 3600;
    sec = sec + horaD;
    sec = sec * 3600;

    strftime(DataPrevista, 50, "%d/%m/%Y", localtime(&sec));

}

void CalcDataDevolucaoCarro (char DtPrevisto[100], char DtDevol[100], char hrDevol[100])
{
    struct tm dataPrev;
    struct tm dataDevol;
    struct tm horaDevol;


    dataPrev.tm_hour = 23;
    dataPrev.tm_min = 59;
    dataPrev.tm_sec = 59;

    sscanf(DtPrevisto, "%d/%d/%d", &dataPrev.tm_mday, &dataPrev.tm_mon, &dataPrev.tm_year);
    sscanf(DtDevol, "%d/%d/%d", &dataDevol.tm_mday, &dataDevol.tm_mon, &dataDevol.tm_year);
    sscanf(hrDevol, "%d:%d", &horaDevol.tm_hour, &horaDevol.tm_min);

    dataDevol.tm_hour = horaDevol.tm_hour;
    dataDevol.tm_min = horaDevol.tm_min;
    dataDevol.tm_sec = 00;

    dataPrev.tm_mon --;
    dataPrev.tm_year -= 1900;

    dataDevol.tm_mon --;
    dataDevol.tm_year -= 1900;


    time_t datatesteEntrada;
    time_t datatesteSaida;


    datatesteEntrada = 0;
    datatesteSaida = 0;
    dif = 0;


    datatesteEntrada = mktime(&dataPrev);
    datatesteSaida = mktime(&dataDevol);


    datatesteEntrada = datatesteEntrada / 3600;
    datatesteSaida = datatesteSaida / 3600;
    dif = datatesteSaida - datatesteEntrada;
    dif = dif - 1;

    strftime(Diferenca, 50, "%H:%M:%S", localtime(&dif));

}

void Menu(void)
{
    int op;

    op = 0;

    while(op != 4)
    {
        if(menu == 1)
        {
            MenuRentCar();
        }

        menu = 1;

        printf("\n\n******************** ######################## ********************\n");
        printf("*                    Escolha a Opção Desejada                    *\n");
        printf("******************** ######################## ********************\n\n");
        printf("1 - Gestão administrativa");
        printf("\n2 - Gestão de locação");
        printf("\n3 - Financeiro");
        printf("\n4 - Encerrar aplicação\n\n");
        printf("Opção: ");

        scanf("%d", &op);

        if( op > 4 )
        {
            Info(1);
        }
        else
        {
            if(op == 1)
            {
                MenuAdm();
            }

            if(op == 2)
            {
               MenuLoc();
            }

            if(op == 3)
            {
                MenuFin();
            }
            if(op == 4)
            {
                Info(3);
                exit(1);
            }
        }
    }
}

void MenuAdm(void)
{
    int op, i, idade, ok, idoso, Ong;
    char Nome[30], CPF[11], OPOng[1];
    op = 0;
    ok = 0;
    Ong = 0;

    while(op < 3)
    {
        system("cls");

        MenuRentCar();

        printf("\n\n******************** ######################## ********************\n");
        printf("*              ESCOLHA A OPÇÃO ADMINISTRATIVA DESEJADA           *\n");
        printf("******************** ######################## ********************\n\n");

        printf("1 - Cadastro de Cliente");
        printf("\n2 - Retornar menu anterior\n");
        printf("Opção: ");

        scanf("%d", &op);

        if(op == 1)
        {
            while(ok == 0)
            {
                printf("******************** ## CADASTRO DE USUÁRIO ## ********************\n\n");

                for(i = 1; i <= 100; i++)
                {
                    if(Cli[i].CodCli == 0)
                    {
                        printf("Digite o nome do cliente: ");
                        scanf("%s", &Nome);

                        printf("\nDigite o CPF do cliente: ");
                        scanf("%s", &CPF);

                        printf("\nDigite a idade do cliente: ");
                        scanf("%d", &idade);

                        printf("\nIntegra alguma ONG?\n");

                        printf("\n***************** ONGs *****************");
                        printf("\n1 - ONG SOS Mata Atlântica");
                        printf("\n2 - Instituto ECOAR");
                        printf("\n3 - Recicloteca (Ambev)");
                        printf("\n4 - Nenhuma");
                        printf("\nOpção: ");

                        scanf("%d", &Ong);

                        if(Ong < 4)
                        {
                            Ong = 1;
                        }
                        else
                        {
                            Ong = 0;
                        }

                        if(idade < 18)
                        {
                           Info(2);
                        }
                        else
                        {
                            if(strlen(CPF) > 11)
                            {
                               Info(4);
                            }
                            else
                            {
                                if(idade >= 60 && Ong != 1)
                                {
                                    idoso = 1;
                                }
                                else
                                {
                                    idoso = 0;
                                }

                                Cli[i].CodCli = VerificaCodCliCLiente(i);
                                strcpy(Cli[i].NomCli, Nome);
                                strcpy(Cli[i].CPF, CPF);
                                Cli[i].Idade = idade;
                                Cli[i].Idoso = idoso;
                                Cli[i].Ong = Ong;

                                Info(5, i);

                                Menu();
                            }
                        }
                    }
                }
            }
        }

        if(op == 2)
        {
            system("cls");
            Menu();
        }
    }

    system("cls");
}

void MenuFin(void)
{
    int op, existep, i;
    op = 0;
    system("cls");

    existep = 0;

    while(op != 3)
    {
        MenuRentCar();

        printf("\n\n******************** ######################## ********************\n");
        printf("*               Escolha a Opção Fincaneira Desejada              *\n");
        printf("******************** ######################## ********************\n\n");


        printf("1-Listar Pagamentos");
        printf("\n2-Retornar Menu Anterior");
        printf("\nOpção: ");

        scanf("%d", &op);

        for(i = 0; i<= 99; i++)
        {
            if(Fin[i].CodCliente == 0)
            {
                existep++;
            }

        }

        if(existep == 100)
        {
            Info(1);
        }
        else
        {
            if(op == 1)
            {

                int i, x, xa, xb, xc;

                x = 6;
                xa = 6;
                xb = 6;
                xc = 6;

                system("cls");
                printf("******************** ######################## ********************\n");
                printf("*                     Relatório de Pagamentos                    *\n");
                printf("******************** ######################## ********************\n");

                gotoxy(1, 5);
                printf("Cód. Cliente");
                gotoxy(20, 5);
                printf("Nome Cliente");
                gotoxy(40, 5);
                printf("Data Locação");
                gotoxy(60, 5);
                printf("Valor Pago");

                for(i = 0; i<= 100; i++)
                {
                    if(Fin[i].CodCliente != 0)
                    {
                        gotoxy(2,x=x+1);
                        printf("%d", Fin[i].CodCliente);

                        Sleep(30);

                        gotoxy(20,xa=xa+1);
                        printf("%s", &Fin[i].NomeCli);

                        Sleep(30);

                        gotoxy(40,xb=xb+1);
                        printf("%s", &Fin[i].DataAlugado);

                        Sleep(30);

                        gotoxy(60,xc=xc+1);
                        printf("R$%.2f", Fin[i].VlrPago);

                        Sleep(50);
                    }
                }

                getch();
            }
        }

        if(op == 2)
        {
            Menu();
        }
    }
}

void MenuLoc(void)
{
    system("cls");
    int op;
    op = 0;

    int CodVeiculo
        ,CodCli
        ,OpTipoCarro
        ,OpGrupo
        ,ExistCli
        ,PosCli
        ,CodV
        ,CodG
        ,TpSeg
        ,seq
        ,CAlugado;
    char OpSeg[1];

    ExistCli = 0;

    CAlugado = 0;
    CodVeiculo = 0;
    fflush(stdout);


    system ("cls");

    while(op !=5)
    {
        MenuRentCar();

        printf("\n\n******************** ######################## ********************\n");
        printf("*                       Gestão de Locação                        *\n");
        printf("******************** ######################## ********************\n");
        printf("\n1 - Saida de Veículos");
        printf("\n2 - Retorno de Veículos");
        printf("\n3 - Relatorio de Veiculos");
        printf("\n4 - Relatorio de Locações");
        printf("\n5 - Retornar ao menu anterior\n\n");
        printf("Opção: ");


        scanf("%d",&op);

        if(op > 5)
        {
            Info(1);
        }
        else
        {
            if(op == 1)
            {
                while(ExistCli == 0)
                {

                    system("cls");

                    printf("******************** ######################## ********************\n");
                    printf("*                       Saída de Veículos                        *\n");
                    printf("*                            Locação                             *\n");
                    printf("******************** ######################## ********************\n\n");

                    printf("Código do cliente: ");
                    scanf("%d", &CodCli);
                    int icar, icli;
                    for(icli = 1; icli < 100; icli++)
                    {
                        if(CodCli == Cli[icli].CodCli)
                        {
                            for(icar = 0; icar <=23; icar++)
                            {
                                if(Cli[icli].CodCli == Carro[icar].ClienteCar)
                                {
                                    ExistCli = 2;
                                    PosCli = icli;
                                    break;
                                }
                                else
                                {
                                    ExistCli = 1;
                                    PosCli = icli;
                                }
                            }
                        }
                    }
                    if(ExistCli == 1)
                    {

                        do{
                                OpGrupo = 99;

                                DadosUsuario(PosCli, OpGrupo, CodVeiculo, 0, 0);
                                printf("******************** ## ESCOLHA UM GRUPO ## ********************\n\n");

                                printf("1 - Hatch\n");
                                printf("2 - Sedan\n");
                                printf("3 - Utilitário\n");
                                printf("4 - Retornar ao menu anterior\n");

                                scanf("%d", &OpTipoCarro);

                                switch(OpTipoCarro)
                                {
                                    case 1:
                                        while(OpGrupo == 99)
                                        {
                                            x = 17;
                                            y = 18;
                                            seq = 1;
                                            system("cls");

                                            DadosUsuario(PosCli, OpTipoCarro, CodVeiculo,0 ,0);

                                            printf("******************** ## ESCOLHA UM TIPO ## ********************\n\n");

                                            printf("11 - Hatch Básico Econômico\n");
                                            printf("12 - Hatch Econômico\n");
                                            printf("13 - Hatch Plus\n");
                                            printf("14 - Hatch Plus Automático\n");
                                            printf("0 - Sair\n\n");
                                            printf("Opção: ");

                                            scanf("%d", &OpGrupo);

                                            if(OpGrupo != 11 && OpGrupo != 12 && OpGrupo != 13 && OpGrupo != 14 && OpGrupo != 0)
                                            {
                                               Info(1);
                                               OpGrupo = 99;
                                            }
                                        }

                                        if(OpGrupo == 0)
                                        {
                                            system("cls || clear");
                                            Menu();
                                        }

                                        gotoxy(1,17);
                                        printf("\nCódigo");
                                        gotoxy(x,y);
                                        printf("Carro");
                                        gotoxy(x+11,y);
                                        printf("Disponível\n");
                                        int i;
                                        seq = 1;
                                        for(i = 0; i <= 23; i++)
                                        {

                                            if(OpGrupo == Carro[i].Grupo)
                                            {
                                                printf("%d - ",seq);

                                                gotoxy(x,y=y+1);
                                                printf("%s", Carro[i].Model);

                                                if(Carro[i].ClienteCar == 0)
                                                {
                                                    gotoxy(x+11,y);
                                                    printf("[S]\n");
                                                }
                                                else
                                                {
                                                    gotoxy(x+11,y);
                                                    printf("[N]\n");
                                                }
                                                seq++;
                                                Sleep(500);;
                                            }

                                        }

                                        printf("\n\n*************************************\n");
                                        printf("Digite o código do carro desejado\n");
                                        printf("*************************************\n\n");
                                        printf("Opção: ");
                                        scanf("%d", &CodVeiculo);

                                        for(i = 0; i <= 23; i++)
                                        {
                                            if(Carro[i].Grupo == OpGrupo)
                                            {
                                                if(Carro[i].CodVeiculo == CodVeiculo)
                                                {
                                                    if(Carro[i].ClienteCar > 0)
                                                    {
                                                        Info(6);
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        CAlugado = 1;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    CAlugado = 0;
                                                }
                                            }
                                        }


                                        break;

                                    case 2:

                                        while(OpGrupo != 21 && OpGrupo != 22 && OpGrupo != 23 && OpGrupo != 0)
                                        {
                                            x = 17;
                                            y = 18;
                                            seq = 1;
                                            system("cls");

                                            DadosUsuario(PosCli, OpTipoCarro, CodVeiculo,0 ,0);

                                            printf("******************** ## ESCOLHA UM TIPO ## ********************\n\n");

                                            printf("21 - Sedan Compacto\n");
                                            printf("22 - Sedan Compacto Plus\n");
                                            printf("23 - Sedan Compacto Plus Automático\n");
                                            printf("0 - Sair\n\n");

                                            printf("Opção: ");
                                            scanf("%d", &OpGrupo);

                                            if(OpGrupo == 0)
                                            {
                                                system("cls || clear");
                                                Menu();
                                            }

                                            if(OpGrupo != 21 && OpGrupo != 22 && OpGrupo != 23 && OpGrupo != 0)
                                            {
                                                Info(1);
                                                OpGrupo = 99;
                                            }
                                        }

                                        gotoxy(1,17);
                                        printf("\nCódigo");
                                        gotoxy(x,y);
                                        printf("Carro");
                                        gotoxy(x+11,y);
                                        printf("Disponível\n");

                                        for(i = 0; i <= 23; i++)
                                        {

                                            if(OpGrupo == Carro[i].Grupo)
                                            {
                                                printf("%d - ",seq);

                                                    gotoxy(x,y=y+1);
                                                    printf("%s", Carro[i].Model);

                                                if(Carro[i].ClienteCar == 0)
                                                {
                                                    gotoxy(x+11,y);
                                                    printf("[S]\n");
                                                }
                                                else
                                                {
                                                    gotoxy(x+11,y);
                                                    printf("[N]\n");
                                                }
                                                seq++;
                                                Sleep(500);;
                                            }

                                        }

                                        printf("\n\n*************************************\n");
                                        printf("Digite o código do carro desejado\n");
                                        printf("*************************************\n\n");
                                        printf("Opção: ");
                                        scanf("%d", &CodVeiculo);

                                        for(i = 0; i <= 23; i++)
                                        {
                                            if(Carro[i].Grupo == OpGrupo)
                                            {
                                                if(Carro[i].CodVeiculo == CodVeiculo)
                                                {
                                                    if(Carro[i].ClienteCar > 0)
                                                    {
                                                        Info(6);
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        CAlugado = 1;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    CAlugado = 0;
                                                }
                                            }
                                        }

                                        break;

                                    case 3:
                                        while(OpGrupo != 31 && OpGrupo != 32 && OpGrupo != 33 && OpGrupo != 34 && OpGrupo != 35 && OpGrupo != 36 && OpGrupo != 0)
                                        {
                                            seq = 1;
                                            x = 19;
                                            y = 20;

                                            system("cls");

                                            DadosUsuario(PosCli, OpTipoCarro, CodVeiculo,0 ,0);

                                            printf("******************** ## ESCOLHA UM TIPO ## ********************\n\n");

                                            printf("31 - SUV Manual\n");
                                            printf("32 - SUV Automático\n");
                                            printf("33 - Pick-Up Cabine Simples\n");
                                            printf("34 - Pick-Up Cabine Dupla\n");
                                            printf("35 - Pick-Up Cabine Dupla Automático\n");
                                            printf("36 - Van 15 Lugares\n");
                                            printf("0 - Sair\n\n");

                                            printf("Opção: ");
                                            scanf("%d", &OpGrupo);

                                           if(OpGrupo == 0)
                                            {
                                                system("cls || clear");
                                                Menu();
                                            }

                                            if(OpGrupo != 31 && OpGrupo != 32 && OpGrupo != 33 && OpGrupo != 34 && OpGrupo != 35 && OpGrupo != 36 && OpGrupo != 0)
                                            {
                                                Info(1);
                                                OpGrupo = 99;
                                            }
                                        }
                                        gotoxy(1,19);
                                        printf("\nCódigo");
                                        gotoxy(x,y);
                                        printf("Carro");
                                        gotoxy(x+11,y);
                                        printf("Disponível\n");

                                        for(i = 0; i <= 23; i++)
                                        {

                                            if(OpGrupo == Carro[i].Grupo)
                                            {
                                                printf("%d - ",seq);

                                                    gotoxy(x,y=y+1);
                                                    printf("%s", Carro[i].Model);

                                                if(Carro[i].ClienteCar == 0)
                                                {
                                                    gotoxy(x+11,y);
                                                    printf("[S]\n");
                                                }
                                                else
                                                {
                                                    gotoxy(x+11,y);
                                                    printf("[N]\n");
                                                }
                                                seq++;
                                                Sleep(700);
                                            }

                                        }

                                        printf("\n\n*************************************\n");
                                        printf("Digite o código do carro desejado\n");
                                        printf("*************************************\n\n");
                                        printf("Opção: ");
                                        scanf("%d", &CodVeiculo);

                                        for(i = 0; i <= 23; i++)
                                        {
                                            if(Carro[i].Grupo == OpGrupo)
                                            {
                                                if(Carro[i].CodVeiculo == CodVeiculo)
                                                {
                                                    if(Carro[i].ClienteCar > 0)
                                                    {
                                                        Info(6);
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        CAlugado = 1;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    CAlugado = 0;
                                                }
                                            }
                                        }

                                        break;
                                    case 4:
                                        MenuLoc();

                                    default:

                                        Info(1);

                                        break;

                                }


                            if(CAlugado == 1)
                            {
                                int dias, i;

                                system("cls");

                                TpSeg = 5;

                                while(TpSeg > 4)
                                {
                                    DadosUsuario(PosCli, OpTipoCarro, CodVeiculo, OpGrupo, 0);

                                    printf("******************** ######################## ********************\n");
                                    printf("*                       Saída de Veículos                        *\n");
                                    printf("*                            Seguro                              *\n");
                                    printf("******************** ######################## ********************\n\n");

                                    printf("1 - Gold\n");
                                    printf("2 - Diamond\n");
                                    printf("3 - Platinum\n");
                                    printf("4 - Sair\n\n");

                                    scanf("%d", &TpSeg);

                                    if(TpSeg > 5)
                                    {
                                        Info(1);
                                    }
                                }

                                switch(TpSeg)
                                {
                                    case 1:
                                        for(i = 0;i <= 23; i++)
                                        {
                                            if(Carro[i].Grupo == OpGrupo)
                                            {
                                                if(Carro[i].CodVeiculo == CodVeiculo)
                                                {
                                                    printf("\n\n*************************************\n");
                                                    printf("Dias pretendidos: \n");
                                                    scanf("%d", &dias);

                                                    CalculaData(dias);

                                                    CalculaValor(dias, OpGrupo, TpSeg, PosCli);

                                                    system("cls");

                                                    ConfirmaAluguel(CodCli, OpGrupo, CodVeiculo, TpSeg, dias);
                                                }
                                            }
                                        }

                                        break;

                                    case 2:
                                         for(i = 0;i <= 23; i++)
                                        {
                                            if(Carro[i].Grupo == OpGrupo)
                                            {
                                                if(Carro[i].CodVeiculo == CodVeiculo)
                                                {
                                                    printf("\n\n*************************************\n");
                                                    printf("Dias pretendidos: \n");
                                                    scanf("%d", &dias);

                                                    CalculaData(dias);

                                                    CalculaValor(dias, OpGrupo, TpSeg, PosCli);

                                                    system("cls");

                                                    ConfirmaAluguel(CodCli, OpGrupo, CodVeiculo, TpSeg, dias);
                                                }
                                            }
                                        }

                                        break;

                                    case 3:
                                        for(i = 0;i <= 23; i++)
                                        {
                                            if(Carro[i].Grupo == OpGrupo)
                                            {
                                                if(Carro[i].CodVeiculo == CodVeiculo)
                                                {
                                                    printf("\n\n*************************************\n");
                                                    printf("Dias pretendidos: \n");
                                                    scanf("%d", &dias);

                                                    CalculaData(dias);

                                                    CalculaValor(dias, OpGrupo, TpSeg, PosCli);

                                                    system("cls");

                                                    ConfirmaAluguel(CodCli, OpGrupo, CodVeiculo, TpSeg, dias);
                                                }
                                            }
                                        }
                                    case 4:
                                        Menu();
                                }
                            }
                            else
                            {
                                Info(1);
                                CodVeiculo = 0;
                            }
                        }while(OpTipoCarro);
                    }
                    if(ExistCli == 2)
                    {
                        Info(8);
                        ExistCli = 0;
                        MenuLoc();
                    }
                    else
                    {
                        Info(7);
                        ExistCli = 0;
                        MenuLoc();
                    }
                }
            }

            if(op == 2)
            {
                    printf("******************** ######################## ********************\n");
                    printf("*                       Saída de Veículos                        *\n");
                    printf("*                           Devolução                            *\n");
                    printf("******************** ######################## ********************\n\n");

                    printf("Código do cliente: ");
                    scanf("%d", &CodCli);

                    int icar, icli;

                    for(icli = 1; icli < 100; icli++)
                    {
                        if(CodCli == Cli[icli].CodCli)
                        {
                            for(icar = 0; icar <= 23; icar++)
                            {
                                if(Cli[icli].CodCli == Carro[icar].ClienteCar)
                                {
                                    PosCli = icli;
                                    CodV = Carro[icar].CodVeiculo;
                                    CodG = Carro[icar].Grupo;
                                    break;
                                }
                                else
                                {
                                    ExistCli = 1;
                                    PosCli = icli;
                                }
                            }
                        }
                    }

                    DevolucaoVeiculo(CodCli, CodG, CodV);

                    ExistCli = 0;

            }

            if(op == 3)
            {
                int i, x, xa, xb, xc, xd;

                x = 6;
                xa = 6;
                xb = 6;
                xc = 6;
                xd = 6;

                system("cls");
                printf("******************** ######################## ********************\n");
                printf("*                       Relatório de Veículos                    *\n");
                printf("******************** ######################## ********************\n");

                gotoxy(1, 5);
                printf("Cód. Veículo");
                gotoxy(20, 5);
                printf("Grupo");
                gotoxy(40, 5);
                printf("Modelo");
                gotoxy(60, 5);
                printf("Marca");
                gotoxy(80, 5);
                printf("Ano");

                for(i = 0; i<= 23; i++)
                {
                    gotoxy(2,x=x+1);
                    printf("%d", Carro[i].CodVeiculo);
                    Sleep(10);

                    gotoxy(20,xa=xa+1);
                    printf("%d", Carro[i].Grupo);
                    Sleep(10);

                    gotoxy(40,xb=xb+1);
                    printf("%s", &Carro[i].Model);
                    Sleep(10);

                    gotoxy(60,xc=xc+1);
                    printf("%s", &Carro[i].Marca);
                    Sleep(10);

                    gotoxy(80,xd=xd+1);
                    printf("%d", Carro[i].AnoCar);

                    Sleep(50);
                }

                getch();

                MenuLoc();

            }

            if(op == 4)
            {
                int i, y, x, xa, xb, xc, xd, xe, xf;

                x = 6;
                xa = 6;
                xb = 6;
                xc = 6;
                xd = 6;
                xe = 6;
                xf = 6;

                system("cls");
                printf("******************** ######################## ********************\n");
                printf("*                       Relatório de Locação                     *\n");
                printf("******************** ######################## ********************\n");

                gotoxy(1, 5);
                printf("Cód. Veículo");
                gotoxy(18, 5);
                printf("Modelo");
                gotoxy(30, 5);
                printf("Marca");
                gotoxy(45, 5);
                printf("Cliente");

                gotoxy(62, 5);
                printf("Data Loc.");

                gotoxy(75, 5);
                printf("Data Prev. Dev.");

                gotoxy(100, 5);
                printf("Valor Total");


                for(i = 0; i<=23; i++)
                {
                    if(Carro[i].ClienteCar != 0)
                    {
                        gotoxy(2,x=x+1);
                        printf("%d", Carro[i].CodVeiculo);

                        gotoxy(18,xa=xa+1);
                        printf("%s", &Carro[i].Model);

                        gotoxy(30,xb=xb+1);
                        printf("%s", &Carro[i].Marca);

                        for(y = 1; y< 100; y++)
                        {
                            if(Carro[i].ClienteCar == Cli[y].CodCli)
                            {
                                gotoxy(45,xc=xc+1);
                                printf("%s", &Cli[y].NomCli);
                            }
                        }

                        gotoxy(62,xd=xd+1);
                        printf("%s", &Carro[i].DataAlugado);

                        gotoxy(75, xe=xe+1);
                        printf("%s", &Carro[i].DataPrev);

                        gotoxy(100, xf=xf+1);
                        printf("R$%.2f", Carro[i].VlrTotal);

                    }
                }

                getch();
            }

            if(op == 5)
            {
                Menu();
            }
        }
    }
}

void CriaCarro(struct Veiculo Carro[24])
{

/*//    VEÍCULOS DO GRUPO 11*/

    Carro[0].CodVeiculo = 1;
    Carro[0].ClienteCar = 0;
    Carro[0].AnoCar = 2017;
    Carro[0].Grupo = 11;
    strcpy(Carro[0].Model, "Up");
    strcpy(Carro[0].Marca, "Wolkswagen");
    Carro[0].VlrBase = 50.0;

    Carro[1].CodVeiculo = 2;
    Carro[1].ClienteCar = 0;
    Carro[1].AnoCar = 2017;
    Carro[1].Grupo = 11;
    strcpy(Carro[1].Model, "Kwid");
    strcpy(Carro[1].Marca, "Renault");
    Carro[1].VlrBase = 50.0;


/*//    VEÍCULOS DO GRUPO 12*/

    Carro[2].CodVeiculo = 1;
    Carro[2].ClienteCar = 0;
    Carro[2].AnoCar = 2017;
    Carro[2].Grupo = 12;
    strcpy(Carro[2].Model, "Ká");
    strcpy(Carro[2].Marca, "Ford");
    Carro[2].VlrBase = 65.0;

    Carro[3].CodVeiculo = 2;
    Carro[3].ClienteCar = 0;
    Carro[3].AnoCar = 2017;
    Carro[3].Grupo = 12;
    strcpy(Carro[3].Model, "Onix");
    strcpy(Carro[3].Marca, "Chevrolet");
    Carro[3].VlrBase = 65.0;

    Carro[4].CodVeiculo = 3;
    Carro[4].ClienteCar = 0;
    Carro[4].AnoCar = 2017;
    Carro[4].Grupo = 12;
    strcpy(Carro[4].Model, "Sandero");
    strcpy(Carro[4].Marca, "Renault");
    Carro[4].VlrBase = 65.0;

/*//    VEÍCULOS DO GRUPO 13*/

    Carro[5].CodVeiculo = 1;
    Carro[5].ClienteCar = 0;
    Carro[5].AnoCar = 2017;
    Carro[5].Grupo = 13;
    strcpy(Carro[5].Model, "Fiesta");
    strcpy(Carro[5].Marca, "Ford");
    Carro[5].VlrBase = 75.0;

    Carro[6].CodVeiculo = 2;
    Carro[6].ClienteCar = 0;
    Carro[6].AnoCar = 2017;
    Carro[6].Grupo = 13;
    strcpy(Carro[6].Model, "Punto");
    strcpy(Carro[6].Marca, "Fiat");
    Carro[6].VlrBase = 75.0;

/*/    VEÍCULOS DO GRUPO 14*/

    Carro[7].CodVeiculo = 1;
    Carro[7].ClienteCar = 0;
    Carro[7].AnoCar = 2017;
    Carro[7].Grupo = 14;
    strcpy(Carro[7].Model, "Fiesta");
    strcpy(Carro[7].Marca, "Ford");
    Carro[7].VlrBase = 95.0;

/*//    VEÍCULOS DO GRUPO 21*/

    Carro[8].CodVeiculo = 1;
    Carro[8].ClienteCar = 0;
    Carro[8].AnoCar = 2017;
    Carro[8].Grupo = 21;
    strcpy(Carro[8].Model, "Ka+");
    strcpy(Carro[8].Marca, "Ford");
    Carro[8].VlrBase = 75.0;

    Carro[9].CodVeiculo = 2;
    Carro[9].ClienteCar = 0;
    Carro[9].AnoCar = 2018;
    Carro[9].Grupo = 21;
    strcpy(Carro[9].Model, "Logan");
    strcpy(Carro[9].Marca, "Renault");
    Carro[9].VlrBase = 75.0;

/*//    VEÍCULOS DO GRUPO 22*/

    Carro[10].CodVeiculo = 1;
    Carro[10].ClienteCar = 0;
    Carro[10].AnoCar = 2017;
    Carro[10].Grupo = 22;
    strcpy(Carro[10].Model, "HB20 S");
    strcpy(Carro[10].Marca, "Hyundai");
    Carro[10].VlrBase = 85.0;

    Carro[11].CodVeiculo = 2;
    Carro[11].ClienteCar = 0;
    Carro[11].AnoCar = 2016;
    Carro[11].Grupo = 22;
    strcpy(Carro[11].Model, "Prisma");
    strcpy(Carro[11].Marca, "Chevrolet");
    Carro[11].VlrBase = 85.0;


/*//    VEÍCULOS DO GRUPO 23*/

    Carro[12].CodVeiculo = 1;
    Carro[12].ClienteCar = 0;
    Carro[12].AnoCar = 2017;
    Carro[12].Grupo = 23;
    strcpy(Carro[12].Model, "HB20 S");
    strcpy(Carro[12].Marca, "Hyundai");
    Carro[12].VlrBase = 120.0;

    Carro[13].CodVeiculo = 2;
    Carro[13].ClienteCar = 0;
    Carro[13].AnoCar = 2017;
    Carro[13].Grupo = 23;
    strcpy(Carro[13].Model, "Prisma");
    strcpy(Carro[13].Marca, "Chevrolet");
    Carro[13].VlrBase = 120.0;

/*//    VEÍCULOS DO GRUPO 31*/

    Carro[14].CodVeiculo = 1;
    Carro[14].ClienteCar = 0;
    Carro[14].AnoCar = 2017;
    Carro[14].Grupo = 31;
    strcpy(Carro[14].Model, "Duster");
    strcpy(Carro[14].Marca, "Renault");
    Carro[14].VlrBase = 130.0;

    Carro[15].CodVeiculo = 2;
    Carro[15].ClienteCar = 0;
    Carro[15].AnoCar = 2017;
    Carro[15].Grupo = 31;
    strcpy(Carro[15].Model, "Renagade");
    strcpy(Carro[15].Marca, "Jeep");
    Carro[15].VlrBase = 130.0;

/*//    VEÍCULOS DO GRUPO 32*/

    Carro[16].CodVeiculo = 1;
    Carro[16].ClienteCar = 0;
    Carro[16].AnoCar = 2017;
    Carro[16].Grupo = 32;
    strcpy(Carro[16].Model, "Duster");
    strcpy(Carro[16].Marca, "Renault");
    Carro[16].VlrBase = 160.0;

    Carro[17].CodVeiculo = 2;
    Carro[17].ClienteCar = 0;
    Carro[17].AnoCar = 2017;
    Carro[17].Grupo = 32;
    strcpy(Carro[17].Model, "Renagade");
    strcpy(Carro[17].Marca, "Jeep");
    Carro[17].VlrBase = 160.0;

/*//    VEÍCULOS DO GRUPO 33*/

    Carro[18].CodVeiculo = 1;
    Carro[18].ClienteCar = 0;
    Carro[18].AnoCar = 2016;
    Carro[18].Grupo = 33;
    strcpy(Carro[18].Model, "Montana");
    strcpy(Carro[18].Marca, "Chevrolet");
    Carro[18].VlrBase = 100.0;

    Carro[19].CodVeiculo = 2;
    Carro[19].ClienteCar = 0;
    Carro[19].AnoCar = 2017;
    Carro[19].Grupo = 33;
    strcpy(Carro[19].Model, "Strada");
    strcpy(Carro[19].Marca, "Fiat");
    Carro[19].VlrBase = 100.0;

/*//    VEÍCULOS DO GRUPO 34*/

    Carro[20].CodVeiculo = 1;
    Carro[20].ClienteCar = 0;
    Carro[20].AnoCar = 2018;
    Carro[20].Grupo = 34;
    strcpy(Carro[20].Model, "Oroch");
    strcpy(Carro[20].Marca, "Renault");
    Carro[20].VlrBase = 180.0;

/*//    VEÍCULOS DO GRUPO 35*/

    Carro[21].CodVeiculo = 1;
    Carro[21].ClienteCar = 0;
    Carro[21].AnoCar = 2018;
    Carro[21].Grupo = 35;
    strcpy(Carro[21].Model, "Toro");
    strcpy(Carro[21].Marca, "Fiat");
    Carro[21].VlrBase = 200.0;

    Carro[22].CodVeiculo = 2;
    Carro[22].ClienteCar = 0;
    Carro[22].AnoCar = 2017;
    Carro[22].Grupo = 35;
    strcpy(Carro[22].Model, "Oroch");
    strcpy(Carro[22].Marca, "Renault");
    Carro[22].VlrBase = 200.0;

/*//    VEÍCULOS DO GRUPO 36*/

    Carro[23].CodVeiculo = 1;
    Carro[23].ClienteCar = 0;
    Carro[23].AnoCar = 2017;
    Carro[23].Grupo = 36;
    strcpy(Carro[23].Model, "Ducato");
    strcpy(Carro[23].Marca, "Fiat");
    Carro[23].VlrBase = 130.0;

    return Carro;
}

void criacliteste(struct Cliente cli[100])
{
    cli[1].CodCli = 10;
    strcpy(cli[1].NomCli, "Davi");
    strcpy(cli[1].CPF, "40684748851");
    cli[1].Idoso = 1;
    cli[1].Ong = 0;

    cli[2].CodCli = 2;
    strcpy(cli[2].NomCli, "Roberto");
    strcpy(cli[2].CPF, "92832");
    cli[2].Idoso = 0;
    cli[2].Ong = 0;

    cli[3].CodCli = 5;
    strcpy(cli[3].NomCli, "Robson");
    strcpy(cli[3].CPF, "00001293");
    cli[3].Idoso = 0;
    cli[4].Ong = 1;

    cli[4].CodCli = 3;
    strcpy(cli[4].NomCli, "Fernando");
    strcpy(cli[4].CPF, "12837281722");
    cli[3].Idoso = 1;
    cli[4].Ong = 0;
}

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void MenuRentCar2()
{
    system("cls");

    gotoxy(26,3);
    printf("LEGAL RENT A CAR");
    gotoxy(30,4);
    printf("BEM VINDO!");

    int i, a, b, c, d ;

    a = 1;
    b = 67;
    c = 6;
    d = 0;



    for(i = 0; i < 67; i++)
    {
        gotoxy(d=d+1,1);
        printf("#");
        Sleep(10);
    }

    for(i = 0; i < 5; i++)
    {
        gotoxy(67, a=a+1);
        printf("#");
        Sleep(10);
    }

    for(i = 0; i < 67; i++)
    {
        gotoxy(b=b-1, 6);
        printf("#");
        Sleep(10);
    }

    for(i = 0; i < 5; i++)
    {
        gotoxy(1, c=c-1);
        printf("#");
        Sleep(10);
    }

/*    Apenas para pular linha.*/
    printf("\n\n\n\n\n");

}

void MenuRentCar()
{
    system("cls");
    printf("##################################################################");
    gotoxy(66,2);
    printf("#");
    gotoxy(1,2);
    printf("#");
    gotoxy(66,3);
    printf("#");
    gotoxy(1,3);
    printf("#");
    gotoxy(26,3);
    printf("LEGAL RENT A CAR");
    gotoxy(30,4);
    printf("BEM VINDO!");
    gotoxy(66,4);
    printf("#");
    gotoxy(1,4);
    printf("#");
    gotoxy(66,5);
    printf("#");
    gotoxy(1,5);
    printf("#");

    printf("\n##################################################################");
}

void DadosUsuario(int p, int Grp, int CodVeiculo, int SGrupo, int dev)
{
    int y1, y2;

    y1 = 5;
    y2 = 6;

    system("cls");
    printf("********************************************\n");
    gotoxy(15,2);
    printf("DADOS DO CLIENTE");
    gotoxy(1,2);
    printf("*");
    gotoxy(1,3);
    printf("*");
    gotoxy(1,4);
    printf("*");
    gotoxy(44,2);
    printf("*");
    gotoxy(44,3);
    printf("*");
    gotoxy(44,4);
    printf("*");
    gotoxy(4,4);
    printf("Usuário: %s", &Cli[p].NomCli);

    if(Grp == 1)
    {

        gotoxy(44,y1);
        printf("*");
        gotoxy(1,y1);
        printf("*");
        gotoxy(4,y1);
        printf("Grupo: 1 - Hatch");
        y1++;
        y2++;
    }
    else
    {
        if(Grp == 2)
        {

            gotoxy(44,y1);
            printf("*");
            gotoxy(1,y1);
            printf("*");
            gotoxy(4,y1);
            printf("Grupo: 2 - Sedan");
            y1++;
            y2++;
        }
        else
        {
           if(Grp == 3)
            {

                gotoxy(44,y1);
                printf("*");
                gotoxy(1,y1);
                printf("*");
                gotoxy(4,y1);
                printf("Grupo: 3 - Utilitário");
                y1++;
                y2++;
            }
        }
    }

    if(CodVeiculo > 0)
    {

        gotoxy(44,y1);
        printf("*");
        gotoxy(44,y2);
        printf("*");
        gotoxy(1,y1);
        printf("*");
        gotoxy(1,y2);
        printf("*");
        int i;
        for(i = 0; i <= 23; i++)
        {
            if(SGrupo == Carro[i].Grupo)
            {
                if(Cli[p].CodCli == Carro[i].ClienteCar)
                {
                    gotoxy(4,y1);
                    printf("Carro: %s", &Carro[i].Model);

                    if(dev > 0)
                    {
                        gotoxy(4,y2);
                        printf("Data Devolução: %s", &Carro[i].DataPrev);
                    }
                }
            }
        }
    }

    printf("\n********************************************\n\n");
}

void ConfirmaAluguel(int CodCli, int OpGrupo, int CodVeiculo, int TpSeg, int Dias)
{
    int i, x, y;
    char ConfAlug[1];

    x = 0;
    y = 30;

    while(x == 0)
    {
        system("cls");
        printf("******************** ######################## ********************\n");
        printf("*                       Informações do                           *\n");
        printf("*                          contrato                              *\n");
        printf("******************** ######################## ********************\n\n");

        for(i = 0; i <= 100; i++)
        {
            if(Cli[i].CodCli == CodCli)
            {
                gotoxy(11,7);
                printf("************ Dados do Cliente ************");
                gotoxy(14,8);
                printf("Nome do Cliente: %s", &Cli[i].NomCli);
                gotoxy(14,9);
                printf("Código de Cadastro: %d", Cli[i].CodCli);
            }
        }
        for(i = 0; i<=23; i++)
        {
            if(Carro[i].Grupo == OpGrupo)
            {
                if(Carro[i].CodVeiculo == CodVeiculo)
                {
                    gotoxy(11,11);
                    printf("************ Dados do Veículo ************");
                    gotoxy(14,12);
                    printf("Modelo: %s", &Carro[i].Model);
                    gotoxy(14,13);
                    printf("Marca: %s", &Carro[i].Marca);
                    gotoxy(14,14);
                    printf("Ano: %d", Carro[i].AnoCar);

                    switch(TpSeg)
                    {
                        case 1:
                            gotoxy(14,15);
                            printf("Seguro: Gold");
                            break;

                        case 2:
                            gotoxy(14,15);
                            printf("Seguro: Diamond");
                            break;

                        case 3:
                            gotoxy(14,15);
                            printf("Seguro: Platinum");
                            break;
                    }
                }
            }
        }
        gotoxy(11,17);
        printf("************ $$ Valores $$ ************");
        gotoxy(14,18);
        printf("Data de locação: %s", &DataAtual);
        gotoxy(14,19);
        printf("Data prevista para devolução: %s", &DataPrevista);
        gotoxy(14,20);
        printf("Valor total das diárias: R$%.2f", VlrDia);
        gotoxy(14,21);
        printf("Valor do Seguro: R$%.2f", VlrSeg);
        gotoxy(14,22);
        printf("Valor do Desconto: R$%.2f", VlrDesc);
        gotoxy(14,23);
        printf("Valor Total: R$%.2f", VlrTotal);



        printf("\n\nConfirmar aluguel do veículo (S/N): ");
        scanf("%s", &ConfAlug);

        if(strcmp(ConfAlug, "S") != 0 && strcmp(ConfAlug, "s") != 0 && strcmp(ConfAlug, "N") != 0 && strcmp(ConfAlug, "n") != 0)
        {
            system("cls");
            gotoxy(45,10);
            printf("Informe no formato correto! (S/N)");
            Sleep(1000);
        }

        else
        {
            if(strcmp(ConfAlug, "N") == 0 && strcmp(ConfAlug, "n") == 0)
            {
                MenuLoc();
            }

            else
            {
                x = 1;
                y = 35;
                for(i = 0; i < 30; i++)
                {
                    system("cls");
                    gotoxy(y=y+1,10);
                    printf("*");
                    Sleep(10);
                }

                for(i = 0; i <= 23; i++)
                {
                    if(Carro[i].Grupo == OpGrupo)
                    {
                        if(Carro[i].CodVeiculo == CodVeiculo)
                        {
                            Carro[i].ClienteCar = CodCli;
                            Carro[i].Seg = TpSeg;
                            strcpy(Carro[i].DataAlugado, DataAtual);
                            strcpy(Carro[i].DataPrev, DataPrevista);
                            Carro[i].VlrBase = VlrB;
                            Carro[i].VlrSeg = VlrSeg;
                            Carro[i].VlrDesc = VlrDesc;
                            Carro[i].VlrTotal = VlrTotal;
                        }
                    }
                }

                    system("cls");
                    gotoxy(45,10);
                    printf("VEÍCULO ALUGADO COM SUCESSO!\n");
                    gotoxy(46,11);
                    printf("OBRIGADO PELA PREFERÊNCIA!");
                    Sleep(2800);
                    system("CLS || CLEAR");

                    Menu();
            }
        }
    }
}

int VerificaCodCliCLiente(int CodCli)
{
    int i;
    for(i = 1; i < 100; i++)
    {
        if(Cli[i].CodCli == CodCli)
        {
            CodCli++;
            VerificaCodCliCLiente(CodCli);
        }
    }

    return CodCli;
}

void Info(int i,int CodIndex)
{
    int x,y, time;

    x = 45;
    y = 10;
    time = 2000;

    switch(i)
    {
        case 1:
            system("cls || clear");

            gotoxy(x,y);
            printf("DIGITE UMA OPÇÃO VÁLIDA!\n\n");

            Sleep(time);

            system("cls || clear");
            break;

        case 2:
            system("cls");

            gotoxy(x,y);
            printf("IDADE MENOR QUE 18 ANOS!\n");

            Sleep(time);

            system("cls");
            break;

        case 3:
            system("cls || clear");

            gotoxy(x,y);
            printf("O PROGRAMA SERÁ ENCERRADO!\n\n");

            Sleep(time);

            system("cls || clear");
            break;

        case 4:
            system("cls");

            gotoxy(x,y);
            printf("CPF INVÁLIDO!\n");
            Sleep(time);

            system("cls");
            break;

        case 5:
            system("cls || clear");

            gotoxy(x,y);
            printf("CLIENTE CADASTRADO COM SUCESSO!\n");

            gotoxy(50,11);
            printf("CÓDIGO CADASTRADO: %d", Cli[CodIndex].CodCli);

            Sleep(time);

            system("CLS || CLEAR");
            break;

        case 6:
            system("cls || clear");

            gotoxy(x,y);
            printf("VEÍCULO NÃO DISPONÍVEL!\n\n");

            Sleep(time);

            system("cls || clear");
            break;

        case 7:
            system("cls || clear");

            gotoxy(x,y);
            printf("CLIENTE NÃO ENCONTRADO!\n\n");

            Sleep(time);

            system("cls || clear");
            break;
        case 8:
            system("cls || clear");

            gotoxy(x,y);
            printf("CLIENTA JÁ CONSTA CARRO ALUGADO!\n\n");

            Sleep(time);

            system("cls || clear");
            break;

        case 9:
            system("cls || clear");

            gotoxy(x,y);
            printf("INFORME NO FORMATO CORRETO (S/N)!\n\n");

            Sleep(time);

            system("cls || clear");
            break;

        case 10:
            system("cls || clear");

            gotoxy(x,y);
            printf("*********** INFORMATIVO !! ***********");
            gotoxy(x,y=y+1);
            printf("* Veículo com devolução em atraso    *");
            gotoxy(x,y=y+1);
            printf("*     Atraso de %d horas             *", dif);
            gotoxy(x,y=y+1);
            printf("*          Haverá multa!             *");
            gotoxy(x,y=y+1);
            printf("**************************************");

            Sleep(time);

            system("cls || clear");
            break;

        case 11:
            system("cls || clear");

            gotoxy(x,y);
            printf("NENHUM PAGAMENTO RECEBIDO!\n\n");

            Sleep(time);

            system("cls || clear");
            break;

        case 12:
            system("cls || clear");

            gotoxy(x,y);
            printf("FORMATO DE DATA INCORRETO!\n\n");
            gotoxy(x,y=y+1);
            printf("FORMATO DD/MM/AAAA\n\n");

            Sleep(time);

            system("cls || clear");
            break;

        case 13:
            system("cls || clear");

            gotoxy(x,y);
            printf("FORMATO DE HORA INCORRETO!\n\n");
            gotoxy(x,y=y+1);
            printf("FORMATO HH:MM\n\n");

            Sleep(time);

            system("cls || clear");
            break;
    }
}

void CalculaValor(int dias, int Grupo, int TpSeg, int IndexCli)
{
    int i;
    VlrDesc = 0;
    VlrTotal = 0;
    VlrDia = 0;

    for(i = 0; i <= 23; i++)
    {
        if(Carro[i].Grupo == Grupo)
        {
            VlrB = Carro[i].VlrBase;
            VlrDia = VlrB * dias;
            break;
        }
    }

    switch(TpSeg)
    {
        /*GOLD*/
        case 1:
            VlrSeg = VlrDia * 0.1;
            break;

        /*DIAMOND*/
        case 2:
            VlrSeg = VlrDia * 0.2;
            break;

        /*PLATINUM*/
        case 3:
            VlrSeg = VlrDia * 0.3;
            break;
    }

    VlrTotal = VlrDia + VlrSeg;

    if(Cli[IndexCli].Ong == 1)
    {
        VlrDesc = VlrTotal * 0.15;
    }
    else
    {
         if(Cli[IndexCli].Idoso == 1)
        {
            VlrDesc = VlrTotal * 0.10;
        }
    }

    VlrTotal = VlrTotal - VlrDesc;
}

void DevolucaoVeiculo(int CodCli,int Grupo, int CodVeiculo)
{
    system("cls");

    struct tm checkdata;

    int TpSeg
        ,AnoCarro
        ,i
        ,PosCli
        ,DataOK;
    char NomeCliente[50]
        ,Modelo[50]
        ,Marca[50]
        ,Op[1];

    float VlrHora, Multa;

    DataOK = 0;

    for(i = 0; i <= 100; i++)
        {
            if(Cli[i].CodCli == CodCli)
            {
                strcpy(NomeCliente, Cli[i].NomCli);
                PosCli = i;
            }
        }

        for(i = 0; i<=23; i++)
        {
            if(Carro[i].Grupo == Grupo)
            {
                if(Carro[i].CodVeiculo == CodVeiculo)
                {
                    TpSeg = Carro[i].Seg;
                    AnoCarro = Carro[i].AnoCar;
                    strcpy(DataAtual, &Carro[i].DataAlugado);
                    strcpy(DataPrevista, &Carro[i].DataPrev);
                    strcpy(Modelo, &Carro[i].Model);
                    strcpy(Marca, &Carro[i].Marca);

                    VlrB = Carro[i].VlrBase;
                    VlrSeg = Carro[i].VlrSeg;
                    VlrDesc = Carro[i].VlrDesc;
                    VlrTotal = Carro[i].VlrTotal;
                }
            }
        }

    while(DataOK == 0)
    {

        DadosUsuario(PosCli, 0, CodVeiculo, Grupo, 1);

        printf("******************** ######################## ********************\n");
        printf("*                       Saída de Veículos                        *\n");
        printf("*                           Devolução                            *\n");
        printf("******************** ######################## ********************\n\n");

        printf("Digite a data de devolução (dd/MM/yyyy): ");
        scanf("%s", DataDevolucao);

        if(sscanf(DataDevolucao, "%d/%d/%d", &checkdata.tm_mday, &checkdata.tm_mon, &checkdata.tm_year) < 3)
        {
            Info(12, 0);
        }
        else
        {
            printf("\nDigite a hora de devolução (H:M): ");
            scanf("%s", HoraDevolucao);

            DataOK = 1;

        }
    }

    CalcDataDevolucaoCarro(DataPrevista, DataDevolucao, HoraDevolucao);

    if(dif > 0)
    {
       Info(10, 0);

       VlrHora = VlrB / 24;
       VlrHora = VlrHora * dif;
       VlrTotal = VlrTotal + VlrHora;

       /*MULTA DE 10%*/
       Multa = VlrTotal * 0.10;

       VlrTotal = VlrTotal + Multa;
    }
    if(dif < 0)
    {
        dif = 0;
        Multa = 0;
    }

    system("cls");
    printf("\n\n******************** ######## Dados da Locação ######## ********************\n");


    gotoxy(11,7);
    printf("************ Dados do Cliente ************");
    gotoxy(14,8);
    printf("Nome do Cliente: %s", &NomeCliente);
    gotoxy(14,9);
    printf("Código de Cadastro: %d", CodCli);

    gotoxy(11,11);
    printf("************ Dados do Veículo ************");
    gotoxy(14,12);
    printf("Modelo: %s", &Modelo);
    gotoxy(14,13);
    printf("Marca: %s", &Marca);
    gotoxy(14,14);
    printf("Ano: %d", AnoCarro);


    switch(TpSeg)
    {
        case 1:
            gotoxy(14,15);
            printf("Seguro: Gold");
            break;

        case 2:
            gotoxy(14,15);
            printf("Seguro: Diamond");
            break;

        case 3:
            gotoxy(14,15);
            printf("Seguro: Platinum");
            break;
    }


    gotoxy(11,17);
    printf("************ $$ Valores $$ ************");
    gotoxy(14,18);
    printf("Data de Locação: %s", &DataAtual);
    gotoxy(14,19);
    printf("Data prevista para devolução: %s", &DataPrevista);
    gotoxy(14,20);
    printf("Data de Devolução: %s - %s", &DataDevolucao, &HoraDevolucao);
    gotoxy(14,21);
    printf("Total de Horas em Atraso: %d Hora(s)", dif);
    gotoxy(14,22);
    printf("Valor da Multa: R$%.2f", Multa);

    gotoxy(14,23);
    printf("Valor Total: R$%.2f", VlrTotal);

    printf("\n\nConfirma devolução? (S/N)");
    scanf("%s", &Op);

    if(strcmp(Op, "s") == 0 && strcmp(Op, "S") == 0)
    {
        Menu();
    }
    else
    {
        int i;

        for(i = 0; i<=100; i++)
        {
            if(Fin[i].CodCliente == 0)
            {
                strcpy(Fin[i].NomeCli, &NomeCliente);
                strcpy(Fin[i].DataAlugado, &DataAtual);

                Fin[i].CodCliente = CodCli;

                Fin[i].VlrPago = VlrTotal;
                break;
            }
        }

        for(i = 0; i <= 23; i++)
        {
            if(Carro[i].Grupo == Grupo && Carro[i].ClienteCar == CodCli)
            {
                Carro[i].VlrSeg = 0;
                Carro[i].VlrDesc = 0;
                Carro[i].VlrTotal = 0;

                Carro[i].ClienteCar = 0;
                strcpy(Carro[i].DataAlugado, "0");
                strcpy(Carro[i].DataPrev, "0");

                break;
            }
        }

        x = 1;
        y = 65;
        for(i = 0; i < 30; i++)
        {
            system("cls");
            gotoxy(y=y-1,10);
            printf("*");
            Sleep(10);
        }
        system("cls");
        gotoxy(45,10);
        printf("VEÍCULO DEVOLVIDO!\n");
        gotoxy(46,11);
        printf("OBRIGADO PELA PREFERÊNCIA!");
        Sleep(2800);
        system("CLS || CLEAR");

        Menu();
    }
}
