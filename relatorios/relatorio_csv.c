#include <stdio.h>
#include <stdlib.h>

#include "../obras/dados_obra.h"

void generateCSVReport()
{
  FILE *csvFile;

  csvFile = fopen("relatorio_visitas.csv", "a");

  if (csvFile == NULL)
  {
    printf("Erro ao salvar relatório de visitas\n");
    exit(1);
  }

  fprintf(csvFile, "ID, Título, Descrição, Autor, Ano, Número de Visitas\n");

  for (int i = 0; i < MAX_OBRAS; i++)
  {
    fprintf(csvFile, "%d,%s,%s,%s,%d,%d\n",
            obras[i].id,
            obras[i].titulo,
            obras[i].descricao,
            obras[i].autor,
            obras[i].ano,
            obras[i].qtdVisitas);
  }

  printf("Relatório de visitas das obras gerado com sucesso\n");

  fclose(csvFile);
}
