/******************************************************************************
        AUTOR: BRENO PINHEIRO DE OLIVEIRA

        PROGRAMA PARA GERAÇÃO DE MENSAGENS AUTOMÁTICAS PARA UTILIZAR NO TELEGRAM


                    O programa não possui fim comercial, apenas para
                    uso pessoal. O mesmo gera um arquivo com um padrão
                    de mensagens que usarei para conseguir acompanhar
                    negociações que faço utilizando Criptomoedas.


*******************************************************************************/

import java.util.Scanner;
import java.io.File;  
import java.io.IOException;  
import java.io.FileWriter; 

class Main {
  public static void main(String[] args) {
          
          System.out.println("\n---------------------------------------------------\n \n \n ");

          System.out.println("PROGRAMA DE GERADOR DE RELATÓRIOS PARA WHATSAPP");

          System.out.println("\n \n \n--------------------------------------------------- \n \n\n");

          // criando as variáveis que serão utilizadas. Todas estão definidas como double para que possamos utilizar as casas decimais
          double lucro_trade_dolar = 0, lucro_total_real = 0, lucro_trade_real = 0, porcentagem_lucro =0, alavancagem =0, valor_inicial =0, valor_final = 0;
          
          
       
          
                    
          Scanner scanner = new Scanner(System.in);
          
          System.out.print("\nDigite o tipo de negociação [L para LONG e S para SHORT]: ");
          char tipo = scanner.next().charAt(0);
          
          scanner.nextLine();
          
          System.out.print("\nDigite a data da compra: ");
          String data_compra = scanner.nextLine();
          
          
          System.out.println("\nDigite a data da venda: ");
          String data_venda = scanner.nextLine();
          
         
          System.out.print("\nDigite o valor de compra da moeda (em dólar):  $");
          Double valor_moeda_compra = scanner.nextDouble();


          System.out.print("\nDigite o valor de venda da moeda (em dólar):  $");
          double valor_moeda_venda = scanner.nextDouble ();// solicitando ao usuário que ele informe a data que fez a venda das moedas
          
          
          System.out.print("\nDigite a quantidade de moedas negociadas:  ");
          int quantidade_negociada = scanner.nextInt ();
          
          valor_inicial = quantidade_negociada * valor_moeda_compra; 
          
          valor_final = quantidade_negociada * valor_moeda_venda;
          
          System.out.print("\nDigite o lucro total antes da última negociação (em dólar): $");
          double lucro_total_dolar = scanner.nextDouble ();
          
          System.out.print("\nDigite o valor da cotação do dólar no dia da venda: R$");
          double dolar = scanner.nextDouble ();
          
          if (tipo == 'S')
          {
                  lucro_trade_dolar = (valor_final - valor_inicial) * -1;
                  
          }
          else
          {
                  lucro_trade_dolar = valor_final - valor_inicial;
          }
          
          lucro_total_dolar = lucro_total_dolar + lucro_trade_dolar;
          
          lucro_trade_real = lucro_trade_dolar * dolar;
          
          lucro_total_real = lucro_total_dolar * dolar;
          
          porcentagem_lucro = (lucro_trade_dolar * 100) / quantidade_negociada;
          
          try {
                        FileWriter myWriter = new FileWriter("mensagens.txt");
                        myWriter.write("DATA DA COMPRA: " + data_compra);
                        myWriter.write("\n DATA DA VENDA: " + data_venda);
                        myWriter.write("\n VALOR INICIAL: $" + valor_inicial);
                        myWriter.write("\n VALOR FINAL: $" + valor_final);
                        myWriter.write("\n LUCRO NEGOCIAÇÃO EM DÓLAR: $" + lucro_trade_dolar);
                        myWriter.write("\n LUCRO NEGOCIAÇÃO EM REAL: R$" + lucro_trade_real);
                        myWriter.write("\n LUCRO TOTAL EM DÓLAR: $" + lucro_total_dolar);
                        myWriter.write("\n LUCRO TOTAL EM REAL: R$" + lucro_total_real);
                        myWriter.write("\n PROCENTAGEM LUCRO: " + porcentagem_lucro + "%");
      
                        myWriter.close();
                        System.out.println("Os dados foram gravados com  sucesso!");
               } catch (IOException e) {
                                                 System.out.println("An error occurred.");
                                                 e.printStackTrace();
                                       }


    
  }
}
