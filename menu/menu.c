int menu()
{
  int opcao;

  puts("\t\nBem Vindo o museu do futebol\t\n");
  printf("1 - Cadastrar Usuário\n");
  printf("2 - Fazer Login\n");
  printf("3 - Sair\n");

  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);

  return opcao;
}
