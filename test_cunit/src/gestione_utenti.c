#include "gestione_utenti.h"


unsigned short int mostra_utenti (char nome_file[]) {
	FILE* file;
	if ( (file = fopen (nome_file, "rb")) == NULL ) {	/*apertura del file in lettura*/
		printf("Errore nell'apertura %s",nome_file);
		return 0;
	}
	else {
		utente utente_letto;						/*variabile che conterra'  l'utente che verra'  stampato*/
		unsigned short int id_ultimo_utente = 0;  	/*identificativo dell'ultimo username letto dal file*/

		printf("\nScegli l'account con cui accedere:\n");
		printf("\t0 - Crea nuovo account\n");

		/* ciclo che legge i contenuti del file */
		while (!feof(file)){

			/* effettua una lettura di un utente dal file e lo assegna a utente_letto */
			short int caratteri_letti = fread (&utente_letto, sizeof(utente), 1, file);

			/* controlla se l'id e' > 0 poiche' per scelta progettuale gli id validi sono da 1 in poi */
			if (utente_letto.id_utente>0 && caratteri_letti>0) {
				stampa_utente (utente_letto);				/*viene stampato id e username di utente_letto*/
				id_ultimo_utente = utente_letto.id_utente;
			}
		}

		fclose(file);

		printf("\t? ");
		return id_ultimo_utente;	/* restituisce l'identificativo dell'ultimo username stampato*/
	}
}






unsigned short int stampa_utente (utente utente_letto) {
	short int caratteri_stampati = printf("\t%hu - %s\n", utente_letto.id_utente, utente_letto.nome );

	/*la printf stampera'  almento 6 caratteri, che sono quelli scritti nel primo parametro della printf,
	 * e se il nome utente non e' vuoto i caratteri_stampati saranno superiori a 6 */
	if (caratteri_stampati > 6){
		return 1;
	} else {
		return 0;	/*se restituisce 0 il nome utente e' vuoto*/
	}
}








unsigned short int aggiungi_utente (char nome_file[], char nome_utente[], unsigned short int id_ultimo_utente) {
	FILE *file;
	utente utente_aggiunto;			/*utente che verra'  scritto sul file*/

	utente_aggiunto.id_utente = id_ultimo_utente + 1;	/*id_ultimo_utente viene incrementato cosa'¬ da avere id sempre diversi nel file*/
	strcpy(utente_aggiunto.nome, nome_utente);			/*il nome_utente passato come parametro viene assegnato al nome di utente_aggiunto*/

	if ((file = fopen(nome_file, "rb+")) == NULL) {		/*apertura del file in modalita'  'append' */
		printf("Errore nell'apertura %s",nome_file);
		return 0;

	}
	else {
		fseek(file, sizeof(utente)* (utente_aggiunto.id_utente - 1), SEEK_SET);
		fwrite(&utente_aggiunto, sizeof(utente), 1, file);		/*utente_aggiunto viene scritto sul file*/
	}

	if(!fclose(file)){
		printf("\nUtente aggiunto!\n");
	}

	return utente_aggiunto.id_utente;	/* viene restituito l'identificativo dell'utente aggiunto al file */
}







