
void adiconar_ao_caixa(S_pilha *caixa)
{
  char opcao = '\0';
  system("cls");
	printf("\n\tDeseja adiconar um novo produto?(s/n)");
	scanf(" %c", %opcao);

  while(1)
  {
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
      printf("\n\n\tDeseja adicionar um novo produto?(s/n)");
    }
  	else if(opcao=='n' || opcao=='N')
    {
  		printf("\n\tnao");
      break;
    }
  	else 
    {
  		printf("\n\tSelecao invalida\n\tPor favor Selecione uma opcao valida");
      printf("\n\tDeseja adicionar um novo produto?(s/n)");
    }
	}
  printf("\nPressione enter para sair.");
  getchar();
  system("cls");
}
