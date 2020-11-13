#include <smartfridge/elaborazione_alimenti.h>
#include <smartfridge/lista_spesa.h>


/**
 * @pre gli elementi del vettore passato come primo parametro devono avere tutti i campi pieni, altrimenti verranno visualizzati caratteri strani
 * @pre numero_alimenti deve corrispondere alla lungehzza effettiva del vettore
 * @post il valore restituito deve corrispondere al numero di alimenti stampati
 * @bug se il secondo parametro e' troppo piccolo, potrebebro essere visualizzati meno alimenti di quelli presenti nel vettore, producendo quindi un errore logico a runtime.
 */

unsigned short int apri_frigo (const alimento alimenti_frigo[], unsigned short int numero_alimenti ) {

	unsigned short int elementi_stampati = 0;	/*contatore degli alimenti stampati*/

	printf("\n*************************************************************************************\n");
	printf("*************************************  FRIGORIFERO  *********************************\n");
	printf("*************************************************************************************\n\n");

	printf("-------------------------------------------------------------------------------------\n");
	printf("| %3s | %35s | %13s | %6s | %12s |\n","ID", "NOME ALIMENTO", "DATA SCADENZA", "NUMERO", "PESO U. (gr)");
	printf("-------------------------------------------------------------------------------------\n");

	for (int i = 0; i < numero_alimenti; i++) {

		if (alimenti_frigo[i].id_alimento > 0) {		/*stampa l'alimento solo se l'id e' valido*/


			printf("| %3hu | %35s | %5hu/%2hu/%4hu | %6hu | %10.2f g |\n",
					alimenti_frigo[i].id_alimento,
					alimenti_frigo[i].nome_alimento,
					alimenti_frigo[i].data_scadenza.giorno,
					alimenti_frigo[i].data_scadenza.mese,
					alimenti_frigo[i].data_scadenza.anno,
					alimenti_frigo[i].numero_pezzi,
					alimenti_frigo[i].peso_unitario);
			printf("-------------------------------------------------------------------------------------\n");

			elementi_stampati++;
		}
	}

	return elementi_stampati;	/*restituisce il numero degli alimenti stampati*/
}







/**
 * La funzione aprira' in modalita' scrittura il file e la scrittura avverra' sul record corrispondente all'id dell'alimento
 * passato come parametro.
 *
* @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
* @pre alimento_frigo deve avere un id > 0
*/

unsigned short int aggiungi_alimento ( char* nome_file, alimento alimento_frigo ) {
	FILE *file;

	if ((file = fopen(nome_file, "rb+")) == NULL) {		/*apertura del file in modalita'a' scrittura */
        printf("Errore nell'apertura del file %s",nome_file);
		return 0;		/* viene restituito 0 se il file non e' stato aperto */
	}
	else {
		fseek(file, sizeof(alimento)* (alimento_frigo.id_alimento - 1), SEEK_SET);					/*viene posizionato il puntare nel file */
		fwrite(&alimento_frigo, sizeof(alimento), 1, file);		/*alimento_frigo viene scritto sul file*/
	}

	if(!fclose(file)){
		printf("\nAlimento aggiunto!\n");
	}

	return 1;	/* viene restituito 1 se la scrittura e' andata a buon fine */

}








/**
 * La funzione richiama le funzioni di controlli.h per acquisire degli input corretti
 *
 * @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
 * @pre alimento_frigo deve avere un id > 0
 * @pre numero_alimenti deve corrispondere alla lunghezza del vettore alimenti_frigo
 */

