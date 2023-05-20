cd ../bin

:: Teste para Quick Sort normal
.\run.exe -v 1 -s 10 -i ../test/entrada.txt -o ./saidaQuickSortNormal.txt -p memlogQuickSortNormal10.out
.\run.exe -v 1 -s 100 -i ../test/entrada.txt -o ./saidaQuickSortNormal.txt -p memlogQuickSortNormal100.out
.\run.exe -v 1 -s 1000 -i ../test/entrada.txt -o ./saidaQuickSortNormal.txt -p memlogQuickSortNormal1000.out
.\run.exe -v 1 -s 20 -i ../test/entrada.txt -o ./saidaQuickSortNormal.txt -p memlogQuickSortNormal20.out
.\run.exe -v 1 -s 2000 -i ../test/entrada.txt -o ./saidaQuickSortNormal.txt -p memlogQuickSortNormal2000.out

:: Teste para Quick Sort com mediana 3
.\run.exe -v 2 -s 10 -k 3 -i ../test/entrada.txt -o ./saidaQuickSortMedianaTres.txt -p memlogQuickSortMedianaTres10.out
.\run.exe -v 2 -s 100 -k 3 -i ../test/entrada.txt -o ./saidaQuickSortMedianaTres.txt -p memlogQuickSortMedianaTres100.out
.\run.exe -v 2 -s 1000 -k 3 -i ../test/entrada.txt -o ./saidaQuickSortMedianaTres.txt -p memlogQuickSortMedianaTres1000.out
.\run.exe -v 2 -s 20 -k 3 -i ../test/entrada.txt -o ./saidaQuickSortMedianaTres.txt -p memlogQuickSortMedianaTres20.out
.\run.exe -v 2 -s 2000 -k 3 -i ../test/entrada.txt -o ./saidaQuickSortMedianaTres.txt -p memlogQuickSortMedianaTres2000.out

:: Teste para Quick Sort com mediana 5
.\run.exe -v 2 -s 10 -k 5 -i ../test/entrada.txt -o ./saidaQuickSortMedianaCinco.txt -p memlogQuickSortMedianaCinco10.out
.\run.exe -v 2 -s 100 -k 5 -i ../test/entrada.txt -o ./saidaQuickSortMedianaCinco.txt -p memlogQuickSortMedianaCinco100.out
.\run.exe -v 2 -s 1000 -k 5 -i ../test/entrada.txt -o ./saidaQuickSortMedianaCinco.txt -p memlogQuickSortMedianaCinco1000.out
.\run.exe -v 2 -s 20 -k 5 -i ../test/entrada.txt -o ./saidaQuickSortMedianaCinco.txt -p memlogQuickSortMedianaCinco20.out
.\run.exe -v 2 -s 2000 -k 5 -i ../test/entrada.txt -o ./saidaQuickSortMedianaCinco.txt -p memlogQuickSortMedianaCinco2000.out

:: Teste para Quick Sort com mediana 7
.\run.exe -v 2 -s 10 -k 7 -i ../test/entrada.txt -o ./saidaQuickSortMedianaSete.txt -p memlogQuickSortMedianaSete10.out
.\run.exe -v 2 -s 100 -k 7 -i ../test/entrada.txt -o ./saidaQuickSortMedianaSete.txt -p memlogQuickSortMedianaSete100.out
.\run.exe -v 2 -s 1000 -k 7 -i ../test/entrada.txt -o ./saidaQuickSortMedianaSete.txt -p memlogQuickSortMedianaSete1000.out
.\run.exe -v 2 -s 20 -k 7 -i ../test/entrada.txt -o ./saidaQuickSortMedianaSete.txt -p memlogQuickSortMedianaSete20.out
.\run.exe -v 2 -s 2000 -k 7 -i ../test/entrada.txt -o ./saidaQuickSortMedianaSete.txt -p memlogQuickSortMedianaSete2000.out

:: Teste para Quick Sort com selecao 10
.\run.exe -v 3 -s 10 -m 10 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoDez.txt -p memlogQuickSortSelecaoDez10.out
.\run.exe -v 3 -s 100 -m 10 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoDez.txt -p memlogQuickSortSelecaoDez100.out
.\run.exe -v 3 -s 1000 -m 10 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoDez.txt -p memlogQuickSortSelecaoDez1000.out
.\run.exe -v 3 -s 20 -m 10 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoDez.txt -p memlogQuickSortSelecaoDez20.out
.\run.exe -v 3 -s 2000 -m 10 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoDez.txt -p memlogQuickSortSelecaoDez200.out

