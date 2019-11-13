/**
* @file date.h
*
* Questo file contiene tutte le funzioni necessarie per gestire le date in un programma, come ad
* esempio l'acquisizione della data corrente dal sistema, la modifica di una data ecc.
* Pe rla maggior parte tali funzioni lavorano sui campi della struct data: giorno, mese, anno e giono settimanale.
*
* @version 1.0
* @date 03/06/2018
* @authors Giuseppe Murro, Alessio Tartarelli
*/

#ifndef DATE_H_
#define DATE_H_

#include "controlli.h"
#include "strutture_dati.h"

#endif /* DATE_H_ */





/**
* Questa funzione non richiede alcun paramentro e ogni volta che viene richiamata
* restituisce la data corrente acquisita dal sistema.
*
* @return data: Restituisce una variabile di tipo 'data' con i propri campi opportunamente riempiti
*/

data calcola_data_corrente (void);





/**
* Questa procedura prende in input un parametro di tipo 'data' e stampa sullo schermo
* i rispettivi campi.
*
* @param data_corrente: Variabile di tipo 'data' con i propri campi opportunamente riempiti
*/

void stampa_data_corrente(data data_corrente);





/**
* Questa funzione prende in input un parametro di tipo 'data', la modifica, incrementadola
* di un giorno e la data modificata viene restituita come valore di ritorno.
* es. 27/10/2018 --> 28/10/2018
*     31/12/2018 --> 1/1/2019
*
* @param data_corrente: Variabile di tipo 'data' con i propri campi opportunamente riempiti
* @return data: Restituisce una variabile di tipo 'data' che sara' l'input incrementato di un giorno
*/

data giorno_successivo(data data_corrente);





/**
* Questa funzione prende in input un parametro di tipo 'data', la modifica, decrementandola
* di un giorno e la data modificata viene restituita come valore di ritorno.
* es. 28/10/2018 --> 27/10/2018
*     1/1/2019 --> 31/12/2018
*
* @param data_corrente: Variabile di tipo 'data' con i propri campi opportunamente riempiti
* @return data: Restituisce una variabile di tipo 'data' che sara' l'input decrementato di un giorno
*/

data giorno_precedente(data data_corrente);





/**
* Questa funzione prende in input un intero compreso tra 0 e 6 e
* restituisce il corrispondente giorno settimanale sottoforma di stringa.
* es. 0 --> DOMENICA
*     1 --> LUNEDI
*     6 --> SABATO
*     9 --> ERRORE
*
* @param giorno_settimana: Intero compreso tra 0 e 6
* @return char*: Giorno settimanale sottoforma di stringa
*/

char* get_giorno_settimana_char (unsigned short int giorno_settimana);





/**
* Questa funzione prende in input  un parametro di tipo 'data', in base al quale calcola
* il giono della settimana, e restituisce l'intero corrispondente a tale giorno.
* es. 3/6/2018 --> 0
*     2/6/2018 --> 6
*
* @param d: Variabile di tipo 'data' con i propri campi opportunamente riempiti
* @return unsigned short int: Intero compreso tra 0 e 6
*/

unsigned short int get_giorno_settimana_intero (data d);





/**
* Questa funzione prende in input  due parametri di tipo 'data' e
* se d1 < d2 restituisce 0
* se d1 > d2 restituisce 1
* se d1 = d2 restituisce 2
*
* es. 3/6/2018, 5/6/2018 --> 0
*     1/7/2018, 30/6/2018 --> 1
*     1/7/2018, 1/7/2018 --> 2
*
* @param d1: Variabile di tipo 'data' con i propri campi opportunamente riempiti
* @param d2: Variabile di tipo 'data' con i propri campi opportunamente riempiti
* @return unsigned short int: Intero compreso tra 0 e 2
*/

unsigned short int confronta_date (data d1, data d2);
