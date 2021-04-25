#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*  fwrite(void * buffer, size_ttamanho, size_t cont, FILE * arquivo), 
  em que buffer contem o que se deseja escrever, tamanho indica
  o tamanho em bytes de cada elemento do buffer e cont indica 
  quantos elementos são lidos/escritos.
*/

#define D_QTDD_DE_ITENS 10
#define D_TAM_DO_NOME_DO_PRODUTO 20
#define D_ESTRELA_NOTA_FICAL "\n******************************\n"

typedef struct 
{
  char nome[D_TAM_DO_NOME_DO_PRODUTO];
  unsigned int qtd;
  float preco;
} S_produto;

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
  printf("Itens comprados\nQte\tDescricao\tValor\tfinal");
  printf(D_ESTRELA_NOTA_FICAL);

  for (int i = 0; i < qtd; ++i)
  {
    printf("%-2d\t%-10s\t%-.2f\n", produtos[i].qtd, produtos[i].nome, produtos[i].preco);
    total+=produtos[i].preco;
  }
  
  printf(D_ESTRELA_NOTA_FICAL);
  printf("Total\t%-7c%-.2f\n", ' ',total);
}

void escrever_arq(S_produto *prod, int qtd)
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
    fclose(arq);
   }
}

int ler_arq(S_produto *prod)
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
   }
   return i;
}

int main()
{
  S_produto prod[3] = 
  {
      {"blablabla", 5 , 5.15},
      {"teste"  , 52, 6.85},
      {"henrique naza", 99, 0.6}
  };
  escrever_arq(prod, 3);  

  S_produto prodiii[10]; 
  memset(prodiii, 0, 10*sizeof(S_produto));

  int num = ler_arq(prodiii);

  printf("%d\n", num);
  nota_fiscal(prodiii, num);
  scanf(" ");

 return 0;
}