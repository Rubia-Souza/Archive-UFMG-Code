-- Questão 3.2.1

SELECT id_empenho, observacao, data_emissao
    FROM empenho
    WHERE data_emissao BETWEEN '2020-01-01' AND '2020-12-31'

-- Questão 3.2.2

SELECT uf, COUNT(uf) AS TotalFavorecidos
    FROM favorecido
    GROUP BY uf
    ORDER BY TotalFavorecidos ASC
    LIMIT 3

-- Questão 3.2.3

SELECT U.nome_unidade, O.nome_orgao
    FROM unidade AS U
    JOIN orgao AS O
        ON U.id_orgao = O.id_orgao
    WHERE U.nome_unidade LIKE 'SUPERINTENDENCIA%'

-- Questão 3.2.4

SELECT codigo_empenho
    FROM empenho
    WHERE observacao LIKE '%COBRIR%'

-- Questão 3.2.5

SELECT F.nome_fornecedor, COUNT(F.id_favorecido) AS QuantidadeEmpenhos
    FROM favorecido AS F
    JOIN empenho AS E
        ON F.id_favorecido = E.id_favorecido
    GROUP BY F.id_favorecido
    HAVING QuantidadeEmpenhos > 1
    ORDER BY QuantidadeEmpenhos ASC

-- Questão 3.2.6

SELECT U.nome_unidade, SUM(I.valor_total_item) AS ValorTotal
    FROM unidade AS U
    JOIN empenho AS E
        ON U.id_unidade = E.id_unidade
    JOIN item_empenho AS I
        ON E.id_empenho = I.id_empenho
    GROUP BY U.nome_unidade
    ORDER BY ValorTotal ASC

-- Questão 3.2.7

SELECT O.nome_orgao, COUNT(O.id_orgao) AS QuantidadeFavorecidos
    FROM orgao AS O
    JOIN unidade AS U
        ON U.id_orgao = O.id_orgao
    JOIN empenho AS E
        ON E.id_unidade = U.id_unidade
    GROUP BY O.nome_orgao
    HAVING QuantidadeFavorecidos > 10
    ORDER BY QuantidadeFavorecidos ASC

-- Questão 3.2.8

SELECT E.id_empenho
    FROM empenho AS E
    JOIN unidade AS U
        ON E.id_unidade = U.id_unidade
    JOIN orgao AS O
        ON O.id_orgao = U.id_orgao
    WHERE nome_orgao = 'Ministério da Saúde'

-- Questão 3.2.9

SELECT DISTINCT U.nome_unidade
    FROM unidade AS U
    JOIN empenho AS E
        ON E.id_unidade = U.id_unidade
    JOIN favorecido AS F
        ON F.id_favorecido = E.id_favorecido
    WHERE F.uf = 'MG'

-- Questão 3.2.10

SELECT DISTINCT I.descricao
    FROM empenho AS E
    JOIN unidade AS U
        ON E.id_unidade = U.id_unidade
    JOIN orgao AS O
        ON O.id_orgao = U.id_orgao
    JOIN item_empenho AS I
        ON I.id_empenho = E.id_empenho
    WHERE nome_orgao = 'Ministério da Saúde'
    ORDER BY I.descricao ASC