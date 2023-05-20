cd ../bin

:: Executa teste com Árvore AVL
.\run.exe -i ../test/entrada00.txt -o ./saidaAVL-endrada00.txt -t arv
.\run.exe -i ../test/entrada01.txt -o ./saidaAVL-endrada01.txt -t arv
.\run.exe -i ../test/entrada02.txt -o ./saidaAVL-endrada02.txt -t arv
.\run.exe -i ../test/entrada03.txt -o ./saidaAVL-endrada03.txt -t arv
.\run.exe -i ../test/entrada04.txt -o ./saidaAVL-endrada04.txt -t arv

:: Executa teste com Hash
.\run.exe -i ../test/entrada00.txt -o ./saidaHash-endrada00.txt -t hash
.\run.exe -i ../test/entrada01.txt -o ./saidaHash-endrada01.txt -t hash
.\run.exe -i ../test/entrada02.txt -o ./saidaHash-endrada02.txt -t hash
.\run.exe -i ../test/entrada03.txt -o ./saidaHash-endrada03.txt -t hash
.\run.exe -i ../test/entrada04.txt -o ./saidaHash-endrada04.txt -t hash
