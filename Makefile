all:
	gcc main.c vendaingresso/vendaing.c usuarios/cadastro.c usuarios/login.c usuarios/usuarios.c questionarios/visitantes/questionario_obra.c obras/obras.c obras/dados_obra.c obras/listagem/listar_obras.c obras/gerar_id.c obras/cadastro/pre_cadastro.c obras/cadastro/cadastrar_obra.c obras/edicao/editar_obra.c obras/remocao/remover_obra.c obras/buscar_obra.c menu/menu.c menuVisitante/visitantes.c relatorios/relatorio_csv.c -o main
