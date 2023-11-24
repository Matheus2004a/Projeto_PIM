#include <stdio.h>
#include <stdlib.h>

#include "../obras/dados_obra.h"
#include "../questionarios/visitantes/questionario_obra.h"

void generateCSVReport()
{
  FILE *csvFile;

  csvFile = fopen("relatorio_visitas.csv", "w");

  if (csvFile == NULL)
  {
    printf("Erro ao salvar relatório de visitas\n");
    exit(1);
  }

  fprintf(csvFile, "ID, Título, Número de Visitas\n");

  for (int i = 0; i <= numObras; i++)
  {
    fprintf(csvFile, "%d,%s,%d\n",
            obras[i].id,
            obras[i].titulo,
            obras[i].qtdVisitas);
  }

  printf("Relatório de visitas das obras gerado com sucesso\n");

  fclose(csvFile);
  questionario_obra();
}
