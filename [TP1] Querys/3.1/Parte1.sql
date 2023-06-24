-- Questão 3.1.1
SELECT nome_fornecedor
    FROM favorecido
    WHERE uf = 'SP'

-- Questão 3.1.2
SELECT codigo_empenho, valor_empenho
    FROM empenho
    WHERE valor_empenho > 1000000

-- Questão 3.1.3
SELECT F.nome_fornecedor, E.valor_empenho
    FROM empenho AS E
    JOIN favorecido AS F
        ON E.id_favorecido = F.id_favorecido
    WHERE valor_empenho < 1000

-- Questão 3.1.4
SELECT U.nome_unidade, E.valor_empenho
    FROM empenho AS E
    JOIN unidade AS U
        ON E.id_unidade = U.id_unidade
    WHERE U.codigo_unidade = 152005

-- Questão 3.1.5
SELECT U.id_unidade, U.nome_unidade
    FROM unidade AS U
    JOIN orgao AS O
        ON U.id_orgao = O.id_orgao
    WHERE O.nome_orgao = 'Ministério da Economia'