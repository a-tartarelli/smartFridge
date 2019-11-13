/**
* @file gestione_menu_settimanale.h
*
* Questo file contiene tutte le funzioni necessarie per gestire il menu settimanale di ciascun utente, come ad
* esempio l'aggiunta di un nuovo menu, la modifica, la cancellazione, la stampa di tutti i menu giornalieri, ecc.
* La maggior parte delle funzioni lavorano su vettori di tipo menu_giornaliero, che vengono passati per riferimento e quindi potranno essere modificati dalle funzioni,
* a meno che non sia indicato il qualificatore const.
* I campi della struct menu_giornaliero su cui le funzioni lavorano sono : id del menu e dell'utente, il giorno della settimana, i pasti, il numero di pasti e le kcal totali.
*
* @version 1.0
* @date 04/06/2018
* @authors Giuseppe Murro, Alessio Tartarelli
*/

#ifndef SRC_GESTIONE_MENU_SETTIMANALE_H_
#define SRC_GESTIONE_MENU_SETTIMANALE_H_

#include "strutture_dati.h"
#include "elaborazione_ricette.h"
#include "elaborazione_alimenti.h"
#include "date.h"
#include "gestione_utenti.h"

#endif /* SRC_GESTIONE_MENU_SETTIMANALE_H_ */


/**
* Questa funzione prende in input un vettore di tipo 'menu_giornaliero', che non puo' essere modificato, e la sua lunghezza
* e stampa sottoforma tabellare tutti i campi degli elementi scritti nel vettore con un id menu valido (>0) che si riferiscono all'utente che ha come id l'intero passato come quarto parametro.
* La funzione restituisce il numero di elementi stampati.
*
* @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che puo' essere unicamente letto
* @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @param ricettario: Vettore di tipo 'ricetta' dal quale vengono stampati i pasti
* @param id_utente: Intero che rappresenta l'id dell'utente per il quale deve essere visualizzato il menu settimanale
* @return unsigned short int: Intero positivo che rappresenta il numero di elementi stampati
*/

unsigned short int visualizza_menu_settimanale (const menu_giornaliero menu_settimanale[], unsigned short int numero_menu_giornalieri, const ricetta* ricettario, unsigned short int id_utente);





/**
* Questa procedura consente di acquire da tastiera quale ricetta preparare e per quante persone e controlla se sono corretti e se la ricetta e' preparabile.
* In tal caso gli alimenti consumati andranno a modificare il vettore di alimenti passato come sesto parametro e verra'
* aggiunto un nuovo menu giornaliero nel giorno passato come ultimo parametro sia sul vettore passato come secodno paramtreo e sia
* sul file il cui nome e' stato passato come primo parametro.
*
* @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui aggiungere il menu settimanale
* @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che puo' essere unicamente letto
* @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore menu_settimanale
* @param ricettario: Vettore di tipo 'ricetta' dal quale vengono presi i dati sui pasti
* @param numero_ricette: Intero che rappresenta il numero di elementi da cui e' composto il vettore ricettario
* @param alimenti_frigo: Vettore di tipo 'alimento' dal quale viene verificata la disponibilita' degli ingredienti
* @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore alimenti_frigo
* @param id_utente: Intero che rappresenta l'utente per il quale deve essere preparato un pasto
* @param data_odierna: Varibile di tipo 'data' che indica il giorno in cui deve essere aggiunto il menu giornaliero
*/

void input_prepara_ricetta (char* nome_file, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, const ricetta ricettario[], unsigned short int numero_ricette, alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int id_utente, data data_odierna);





/**
* Questa funzione scrive il menu giornaliero (passato come secondo parametro) sul file
* il cui nome e' stato passato come primo parametro.
* Se la scrittura e' andata a buon fine, restituisce 1, altrimenti restuisce 0.
*
* @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui aggiungere il menu giornaliero
* @param menu_odierno: Variabile di tipo 'menu_giornaliero' che sara' scritta su un record del file
* @param data_odierna: Varibile di tipo 'data' che indica il giorno in cui deve essere aggiunto il menu giornaliero
* @return unsigned short int: Valore booleano che rappresenta l'esito della scrittura
*/

unsigned short int aggiungi_menu_giornaliero (char* nome_file, menu_giornaliero menu_odierno, data data_odierna );





