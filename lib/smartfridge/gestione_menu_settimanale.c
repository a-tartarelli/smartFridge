#include <smartfridge/gestione_menu_settimanale.h>


unsigned short int visualizza_menu_settimanale (const menu_giornaliero menu_settimanale[], unsigned short int numero_menu_giornalieri, const ricetta* ricettario, unsigned short int id_utente) {

	unsigned short int elementi_stampati = 0;	/* contatore degli alimenti stampati */
	unsigned short int i_ricetta;				/* variabile che memorizza l'indice della ricetta corrispondente al nome del pasto d avisualizzare per ogni menu */

	printf("\n**********************************************************************************************************************\n");
	printf("**************************************************  MENU SETTIMANALE  ************************************************\n");
	printf("**********************************************************************************************************************\n\n");

	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("| %3s | %9s | %22s | %12s | %7s | %46s |\n","ID", "ID UTENTE", "GIORNO", "KCAL TOT" , "N PASTI", "PASTI" );
	printf("----------------------------------------------------------------------------------------------------------------------\n");

	for (int i = 0; i < numero_menu_giornalieri; i++) {

		if (menu_settimanale[i].id_menu > 0 && menu_settimanale[i].id_utente == id_utente) {		/*stampa il menu solo se l'id e' valido e se l'utente e' quello corrente*/


			printf("| %3hu | %9hu | %9s (%2hu/%2hu/%4hu) | %7.2f kcal | %7hu |",
					menu_settimanale[i].id_menu,
					menu_settimanale[i].id_utente,
					menu_settimanale[i].data_menu.giorno_settimana,
					menu_settimanale[i].data_menu.giorno,
					menu_settimanale[i].data_menu.mese,
					menu_settimanale[i].data_menu.anno,
					menu_settimanale[i].kcal_giornaliere,
					menu_settimanale[i].numero_pasti);

			i_ricetta = indice_id_ricetta (ricettario, NUMERO_RICETTE, menu_settimanale[i].pasti[0].id_ricetta);	/* calcola l'indice del ricettario che ha per come id il campo menu_settimanale[i].pasti[0].id_ricetta*/
			printf("%41s (x%2hu) |\n", ricettario[ i_ricetta ].nome_ricetta, menu_settimanale[i].pasti[0].n_persone);	/* stampa il nome del pasto e il numero di persone */

			for (int j = 1; j < menu_settimanale[i].numero_pasti; j++) {
				i_ricetta = indice_id_ricetta (ricettario, NUMERO_RICETTE, menu_settimanale[i].pasti[j].id_ricetta);	/* calcola l'indice del ricettario che ha per come id il campo menu_settimanale[i].pasti[j].id_ricetta*/
				printf("| %3s | %9s | %22s | %12s | %7s | %40s (x%2hu) |\n", "","","","","", ricettario[ i_ricetta ].nome_ricetta, menu_settimanale[i].pasti[j].n_persone );	/* stampa a capo il nome del pasto e il numero di persone */
			}

			printf("---------------------------------------------------------------------------------------------------------------------\n");

			elementi_stampati++;
		}
	}

	if (elementi_stampati == 0) {
			printf ("\tOPS! Non c'e' alcun menu settimanale per questo utente.\n");
		}

	return elementi_stampati;	/*restituisce il numero degli alimenti stampati*/

}


/**
 *
 * @warning quasta funzione consente di aprire la pagina web del procedimento di una ricetta solo s eil programam viene eseguito su un sistema operativo windows
 */
