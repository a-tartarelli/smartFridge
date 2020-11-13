/**
* @file gestione_utenti.h
*
* Questo file contiene tutte le funzioni necessarie per gestire il gli account degli utenti, come ad
* esempio l'aggiunta di un nuovo utente, la cancellazione, la scelta dell'utente con cui loggarsi ecc.
* La maggior parte delle funzioni lavorano direttamente sul file in cui gli utenti vengono registrati.
* I campi della struct utente su cui le funzioni lavorano sono : id del utente e nome utente.
*
* @version 1.0
* @date 04/06/2018
* @authors Giuseppe Murro, Alessio Tartarelli
*/

#ifndef SRC_GESTIONE_UTENTI_H_
#define SRC_GESTIONE_UTENTI_H_

#include "strutture_dati.h"
#include "controlli.h"

#endif /* SRC_GESTIONE_UTENTI_H_ */

/**
 * Questa funzione riceve come paramentro una stringa (nome_file) e restituisce un intero.
 * Stampera'sottoforma di elenco tutti gli username degli account salvati sul file
 * (il cui nome e' proprio il parametro), e passera'come valore di ritorno
 * l'identificativo dell'ultimo username stampato.
 * Se nel file non e' registrato
 * ancora nessun utente, la funzione ritonera'0.
 *
 * @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui sono memorizzati gli utenti
 * @return unsigned short int: Intero che sara' id dell'ultimo utente stampato
 */

unsigned short int mostra_utenti (char nome_file[]);





/**
 * Questa funzione boolena riceve come paramentro un dato di tipo utente (utente_letto) e restituisce un intero.
 * Stampera'a' l'id e l'username dell'utente passato come parametro e
 * se i campi stampati sono effettivamente pieni la funzione restituira' 1;
 * altrimenti restituira' 0
 *
 * @param utente_letto: Variabile di tipo 'utente' i cui dati devo essere stampati
 * @return unsigned short int: Intero che indica se i campi dell'utente sono pieni o meno
 */
unsigned short int stampa_utente (utente utente_letto);





/**
 * Questa funzione riceve come paramentri due stringhe (nome_file e nome_utente) e un intero (id_ultimo_utente) e restituisce un intero.
 * La funzione aprira' in modalita' 'append' il file il cui nome e' stato passato come parametro
 * e scrivera' su di esso un dato utente il cui username e' stato passato come parametro.
 * La funzione restituita'a' l'identificativo dell'utente aggiunto al file
 *
 * @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui sono memorizzati gli utenti
 * @param nome_utente: Vettore di caratteri che rappresenta il nome dell'utente che deve essere aggiunto
 * @param id_ultimo_utente: Intero che indica l'id dell'ultimo utente scritto sul file
 * @return unsigned short int: Intero che rappresenta id dell'utente aggiunto al file
 */

unsigned short int aggiungi_utente (char nome_file[], char nome_utente[], unsigned short int id_ultimo_utente);





/**
 * Questa funzione riceve come paramentro una stringa (nome_file) e restituisce un intero.
 * La funzione mostrera' sottoforma di elenco gli utenti scritti sul file e chiedera' all'utente
 * di inserire in input un identificativo.
 * Se l'input e' 0, verra' aggiunto un nuovo utente al file e verra' restitito il suo identificativo;
 * Se l'input e' uno tra gli id scritti sul file, verra' restitito il suo identificativo;
 * Se l'input non e' corretto sara' richiesto un nuovo input.
 *
 * @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui sono memorizzati gli utenti
 * @return unsigned short int: Intero che rappresenta l'id_utente scelto
 */

unsigned short int seleziona_utente (char nome_file[]);





