/**
* @file controlli.h
*
* Questo file contiene tutte le funzioni che consentono di acquisire in modo corretto interi, numeri decimali,
* stringhe con e senza spazio e date e funzioni che effettuano controlli su una stringa in input per verificare se e' effettivamente
* un intero, un numero decimale, o una stringa valida o una data corretta.
* Queste funzioni vengono usate principalmente per acquisisre dati da tastiera in modo corretto e
* svolgono lo stesso ruolo della scanf o della fgets implementando controlli sull'input.
*
* @version 1.0
* @date 02/06/2018
* @authors Giuseppe Murro, Alessio Tartarelli
*/



#ifndef CONTROLLI_H_
#define CONTROLLI_H_

#include "strutture_dati.h"

#endif /* CONTROLLI_H_ */



/**
* Questa funzione stampa il messaggio passato come primo parametro, e si mette in attesa finche' non viene inserito un input da tastiera,
* la cui lunghezza massima e' indicata dal secondo paramentro. Se l'input non e' un intero, viene chiesto di reinserire un nuovo valore.
* Altrimenti se l'input e' effettivamente un intero, verra' restituito come valore di ritorno.
* es. "13" OK;
* 	  "12ab"  NO;
* 	  "14,6" NO;
*
* @param[in] messaggio: Vettore di caratteri che rappresenta il messaggio che verra' stampato prima di acquisire l'input (es. Inserisci eta':)
* @param[in] lunghezza_input: Valore intero riguardante il numero massimo di caratteri che vengono acquisiti in input.
* 							  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return short int: Valore intero corretto che e' stato acquisito da tastiera
*/

short int inserisci_input_intero (char messaggio[],  unsigned short int lunghezza_input);





/**
* Questa funzione stampa il messaggio passato come primo parametro, e si mette in attesa finche' non viene inserito un input da tastiera,
* la cui lunghezza massima e' indicata dal secondo paramentro. Se l'input non una stringa di sole lettere, viene chiesto di reinserire una nuova stringa.
* Altrimenti se l'input e' effettivamente una stringa di sole lettere, il puntatore ad essa verra' restituito come valore di ritorno.
* es. "Latte" OK;
* 	  "12ab"  NO;
* 	  "Pasta al forno" NO;
*
* @param[in] messaggio: Vettore di caratteri che rappresenta il messaggio che verra' stampato prima di acquisire l'input (es. Inserisci nome:)
* @param[in] lunghezza_input: Valore intero riguardante il numero massimo di caratteri che vengono acquisiti in input.
* 							  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return char*: Puntatore alla stringa che e' stata acquisita da tastiera
*/

char* inserisci_input_caratteri (char messaggio[], unsigned short int lunghezza_input);





/**
* Questa funzione stampa il messaggio passato come primo parametro, e si mette in attesa finche' non viene inserito un input da tastiera,
* la cui lunghezza massima e' indicata dal secondo paramentro. Se l'input non una stringa di sole lettere (compreso lo spazio), viene chiesto di reinserire una nuova stringa.
* Altrimenti se l'input e' effettivamente una stringa di sole lettere (compreso lo spazio), il puntatore ad essa verra' restituito come valore di ritorno.
* es. "Latte" OK;
* 	  "Pasta al forno" OK;
* 	  "12abc"  NO;
*
* @param[in] messaggio: Vettore di caratteri che rappresenta il messaggio che verra' stampato prima di acquisire l'input (es. Inserisci cognome:)
* @param[in] lunghezza_input: Valore intero riguardante il numero massimo di caratteri che vengono acquisiti in input.
* 							  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return char*: Puntatore alla stringa che e' stata acquisita da tastiera
*/

char* inserisci_input_caratteri_spazio (char messaggio[], unsigned short int lunghezza_input);





/**
* Questa funzione stampa il messaggio passato come primo parametro, e si mette in attesa finche' non viene inserito un input da tastiera,
* la cui lunghezza massima e' indicata dal secondo paramentro. Se l'input non e' un numero decimale, viene chiesto di reinserire un nuovo valore.
* Altrimenti se l'input e' effettivamente numero decimale, verra' restituito come valore di ritorno.
* es. "1.2" OK;
* 	  "104" OK;
* 	  "13,4"  NO;
* 	  "13.asnhad"  NO;
*
* @param[in] messaggio: Vettore di caratteri che rappresenta il messaggio che verra' stampato prima di acquisire l'input (es. Inserisci cognome:)
* @param[in] lunghezza_input: Valore intero riguardante il numero massimo di caratteri che vengono acquisiti in input.
* 							  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return float: Valore decimale corretto che e' stato acquisito da tastiera
*/

float inserisci_input_float (char messaggio[], unsigned short int lunghezza_input);





