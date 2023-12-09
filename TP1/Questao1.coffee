.data
vetor: .word 2 3 4 5
vetor2: .word 11 21 307 75
vetor3: .word 1 2 3 4 5 6 7 8 9 10
vetor4: .word -1 2 -3 -4 5 -6 7

##### START MODIFIQUE AQUI START #####
#
# Este espaço é para você definir as suas constantes e vetores auxiliares.
#
##### END MODIFIQUE AQUI END #####

.text

teste1:
    la x7, vetor
    addi x28, x0, 4

    jal x1, contador

    addi x14, x0, 2 # utilizado para correção
    verificacao1_1: beq x14, x10, verificacao1_2    # Verifica # de pares
    verificacao1_2: beq x14, x11, teste2            # Verifica # de ímpares

teste2:
    la x7, vetor2
    addi x28, x0, 4

    jal x1, contador

    addi x14, x0, 4
    verificacao2_1: beq x0, x10, verificacao2_2     # Verifica # de pares
    verificacao2_2: beq x14, x11, teste3            # Verifica # de ímpares

teste3:
    la x7, vetor3
    addi x28, x0, 10

    jal x1, contador

    addi x14, x0, 5
    verificacao3_1: beq x14, x10, verificacao3_2    # Verifica # de pares
    verificacao3_2: beq x14, x11, teste4            # Verifica # de ímpares

teste4:
    la x7, vetor4
    addi x28, x0, 7

    jal x1, contador

    addi x14, x0, 3
    addi x15, x0, 4
    verificacao4_1: beq x14, x10, verificacao4_2    # Verifica # de pares
    verificacao4_2: beq x15, x11, FIM               # Verifica # de ímpares

##### START MODIFIQUE AQUI START #####

# IMPORTANTE: Nessa questão considerei que os valores dos registradores t2, e t3 já são passados como parâmetro para a função.
# Ou seja, não é necessário carregar o vetor em t2 e nem o tamanho do vetor em t3.

# t2 (x7) = endereço do vetor
# t3 (x28) = tamanho do vetor

# t0 (x5) = indice ajustado do vetor
# t1 (x6) = indice do vetor
# t4 (x29) = elemento atual do vetor
# t5 (x30) = resto divisão por 2
# t6 (x31) = constante 2

# a0 (x10) = quantidade pares
# a1 (x11) = quantidade ímpares

contador:
    # Inicializar variáveis

    # Inicializa registradores auxiliares
    addi x5, x0, 0      # indice_ajustado = 0
    addi x6, x0, 0      # indice = 0
    addi x29, x0, 0     # elemento_atual = 0
    addi x30, x0, 0     # resto = 0
    addi x31, x0, 2     # constante_2 = 2

    # Inicializa registradores de contagem
    addi x10, x0, 0      # contador_pares = 0
    addi x11, x0, 0      # contador_impares = 0

    # Caso fosse necessário carregar o vetor em x7 bastaria descomentar as linhas abaixo
    # Carrega vetor em t2
    # la x7, vetor      # x7 = endereço do vetor

    # Armazena posição inicial do vetor na pilha
    addi x2, x2, -4     # Aloca uma posição na pilha
    sw x7, 0(x2)        # Armazena o endereço inicial do vetor na pilha

    loop_contagem:
        bge x6, x28, fim_loop # indice >= tamanho ? goto fim_loop : continue

        # Carrega elemento atual do vetor
        lw x29, 0(x7)       # valor_atual = vetor[x6]

        # Atualiza indice do vetor
        addi x7, x7, 4      # indice_ajustado += 4
        addi x6, x6, 1      # indice++

        # Verifica se o número é par ou impar
        rem x30, x29, x31   # resto = valor_atual % 2
        beq x30, x0, par    # resto == 0 ? goto par : goto impar
    
        impar: # Incrementar quantidade de ímpares
            addi x11, x11, 1    # contador_impares++
            j loop_contagem     # goto loop_contagem

        par: # Incrementar quantidade de pares
            addi x10, x10, 1    # contador_pares++
            j loop_contagem     # goto loop_contagem
    fim_loop:

    # Recarrega posição inicial do vetor
    lw x7, 0(x2)        # Carrega o endereço inicial do vetor
    addi x2, x2, 4      # Desaloca uma posição da pilha
    
    jalr x0, 0(x1)      # return

##### END MODIFIQUE AQUI END #####

FIM: addi x0, x0, 1