void input_aggiungi_alimento ( char* nome_file, alimento* alimenti_frigo, unsigned short int numero_alimenti ) {
	alimento alimento_aggiunto; 			  /* alimento che verra'a' aggiunto al file */

	printf("\n*************************************************************\n");
	printf("********************  AGGIUNGI ALIMENTO  ********************\n");
	printf("*************************************************************\n\n");

	alimento_aggiunto.id_alimento = get_nuovo_id_alimento (alimenti_frigo, numero_alimenti);							/*l'id dell'alimento aggiunto sara' incrementato di 1 rispetto al massimo id presente nel vettore*/
	strcpy (alimento_aggiunto.nome_alimento, inserisci_input_caratteri_spazio ("Nome alimento: ", LUNGHEZZA_NOME) );	/*viene acquisita una stringa valida formata da sole lettere e asseganta al nome dell'alimento*/
	alimento_aggiunto.data_scadenza = inserisci_input_data ("Data scadenza (gg/mm/aaaa): ", LUNGHEZZA_INPUT);			/*viene acquisita una data valida e asseganta alla data di scadenza dell'alimento*/
	alimento_aggiunto.numero_pezzi = inserisci_input_intero ("Numero pezzi/confezioni: ", LUNGHEZZA_INPUT);				/*viene acquisito un intero valido e asseganto al numero di pezzi dell'alimento*/
	alimento_aggiunto.peso_unitario = inserisci_input_float ("Peso unitario (g): ", LUNGHEZZA_INPUT);					/*viene acquisito un nuemro decimale valido e asseganto al peso unitario dell'alimento*/

	aggiungi_alimento (nome_file, alimento_aggiunto );		/* l'alimento acquisito da tastiera verra' aggiunto al file*/

	alimenti_frigo [ get_ultimo_indice_alimento (alimenti_frigo, numero_alimenti) + 1 ] = alimento_aggiunto;		/* l'alimento acquisito da tastiera viene assegnato all'indice del vettore successivo ripetto all'ultimo valido*/
}






/**
 * La funzione cerca il massimo id nel vettore passato come primo paramentro, lo incrementa e lo restituisce come valore di ritorno
 *
 * @pre alimenti_frigo deve avere almeno un elemento con id > 0
 * @pre numero_alimenti deve corrispondere alla lunghezza del vettore alimenti_frigo
 * @post l'intero restituito deve essere diverso da tutti gli altri id del vettore
 */

unsigned short int get_nuovo_id_alimento (const alimento* alimenti_frigo, unsigned short int numero_alimenti) {

	unsigned short int max_id = alimenti_frigo[0].id_alimento;			/*inizialmente viene imposto come massimo l'id del primo elemento*/

	for ( int i=0; i<numero_alimenti; i++) {														/*ciclo ce cerca il massimo id nel vettore*/
		if (alimenti_frigo[i].id_alimento > 0 && alimenti_frigo[i].id_alimento > max_id) {
			max_id = alimenti_frigo[i].id_alimento;
		}
	}

	return ++max_id;			/*il massimo viene incementato di uno e restituito*/

}



/**
 * La funzione itera sul vettore passato come primo paramentro e restituisce l'ultimo indice contenente un id > 0
 *
 * @pre alimenti_frigo deve avere almeno un elemento con id > 0
 * @pre numero_alimenti deve corrispondere alla lunghezza del vettore alimenti_frigo
 */

unsigned short int get_ultimo_indice_alimento (const alimento* alimenti_frigo, unsigned short int numero_alimenti) {

	unsigned short int ultimo_i = 0;
	int i;
	for ( i=0; i<numero_alimenti; i++) {
		if (alimenti_frigo[i].id_alimento > 0) {		/*entra nell'if solo se l'id e' valido*/
			ultimo_i = i;
		}
	}

	return ultimo_i;
}





/**
 * La funzione aprira' in modalita' scrittura il file e la scrittura avverra' sul record corrispondente all'id dell'alimento
 * passato come parametro.
 *
* @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
* @pre alimento_frigo deve avere un id > 0
*/

unsigned short int modifica_alimento ( char* nome_file, alimento alimento_frigo ) {
	FILE *file;

	if ((file = fopen(nome_file, "rb+")) == NULL) {		/*apertura del file in modalita'a' scrittura/lettura */
        printf("Errore nell'apertura del file %s",nome_file);
		return 0;		/* viene restituito 0 se il file non e' stato aperto */
	}
	else {
		fseek(file, sizeof(alimento)* (alimento_frigo.id_alimento - 1), SEEK_SET);					/*viene posizionato il puntare nel file */
		fwrite(&alimento_frigo, sizeof(alimento), 1, file);							/*alimento_frigo viene scritto sul file*/

	}

	fclose(file);

	return 1;	/* viene restituito 1 se la scrittura e' andata a buon fine */

}