/**
* Questa funzione cancella dal file il menu giornaliero del giorno passato come terzo paramentro,
* il quale si riferisce all'utente che ha per id il secondo parametro passato alla funzione.
* Se la cancellazione e' andata a buon fine, restituisce 1, altrimenti restituisce 0.
*
* @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui cancellare il menu giornaliero
* @param id_utente: Intero che rappresenta l'utente al quale sara' cancellato il menu dal file
* @param data_menu: Variabile di tipo 'data' che rappresenta il giorno del menu settimanale da cui cancellare il menu giornaliero
* @return unsigned short int: Valore booleano che rappresenta l'esito della cancellazione
*/
unsigned short int cancella_menu_giornaliero ( char* nome_file, unsigned short int id_utente, data data_menu );





/**
* Questa funzione legge il vettore di tipo menu_giornaliero passato come primo parametro e restituisce
* un intero che rappresenta l'ultimo indice valido, cioe' l'ultimo elemento che ha un id > 0.
*
* @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che verra' letto
* @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @return unsigned short int: Intero che rappresenta l'ultimo indice contenete un menu giornaliero valido
*/

unsigned short int get_ultimo_indice_menu (const menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri);





/**
* Questa funzione legge il vettore di tipo menu_giornaliero come primo parametro e restituisce
* un intero che rappresenta un nuovo id diverso da tutti gli altri.
*
* @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che verra' letto
* @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @return unsigned short int: Intero che rappresenta un nuovo id valido
*/

unsigned short int get_nuovo_id_menu (const menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri);





/**
 * Questa funzione prende una ricetta come primo parametro e verifica se gli ingredienti di tale ricetta sono contenuti in quantita' sufficenti nel
 * vettore di alimenti passato coem secondo paramentro. Se la ricetta e' preparabile, la funzione restituisce 1, altrimenti 0.
 * @param[in] ricetta_da_preparare:	Variabile di tipo ricetta sulla quale viene effettuato il controllo della disponibilita' degli ingredienti
 * @param[in] alimenti_frigo: Vettore di tipo 'alimento' sul quale vengono contate le quantita' degli alimenti memorizzati
 * @param[in] numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
 * @param[in] numero_persone: Intero che rappresenta il numero di persone per cui si vuole preparare la ricetta
 * @return unsigned short int: Valore booleano che puo' essere 1 o 0
 */
unsigned short int is_ricetta_preparabile (ricetta ricetta_da_preparare, const alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int numero_persone);





/**
 * Questa procedura prende in input una ricetta e il numero di persone per cui e' stata preparata e elimina gli alimenti usati per la ricetta dal vettore di
 * alimenti passato come terzo parametro. Se l'ultimo paramentro e' 1, verranno stampati gli alimenti cancellati dal frigo, altrimenti non vaerra' stampato nulla.
 * @param ricetta_da_preparare: Variabile di tipo ricetta i cui ingredienti devono essere tolti dal frigo
 * @param numero_persone: Intero che rappresenta il numero di persone per cui e' stata preparata la ricetta
 * @param alimenti_frigo: Vettore di tipo 'alimento' che verra' modificato in base agli ingredienti usati
 * @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore
 * @param stampa_alimenti_usati: Intero booleano che puo' essere 1 o 0
 */

void elimina_ingredienti_usati (ricetta ricetta_da_preparare, unsigned short int numero_persone, alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int stampa_alimenti_usati);





/**
 * Questa procedura consente di acquire da tastiera quale menu giornaliero modificare, e chiede se l'utente vuole modificare l'id utente o un pasto.
 * La modifica dell'id utente consegue l'asseganzione del menu giornaliero ad un altro utente.
 * La modifica del pasto fa inserire un nuovo pasto all'utente e se questo e' preparebile,
 * il menu viene modificato, altrimenti la modifica viene annullata.
 *
 * @param nome_file: Vettore di caratteri che rappresenta il nome del file da cui modificare il menu giornaliero
 * @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che verra' modificato
 * @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore menu_settimanale
 * @param ricettario: Vettore di tipo 'ricetta' dal quale vengono presi i dati sui pasti
 * @param  numero_ricette: Intero che rappresenta il numero di elementi da cui e' composto il vettore ricettario
 * @param alimenti_frigo: Vettore di tipo 'alimento' che verra' modificato in base al pasto che si vuole modificare
 * @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore alimenti_frigo
 * @param id_utente: Intero che rappresenta l'utente per il quale deve essere modificato il menu giornaliero
 * @param data_corrente: Varibile di tipo 'data' che indica la data corrente al momento della chiamata della funzione
 */

