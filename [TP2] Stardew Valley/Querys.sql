----------- 2 com apenas seleção e projeção
----- Listar o Nome e Senha de todos Fazendeiros cadastrados
-- Forma 1
SELECT F.nome, F.senha 
    FROM fazendeiro AS F;

-- Forma 2: Trocando ordem de seleção das colunas
SELECT senha, nome
    FROM fazendeiro;

----- Listar o Nome e a Data de todas Tarefas do ano 2023
-- Forma 1
SELECT T.nome, T.data  
    FROM tarefa AS T
    WHERE T.data BETWEEN '2023-01-01' AND '2023-12-31';

-- Forma 2: Utilizando manipulação de datas
SELECT T.nome, T.data
    FROM tarefa AS T
    WHERE EXTRACT(YEAR FROM T.data) = 2023;

----------- 3 com join de 2 relações
----- Listar todas Tarefas da Fazendeira Amora Bettany
-- Forma 1
SELECT T.nome, T.data
    FROM tarefa AS T
    INNER JOIN fazendeiro AS F
        ON T.cnpjFazendeiro = F.cnpj 
    WHERE F.nome = 'Amora Bettany';

-- Forma 2: Utilizando LIKE
SELECT T.nome, T.data
    FROM tarefa AS T
    INNER JOIN fazendeiro AS F
        ON T.cnpjFazendeiro = F.cnpj 
    WHERE F.nome LIKE('Amora Bettany');

----- Listar os Telefones de todos Compradores
-- Forma 1
SELECT T.numero 
    FROM comprador AS C
    INNER JOIN telefone AS T 
        ON C.cnpj = T.cnpjComprador;

-- Forma 2: Sem utilizar INNER JOIN e ON
SELECT T.numero 
    FROM comprador AS C, telefone AS T
    WHERE C.cnpj = T.cnpjComprador;

----- Listar o Nome de todos Produtos que já foram vendidos alguma vez
-- Forma 1
SELECT DISTINCT P.nome 
    FROM produto AS P
    INNER JOIN venda AS V
        ON P.id = V.idProduto;

-- Forma 2: Utilizando FULL JOIN e removendo no WHERE
SELECT DISTINCT P.nome 
    FROM produto AS P
    FULL JOIN venda AS V
        ON P.id = V.idProduto
    WHERE V.idProduto IS NOT NULL;

----------- 3 com join de 3 ou mais relações
----- Criar um relatório de vendas com nome do Comprador, nome do Produto, Tipo da Pagamento e Valor, que tiveram um Valor superior a 200
-- Forma 1
SELECT C.nome, P.nome, V.formaPagamento, V.valor
    FROM venda AS V
    INNER JOIN comprador AS C
        ON V.cnpjComprador = C.cnpj
    INNER JOIN produto AS P
        ON V.idProduto = P.id
    WHERE V.valor > 200;

-- Forma 2: Utilizando negação no WHERE
SELECT C.nome, P.nome, V.formaPagamento, V.valor
    FROM venda AS V
    INNER JOIN comprador AS C
        ON V.cnpjComprador = C.cnpj
    INNER JOIN produto AS P
        ON V.idProduto = P.id
    WHERE NOT V.valor <= 200;

----- Listar quantos e quais Insumos cada Tarefa irá utilizar em ordem alfabetica pelo Nome das Tarefas
-- Forma 1
SELECT T.nome, I.nome, U.quantidadeInsumoGasto
    FROM utiliza AS U
    INNER JOIN insumo AS I
        ON I.id = U.idInsumo
    INNER JOIN tarefa AS T
        ON T.id = U.idTarefa
    ORDER BY T.nome;

-- Forma 2: Utilizando apenas JOIN
SELECT T.nome, I.nome, U.quantidadeInsumoGasto
    FROM utiliza AS U
    JOIN insumo AS I
        ON I.id = U.idInsumo
    JOIN tarefa AS T
        ON T.id = U.idTarefa
    ORDER BY T.nome;

----- Listar o nome de todos Patrimonios, Produtos e Tarefas da Fazendeira Amora Bettany
-- Forma 1
SELECT PA.nome AS Patromonio, T.nome AS Tarefa, P.nome AS Produto
    FROM fazendeiro AS F
    INNER JOIN patrimonio AS PA
        ON F.cnpj = PA.cnpjFazendeiro
    INNER JOIN produto AS P
        ON F.cnpj = P.cnpjFazendeiro
    INNER JOIN tarefa AS T
        ON F.cnpj = T.cnpjFazendeiro
    WHERE F.nome = 'Amora Bettany';

-- Forma 2: Subquery para encontrar Id Amora Bettany
SELECT PA.nome AS Patromonio, T.nome AS Tarefa, P.nome AS Produto
    FROM fazendeiro AS F
    INNER JOIN patrimonio AS PA
        ON F.cnpj = PA.cnpjFazendeiro
    INNER JOIN produto AS P
        ON F.cnpj = P.cnpjFazendeiro
    INNER JOIN tarefa AS T
        ON F.cnpj = T.cnpjFazendeiro
    WHERE F.cnpj IN (SELECT cnpj FROM fazendeiro WHERE nome = 'Amora Bettany');

----------- 2 com função de agregação (sum, avg e tal) em um join de 2 ou mais relações
------- Calcular a soma total dos Patrimonios por Fazendeiro
-- Forma 1
SELECT F.nome, SUM(P.valor) AS SomaPatrimonio
    FROM fazendeiro AS F
    INNER JOIN patrimonio AS P
        ON F.cnpj = P.cnpjFazendeiro
    WHERE P.status != 'VENDIDO' AND P.status != 'DESCARTADO'
	GROUP BY F.nome;

-- Forma 2: Aplicando todos outros possiveis estatos com OR
SELECT F.nome, SUM(P.valor) AS SomaPatrimonio
    FROM fazendeiro AS F
    INNER JOIN patrimonio AS P
        ON F.cnpj = P.cnpjFazendeiro
    WHERE P.status = 'EM_POSSE' OR P.status = 'ALUGADO' OR P.status = 'EM_MANUTENCAO'
	GROUP BY F.nome;

----- Calcular o valor médio gasto por Comprador
-- Forma 1
SELECT C.nome, AVG(V.valor) AS MediaGastaComprador
    FROM comprador AS C
    INNER JOIN venda AS V
        ON C.cnpj = V.cnpjComprador
	GROUP BY C.nome;

-- Forma 2: Agrupando pelo CNPJ mesmo não sendo selecionado como coluna
SELECT C.nome, AVG(V.valor) AS MediaGastaComprador
    FROM comprador AS C
    INNER JOIN venda AS V
        ON C.cnpj = V.cnpjComprador
	GROUP BY C.cnpj;