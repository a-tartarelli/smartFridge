/**
* @file elaborazione_ricette.h
*
* Questo file contiene tutte le funzioni che consentono di interagire con le ricette, dall' aggiunta di una nuova ricetta alla sua eliminazione o modifica.
* Inoltre ci sono varie funzioni per l'acquisizione di dati sempre inerenti alle ricette, funzioni per la loro scrittura su file, funzioni di ricerca e
* di ordinamento delle ricette.
*
* @version 1.0
* @date 03/06/2018
* @authors Giuseppe Murro, Alessio Tartarelli
*/



#ifndef SRC_ELABORAZIONE_RICETTE_H_
#define SRC_ELABORAZIONE_RICETTE_H_

#include "strutture_dati.h"

#endif /* SRC_ELABORAZIONE_RICETTE_H_ */



/**
 * Questa funzione di occupa di prendere in input gli ingredienti di una nuova ricetta che poi verra' aggiunta al ricettario.
 * I valori inseriti sono controllati per evitare l'inserimento di valori errati o non conformi con quelli attesi.
 *
 * @param[in] numero_ingrdiente indica quanti sono gli ingredienti della ricetta
 * @return il valore di ritorno e' una strcut di tipo ::ingrediente
 */
ingrediente input_ingredienti( unsigned short int numero_ingrdiente );



/**
 * Questa funzione si occupa di prendere in input tutti i dati relativi a una nuova ::ricetta. Ovvero il nome delle ricetta, gli ingredienti,
 * il tempo di preparazione, la complessita', il link al procedimento, per quante persone e' la ricetta e le kcal prigionate dal piatto.
 *
 * @param[in] nome_file indica il nome del file che verra' passato ad un'altra funzione per la scrittura dei dati sul file
 * @param[in] ricettario indica il puntatore alla zona di memoria contenente le ricette
 * @param[in] numero_ricette indica il numero delle ricette presenti in memoria
 */
void input_aggiungi_ricetta (char* nome_file, ricetta* ricettario, unsigned short int numero_ricette );



/**
 * Questa funzione si occupa di scrivere sul file una struct di tipo ::ricetta
 * @param[in] nome_file indica il nome del file su cui verranno memorizzati i dati
 * @param[in] ricetta_nuova indica la ::ricetta da memorizzare
 * @return 1 se la scrittura e' andata a buon fine
 * @return 0 se la scrittura e' fallita
 *
 */
unsigned short int aggiungi_ricetta ( char* nome_file, ricetta ricetta_nuova );



/**
 * Questa funzione visualizza a video con una formattazione tabellare tutte le ricette presenti nel ricettario, solo se il campo id
 * della struct ::ricetta e' maggiore di 0.
 *
 * @param[in] ricettario vettore di tipo ::ricetta contenente tutti i dati delle ricette
 * @param[in] numero_ricette lunghezza del vettore
 * @return il numero degli elementi stampati
 */
unsigned short int apri_ricettario(const ricetta ricettario[], unsigned short int numero_ricette);



/**
 * Questa funzione legge il vettore di ricette passato come primo parametro e restituisce
 * un intero che rappresenta un nuovo id diverso da tutti gli altri.
 *
 * @param[in] ricettario vettore di tipo ::ricetta
 * @param[in] numero_ricette lunghezza del vettore
 * @return valore che rappresenta un nuovo id valido
 */
unsigned short int get_ultimo_id_ricetta (const ricetta* ricettario, unsigned short int numero_ricette);



/**
 * Questa funzione legge il vettore di ricette passato come primo parametro e restituisce
 * un intero che rappresenta l'ultimo indice valido, cioe' l'ultimo elemento che ha un id > 0.
 *
 * @param[in] ricettario
 * @param[in] numero_ricette
 * @return valore che rappresenta l'ultimo indice contenete una ricetta valida
 */
unsigned short int get_ultimo_indice_ricetta (const ricetta* ricettario, unsigned short int numero_ricette);



