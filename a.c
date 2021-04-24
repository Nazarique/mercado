
// void cadastro_produtos(S_produto *produtos, int qtde)
// {
// 	char nome_novo_produto[D_D_QTDD_DE_ITENS_DO_NOME_DO_PRODUTO];
// 	int i;
// 	char opcao;
		
// 		printf("\n\tRegistro de mercadorias\n\n");
//     	printf("\nNome: ");
// 		scanf("%s", nome_novo_produto);
// 		fflush(stdin);

// 		for (i = 0; i < qtd; i++) //verificando se o código já está cadastrado
// 		{
// 			if(strcmp(nome_novo_produto, produtos[i].nome) == 0) 
// 			{
// 				printf("\nMercadoria já cadastrada\n");
// 				//system("cls");
// 				printf("\nDeseja altera a quantidade ou preço do produto?(s/n)\n");
// 				fflush(stdin);
// 				opcao = getchar();
// 				system("cls");

// 				if(opcao=='s' || opcao=='S')
// 					//altera_produtos(S_produto *produtos, int qtd, char *nome_novo_produto, int index);
// 					 printf("\nsim\n");
// 				else if(opcao=='n' || opcao=='N')
// 					printf("\nnao");
// 				else 
// 					printf("Selecao invalida\n");
// 				break;
// 			}
// 		}	
// 		printf("\nPressione enter para sair.");
// 		getchar();
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define D_QTDD_DE_ITENS 8
#define D_D_QTDD_DE_ITENS_DO_NOME_DO_PRODUTO 20

typedef struct 
{
  char nome[D_D_QTDD_DE_ITENS_DO_NOME_DO_PRODUTO];
  unsigned int qtd;
  float preco;

} S_produto;

typedef struct 
{	
	S_produto pilha [D_QTDD_DE_ITENS];
	int topo;
} S_pilha;

void Imprime_Vetor(S_produto *prod){

    for(int i = 0; i< D_QTDD_DE_ITENS; i++)
        printf("%-2d\t%-10s\t%-.2f\n", prod[i].qtd, prod[i].nome, prod[i].preco);
   printf("\n");
}

void pilha_push(S_produto *prod, int *topo, S_produto novo_prod)
{
  
    if (*topo == D_QTDD_DE_ITENS -1 )
       printf("pilha cheia! ");
    else
    {
        *topo = *topo + 1;
        prod[*topo] = novo_prod;
    }
}

S_produto pilha_pop(S_produto *prod, int *topo)
{
	S_produto aux;
    if (*topo ==  -1 )
       printf("pilha Vazia!\n");
    else
    {
        printf("Retirando valor!: %s\n", prod[*topo].nome);
        aux = prod[*topo];
        memset(&prod[*topo], 0, sizeof(S_produto));
        *topo = *topo - 1;
    }
    return aux;
}

void inicializa_pilha(S_pilha *pilha)
{
	memset(pilha, 0, sizeof(S_pilha));
	pilha->topo = -1;	
}

int main(int argc, char const *argv[])
{
   	S_pilha caixa; 
   	inicializa_pilha(&caixa);
 //   	memset(&caixa, 0, sizeof(S_pilha));
	// caixa.topo = -1;    	
   	// {
   	// 	{
	   //      {"blablabla", 5 , 5.15},
	   //      {"teste"  , 52, 6.85},
	   //      {"henrique naza", 99, 0.6}
	   //  },
	   //  2
    // };

    S_produto prod_novo = {"prod novo", 25 , 6.85};

    Imprime_Vetor(caixa.pilha);
    
    pilha_push(caixa.pilha, &caixa.topo, prod_novo);
    Imprime_Vetor(caixa.pilha);

    S_produto prod_novo2 = pilha_pop(caixa.pilha, &caixa.topo);
    pilha_push(caixa.pilha, &caixa.topo, prod_novo2);

    Imprime_Vetor(caixa.pilha);
    scanf(" ");

	return 0;
}