void input_modifica_menu ( char* nome_file, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, const ricetta* ricettario, unsigned short int numero_ricette, alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int id_utente, data data_corrente );





/**
* Questa funzione prende in input un vettore di tipo 'menu_giornaliero', lo legge
* e restituisce l'indice dell'elemento che ha come id il terzo parametro.
*
* @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che verra' letto
* @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @param id_menu: Id da cercare nel vettore
* @return unsigned short int: Intero che rappresenta l'indice dell'id cercato
*/
unsigned short int indice_id_menu ( const menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, unsigned short int id_menu);





/**
* Questa funzione prende in input un vettore di tipo 'menu_giornaliero',
* e verfica se il terzo parametro e' uno tra gli id nel vettore.
* Se si ha almeno una corrispondenza, la funzione restituisce 1,
* altrimenti retituisce 0.
*
* @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che verra' letto
* @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore
* @param id_menu: Id da cercare nel vettore
* @param id_utente: Intero che rappresenta l'id dell'utente per cui il menu deve esistere
* @return unsigned short int: Intero booleano che indica se l'id esiste o meno nel vettore
*/

unsigned short int is_menu_esistente (const menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, unsigned short int id_menu, unsigned short int id_utente);





/**
 * Questa procedura consente di acquire da tastiera quale pasto del menu giornaliero cancellare, dopodiche' il pasto viene cancellato sia dal vettore che dal file.
 *
 * @param nome_file: Vettore di caratteri che rappresenta il nome del file da cui cancellare il menu giornaliero
 * @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che verra' modificato
 * @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore menu_settimanale
 * @param ricettario: Vettore di tipo 'ricetta' dal quale vengono presi i dati sui pasti
 * @param numero_ricette: Intero che rappresenta il numero di elementi da cui e' composto il vettore ricettario
 * @param id_utente: Intero che rappresenta l'utente per il quale deve essere cancellato il menu giornaliero
 */

void input_cancella_menu ( char* nome_file, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int id_utente );





/**
 * Questa funzione consente di modificare l'utente a cui il menu giornaliero (passato come secondo parametro) si riferisce.
 * Pero' se l'utente a cui verra' attribuito il menu' ha un menu' piu recente nello stesso giorno, verra' mostrato un messaggio di errore.
 * La funzione restituisce 1 se il menu viene modificato, 0 altrimenti.
 *
 * @param nome_file:  Vettore di caratteri che rappresenta il nome del file da cui modificare il menu giornaliero
 * @param menu_modificato: Variabile di tipo 'menu_giornaliero' che deve essere modificata
 * @param menu_settimanale: Vettore di tipo 'menu_giornaliero' che verra' modificato
 * @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore menu_settimanale
 * @param indice_mod: Intero che rappresenta l'indice del vettore da modificare
 * @param id_utente: Intero che rappresenta l'utente per il quale deve essere modificato il menu giornaliero
 * @return unsigned short int: Intero booleano che indica se il menu e' stato modificato o meno
 */

unsigned short int modifica_giorno (char* nome_file, menu_giornaliero menu_modificato, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, unsigned short int indice_mod, unsigned short int id_utente);





/**
 * Questa funzione consente di aggiungere al vettore di alimenti, gli ingredienti necessari ad una data ricetta del vettore di ricette specificata dall'indice 'indice_ricetta'.
 * La funzione restituisce il numero di alimenti rimessi in frigo.
 *
 * @param alimenti_frigo: Vettore di tipo 'alimento' in cui verranno rimessi gli alimenti
 * @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore alimenti_frigo
 * @param ricettario: Vettore di tipo 'ricetta' dal quale vengono presi i dati sui pasti
 * @param numero_ricette: Intero che rappresenta il numero di elementi da cui e' composto il vettore ricettario
 * @param indice_ricetta: Intero che rappresenta l'indice del vettore di ricette i cui ingredienti devono essere rimessi in frigo
 * @param numero_persone: Intero che rappresenta il numero di persone per cui e' stata preparata la ricetta
 * @param stampa_alimenti_rimessi: Intero booleano che se 1 la funzione stampera' gli alimenti rimessi, se 0 non stampera' nulla
 * @return unsigned short int: Intero che conta il numero degli alimenti riemssi in frigo
 */
