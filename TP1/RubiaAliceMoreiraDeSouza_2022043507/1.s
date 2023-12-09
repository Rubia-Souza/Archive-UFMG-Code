.data
vetor: .word 0 0 0 0

##### START MODIFIQUE AQUI START #####
#
# Este espaço é para você definir as suas constantes e vetores auxiliares.
#
##### END MODIFIQUE AQUI END #####

.text
jal x1, contador
addi x14, x0, 2 # utilizado para correção
beq x14, x10, FIM # Verifica # de pares
beq x14, x11, FIM # Verifica # de ímpares

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