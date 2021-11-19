# Grafy-To-Go
Grafy-To-Go è un'applicativo che permette l'uso delle operazioni CRUD sulle strutture dati e con gli algoritmi visti durante il corso di "Algoritmi e strutture dati".
Quindi, permette l'uso delle più comuni operazioni su code, stack, alberi binari (R&B) e grafi, il tutto su una linearissima CMD.
Particolare attenzione si è prestata alle prestazioni, dove, oltre ad aver usato tutti algoritmi a tempo asintoticamente ottimali, sono stati utilizzati strumenti per il debug in memoria, per la ricerca dei memory leak ed il profiling del software, come ad esempio Valgrind, in ambiente C.

# Come iniziare
L'applicativo attualmente non presenta installer e và importato nel proprio IDE per essere anche solo eseguito. Bisogna inanzitutto creare una nuova repository Git, effettuare una clonazione del contenuto della repository originale, per poi effettaure il mirror con la copia locale. Tramite command line di Git:
```
$ git clone --bare https://github.com/Noctino52/Grafy-To-Go
$ cd Grafy-To-Go
$ git push --mirror https://github.com/Noctino52/Grafy-To-Go
$ cd ..
$ rm -rf Grafy-To-Go
```
