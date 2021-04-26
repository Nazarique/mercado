#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define D_QTDD_DE_ITENS 10
#define D_TAM_DO_NOME_DO_PRODUTO 15
#define D_ESTRELA_NOTA_FICAL "\n\t*****************************************\n"


typedef struct 
{
  char nome[D_TAM_DO_NOME_DO_PRODUTO];
  unsigned int qtd;
  float preco;

} S_produto;

typedef struct 
{ 
  S_produto pilha [D_QTDD_DE_ITENS];
  int topo;
} S_pilha;


void pilha_imprime(S_produto *pilha, int qtd)
{
  if(qtd != 0)
  {
    float total = 0;
    
    for(int i = 0; i < qtd; ++i)
    {
      printf("\t%-2d\t%-15s\t%-.2f\n", pilha[i].qtd, pilha[i].nome, pilha[i].preco);
      total+= pilha[i].qtd * pilha[i].preco;
    }
    printf("\tTotal\t%-15c\t%-.2f\n", ' ',total);
 }
 else
  printf("\t\tNAO HA ITENS\n");
}

void relatorio(S_pilha caixa, S_pilha processados)
{
  printf("\n\tItens no caixa ainda nao processados:\n\n");
  pilha_imprime(caixa.pilha, caixa.topo+1);
  printf("\n\n\tItens processados:\n\n");
  pilha_imprime(processados.pilha, processados.topo+1);
  printf("\n\t-----------------------------------------\n");
}

void pilha_adiciona(S_produto *pilha, int *topo, S_produto novo_prod)
{
  
    if (*topo == D_QTDD_DE_ITENS -1 )
       printf("\n\tpilha cheia! ");
    else
    {
        *topo = *topo + 1;
        pilha[*topo] = novo_prod;
    }
}

S_produto pilha_retira(S_produto *pilha, int *topo)
{
  S_produto aux;
    if (*topo ==  -1 )
       printf("\n\tpilha Vazia!\n");
    else
    {
        aux = pilha[*topo];
        memset(&pilha[*topo], 0, sizeof(S_produto));
        *topo = *topo - 1;
    }
    return aux;
}

void pilha_inicializa(S_pilha *pilha)
{
  memset(pilha, 0, sizeof(S_pilha));
  pilha->topo = -1; 
}

int contar(char *string)
{
  for (int i = 0; string;)
    if (*(i + string)!= '\0')
      i++;
    else
      return i;
}

void nota_fiscal(S_produto *produtos, int qtd)
{
  float total = 0;
  printf("\n\n\n\n\t\tItens comprados\n\tQte\tDescricao\tValor final");
  printf(D_ESTRELA_NOTA_FICAL);

  for (int i = 0; i < qtd; ++i)
  {
    printf("\t%-2d\t%-15s\t%-.2f\n", produtos[i].qtd, produtos[i].nome, produtos[i].preco);
    total+= produtos[i].qtd * produtos[i].preco;
  }
  
  printf(D_ESTRELA_NOTA_FICAL);
  printf("\tTotal\t%-15c\t%-.2f\n", ' ',total);
  printf("\n\n\n\n\tObrigado pela compra, volte sempre!!!");
  getchar();
  exit(0);

}

void arq_escrever(S_produto *prod, int qtd)
{
  FILE *arq;
  if ((arq=fopen ("caixa.txt","w")) != NULL) 
  {
    for (int i = 0; i < qtd; ++i)
    {
      fprintf(arq, "%u,"  ,prod[i].qtd);
      fwrite(prod[i].nome, sizeof(char), contar(prod[i].nome), arq);
      fprintf(arq, ",%.2f\n",prod[i].preco);
    }
    printf("\n\tArquivos escritos com sucesso!!!\n");
    fclose(arq);
  }
  else
    printf("\n\tERRO!!!\n");
}

int arq_ler(S_produto *prod)
{
  int i;
  FILE *arq;

  if ((arq = fopen("caixa.txt","r")) != NULL) 
   {
    for(i=0; i < D_QTDD_DE_ITENS && (arq != NULL);)
    {
      fscanf(arq,"%u,%[^,]s",&prod[i].qtd, prod[i].nome);
      fscanf(arq,",%f", &prod[i].preco); 
     
     if('\n'==fgetc(arq))
        i++;
     else
      break;
    }
    fclose(arq);
    if(i > 0) 
      printf("\n\tArquivos lidos com sucesso!!!\n");
    else
      printf("\n\tArquivos NAO existentes!!!\n");  
    return i;
   }
   else
   {
    printf("\n\tERRO!!!\n");
    return 0;
   }
}