void input_prepara_ricetta (char* nome_file, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, const ricetta ricettario[], unsigned short int numero_ricette, alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int id_utente, data data_odierna) {
	menu_giornaliero menu_odierno;

	unsigned short int input_id_ricetta;	/* id della ricetta da preparare che verra' inserito dall' utente */
	unsigned short int indice_ricetta;		/* indice della ricetta da preparare */
	unsigned short int numero_persone;		/* numero di persone per cui preparare la ricetta che verra' inserito dall'utente*/
	unsigned short int risposta;			/* flag che se 1 apre la pagina del procedimento della ricetta, se 0 non la apre */
	char link[LUNGHEZZA_NOME];				/* stringa che conterra' il link del procedimento della ricetta da preparare */



	unsigned short int indice_menu_odierno = get_ultimo_indice_menu (menu_settimanale, numero_menu_giornalieri) + 1 ;	/* viene assegnato l'indice dove deve essere memorizzato il menu a indice_menu_odierno */

	menu_odierno.id_menu = get_nuovo_id_menu (menu_settimanale, numero_menu_giornalieri);	/* viene assegnato un nuovo id diverso dagli altri a menu odierno */
	menu_odierno.id_utente = id_utente;
	menu_odierno.data_menu = data_odierna;
	menu_odierno.numero_pasti = 0;
	menu_odierno.kcal_giornaliere = 0;

	/* ciclo che verifica se nel vettore esiste gia' una menu per lo stesso utente nello stesso giorno*/
	for (int i = 0; i < numero_menu_giornalieri; i++) {
		if ( menu_settimanale[i].id_utente == id_utente && !strcmp(menu_settimanale[i].data_menu.giorno_settimana, data_odierna.giorno_settimana) ) {	/* se esiste viene copiato l'indice e l'id*/
			indice_menu_odierno = i;
			menu_odierno.id_menu = menu_settimanale[i].id_menu;

			if (confronta_date (menu_settimanale[i].data_menu, data_odierna) == 2){		/* se la data e' quella odierna viene copiato tutto il menu in menu_odierno*/
				menu_odierno = menu_settimanale[i];
			}
		}
	}


	printf("\n*************************************************************\n");
	printf("********************  PREPARA RICETTA  ********************\n");
	printf("*************************************************************\n\n");

	/* l'utente sceglie un pasto e per quante persone prepararlo e poiche input_id_ricetta e numero_persone sono passati per riferimento, verranno modificati */
	input_scelta_pasto (ricettario, numero_ricette, &input_id_ricetta, &numero_persone);

	indice_ricetta = indice_id_ricetta (ricettario, numero_ricette, input_id_ricetta); 	/* viene trovato quale elemento nel vettore ricettario ha l'id inserito e viene salvato in indice_ricetta*/

	/* se la ricetta e' preparabile, cioe se ci sono abbastanza alimenti in frigo per preparare la ricetta */
	if (is_ricetta_preparabile (ricettario[indice_ricetta], alimenti_frigo, numero_alimenti, numero_persone)) {

		risposta = inserisci_input_intero("Vuoi visualizzare il procedimento? (0 = no / 1 = si): ", LUNGHEZZA_RISPOSTA);

		printf("\n");
		while (!is_compreso_tra(0, 1, risposta)) {																		/*itera finche' non viene data una risposta giusta*/
			risposta = inserisci_input_intero("Inserisci un valore che sia (0 = no o 1 = si): ", LUNGHEZZA_RISPOSTA);
		}

		if(risposta == 1) {
			sprintf (link,"explorer %s",ricettario[indice_ricetta].link_procedimento);	/* se la risposta e' 1 */
			system(link);																/* verra' aperto il browser e verra' visualizzata la pagina web di ricettario[indice_ricetta].link_procedimento*/
		}

		menu_odierno.pasti[menu_odierno.numero_pasti].id_ricetta = input_id_ricetta;	/*l'id della ricetta scelta viene asseganto al pasto successivo rispetto all'ultimo valido di menu_odierno.pasti */
		menu_odierno.pasti[menu_odierno.numero_pasti].n_persone = numero_persone;		/*il numero di persone per cui preparare il pasto viene asseganto al pasto successivo rispetto all'ultimo valido di menu_odierno.pasti */

		menu_odierno.numero_pasti++;										/* viene incrementato il nuemro di pasti validi */
		menu_odierno.kcal_giornaliere += numero_persone * ricettario[indice_ricetta].kcal / ricettario[indice_ricetta].n_persone;	/* vengono calcolate le kcal totali in base al numero di persone per cui preparare la ricetta */
		menu_settimanale[indice_menu_odierno] = menu_odierno;																		/* viene aggiunto il menu al vettore di menu giornalieri */

		printf("DOSI DEGLI INGREDIENTI di \"%s\" per %hu persone:\n", ricettario[indice_ricetta].nome_ricetta, numero_persone);

		for (int i = 0; i < ricettario[indice_ricetta].numero_ingredienti; i++) {
				printf("\t- %s ", ricettario[indice_ricetta].ingredienti[i].nome_alimento);	/* stampa il nome dell'ingrediente */

				if( strcasecmp(ricettario[indice_ricetta].ingredienti[i].quantita, "qb") ) {
					printf("(%.2f %c)\n", (float) numero_persone * atof(ricettario[indice_ricetta].ingredienti[i].quantita) / ricettario[indice_ricetta].n_persone ,	/* stampa la dose in grammi */
										   ricettario[indice_ricetta].ingredienti[i].unita_misura);
				} else {
					printf("(qb)\n");
				}
		}

		printf("\nLa ricetta e' stata preparata, buon appetito!\n\n");
		elimina_ingredienti_usati (ricettario[indice_ricetta], numero_persone, alimenti_frigo, numero_alimenti, STAMPA_ALIMENTI_USATI);	/* vengono eliminati gli ingredienti usati dal frigo*/
		aggiungi_menu_giornaliero ( nome_file, menu_odierno, data_odierna );			/* viene aggiunto il menu giornaliero anche sul file */
	}


}




/* Funzione booleana che riceve come paramentri una stringa (nome_file), un dato di tipo menu_giornaliero (menu_odierno), e un intero (id_utente) e restituisce un intero.
 * La funzione aprira'a' in modalita'a' scrittura il file il cui nome e' stato passato come parametro
 * e scrivera'a' su di esso un dato menu giornaliero che e' stato passato come parametro.
 * La funzione restituita'a' 1 se la scrittura e' andata a buon fine;
 * invece restituira'a' 0 se il file non e' stato aperto e l'alimento non e' stato scritto */


unsigned short int aggiungi_menu_giornaliero ( char* nome_file, menu_giornaliero menu_odierno, data data_odierna ) {
	FILE *file;

	if ((file = fopen(nome_file, "rb+")) == NULL) {		/*apertura del file in modalita'a' scrittura */
        printf("Errore nell'apertura del file %s",nome_file);
		return 0;		/* viene restituito 0 se il file non e' stato aperto */
	}
	else {
		fseek(file, (sizeof(menu_giornaliero) * NUMERO_GIORNI_SETTIMANA * (menu_odierno.id_utente -1)) +  get_giorno_settimana_intero (data_odierna) * sizeof(menu_giornaliero) , SEEK_SET);					/*viene posizionato il puntare nel file */
		fwrite(&menu_odierno, sizeof(menu_giornaliero), 1, file);		/*menu_odierno viene scritto sul file*/
	}

	fclose(file);


	return 1;	/* viene restituito 1 se la scrittura e' andata a buon fine */

}



unsigned short int is_menu_esistente (const menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, unsigned short int id_menu, unsigned short int id_utente) {

	int i;
	for ( i=0; i<numero_menu_giornalieri; i++) {
		if (id_menu != 0 && menu_settimanale[i].id_menu == id_menu && menu_settimanale[i].id_utente == id_utente) {	  /* se id_menu e' valido e menu_settimanale[i] ha i campi id_utente e id_menu uguali a quelli passati come parametri */
			return 1;	/* il menu, che ha id_menu come id, esiste per l'utente che ha id_utente come id*/
		}
	}

	return 0;
}




