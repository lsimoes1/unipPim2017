struct Financeiro
{
    char NomeCli[30], DataAlugado[50];

    int CodCliente;

    float VlrPago;
};

struct Cliente
{
    char NomCli[30]
        ,CPF[11];


    int CodCli,
        Idade,
        Idoso,
        Ong,
        Pg;
};

struct Veiculo
{
    int CodVeiculo,
        ClienteCar,
        AnoCar,
        Grupo,
        Seg;

    float VlrBase
        ,VlrSeg
        ,VlrDesc
        ,VlrTotal;

    char Model[20],
        Marca[20],
        DataAlugado[30],
        DataPrev[30];
};