unsigned short int seleziona_utente (char nome_file[]) {
	unsigned short int id_ultimo_utente;		/*identificativo dell'ultimo username letto dal file*/
	unsigned short int id_utente;				/* input dell'utente */
	unsigned short int input_corretto = 0;		/* flag che se e' 0 indica che il l'id_utente non e' valido, se e' 1 invece indica che e' valido */
	char nome_utente[LUNGHEZZA_NOME];		/*nome dell'utente che verra'  aggiunto*/

	id_ultimo_utente = mostra_utenti (nome_file);	/*stampa sottoforma di elenco gli utenti scritti sul file e assegna a id_ultimo_utente id dell'ultimo utente stampato*/

	/* ciclo che itera solo se l'id_utente in input non e' valido*/
	while (input_corretto == 0){
		id_utente = inserisci_input_intero ("", LUNGHEZZA_INPUT);	/* viene acquisito un intero valido e assegnato a id_utente*/

		if (id_utente == 0) {					/*se input da tastiera e' 0 deve essere aggiunto un nuovo utente*/

			unsigned short int id_nuovo_utente;		/*id dell'utente che verra'  aggiunto*/
			unsigned short int is_nome_utente_corretto = 0;		/* flag che se e' 0 indica che il l'id_utente non e' valido, se e' 1 invece indica che e' valido */

			do {

				printf("\nInserisci nome utente \n(deve avere tra %d e %d caratteri e non puo' contenere simboli o numeri) : ", MIN_LUNGHEZZA_USERNAME, MAX_LUNGHEZZA_USERNAME);
				fgets(nome_utente, LUNGHEZZA_NOME, stdin);

				svuota_buffer_input (nome_utente);		/*viene svuotato il buffer di input per evitare bug*/

				/*entra nell'if se il nome_utente acquisito da tastiera non contiene cifre o simboli,
				 * se la sua lunghezza e' >=5 e <=15
				 * e se il nome_utente non esiste sia'  per altri utenti sul file */
				if ( is_stringa_caratteri (nome_utente) &&
						is_compreso_tra (MIN_LUNGHEZZA_USERNAME, MAX_LUNGHEZZA_USERNAME, strlen(nome_utente) ) &&
						!is_utente_esistente (nome_utente, nome_file) ) {
					is_nome_utente_corretto = 1;
				}

			} while( !is_nome_utente_corretto );	/* ciclo che itera solo se il nome_utente in input non e' valido*/

			id_nuovo_utente = aggiungi_utente (nome_file, nome_utente, id_ultimo_utente);	/*l'utente viene scritto sul file*/

			input_corretto = 1;
			id_utente = id_nuovo_utente;

		} else if (ricerca_utente (nome_file, id_utente) != NULL ) {	/*altrimenti se l'id in input esite sul file*/

			input_corretto = 1;

		} else{
			printf("Valore errato! Reinserisci id utente: ");
		}
	}

	strcpy (nome_utente, ricerca_utente (nome_file, id_utente));
	printf("\n\"Benvenuto %s!\"", nome_utente);

	return id_utente;	/*viene restituito l'id scelto*/

}









unsigned short int is_utente_esistente (char nome_utente[], char nome_file[]) {
	FILE* file;
	if ( (file = fopen (nome_file, "rb")) == NULL ) {	/*apertura del file in lettura */
		printf("Errore nell'apertura %s",nome_file);
		return 0;
	}
	else {
		utente utente_letto;					/*utente che verra'  letto dal file*/
		unsigned short int is_esistente = 0;	/* flag che se e' 0 indica che il nome_utente non esiste sul file, se e' 1 invece indica che esiste */

		/* ciclo che legge i contenuti del file */
		while (!feof(file)){

			/* effettua una lettura di un utente dal file e lo assegna a utente_letto */
			short int caratteri_letti = fread (&utente_letto, sizeof(utente), 1, file);

			/* controlla se il nome_utente corrisponde al nome dell'utente letto */
			if (!strcasecmp(utente_letto.nome, nome_utente) && caratteri_letti>0) {
				is_esistente = 1;
			}
		}

		if (is_esistente){
			printf("Nome utente gia'  esistente, reinserire!\n ");
		}

		return is_esistente;	/*viene restituito il valore del flag (0 o 1)*/
	}
}







char* ricerca_utente (char nome_file[], unsigned short int id_utente) {

	FILE *file;
	utente utente_letto;			/*utente che verra'  letto dal file*/
	//unsigned short int trovato = 0;

	char* nome_utente = (char*) calloc(LUNGHEZZA_NOME, sizeof(char));		/*allocazione dinamica della memoria per la stringa nome_utente*/

	if ((file = fopen(nome_file, "rb")) == NULL) {			/*apertuta del file in lettura*/
		printf("Errore nell'apertura %s",nome_file);
		return NULL;
	}
	else {

		fseek(file, sizeof(utente)* (id_utente - 1), SEEK_SET);
		fread(&utente_letto, sizeof(utente), 1, file);

		fclose(file);
	}

	if (is_compreso_tra (1, NUMERO_UTENTI, utente_letto.id_utente)) {
		strcpy (nome_utente, utente_letto.nome);
		return nome_utente;
	} else {
		return NULL;
	}
}





