COMPILER = gcc
BUILD_FLAGS = -lstdc++ -std=c++11 -Wall

PROJECT_NAME = vpl_execution

SRC_FOLDER = ./src
BUILD_FOLDER = ./build
INCLUDE_FOLDER = ./include

all: ${PROJECT_NAME}

# Builda Main
${PROJECT_NAME}: ${BUILD_FOLDER}/main.o ${BUILD_FOLDER}/Heroi.o ${BUILD_FOLDER}/Personagem.o ${BUILD_FOLDER}/Vilao.o
	${COMPILER} ${BUILD_FOLDER}/*.o -o ${PROJECT_NAME} ${BUILD_FLAGS}

${BUILD_FOLDER}/main.o: ${SRC_FOLDER}/main.cpp
	${COMPILER} -I ${INCLUDE_FOLDER} -c ${SRC_FOLDER}/main.cpp -o ${BUILD_FOLDER}/main.o

# Builda Entidades
${BUILD_FOLDER}/Heroi.o: ${INCLUDE_FOLDER}/Heroi.hpp ${SRC_FOLDER}/entidades/Heroi.cpp
	${COMPILER} -I ${INCLUDE_FOLDER} -c ${SRC_FOLDER}/entidades/Heroi.cpp -o ${BUILD_FOLDER}/Heroi.o

${BUILD_FOLDER}/Personagem.o: ${INCLUDE_FOLDER}/Personagem.hpp ${SRC_FOLDER}/entidades/Personagem.cpp
	${COMPILER} -I ${INCLUDE_FOLDER} -c ${SRC_FOLDER}/entidades/Personagem.cpp -o ${BUILD_FOLDER}/Personagem.o

${BUILD_FOLDER}/Vilao.o: ${INCLUDE_FOLDER}/Vilao.hpp ${SRC_FOLDER}/entidades/Vilao.cpp
	${COMPILER} -I ${INCLUDE_FOLDER} -c ${SRC_FOLDER}/entidades/Vilao.cpp -o ${BUILD_FOLDER}/Vilao.o

clean:
	del /S .\build\*
	del ${PROJECT_NAME}.exe