/**
 * Questa funzione boolena riceve come paramentri due stringhe (nome_utente e nome_file) e restituisce un intero.
 * La funzione aprira' in lettura il file il cui nome e' proprio il parametro nome_file e controllera'
 * se il nome utente passato come parametro esiste tra gli utenti scritti sul file.
 * Se esiste una corrispondenza la funzione restituira' 1;
 * altrimenti stampera' un messaggio di errore e restituira' 0
 *
 * @param nome_utente: Vettore di caratteri che rappresenta il nome dell'utente per cui verificare l'esistenza
 * @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui sono memorizzati gli utenti
 * @return unsigned short int: Intero che indica se l'utente esiste o meno sul file.
 */

unsigned short int is_utente_esistente (char nome_utente[], char nome_file[]);





/**
 * Questa funzione riceve come paramentri una stringa (nome_file) e un intero (id_utente) e  restituisce un intero.
 * La funzione aprira' in lettura il file il cui nome e' proprio il parametro nome_file e controllera'
 * se l'id dell' utente passato come parametro esiste tra gli utenti scritti sul file.
 * Se esiste una corrispondenza la funzione restituira' il puntatore al nome utente corrispondete;
 * altrimenti stampera' un messaggio di errore e restituira' NULL
 *
 * @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui sono memorizzati gli utenti
 * @param id_utente: Intero che rappresenta l'id utente che deve essere cercato nel file
 * @return char*: Puntatore al nome utente corrispondete all'id passato come parametro
 */

char* ricerca_utente (char nome_file[], unsigned short int id_utente);





/**
 * Questa funzione riceve come paramentri una stringa (nome_file) e un intero (id_utente) e  restituisce un intero.
 * La funzione aprira' in lettura/scrittura il file il cui nome e' proprio il parametro nome_file e
 * controllera' se l'id dell' utente passato come parametro esiste tra gli utenti scritti sul file.
 * Se esiste una corrispondenza la funzione sovrascrivera' nel file l'utente trovato con un utente vuoto, cancellera' il menu settimanale corrispondente
 * e chiedera' all'utente di accedere ad un altro account.
 * La funzione restituira' l'id digitato da tastiera con cui effettuare il nuovo login
 *
 * @param nome_file_utenti: Vettore di caratteri che rappresenta il nome del file su cui sono memorizzati gli utenti
 * @param nome_file_menu: Vettore di caratteri che rappresenta il nome del file su cui sono memorizzati i menu' settimanali degli utenti
 * @param id_utente: Intero che rappresenta l'id dell'utente da cancellare
 * @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che verra' modificato
 * @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore menu_settimanale
 * @return unsigned short int: Intero che rappresenta l'id digitato da tastiera con cui effettuare il nuovo login
 */
unsigned short int input_cancella_utente (char nome_file_utenti[], char nome_file_menu[], unsigned short int id_utente, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri);





/**
 * Questa funzione cancella dal file l'utente il cui id viene passato come secondo parametro.
 * Restituisce 1 se l'utente e' stato cancellato, 0 altrimenti.
 *
 * @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui sono memorizzati gli utenti
 * @param id_utente: Intero che rappresenta l'id dell'utente da cancellare
 * @return unsigned short int: Intero che indica se la cancellazione e' andata a buon fine o meno
 */
unsigned short int cancella_utente (char nome_file[], unsigned short int id_utente);





/**
 * Questa funzione cancella dal vettore menu_settimanale e dal file il cui nome e' stato passato come primo parametro,
 *  tutti i menu giornalieri che hanno come id_utente, l'identificativo passato come secondo parametro.
 *  Restituisce 1 se il menu settimanale e' stato cancellato, 0 altrimenti.
 *
 * @param nome_file_menu: Vettore di caratteri che rappresenta il nome del file su cui sono memorizzati i menu giornalieri
 * @param id_utente: Intero che rappresenta l'id dell'utente per il quale cancellate i menu gironalieri
 * @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che verra' modificato
 * @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore menu_settimanale
 * @return unsigned short int: Intero che indica se la cancellazione e' andata a buon fine o meno
 */
unsigned short int cancella_menu_settimanale_utente (char nome_file_menu[], unsigned short int id_utente, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri);
