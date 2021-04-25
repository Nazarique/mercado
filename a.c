
void adiconar_ao_caixa()
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
       if(!igual)
        produto[*qtde].codigomercadoria = *qtde;
        fflush(stdin);  
              
        printf("\nQuantidade: ");
        scanf("%d", &produto[*qtde].qtdmercadoria);
    
        printf("\nPreço: ");
        scanf("%f", &produto[*qtde].precomercadoria);
        

       break;
    }
  	else if(opcao=='n' || opcao=='N')
    {
  		printf("\n\tnao");
      break;
    }
  	else 
    {
  		printf("\n\tSelecao invalida\n\tPor favor Selecione uma opcao valida");
      printf("\n\tDeseja adiconar um novo produto?(s/n)");
    }
	}
  printf("\nPressione enter para sair.");
  getchar();
  system("cls");
}