/**
 * La procedura fa sceglie all'utente l'alimento e il campo da modificare e in base a quest'ultimo implementa dei controlli diversi sull'input.
 * L'aliemento modificato verra' scritto sia sul file che sul vettore.
 *
 * @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
 * @pre alimenti_frigo deve avere almeno un elemento con id > 0
 * @pre numero_alimenti deve corrispondere alla lunghezza del vettore alimenti_frigo
 */

void input_modifica_alimento ( char* nome_file, alimento* alimenti_frigo, unsigned short int numero_alimenti ) {

	printf("\n*************************************************************\n");
	printf("********************  MODIFICA ALIMENTO  ********************\n");
	printf("*************************************************************\n\n");

	alimento alimento_modificato; 			 	 /* variabile che memorizza l'alimentoa'modificato */
	unsigned short int indice_mod;				 /*indice dell'elemento del vettore da modificare*/
	unsigned short int is_scelta_corretta = 0;	 /*flag che se e' 0 indica che la scelta non e' corretta, se e' 1 vuol dire che la scelta e' corretta*/

	printf ("Quale alimento vuoi modificare?\n");
	for (int i = 0; i < numero_alimenti; i++) {
		if (alimenti_frigo[i].id_alimento > 0) {		/*stampa l'alimento solo se l'id e' valido*/
			printf("\t%hu - %s\n", alimenti_frigo[i].id_alimento, alimenti_frigo[i].nome_alimento);
		}
	}

	alimento_modificato.id_alimento = inserisci_input_intero ("? ", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido all'id alimento*/

	/*ciclo che itera finche' is_alimento_esistente e' 0, cioe' fin quando l'input non e' un id esistente nel vettore*/
	while ( !is_alimento_esistente(alimenti_frigo, numero_alimenti, alimento_modificato.id_alimento) ) {

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */
		alimento_modificato.id_alimento = inserisci_input_intero ("", LUNGHEZZA_INPUT );	/*viene assegnato un intero valido all'id alimento*/
	}

	indice_mod = indice_id_alimento (alimenti_frigo, numero_alimenti, alimento_modificato.id_alimento);		/* viene asseganto l'indice corrispondere all'id dell'alimento che si vuole modificare*/
	alimento_modificato = alimenti_frigo[indice_mod]; 	/*tutti i campi dell'elemento del vettore da modificare vengono copiati in alimento_modificato*/

	printf ("\nQuale campo vuoi modificare?\n");
	printf ("\t1- Nome\n"
			"\t2- Data scadenza\n"
			"\t3- Numero pezzi\n"
			"\t4- Peso unitario\n"
			"? ");

	short int scelta = inserisci_input_intero("", LUNGHEZZA_INPUT);

	/* ciclo che si ripete finche' l'utente non inserisce un input diverso da 1,2,3,4 */
	/* ad ogni iterazione verra'a' chiesto un nuovo input all'utente */

	while( is_scelta_corretta == 0 ){		/*quando viene inserito 1,2,3, o 4 is_scelta_corretta diventera' 1 e si uscira' dal ciclo*/

		switch(scelta){						/* switch che eseguira'a' un operazione diversa in base all'input dell'utente */

		case 1:
			strcpy (alimento_modificato.nome_alimento, inserisci_input_caratteri_spazio ("\nNome alimento: ", LUNGHEZZA_NOME) );	/*viene acquisita una stringa valida formata da sole lettere e asseganta al nome dell'alimento*/
			is_scelta_corretta = 1;
			break;
		case 2:
			alimento_modificato.data_scadenza = inserisci_input_data ("\nData scadenza (gg/mm/aaaa): ", LUNGHEZZA_INPUT);		/* viene acquisita una data valida */
			is_scelta_corretta = 1;
			break;
		case 3:
			alimento_modificato.numero_pezzi = inserisci_input_intero ("\nNumero pezzi/confezioni: ", LUNGHEZZA_INPUT);			/* viene acquisito un intero valido */
			is_scelta_corretta = 1;
			break;
		case 4:
			alimento_modificato.peso_unitario = inserisci_input_float ("\nPeso unitario (g): ", LUNGHEZZA_INPUT);				/* viene acquisito un nuemro decimale valido */
			is_scelta_corretta = 1;
			break;
		default:
			printf("Valore errato! Reinserire: ");
			scelta = inserisci_input_intero("", LUNGHEZZA_INPUT);
		}
	}

	alimenti_frigo[indice_mod] = alimento_modificato;			/* viene modificato l'alimento nel vettore */
	modifica_alimento (nome_file, alimento_modificato );		/* viene modificato l'alimento nel file */
	printf("\nAlimento modificato!\n");
}


/**
 * @pre alimenti_frigo deve avere almeno un elemento con id > 0
 * @pre numero_alimenti deve corrispondere alla lunghezza del vettore alimenti_frigo
 * @pre id_alimento deve essere > 0
 * @post il valore restituito sara' 1 se l'id e' presente nel vettore, 0 altrimenti
 */

unsigned short int is_alimento_esistente (const alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int id_alimento) {

	int i;
	for ( i=0; i<numero_alimenti; i++) {
		if (id_alimento != 0 && alimenti_frigo[i].id_alimento == id_alimento) {
			return 1;
		}
	}

	return 0;
}



/**
 * @pre numero_alimenti deve corrispondere alla lunghezza del vettore alimenti_frigo
 * @pre id_alimento deve essere > 0
 */

unsigned short int indice_id_alimento (const alimento* alimenti_frigo, unsigned short int numero_alimenti, unsigned short int id_alimento) {

	int i;
	for ( i=0; i<numero_alimenti; i++) {
		if (alimenti_frigo[i].id_alimento == id_alimento) {
			return i;
		}
	}

	return i;
}


/**
 * La funzione itera sul vettore passato come secondo parametro e chiama is_scaduto() per controllare se ogni elemento e' scaduto.
 * In tal caso, l'alimento viene eliminato dal vettore e dal file, il cui nome e' stato passato come parametro, azzerando l'id.
 * @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
 * @pre alimenti_frigo deve avere almeno un elemento con id > 0
 * @pre numero_alimenti deve corrispondere alla lunghezza del vettore alimenti_frigo
 * @pre data_corrente deve essere una data valida
 */

unsigned short int is_alimenti_scaduti  ( char* nome_file, alimento* alimenti_frigo, unsigned short int numero_alimenti, data data_corrente ) {

	unsigned short int is_cancellato = 0;

	for (int i=0; i<numero_alimenti; i++) {
		if ( alimenti_frigo[i].id_alimento != 0 && is_scaduto (alimenti_frigo[i], data_corrente) == 1) {	/*se l'id e' valido e is_scaduto() restutisce 1*/

			printf("\n**********************************************************************\n");
			printf("L'alimento %hu '%s' e' stato tolto dal frigo poiche' era scaduto!\n", alimenti_frigo[i].id_alimento, alimenti_frigo[i].nome_alimento);
			printf("**********************************************************************\n");

			cancella_alimento (nome_file, alimenti_frigo[i]);		/* l'alimento verra' cancellato dal file */
			alimenti_frigo[i].id_alimento = 0;						/* l'alimento verra' cancellato vettore azzerando l'id */

			is_cancellato = 1;

		}
	}

	return is_cancellato;
}


/**
 * @pre alimento_frigo deve avere una data di scadenza valida
 * @pre data_corrente deve essere una data valida
 * @post il valore restituito sara' 1 se la data di scadenza e' uguale o minore alla data corrente, 0 altrimenti
 * */

unsigned short int is_scaduto (alimento alimento_frigo, data data_corrente) {

    if (confronta_date(data_corrente, alimento_frigo.data_scadenza) > 0) {
        return 1;
    } else {
        return 0;
    }
}


/**
 * La funzione aprira' in modalita' scrittura il file e la scrittura avverra' sul record corrispondente all'id dell'alimento
 * passato come parametro. Prima di scrivere l'aliemento da cancellare, l'id e il numero di pezzi verranno settati a 0.
 *
* @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
* @pre alimento_da_cancellare deve avere un id > 0
*/

unsigned short int cancella_alimento ( char* nome_file, alimento alimento_da_cancellare ) {
	FILE *file;

	if ((file = fopen(nome_file, "rb+")) == NULL) {		/*apertura del file in modalita'a' scrittura/lettura */
        printf("Errore nell'apertura del file %s",nome_file);
		return 0;		/* viene restituito 0 se il file non e' stato aperto */
	}
	else {
		fseek(file, sizeof(alimento)* (alimento_da_cancellare.id_alimento - 1), SEEK_SET);					/*viene posizionato il puntare nel file */
		alimento_da_cancellare.id_alimento = 0;
		alimento_da_cancellare.numero_pezzi = 0;
		fwrite(&alimento_da_cancellare, sizeof(alimento), 1, file);							/*alimento_vuoto viene scritto sul file*/

	}

	fclose(file);

	return 1;	/* viene restituito 1 se la scrittura e' andata a buon fine */

}


/**
 * La funzione incrementa la data corrente tante volte quanto e' la soglia_scadenza passata come quinto parametro.
 * Tale data verra' confrontata con la data di scadenza di ogni alimento del vettore passato come secondo parametro.
 * Se le due date sono uguali, il nome dell'alimento verra' aggiunto al vettore di stringhe passato come primo parametro.
 *
 * @pre alimenti_frigo deve avere almeno un elemento con id > 0
 * @pre numero_alimenti deve corrispondere alla lunghezza del vettore alimenti_frigo
 * @pre data_corrente deve essere una data valida
 * @pre soglia_scadenza deve essere > 0
*/

unsigned short int controlla_scadenza_alimenti  (char alimenti_scadenza[][LUNGHEZZA_NOME], const alimento* alimenti_frigo, unsigned short int numero_alimenti, data data_corrente, unsigned short int soglia_scadenza) {

	unsigned short int alimenti_in_scadenza = 0;
	data data_alim_in_scadenza = data_corrente;		/* data con cui verra' confrontata la data di scadenza */

	for (int j=0; j<soglia_scadenza; j++) {											/*itera in modo da incrememntare la data da 0 a 2 giorni */
		data_alim_in_scadenza = giorno_successivo (data_alim_in_scadenza);			/* viene incrementata la data corrente */

		for (int i=0; i<numero_alimenti; i++) {
			if (alimenti_frigo[i].id_alimento != 0 && confronta_date (data_alim_in_scadenza, alimenti_frigo[i].data_scadenza) == 2 ) {		/* se la data corrente e' uguale alla data di scadenza*/

				strcpy (alimenti_scadenza[alimenti_in_scadenza], alimenti_frigo[i].nome_alimento);			/* il nome dell' alimento viene messo nel vettore di alimenti in scadenza*/
				alimenti_in_scadenza++;
			}
		}
	}

	return alimenti_in_scadenza;
}

/**
 *
 * @pre contatore_scadenza_alimenti deve corrispondere al numero di alimenti in scadenza effettivamente scritti nel vettore passato come primo parametro
 */

void stampa_alimenti_scadenza (const char alimenti_scadenza[][LUNGHEZZA_NOME], unsigned short int contatore_scadenza_alimenti, unsigned short int soglia_scadenza) {

	if (contatore_scadenza_alimenti > 0) {
		printf("\n***********************************************************\n");
		printf("ATTENZIONE: Sono in scadenza i seguenti alimenti:\n");
	}

	for (int i=0; i<contatore_scadenza_alimenti; i++) {
		printf("\t- L'alimento '%s' scade tra %d giorni o meno\n", alimenti_scadenza[i], soglia_scadenza);
	}

	if (contatore_scadenza_alimenti > 0) {
		printf("\n***********************************************************\n");
	}
}

/**
 * La funzione itera sul vettore di alimenti passato come secondo parametro e conta le occorrenze di ciascun alimento in frigo.
 * Se le occorrenze sono inferiori della soglia_esaurimento passata come quarto parametro, il nome dell'alimento verra' aggiunto al vettore
 * di stringhe passato come primo parametro.
 *
 * @pre alimenti_frigo deve avere almeno un elemento con id > 0
 * @pre numero_alimenti deve corrispondere alla lunghezza del vettore alimenti_frigo
 * @pre soglia_esaurimento deve essere > 0
*/


unsigned short int controlla_esaurimento_alimenti  (char alimenti_esaurimento[][LUNGHEZZA_NOME],  alimento* alimenti_frigo, unsigned short int numero_alimenti,  unsigned short int soglia_esaurimento) {

	unsigned short int contatore_esaurimento = 0;		/* variabile che conta il numero di alimenti in esaurimento presenti nel frigo */
	unsigned short int occorrenze_alimento = 0;			/* variabile che conta quanti alimenti con lo stesso nome ci sono nel frigo */
	unsigned short int is_alimento_presente = 0;		/* flag che viene impostato a 1 quando un alimento in esaurimento e' stato gia' messo nel vettore in modo che non venga inserito piu' volte */


	for (int i=0; i<numero_alimenti; i++) {

		is_alimento_presente = 0;
		occorrenze_alimento = 0;				/* azzera le occorrenze */

		for (int j=0; j<numero_alimenti; j++) {		/* ciclo che conta le occorrenze dell'alimento alimenti_frigo[i] nel frigo */
			if(alimenti_frigo[i].id_alimento != 0 && alimenti_frigo[j].id_alimento != 0 && !strcasecmp (alimenti_frigo[i].nome_alimento,alimenti_frigo[j].nome_alimento) ) {		/* se viene trovato un alimento con lo stesso nome*/
				occorrenze_alimento += alimenti_frigo[j].numero_pezzi;																												/* vengono incrementate le occorrenze */
			}
		}

		if (alimenti_frigo[i].id_alimento != 0 && occorrenze_alimento <= soglia_esaurimento ) {			/* se le occorrenze dell'alimento sono <= 2 */

			for (int k=0; k<contatore_esaurimento; k++) {										/* verifica se l'alimento e' stato gia' inserito nel vettore degli elementi in esaurimento*/
				if (!strcasecmp (alimenti_frigo[i].nome_alimento, alimenti_esaurimento[k])) {
					is_alimento_presente = 1;
				}
			}

			if (!is_alimento_presente) {		/* se non e' gia' stato inserito, lo inserisce */

				strcpy(alimenti_esaurimento[contatore_esaurimento], alimenti_frigo[i].nome_alimento);
				contatore_esaurimento++;

				aggiungi_a_lista("files/lista_spesa.txt", alimenti_frigo[i].nome_alimento);

			}
		}
	}






	return contatore_esaurimento;
}


/**
 *
 * @pre contatore_esaurimento_alimenti deve corrispondere al numero di alimenti in esauriemento effettivamente scritti nel vettore passato come primo parametro
 */

void stampa_alimenti_esaurimento ( const char alimenti_esaurimento[][LUNGHEZZA_NOME], unsigned short int contatore_esaurimento_alimenti) {

	if (contatore_esaurimento_alimenti > 0) {
	printf("\n\nATTENZIONE: Sono in esaurimento i seguenti alimenti:\n");
	}

	for (int i=0; i<contatore_esaurimento_alimenti; i++) {
		printf("\t- '%s'\n", alimenti_esaurimento[i] );
	}
}


/**
 * La funzione implementa l'algorimo di ordinamento shell sort, che e' uno dei piu' efficenti in questo caso
 * poiche' trae vantaggi dal preordinamento e ha una complessita' computazionale discreta.
 * Fonte: https://it.wikibooks.org/wiki/Implementazioni_di_algoritmi/Shell_sort
 * */

void shell_sort_date (alimento* vett, int n) {
	int i, j, gap;
	alimento x;
	int vett_gap[5]= { 9, 5, 3, 2, 1 };

	for (int k=0; k<5; k++) {
		gap = vett_gap[k];

		for (i=gap; i<n; i++) {

			if (vett[i].id_alimento != 0) {
				x = vett[i];
				j = i;

				while (j>=gap && confronta_date (vett[j-gap].data_scadenza, x.data_scadenza)) {
					vett[j] = vett[j-gap];
					j = j-gap;
				}

				vett[j] = x;
			}
		}
	}
}


