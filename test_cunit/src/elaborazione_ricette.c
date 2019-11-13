#include "elaborazione_ricette.h"
#include "gestione_utenti.h"
#include "controlli.h"
#include "strutture_dati.h"

/**
 * ci sono vari controlli effettuati sull'input eseguiti attravero funzioni presenti in controlli.c
 *
 *@pre il file deve gia esistere altrimenti ci sara' un mal funzionameno della funzione
 */
void input_aggiungi_ricetta(char* nome_file, ricetta* ricettario, unsigned short int numero_ricette){
	//variabili locali
	unsigned short int i = 0;
	short int risposta;
	int temp;
	float kcal_temp;
	ricetta ricetta_nuova;

	printf("\n*************************************************************\n");
	printf("********************  AGGIUNGI RICETTA  ********************\n");
	printf("*************************************************************\n\n");

	//prendo l'ultimo id della ricetta presente nel ricettario e lo incremento di 1
	ricetta_nuova.id_ricetta = get_ultimo_id_ricetta (ricettario, numero_ricette) + 1;

	strcpy(ricetta_nuova.nome_ricetta, inserisci_input_caratteri_spazio("Nome della ricetta (MAX 40 caratteri): ", LUNGHEZZA_NOME));

	temp = inserisci_input_intero("Per quante persone e' la ricetta? ", LUNGHEZZA_INPUT);
	//finquando il valore acquisito non e' compreso tra 1 e MAX_PERSONE faccio reinserire il valore
	while (!is_compreso_tra(1, MAX_PERSONE, temp)) {
		temp = inserisci_input_intero("Il valore deve essere compreso tra 1 e 10, reinserire valore: ", LUNGHEZZA_INPUT);
	}
	ricetta_nuova.n_persone = temp;

	printf("\n");
	do {
		ricetta_nuova.numero_ingredienti++;
		ricetta_nuova.ingredienti[i] = input_ingredienti(i);
		i++;

		risposta = inserisci_input_intero("Inserire altro alimento? (0 = no / 1 = si): ", LUNGHEZZA_RISPOSTA);

		printf("\n");
		while (!is_compreso_tra(0, 1, risposta)) {
			risposta = inserisci_input_intero("Inserisci un valore che sia (0 = no o 1 = si): ", LUNGHEZZA_RISPOSTA);
		}

	} while (risposta == 1);

	ricetta_nuova.numero_ingredienti = i;

	temp = inserisci_input_intero("Tempo di preparazione? (in minuti): ", LUNGHEZZA_INPUT);

	while (!is_compreso_tra(0, MAX_TEMPO_PREPARAZIONE, temp)) {
		temp = inserisci_input_intero("Il tempo di preparazione non puo' superare i 360 minuti, inserire un altro valore: ", LUNGHEZZA_INPUT);
	}

	ricetta_nuova.tempo_preparazione = temp;

	strcpy(ricetta_nuova.link_procedimento, inserisci_input_link("Link procedimento (short link bit.ly): ", MAX_LUNGHEZZA_LINK));

	temp = inserisci_input_intero("Complessita'? (0 = BASSA, 1 = MEDIA, 2 = ALTA): ", LUNGHEZZA_INPUT);
	while (!is_compreso_tra(0, MAX_COMPLESSITA, temp)) {
		temp = inserisci_input_intero("Inserire un valore che sia (0 = BASSA, 1 = MEDIA e 2 = ALTA): ", LUNGHEZZA_INPUT);
	}
	ricetta_nuova.complessita = temp;

	kcal_temp = inserisci_input_float("Kcal sprigionate dal piatto: ", LUNGHEZZA_INPUT);
	while (!is_compreso_tra(0, MAX_CALORIE, kcal_temp)) {
		kcal_temp = inserisci_input_intero("Non superare il limite massimo di 9000 kcal, reinserire valore: ", LUNGHEZZA_INPUT);
	}
	ricetta_nuova.kcal = kcal_temp;

	printf("********************************************************\n");

	//richiamo la funzione aggiungi_ricetta che scrivera' su file la ricetta appena acquisita
	aggiungi_ricetta(nome_file, ricetta_nuova);

	//aggiorno anche il vettore di ricette, inserendo la nuova ricetta acquisita
	ricettario[get_ultimo_indice_ricetta (ricettario, numero_ricette) + 1] = ricetta_nuova;
}


