/*//
//typedef struct {
//    int ano;
//    short mes;
//    short dia;
//} Data;
*/
struct Cliente
{
    char NomCli[30]
        ,CPF[11];


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


};


