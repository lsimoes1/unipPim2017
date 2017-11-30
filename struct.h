//
//typedef struct {
//    int ano;
//    short mes;
//    short dia;
//} Data;

struct Cliente
{
    char NomCli[30]
        ,CPF[11];

//    Data DataNascimento;

    int CodCli,
        Idade;
};

struct Veiculo
{
    int CodVeiculo,
        ClienteCar,
        AnoCar,
        Grupo,
        Seg;

    char Model[20],
        Marca[20];


//    Data DataRetirada
//        ,DataEntrega;

};


