/**
* @file elaborazione_alimenti.h
*
* Questo file contiene tutte le funzioni necessarie per gestire gli alimenti nel frigo, come ad
* esempio l'aggiunta di un nuovo alimento, la modifica, la cancellazione, la stampa di tutti gli alimenti, l'ordinamento, ecc.
* La maggior parte delle funzioni lavorano su vettori di tipo alimento, che vengono passati per riferimento e quindi potranno essere modificati dalle funzioni,
* a meno che non sia indicato il qualificatore const.
* I campi della struct alimento su cui le funzioni lavorano sono : id, nome, data scadenza, numero pezzi e peso unitario.
*
* @version 1.0
* @date 03/06/2018
* @authors Giuseppe Murro, Alessio Tartarelli
*/

#ifndef ELABORAZIONE_ALIMENTI_H_
#define ELABORAZIONE_ALIMENTI_H_

#include "strutture_dati.h"
#include "controlli.h"
#include "date.h"

#endif /* ELABORAZIONE_ALIMENTI_H_ */





/**
* Questa funzione prende in input un vettore di tipo 'alimento', che non puo' essere modificato, e la sua lunghezza
* e stampa sottoforma tabellare tutti i campi degli elementi scritti nel vettore con un id valido (>0).
* La funzione restituisce il numero di elementi stampati.
*
* @param alimenti_frigo: Vettore di tipo 'alimento' che puo' essere unicamnete letto
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @return unsigned short int: Intero positivo che rappresenta il numero di elementi stampati
*/

unsigned short int apri_frigo ( const alimento alimenti_frigo[], unsigned short int numero_alimenti );





/**
* Questa procedura consente di acquire da tastiera i campi dei un nuovo alimento da aggiungere e controlla se sono corretti.
* In tal caso l'alimento verra' aggiunto in coda al vettore alimenti_frigo passato come secondo parametro e verra' aggiunto al file
* il cui nome e' stato passato come primo parametro.
*
* @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui aggiungere l'alimento
* @param alimenti_frigo: Vettore di tipo 'alimento' che verra' modificato
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
*/

void input_aggiungi_alimento ( char* nome_file, alimento* alimenti_frigo, unsigned short int numero_alimenti );





/**
* Questa funzione scrive l'alimento passato come secondo parametro sul file
* il cui nome e' stato passato come primo parametro.
* Se la scrittura e' andata a buon fine, restituisce 1, altrimenti restuisce 0.
*
* @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui aggiungere l'alimento
* @param alimento_frigo: Variabile di tipo 'alimento' che sara' scritta su un record del file
* @return unsigned short int: Valore booleano che rappresenta l'esito della scrittura
*/

unsigned short int aggiungi_alimento ( char* nome_file, alimento alimento_frigo ) ;





/**
* Questa funzione legge il vettore di alimenti passato come primo parametro e restituisce
* un intero che rappresenta un nuovo id diverso da tutti gli altri.
*
* @param alimenti_frigo: Vettore di tipo 'alimento' che verra' letto
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @return unsigned short int: Intero che rappresenta un nuovo id valido
*/

unsigned short int get_nuovo_id_alimento (const alimento* alimenti_frigo, unsigned short int numero_alimenti);





/**
* Questa funzione legge il vettore di alimenti passato come primo parametro e restituisce
* un intero che rappresenta l'ultimo indice valido, cioe' l'ultimo elemento che ha un id > 0.
*
* @param alimenti_frigo: Vettore di tipo 'alimento' che verra' letto
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @return unsigned short int: Intero che rappresenta l'ultimo indice contenete un alimento valido
*/

unsigned short int get_ultimo_indice_alimento (const alimento* alimenti_frigo, unsigned short int numero_alimenti);





/**
* Questa funzione prende in input un vettore di tipo 'alimento', che non puo' essere modificato,
* e verfica se il terzo parametro e' uno tra gli id nel vettore.
* Se si ha almeno una corrispondenza, la funzione restituisce 1,
* altrimenti retituisce 0.
*
* @param alimenti_frigo: Vettore di tipo 'alimento' che verra' letto
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @param id_alimento: Id da cercare nel vettore
* @return unsigned short int: Intero booleano che indica se l'id esiste o meno nel vettore
*/

unsigned short int is_alimento_esistente (const alimento* alimenti_frigo,unsigned short int numero_alimenti, unsigned short int id_alimento);





/**
* Questa funzione prende in input un vettore di tipo 'alimento', che non puo' essere modificato,
* e restituisce l'indice dell'elemento che ha come id il terzo parametro.
*
* @param alimenti_frigo: Vettore di tipo 'alimento' che verra' letto
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @param id_alimento: Id da cercare nel vettore
* @return unsigned short int: Intero che rappresenta l'indice dell'id cercato
*/

unsigned short int indice_id_alimento (const alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int id_alimento);





/**
* Questa funzione sostituisce l'alimento passato come secondo parametro al precedente record
* scritto sul file il cui nome e' stato passato come primo parametro.
* Se la scrittura e' andata a buon fine, restituisce 1, altrimenti restituisce 0.
*
* @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui modificare l'alimento
* @param alimento_frigo: Variabile di tipo 'alimento' che sara' scritta su un record del file
* @return unsigned short int: Valore booleano che rappresenta l'esito della scrittura
*/

unsigned short int modifica_alimento ( char* nome_file, alimento alimento_frigo );





/**
* Questa procedura consente di acquire da tastiera il campo dei un nuovo alimento da modificare e controlla e' corretto.
* In tal caso l'alimento verra' modificato sia nel vettore alimenti_frigo passato come secondo parametro e sia nel file
* il cui nome e' stato passato come primo parametro.
*
* @param nome_file: Vettore di caratteri che rappresenta il nome del file in cui modificare l'alimento
* @param alimenti_frigo: Vettore di tipo 'alimento' che verra' modificato
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
*/

