int opcao;
do{
    getchar();
    system("cls")
    printf("\t\tMENU\n\n");
    printf("\t[ 1 ] - Comprar com arquivo\n\t[ 2 ] - Comprar manualmente\n\t[ 3 ] - Funcionario processando mercadoria\n\t[ 4 ] - Listas Itens no CAIXA\n\t[ 5 ] - Arquivar caixa\n\t[ 0 ] - Sair\n>");
        
    scanf("%d", &opcao);
        
      switch(opcao)
      {
          case 1:
            printf("\n\tItens adicionados ao caixa via arquivo!\n");
            caixa.topo = ler_arq(caixa.pilha)-1;
            break;

          case 2:
            if(caixa.topo => 9)
              printf("\n\tVoce atingiu o limite de 10 itens\n\tPor favor finalize a compra, retire itens ou arquive o seu CAIXA!!!\n");
            else if(caixa.topo == -1)
              printf("\n\tCAIXA vazio!!!\n");
            else
              if(caixa.topo < 9)
                pilha_adiciona(&caixa);
            break;

          case 3:
            pilha_adiciona(processado.pilha, &processado.topo, pilha_retira(caixa.pilha, &caixa.topo));
            relatorio(caixa, processado);
            break;

            case 4:
            printf("\n\tItens no caixa ainda nao processados:\n\n");
            pilha_imprime(caixa.pilha, caixa.topo+1);
            break;

            case 5:
              if(caixa.topo == -1)
                printf("\n\tCAIXA vazio!!!\n");


                escrever_arq(caixa.pilha, caixa.topo+1);
                printf("\n\tCAIXA liberado\n");
                pilha_inicializa(&caixa);
                pilha_inicializa(&processado);

            break;
          case 0:
            exit(0);
            break;

          default:
            printf("\n\tSelecao invalida\n\tPor favor Selecione uma opcao valida");
            break;
      }
      
    }while(opcao != 0);