/**
 * @pre il file deve gia esistere altrimenti ci sara' un mal funzionameno della funzione
 *
 */
unsigned short int aggiungi_ricetta ( char* nome_file, ricetta ricetta_nuova) {
	FILE *file;

	if ((file = fopen(nome_file, "wb+")) == NULL) {		/*apertura del file in modalita' scrittura/modifica */
		printf("Errore nell'apertura %s",nome_file);
		return 0;		/* viene restituito 0 se il file non e' stato aperto */
	}
	else {
		fseek(file, sizeof(ricetta)* (ricetta_nuova.id_ricetta - 1), SEEK_SET);					/*viene posizionato il puntare nel file */
		fwrite(&ricetta_nuova, sizeof(ricetta), 1, file);		/*ricetta_nuova viene scritta sul file*/
	}

	if(!fclose(file)){
		printf("\nRicetta aggiunta!\n");
	}

	return 1;	/* viene restituito 1 se la scrittura e' andata a buon fine */

}



unsigned short int get_ultimo_id_ricetta (const ricetta* ricettario, unsigned short int numero_ricette) {

	unsigned short int i = get_ultimo_indice_ricetta (ricettario, numero_ricette);
	return ricettario[i].id_ricetta;
}


/**
 * Scorro tutto il vettore di ::ricetta per trovare l'ultimo indice del vettore di ricette
 * Controllo se il campo ID della struct ::ricetta e' maggiore di 0, poiche' tutti i valori non validi o non presenti
 * hanno id = 0
 */
unsigned short int get_ultimo_indice_ricetta (const ricetta* ricettario, unsigned short int numero_ricette) {

	unsigned short int ultimo_i = 0;
	int i;
	for (i=0; i<numero_ricette; i++) {
		if (ricettario[i].id_ricetta > 0) {
			ultimo_i = i;
		}
	}

	return ultimo_i;
}



ingrediente input_ingredienti (unsigned short int numero_ingrediente) {
	ingrediente ingrediente;
	char temp[LUNGHEZZA_INPUT];
	char messaggio [LUNGHEZZA_NOME];

	sprintf (messaggio,"Nome ingrediente %hu: ", numero_ingrediente + 1);
	strcpy(ingrediente.nome_alimento, inserisci_input_caratteri_spazio(messaggio, LUNGHEZZA_NOME));

	strcpy(temp, inserisci_input_float_qb ("Inserisci quantita' (espressa in grammi o \"qb\"): ", LUNGHEZZA_INPUT));

	while(!is_compreso_tra_float(1, MAX_QUANTITA, (float) atof(temp)) && strcmp(temp, "qb") ) {
		strcpy(temp, inserisci_input_float_qb ("Inserisci quantita' (espressa in grammi o \"qb\"): ", LUNGHEZZA_INPUT));
	}

	strcpy(ingrediente.quantita, temp);

	//imposto l'unita' di misura in grammi se e' stato inserito un valore numerico altrimenti
	//se e' stato inserito "qb" imposto l'unita' di misura con uno spazio
	if (strcmp(temp, "qb")== 0){
		ingrediente.unita_misura = ' ';
	} else {
		ingrediente.unita_misura = 'g';
	}

	return ingrediente;
}


/**
 * Scandisco tutto il vettore di ricette e stampo solo quelle con id > 0
 */