:: Teste para Quick Sort com selecao 100
.\run.exe -v 3 -s 10 -m 100 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoCem.txt -p memlogQuickSortSelecaoCem10.out
.\run.exe -v 3 -s 100 -m 100 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoCem.txt -p memlogQuickSortSelecaoCem100.out
.\run.exe -v 3 -s 1000 -m 100 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoCem.txt -p memlogQuickSortSelecaoCem1000.out
.\run.exe -v 3 -s 20 -m 100 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoCem.txt -p memlogQuickSortSelecaoCem20.out
.\run.exe -v 3 -s 2000 -m 100 -i ../test/entrada.txt -o ./saidaQuickSortSelecaoCem.txt -p memlogQuickSortSelecaoCem200.out

:: Teste para Quick Sort Iterativo
.\run.exe -v 4 -s 10 -i ../test/entrada.txt -o ./saidaQuickSortIterativo.txt -p memlogQuickSortIterativo10.out
.\run.exe -v 4 -s 100 -i ../test/entrada.txt -o ./saidaQuickSortIterativo.txt -p memlogQuickSortIterativo100.out
.\run.exe -v 4 -s 1000 -i ../test/entrada.txt -o ./saidaQuickSortIterativo.txt -p memlogQuickSortIterativo1000.out
.\run.exe -v 4 -s 20 -i ../test/entrada.txt -o ./saidaQuickSortIterativo.txt -p memlogQuickSortIterativo20.out
.\run.exe -v 4 -s 2000 -i ../test/entrada.txt -o ./saidaQuickSortIterativo.txt -p memlogQuickSortIterativo2000.out

:: Teste para Quick Sort Iterativo inteligente
.\run.exe -v 5 -s 10 -i ../test/entrada.txt -o ./saidaQuickSortIterativoInteligente.txt -p memlogQuickSortIterativoInteligente10.out
.\run.exe -v 5 -s 100 -i ../test/entrada.txt -o ./saidaQuickSortIterativoInteligente.txt -p memlogQuickSortIterativoInteligente100.out
.\run.exe -v 5 -s 1000 -i ../test/entrada.txt -o ./saidaQuickSortIterativoInteligente.txt -p memlogQuickSortIterativoInteligente1000.out
.\run.exe -v 5 -s 20 -i ../test/entrada.txt -o ./saidaQuickSortIterativoInteligente.txt -p memlogQuickSortIterativoInteligente20.out
.\run.exe -v 5 -s 2000 -i ../test/entrada.txt -o ./saidaQuickSortIterativoInteligente.txt -p memlogQuickSortIterativoInteligente2000.out

:: Teste para Merge Sort Iterativo inteligente
.\run.exe -r 2 -r 2 -v 2 -s 10 -i ../test/entrada.txt -o ./saidaMergeSort.txt -p memlogMergeSort10.out
.\run.exe -r 2 -v 2 -s 100 -i ../test/entrada.txt -o ./saidaMergeSort.txt -p memlogMergeSort100.out
.\run.exe -r 2 -v 2 -s 1000 -i ../test/entrada.txt -o ./saidaMergeSort.txt -p memlogMergeSort1000.out
.\run.exe -r 2 -v 2 -s 20 -i ../test/entrada.txt -o ./saidaMergeSort.txt -p memlogMergeSort20.out
.\run.exe -r 2 -v 2 -s 2000 -i ../test/entrada.txt -o ./saidaMergeSort.txt -p memlogMergeSort2000.out

:: Teste para Heap Sort Iterativo inteligente
.\run.exe -r 2 -v 3 -s 10 -i ../test/entrada.txt -o ./saidaHeapSort.txt -p memlogHeapSort10.out
.\run.exe -r 2 -v 3 -s 100 -i ../test/entrada.txt -o ./saidaHeapSort.txt -p memlogHeapSort100.out
.\run.exe -r 2 -v 3 -s 1000 -i ../test/entrada.txt -o ./saidaHeapSort.txt -p memlogHeapSort1000.out
.\run.exe -r 2 -v 3 -s 20 -i ../test/entrada.txt -o ./saidaHeapSort.txt -p memlogHeapSort20.out
.\run.exe -r 2 -v 3 -s 2000 -i ../test/entrada.txt -o ./saidaHeapSort.txt -p memlogHeapSort2000.out
 