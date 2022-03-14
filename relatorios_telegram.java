/******************************************************************************
        AUTOR: BRENO PINHEIRO DE OLIVEIRA

        PROGRAMA PARA GERAÇÃO DE MENSAGENS AUTOMÁTICAS PARA UTILIZAR NO TELEGRAM


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
          double lucro_trade_dolar = 0, lucro_total_real = 0, lucro_trade_real = 0, porcentagem_lucro =0, alavancagem =0, valor_incial =0, valor_final = 0;
          
          char tipo;
                    
          Scanner scanner = new Scanner(System.in);
         
          System.out.print("\n Digite o valor de compra da moeda (em dólar):  $");
          double valor_moeda_compra = scanner.nextDouble();


          System.out.print("\n Digite o valor de venda da moeda (em dólar):  $");
          double valor_final = scanner.nextDouble ();// solicitando ao usuário que ele informe a data que fez a venda das moedas
          
          
          System.out.print("\n Digite a quantidade de moedas negociadas:  ");
          int quantidade_negociada = scanner.nextInt ();
          
          valor_incial = quantidade_negociada * valor_moeda_compra; 
          
          valor_final = quantidade_negociada * valor_moeda_venda;
          
          System.out.print("\n Digite o lucro total antes da última negociação (em dólar): $");
          double lucro_total_dolar = scanner.nextDouble ();
          
          System.out.println("Digite o valor da cotação do dólar no dia da venda: R$");
          double dolar = scanner.nextDouble ();
          
          if (tipo == 'S')
          {
                  lucro_trade_dolar = (valor_final - valor_incial) * -1;
                  
          }
          else
          {
                  lucro_trade_dolar = valor_final - valor_inicial;
          }
          
          lucro_total_dolar = lucro_total_dolar + lucro_trade;
          
    
  }
}