/**
* Questa funzione stampa il messaggio passato come primo parametro, e si mette in attesa finche' non viene inserito un input da tastiera,
* la cui lunghezza massima e' indicata dal secondo paramentro. Se l'input non e' un numero decimale o e' diverso da "qb", viene chiesto di reinserire un nuovo valore.
* Altrimenti se l'input e' effettivamente numero decimale o "qb", verra' restituito il puntatore all'input acquisito sottoforma di stringa.
* es. "1.2" OK;
* 	  "qb" OK;
* 	  "13,4"  NO;
* 	  "qbsnsb"  NO;
*
* @param[in] messaggio: Vettore di caratteri che rappresenta il messaggio che verra' stampato prima di acquisire l'input (es. Inserisci cognome:)
* @param[in] lunghezza_input: Valore intero riguardante il numero massimo di caratteri che vengono acquisiti in input.
* 							  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return char*: Puntatore alla stringa che e' stata acquisita da tastiera
*/

char* inserisci_input_float_qb (char messaggio[], unsigned short int lunghezza_input);





/**
* Questa funzione stampa il messaggio passato come primo parametro, e si mette in attesa finche' non viene inserito un input da tastiera,
* la cui lunghezza massima e' indicata dal secondo paramentro. Se l'input non e' una data nel formato corretto, viene chiesto di reinserire un nuovo valore.
* Altrimenti se l'input rappresenta effettivamente una data (nel formato gg/mm/aa), verra' restituito un dato di tipo 'data' che contiene la data inserita in input.
* es. "12/9/2018" OK;
* 	  "30/2/2018" NO;
* 	  "13"  NO;
* 	  "g/m/a"  NO;
*
* @param[in] messaggio: Vettore di caratteri che rappresenta il messaggio che verra' stampato prima di acquisire l'input (es. Inserisci cognome:)
* @param[in] lunghezza_input: Valore intero riguardante il numero massimo di caratteri che vengono acquisiti in input.
* 							  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return data: Variabile che contiene nei propri membri il giorno, il mese e la data inseriti in input
*/

data inserisci_input_data (char messaggio[], unsigned short int lunghezza_input);





/**
* Questa funzione stampa il messaggio passato come primo parametro, e si mette in attesa finche' non viene inserito un input da tastiera,
* la cui lunghezza massima e' indicata dal secondo paramentro. Se l'input non e' un link valido, viene chiesto di reinserire una nuova stringa.
* Altrimenti se l'input e' effettivamente un link valido (deve iniziare con https://bit.ly/), il puntatore a tale stringa verra' restituito come valore di ritorno.
* es. "https://bit.ly/snhad87sb" OK;
* 	  "https://google.com" NO;
* 	  "facebook.com"  NO;
*
* @param[in] messaggio: Vettore di caratteri che rappresenta il messaggio che verra' stampato prima di acquisire l'input (es. Inserisci cognome:)
* @param[in] lunghezza_input: Valore intero riguardante il numero massimo di caratteri che vengono acquisiti in input.
* 							  Il tipo e' unsigned short int proprio perche' non puo' essere un valore negativo.
* @return char*: Puntatore alla stringa che e' stata acquisita da tastiera
*/

char* inserisci_input_link (char messaggio[], unsigned short int lunghezza_input);





/**
* Questa e' una funzione boolena che verifica se la stringa passata come paramentro rappresenta effettivamente un numero intero.
* Se lo e', la funzione restituisce 1.
* Altrimenti restituisce 0.
* es. "133" --> 1;
* 	  "13.4" --> 0;
* 	  "dieci" -->  0;
*
* @param[in] input: Vettore di caratteri sul quale viene effettuato il controllo se e' un intero o meno (es. 111)
* @return unsigned short int: Valore booleano che puo' essere 0 o 1
*/

unsigned short int is_intero (char input[]);


/**
* Questa e' una funzione boolena che verifica se la stringa passata come paramentro e' formata da sole lettere.
* Se lo e', la funzione restituisce 1.
* Altrimenti restituisce 0.
* es. "ciao" --> 1;
* 	  "hello word" --> 0;
* 	  "abc123" -->  0;
*
* @param[in] stringa: Vettore di caratteri sul quale viene effettuato il controllo se e' formato da sole lettere
* @return unsigned short int: Valore booleano che puo' essere 0 o 1
*/

unsigned short int is_stringa_caratteri (char stringa[]);





/**
* Questa e' una funzione boolena che verifica se la stringa passata come paramentro e' formata da sole lettere (compreso lo spazio).
* Se lo e', la funzione restituisce 1.
* Altrimenti restituisce 0.
* es. "ciao" --> 1;
* 	  "hello word" --> 1;
* 	  "abc123" -->  0;
*
* @param[in] stringa: Vettore di caratteri sul quale viene effettuato il controllo se e' formato da sole lettere (compreso lo spazio).
* @return unsigned short int: Valore booleano che puo' essere 0 o 1
*/

unsigned short int is_stringa_caratteri_spazio (char stringa[]);





