/*
Questões:
1) Entenda e comente o código a seguir.
2) Implemente a função 'calculaPontos'.
   Lembre-se de que sua implementação deve
   devolver o número do documento do motorista
   com maior número de pontos.
*/

#include <stdio.h>
#define TOTAL 1

struct cadastro{
    char nome[20];
    int documento;
    int qtdeMultas;
    int pontosPerdidos;
    float valorMulta;
};

typedef struct cadastro TCadastro;

TCadastro cadastraNovoMotorista()
{
    TCadastro c;
    scanf("%s", c.nome);
    scanf("%d %d %d %f", &c.documento, &c.qtdeMultas, &c.pontosPerdidos, &c.valorMulta);
    return c;
}

void mostraCadastro(TCadastro c)
{
    printf("%s\n", c.nome);
    printf("%d %d %f\n", c.qtdeMultas, c.pontosPerdidos, c.valorMulta);
}

float calculaMultas(TCadastro *motoristas)
{
    int i;
    float soma = 0.0;
    for(i = 0; i < TOTAL; i++)
        soma += motoristas[i].valorMulta;

    return soma;
}


int calculaPontos(TCadastro motoristas[])
{
    /*Sua implementacao deve ser incluída AQUI*/
    return 0;
}

int main()
{
    TCadastro motoristas[TOTAL];
    int i;
    for(i = 0; i < TOTAL; i++)
        motoristas[i] = cadastraNovoMotorista();

    /*Descomente estas linhas para mostrar os
      cadastros lidos.
    for(i = 0; i < TOTAL; i++)
        mostraCadastro(motoristas[i]);*/

    printf("Valor total de multas: R$ %.2f\n", calculaMultas(motoristas));
    printf("Motorista %d tem mais pontos perdidos\n", calculaPontos(motoristas));
    return 0;
}