unsigned short int indice_id_menu (const menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, unsigned short int id_menu) {

	int i;
	for ( i=0; i<numero_menu_giornalieri; i++) {
		if (id_menu != 0 && menu_settimanale[i].id_menu == id_menu ) {		/* se id_menu e' valido e menu_settimanale[i] ha il campo id_menu uguale a quello passato come parametro */
			return i;		/*viene restituito l'indice corrispindente*/
		}
	}

	return i;
}



/* Funzione  che riceve come paramentri un vettore di tipo menu_giornaliero (menu_settimanale) e la sua lunghezza e restituisce un intero.
 * La funzione eseguira'a' un ciclo per scandire tutti gli elementi del vettore passato come paramentro e
 * se l'elemento ha un id valido, l'indice del vettore viene salvato in una variabile.
 * Alla fine del ciclo la funzione restituira'a' l'ultimo indice che contiene un menu giornaliero corretto */


unsigned short int get_ultimo_indice_menu (const menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri) {

	unsigned short int ultimo_i = 0;
	int i;
	for ( i=0; i<numero_menu_giornalieri; i++) {
		if (menu_settimanale[i].id_menu > 0) {		/*ultimo_i vien modificato finche' si trova nel vettore un elemento con id valido*/
			ultimo_i = i;
		}
	}

	return ultimo_i;
}





/* Funzione  che riceve come paramentri un vettore di tipo menu_giornaliero (menu_settimanale) e la sua lunghezza e restituisce un intero.
 * La funzione prende l'id dell'ultimo elemento valido del vettore e lo restituira'a' come valore di ritorno */


unsigned short int get_nuovo_id_menu (const menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri) {

	unsigned short int max_id = menu_settimanale[0].id_menu;	/* il massimo viene inizializzato con l'id del primo elemento */

	for ( int i=0; i<numero_menu_giornalieri; i++) {
		if (menu_settimanale[i].id_menu > 0 && menu_settimanale[i].id_menu > max_id) {		/* viene cercato il massimo nel vettore */
			max_id = menu_settimanale[i].id_menu;
		}
	}

	return ++max_id;		/* il massimo viene incrementato e  viene restituito*/
}



unsigned short int is_ricetta_preparabile (ricetta ricetta_da_preparare, const alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int numero_persone) {

	unsigned short int occorrenze_alimento;			/* contaatore delle occorrenze di ciascun alimento */
	unsigned short int is_preparabile = 1;			/* flag che se 1 indica che la ricetta e' preparabile, se 0 indica che la ricetta non e' preparabile */
	float quantita_disponibile;						/* quantita' in grammi disponibile per ciascun alimento in frigo */
	float quantita_necessaria;						/* quantita in grammi di ciascun ingrediente necessaria per preparare la ricetta */

	printf("\n");

	for (int i=0; i<ricetta_da_preparare.numero_ingredienti; i++) {		/* itera sugli ingredienti della ricetta da preparare*/
		occorrenze_alimento = 0;
		quantita_disponibile = 0;

		for (int j=0; j<numero_alimenti; j++) {

			if (alimenti_frigo[j].id_alimento > 0){	/* ciclo che verifica la quantita disponibile e le occorrenze dell'ingrediente in frigo */
				if ( !strcasecmp (ricetta_da_preparare.ingredienti[i].nome_alimento, alimenti_frigo[j].nome_alimento) ) {	/* quando viene trovato l'ingrediente nel frigo attraveros una corrispondenza per nome*/
					occorrenze_alimento++;																					/* vengono incrementate le occorrenze */
					quantita_disponibile += alimenti_frigo[j].numero_pezzi * alimenti_frigo[j].peso_unitario;				/* e la quantita' disponibile */
				}
			}
		}

		quantita_necessaria = (float) numero_persone * atof(ricetta_da_preparare.ingredienti[i].quantita) / ricetta_da_preparare.n_persone ; /* viene calcolata la quantita' necessaria dell'ingrediente per preparare la ricetta */

		if (occorrenze_alimento == 0) {		/* se l'ingrediente non c'e proprio nel frigo */
			printf("ATTENZIONE: L'ingrediente '%s' non e' disponibile in frigo.\n", ricetta_da_preparare.ingredienti[i].nome_alimento);
			is_preparabile = 0;

		} else if ( quantita_disponibile < quantita_necessaria) {		/* se l'ingrediente c'e nel frigo ma non in quantita' sufficenti */
			printf("ATTENZIONE: L'ingrediente '%s' e' disponibile ma non in quantita'a' sufficenti (%.2f g ma al ricetta ne richede %.2f).\n", ricetta_da_preparare.ingredienti[i].nome_alimento, quantita_disponibile, quantita_necessaria);
			is_preparabile = 0;
		}

	}

	return is_preparabile;	/* restituisce  se 1 che la ricetta e' preparabile,  0 se la ricetta non e' preparabile */
}



