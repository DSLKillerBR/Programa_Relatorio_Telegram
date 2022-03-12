/******************************************************************************
        AUTOR: BRENO PINHEIRO DE OLIVEIRA

        PROGRAMA PARA GERAÇÃO DE MENSAGENS AUTOMÁTICAS PARA UTILIZAR NO WHATSAPP


                    O programa não possui fim comercial, apenas para
                    uso pessoal. O mesmo gera um arquivo com um padrão
                    de mensagens que usarei para conseguir acompanhar
                    negociações que faço utilizando Criptomoedas.


*******************************************************************************/

import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    System.out.println("\n---------------------------------------------------\n \n \n ");

    System.out.println("PROGRAMA DE GERADOR DE RELATÓRIOS PARA WHATSAPP");

    System.out.println("\n \n \n--------------------------------------------------- \n \n\n");

    // criando as variáveis que serão utilizadas. Todas estão definidas como double para que possamos utilizar as casas decimais
    double dolar = 0, lucro_total_dolar = 0, lucro_trade_dolar = 0, lucro_total_real = 0, lucro_trade_real = 0, porcentagem_lucro =0, alavancagem =0, valor_moeda_compra =0, quantidade_negociada = 0, valor_moeda_venda = 0;


    System.out.println("\n Digite o valor da compra:  ");
    Scanner scanner = new Scanner(System.in); // solicitando ao usuário que ele digite a data que fez a compra
    double valor_inicial = scanner.nextDouble();


    System.out.println("\n Digite o valor da venda:  ");

    double valor_final = scanner.nextDouble ();// solicitando ao usuário que ele informe a data que fez a venda das moedas
     System.out.println("\n Valor da compra:  " + valor_inicial) ;

    System.out.println("\n Valor da venda:  " + valor_final);
  }
}