/**
 * Funzione che si occupa di applicare le modifiche effettuate attraverso la funzione input_modifica_ricetta(). Per applicare le modifiche
 * riscrive sul file la ricetta nella posizione della ricetta che è stata modificata.
 *
 * @param[in] nome_file indica il nome del file su cui si andra' a riscrivere la ricetta
 * @param[in] ricetta ::ricetta che si andra' a sostituire alla precedente
 * @return 1 in caso di modifica con successo
 * @return 0 in caso di modifica fallita
 */
unsigned short int modifica_ricetta (char* nome_file, ricetta ricetta);



/**
 * Procedura che si occupa di acquisire i dati in input dall'utente per la modifica dei campi della ::ricetta
 *
 * @param[in] nome_file indica il nome del file su cui poi andranno scritte le modifiche effettuate
 * @param[in] ricettario vettore di tipo ::ricetta
 * @param[in] numero_ricette lunghezza del vettore
 */
void input_modifica_ricetta (char* nome_file, ricetta* ricettario, unsigned short int numero_ricette);



/**
 * Funzione che confronta il parametro id_ricetta con gli id della struct ::ricetta
 *
 * @param[in] ricettario vettore di ::ricetta
 * @param[in] numero_ricette lunghezza del vettore
 * @param[in] id_ricetta valore da confrontare
 * @return restituisce il valore dell'indice se uguale al parametro id_ricetta
 */
unsigned short int indice_id_ricetta (const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int id_ricetta);


/**
 * Funzione che verifica la presenza di una ricetta nel ricettario.
 *
 * @param[in] ricettario vettore di tipo ::ricetta
 * @param[in] numero_ricette lunghezza del vettore
 * @param[in] id_ricetta
 * @return 1 se la ricetta e' presente
 * @return 0 se la ricetta non e' presente
 */
unsigned short int is_ricetta_esistente(const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int id_ricetta);


/**
 * Procedura per l'acquisizione dall'utente dei dati per la modifica di un ingrediente di una ricetta. E' possibile modificare la quantita'
 * e il nome dell'ingrediente.
 *
 * @param[in] ricetta_da_modificare ::ricetta di cui si vogliono modifcare gli ingredienti
 * @param[in] numero_ingredienti numero degli ingredienti presenti nella ::ricetta
 */
void input_modifica_ingredienti(ricetta* ricetta_da_modificare, unsigned short int numero_ingredienti);


/**
 * Procedura per l'acquisizione da parte dell'utente dei dati (id) relativi alla ricetta che si vuole cancellare
 *
 * @param[in] ricettario vettore di tipo ::ricetta
 * @param[in] numero_ricette lunghezza del vettore di tipo ::ricetta
 */
void input_cancella_ricetta(ricetta* ricettario, unsigned short int numero_ricette);


/**
 * Funzione per la cancellazione effettiva su file della ::ricetta.
 *
 * @param[in] nome_file nome del file su cui sono memorizzate le ricette
 * @param[in] id_ricetta id della ::ricetta da cancellare
 * @return 1 se la cancellazione e' avvenuta con successo
 * @return 0 se la cancellazione non e' andata a buon fine
*/
unsigned short int cancella_ricetta (char* nome_file, unsigned short int id_ricetta);


/**
 * Funzione per la scelta delle ricerca da effettuare. (Es. 1 ricerca per ID)
 *
 * @return valore che identifica il tipo di ricerca da effettuare
 */
unsigned short int input_ricerca_ricetta();

/**
 * Funzione per l'acquisizione dell'ID della ricetta da ricercare.
 *
 * @return il valore dell'ID acquisito
 */
unsigned short int input_inserisci_id();


/**
 * Procedura per la visualizzazione della ricetta con un formato tabellare
 * @param[in] ricetta la ::ricetta da visualizzare
 */
void visualizza_ricetta(ricetta ricetta);


