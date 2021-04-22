#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*  fwrite(void * buffer, size_ttamanho, size_t cont, FILE * arquivo), 
	em que buffer contem o que se deseja escrever, tamanho indica
	o tamanho em bytes de cada elemento do buffer e cont indica 
	quantos elementos são lidos/escritos.
*/


#define D_TAM_DO_NOME_DO_PRODUTO 20
#define D_ESTRELA_NOTA_FICAL "\n******************************\n"


typedef struct 
{
	char nome[D_TAM_DO_NOME_DO_PRODUTO];
	unsigned int qtd;
	float preco;

}	S_produto;

void cadastro_produtos(S_produto *produtos, int qtde)
{
	char nome_novo_produto[D_TAM_DO_NOME_DO_PRODUTO];
	int i;
	char opcao;
		
		printf("\n\tRegistro de mercadorias\n\n");
    	printf("\nNome: ");
		scanf("%s", nome_novo_produto);
		fflush(stdin);

		for (i = 0; i < qtde; i++) //verificando se o código já está cadastrado
		{
			if(strcmp(nome_novo_produto, produtos[i].nome) == 0) 
			{
				printf("\nMercadoria já cadastrada\n");
				//system("cls");
				printf("\nDeseja altera a quantidade ou preço do produto?(s/n)\n");
				fflush(stdin);
				opcao = getchar();
				system("cls");

				if(opcao=='s' || opcao=='S')
					//altera_produtos(S_produto *produtos, int qtde, char *nome_novo_produto, int index);
					 printf("\nsim\n");
				else if(opcao=='n' || opcao=='N')
					printf("\nnao");
				else 
					printf("Selecao invalida\n");
				break;
			}
		}	
		printf("\nPressione enter para sair.");
		getchar();
}

void nota_fiscal(S_produto *produtos, int qtd)
{
	float total = 0;
	printf("Itens comprados\nQte\tDescrição\tValor\tfinal");
	printf(D_ESTRELA_NOTA_FICAL);

	for (int i = 0; i < qtd; ++i)
	{
		printf("%-2d\t%-10s\t%-.2f\n", produtos[i].qtd, produtos[i].nome, produtos[i].preco);
		total+=produtos[i].preco;
	}
	
	printf(D_ESTRELA_NOTA_FICAL);
	printf("Total\t%-7c%-.2f\n", ' ',total);
}

int contar(char *string)
{
	for (int i = 0; string;)
		if (*(i + string)!= '\0')
			i++;
		else
			return i;
}
void func()
{
		 // if ((fp=fopen ("nomes.txt","wb")) != NULL) 
	 // {
	 // 	for (int i = 0; i < 2; ++i)
	 // 	{
		//  	fprintf(fp, "%d,"	 ,prod[i].qtd);
		//  	fwrite(prod[i].nome, sizeof(char), contar(prod[i].nome), fp);
		//  	fprintf(fp, ",%.2f\n",prod[i].preco);
		 	
		// }
		// fclose(fp);
	 // }
}
int main(int argc,char *argv[]) 
{
	 //FILE *fp;
	 S_produto prod[2] = {
	 						{"blablabla", 5	, 5.15},
	 						{"teste"	, 52, 6.85}
	 					 };

	 // printf("%d\n", contar(prod[0].nome));
	 cadastro_produtos(prod, 2);
	 // if ((fp=fopen ("nomes.txt","wb")) != NULL) 
	 // {
	 // 	for (int i = 0; i < 2; ++i)
	 // 	{
		//  	fprintf(fp, "%d,"	 ,prod[i].qtd);
		//  	fwrite(prod[i].nome, sizeof(char), contar(prod[i].nome), fp);
		//  	fprintf(fp, ",%.2f\n",prod[i].preco);
		 	
		// }
		// fclose(fp);
	 // }
	return 0;
}