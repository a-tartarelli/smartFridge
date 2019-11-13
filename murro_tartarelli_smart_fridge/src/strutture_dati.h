/**
* @file strutture_dati.h
*
* Questa libreria contiene tutti i tipi di dati da noi definiti, come ad esempio il
* tipo ::ricetta. Oltre ai tipi di dato sono presenti anche tutte le costanti simboliche
* utilizzate nel programma e ci sono anche delle inclusioni a delle librerie piu' comuni
* e utilizzate.
*
*
* @version 1.0
* @date 03/06/2018
* @authors Giuseppe Murro, Alessio Tartarelli
*/

#ifndef STRUTTURE_DATI_H_
#define STRUTTURE_DATI_H_

/**
 * Costante utilizzata per indicare il valore per cui il numero di elementi di
 * un vettore deve essere diviso per ottenere il centro
 */
#define DIVIDI_ARRAY 2
/**
 * Costante utilizzata per indicare il numero massimo di alimenti in esaurimento
 */
#define MAX_ALIMENTI_ESAURIMENTO 30
/**
 * Costante utilizzata per indicare il numero minimo di alimenti inseriti
 * per poter effettuare una ricerca per insieme di alimenti
 */
#define MIN_ALIMENTI_RICERCA 2
/**
 * Costante utilizzata per indicare il numero massimo di alimenti inseriti
 * per poter effettuare una ricerca per insieme di alimenti
 */
#define MAX_ALIMENTI_RICERCA 7
/**
 * Costante utilizzata per indicare il numero minimo di alimenti inseriti
 * per poter effettuare una ricerca per insieme di alimenti
 */
#define MAX_SCELTA_RICERCA 4
/**
 * Costante utilizzata per indicare il numero massimo di persone per cui si puo'
 * preparare una ricetta o per quante persone
 * e' quella data ricette in fase di aggiunta di una nuova ricetta
 */
#define MAX_PERSONE 10
/**
 * Costante utilizzata per indicare il numero massimo di kcal di un piatto
 */
#define MAX_CALORIE 9000
/**
 * Costante utilizzata per indicare la lunghezza massima
 * della stringa che indica la quantita'  di un alimento
 */
#define MAX_QUANTITA 1500
/**
 * Costante utilizzata per indicare il valore massimo che puo'assumere la enum livello
 */
#define MAX_COMPLESSITA 2
/**
 * Costante utilizzata per indicare la quantitÃ  di tempo massima (espressa in minuti)
 * per la preparazione di una ricetta
 */
#define MAX_TEMPO_PREPARAZIONE 360
/**
 * Costante utilizzata per indicare la lunghezza massima
 * che possono avere i nomi (es nome ricetta) in questo programma
 */
#define LUNGHEZZA_NOME 41
/**
 * Costante utilizzata per indicare il
 * numero massimo di ingredienti presenti in una ricetta
 */
#define NUMERO_INGREDIENTI 30
/**
 * Costante utilizzata per indicare il numero massimo di utenti registrati al sistema
 */
#define NUMERO_UTENTI 20
/**
 * Costante utilizzata per indicare la lunghezza massima che puo'assumere una
 * stringa contenente un link al procedimento della ricetta
 */
#define MAX_LUNGHEZZA_LINK 27
/**
 * Costante utilizzata per indicare la lunghezza minima che puo'assumere una
 * stringa contenente un link al procedimento della ricetta
 */
#define MIN_LUNGHEZZA_LINK 16
/**
 * Costante utilizzata per indicare la lunghezza massima della stringa
 * che indica la quantitÃ  di un alimento
 */
#define LUNGHEZZA_QUANTITA  5
/**
 * Costante utilizzata per indicare la lunghezza massima che possono
 * avere i nomi dei file (es elenco_ricette.bin) in questo programma
 */
#define LUNGHEZZA_NOME_FILE 25
/**
 * Costante utilizzata per indicare il numero delle voci del menu' principale del sistema
 */
#define NUMERO_VOCI_MENU 21
/**
 * Costante utilizzata per indicare la massima lunghezza della stringa acquisita in input
 */
#define LUNGHEZZA_INPUT 12
/**
 * Costante utilizzata per indicare il numero massimo di
 * pasti giornalieri per singolo utente
 */
#define MAX_NUMERO_PASTI 10
/**
 * Costante utilizzata per indicare la massima lunghezza
 * che puo'avere la risposta alla domande poste all'utente
 */