/**
 * Procedura per l'acquisizione del nome di un alimento
 *
 * @param[in] nome_alimento
 */
void input_alimento(char* nome_alimento);


/**
 * Funzione per la ricerca di una ricetta contenente un dato alimento passato come parametro.
 *
 * @param[in] ricettario vettore di tipo ::ricetta contenente le varie ricette
 * @param[in] numero_ricette lunghezza del vettore di ricette
 * @param[in] alimento alimento che dovra' essere presente nella ricetta
 * @return 1 se c'e' almeno una ricetta contenente il dato alimento
 * @return 0 se non ci sono ricette con quel alimento
 */
unsigned short int ricerca_ricetta_alimento(ricetta* ricettario, unsigned short int numero_ricette, char alimento[]);


/**
 * Funzione per l'acquisizione del numero di alimenti da ricercare
 *
 * @return il valore che rappresenta il numero di alimenti da ricercare
 */
unsigned short int input_numero_alimenti();


/**
 * Funzione per la ricerca di una ricetta che contine un insieme di alimenti
 *
 *
 * @param[in] insieme_alimenti matrice contenente l'insime degli alimenti da ricercare
 * @param[in] numero_alimenti numero degli alimenti da ricercare
 * @param[in] ricettario vettore di tipo ::ricetta
 * @param[in] numero_ricette lunghezza del vettore di tipo ::ricetta
 * @return
 */
unsigned short int cerca_ricetta_insieme(char insieme_alimenti[][LUNGHEZZA_NOME], unsigned short int numero_alimenti, ricetta* ricettario, unsigned short int numero_ricette);


/**
 * Procedura per lo scambio di due ricette
 *
 * @param[in] a puntatore di tipo ricetta da scambiare con b
 * @param[in] b puntatore di tipo ricetta da scambiare da a
 */
void swap_ricette(ricetta* a, ricetta* b);


/**
 * Funzione per il partizionamento del vettore di tipo ::ricetta in due parti
 *
 * @param[in] ricettario vettore di tipo ::ricetta
 * @param[in] l indica l'inizio del vettore
 * @param[in] r indica la fine del vettore
 */
int partition (ricetta* ricettario, int l, int r);


/**
 * Funzione per l'ordinamento delle ricette in base alla kcal, sfrutta l'algoritmo di ordinamento "quicksort"
 *
 * @param[in] ricettario
 * @param[in] l inizio del vettore di tipo ::ricetta
 * @param[in] r fine del vettore di tipo ::ricetta
 */
void quickSort(ricetta* ricettario, int l, int r);


/**
 * Funzione per effettuare la ricerca di una o piu' ricette in base a una soglia di kcal passata come parametro. Se le kcal della
 * ricetta sono <= del parametro "kcal_da_cercare" allora la ricetta sara' visualizzata in formato tabellare
 *
 * @param ricettario vettore di tipo ::ricetta
 * @param numero_ricette lunghezza del vettore contenente le ricette
 * @param kcal_da_cercare soglia di kcal
 * @param is_ordinato e' un valore sentinella che indica se il vettore di ricette e' ordinato in modo crescente in base alla kcal (is_ordinato = 1)
 * @return 1 se c'e' almeno una ricetta con kcal <= del parametro "kcal_da_cercare"
 * @return 0 se ci sono ricette idonee
 */
unsigned short int ricerca_ricetta_kcal(ricetta* ricettario, unsigned short int numero_ricette, float kcal_da_cercare, unsigned short int is_ordinato);


/**
 * Funzione per effettuare la copia del vettore di ::ricetta per evitare che venga poi utlizzato ordinato da altre funzioni in cui non e'
 * neccessario che lo sia
 *
 * @param ricettario vettore di tipo ::ricetta
 * @param numero_elementi lunghezza del vettore
 * @return puntatore di tipo ::ricetta alla prima locazione di memoria del vettore di ricette copiato
 */
ricetta* copia_ricettario(ricetta* ricettario, unsigned short int numero_elementi);
