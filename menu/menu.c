int menu()
{
  int opcao;

  printf("1 - Cadastrar Usuário\n");
  printf("2 - Fazer Login\n");
  printf("3 - Sair\n");

  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);

  return opcao;
}
