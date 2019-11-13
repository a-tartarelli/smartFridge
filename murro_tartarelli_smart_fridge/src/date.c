#include "date.h"


/**
 * @post il valore restituito deve corrispondere alla data fornita dal sistema
 */

data calcola_data_corrente (void) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	data data_corrente;
	data_corrente.anno = tm.tm_year + 1900;		/* acquisisce dal sistema l'anno corrente e lo salva in data_corrente.anno */
	data_corrente.mese = tm.tm_mon + 1;			/* acquisisce dal sistema il mese corrente e lo salva in data_corrente.mese */
	data_corrente.giorno = tm.tm_mday;			/* acquisisce dal sistema il giorno corrente e lo salva in data_corrente.giorno */

	short int giorno_settimana_int = get_giorno_settimana_intero (data_corrente);				/* dalla data corrente si ottiene il giorno settimanale corrispondente in intero*/
	strcpy (data_corrente.giorno_settimana, get_giorno_settimana_char (giorno_settimana_int));	/* converte il giorno settimanale da intero a stringa e lo assegna al campo data_corrente.giorno_settimana*/

	return data_corrente;
}


/**
 * @pre la data passata come parametro deve avere tutti i campi pieni, altrimenti potrebbero essere visualizzati caratteri strani
 */

void stampa_data_corrente(data data_corrente) {
	printf("\nData corrente:\n\t%u/%u/%u (%s)\n", data_corrente.giorno, data_corrente.mese, data_corrente.anno, data_corrente.giorno_settimana );
}


/**
 * La funzione esegue dei controlli sul mese e sul giorno in modo da evitare di avere date errate, come ad esempio 31 novembre,
 * e valuta i range in cui giorni e mesi sono effettivamente corretti. In base a cio' incrementa e modifica gli opportuni campi.
 *
 * @pre la data in input deve essere corretta e i campi devono essere pieni, altriemnti potrebbero verificarsi errori logoci a runtime
 * @post la data restituita deve essere esattamente quella del giorno successivo all'input
 */

data giorno_successivo(data data_corrente){

	switch ( data_corrente.mese ) {                                      /*selezione multipla per rendere valido il giorno di nascita in base al mese*/
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if(data_corrente.giorno == MAX_GIORNO && data_corrente.mese == MAX_MESE){		/*se il giorno e' 31 dicembre, bisogna passare all'anno nuovo*/
			data_corrente.giorno = 1;
			data_corrente.mese = 1;
			data_corrente.anno++;
		} else if ( is_compreso_tra (MIN_GIORNO, MAX_GIORNO -1, data_corrente.giorno) ){	/* altrimenti se il mese e' uno tra 1,3,5,7, 8, 10 e il giorno non e' 31*/
			data_corrente.giorno++;															/* viene semplicemente incrementato il giorno*/
		}  else {
			data_corrente.giorno = MIN_GIORNO;												/* altrimenti si passa al mese successivo */
			data_corrente.mese++;
		}
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		if ( is_compreso_tra (MIN_GIORNO, MAX_GIORNO-2, data_corrente.giorno) ){		/*  se il mese e' uno tra 4, 6, 9, 11 e il giorno non e' 30*/
			data_corrente.giorno++;														/* viene semplicemente incrementato il giorno*/
		} else {
			data_corrente.giorno = 1;													/* altrimenti si passa al mese successivo */
			data_corrente.mese++;
		}
		break;

	case 2:
		if (data_corrente.anno % BISESTILE == 0) {           /*Se il mese e' 2 e l'anno e' bisestile*/
			if ( is_compreso_tra (MIN_GIORNO, GIORNI_FEBBRAIO-1, data_corrente.giorno) ){
				data_corrente.giorno++;
			} else {
				data_corrente.giorno = 1;
				data_corrente.mese++;
			}
		} else {
			if ( is_compreso_tra (MIN_GIORNO, GIORNI_FEBBRAIO-2, data_corrente.giorno) ){
				data_corrente.giorno++;
			} else {
				data_corrente.giorno = 1;
				data_corrente.mese++;
			}
		}
		break;

	}

	short int giorno_settimana_int = get_giorno_settimana_intero (data_corrente);				 /* dalla data corrente si ottiene il giorno settimanale corrispondente in intero*/
	strcpy (data_corrente.giorno_settimana, get_giorno_settimana_char (giorno_settimana_int));	 /* converte il giorno settimanale da intero a stringa e lo assegna al campo data_corrente.giorno_settimana*/
	return data_corrente;
}



/**
 * La funzione esegue dei controlli sul mese e sul giorno in modo da evitare di avere date errate, come ad esempio 31 novembre,
 * e valuta i range in cui giorni e mesi sono effettivamente corretti. In base a cio' decrementa e modifica gli opportuni campi.
 *
 * @pre la data in input deve essere corretta e i campi devono essere pieni, altriemnti potrebbero verificarsi errori logoci a runtime
 * @post la data restituita deve essere esattamente quella del giorno precedente all'input
 */

