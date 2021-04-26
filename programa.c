#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*  fwrite(void * buffer, size_ttamanho, size_t cont, FILE * arquivo), 
  em que buffer contem o que se deseja escrever, tamanho indica
  o tamanho em bytes de cada elemento do buffer e cont indica 
  quantos elementos são lidos/escritos.
*/

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
  printf("\n\n\n\n\t\tItens comprados\n\tQte\tDescricao\tValor\tfinal");
  printf(D_ESTRELA_NOTA_FICAL);

  for (int i = 0; i < qtd; ++i)
  {
    printf("\t%-2d\t%-15s\t%-.2f\n", produtos[i].qtd, produtos[i].nome, produtos[i].preco);
    total+= produtos[i].qtd * produtos[i].preco;
  }
  
  printf(D_ESTRELA_NOTA_FICAL);
  printf("\tTotal\t%-15c\t%-.2f\n", ' ',total);
  printf("\n\n\n\n\tObrigado pela compra, volte sempre!!!");

}

void arq_escrever(S_produto *prod, int qtd)
{
  FILE *arq;
  if ((arq=fopen ("nomes.txt","w")) != NULL) 
   {
    for (int i = 0; i < qtd; ++i)
    {
      fprintf(arq, "%u,"  ,prod[i].qtd);
      fwrite(prod[i].nome, sizeof(char), contar(prod[i].nome), arq);
      fprintf(arq, ",%.2f\n",prod[i].preco);
    }
    fclose(arq);
   }
}

int arq_ler(S_produto *prod)
{
  int i;
  FILE *arq;

  if ((arq = fopen("nomes.txt","r")) != NULL) 
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
   }
   return i;
}

void adiconar_ao_caixa(S_pilha *caixa)
{
  char opcao = '\0';
  system("cls");

  while(1)
  {
    printf("\n\tDeseja adiconar um novo produto?(s/n)");
    scanf(" %c", &opcao);

    if(opcao=='s' || opcao=='S')
    {

      printf("\n\tsim\n");
      S_produto prod_novo;
      memset(&prod_novo, 0, sizeof(S_produto));

      printf("\n\tNome: ");
      scanf("%s", prod_novo.nome);

      printf("\n\tQuantidade: ");
      scanf("%u", &prod_novo.qtd);

      printf("\n\tPreco: ");
      scanf("%f", &prod_novo.preco);

      pilha_adiciona(caixa->pilha, &caixa->topo, prod_novo);
    }
    else if(opcao=='n' || opcao=='N')
    {
      printf("\n\tnao");
      break;
    }
    else 
    {
      printf("\n\tSelecao invalida\n\tPor favor Selecione uma opcao valida");
    }
  }
  printf("\nPressione enter para sair.");
  getchar();
  system("cls");
}

int main(void)
{

  S_pilha caixa;
  S_pilha processado; 

  pilha_inicializa(&caixa);
  pilha_inicializa(&processado);

  relatorio(caixa, processado);
  adiconar_ao_caixa(&caixa);
  //pilha_adiciona(caixa.pilha, &caixa.topo, prod_novo);
  
  relatorio(caixa, processado);
  
  // pilha_adiciona(processado.pilha, &processado.topo, pilha_retira(caixa.pilha, &caixa.topo));
  
  // relatorio(caixa, processado);

  // nota_fiscal(processado.pilha, processado.topo+1);
  getchar();

 return 0;
}