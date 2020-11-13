/**
* @file lista_spesa.h
*
* Questo file contine tutte le funzioni per la gestione della lista delle spesa del porgramma.
*
* @version 1.0
* @date 04/06/2018
* @authors Giuseppe Murro, Alessio Tartarelli
*/



#include "strutture_dati.h"

/**
 * Procedura che si occupa di aggiungere un elemento alla lista della spesa.
 * Se l'alimento e' gia' presente in lista allora non verra' aggiunto.
 *
 * @param nome_file indica il nome del file su cui verranno salvati i vari alimenti da
 * aggiungere alla lista
 * @param alimento indica l'alimento da aggiungere alla lista della spesa
 * @return 1 se l'alimento viene aggiunto alla lista della spesa
 * @return 0 se l'alimento non viene aggiunto alla lista della spesa
 */
unsigned short int aggiungi_a_lista(char nome_file[], char* alimento);

/**
 * Procedura per la lettura da file degli alimenti presenti  nella lista delle spase.
 * Gli alimenti letti verranno stampati a video.
 *
 * @param nome_file indica il nome del file da cui si andranno a leggere gli alimenti
 */
unsigned short int stampa_lista_spesa (char* nome_file);


/**
 *
 */
unsigned short int cancella_lista_spesa(char nome_file[]);
