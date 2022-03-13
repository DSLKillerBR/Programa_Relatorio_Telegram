/******************************************************************************
        AUTOR: BRENO PINHEIRO DE OLIVEIRA

        PROGRAMA PARA GERAÇÃO DE MENSAGENS AUTOMÁTICAS PARA UTILIZAR NO WHATSAPP


                    O programa não possui fim comercial, apenas para
                    uso pessoal. O mesmo gera um arquivo com um padrão
                    de mensagens que usarei para conseguir acompanhar
                    negociações que faço utilizando Criptomoedas.


*******************************************************************************/

#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");
        
    

    printf("\n---------------------------------------------------\n \n \n ");

    printf("PROGRAMA DE GERADOR DE RELATÓRIOS PARA WHATSAPP"); //imprimindo uma mensagem para que o usuário identifique o nome do programa

    printf("\n \n \n--------------------------------------------------- \n \n\n");
        
    char controle; // variável para controlar a repetição do programa
          
    do {

        // criando as variáveis que serão utilizadas. Todas estão definidas como double para que possamos utilizar as casas decimais
         double dolar = 0, lucro_total_dolar = 0, lucro_trade_dolar = 0, lucro_total_real = 0, lucro_trade_real = 0, valor_inicial = 0, valor_final = 0, porcentagem_lucro =0, alavancagem =0, valor_moeda_compra =0, quantidade_negociada = 0, valor_moeda_venda = 0;

         FILE *arquivo;
         // criando, caso não exista, o arquivo "mensagem.txt". Se o arquivo existir, ele abrirá e editará o mesmo.
         arquivo = fopen("mensagem.txt", "a");
        
         char data_compra[50]; // criando o array que receberá a data de compra
         char data_venda[50];  // criando o array que receberá a data de venda
         char tipo; // criando a variável que receberá o tipo da negociação
        
         printf("\n Digite o tipo da negociação [ L para LONG e S para SHORT]:  "); // solicitando ao usuário que ele digite o tipo da negociação
         tipo = getchar(); 


         printf("\n Digite a data da compra:  ");
         scanf("%s", data_compra); // solicitando ao usuário que ele digite a data que fez a compra

         printf("\n Digite a data da venda:  ");
         scanf("%s", data_venda); // solicitando ao usuário que ele informe a data que fez a venda das moedas

         if(arquivo == NULL) // se não for possível abrir o arquivo, ele informa que gouve erro ao tentar abrir o mesmo
         {
                printf("Erro na abertura do arquivo!");
                return 1;
         }



         printf("\n Digite o valor de compra da moeda (em dolar): $ ");
         scanf("%lf", &valor_moeda_compra); // solicitando ao usuário o valor gasto por moeda, em dólar
        
         printf("\n Digite o valor de venda da moeda (em dolar): $ ");
         scanf("%lf", &valor_moeda_venda); // solicitando ao usuário o valor recebido por moeda, em dólar
        
         printf("\n Digite a quantidade de moedas negociadas : ");
         scanf("%lf", &quantidade_negociada); // solicitando ao usuário a quantidade de moedas negociadas (não é a soma da quantidade vendida + comprada, é apenas uma das duas quantias)


  
         valor_inicial = quantidade_negociada * valor_moeda_compra; // calculando o valor que a conta tinha ao iniciar a negociação, ou seja, o valor gasto para comprar as moedas

         valor_final = quantidade_negociada * valor_moeda_venda; // calculando o valor que a conta tinha quando fechou a negociação, ou seja, o valor recebido ao vender as moedas
  
    

         printf("\n Digite o lucro total antes da ultima negociação (em dolar): $ ");
         scanf("%lf", &lucro_total_dolar); // solicitando ao usuário os lucros ganhos antes desta negociação
    
        
         printf("\n Digite o valor da cotação do dólar no dia da venda: R$ ");
         scanf("%lf", &dolar); // solicitando ao usuário o valor que o dólar estava no dia da venda
        
   
        
         if (tipo == 'S') // quando uma negociação é do tipo SHORT, o lucro fica negativo, então criei essa exceção para que os valores negativos sejam transformados em valores positivos
         { 

                lucro_trade_dolar = (valor_final - valor_inicial) * -1; // tirando o sinal de negativo do lucro de operações SHORT
              
         }
         else 
         {
               
                lucro_trade_dolar = valor_final - valor_inicial; // calculando o lucro da negociação para negociações LONG;     
               
         }

         lucro_total_dolar = lucro_total_dolar + lucro_trade_dolar; // calculando o lucro de todas as negociações

         lucro_trade_real = lucro_trade_dolar  * dolar; // calculando o lucro da negociação e convertendo para o real

         lucro_total_real = lucro_total_dolar * dolar; // calculando o lucro de todas as negociações e convertendo para o real
  
         porcentagem_lucro = (lucro_trade_dolar * 100) / valor_inicial; // calculando a porcentagem de lucro
    

  
        
        /*
                        IMPRIMINDO NO ARQUIVO "mensagem.txt"
        */

        fprintf(arquivo, "\n---------------------------------------------------\n \n \n "); // imprimindo uma linha divisória entre as negociações, para que haja organização caso tenha mais de um trade no mês

        fprintf(arquivo, "\n *DATA DA COMPRA:* %s", data_compra); // imprimindo a data inicial (compra) da negociação

        fprintf(arquivo, "\n *DATA DA VENDA:* %s", data_venda); // imprimindo a data final (venda) da negociação
  
        fprintf(arquivo, "\n *Valor Inicial:* $%.2lf", valor_inicial); // imprimindo o valor que tinha na conta no ínicio da negociação (valor utilizado para comprar as moedas)

        fprintf(arquivo, "\n *Valor Final:* $%.2lf", valor_final); // imprimindo o valor que tinha após o fim da negociação (valor recebido após a venda das moedas)

        fprintf(arquivo, "\n *Lucro negociação em dólar:* $%.2lf", lucro_trade_dolar); // imprimindo o lucro obtido na negociação (em dólar)
        
        fprintf(arquivo, "\n *Lucro negociação em real:* R$%.2lf", lucro_trade_real); // imprimindo o lucro obtido na negociação (em real)

        fprintf(arquivo, "\n *Lucro total em dólar:* $%.2lf", lucro_total_dolar); // imprimindo o lucro obtido em todas negociações do mês (em dólar)
       
        fprintf(arquivo, "\n *Lucro total em real:* R$%.2lf", lucro_total_real); // imprimindo o lucro obtido em todas negociações do mês (em real)

        fprintf(arquivo, "\n *Porcentagem Lucro:* %.2lf%%", porcentagem_lucro);  // imprimindo a porcentagem de lucro obtido na negociação

        fprintf(arquivo, "\n \n \n---------------------------------------------------\n "); // imprimindo uma linha divisória entre as negociações, para que haja organização caso tenha mais de um trade no mês

        printf("\n Os dados foram gravados no arquivo 'mensagem.txt' com sucesso!!!\n"); // informando ao usuário que os dados foram gravados no arquivo "mensagem.txt"
            
        printf ("\n Deseja parar? [ D para SIM e N para NÃO]  ");
        control = getchar();
            
        } while (controle != 'S');
                
                
    printf(" \n -----------------------------------------------");
    printf(" \n         Fim do programa!\n");
    printf(" \n    Pressione qualquer tecla para sair\n");
    printf(" ----------------------------------------------- \n");

    return 0;
}
