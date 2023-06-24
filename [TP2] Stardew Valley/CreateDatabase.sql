CREATE TABLE Fazendeiro
(
  cnpj Varchar(40) NOT NULL PRIMARY KEY,
  nome Varchar(40) NOT NULL,
  email Varchar(40) NOT NULL,
  senha Varchar(128) NOT NULL
);

CREATE TYPE TIPO_PATRIMONIO AS ENUM ('MAQUINA', 'ANIMAL', 'IMOVEL', 'MERCADORIA', 'UTENSILIO', 'VEICULO', 'TERRENO', 'OUTROS');
CREATE TYPE STATUS_PATRIMONIO AS ENUM ('EM_POSSE', 'VENDIDO', 'ALUGADO', 'DESCARTADO', 'EM_MANUTENCAO');

CREATE TABLE Patrimonio
(
  id SERIAL NOT NULL PRIMARY KEY,
  nome Varchar(40) NOT NULL,
  tipo TIPO_PATRIMONIO NOT NULL,
  valor Float NOT NULL,
  status STATUS_PATRIMONIO NOT NULL,
  cnpjFazendeiro Varchar(40) NOT NULL,
  FOREIGN KEY(cnpjFazendeiro) REFERENCES Fazendeiro(cnpj)
);


CREATE TABLE Tarefa
(
  id SERIAL NOT NULL PRIMARY KEY,
  nome Varchar(40) NOT NULL,
  descricao Varchar(200),
  data Date NOT NULL,
  cnpjFazendeiro Varchar(40) NOT NULL,
  FOREIGN KEY(cnpjFazendeiro) REFERENCES Fazendeiro(cnpj)
);


CREATE TABLE Insumo
(
  id SERIAL NOT NULL PRIMARY KEY,
  nome Varchar(40) NOT NULL,
  finalidade Varchar(120) NOT NULL,
  custo Float NOT NULL,
  quantidadeEstoque Int NOT NULL
);


CREATE TABLE Utiliza
(
  idTarefa Int NOT NULL,
  idInsumo Int NOT NULL,
  quantidadeInsumoGasto Int NOT NULL,
  FOREIGN KEY(idTarefa) REFERENCES Tarefa(id) ON DELETE CASCADE,
  FOREIGN KEY(idInsumo) REFERENCES Insumo(id) ON DELETE CASCADE,
  CONSTRAINT idUtiliza PRIMARY KEY (idTarefa, idInsumo)
);


CREATE TABLE Produto
(
  id SERIAL NOT NULL PRIMARY KEY,
  nome Varchar(40) NOT NULL,
  descricao Varchar(120),
  valor Float NOT NULL,
  quantidadeEstoque Int NOT NULL,
  cnpjFazendeiro Varchar(40) NOT NULL,
  FOREIGN KEY(cnpjFazendeiro) REFERENCES Fazendeiro(cnpj)
);


CREATE TABLE Comprador
(
  cnpj Varchar(40) NOT NULL PRIMARY KEY,
  nome Varchar(40) NOT NULL
);


CREATE TABLE Telefone
(
  id SERIAL NOT NULL PRIMARY KEY,
  numero Varchar(20) NOT NULL,
  cnpjComprador Varchar(40) NOT NULL,
  FOREIGN KEY(cnpjComprador) REFERENCES Comprador(cnpj) ON DELETE CASCADE
);


CREATE TYPE FORMA_PAGAMENTO AS ENUM ('CARTAO_CREDITO', 'CARTAO_DEBITO', 'BOLETO', 'PIX', 'DINHEIRO');

CREATE TABLE Venda
(
  idProduto Int NOT NULL,
  cnpjComprador Varchar(40) NOT NULL,
  valor Float NOT NULL,
  data Date NOT NULL,
  formaPagamento FORMA_PAGAMENTO NOT NULL,
  quantidade Int NOT NULL,
  FOREIGN KEY(idProduto) REFERENCES Produto(id) ON DELETE CASCADE,
  FOREIGN KEY(cnpjComprador) REFERENCES Comprador(cnpj) ON DELETE CASCADE,
  CONSTRAINT idVenda PRIMARY KEY (idProduto, cnpjComprador)
);