void input_modifica_alimento (char* nome_file, alimento* alimenti_frigo, unsigned short int numero_alimenti);





/**
* Questa funzione controlla se gli alimenti del vettore passato come secondo paramentro hanno una data di scadenza uguale alla data corrente, passata come
* quarto parametro, e in caso positivo tali alimenti vengono eliminati dal vettore e dal file che ha come nome la stringa passata come primo parametro.
* Se c'e' almeno un alimento scaduto, la funzione restituisce 1, altrimenti restituisce 0.
*
* @param nome_file: Vettore di caratteri che rappresenta il nome del file da cui eliminare l'alimento
* @param alimenti_frigo: Vettore di tipo 'alimento' che verra' letto
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @param data_corrente: Data corrente al momento della chiamata della funzione
* @return unsigned short int: Intero booleano che indica se ci sono alimenti scaduti o meno
*/

unsigned short int is_alimenti_scaduti  ( char* nome_file, alimento* alimenti_frigo, unsigned short int numero_alimenti, data data_corrente );





/**
* Questa funzione controlla l'alimento passato come primo paramentro ha una data di scadenza uguale alla data corrente, passata come
* secondo parametro, e in caso positivo la funzione restituisce 1, altrimenti restituisce 0.
*
* @param alimento_frigo: Variabile di tipo 'alimento' sulla quale verra' effettuato il controllo
* @param data_corrente: Data corrente al momento della chiamata della funzione
* @return unsigned short int: Intero booleano che indica se l' alimento e' scaduto o meno
*/

unsigned short int is_scaduto (alimento alimento_frigo, data data_corrente);





/**
* Questa funzione cancella l'alimento passato come secondo parametro dal
* file il cui nome e' stato passato come primo parametro.
* Se la cancellazione e' andata a buon fine, restituisce 1, altrimenti restituisce 0.
*
* @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui cancellare l'alimento
* @param alimento_da_cancellare: Variabile di tipo 'alimento' che sara' cancellata dal file
* @return unsigned short int: Valore booleano che rappresenta l'esito della cancellazione
*/

unsigned short int cancella_alimento ( char* nome_file, alimento alimento_da_cancellare );





/**
* Questa funzione controlla quali alimenti del vettore passato come secondo parametro sono in scadenza,
* e li aggiunge al vettore di stringhe passato come primo parametro.
* La funzione restituisce il numero degli alimenti in scadenza.
*
* @param alimenti_scadenza: Vettore di stringhe che verra' modificato dalla funzione
* @param alimenti_frigo: Vettore di tipo 'alimento' che verra' letto
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @param data_corrente: Data corrente al momento della chiamata della funzione
* @param soglia_scadenza: Intero che rappresenta il numero dei giorni entro i quali un alimento e' considerato in scadenza
* @return unsigned short int: Intero che rappresenta il numero di aliemnti in scadenza
*/

unsigned short int controlla_scadenza_alimenti  (char alimenti_scadenza[][LUNGHEZZA_NOME], const alimento* alimenti_frigo, unsigned short int numero_alimenti, data data_corrente, unsigned short int soglia_scadenza);





/**
* Questa procedura prende in input un vettore di stringhe, che non puo' essere modificato, e la sua lunghezza
* e stampa tutti gli elementi di tale vettore.
*
* @param alimenti_scadenza: Vettore di stringhe che  memorizza i nomi degli alimenti in scadenza
* @param contatore_scadenza_alimenti: Intero che rappresenta il numero effettivo di alimenti in scadenza nel vettore
* @param soglia_scadenza:  Intero che rappresenta il numero dei giorni entro i quali un alimento e' considerato in scadenza
*/

void stampa_alimenti_scadenza ( const char alimenti_scadenza[][LUNGHEZZA_NOME], unsigned short int contatore_scadenza_alimenti, unsigned short int soglia_scadenza);





/**
* Questa funzione controlla quali alimenti del vettore passato come secondo parametro sono in esaurimento,
* e li aggiunge al vettore di stringhe passato come primo parametro.
* La funzione restituisce il numero degli alimenti in esaurimento.
*
* @param alimenti_esaurimento: Vettore di stringhe che verra' modificato dalla funzione
* @param alimenti_frigo: Vettore di tipo 'alimento' che verra' letto
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @param soglia_esaurimento: Intero che rappresenta la soglia oltre la quale un alimento e' considerato in esaurimento
* @return unsigned short int: Intero che rappresenta il numero di alimenti in esaurimento
*/

unsigned short int controlla_esaurimento_alimenti  (char alimenti_esaurimento[][LUNGHEZZA_NOME],   alimento* alimenti_frigo, unsigned short int numero_alimenti,  unsigned short int soglia_esaurimento);




/**
* Questa procedura prende in input un vettore di stringhe, che non puo' essere modificato, e la sua lunghezza
* e stampa tutti gli elementi di tale vettore.
*
* @param alimenti_esaurimento: Vettore di stringhe che memorizza i nomi degli alimenti in esaurimento
* @param contatore_esaurimento_alimenti: Intero che rappresenta il numero effettivo di alimenti in esaurimento nel vettore
*/

void stampa_alimenti_esaurimento (const char alimenti_esaurimento[][LUNGHEZZA_NOME], unsigned short int contatore_esaurimento_alimenti);





/**
* Questa funzione prende in input un vettore di tipo 'alimento'
* e lo ordina in modo crescente in base alla data di scadenza.
*
* @param vett: Vettore di tipo 'alimento' che verra' ordinato
* @param n: Intero che rappresenta il numero di elementi da cui e' composto il vettore
*/

void shell_sort_date (alimento* vett, int n);