unsigned short int apri_ricettario(const ricetta ricettario[], unsigned short int numero_ricette){

	unsigned short int elementi_stampati = 0;	/*contatore degli alimenti stampati*/

	printf("\n**************************************************************************************************************************************************************\n");
	printf("************************************************************************  RICETTARIO  ************************************************************************\n");
	printf("**************************************************************************************************************************************************************\n\n");

	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %3s | %35s | %9s | %12s | %27s | %5s | %11s| %30s  |\n","ID", "NOME RICETTA", "N PERSONE", "CALORIE", "LINK PROCEDIMENTO", "TEMPO", "COMPLESSITA'", "INGREDIENTI");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	for (int i = 0; i < numero_ricette; i++) {

		if (ricettario[i].id_ricetta > 0) {		/*stampa l'alimento solo se l'id e' valido*/


			printf("| %3hu | %35s | %9hu | %7.2f kcal | %27s | %4hu' |",
					ricettario[i].id_ricetta,
					ricettario[i].nome_ricetta,
					ricettario[i].n_persone,
					ricettario[i].kcal,
					ricettario[i].link_procedimento,
					ricettario[i].tempo_preparazione);

			if (ricettario[i].complessita == BASSA) {
				printf(" %11s |", "BASSA" );
			} else if (ricettario[i].complessita == MEDIA) {
				printf(" %11s |", "MEDIA" );
			} else if (ricettario[i].complessita == ALTA) {
				printf(" %11s |", "ALTA" );
			}

			printf("%23s (%4s %1c) |\n", ricettario[i].ingredienti[0].nome_alimento, ricettario[i].ingredienti[0].quantita, ricettario[i].ingredienti[0].unita_misura);
			for (int j = 1; j < ricettario[i].numero_ingredienti; j++) {
				printf("| %3s | %35s | %9s | %12s | %27s | %5s | %11s |%23s (%4s %1c) |\n","","","","","","","", ricettario[i].ingredienti[j].nome_alimento, ricettario[i].ingredienti[j].quantita, ricettario[i].ingredienti[j].unita_misura);
			}

			printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

			elementi_stampati++;
		}
	}

	return elementi_stampati;	/*restituisce il numero degli alimenti stampati*/

}



unsigned short int modifica_ricetta (char* nome_file, ricetta ricetta) {

	FILE *file;

	if ((file = fopen(nome_file, "rb+")) == NULL) {		/*apertura del file in modalita' lettura/modifica */
		printf("Errore nell'apertura %s",nome_file);
		return 0;		/* viene restituito 0 se il file non e' stato aperto */
	}
	else {
		fseek(file, sizeof(ricetta) * (ricetta.id_ricetta - 1), SEEK_SET);					/*viene posizionato il puntare nel file */
		fwrite(&ricetta, sizeof(ricetta), 1, file);							/*ricetta viene scritto sul file*/

	}

	if(!fclose(file)){
		printf("\nRicetta modificata!\n");
	}

	return 1;	/* viene restituito 1 se la scrittura e' andata a buon fine */


}


/**
 * Viene richiesto all'utente quale campo desidera modificare per poi procedere con la relativa modifica
 *
 * @pre il file deve gia esistere altrimenti ci sara' un mal funzionameno della funzione
 */