data giorno_precedente(data data_corrente){

	switch ( data_corrente.mese ) {                                      /*selezione multipla per rendere valido il giorno di nascita in base al mese*/
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if(data_corrente.giorno == MIN_GIORNO && data_corrente.mese == MIN_MESE){			/*se il giorno e' 1 gennaio, bisogna passare all'anno precedente*/
			data_corrente.giorno = MAX_GIORNO;
			data_corrente.mese = MAX_MESE;
			data_corrente.anno--;
		} else if ( is_compreso_tra (MIN_GIORNO+1, MAX_GIORNO, data_corrente.giorno) ){		/* altrimenti se il mese e' uno tra 3,5,7, 8, 10, 12 e il giorno non e' 1*/
			data_corrente.giorno--;															/* viene semplicemente decrementato il giorno*/
		} else {
			data_corrente.giorno = MAX_GIORNO;
			data_corrente.mese--;															/* altrimenti si passa al mese precedente */
		}
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		if ( is_compreso_tra (MIN_GIORNO+1, MAX_GIORNO-1, data_corrente.giorno) ){			/*  se il mese e' uno tra 4, 6, 9, 11 e il giorno non e' 1 */
			data_corrente.giorno--;															/* viene semplicemente decrementato il giorno*/
		} else {
			data_corrente.giorno = MAX_GIORNO-1;											/* altrimenti si passa al mese precedente */
			data_corrente.mese--;
		}
		break;

	case 2:
		if (data_corrente.anno % BISESTILE == 0) {           								/*Se il mese e' 2 e l'anno e' bisestile*/
			if ( is_compreso_tra (MIN_GIORNO+1, GIORNI_FEBBRAIO, data_corrente.giorno) ){
				data_corrente.giorno--;
			} else {
				data_corrente.giorno = GIORNI_FEBBRAIO;
				data_corrente.mese--;
			}
		} else {
			if ( is_compreso_tra (MIN_GIORNO+1, GIORNI_FEBBRAIO-1, data_corrente.giorno) ){
				data_corrente.giorno--;
			} else {
				data_corrente.giorno = GIORNI_FEBBRAIO-1;
				data_corrente.mese--;
			}
		}
		break;

	}

	short int giorno_settimana_int = get_giorno_settimana_intero (data_corrente);					/* dalla data corrente si ottiene il giorno settimanale corrispondente in intero*/
	strcpy (data_corrente.giorno_settimana, get_giorno_settimana_char (giorno_settimana_int));		/* converte il giorno settimanale da intero a stringa e lo assegna al campo data_corrente.giorno_settimana*/
	return data_corrente;
}


/**
 * @pre la data in input deve essere corretta e i campi devono essere pieni, altriemnti potrebbero verificarsi errori logoci a runtime
 * @post l'intero restituisto sara' sicuramente compreso tra 0 e 6 e deve essere corretto in base alla data in input
 */

unsigned short int get_giorno_settimana_intero (data d) {

	short int modifica, mm, yy;

	modifica = (14 - d.mese) / 12;
	mm = d.mese + 12 * modifica - 2;
	yy = d.anno - modifica;
	return (d.giorno + (13 * mm - 1) / 5 +yy + yy / 4 - yy / 100 + yy / 400) % 7;
}


/**
 * @pre l'intero in input deve essere compreso tra 0 e 6 per far si che la funzione non ritorni la stringa ERRORE
 * @post la stringa restituita sara' sicuramnete una tra quelle assegante nei case della switch a giorno_settimana_char
 */

char* get_giorno_settimana_char (unsigned short int giorno_settimana) {

	char* giorno_settimana_char = (char*) calloc(LUNGHEZZA_GIORNO_SETTIMANA, sizeof(char));		/* allocazione dinamica di una stringa in memoria */
	switch (giorno_settimana) {

		case 0: strcpy (giorno_settimana_char, "DOMENICA");
		break;

		case 1: strcpy (giorno_settimana_char, "LUNEDI");
		break;

		case 2: strcpy (giorno_settimana_char, "MARTEDI");
		break;

		case 3: strcpy (giorno_settimana_char, "MERCOLEDI");
		break;

		case 4: strcpy (giorno_settimana_char, "GIOVEDI");
		break;

		case 5: strcpy (giorno_settimana_char, "VENERDI");
		break;

		case 6: strcpy (giorno_settimana_char, "SABATO");
		break;

		default: strcpy (giorno_settimana_char, "ERRORE");
		}

	return giorno_settimana_char;
}


/**
 * La funzione confronta prima l'anno, poi il mese e poi il giorno.
 * Se tutti i contronti danno come risultato dei valori uguali, le due date saranno uguali.
 * Se invece una data e' minore dell'altra lo si evince dal confronto in sequenza di anno, mese e giorno.
 * Lo stesso vale per verificare che una data e' maggiore dell'altra.
 *
 * @pre le date in input devono essere corrette e i campi devono essere pieni, altriemnti potrebbero verificarsi errori logoci a runtime
 * @post l'intero restituito deve essere coerente con il confronto delle date (es. non deve restituire 0 se d1 > d2)
 */

unsigned short int confronta_date (data d1, data d2) {

	if (d1.anno > d2.anno) {
		return 1;
	} else if (d1.anno < d2.anno) {
		return 0;
	} else {							//stesso anno
		if (d1.mese > d2.mese) {
			return 1;
		} else if (d1.mese < d2.mese){
			return 0;
		} else {						//stesso mese
			if (d1.giorno > d2.giorno) {
				return 1;
			} else if (d1.giorno < d2.giorno) {
				return 0;
			} else {
				return 2;				//stesso giorno
			}
		}
	}
}