unsigned short int rimetti_alimenti_in_frigo (alimento* alimenti_frigo, unsigned short int numero_alimenti, const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int indice_ricetta, unsigned short int numero_persone, unsigned short int stampa_alimenti_rimessi);





/**
 * Questa procedura permettere di scegliere all'utente quale pasto preparare.
 * L'ultimo e il penultimo parametro vengono passati per riferimento, in modo da mmodificare direttamente i parametri attuali quando la funzione viene chiamata.
 *
 * @param ricettario: Vettore di tipo 'ricetta' dal quale vengono presi i dati sui pasti
 * @param numero_ricette: Intero che rappresenta il numero di elementi da cui e' composto il vettore ricettario
 * @param input_id_ricetta: Intero passato per riferiemento che memeorizzera' l'id della ricetta inserito da tastiera
 * @param numero_persone: Intero passato per riferiemento che memeorizzera' il numero di persone inserito da tastiera per cui preparare la ricetta
 */

void input_scelta_pasto (const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int* input_id_ricetta, unsigned short int* numero_persone);





/**
 * Questa funzione consente di modificare un pasto del menu' giornaliero presente in corrispondenza dell'indice passato come secondo parametro.
 * Al pasto indicato dall'ultimo parametro pasto_da_modificare viene sostituito un nuovo pasto, indicato dal parametro nuovo_indice_ricetta.
 * Se il nuovo pasto e' preparabile, la funzione restituisce 1 e modifica sia il vettore che il file di menu settimanali.
 * Altrimenti restituisce 0.
 *
 * @param nome_file: Vettore di caratteri che rappresenta il nome del file su cui modificare il menu giornaliero
 * @param indice_menu: Intero che rappresente l'indice del vettore menu_settimanale da modificare
 * @param menu_settimanale:  Vettore di tipo 'menu_giornaliero' che verra' modificato
 * @param numero_menu_giornalieri: Intero che rappresenta il numero di elementi da cui e' composto il vettore menu_settimanale
 * @param ricettario: Vettore di tipo 'ricetta' dal quale vengono presi i dati sui pasti
 * @param numero_ricette: Intero che rappresenta il numero di elementi da cui e' composto il vettore ricettario
 * @param alimenti_frigo: Vettore di tipo 'alimento' che verra' modificato
 * @param numero_alimenti: Intero che rappresenta il numero di elementi da cui e' composto il vettore alimenti_frigo
 * @param input_id_ricetta: Intero che memeorizzera' l'id della ricetta da sostituire al pasto precedente
 * @param vecchio_numero_persone: Intero che indica in numero di persone per cui era il pasto che si vuole modificare
 * @param nuovo_numero_persone: Intero che indica il numero di persone per cui e' il nuovo pasto
 * @param vecchio_indice_ricetta: Intero che indica l'indice del pasto che si vuole modificare
 * @param nuovo_indice_ricetta: Intero che indica l'indice del nuovo pasto
 * @param pasto_da_modificare: Intero che indica l'indice del pasto da modificare nel menu giornaliero
 * @return unsigned short int: Intero booleano che indica se la ricetta scelta e' preparabile o meno
 */

unsigned short int modifica_pasto (char* nome_file, unsigned short int indice_menu, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, const ricetta* ricettario, unsigned short int numero_ricette, alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int input_id_ricetta, unsigned short int vecchio_numero_persone, unsigned short int nuovo_numero_persone, unsigned short int vecchio_indice_ricetta, unsigned short int nuovo_indice_ricetta, unsigned short int pasto_da_modificare);





/**
 * Questa funzione effettua una copia del vettore passato come primo parametro e
 * restituisce il puntatore al vettore copiato come valore di ritorno.
 * @param alimenti_frigo: Vettore di tipo 'alimento' che verra' copiato
 * @param numero_alimenti_frigo: Intero che rappresenta il numero di elementi da cui e' composto il vettore alimenti_frigo
 * @return
 */
alimento* copia_vettore_alimenti (const alimento* alimenti_frigo, unsigned short int numero_alimenti_frigo);