void input_modifica_ricetta (char* nome_file, ricetta* ricettario, unsigned short int numero_ricette) {

	printf("\n*************************************************************\n");
	printf("********************  MODIFICA RICETTA  ********************\n");
	printf("*************************************************************\n\n");

	ricetta ricetta_modificata; 			  /* alimento che verra'� modificato file */
	unsigned short int indice_mod;			/*indice dell'elemento del vettore da modificare*/
	unsigned short int is_scelta_corretta = 0;	/*flag che se e' 0 indica che la scelta non e' corretta, se e' 1 vuol dire che la scelta e' corretta*/
	int temp;
	short int scelta;

	printf ("Quale alimento vuoi modificare?\n");
	for (int i = 0; i < numero_ricette; i++) {
		if (ricettario[i].id_ricetta > 0) {		/*stampa l'alimento solo se l'id e' valido*/
			printf("\t%hu - %s\n", ricettario[i].id_ricetta, ricettario[i].nome_ricetta);
		}
	}

	ricetta_modificata.id_ricetta = inserisci_input_intero ("? ", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido all'id alimento*/

	/*ciclo che itera finche' is_alimento_esistente e' 0, cioe' fin quando l'input non e' un id esistente nel vettore*/
	while (!is_ricetta_esistente(ricettario, numero_ricette, ricetta_modificata.id_ricetta)) {

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */
		ricetta_modificata.id_ricetta = inserisci_input_intero ("", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido all'id alimento*/
	}

	indice_mod = indice_id_ricetta(ricettario, numero_ricette, ricetta_modificata.id_ricetta);
	ricetta_modificata = ricettario[indice_mod]; /*tutti i campi dell'elemento del vettore da modificare vengono copiati in alimento_modificato*/

	printf ("\nQuale campo vuoi modificare?\n");
	printf ("\t1- Nome ricetta\n"
			"\t2- Tempo di preparazione\n"
			"\t3- Link procedimento\n"
			"\t4- complessita\n"
			"\t5- Kcal sprigionate\n"
			"\t6- N° persone\n"
			"\t7- Ingredienti\n"
			"? ");

	scelta = inserisci_input_intero("", LUNGHEZZA_INPUT);

	/* ciclo che si ripete finche' l'utente non inserisce un input diverso da 1,2,3,4 */
	/* ad ogni iterazione verra'� chiesto un nuovo input all'utente */

	while( is_scelta_corretta == 0 ){

		switch(scelta){						/* switch che eseguira'� un operazione diversa in base all'input dell'utente */

		case 1:
			strcpy(ricetta_modificata.nome_ricetta, inserisci_input_caratteri_spazio ("Nome ricetta: ", LUNGHEZZA_NOME) );	/*viene acquisita una stringa valida formata da sole lettere e asseganta al nome dell'alimento*/
			is_scelta_corretta = 1;
			break;



		case 2:
			temp = inserisci_input_intero("Tempo di preparazione? (in minuti): ", LUNGHEZZA_INPUT);

			while (!is_compreso_tra(0, MAX_TEMPO_PREPARAZIONE, temp)) {
				temp = inserisci_input_intero("Il tempo di preparazione non puo' superare i 360 minuti, inserire un altro valore: ", LUNGHEZZA_INPUT);
			}

			ricetta_modificata.tempo_preparazione = temp;
			is_scelta_corretta = 1;
			break;



		case 3:
			strcpy(ricetta_modificata.link_procedimento, inserisci_input_link("Link procedimento (short link bit.ly): ", MAX_LUNGHEZZA_LINK));
			is_scelta_corretta = 1;
			break;
		case 4:
			temp = inserisci_input_intero("Complessita'? (0 = BASSA, 1 = MEDIA, 2 = ALTA): ", LUNGHEZZA_INPUT);
			while (!is_compreso_tra(0, MAX_COMPLESSITA, temp)) {
				temp = inserisci_input_intero("Inserire un valore che sia (0 = BASSA, 1 = MEDIA e 2 = ALTA): ", LUNGHEZZA_INPUT);
			}
			ricetta_modificata.complessita = temp;
			is_scelta_corretta = 1;
			break;



		case 5:
			ricetta_modificata.kcal = inserisci_input_float("Kcal sprigionate dal piatto: ", LUNGHEZZA_INPUT);
			while (!is_compreso_tra(0, MAX_CALORIE, ricetta_modificata.kcal)) {
				ricetta_modificata.kcal = inserisci_input_intero("Non superare il limite massimo di 2000 kcal, reinserire valore: ", LUNGHEZZA_INPUT);
			}
			is_scelta_corretta = 1;
			break;



		case 6:
			temp = inserisci_input_intero("Per quante persone e' la ricetta? ", LUNGHEZZA_INPUT);
			while (!is_compreso_tra(0, MAX_PERSONE, temp)) {
				temp = inserisci_input_intero("Non superare il limite massimo di 10 persone, reinserire valore: ", LUNGHEZZA_INPUT);
			}
			ricetta_modificata.n_persone = temp;
			is_scelta_corretta = 1;
			break;



		case 7:
			input_modifica_ingredienti(&ricetta_modificata, ricetta_modificata.numero_ingredienti);
			is_scelta_corretta = 1;
			break;



		default:
			printf("Valore errato! Reinserire: ");
			scelta = inserisci_input_intero("", LUNGHEZZA_INPUT);
		}
	}

	//aggiorno il ricettario
	ricettario[indice_mod] = ricetta_modificata;
	//scrivo sul file la modifica effettuata
	modifica_ricetta (nome_file, ricetta_modificata);
}



/**
 * scandisco tutto il vettore di tipo ::ricetta alla ricerca del campo ID conincidente con il parametro "id_ricetta"
 *
 * @pre il parametro "id_ricetta" deve essere sicuramente presente nel ricettario, per tanto va prima controllato con la
 * funzione is_ricetta_esistente(). Altriemnti si verifica un errore logico
 */
unsigned short int indice_id_ricetta (const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int id_ricetta) {

	int i;
	for ( i=0; i<numero_ricette; i++) {
		if (ricettario[i].id_ricetta == id_ricetta) {
			return i;
		}
	}

	return i;
}



/**
 * Verifica che l'ID della ricetta non sia 0 e che ci sia un elemento del vettore di :ricetta = al parametro "id_ricetta"
 */
unsigned short int is_ricetta_esistente(const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int id_ricetta) {

	int i;
	for ( i=0; i<numero_ricette; i++) {
		if (id_ricetta != 0 && ricettario[i].id_ricetta == id_ricetta) {
			return 1;
		}
	}

	return 0;
}



void input_modifica_ingredienti(ricetta* ricetta_da_modificare, unsigned short int numero_ingredienti) {
	short int i, scelta;
	unsigned short int is_scelta_corretta = 0;
	char temp[LUNGHEZZA_INPUT];

	puts("Quale ingrediente si vuole modificare?");

	for(i=0; i<numero_ingredienti; i++) {
		printf("\t%hu- %s\n", i, ricetta_da_modificare->ingredienti[i].nome_alimento);
	}

	i = inserisci_input_intero ("? ", LUNGHEZZA_INPUT ); /*viene impostato l'indice per il vettore di ingredienti*/

	while(!is_compreso_tra(0, numero_ingredienti, i)) {
		printf("Valore errato, reinserire!\n");
		i = inserisci_input_intero ("? ", LUNGHEZZA_INPUT );
	}

	printf ("\nQuale campo vuoi modificare?\n");
	printf ("\t1- Nome ingrediente\n"
			"\t2- Quantita'\n"
			"? ");

	scelta = inserisci_input_intero("", LUNGHEZZA_INPUT);

	while(is_scelta_corretta == 0 ){

		switch(scelta){						/* switch che eseguira'un operazione diversa in base all'input dell'utente */

		case 1:
			strcpy(ricetta_da_modificare->ingredienti[i].nome_alimento, inserisci_input_caratteri_spazio("Nome ingrediente: ", LUNGHEZZA_NOME));
			is_scelta_corretta = 1;
			break;



		case 2:
			strcpy(temp, inserisci_input_float_qb("Inserisci quantita' (espressa in grammi o \"qb\"): ", LUNGHEZZA_INPUT));

			while(!is_compreso_tra_float(1, MAX_QUANTITA, (float) atof(temp)) && strcmp(temp, "qb") ) {
				strcpy(temp, inserisci_input_float_qb ("Inserisci quantita' (espressa in grammi o \"qb\"): ", LUNGHEZZA_INPUT));
			}

			strcpy(ricetta_da_modificare->ingredienti[i].quantita, temp);

			if (strcmp(temp, "qb")== 0){
				ricetta_da_modificare->ingredienti[i].unita_misura = ' ';
			} else {
				ricetta_da_modificare->ingredienti[i].unita_misura = 'g';
			}
			is_scelta_corretta = 1;
			break;


		default:
			printf("Valore errato! Reinserire: ");
			scelta = inserisci_input_intero("", LUNGHEZZA_INPUT);
		}
	}
}



void input_cancella_ricetta(ricetta* ricettario, unsigned short int numero_ricette) {
	short int id_ricetta_cancellare;

	id_ricetta_cancellare = inserisci_input_intero("Inserire l'id della ricetta da cancellare: ", LUNGHEZZA_INPUT);

	while(!is_ricetta_esistente(ricettario, numero_ricette, id_ricetta_cancellare)) {
		id_ricetta_cancellare = inserisci_input_intero("Id della ricetta non valido, reinserire: ", LUNGHEZZA_INPUT);
	}

	if(cancella_ricetta("elenco_ricette.bin", id_ricetta_cancellare)) {
		//modifica anche sul vettore di tipo ricetta
		ricettario[id_ricetta_cancellare - 1].id_ricetta = 0;
		printf("***Ricetta cancellata!\n");
	}

}


/**
 * Per la cancellazione della ricetta viene impostato il suo ID a 0 cosi che venga ignorato dalle altr funzioni
 */
unsigned short int cancella_ricetta (char* nome_file, unsigned short int id_ricetta) {
	FILE *file;
	ricetta ricetta_vuota;
	ricetta_vuota.id_ricetta = 0;

	if ((file = fopen(nome_file, "rb+")) == NULL) {		/*apertura del file in modalita' scrittura/lettura */
		printf("Errore nell'apertura %s",nome_file);
		return 0;		/* viene restituito 0 se il file non e' stato aperto */
	}
	else {
		fseek(file, sizeof(ricetta)* (id_ricetta - 1), SEEK_SET);					/*viene posizionato il puntare nel file */
		fwrite(&ricetta_vuota, sizeof(ricetta), 1, file);							/*ricetta_vuota viene scritto sul file*/

	}

	fclose(file);

	return 1;	/* viene restituito 1 se la scrittura e' andata a buon fine */

}



unsigned short int input_ricerca_ricetta() {
	unsigned short int scelta = 0;

	printf("Che tipo di ricerca vuoi effettuare?\n");
	printf("1) Ricerca per ID della ricetta\n");
	printf("2) Ricerca per ingrediente\n");
	printf("3) Ricerca per un insieme di ingredienti\n");
	printf("4) Esci\n");

	scelta = inserisci_input_intero("?", LUNGHEZZA_INPUT);

	//finquando scelta non e' compreso tra 1 e MAX_SCELTA_RICERCA verra' chiesto di reinserire il valore
	while(!is_compreso_tra(1, MAX_SCELTA_RICERCA, scelta)) {
		scelta = inserisci_input_intero("Il valore non corrisponde a quello delle possibili voci disponibili, reinserire: ", LUNGHEZZA_INPUT);
	}

	return scelta;
}



unsigned short int input_inserisci_id() {
	unsigned short int id = 0;

	printf("Inserisci ID delle ricetta da cercare: ");
	printf("\n");

	id = inserisci_input_intero("?", LUNGHEZZA_INPUT);

	printf("\n");
	return id;
}



void visualizza_ricetta(ricetta ricetta) {

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %3s | %40s | %9s | %12s | %27s | %5s | %11s| %30s |\n","ID", "NOME RICETTA", "N PERSONE", "CALORIE", "LINK PROCEDIMENTO", "TEMPO", "COMPLESSITA'", "INGREDIENTI");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	printf("| %3hu | %40s | %9hu | %7.2f kcal | %27s | %4hu' |",
			ricetta.id_ricetta,
			ricetta.nome_ricetta,
			ricetta.n_persone,
			ricetta.kcal,
			ricetta.link_procedimento,
			ricetta.tempo_preparazione);

	if (ricetta.complessita == BASSA) {
		printf(" %11s |", "BASSA" );
	} else if (ricetta.complessita == MEDIA) {
		printf(" %11s |", "MEDIA" );
	} else if (ricetta.complessita == ALTA) {
		printf(" %11s |", "ALTA" );
	}

	printf("%23s (%4s %1c) |\n", ricetta.ingredienti[0].nome_alimento, ricetta.ingredienti[0].quantita, ricetta.ingredienti[0].unita_misura);
	for (int j = 1; j < ricetta.numero_ingredienti; j++) {
		printf("| %3s | %40s | %9s | %12s | %27s | %5s | %11s |%23s (%4s %1c) |\n","","","","","","","", ricetta.ingredienti[j].nome_alimento, ricetta.ingredienti[j].quantita, ricetta.ingredienti[j].unita_misura);
	}

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


}



void input_alimento(char* nome_alimento){
	strcpy(nome_alimento, inserisci_input_caratteri_spazio("\nInserisci alimento da ricercare: ", LUNGHEZZA_NOME));
}


/**
 * Viene scandito il vettore di tipo ::ricetta, in particolare per gli elementi con "id_ricetta" > 0 vengono controllati
 * tutti gli elementi del vettore di tipo ::ingrediente presente nella struct ::ricetta, controntando il nome del ingrediente
 * con il nome dell'alimento da ricercare
 */
unsigned short int ricerca_ricetta_alimento(ricetta* ricettario, unsigned short int numero_ricette, char alimento[]) {
	unsigned short int i, j, flag = 0;

	for(i=0; i<numero_ricette; i++) {

		if(ricettario[i].id_ricetta > 0) {

			for(j=0; j<ricettario[i].numero_ingredienti; j++) {

				//uso strcasecmp per ignorare il fatto che le lettere dell'ingrediente siamo maiuscole o minuscole
				if(strcasecmp(alimento, ricettario[i].ingredienti[j].nome_alimento) == 0) {
					flag = 1;
					visualizza_ricetta(ricettario[ricettario[i].id_ricetta - 1]);
				}
			}

		}

	}

	return flag;
}


/**
 * @bug passare un valore negativo o uguale a 0 attraverso il parametro "max_insieme" causerebbe un mal funzionamento della funzione
 */
void input_insieme_alimenti(char insieme_alimenti[][LUNGHEZZA_NOME], unsigned short int max_insime) {
	unsigned short int i;

	printf("\n");
	for(i=0; i<max_insime; i++) {
		printf("Inserisci il %hu^ alimento da ricercare", i+1);
		strcpy(insieme_alimenti[i], inserisci_input_caratteri_spazio(": ", LUNGHEZZA_NOME));

	}
}


/**
 * Funzionamento analogo alla funzione ricerca_ricetta_alimento() con la differenza che abbiamo un contatore di occorrenze
 * degli ingredienti e un controllo su quest'ultimo.
 * Se il contatore è uguale al parametro numero_alimenti (cioe' il numero di alimenti che stiamo cercando) verra' visualizzata la ricetta in
 * formato tabellare, altrimenti non verra' visualizzata.
 */
unsigned short int cerca_ricetta_insieme(char insieme_alimenti[][LUNGHEZZA_NOME], unsigned short int numero_alimenti, ricetta* ricettario, unsigned short int numero_ricette)	 {
	unsigned short int i, j, k, flag = 0, occorrenze;

	for(i=0; i<numero_ricette; i++) {
		if(ricettario[i].id_ricetta > 0) {
			occorrenze = 0;

			for(j=0; j<ricettario[i].numero_ingredienti; j++) {


				for(k=0; k<numero_alimenti; k++) {
					if(strcasecmp(insieme_alimenti[k], ricettario[i].ingredienti[j].nome_alimento) == 0) {
						occorrenze++;
					}
				}
			}

			if(occorrenze == numero_alimenti) {
				flag = 1;
				visualizza_ricetta(ricettario[ricettario[i].id_ricetta - 1]);
			}

		}
	}

	return flag;
}



unsigned short int input_numero_alimenti() {
	unsigned short int numero;

	numero = inserisci_input_intero("\nInserisci il numero di alimenti da ricercare (min 2, max 7): ", LUNGHEZZA_INPUT);
	while(!is_compreso_tra(MIN_ALIMENTI_RICERCA, MAX_ALIMENTI_RICERCA, numero)) {
		numero = inserisci_input_intero("Reinserire valore: ", LUNGHEZZA_INPUT);
	}

	return numero;
}



unsigned short int ricerca_ricetta_kcal(ricetta* ricettario, unsigned short int numero_ricette, float kcal_da_cercare, unsigned short int is_ordinato) {
	unsigned short int count = 0, flag, centro, i;

	//controllo se il vettore e' ordinato in base alle kcal, se non lo e' lo ordino con la funzione quickSort()
	if (!is_ordinato) {
		quickSort(ricettario, 0, NUMERO_RICETTE-1);
	}

	//trovo il centro del vettore dividendo per 2
	centro = numero_ricette/DIVIDI_ARRAY;

	//se le calorie della ricetta nel mezzo sono >= delel kcal da cercare allora scandisco tutte le ricette da 0 fino al valore centrale, altrimenti cerco nella meta successiva
	if(ricettario[centro].kcal >= kcal_da_cercare) {

		for(i=0; i<centro; i++) {

			//controllo che sia una ricetta valida (id_ricetta > 0) e verifico se le kcal della ricetta presa in analisi siano <= alle kcal da cercare
			if(ricettario[i].id_ricetta > 0 && ricettario[i].kcal <= kcal_da_cercare) {
				visualizza_ricetta(ricettario[i]);
				count++;
			}

		}

	} else {

		for(i=centro; i<numero_ricette-1; i++) {

			//controllo che sia una ricetta valida (id_ricetta > 0) e verifico se le kcal della ricetta presa in analisi siano <= alle kcal da cercare
			if(ricettario[i].id_ricetta > 0 && ricettario[i].kcal <= kcal_da_cercare) {
				visualizza_ricetta(ricettario[i]);
				count++;
			}

		}

	}

	//se sono state trovate ricette con kcal <= kcal da cercare il contatore sara' maggiore di 0 e quindi imposto il flag a 1 (true), altrimenti lo imposto a 0 (false)
	if(count > 0) {
		flag = 1;
	} else flag = 0;

	return flag;
}



ricetta* copia_ricettario(ricetta* ricettario, unsigned short int numero_elementi) {
	unsigned short int i;
	//alloco la memoria necessaria per la copia del ricettario
	ricetta* ricettario_copiato = malloc( NUMERO_RICETTE * sizeof(ricetta));

	//copio valore per valore le ricette
	for(i=0; i<numero_elementi; i++) {
		ricettario_copiato[i] = ricettario[i];
	}

	return ricettario_copiato;
}



//fonte: https://www.geeksforgeeks.org/quick-sort/
// A utility function to swap two elements
void swap_ricette(ricetta* a, ricetta* b)
{
	ricetta t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (ricetta* ricettario, int l, int r)
{
	float pivot = ricettario[r].kcal; // pivot
	int i = (l - 1); // Index of smaller element

	for (int j = l; j <= r- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (ricettario[j].kcal <= pivot)
		{
			i++; // increment index of smaller element
			swap_ricette(&ricettario[i], &ricettario[j]);
		}
	}
	swap_ricette(&ricettario[i + 1], &ricettario[r]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
l --> Starting index,
r --> Ending index */
void quickSort(ricetta* ricettario, int l, int r)
{
	if (l < r)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(ricettario, l, r);

		// Separately sort elements before
		// partition and after partition
		quickSort(ricettario, l, pi - 1);
		quickSort(ricettario, pi + 1, r);
	}

}



