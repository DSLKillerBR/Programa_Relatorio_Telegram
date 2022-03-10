/******************************************************************************


        PROGRAMA PARA GERAÇÃO DE MENSAGENS AUTOMÁTICAS PARA UTILIZAR NO WHATSAPP


                    O programa não possui fim comercial, apenas para
                    uso pessoal. O mesmo gera um arquivo com um padrão
                    de mensagens que usarei para conseguir acompanhar
                    trades que faço utilizando Criptomoedas.


*******************************************************************************/

#include <stdio.h>

int main()
{

    printf("\n ---------------------------------------------------\n \n \n ");

    printf("PROGRAMA DE GERADOR DE RELATÓRIOS PARA WHATSAPP");

    printf("\n \n \n--------------------------------------------------- \n \n\n");

  
    double lucro_total = 0, lucro_trade = 0, valor_inicial = 0, valor_final = 0, porcentagem_lucro =0, alavancagem =0, valor_moeda_compra =0, quantidade_negociada = 0, valor_moeda_venda = 0;

    FILE *arquivo;

    arquivo = fopen("mensagem.txt", "a");

    char data_compra[50];
    char data_venda[50];

    printf("\n Digite a data da compra:  ");
    scanf("%s", data_compra);

    printf("\n Digite a data da venda:  ");
    scanf("%s", data_venda);

    if(arquivo == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }



    printf("\n Digite o valor de compra da moeda: ");
    scanf("%lf", &valor_moeda_compra);

    printf("\n Digite a quantidade de moedas negociadas: ");
    scanf("%lf", &quantidade_negociada);

    printf("\n Digite o valor de venda da moeda: ");
    scanf("%lf", &valor_moeda_venda);
  
    valor_inicial = quantidade_negociada * valor_moeda_compra;

    valor_final = quantidade_negociada * valor_moeda_venda;
  
    lucro_trade = valor_final - valor_inicial;

    printf("\n Digite o lucro total antes do ultimo trade: ");
    scanf("%lf", &lucro_total);

    lucro_total = lucro_total + lucro_trade;

    porcentagem_lucro = (lucro_trade * 100) / valor_inicial;

    fprintf(arquivo, "\n ---------------------------------------------------\n \n \n ");

    fprintf(arquivo, "\n *DATA DA COMPRA:* %s", data_compra);

    fprintf(arquivo, "\n *DATA DA VENDA:* %s", data_venda);  
  
    fprintf(arquivo, "\n *Valor Inicial:* R$%.2lf", valor_inicial);

    fprintf(arquivo, "\n *Valor Final:* R$%.2lf", valor_final);

    fprintf(arquivo, "\n *Lucro Trade:* R$%.2lf", lucro_trade);

    fprintf(arquivo, "\n *Lucro total:* R$%.2lf", lucro_total);

    fprintf(arquivo, "\n *Porcentagem Lucro:* %.2lf%%", porcentagem_lucro);

    fprintf(arquivo, "\n \n \n---------------------------------------------------\n ");

    printf("\n Os dados foram gerados no arquivo 'mensagem.txt'!!!\n");

    return 0;
}
