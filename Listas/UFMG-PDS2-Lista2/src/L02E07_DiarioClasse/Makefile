# Define configurações do projeto
PROJECT_NAME = VPL7_DiarioClasse

# Define pastas do projeto
SRC_FOLDER = .
BUILD_FOLDER = ./build
TEST_FOLDER = ${SRC_FOLDER}/tests

# Define include doctest
DOCTEST_HEADER = ${SRC_FOLDER}/libs

# Define o compilador
COMPILER = g++
COMMUN_BUILD_FLAGS = -std=c++11 -Wall --coverage
DOCTEST_INCLUDE = -I ${DOCTEST_HEADER}

# Define os arquivos de build
BUILD_CLASSES = ${BUILD_FOLDER}/DiarioClasse.o
BUILD_TESTS = ${BUILD_FOLDER}/TesteDiarioClasse.o
BUILD_FILES = ${BUILD_FOLDER}/main.o ${BUILD_CLASSES} ${BUILD_TESTS}

# Builda projeto
all: ${PROJECT_NAME}

${PROJECT_NAME}: ${BUILD_FILES}
	${COMPILER} ${DOCTEST_INCLUDE} ${BUILD_FOLDER}/*.o -o ${PROJECT_NAME} ${COMMUN_BUILD_FLAGS}

${BUILD_FOLDER}/main.o: ${SRC_FOLDER}/main.cpp
	${COMPILER} ${DOCTEST_INCLUDE} -c ${SRC_FOLDER}/main.cpp -o ${BUILD_FOLDER}/main.o ${COMMUN_BUILD_FLAGS}

# Builda classes
DIARIO_CLASSE_FOLDER = ${SRC_FOLDER}/classes/DiarioClasse
${BUILD_FOLDER}/DiarioClasse.o: ${DIARIO_CLASSE_FOLDER}/DiarioClasse.hpp ${DIARIO_CLASSE_FOLDER}/DiarioClasse.cpp
	${COMPILER} -c ${DIARIO_CLASSE_FOLDER}/DiarioClasse.cpp -o ${BUILD_FOLDER}/DiarioClasse.o ${COMMUN_FLAGS}

# Builda testes
TEST_DIARIO_CLASSE_FOLDER = ${TEST_FOLDER}/DiarioClasse
${BUILD_FOLDER}/TesteDiarioClasse.o: ${TEST_DIARIO_CLASSE_FOLDER}/TesteDiarioClasse.cpp
	${COMPILER} ${DOCTEST_INCLUDE} -c ${TEST_DIARIO_CLASSE_FOLDER}/TesteDiarioClasse.cpp -o ${BUILD_FOLDER}/TesteDiarioClasse.o ${COMMUN_FLAGS}

clean:
	del /S .\build\*
	del ${PROJECT_NAME}.exe