void adiconar_ao_caixa(S_pilha *caixa)
{
  printf("\n\tInsira os dados do produto:\n");
  S_produto prod_novo;
  memset(&prod_novo, 0, sizeof(S_produto));

  printf("\n\tNome do produto (0 ... 15/Caracteres): ");
  scanf("%s", prod_novo.nome);

  printf("\n\tQuantidade do produto (0 ... 50): ");
  scanf("%u", &prod_novo.qtd);

  printf("\n\tPreco do produto (0.0 ... 99.00): ");
  scanf("%f", &prod_novo.preco);

  pilha_adiciona(caixa->pilha, &caixa->topo, prod_novo);
}

int main(void)
{
  system("color e4");
  S_pilha caixa;
  S_pilha processado; 

  pilha_inicializa(&caixa);
  pilha_inicializa(&processado);

  int opcao = 0;

  do{
      
      system("cls");
      printf("\t\tMENU\n\n");
      printf("\t[ 1 ] - Comprar com arquivo\n\t[ 2 ] - Comprar manualmente\n\t[ 3 ] - Funcionario processando UMA mercadoria\n\t[ 4 ] - Funcionario processando TODAS mercadoria\n\t[ 5 ] - Listas Itens no CAIXA\n\t[ 6 ] - Arquivar caixa\n\t[ 7 ] - Finalizar a comprar e Imprimir Nota Fiscal\n\t[ 0 ] - Sair\n>");
          
      //fflush(stdout);
      scanf("%d", &opcao);
      fflush(stdin);
      system("cls");    
        switch(opcao)
        {
            case 1:
              caixa.topo = arq_ler(caixa.pilha)-1;
              if(caixa.topo == -1)
              {
                printf("\n\tCAIXA vazio!!!\n");
                pilha_inicializa(&caixa);
              }
              else
              
                printf("\n\tItens adicionados ao caixa via arquivo!\n");
              break;
            case 2:
              if(caixa.topo >= 9)
                printf("\n\tVoce atingiu o limite de 10 itens\n\tPor favor finalize a compra, retire itens ou arquive o seu CAIXA!!!\n");
              else 
                if(caixa.topo < 9)
                  adiconar_ao_caixa(&caixa);
              break;

            case 3:
              if(caixa.topo == -1)
                printf("\n\tCAIXA vazio!!!\n");
              else
              {
                pilha_adiciona(processado.pilha, &processado.topo, pilha_retira(caixa.pilha, &caixa.topo));
                relatorio(caixa, processado);
              }
              break;
            case 4:
              if(caixa.topo == -1)
                printf("\n\tCAIXA vazio!!!\n");
              else
              {
                while(caixa.topo != -1)
                  pilha_adiciona(processado.pilha, &processado.topo, pilha_retira(caixa.pilha, &caixa.topo));
                relatorio(caixa, processado);
              }
              break;

              case 5:
              if(processado.topo == -1 && caixa.topo == -1)
              {
                  printf("\n\tCAIXA vazio!!!\n");
              }
              else if(caixa.topo == -1)
              {
                  printf("\n\tItens do caixa ja foram processados:\n\n");
              
              }
              else
                pilha_imprime(caixa.pilha, caixa.topo+1);
              break;

              case 6:
                if(caixa.topo == -1)
                  printf("\n\tCAIXA vazio!!!\n");
                else
                {
                  arq_escrever(caixa.pilha, caixa.topo+1);
                  printf("\n\tCAIXA liberado\n");
                  pilha_inicializa(&caixa);
                  pilha_inicializa(&processado);
                } 
                break;             
              case 7:
                if(processado.topo == -1)
                  printf("\n\tNENHUM ITEM FOI PROCESSADO!!!\n");
                else
                {
                  nota_fiscal(processado.pilha, processado.topo+1);
                  pilha_inicializa(&caixa);
                  pilha_inicializa(&processado);
                }
              break;
            case 0:
              exit(0);
              break;

            default:
              printf("\n\tSelecao invalida\n\tPor favor Selecione uma opcao valida");
              break;
        }
      printf("\n\tPressione enter para sair.\n");
      getchar();
    }
    while(opcao != 0);

 return 0;
}