#define LUNGHEZZA_RISPOSTA 5
/**
 * Costante utilizzata per indicare la lunghezza
 * minima della stringa contenente il nome utente
 */
#define MIN_LUNGHEZZA_USERNAME 5
/**
 * Costante utilizzata per indicare la lunghezza massima
 * della stringa contenente il nome utente
 */
#define MAX_LUNGHEZZA_USERNAME 15
/**
 * Costante utilizzata per indicare il numero massimo di alimenti presenti in frigorifero
 */
#define NUMERO_ALIMENTI 200
/**
 * Costante utilizzata per indicare il numero massimo
 * di ricette che il ricettario puo'contenere
 */
#define NUMERO_RICETTE 50
/**
 * Costante utilizzata per indicare il numero massimo di menu giornalieri degli utenti
 */
#define NUMERO_MENU_GIORNALIERI 140
/**
 * Costante utilizzata per indicare il numero di giorni in una settimana
 */
#define NUMERO_GIORNI_SETTIMANA 7
/**
 * Costante utilizzata per indicare la lunghezza massima
 * della stringa che indica il giorno delle settimana
 */
#define LUNGHEZZA_GIORNO_SETTIMANA 10

/**
 * Costante utilizzata per indicare la lunghezza del link di base (https://bit.ly/)
 */
#define LINK_BASE 15
/**
 * Costante utilizzata per indicare l'anno massimo in cui si considera una data valida
 */
#define MAX_ANNO 2030
/**
 * Costante utilizzata per indicare l'anno minimo in cui si considera una data valida
 */
#define MIN_ANNO 1990
/**
 * Costante utilizzata per indicare il numero massimo del mese in un anno
 */
#define MAX_MESE 12
/**
 * Costante utilizzata per indicare il numero minimo del mese in un anno
 */
#define MIN_MESE 1
/**
 * Costante utilizzata per indicare il numero massimo del giorno in un mese
 */
#define MAX_GIORNO 31
/**
 * Costante utilizzata per indicare il numero minimo del giorno in un mese
 */
#define MIN_GIORNO 1
/**
 * Costante utilizzata per indicare ogni quanto febbraio e' bisestile
 */
#define BISESTILE 4
/**
 * Costante utilizzata per indicare il numero di giorni
 * di febbraio nel caso in cui e' bisestile
 */
#define GIORNI_FEBBRAIO 29
/**
 * Costante utilizzata per indicare la lunghezza minima
 * che puo'assumere una stringa contenente una data
 */
#define MIN_LUNGHEZZA_DATA 8
/**
 * Costante utilizzata per indicare la lunghezza massima
 * che puo'assumere una stringa contenente una data
 */
#define MAX_LUNGHEZZA_DATA 10
/**
 * Costante utilizzata per indicare il numero massimo di alimenti in esaurimento
 */
#define NUMERO_ELEMENTI_ESAURIMENTO 200
/**
 * Costante utilizzata per indicare il numero massimo di alimenti in scadenza
 */
#define NUMERO_ELEMENTI_SCADENZA 200
/**
 * Costante utilizzata per indicare il valore booleano "true" per
 * quanto riguarda la stampa degli alimenti rimessi in frigorifero
 */
#define STAMPA_ALIMENTI_RIMESSI 1
/**
 * Costante utilizzata per indicare il valore booleano "false" per
 * quanto riguarda la stampa degli alimenti rimessi in frigorifero
 */
#define NON_STAMPA_ALIMENTI_RIMESSI 0
/**
 * Costante utilizzata per indicare il valore booleano "false" per quanto
 * riguarda la stampa degli alimenti usati per la preparazione di una ricetta
 */
#define STAMPA_ALIMENTI_USATI 1
/**
 * Costante utilizzata per indicare il valore booleano "false" per quanto riguarda
 * la stampa degli alimenti usati per la preparazione di una ricetta
 */
#define NON_STAMPA_ALIMENTI_USATI 0
/**
 * Costante utilizzata per indicare il numero per cui se la quantita'  di un
 * alimento e' <= di questa soglia si considera l'alimento in esaurimento
 */
#define SOGLIA_ESAURIMENTO 2
/**
 * Costante utilizzata per indicare il numero di giorni prima della data di scadenza,
 * per cui se la data di scadenza e' tra due giorni l'alimento verra'  notificato tra gli
 * alimenti in scadenza
 */
#define SOGLIA_SCADENZA 2

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


enum livello {BASSA, MEDIA, ALTA};