unsigned short int input_cancella_utente (char nome_file_utenti[], char nome_file_menu[], unsigned short int id_utente, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri) {

	char risposta[LUNGHEZZA_INPUT];
	char nome_utente[LUNGHEZZA_NOME];
	strcpy (nome_utente, ricerca_utente (nome_file_utenti, id_utente));

	printf("\nVuoi cancellare l'utente corrente \"%s\" e tutti i suoi dati? (y/n) ", nome_utente);
	fgets (risposta, LUNGHEZZA_INPUT, stdin);
	svuota_buffer_input(risposta);				/*svuota il buffer di input per evitare bug*/

	/*Entra nell'if se l'input dell'utente e' una parola tra 'y', 'Y', 'yes' 'Yes', 'YES'*/
	if ( !strcmp(risposta,"y") || !strcmp(risposta,"Y") || !strcmp(risposta,"yes") || !strcmp(risposta,"Yes") || !strcmp(risposta,"YES")) {

		cancella_utente (nome_file_utenti, id_utente);
		cancella_menu_settimanale_utente (nome_file_menu, id_utente, menu_settimanale, numero_menu_giornalieri);
		printf("Utente cancellato.\n\n");
		return seleziona_utente ("elenco_utenti.bin");	/*viene restituito l'id digitato da tastiera a con cui effettuare il nuovo login*/

	} else {
		printf("Cancellazione annullata.\n");   /*se la risposta e' diversa da 'y', 'Y', 'yes' 'Yes', 'YES'*/
		return id_utente;						/*viene restituito l'id utente passato come parametro*/
	}
}

unsigned short int cancella_utente (char nome_file[], unsigned short int id_utente) {

	//utente utente_cancellato;			/*utente che verra'  letto dal file*/
	utente utente_vuoto;				/*utente che verra'  sovrascritto a quello da cancellare*/

	/*inizializzazione dell'utente vuoto*/
	utente_vuoto.id_utente = 0;
	strcpy (utente_vuoto.nome, "");

	FILE *file;

	if ((file = fopen(nome_file, "rb+")) == NULL) {		/*apertura del file in lettura/scrittura*/
		printf("Errore nell'apertura %s",nome_file);
		return 0;
	}
	else {

		fseek(file, sizeof(utente)* (id_utente - 1), SEEK_SET);
		fwrite(&utente_vuoto, sizeof(utente), 1, file);

	}

	fclose(file);

	return 1;
}





unsigned short int cancella_menu_settimanale_utente (char nome_file_menu[], unsigned short int id_utente, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri) {

	menu_giornaliero menu_vuoto;				/*menu che verra'  sovrascritto a quello da cancellare*/

	/*inizializzazione del menu vuoto*/
	menu_vuoto.id_menu = 0;
	menu_vuoto.id_utente = 0;

	for (int j=0; j<numero_menu_giornalieri; j++) {
		if ( menu_settimanale[j].id_menu != 0 && menu_settimanale[j].id_utente == id_utente ) {
			menu_settimanale[j] = menu_vuoto;
		}
	}

	FILE *file;

	if ((file = fopen(nome_file_menu, "rb+")) == NULL) {		/*apertura del file in modalita'  scrittura/lettura */
		printf("Errore nell'apertura %s",nome_file_menu);
		return 0;		/* viene restituito 0 se il file non e' stato aperto */
	}
	else {
		fseek(file, (sizeof(menu_giornaliero) * NUMERO_GIORNI_SETTIMANA * (id_utente -1)) , SEEK_SET);					/*viene posizionato il puntare nel file */
		for (int i=0; i<NUMERO_GIORNI_SETTIMANA; i++) {
			fwrite(&menu_vuoto, sizeof(menu_giornaliero), 1, file);							/*menu_vuoto viene scritto sul file*/
		}
	}

	fclose(file);

	return 1;	/* viene restituito 1 se la scrittura e' andata a buon fine */
}



