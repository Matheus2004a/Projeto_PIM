all:
	gcc main.c vendaingresso/vendaing.c usuarios/cadastro.c usuarios/login.c usuarios/usuarios.c questionarios/visitantes/questionario_obra.c obras/obras.c obras/dados_obra.c obras/listar_obras.c obras/gerar_id.c obras/cadastro/pre_cadastro.c menu/menu.c menuVisitante/visitantes.c -o main
