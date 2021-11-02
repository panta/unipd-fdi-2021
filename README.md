README
======

Questo repository contiene codice C relativo al corso di
Fondamenti di Informatica dell'[Università di Padova](https://www.unipd.it/) per
Ingegneri Meccatronici, anno 2021/2022.

Il materiale relativo a specifiche lezioni è disponibile nelle relative sotto-directory.


## Prerequisiti

Il codice dovrebbe essere compilabile senza problemi con qualunque compilatore C99 o successivo
(alcuni esempi potrebbero usare a scopo didattico versioni precedenti dello standard C, come C89/C90,
ma dovrebbero essere comunque utilizzabili anche con compilatori più recenti), su sistemi POSIX-compatibili.
Alcuni esempi potrebbero essere specifici per linux o unix (bsd, ...).

Si consiglia di utilizzare (eventualmente in una macchina virtuale), sistemi debian o ubuntu.

### Installazione dei pre-requisiti su debian/ubuntu

```bash
$ sudo apt-get install build-essential git manpages-dev
```

(`manpages-dev` non è un requisito ma è pacchetto di documentazione consigliato).

### Installazione dei pre-requisiti su macOS

E` possibile installare Homebrew e git:
```bash
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)" 

$ brew update
$ brew install git
```


## Come scaricare il repository

Il repository completo è disponibile su [github](https://github.com/panta/unipd-fdi-2021.git).
Per crearne una copia sul proprio sistema utilizzando [git](https://git-scm.com/):

```bash
$ mkdir ~/projects
$ cd ~/projects
$ git clone https://github.com/panta/unipd-fdi-2021.git
$ cd unipd-fdi-2021
```

## Utilizzo

Nelle directory in cui il codice conduce a programmi eseguibili, solitamente è presente un
`Makefile` che ne dettaglia e automatizza la compilazione.

Per compilare tutti i programmi presenti in una sotto-directory, sui sitemi linux/unix è
sufficiente entrare nella directory da riga di comando e dare il comando `make`:

```bash
$ cd lezione-13
$ make
...

$ ./simple
Hello, World!
length of <2, 1>: 2.23607
```


## Licenza

Tutto il materiale, ove non diversamente specificato, è rilasciato sotto licenza "GNU General Public License",
pubblicata da [Free Software Foundation](https://www.fsf.org/), nella versione 2 (nota anche come GNU GPL v2).
Il testo completo della licenza è disponibile nel file `COPYING`.

Per tutto il materiale, ove non diversamente specificato:

Copyright (C) 2020-2021 Marco Pantaleoni. Tutti i diritti riservati.
Copyright (C) 2020-2021 Marco Pantaleoni. All rights reserved.