/**
 * Struct utilizzata per la rappresentazione della data
 */
typedef struct {
	/**
	 * valore che indica il giorno
	 */
	unsigned short int giorno;
	/**
	 * valore che indica il mese
	 */
	unsigned short int mese;
	/**
	 * valore che indica l'anno
	 */
	unsigned short int anno;
	/**
	 * stringa che indica il giorno della settimana
	 */
	char giorno_settimana[LUNGHEZZA_GIORNO_SETTIMANA];
}data;



/**
 * Struct utilizzata per rappresentare l'utente
 */
typedef struct {
	/**
	 * campo ID identificativo ed univoco
	 */
	unsigned short int id_utente;
	/**
	 * nome o nickname dell'utente
	 */
	char nome[LUNGHEZZA_NOME];
}utente;



/**
 * Struct utilizzata per rappresentare gli ingredienti
 */
typedef struct {
	/**
	 * indica il nome dell'alimento
	 */
	char nome_alimento[LUNGHEZZA_NOME];
	/**
	 * valore che indica la quantita' dell'alimento
	 */
	char quantita[LUNGHEZZA_QUANTITA];
	/**
	 * campo che indica l'unita' di misura dell'alimento che puo' essere espressa in grammi oppure puo' non essere presente
	 */
	char unita_misura;
}ingrediente;



/**
 * Struct utilizzata per rappresentare la ricetta
 */
typedef struct {
	/**
	 * campo ID identificativo ed univoco
	 */
	unsigned short int id_ricetta;
	/**
	 * campo che indica il nome delle ricetta
	 */
	char nome_ricetta[LUNGHEZZA_NOME];
	/**
	 * vettore di tipo ::ingrediente che contiene tutti gli ingredienti della ricetta
	 */
	ingrediente ingredienti[NUMERO_INGREDIENTI];
	/**
	 * campo che indica il numero degli ingredienti della ricetta
	 */
	unsigned short int numero_ingredienti;
	/**
	 * campo che indica il tempo di preparazione della ricetta (espresso in minuti)
	 */
	unsigned short int tempo_preparazione;
	/**
	 * stringa che indica il link al procedimento della ricetta
	 */
	char link_procedimento[MAX_LUNGHEZZA_LINK];
	/**
	 * campo che indica la complessita' della ricetta
	 */
	enum livello complessita;
	/**
	 * campo che indica le kcal sprigionate dalla ricetta
	 */
	float kcal;
	/**
	 * campo che indica per quante persone solo le dosi di questa ricetta
	 */
	unsigned short int n_persone;
}ricetta;


/**
 * Struct che rappresenta gli alimenti presenti in frigorifero
 */
typedef struct {
	/**
	 * campo ID identificativo ed univoco
	 */
	unsigned short int id_alimento;
	/**
	 * Stringa che indica il nome dell'alimento
	 */
	char nome_alimento[LUNGHEZZA_NOME];
	/**
	 * campo di tipo ::data che indica la data di scadenza dell'alimento
	 */
	data data_scadenza;
	/**
	 * campo che indica il numero di pezzi presenti
	 */
	short int numero_pezzi;
	/**
	 * campo che indica il peso per ogni singola unita' presente
	 */
	float peso_unitario;
}alimento;


/**
 * Struct utilizzata per rappresentare un pasto
 */
typedef struct {
	/**
	 * campo ID identificativo ed univoco della ricetta consumata
	 */
	unsigned short int id_ricetta;
	/**
	 * campo che indica per quante persone e' stato cucinato questa ricetta
	 */
	unsigned short int n_persone;
}pasto;


/**
 * Struct usata per rappresentare il menu giornaliero
 */
typedef struct {
	/**
	 * campo ID identificativo ed univoco del menu'
	 */
	unsigned short int id_menu;
	/**
	 * campo ID identificativo ed univoco dell'utente colegato al menu'
	 */
	unsigned short int id_utente;
	/**
	 * campo di tipo ::data che rappresenta la data del menu' giornaliero
	 */
	data data_menu;
	/**
	 * vettore di tipo ::pasto che rappresenta tutti i pasti consumati
	 */
	pasto pasti[MAX_NUMERO_PASTI];
	/**
	 * campo che indica il numero dei pasti presenti nel menu'
	 */
	unsigned short int numero_pasti;
	/**
	 * campo che indica le kcal giornaliere del menu'
	 */
	float kcal_giornaliere;
}menu_giornaliero;



#endif /* STRUTTURE_DATI_H_ */
