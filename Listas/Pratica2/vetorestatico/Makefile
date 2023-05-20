#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa vetop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-01 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make mem - gera arquivos de registro de acesso
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/vetop.o $(OBJ)/vet.o $(OBJ)/memlog.o
HDRS = $(INC)/vet.h $(INC)/memlog.h $(INC)/msgassert.h
CFLAGS = -pg -Wall -c -I$(INC)
ANALISAMEM = ../analisamem/bin/analisamem

EXE = $(BIN)/vetop

all:  mem perf gprof

mem: $(EXE)
	$(EXE) -d 20 -s -p /tmp/somalog.out -l 
	rm -rf /tmp/somaest
	mkdir /tmp/somaest
	$(ANALISAMEM) -i /tmp/somalog.out -p /tmp/somaest/somaest
	$(EXE) -d 20 -i -p /tmp/internolog.out -l 
	rm -rf /tmp/internoest
	mkdir /tmp/internoest
	$(ANALISAMEM) -i /tmp/internolog.out -p /tmp/internoest/internoest
	$(EXE) -d 20 -n -p /tmp/normalog.out -l 
	rm -rf /tmp/normaest
	mkdir /tmp/normaest
	$(ANALISAMEM) -i /tmp/normalog.out -p /tmp/normaest/normaest

perf: $(EXE)
	$(EXE) -d 100 -s -p /tmp/soma1M.out
	$(EXE) -d 100 -i -p /tmp/interno1M.out
	$(EXE) -d 100 -n -p /tmp/norma1M.out
	$(EXE) -d 200 -s -p /tmp/soma2M.out
	$(EXE) -d 200 -i -p /tmp/interno2M.out
	$(EXE) -d 200 -n -p /tmp/norma2M.out
	$(EXE) -d 300 -s -p /tmp/soma3M.out
	$(EXE) -d 300 -i -p /tmp/interno3M.out
	$(EXE) -d 300 -n -p /tmp/norma3M.out
	$(EXE) -d 400 -s -p /tmp/soma4M.out
	$(EXE) -d 400 -i -p /tmp/interno4M.out
	$(EXE) -d 400 -n -p /tmp/norma4M.out
	$(EXE) -d 500 -s -p /tmp/soma5M.out
	$(EXE) -d 500 -i -p /tmp/interno5M.out
	$(EXE) -d 500 -n -p /tmp/norma5M.out

gprof: $(BIN)/vetop
# Teste 100
	$(EXE) -d 100 -s -p /tmp/soma1Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/soma1Mgprof.txt
	$(EXE) -d 100 -i -p /tmp/interno1Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/interno1Mgprof.txt
	$(EXE) -d 100 -n -p /tmp/norma1Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/norma1Mgprof.txt

# Teste 200
	$(EXE) -d 200 -s -p /tmp/soma2Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/soma2Mgprof.txt
	$(EXE) -d 200 -i -p /tmp/interno2Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/interno2Mgprof.txt
	$(EXE) -d 200 -n -p /tmp/norma2Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/norma2Mgprof.txt

# Teste 300
	$(EXE) -d 300 -s -p /tmp/soma3Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/soma3Mgprof.txt
	$(EXE) -d 300 -i -p /tmp/interno3Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/interno3Mgprof.txt
	$(EXE) -d 300 -n -p /tmp/norma3Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/norma3Mgprof.txt

# Teste 400
	$(EXE) -d 400 -s -p /tmp/soma4Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/soma4Mgprof.txt
	$(EXE) -d 400 -i -p /tmp/interno4Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/interno4Mgprof.txt
	$(EXE) -d 400 -n -p /tmp/norma4Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/norma4Mgprof.txt

# Teste 500
	$(EXE) -d 500 -s -p /tmp/soma5Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/soma5Mgprof.txt
	$(EXE) -d 500 -i -p /tmp/interno5Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/interno5Mgprof.txt
	$(EXE) -d 500 -n -p /tmp/norma5Mgprof.out 
	gprof $(EXE) gmon.out > /tmp/norma5Mgprof.txt
	

$(BIN)/vetop: $(OBJS)
	$(CC) -pg -o $(BIN)/vetop $(OBJS) $(LIBS)

$(OBJ)/vetop.o: $(HDRS) $(SRC)/vetop.c
	$(CC) $(CFLAGS) -o $(OBJ)/vetop.o $(SRC)/vetop.c 

$(OBJ)/vet.o: $(HDRS) $(SRC)/vet.c
	$(CC) $(CFLAGS) -o $(OBJ)/vet.o $(SRC)/vet.c 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out

windows_clean:
	del /S .\bin\*
	del /S .\obj\*