void input_scelta_pasto (const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int* input_id_ricetta, unsigned short int* numero_persone) {

	printf ("\nScegli una ricetta:\n");
	for (int i = 0; i < numero_ricette; i++) {
		if (ricettario[i].id_ricetta > 0) {		/*stampa la ricetta solo se l'id e' valido*/
			printf("\t%hu - %s\n", ricettario[i].id_ricetta, ricettario[i].nome_ricetta);
		}
	}

	*input_id_ricetta = inserisci_input_intero ("? ", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido alla locazione puntata da input_id_ricetta*/

	/*ciclo che itera finche' is_ricetta_esistente e' 0, cioe' fin quando l'input non e' un id esistente nel vettore*/
	while ( !is_ricetta_esistente(ricettario, numero_ricette, *input_id_ricetta) ) {

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */
		*input_id_ricetta = inserisci_input_intero ("", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido alla locazione puntata da input_id_ricetta*/
	}


	*numero_persone = inserisci_input_intero("\nPer quante persone vuoi preparare la ricetta? ", LUNGHEZZA_INPUT);	/*viene assegnato un intero valido alla locazione puntata da numero_persone*/

	while (!is_compreso_tra(1, MAX_PERSONE, *numero_persone)) {
		*numero_persone = inserisci_input_intero("Il valore deve essere compreso tra 1 e 10, reinserire valore: ", LUNGHEZZA_INPUT);	/*viene assegnato un intero valido alla locazione puntata da numero_persone*/
	}

}



void input_modifica_menu ( char* nome_file, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, const ricetta* ricettario, unsigned short int numero_ricette, alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int id_utente, data data_corrente ) {

	printf("\n*************************************************************\n");
	printf("****************  MODIFICA MENU SETTIMANALE  ****************\n");
	printf("*************************************************************\n\n");

	menu_giornaliero menu_modificato;			/* variabile che memorizza il menu gironaliero che verra' modificato*/
	alimento* copia_frigo;						/* puntatore al un vettore che sara' la copia esatta di alimenti_frigo*/
	unsigned short int indice_mod;				/*indice dell'elemento del vettore da modificare*/
	unsigned short int vecchio_indice_ricetta;	/* indice della ricetta del pasto da modificare */
	unsigned short int nuovo_indice_ricetta;    /* indice della ricetta da sostituire al precedente pasto */
	unsigned short int nuovo_numero_persone;	/* numero di persone per cui deve essere preparato il nuovo pasto */
	unsigned short int vecchio_numero_persone;	/* numero di persone per cui e' stata preparato il pasto da modificare */
	unsigned short int pasto_da_modificare;		/* id della ricetta del pasto da modificare */
	unsigned short int is_scelta_corretta = 0;	/*flag che se e' 0 indica che la scelta non e' corretta, se e' 1 vuol dire che la scelta e' corretta*/
	unsigned short int is_menu_vuoto = 1;		/*flag che se e' 0 indica che il menu settimanale per l'utente passato come parametro ha qualche menu giornaliero, se e' 1 vuol dire che non ha nessun menu giornaliero */
	unsigned short int is_menu_modificato = 1;	/*flag che se e' 0 indica che non e' stato possibile modificare il menu, se e' 1 vuol dire e' stato modificato*/
	unsigned short int input_id_ricetta;		/* id della ricetta da preparare che verra' inserito dall' utente */



	printf ("Quale menu giornaliero vuoi modificare?\n");
	for (int i = 0; i < numero_menu_giornalieri; i++) {
		if (menu_settimanale[i].id_menu > 0 && menu_settimanale[i].id_utente == id_utente) {
			printf("\t%hu - %s\n", menu_settimanale[i].id_menu, menu_settimanale[i].data_menu.giorno_settimana);
			is_menu_vuoto = 0;
		}
	}

	if (is_menu_vuoto) {
		printf ("\tOPS! Non c'e' alcun menu giornaliero per questo utente.\n");
	} else {
		menu_modificato.id_menu = inserisci_input_intero ("? ", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido all'id menu*/

		/*ciclo che itera finche' is_menu_esistente e' 0, cioe' fin quando l'input non e' un id esistente nel vettore*/
		while ( !is_menu_esistente(menu_settimanale, numero_menu_giornalieri, menu_modificato.id_menu, id_utente) ) {

			printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */
			menu_modificato.id_menu = inserisci_input_intero ("", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido all'id menu*/
		}

		indice_mod = indice_id_menu (menu_settimanale, numero_menu_giornalieri, menu_modificato.id_menu);	/* viene trovato l'indice del menu giornaliero da modificare in base all'id */
		menu_modificato = menu_settimanale[indice_mod]; /*tutti i campi dell'elemento del vettore da modificare vengono copiati in menu_modificato*/

		printf ("\nQuale campo vuoi modificare?\n");
		printf ("\t1- Id utente\n"
				"\t2- Pasto\n"
				"? ");

		short int scelta = inserisci_input_intero("", LUNGHEZZA_INPUT);


		/* ciclo che si ripete finche' l'utente non inserisce un input diverso da 1 o 2 */
		/* ad ogni iterazione verra'a' chiesto un nuovo input all'utente */

		while( is_scelta_corretta == 0 ){

			switch(scelta){						/* switch che eseguira'a' un operazione diversa in base all'input dell'utente */

			case 1:		/* se viene scelto di modificare l'id utente*/

				menu_modificato.id_utente = inserisci_input_intero("\nID utente a cui attribuire il menu: ", LUNGHEZZA_INPUT);

				/* ciclo che itera finche' non viene inserito un id utenet esistente e diverso da id_utente */
				while (ricerca_utente ("files/elenco_utenti.bin", menu_modificato.id_utente) == NULL || menu_modificato.id_utente == id_utente) {
					menu_modificato.id_utente = inserisci_input_intero("L'id utente deve essere valido e diverso da se stesso! Reinserire: ", LUNGHEZZA_INPUT);
				}

				is_menu_modificato = modifica_giorno (nome_file, menu_modificato, menu_settimanale, numero_menu_giornalieri, indice_mod, id_utente);	/* viene modificato l'id utente e l'esito viene assegnato a is_menu_modificato*/

				if (is_menu_modificato) {

					printf("\nMenu' di %s aggiunto all'utente %hu.\n",menu_modificato.data_menu.giorno_settimana, menu_modificato.id_utente);

				} else {

					printf("\nImpossibile aggiungere il menu' di %s all'utente %hu poiche' ne ha uno piu' recente.\n",menu_modificato.data_menu.giorno_settimana, menu_modificato.id_utente);
				}
				is_scelta_corretta = 1;
				break;

			case 2:	/* se viene scelto di modificare un pasto */


				printf ("\nQuale tra i pasti del menu' selezionato vuoi modificare?\n");
				for (int i=0; i<menu_settimanale[indice_mod].numero_pasti; i++) {				/* ciclo che stampa i nomi dei pasti del menu giornaliero selezionato */
					pasto_da_modificare = menu_settimanale[indice_mod].pasti[i].id_ricetta;
					printf("\t%hu - %s (x%2hu)\n", i, ricettario[ indice_id_ricetta (ricettario, numero_ricette, pasto_da_modificare) ].nome_ricetta, menu_settimanale[indice_mod].pasti[i].n_persone );
				}

				pasto_da_modificare = inserisci_input_intero ("? ", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido*/

				/* ciclo che itera finche' non viene inserito un pasto valido */
				while ( !is_compreso_tra(0, menu_settimanale[indice_mod].numero_pasti-1, pasto_da_modificare) ) {

					printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */
					pasto_da_modificare = inserisci_input_intero ("", LUNGHEZZA_INPUT );
				}

				vecchio_numero_persone = menu_settimanale[indice_mod].pasti[pasto_da_modificare].n_persone;		/* viene memorizzato il numero di persone per cui e' stata preparato il pasto da modificare */
				vecchio_indice_ricetta = indice_id_ricetta (ricettario, numero_ricette, menu_settimanale[indice_mod].pasti[pasto_da_modificare].id_ricetta); /* viene memorizzato l'indice della ricetta del pasto da modificare */

				copia_frigo = copia_vettore_alimenti (alimenti_frigo, numero_alimenti);	/* viene copiato il vettore alimenti_frigo e il puntatore della copia viene asseganto a copia_frigo */

				/* gli ingredienti del pasto da modificare vengono rimessi nel vettore di alimenti copiato */
				rimetti_alimenti_in_frigo (copia_frigo, numero_alimenti, ricettario, numero_ricette, vecchio_indice_ricetta, vecchio_numero_persone, NON_STAMPA_ALIMENTI_RIMESSI);
				is_alimenti_scaduti  ( "files/elenco_alimenti.bin", copia_frigo, numero_alimenti, data_corrente );	/*se qualche alimento e' scaduto, verra' tolto dal vettore copia_frigo*/

				/* l'utente sceglie un pasto e per quante persone prepararlo e poiche input_id_ricetta e nuovo_numero_persone sono passati per riferimento, verranno modificati */
				input_scelta_pasto (ricettario, numero_ricette, &input_id_ricetta, &nuovo_numero_persone);

				nuovo_indice_ricetta = indice_id_ricetta (ricettario, numero_ricette, input_id_ricetta);	/* viene calcolato l'indice della nuova ricetta che si vuole preparare*/

				/* viene modificato il pasto del menu giornaliero sia nel vettore che su file e l'esito viene assegnato a is_menu_modificato*/
				is_menu_modificato = modifica_pasto (nome_file, indice_mod, menu_settimanale, numero_menu_giornalieri, ricettario, numero_ricette, copia_frigo, numero_alimenti, input_id_ricetta, vecchio_numero_persone, nuovo_numero_persone, vecchio_indice_ricetta, nuovo_indice_ricetta, pasto_da_modificare);

				if (is_menu_modificato) {			/* se il pasto puo' essere modificato, le modifiche vengono applicate effettivamente al vettore alimenti_frigo*/

					rimetti_alimenti_in_frigo (alimenti_frigo, numero_alimenti, ricettario, numero_ricette, vecchio_indice_ricetta, vecchio_numero_persone, STAMPA_ALIMENTI_RIMESSI);
					elimina_ingredienti_usati (ricettario[nuovo_indice_ricetta], nuovo_numero_persone, alimenti_frigo, numero_alimenti, STAMPA_ALIMENTI_USATI);
					is_alimenti_scaduti  ( "files/elenco_alimenti.bin", alimenti_frigo, numero_alimenti, data_corrente );

					printf("\nIl pasto e' stato sostituito correttamente al precedente!\n");
				}

				is_scelta_corretta = 1;
				break;


			default:
				printf("Valore errato! Reinserire: ");
				scelta = inserisci_input_intero("", LUNGHEZZA_INPUT);
			}
		}

	}
}



void elimina_ingredienti_usati (ricetta ricetta_da_preparare, unsigned short int numero_persone, alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int stampa_alimenti_usati) {

	float quantita_necessaria;	/* quantita in grammi di ciascun ingrediente necessaria per preparare la ricetta */

	printf("\n");
	for (int i=0; i<ricetta_da_preparare.numero_ingredienti; i++) {		/* ciclo che itera sugli ingredienti della ricetta da preparare*/

		quantita_necessaria = (float) numero_persone * atof(ricetta_da_preparare.ingredienti[i].quantita) / ricetta_da_preparare.n_persone ;		/* viene calcolata la quantita' necessaria */

		for (int j=0; j<numero_alimenti; j++) {
			if (alimenti_frigo[j].id_alimento > 0){
				if ( !strcasecmp (ricetta_da_preparare.ingredienti[i].nome_alimento, alimenti_frigo[j].nome_alimento) ) {	/* se viene trovata una corrispondenza dell'ingredente con gli alimenti nel frigo */

					 if (quantita_necessaria >= (alimenti_frigo[j].numero_pezzi * alimenti_frigo[j].peso_unitario) ) {		/* se la quantita' necessaria e' superiore rispetto alla quantita' dell'alimento presente nel frigo */

						quantita_necessaria -= alimenti_frigo[j].numero_pezzi * alimenti_frigo[j].peso_unitario;			/* la quantita' necessaria viene decrementata */

						if (stampa_alimenti_usati == 1) {

							printf("L'alimento %hu '%s' e' stato consumato completamente, pertanto non e' piu' presente in frigo.\n",alimenti_frigo[j].id_alimento, alimenti_frigo[j].nome_alimento);
						}

						cancella_alimento ( "files/elenco_alimenti.bin", alimenti_frigo[j] );					/* e l'alimento viene tolto sia dal file*/
						alimenti_frigo[j].id_alimento = 0;												/* che dal vettore alimenti_frigo (azzerando id e quantita')*/
						alimenti_frigo[j].numero_pezzi = 0;

					} else if (quantita_necessaria > 0){		/* Altrimneti se la quantita' necessaria e' < della quantita' dell'alimento presente nel frigo ma e' > 0*/
																/* deve essere decrementato il numero di pezzi disponibili dell'alimento */
																/* e anche se la quantita' necessaria non equivale completamente alla quantita' di un pezzo, per scelta progettuale viene decrementato */
						short int pezzi_consumati = 1;
						while ( quantita_necessaria > alimenti_frigo[j].peso_unitario) {
							alimenti_frigo[j].numero_pezzi--;
							quantita_necessaria -= alimenti_frigo[j].peso_unitario;
							pezzi_consumati++;											/*ogni volta che viene decrementato un pezzo viene registrato il nuemro di pezzi consumati*/
						}

						if (stampa_alimenti_usati == 1) {
							printf("Sono state consumati %hd pezzi/confezioni dell'alimento %hu '%s'\n", pezzi_consumati, alimenti_frigo[j].id_alimento, alimenti_frigo[j].nome_alimento);
						}

						alimenti_frigo[j].numero_pezzi--;		/* proprio per la scelta progettuale esplicitata pocanzi, il numero di pezzi viene decrementato un ultima volta */
						quantita_necessaria -= alimenti_frigo[j].peso_unitario;
						modifica_alimento ("files/elenco_alimenti.bin", alimenti_frigo[j]);	/* la quantita' disponibile dell'alimento viene modificata anche sul file*/

						if (alimenti_frigo[j].numero_pezzi == 0) {	/* se la quantita' disponibile dell'alimento e' pari a 0, l'alimento deve essere cancellato dal vettore e dal file*/

							if (stampa_alimenti_usati == 1) {

								printf("L'alimento %hu '%s' e' stato consumato completamente, pertanto non e' piu' presente in frigo.\n",alimenti_frigo[j].id_alimento, alimenti_frigo[j].nome_alimento);
							}

							cancella_alimento ( "files/elenco_alimenti.bin", alimenti_frigo[j] );
							alimenti_frigo[j].id_alimento = 0;

						}
					}
				}
			}
		}
	}
}



unsigned short int rimetti_alimenti_in_frigo (alimento* alimenti_frigo, unsigned short int numero_alimenti, const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int indice_ricetta, unsigned short int numero_persone, unsigned short int stampa_alimenti_rimessi) {

	unsigned short int is_alimento_modificato;		/*flag che se e' 1 indica che l'ingrediente e' stato riemsso in frigo, 0 altrimenti*/
	float quantita_rimettere_in_frigo;				/* quantita' in grammi dell'ingrediente da riemttere in frigo */
	unsigned short int numero_pezzi_aggiungere;		/* numero di pezzi da ggiungere ad un alimento in base alla quantita da rimmettere in frigo*/
	unsigned short int count_alimenti_rimessi = 0;	/* contatore di alimenti rimessi in frigo*/

	if (stampa_alimenti_rimessi == 1) {
		printf("\nSono stati rimessi in frigo i seguenti alimenti:\n");
	}

	for (int i=0; i<ricettario[indice_ricetta].numero_ingredienti; i++) {		/* ciclo che itera sugli ingredienti della ricetta che devono essere rimessi in frigo*/
		is_alimento_modificato = 0;

		for (int j=0; j<numero_alimenti; j++) {

			/* se l'ingrediente non e' stato ancora rimesso in frigo ed e' stata trovata una corrispondenza attraverso il nome*/
			if ( !is_alimento_modificato && !strcasecmp (ricettario[indice_ricetta].ingredienti[i].nome_alimento, alimenti_frigo[j].nome_alimento) ) {

				if(strcasecmp (ricettario[indice_ricetta].ingredienti[i].quantita, "qb")) {		/*se la quantita' dell'ingrediente non e' "qb", l'aliemnto deve essere rimesso in frigo*/

					quantita_rimettere_in_frigo = (float) numero_persone * atof(ricettario[indice_ricetta].ingredienti[i].quantita) / ricettario[indice_ricetta].n_persone;
					numero_pezzi_aggiungere = quantita_rimettere_in_frigo / alimenti_frigo[j].peso_unitario;

					if (numero_pezzi_aggiungere == 0) {	/*se numero_pezzi_aggiungere = 0 , quantita_rimettere_in_frigo <= alimenti_frigo[j].peso_unitario, ma comuqnue deve essere rimesso un pezzo dell'alimento in frigo */
						numero_pezzi_aggiungere++;
					}
					alimenti_frigo[j].numero_pezzi += numero_pezzi_aggiungere;		/* viene rimesso l'alimento in frigo */

					if(alimenti_frigo[j].id_alimento == 0){							/* se l'alimento e' stato precedentemente cancellato poiche probabilemnte era terminato*/
						alimenti_frigo[j].id_alimento = get_nuovo_id_alimento (alimenti_frigo, numero_alimenti);	/* gli viene assegnato un nuovo id */
					}

					modifica_alimento ( "files/elenco_alimenti.bin", alimenti_frigo[j] );		/* viene rimesso l'aliemnto anche nel file */
					is_alimento_modificato = 1;

					count_alimenti_rimessi++;

					if (stampa_alimenti_rimessi == 1) {
						printf("\t- %s (%2hu pezzi/confezioni)\n", alimenti_frigo[j].nome_alimento, numero_pezzi_aggiungere );
					}
				}
			}
		}
	}

	return count_alimenti_rimessi;	/* restituisce il numero degli alimenti rimessi in frigo*/
}





unsigned short int modifica_giorno (char* nome_file, menu_giornaliero menu_modificato, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, unsigned short int indice_mod, unsigned short int id_utente) {

	menu_giornaliero menu_vuoto;		/*menu giornaliero che viene inizializzato con id 0 in modo da non essere visibile*/
	menu_vuoto.id_menu = 0;
	menu_vuoto.id_utente = 0;

	unsigned short int indice_da_cancellare = indice_mod;		/* indice del vettore menu_settimanale il cui elemento deve essere cancellato*/


	for (int i = 0; i < numero_menu_giornalieri; i++) {

		/* se l'id del menu_ settimanale corrisponde a id_utente e il giorno settimanale e' lo stesso di quello del menu che deve essere modificato*/
		if (menu_settimanale[i].id_menu > 0 && menu_settimanale[i].id_utente == menu_modificato.id_utente && !strcmp (menu_settimanale[i].data_menu.giorno_settimana, menu_modificato.data_menu.giorno_settimana)) {
			menu_modificato.id_menu = menu_settimanale[i].id_menu;
			indice_mod = i;
			if (confronta_date (menu_settimanale[i].data_menu, menu_modificato.data_menu) == 2) {		/*se la data di menu_settimanale[i] e' la stessa del menu da modificare */
				for (int j=0; j<menu_settimanale[i].numero_pasti; j++) {								/*il menu viene modificato*/
					menu_modificato.pasti[ menu_modificato.numero_pasti ] = menu_settimanale[i].pasti[j];
					menu_modificato.numero_pasti++;

				}
				menu_modificato.kcal_giornaliere += menu_settimanale[i].kcal_giornaliere;
			} else {
				return 0;																			/* altrimenti non puo' essere modificato*/
			}
		}
	}

	menu_settimanale[indice_da_cancellare] = menu_vuoto;
	cancella_menu_giornaliero ( nome_file, id_utente, menu_modificato.data_menu );					/* il vecchio menu viene cancellato*/
	menu_settimanale[indice_mod] = menu_modificato;
	aggiungi_menu_giornaliero ( nome_file, menu_modificato, menu_modificato.data_menu );			/* e le modifiche vengono effettuate anche sul file*/

	return 1;

}






unsigned short int modifica_pasto (char* nome_file, unsigned short int indice_menu, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, const ricetta* ricettario, unsigned short int numero_ricette, alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int input_id_ricetta, unsigned short int vecchio_numero_persone, unsigned short int nuovo_numero_persone, unsigned short int vecchio_indice_ricetta, unsigned short int nuovo_indice_ricetta, unsigned short int pasto_da_modificare) {


		if (is_ricetta_preparabile (ricettario[nuovo_indice_ricetta], alimenti_frigo, numero_alimenti, nuovo_numero_persone)) {	 /* se la ricetta ricettario[nuovo_indice_ricetta] e' preparabile */

			menu_settimanale[indice_menu].pasti[pasto_da_modificare].id_ricetta = input_id_ricetta;
			menu_settimanale[indice_menu].pasti[pasto_da_modificare].n_persone = nuovo_numero_persone;

			float kcal_pasto_vecchio = vecchio_numero_persone * ricettario[vecchio_indice_ricetta].kcal / ricettario[vecchio_indice_ricetta].n_persone;
			float kcal_pasto_nuovo = nuovo_numero_persone * ricettario[nuovo_indice_ricetta].kcal / ricettario[nuovo_indice_ricetta].n_persone;
			menu_settimanale[indice_menu].kcal_giornaliere += kcal_pasto_nuovo - kcal_pasto_vecchio;	/* vengono calcolate le kcal dopo la modifica del menu giornaliero */

			printf("DOSI DEGLI INGREDIENTI di \"%s\" per %hu persone:\n", ricettario[nuovo_indice_ricetta].nome_ricetta, nuovo_numero_persone);

			for (int i = 0; i < ricettario[nuovo_indice_ricetta].numero_ingredienti; i++) {					/* ciclo che stampa i nomi e le dosi degli ingredienti*/
					printf("\t- %s ", ricettario[nuovo_indice_ricetta].ingredienti[i].nome_alimento);
					if( strcasecmp(ricettario[nuovo_indice_ricetta].ingredienti[i].quantita, "qb") ) {
						printf("(%.2f %c)\n", (float) nuovo_numero_persone * atof(ricettario[nuovo_indice_ricetta].ingredienti[i].quantita) / ricettario[nuovo_indice_ricetta].n_persone ,
								ricettario[nuovo_indice_ricetta].ingredienti[i].unita_misura);
					} else {
						printf("(qb)\n");
					}
			}

			elimina_ingredienti_usati (ricettario[nuovo_indice_ricetta], nuovo_numero_persone, alimenti_frigo, numero_alimenti, NON_STAMPA_ALIMENTI_USATI);			 /*gli ingredienti usati vengono tolti dal frigo*/
			aggiungi_menu_giornaliero ( nome_file, menu_settimanale[indice_menu], menu_settimanale[indice_menu].data_menu );										/* il menu viene modifcato anche sul file*/

			return 1;
		} else {
			return 0;
		}
}




alimento* copia_vettore_alimenti ( const alimento* alimenti_frigo, unsigned short int numero_alimenti_frigo) {
	alimento* copia_frigo = malloc (numero_alimenti_frigo * sizeof(alimento));

	for (int i=0; i<numero_alimenti_frigo; i++) {
		copia_frigo[i] = alimenti_frigo[i];				/*ogni elemento di alimenti_frigo viene copiato in copia_frigo*/
	}
	return copia_frigo;
}




void input_cancella_menu ( char* nome_file, menu_giornaliero* menu_settimanale, unsigned short int numero_menu_giornalieri, const ricetta* ricettario, unsigned short int numero_ricette, unsigned short int id_utente ) {

	printf("\n*************************************************************\n");
	printf("****************  CANCELLA MENU SETTIMANALE  ****************\n");
	printf("*************************************************************\n\n");

	unsigned short int id_menu;
	unsigned short int pasto_da_cancellare;
	unsigned short int indice_da_cancellare, indice_ricetta;			/*indice dell'elemento del vettore da cancellare*/
	unsigned short int is_menu_vuoto = 1;
	pasto nuovo_vett_pasti[MAX_NUMERO_PASTI] = {0};
	menu_giornaliero menu_vuoto;
	menu_vuoto.id_menu = 0;
	menu_vuoto.id_utente = 0;

	printf ("Quale menu giornaliero vuoi cancellare?\n");
	for (int i = 0; i < numero_menu_giornalieri; i++) {
		if (menu_settimanale[i].id_menu > 0 && menu_settimanale[i].id_utente == id_utente) {
			printf("\t%hu - %s\n", menu_settimanale[i].id_menu, menu_settimanale[i].data_menu.giorno_settimana);
			is_menu_vuoto = 0;
		}
	}

	if (is_menu_vuoto) {
		printf ("\tOPS! Non c'e' alcun menu giornaliero per questo utente.\n");
	} else {
		id_menu= inserisci_input_intero ("? ", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido all'id menu*/

		/*ciclo che itera finche' is_menu_esistente e' 0, cioe' fin quando l'input non e' un id esistente nel vettore*/
		while ( !is_menu_esistente(menu_settimanale, numero_menu_giornalieri, id_menu, id_utente) ) {

			printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */
			id_menu = inserisci_input_intero ("", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido all'id menu*/
		}

		indice_da_cancellare = indice_id_menu (menu_settimanale, numero_menu_giornalieri, id_menu);


		printf ("\nQuale tra i pasti del menu' selezionato vuoi eliminare?\n");
		for (int i=0; i<menu_settimanale[indice_da_cancellare].numero_pasti; i++) {
			pasto_da_cancellare = menu_settimanale[indice_da_cancellare].pasti[i].id_ricetta;
			printf("\t%hu - %s (x%2hu)\n", i, ricettario[ indice_id_ricetta (ricettario, numero_ricette, pasto_da_cancellare) ].nome_ricetta, menu_settimanale[indice_da_cancellare].pasti[i].n_persone );
		}

		pasto_da_cancellare = inserisci_input_intero ("? ", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido*/


		while ( !is_compreso_tra(0, menu_settimanale[indice_da_cancellare].numero_pasti-1, pasto_da_cancellare) ) {

			printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */
			pasto_da_cancellare = inserisci_input_intero ("", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido all'id menu*/
		}

		unsigned short int is_elemento_saltato = 0;

		menu_settimanale[indice_da_cancellare].numero_pasti--;
		indice_ricetta = indice_id_ricetta (ricettario, numero_ricette, menu_settimanale[indice_da_cancellare].pasti[pasto_da_cancellare].id_ricetta);
		menu_settimanale[indice_da_cancellare].kcal_giornaliere -= menu_settimanale[indice_da_cancellare].pasti[pasto_da_cancellare].n_persone * ricettario[indice_ricetta].kcal / ricettario[indice_ricetta].n_persone;

		for (int i=0; i<menu_settimanale[indice_da_cancellare].numero_pasti; i++) {
			if (pasto_da_cancellare != i || is_elemento_saltato) {
				nuovo_vett_pasti[i]= menu_settimanale[indice_da_cancellare].pasti[i + is_elemento_saltato];
			} else {
				i--;
				is_elemento_saltato = 1;
			}
		}

		for (int i=0; i<MAX_NUMERO_PASTI; i++) {
			menu_settimanale[indice_da_cancellare].pasti[i] = nuovo_vett_pasti[i];
		}

		if (menu_settimanale[indice_da_cancellare].numero_pasti > 0) {
			aggiungi_menu_giornaliero ( nome_file, menu_settimanale[indice_da_cancellare], menu_settimanale[indice_da_cancellare].data_menu );
		} else {
			cancella_menu_giornaliero ( nome_file, id_utente, menu_settimanale[indice_da_cancellare].data_menu );
			menu_settimanale[indice_da_cancellare] = menu_vuoto;
		}

		printf("\nPasto cancellato!\n");
	}
}



unsigned short int cancella_menu_giornaliero ( char* nome_file, unsigned short int id_utente, data data_menu ) {
	FILE *file;
	menu_giornaliero menu_vuoto;
	menu_vuoto.id_menu = 0;
	menu_vuoto.id_utente = 0;

	if ((file = fopen(nome_file, "rb+")) == NULL) {		/*apertura del file in modalita'a' scrittura */
        printf("Errore nell'apertura del file %s",nome_file);
		return 0;		/* viene restituito 0 se il file non e' stato aperto */
	}
	else {
		fseek(file, (sizeof(menu_giornaliero) * NUMERO_GIORNI_SETTIMANA * (id_utente -1)) +  get_giorno_settimana_intero (data_menu) * sizeof(menu_giornaliero) , SEEK_SET);					/*viene posizionato il puntare nel file */
		fwrite(&menu_vuoto, sizeof(menu_giornaliero), 1, file);		/*menu_odierno viene scritto sul file*/
	}

	fclose(file);


	return 1;	/* viene restituito 1 se la scrittura e' andata a buon fine */

}