/**
* Questa e' una funzione boolena che verifica se la stringa passata come paramentro rappresenta effettivamente un numero decimale.
* Se lo e', la funzione restituisce 1.
* Altrimenti restituisce 0.
* es. "12.4" --> 1;
* 	  "12,5" --> 0;
* 	  "abc123" -->  0;
*
* @param[in] input: Vettore di caratteri sul quale viene effettuato il controllo se un numero decimale o meno.
* @return unsigned short int: Valore booleano che puo' essere 0 o 1
*/

unsigned short int is_float (char input[]);





/**
* Questa e' una funzione boolena che verifica se la variabile di tipo 'data' rappresenta una data corretta.
* Se lo e', la funzione restituisce 1.
* Altrimenti restituisce 0.
* es. g: 23, m: 3, a: 2018  --> 1;
* 	  g: 31, m: 2, a: 2018  --> 0;
*
* @param[in] data_input: Parametro di tipo 'data' sul quale viene effettuato il controllo per verificare se e' una data corretta o meno.
* @return unsigned short int: Valore booleano che puo' essere 0 o 1
*/

unsigned short int is_data_corretta( data data_input );





/**
* Questa e' una funzione boolena che verifica se la stringa passata come paramentro e' e' effettivamente un link valido (deve iniziare con https://bit.ly/).
* Se lo e', la funzione restituisce 1.
* Altrimenti restituisce 0.
* es. "https://bit.ly/ad8scs" --> 1;
* 	  "https://google.com" --> 0;
* 	  "abc123" -->  0;
*
* @param[in] stringa: Vettore di caratteri sul quale viene effettuato il controllo se e' un link valido
* @return unsigned short int: Valore booleano che puo' essere 0 o 1
*/

unsigned short int is_link (char stringa[]);





/**
* Questa e' una funzione booleana che risolve i bug riguardanti l'overfl dello stdin.
* Riceve come parametro un vettore di caratteri in base al quale
<<<<<<< HEAD
* se il buffer di input non e' sovraccaricato restituira'ï¿½1;
* altrimenti restituirï¿½ 0.
=======
* se il buffer di input non e' sovraccaricato restituira' 1;
* altrimenti restituira'  0.
>>>>>>> branch 'master' of https://Alss@bitbucket.org/Alss/windows_caso_studio.git
*
* @param[in] input: Vettore di caratteri sul quale viene effettuato il controllo
* @return unsigned short int: Valore booleano che puo' essere 0 o 1
*/

unsigned short int svuota_buffer_input (char* input) ;




/**
* Questa procedura che prende in input una stringa e la sua lunghezza
* e modifica la stringa rendendola vuota.
* es. "abcd" --> "";
*
* @param[in] s: Vettore di caratteri che deve essere pulito
* @param[in] lunghezza: Valore intero che rappresenta la lunghezza della stringa
*/

void pulisci_stringa (char s[], unsigned short int lunghezza);





/**
* Questa funzione riceve come paramentro una stringa che rappresenta una data nel formato (gg/mm/aaaa)
* e ne ricava il giorno, il mese e l'anno, assegnandoli ai campi di una variabile di tipo data, la quale
<<<<<<< HEAD
* verrï¿½ restituita come valore di ritorno.
=======
* verra' restituita come valore di ritorno.
>>>>>>> branch 'master' of https://Alss@bitbucket.org/Alss/windows_caso_studio.git
* es. "23/6/2018" --> g:23, m:6, a:2018;
*
* @param[in] data_input: Vettore di caratteri che rappresenta una data nel formato (gg/mm/aaaa)
* @return data: Variabile di tipo data nella quale viene "convertita" la stringa in input
*/

data split_data (char* data_input);





/**
* Questa e' una funzione booleana che verifica se il terzo parametro e' un intero strettamente
* compreso tra il primo e il secondo paramentro.
* Se e' compreso, la funzione restituisce 1,
* altrimenti restituisce 0.
*
* @param[in] min: Valore intero minimo dell'intervallo su cui effettuare il confronto
* @param[in] max: Valore intero massimo dell'intervallo su cui effettuare il confronto
* @param[in] numero: Valore intero da verificare se appartiene all'intevallo
* @return unsigned short int: Valore booleano che puo' essere 0 o 1
*/

unsigned short int is_compreso_tra (short int min, short int max, short int numero);





/**
* Questa e' una funzione booleana che verifica se il terzo parametro e' un decimale strettamente
* compreso tra il primo e il secondo paramentro.
* Se e' compreso, la funzione restituisce 1,
* altrimenti restituisce 0.
*
* @param[in] min: Valore decimale minimo dell'intervallo su cui effettuare il confronto
* @param[in] max: Valore decimale massimo dell'intervallo su cui effettuare il confronto
* @param[in] numero: Valore decimale da verificare se appartiene all'intevallo
* @return unsigned short int: Valore booleano che puo' essere 0 o 1
*/
unsigned short int is_compreso_tra_float (float min, float max, float numero);

