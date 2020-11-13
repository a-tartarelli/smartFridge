/**
* @file carica_file.h
*
* Questo file contiene tutte le funzioni che consentono di leggere i file binari esistenti riguardanti
* gli alimenti, le ricette e il menu settimanale e ricavarne dei vettori.
* In ogni elemento del vettore verra' scritto ciascun record del file letto.
* Normalmente queste funzioni vengono utilizzate all'inizio di un programma per effettuare il caricamento
* da file.
* Se i file letti risultano essere vuoti, verranno 'popolati' con le funzioni del tipo popolazione file
* che inizializzano dei vettori da codice e li scrivono sul file aperto.
*
* @version 1.0
* @date 02/06/2018
* @authors Giuseppe Murro, Alessio Tartarelli
* @bug Se i file da aprire non esistono, il programma chiamante non termina correttamente.
*/


#ifndef CARICA_FILE_H_
#define CARICA_FILE_H_

#include "strutture_dati.h"

#endif /* CARICA_FILE_H_ */



/**
* Questa funzione legge il file, il cui nome viene passato come parametro, e
* alloca un vettore di tipo alimento. Ad ogni elemento del vettore verra' assegnato
* un record valido letto dal file.
*
* @param[in] nome_file: Vettore di caratteri che rappresenta il nome del file da leggere (es. elenco_alimenti.bin)
* @param[in] numero_alimenti: Valore intero riguardante la lunghezza del vettore di tipo alimento che verra' allocato.
* 							  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return alimento* : Puntatore al vettore di tipo alimento allocato dalla funzione
*/

alimento* carica_elenco_alimenti ( char* nome_file, unsigned short int numero_alimenti );





/**
* Questa funzione aprira' il file, il cui nome viene passato come parametro, e
* scrivera' su di esso un insieme di record di tipo alimento inizializzati da codice.
* Il numero di record che verranno scritti scritti e' limitato dal secondo paramentro.
*
* @param[in] nome_file: Vettore di caratteri che rappresenta il nome del file da aprire in scrittura (es. elenco_alimenti.bin)
* @param[in] numero_alimenti: Valore intero riguardante il massimo numero di record che verranno scritti sul file.
* * 						  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return unsigned short int* : Valore intero che rappresenta il numero di record di tipo alimento effettivamente scritti sul file.
*/

unsigned short int popolazione_file_alimenti (char* nome_file, unsigned short int numero_alimenti );





/**
* Questa funzione aprira' il file, il cui nome viene passato come parametro, e
* scrivera' su di esso un insieme di record di tipo ricetta inizializzati da codice.
* Il numero di record che verranno scritti scritti e' limitato dal secondo paramentro.
*
* @param[in] nome_file: Vettore di caratteri che rappresenta il nome del file da aprire in scrittura (es. elenco_ricette.bin)
* @param[in] numero_ricette: Valore intero riguardante il massimo numero di record che verranno scritti sul file.
* 							 Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return unsigned short int* : Valore intero che rappresenta il numero di record di tipo ricette effettivamente scritti sul file.
*/

unsigned short int popolazione_file_ricette (char* nome_file, unsigned short int numero_ricette );





/**
* Questa funzione legge il file, il cui nome viene passato come parametro, e
* alloca un vettore di tipo ricetta. Ad ogni elemento del vettore verra' assegnato
* un record valido letto dal file.
*
* @param[in] nome_file: Vettore di caratteri che rappresenta il nome del file da leggere (es. elenco_ricette.bin)
* @param[in] numero_ricette: Valore intero riguardante la lunghezza del vettore di tipo ricette che verra' allocato.
* 							 Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return alimento* : Puntatore al vettore di tipo ricette allocato dalla funzione
*/

ricetta* carica_elenco_ricette ( char* nome_file, unsigned short int numero_ricette );





/**
* Questa funzione legge il file, il cui nome viene passato come parametro, e
* alloca un vettore di tipo menu_giornaliero. Ad ogni elemento del vettore verra' assegnato
* un record valido letto dal file.
*
* @param[in] nome_file: Vettore di caratteri che rappresenta il nome del file da leggere (es.menu_settimanale.bin)
* @param[in] numero_menu_giornalieri: Valore intero riguardante la lunghezza del vettore di tipo menu_giornaliero che verra' allocato.
* 							  		  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return menu_giornaliero* : Puntatore al vettore di tipo menu_giornaliero allocato dalla funzione
*/

menu_giornaliero* carica_menu_settimanale (char* nome_file, unsigned short int numero_menu_giornalieri);
