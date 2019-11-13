#include "carica_file.h"


/**
* La funzione apre il file in lettura, leggere ciascun record (la cui dimensione e' sizeof(alimento))
* e lo assegna ad un elemento del vettore alimenti_frigo.
* La funzione restituisce il puntatore al vettore alimenti_frigo.
* Se il file e' vuoto, viene richiamata la funzione popolazione_file_alimenti()
* e successivamente in modo ricorsivo la funzione richiama se' stessa per caricare nel vettore
* i record del file appena popolato.
* Per tutti i restanti elementi del vettore a cui non e' stato assegnato nulla, l'id verra' azzerato
* cosi da sovrascrivere valori anomali e evitare bug.
*
* @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
* @pre numero_alimenti deve essere un intero > 0
* @post il vettore restituito deve contenere almeno un elemento di tipo alimento
*/

alimento* carica_elenco_alimenti ( char* nome_file, unsigned short int numero_alimenti ) {
	alimento* alimenti_frigo = malloc( numero_alimenti * sizeof(alimento));     /* allocazione dinamica in memoria di un vettore di alimenti*/
	FILE *file;

	if ( (file = fopen (nome_file, "rb")) == NULL ) {			/*apertura del file in lettura*/
		printf("Errore nell'apertura");
	}
	else {
		int i = 0;
		while( !feof(file) ) {                              // ciclo che legge i contenuti del file
			fread (&alimenti_frigo[i], sizeof(alimento), 1, file);  // effettua una lettura di un alimento dal file e la assegna a alimenti_frigo[i]
			i++;
		}


		if ( i == 1 ) {                                           						/*se il file e' vuoto*/
			popolazione_file_alimenti ( nome_file, numero_alimenti );    				/* popola il file elenco_alimenti.bin*/
			alimenti_frigo = carica_elenco_alimenti ( nome_file, numero_alimenti ); 	/* ricarica gli alimenti */
		} else {
			for(i--; i<numero_alimenti; i++) {											/* altrimenti inizializza a 0 tutti gli id*/
				alimenti_frigo[i].id_alimento = 0;										/* degli elementi del vettore per i quali non e' stato assegnato */
			}																			/* alcun record*/
		}


	}

	fclose(file);
	return alimenti_frigo;  /* restituisce un puntatore al primo elemento del vettore */
}





/**
* La funzione apre il file in scrittura in modo da sostituire tutti i recor precedenti.
* Verra' allocato un vettore di tipo alimento (alimenti_frigo) che conterra' un numero di elementi pari al secondo parametro 'numero_alimenti'.
* Tutti i campi  di ciascun elemento del vettore verranno inizializzati da codice con dei valori opportuni.
* Solo gli elementi con un id valido (cioe >0) di tale vettore verranno scritti sul file.
* La funzione restituisce il numero di elementi effettivamnete scritti.
*
* @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
* @pre numero_alimenti deve essere un intero > 0
* @post l'intero restituito sara' un volore compreso tra 1  e numero_alimenti
* @bug da codice deve essere inizializzato almeno un elemento nel vettore alimenti_frigo altrimenti si avranno errori logici a runtime
*/

unsigned short int popolazione_file_alimenti (char* nome_file, unsigned short int numero_alimenti ) {

		FILE *file;
		unsigned short int elementi_scritti = 0;			/*contatore degli alimenti scritti sul file*/

		if ( (file = fopen (nome_file, "wb")) == NULL ) {		/*apertura del file in scrittura*/
			printf("Errore nell'apertura");
		}
		else {

			/*dichiarazione e allocazione dinamica della menoria per un vettore di alimenti*/
			alimento* alimenti_frigo = malloc( numero_alimenti * sizeof(alimento));

			/*inizializzazione degli elementi del vettore alimenti_frigo*/

			alimenti_frigo[0].id_alimento = 1;
			strcpy (alimenti_frigo[0].nome_alimento, "Latte");
			alimenti_frigo[0].data_scadenza.giorno = 23;
			alimenti_frigo[0].data_scadenza.mese = 6;
			alimenti_frigo[0].data_scadenza.anno = 2018;
			alimenti_frigo[0].numero_pezzi = 10;
			alimenti_frigo[0].peso_unitario = 100;

			alimenti_frigo[1].id_alimento = 2;
			strcpy (alimenti_frigo[1].nome_alimento, "Uova");
			alimenti_frigo[1].data_scadenza.giorno = 2;
			alimenti_frigo[1].data_scadenza.mese = 7;
			alimenti_frigo[1].data_scadenza.anno = 2018;
			alimenti_frigo[1].numero_pezzi = 24;
			alimenti_frigo[1].peso_unitario = 60;

			alimenti_frigo[2].id_alimento = 3;
			strcpy (alimenti_frigo[2].nome_alimento, "Pomodori");
			alimenti_frigo[2].data_scadenza.giorno = 1;
			alimenti_frigo[2].data_scadenza.mese = 7;
			alimenti_frigo[2].data_scadenza.anno = 2018;
			alimenti_frigo[2].numero_pezzi = 50;
			alimenti_frigo[2].peso_unitario = 80;

			alimenti_frigo[3].id_alimento = 4;
			strcpy (alimenti_frigo[3].nome_alimento, "Cacao");
			alimenti_frigo[3].data_scadenza.giorno = 25;
			alimenti_frigo[3].data_scadenza.mese = 6;
			alimenti_frigo[3].data_scadenza.anno = 2018;
			alimenti_frigo[3].numero_pezzi = 10;
			alimenti_frigo[3].peso_unitario = 100;

			alimenti_frigo[4].id_alimento = 5;
			strcpy (alimenti_frigo[4].nome_alimento, "Latte");
			alimenti_frigo[4].data_scadenza.giorno = 25;
			alimenti_frigo[4].data_scadenza.mese = 6;
			alimenti_frigo[4].data_scadenza.anno = 2018;
			alimenti_frigo[4].numero_pezzi = 12;
			alimenti_frigo[4].peso_unitario = 100;

			alimenti_frigo[5].id_alimento = 6;
			strcpy (alimenti_frigo[5].nome_alimento, "Caffe");
			alimenti_frigo[5].data_scadenza.giorno = 25;
			alimenti_frigo[5].data_scadenza.mese = 6;
			alimenti_frigo[5].data_scadenza.anno = 2018;
			alimenti_frigo[5].numero_pezzi = 19;
			alimenti_frigo[5].peso_unitario = 10;

			alimenti_frigo[6].id_alimento = 7;
			strcpy (alimenti_frigo[6].nome_alimento, "Zucchero");
			alimenti_frigo[6].data_scadenza.giorno = 25;
			alimenti_frigo[6].data_scadenza.mese = 6;
			alimenti_frigo[6].data_scadenza.anno = 2018;
			alimenti_frigo[6].numero_pezzi = 20;
			alimenti_frigo[6].peso_unitario = 30;

			alimenti_frigo[7].id_alimento = 8;
			strcpy (alimenti_frigo[7].nome_alimento, "Spaghetti");
			alimenti_frigo[7].data_scadenza.giorno = 25;
			alimenti_frigo[7].data_scadenza.mese = 6;
			alimenti_frigo[7].data_scadenza.anno = 2018;
			alimenti_frigo[7].numero_pezzi = 10;
			alimenti_frigo[7].peso_unitario = 500;

			alimenti_frigo[8].id_alimento = 9;
			strcpy (alimenti_frigo[8].nome_alimento, "Pecorino romano");
			alimenti_frigo[8].data_scadenza.giorno = 25;
			alimenti_frigo[8].data_scadenza.mese = 6;
			alimenti_frigo[8].data_scadenza.anno = 2018;
			alimenti_frigo[8].numero_pezzi = 15;
			alimenti_frigo[8].peso_unitario = 200;

			alimenti_frigo[9].id_alimento = 10;
			strcpy (alimenti_frigo[9].nome_alimento, "Guanciale");
			alimenti_frigo[9].data_scadenza.giorno = 25;
			alimenti_frigo[9].data_scadenza.mese = 6;
			alimenti_frigo[9].data_scadenza.anno = 2018;
			alimenti_frigo[9].numero_pezzi = 15;
			alimenti_frigo[9].peso_unitario = 200;

			alimenti_frigo[10].id_alimento = 11;
			strcpy (alimenti_frigo[10].nome_alimento, "Sale fino");
			alimenti_frigo[10].data_scadenza.giorno = 25;
			alimenti_frigo[10].data_scadenza.mese = 6;
			alimenti_frigo[10].data_scadenza.anno = 2018;
			alimenti_frigo[10].numero_pezzi = 10;
			alimenti_frigo[10].peso_unitario = 50;

			alimenti_frigo[11].id_alimento = 12;
			strcpy (alimenti_frigo[11].nome_alimento, "Pepe nero");
			alimenti_frigo[11].data_scadenza.giorno = 25;
			alimenti_frigo[11].data_scadenza.mese = 6;
			alimenti_frigo[11].data_scadenza.anno = 2018;
			alimenti_frigo[11].numero_pezzi = 10;
			alimenti_frigo[11].peso_unitario = 100;

			alimenti_frigo[12].id_alimento = 13;
			strcpy (alimenti_frigo[12].nome_alimento, "Linguine");
			alimenti_frigo[12].data_scadenza.giorno = 25;
			alimenti_frigo[12].data_scadenza.mese = 6;
			alimenti_frigo[12].data_scadenza.anno = 2018;
			alimenti_frigo[12].numero_pezzi = 20;
			alimenti_frigo[12].peso_unitario = 500;

			alimenti_frigo[13].id_alimento = 14;
			strcpy (alimenti_frigo[13].nome_alimento, "Gamberi");
			alimenti_frigo[13].data_scadenza.giorno = 25;
			alimenti_frigo[13].data_scadenza.mese = 6;
			alimenti_frigo[13].data_scadenza.anno = 2018;
			alimenti_frigo[13].numero_pezzi = 15;
			alimenti_frigo[13].peso_unitario = 100;

			alimenti_frigo[14].id_alimento = 15;
			strcpy (alimenti_frigo[14].nome_alimento, "Olio");
			alimenti_frigo[14].data_scadenza.giorno = 25;
			alimenti_frigo[14].data_scadenza.mese = 6;
			alimenti_frigo[14].data_scadenza.anno = 2018;
			alimenti_frigo[14].numero_pezzi = 20;
			alimenti_frigo[14].peso_unitario = 500;

			alimenti_frigo[15].id_alimento = 16;
			strcpy (alimenti_frigo[15].nome_alimento, "Aglio");
			alimenti_frigo[15].data_scadenza.giorno = 25;
			alimenti_frigo[15].data_scadenza.mese = 6;
			alimenti_frigo[15].data_scadenza.anno = 2018;
			alimenti_frigo[15].numero_pezzi = 30;
			alimenti_frigo[15].peso_unitario = 20;

			alimenti_frigo[16].id_alimento = 17;
			strcpy (alimenti_frigo[16].nome_alimento, "Brandy");
			alimenti_frigo[16].data_scadenza.giorno = 25;
			alimenti_frigo[16].data_scadenza.mese = 6;
			alimenti_frigo[16].data_scadenza.anno = 2018;
			alimenti_frigo[16].numero_pezzi = 20;
			alimenti_frigo[16].peso_unitario = 100;

			alimenti_frigo[17].id_alimento = 18;
			strcpy (alimenti_frigo[17].nome_alimento, "Sale grosso");
			alimenti_frigo[17].data_scadenza.giorno = 25;
			alimenti_frigo[17].data_scadenza.mese = 6;
			alimenti_frigo[17].data_scadenza.anno = 2018;
			alimenti_frigo[17].numero_pezzi = 20;
			alimenti_frigo[17].peso_unitario = 500;

			alimenti_frigo[18].id_alimento = 19;
			strcpy (alimenti_frigo[18].nome_alimento, "Basilico");
			alimenti_frigo[18].data_scadenza.giorno = 25;
			alimenti_frigo[18].data_scadenza.mese = 6;
			alimenti_frigo[18].data_scadenza.anno = 2018;
			alimenti_frigo[18].numero_pezzi = 100;
			alimenti_frigo[18].peso_unitario = 10;

			alimenti_frigo[19].id_alimento = 20;
			strcpy (alimenti_frigo[19].nome_alimento, "Pecorino");
			alimenti_frigo[19].data_scadenza.giorno = 25;
			alimenti_frigo[19].data_scadenza.mese = 6;
			alimenti_frigo[19].data_scadenza.anno = 2018;
			alimenti_frigo[19].numero_pezzi = 10;
			alimenti_frigo[19].peso_unitario = 100;

			alimenti_frigo[20].id_alimento = 21;
			strcpy (alimenti_frigo[20].nome_alimento, "Pinoli");
			alimenti_frigo[20].data_scadenza.giorno = 25;
			alimenti_frigo[20].data_scadenza.mese = 6;
			alimenti_frigo[20].data_scadenza.anno = 2018;
			alimenti_frigo[20].numero_pezzi = 20;
			alimenti_frigo[20].peso_unitario = 50;

			alimenti_frigo[21].id_alimento = 22;
			strcpy (alimenti_frigo[21].nome_alimento, "Parmigiano reggiano");
			alimenti_frigo[21].data_scadenza.giorno = 25;
			alimenti_frigo[21].data_scadenza.mese = 6;
			alimenti_frigo[21].data_scadenza.anno = 2018;
			alimenti_frigo[21].numero_pezzi = 15;
			alimenti_frigo[21].peso_unitario = 100;

			alimenti_frigo[22].id_alimento = 23;
			strcpy (alimenti_frigo[22].nome_alimento, "Riso");
			alimenti_frigo[22].data_scadenza.giorno = 25;
			alimenti_frigo[22].data_scadenza.mese = 6;
			alimenti_frigo[22].data_scadenza.anno = 2018;
			alimenti_frigo[22].numero_pezzi = 20;
			alimenti_frigo[22].peso_unitario = 500;

			alimenti_frigo[23].id_alimento = 24;
			strcpy (alimenti_frigo[23].nome_alimento, "Brodo vegetale");
			alimenti_frigo[23].data_scadenza.giorno = 25;
			alimenti_frigo[23].data_scadenza.mese = 6;
			alimenti_frigo[23].data_scadenza.anno = 2018;
			alimenti_frigo[23].numero_pezzi = 15;
			alimenti_frigo[23].peso_unitario = 1000;

			alimenti_frigo[24].id_alimento = 25;
			strcpy (alimenti_frigo[24].nome_alimento, "Cipolle rosse");
			alimenti_frigo[24].data_scadenza.giorno = 25;
			alimenti_frigo[24].data_scadenza.mese = 6;
			alimenti_frigo[24].data_scadenza.anno = 2018;
			alimenti_frigo[24].numero_pezzi = 20;
			alimenti_frigo[24].peso_unitario = 80;

			alimenti_frigo[25].id_alimento = 26;
			strcpy (alimenti_frigo[25].nome_alimento, "Vino bianco");
			alimenti_frigo[25].data_scadenza.giorno = 25;
			alimenti_frigo[25].data_scadenza.mese = 6;
			alimenti_frigo[25].data_scadenza.anno = 2018;
			alimenti_frigo[25].numero_pezzi = 20;
			alimenti_frigo[25].peso_unitario = 1000;

			alimenti_frigo[26].id_alimento = 27;
			strcpy (alimenti_frigo[26].nome_alimento, "Burro");
			alimenti_frigo[26].data_scadenza.giorno = 25;
			alimenti_frigo[26].data_scadenza.mese = 6;
			alimenti_frigo[26].data_scadenza.anno = 2018;
			alimenti_frigo[26].numero_pezzi = 20;
			alimenti_frigo[26].peso_unitario = 200;

			alimenti_frigo[27].id_alimento = 28;
			strcpy (alimenti_frigo[27].nome_alimento, "Sale fino");
			alimenti_frigo[27].data_scadenza.giorno = 25;
			alimenti_frigo[27].data_scadenza.mese = 6;
			alimenti_frigo[27].data_scadenza.anno = 2018;
			alimenti_frigo[27].numero_pezzi = 20;
			alimenti_frigo[27].peso_unitario = 500;

			alimenti_frigo[28].id_alimento = 29;
			strcpy (alimenti_frigo[28].nome_alimento, "Zucchine");
			alimenti_frigo[28].data_scadenza.giorno = 25;
			alimenti_frigo[28].data_scadenza.mese = 6;
			alimenti_frigo[28].data_scadenza.anno = 2018;
			alimenti_frigo[28].numero_pezzi = 20;
			alimenti_frigo[28].peso_unitario = 100;

			alimenti_frigo[29].id_alimento = 30;
			strcpy (alimenti_frigo[29].nome_alimento, "Patate");
			alimenti_frigo[29].data_scadenza.giorno = 22;
			alimenti_frigo[29].data_scadenza.mese = 6;
			alimenti_frigo[29].data_scadenza.anno = 2018;
			alimenti_frigo[29].numero_pezzi = 100;
			alimenti_frigo[29].peso_unitario = 90;

			alimenti_frigo[30].id_alimento = 31;
			strcpy (alimenti_frigo[30].nome_alimento, "Paprica");
			alimenti_frigo[30].data_scadenza.giorno = 21;
			alimenti_frigo[30].data_scadenza.mese = 6;
			alimenti_frigo[30].data_scadenza.anno = 2018;
			alimenti_frigo[30].numero_pezzi = 5;
			alimenti_frigo[30].peso_unitario = 200;

			alimenti_frigo[31].id_alimento = 32;
			strcpy (alimenti_frigo[31].nome_alimento, "Panna fresca");
			alimenti_frigo[31].data_scadenza.giorno = 2;
			alimenti_frigo[31].data_scadenza.mese = 7;
			alimenti_frigo[31].data_scadenza.anno = 2018;
			alimenti_frigo[31].numero_pezzi = 10;
			alimenti_frigo[31].peso_unitario = 500;

			alimenti_frigo[32].id_alimento = 33;
			strcpy (alimenti_frigo[32].nome_alimento, "Bacche di vaniglia");
			alimenti_frigo[32].data_scadenza.giorno = 8;
			alimenti_frigo[32].data_scadenza.mese = 7;
			alimenti_frigo[32].data_scadenza.anno = 2018;
			alimenti_frigo[32].numero_pezzi = 12;
			alimenti_frigo[32].peso_unitario = 15;

			alimenti_frigo[33].id_alimento = 34;
			strcpy (alimenti_frigo[33].nome_alimento, "Zucchero a velo");
			alimenti_frigo[33].data_scadenza.giorno = 23;
			alimenti_frigo[33].data_scadenza.mese = 6;
			alimenti_frigo[33].data_scadenza.anno = 2018;
			alimenti_frigo[33].numero_pezzi = 6;
			alimenti_frigo[33].peso_unitario = 100;

			alimenti_frigo[34].id_alimento = 35;
			strcpy (alimenti_frigo[34].nome_alimento, "Nutella");
			alimenti_frigo[34].data_scadenza.giorno = 23;
			alimenti_frigo[34].data_scadenza.mese = 9;
			alimenti_frigo[34].data_scadenza.anno = 2018;
			alimenti_frigo[34].numero_pezzi = 3;
			alimenti_frigo[34].peso_unitario = 500;

			alimenti_frigo[35].id_alimento = 36;
			strcpy (alimenti_frigo[35].nome_alimento, "Acqua");
			alimenti_frigo[35].data_scadenza.giorno = 23;
			alimenti_frigo[35].data_scadenza.mese = 10;
			alimenti_frigo[35].data_scadenza.anno = 2018;
			alimenti_frigo[35].numero_pezzi = 6;
			alimenti_frigo[35].peso_unitario = 1000;

			alimenti_frigo[36].id_alimento = 37;
			strcpy (alimenti_frigo[36].nome_alimento, "Ditaloni");
			alimenti_frigo[36].data_scadenza.giorno = 13;
			alimenti_frigo[36].data_scadenza.mese = 10;
			alimenti_frigo[36].data_scadenza.anno = 2018;
			alimenti_frigo[36].numero_pezzi = 4;
			alimenti_frigo[36].peso_unitario = 1000;

			for (int i=0; i<numero_alimenti; i++ ){								/*ciclo che itera per ogni elemnto del vettore*/
				if (alimenti_frigo[i].id_alimento > 0) {						/*scrive sul file solo gli elementi del vettore che hanno un id valido*/
					fwrite( &alimenti_frigo[i], sizeof(alimento), 1, file );
					elementi_scritti++;
				}
			}

		}

		fclose(file);

		return elementi_scritti;	/*restituisce il numero degli alimenti scritti sul file*/
}





/**
* La funzione apre il file in lettura, leggere ciascun record (la cui dimensione e' sizeof(ricetta))
* e lo assegna ad un elemento del vettore 'ricettario'.
* La funzione restituisce il puntatore al vettore ricettario.
* Se il file e' vuoto, viene richiamata la funzione popolazione_file_ricette()
* e successivamente in modo ricorsivo la funzione richiama se' stessa per caricare nel vettore
* i record del file appena popolato.
* Per tutti i restanti elementi del vettore a cui non e' stato assegnato nulla, l'id verra' azzerato
* cosi da sovrascrivere valori anomali e evitare bug.
*
* @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
* @pre numero_ricette deve essere un intero > 0
* @post il vettore restituito deve contenere almeno un elemento di tipo ricetta
*/

ricetta* carica_elenco_ricette ( char* nome_file, unsigned short int numero_ricette ) {

	ricetta* ricettario = malloc( numero_ricette * sizeof(ricetta));     /* allocazione dianmica in memoria di un vettore di ricette*/
	FILE *file;
	if ( (file = fopen (nome_file, "rb")) == NULL ) {					/* apertura del file in lettura */
		printf("Errore nell'apertura");
	}
	else {
		int i = 0;
		while( !feof(file) ) {                              		// ciclo che legge i contenuti del file
			fread (&ricettario[i], sizeof(ricetta), 1, file);  		// effettua una lettura di una ricetta dal file e la assegna ricettario[i]
			i++;
		}

		if ( i == 1 ) {                                           						/*se il file e' vuoto*/
			popolazione_file_ricette ( nome_file, numero_ricette );    					/* popola il file elenco_ricette.bin*/
			ricettario = carica_elenco_ricette ( nome_file, numero_ricette ); 			/* ricarica le ricette */
		} else{
			for(i--; i<numero_ricette; i++) {											/* altrimenti inizializza a 0 tutti gli id*/
				ricettario[i].id_ricetta = 0;											/* degli elementi del vettore per i quali non e' stato assegnato */
			}																			/* alcun record */
		}

	}

	fclose(file);
	return ricettario;  /* restituisce un puntatore al primo elemento del vettore */
}





/**
* La funzione apre il file in scrittura in modo da sostituire tutti i recor precedenti.
* Verra' allocato un vettore di tipo ricetta (ricettario) che conterra' un numero di elementi pari al secondo parametro 'numero_ricette'.
* Tutti i campi  di ciascun elemento del vettore verranno inizializzati da codice con dei valori opportuni.
* Solo gli elementi con un id valido (cioe >0) di tale vettore verranno scritti sul file.
* La funzione restituisce il numero di elementi effettivamnete scritti.
*
* @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
* @pre numero_ricette deve essere un intero > 0
* @post l'intero restituito sara' un volore compreso tra 1  e numero_ricette
* @bug da codice deve essere inizializzato almeno un elemento nel vettore ricettario altrimenti si avranno errori logici a runtime
*/

unsigned short int popolazione_file_ricette (char* nome_file, unsigned short int numero_ricette ) {

		FILE *file;
		unsigned short int elementi_scritti = 0;			/*contatore delle ricette scritte sul file*/

		if ( (file = fopen (nome_file, "wb")) == NULL ) {		/*apertura del file in scrittura*/
			printf("Errore nell'apertura");
		}
		else {

			/*dichiarazione e allocazione dinamica della memoria per un vettore di ricette*/
			ricetta* ricettario = malloc( numero_ricette * sizeof(ricetta));


			/*inizializzazione degli elementi del vettore ricettario*/

			ricettario[0].id_ricetta = 1;
			strcpy (ricettario[0].nome_ricetta, "Spumone al caffe");

			strcpy (ricettario[0].ingredienti[0].nome_alimento, "Caffe");
			strcpy (ricettario[0].ingredienti[0].quantita, "15");
			ricettario[0].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[0].ingredienti[1].nome_alimento, "Zucchero");
			strcpy (ricettario[0].ingredienti[1].quantita, "70");
			ricettario[0].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[0].ingredienti[2].nome_alimento, "Latte");
			strcpy (ricettario[0].ingredienti[2].quantita, "250");
			ricettario[0].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[0].ingredienti[3].nome_alimento, "Cacao");
			strcpy (ricettario[0].ingredienti[3].quantita, "qb");
			ricettario[0].ingredienti[3].unita_misura = ' ';

			ricettario[0].numero_ingredienti = 4;
			ricettario[0].complessita = BASSA;
			ricettario[0].kcal = 720;
			ricettario[0].n_persone = 4;
			ricettario[0].tempo_preparazione = 10;
			strcpy (ricettario[0].link_procedimento, "https://bit.ly/2rUgSMt");



			ricettario[1].id_ricetta = 2;
			strcpy (ricettario[1].nome_ricetta, "Spaghetti alla carbonara");

			strcpy (ricettario[1].ingredienti[0].nome_alimento, "Spaghetti");
			strcpy (ricettario[1].ingredienti[0].quantita, "320");
			ricettario[1].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[1].ingredienti[1].nome_alimento, "Guanciale");
			strcpy (ricettario[1].ingredienti[1].quantita, "150");
			ricettario[1].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[1].ingredienti[2].nome_alimento, "Uova");
			strcpy (ricettario[1].ingredienti[2].quantita, "280");
			ricettario[1].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[1].ingredienti[3].nome_alimento, "Pecorino romano");
			strcpy (ricettario[1].ingredienti[3].quantita, "50");
			ricettario[1].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[1].ingredienti[4].nome_alimento, "Sale fino");
			strcpy (ricettario[1].ingredienti[4].quantita, "qb");
			ricettario[1].ingredienti[4].unita_misura = ' ';

			strcpy (ricettario[1].ingredienti[5].nome_alimento, "Pepe nero");
			strcpy (ricettario[1].ingredienti[5].quantita, "qb");
			ricettario[1].ingredienti[5].unita_misura = ' ';

			ricettario[1].numero_ingredienti = 6;
			ricettario[1].complessita = BASSA;
			ricettario[1].kcal = 2320;
			ricettario[1].n_persone = 4;
			ricettario[1].tempo_preparazione = 15;
			strcpy (ricettario[1].link_procedimento, "https://bit.ly/2wivTgL");



			ricettario[2].id_ricetta = 3;
			strcpy (ricettario[2].nome_ricetta, "Pasta al pesto e gamberi");

			strcpy (ricettario[2].ingredienti[0].nome_alimento, "Linguine");
			strcpy (ricettario[2].ingredienti[0].quantita, "320");
			ricettario[2].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[2].ingredienti[1].nome_alimento, "Gamberi");
			strcpy (ricettario[2].ingredienti[1].quantita, "400");
			ricettario[2].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[2].ingredienti[2].nome_alimento, "Olio");
			strcpy (ricettario[2].ingredienti[2].quantita, "130");
			ricettario[2].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[2].ingredienti[3].nome_alimento, "Aglio");
			strcpy (ricettario[2].ingredienti[3].quantita, "6");
			ricettario[2].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[2].ingredienti[4].nome_alimento, "Brandy");
			strcpy (ricettario[2].ingredienti[4].quantita, "50");
			ricettario[2].ingredienti[4].unita_misura = 'g';

			strcpy (ricettario[2].ingredienti[5].nome_alimento, "Pepe nero");
			strcpy (ricettario[2].ingredienti[5].quantita, "qb");
			ricettario[2].ingredienti[5].unita_misura = ' ';

			strcpy (ricettario[2].ingredienti[6].nome_alimento, "Sale grosso");
			strcpy (ricettario[2].ingredienti[6].quantita, "qb");
			ricettario[2].ingredienti[6].unita_misura = ' ';

			strcpy (ricettario[2].ingredienti[7].nome_alimento, "Basilico");
			strcpy (ricettario[2].ingredienti[7].quantita, "50");
			ricettario[2].ingredienti[7].unita_misura = 'g';

			strcpy (ricettario[2].ingredienti[8].nome_alimento, "Pecorino");
			strcpy (ricettario[2].ingredienti[8].quantita, "50");
			ricettario[2].ingredienti[8].unita_misura = 'g';

			strcpy (ricettario[2].ingredienti[9].nome_alimento, "Pinoli");
			strcpy (ricettario[2].ingredienti[9].quantita, "15");
			ricettario[2].ingredienti[9].unita_misura = 'g';

			strcpy (ricettario[2].ingredienti[10].nome_alimento, "Parmigiano reggiano");
			strcpy (ricettario[2].ingredienti[10].quantita, "70");
			ricettario[2].ingredienti[10].unita_misura = 'g';

			ricettario[2].numero_ingredienti = 11;
			ricettario[2].complessita = BASSA;
			ricettario[2].kcal = 2720;
			ricettario[2].n_persone = 4;
			ricettario[2].tempo_preparazione = 40;
			strcpy (ricettario[2].link_procedimento, "https://bit.ly/2soWwv4");



			ricettario[3].id_ricetta = 4;
			strcpy (ricettario[3].nome_ricetta, "Risotto con zucchine");

			strcpy (ricettario[3].ingredienti[0].nome_alimento, "Riso");
			strcpy (ricettario[3].ingredienti[0].quantita, "320");
			ricettario[3].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[3].ingredienti[1].nome_alimento, "Zucchine");
			strcpy (ricettario[3].ingredienti[1].quantita, "350");
			ricettario[3].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[3].ingredienti[2].nome_alimento, "Brodo vegetale");
			strcpy (ricettario[3].ingredienti[2].quantita, "1000");
			ricettario[3].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[3].ingredienti[3].nome_alimento, "Cipolle rosse");
			strcpy (ricettario[3].ingredienti[3].quantita, "80");
			ricettario[3].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[3].ingredienti[4].nome_alimento, "Vino bianco");
			strcpy (ricettario[3].ingredienti[4].quantita, "100");
			ricettario[3].ingredienti[4].unita_misura = 'g';

			strcpy (ricettario[3].ingredienti[5].nome_alimento, "Burro");
			strcpy (ricettario[3].ingredienti[5].quantita, "50");
			ricettario[3].ingredienti[5].unita_misura = 'g';

			ricettario[3].numero_ingredienti = 6;
			ricettario[3].complessita = BASSA;
			ricettario[3].kcal = 1920;
			ricettario[3].n_persone = 4;
			ricettario[3].tempo_preparazione = 10;
			strcpy (ricettario[3].link_procedimento, "https://bit.ly/2sp9bhA");



			ricettario[4].id_ricetta = 5;
			strcpy (ricettario[4].nome_ricetta, "Uova sode");

			strcpy (ricettario[4].ingredienti[0].nome_alimento, "Uova");
			strcpy (ricettario[4].ingredienti[0].quantita, "240");
			ricettario[4].ingredienti[0].unita_misura = 'g';

			ricettario[4].numero_ingredienti = 1;
			ricettario[4].complessita = BASSA;
			ricettario[4].kcal = 520;
			ricettario[4].n_persone = 4;
			ricettario[4].tempo_preparazione = 2;
			strcpy (ricettario[4].link_procedimento, "https://bit.ly/2J1B6eU");



			ricettario[5].id_ricetta = 6;
			strcpy (ricettario[5].nome_ricetta, "Omlette");

			strcpy (ricettario[5].ingredienti[0].nome_alimento, "Uova");
			strcpy (ricettario[5].ingredienti[0].quantita, "120");
			ricettario[5].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[5].ingredienti[1].nome_alimento, "Latte");
			strcpy (ricettario[5].ingredienti[1].quantita, "30");
			ricettario[5].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[5].ingredienti[2].nome_alimento, "Sale fino");
			strcpy (ricettario[5].ingredienti[2].quantita, "qb");
			ricettario[5].ingredienti[2].unita_misura = ' ';

			strcpy (ricettario[5].ingredienti[3].nome_alimento, "Olio");
			strcpy (ricettario[5].ingredienti[3].quantita, "15");
			ricettario[5].ingredienti[3].unita_misura = 'g';

			ricettario[5].numero_ingredienti = 4;
			ricettario[5].complessita = BASSA;
			ricettario[5].kcal = 209;
			ricettario[5].n_persone = 1;
			ricettario[5].tempo_preparazione = 5;
			strcpy (ricettario[5].link_procedimento, "https://bit.ly/2L7eQkl");



			ricettario[6].id_ricetta = 7;
			strcpy (ricettario[6].nome_ricetta, "Patatine fritte");

			strcpy (ricettario[6].ingredienti[0].nome_alimento, "Patate");
			strcpy (ricettario[6].ingredienti[0].quantita, "1000");
			ricettario[6].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[6].ingredienti[1].nome_alimento, "Olio");
			strcpy (ricettario[6].ingredienti[1].quantita, "1000");
			ricettario[6].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[6].ingredienti[2].nome_alimento, "Sale");
			strcpy (ricettario[6].ingredienti[2].quantita, "qb");
			ricettario[6].ingredienti[2].unita_misura = ' ';

			strcpy (ricettario[6].ingredienti[3].nome_alimento, "Paprica");
			strcpy (ricettario[6].ingredienti[3].quantita, "qb");
			ricettario[6].ingredienti[3].unita_misura = ' ';

			ricettario[6].numero_ingredienti = 4;
			ricettario[6].complessita = BASSA;
			ricettario[6].kcal = 2209;
			ricettario[6].n_persone = 4;
			ricettario[6].tempo_preparazione = 20;
			strcpy (ricettario[6].link_procedimento, "https://bit.ly/2JlbnCi");




			ricettario[7].id_ricetta = 8;
			strcpy (ricettario[7].nome_ricetta, "Gelato alla panna");

			strcpy (ricettario[7].ingredienti[0].nome_alimento, "Panna fresca");
			strcpy (ricettario[7].ingredienti[0].quantita, "170");
			ricettario[7].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[7].ingredienti[1].nome_alimento, "Latte");
			strcpy (ricettario[7].ingredienti[1].quantita, "350");
			ricettario[7].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[7].ingredienti[2].nome_alimento, "Zucchero");
			strcpy (ricettario[7].ingredienti[2].quantita, "150");
			ricettario[7].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[7].ingredienti[3].nome_alimento, "Bacca di vaniglia");
			strcpy (ricettario[7].ingredienti[3].quantita, "2");
			ricettario[7].ingredienti[3].unita_misura = 'g';

			ricettario[7].numero_ingredienti = 4;
			ricettario[7].complessita = BASSA;
			ricettario[7].kcal = 1130;
			ricettario[7].n_persone = 4;
			ricettario[7].tempo_preparazione = 40;
			strcpy (ricettario[7].link_procedimento, "https://bit.ly/2JDJmVL");




			ricettario[8].id_ricetta = 9;
			strcpy (ricettario[8].nome_ricetta, "Gelato alla panna");

			strcpy (ricettario[8].ingredienti[0].nome_alimento, "Panna fresca");
			strcpy (ricettario[8].ingredienti[0].quantita, "170");
			ricettario[8].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[8].ingredienti[1].nome_alimento, "Latte");
			strcpy (ricettario[8].ingredienti[1].quantita, "350");
			ricettario[8].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[8].ingredienti[2].nome_alimento, "Zucchero");
			strcpy (ricettario[8].ingredienti[2].quantita, "140");
			ricettario[8].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[8].ingredienti[3].nome_alimento, "Bacche di vaniglia");
			strcpy (ricettario[8].ingredienti[3].quantita, "2");
			ricettario[8].ingredienti[3].unita_misura = 'g';

			ricettario[8].numero_ingredienti = 4;
			ricettario[8].complessita = BASSA;
			ricettario[8].kcal = 1130;
			ricettario[8].n_persone = 4;
			ricettario[8].tempo_preparazione = 40;
			strcpy (ricettario[8].link_procedimento, "https://bit.ly/2JDJmVL");





			ricettario[9].id_ricetta = 10;
			strcpy (ricettario[9].nome_ricetta, "Crepes alla nutella");

			strcpy (ricettario[9].ingredienti[0].nome_alimento, "Uova");
			strcpy (ricettario[9].ingredienti[0].quantita, "180");
			ricettario[9].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[9].ingredienti[1].nome_alimento, "Farina");
			strcpy (ricettario[9].ingredienti[1].quantita, "250");
			ricettario[9].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[9].ingredienti[2].nome_alimento, "Latte");
			strcpy (ricettario[9].ingredienti[2].quantita, "500");
			ricettario[9].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[9].ingredienti[3].nome_alimento, "Nutella");
			strcpy (ricettario[9].ingredienti[3].quantita, "qb");
			ricettario[9].ingredienti[3].unita_misura = ' ';

			strcpy (ricettario[9].ingredienti[4].nome_alimento, "Burro");
			strcpy (ricettario[9].ingredienti[4].quantita, "qb");
			ricettario[9].ingredienti[4].unita_misura = ' ';

			strcpy (ricettario[9].ingredienti[5].nome_alimento, "Zucchero a velo");
			strcpy (ricettario[9].ingredienti[5].quantita, "qb");
			ricettario[9].ingredienti[5].unita_misura = ' ';

			ricettario[9].numero_ingredienti = 6;
			ricettario[9].complessita = BASSA;
			ricettario[9].kcal = 2880;
			ricettario[9].n_persone = 8;
			ricettario[9].tempo_preparazione = 10;
			strcpy (ricettario[9].link_procedimento, "https://bit.ly/2HuwlsC");





			ricettario[10].id_ricetta = 11;
			strcpy (ricettario[10].nome_ricetta, "Dorayaki");

			strcpy (ricettario[10].ingredienti[0].nome_alimento, "Acqua");
			strcpy (ricettario[10].ingredienti[0].quantita, "180");
			ricettario[10].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[10].ingredienti[1].nome_alimento, "Farina");
			strcpy (ricettario[10].ingredienti[1].quantita, "240");
			ricettario[10].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[10].ingredienti[2].nome_alimento, "Uova");
			strcpy (ricettario[10].ingredienti[2].quantita, "120");
			ricettario[10].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[10].ingredienti[3].nome_alimento, "Lievito in polvere");
			strcpy (ricettario[10].ingredienti[3].quantita, "3");
			ricettario[10].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[10].ingredienti[4].nome_alimento, "Miele");
			strcpy (ricettario[10].ingredienti[4].quantita, "20");
			ricettario[10].ingredienti[4].unita_misura = 'g';

			strcpy (ricettario[10].ingredienti[5].nome_alimento, "Zucchero a velo");
			strcpy (ricettario[10].ingredienti[5].quantita, "150");
			ricettario[10].ingredienti[5].unita_misura = 'g';

			strcpy (ricettario[10].ingredienti[6].nome_alimento, "Olio");
			strcpy (ricettario[10].ingredienti[6].quantita, "qb");
			ricettario[10].ingredienti[6].unita_misura = ' ';

			ricettario[10].numero_ingredienti = 7;
			ricettario[10].complessita = BASSA;
			ricettario[10].kcal = 978;
			ricettario[10].n_persone = 6;
			ricettario[10].tempo_preparazione = 10;
			strcpy (ricettario[10].link_procedimento, "https://bit.ly/2sGq08K");





			ricettario[11].id_ricetta = 12;
			strcpy (ricettario[11].nome_ricetta, "Spaghetti e cozze");

			strcpy (ricettario[11].ingredienti[0].nome_alimento, "Spaghetti");
			strcpy (ricettario[11].ingredienti[0].quantita, "320");
			ricettario[11].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[11].ingredienti[1].nome_alimento, "Cozze");
			strcpy (ricettario[11].ingredienti[1].quantita, "1500");
			ricettario[11].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[11].ingredienti[2].nome_alimento, "Salsa");
			strcpy (ricettario[11].ingredienti[2].quantita, "350");
			ricettario[11].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[11].ingredienti[3].nome_alimento, "Olio");
			strcpy (ricettario[11].ingredienti[3].quantita, "70");
			ricettario[11].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[11].ingredienti[4].nome_alimento, "Aglio");
			strcpy (ricettario[11].ingredienti[4].quantita, "6");
			ricettario[11].ingredienti[4].unita_misura = 'g';

			strcpy (ricettario[11].ingredienti[5].nome_alimento, "Prezzemolo");
			strcpy (ricettario[11].ingredienti[5].quantita, "10");
			ricettario[11].ingredienti[5].unita_misura = 'g';

			strcpy (ricettario[11].ingredienti[6].nome_alimento, "Pepe nero");
			strcpy (ricettario[11].ingredienti[6].quantita, "qb");
			ricettario[11].ingredienti[6].unita_misura = ' ';

			ricettario[11].numero_ingredienti = 7;
			ricettario[11].complessita = BASSA;
			ricettario[11].kcal = 2472;
			ricettario[11].n_persone = 4;
			ricettario[11].tempo_preparazione = 40;
			strcpy (ricettario[11].link_procedimento, "https://bit.ly/2LyvWYu");




			ricettario[12].id_ricetta = 13;
			strcpy (ricettario[12].nome_ricetta, "Pasta e piselli");

			strcpy (ricettario[12].ingredienti[0].nome_alimento, "Ditaloni");
			strcpy (ricettario[12].ingredienti[0].quantita, "160");
			ricettario[12].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[12].ingredienti[1].nome_alimento, "Piselli");
			strcpy (ricettario[12].ingredienti[1].quantita, "200");
			ricettario[12].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[12].ingredienti[2].nome_alimento, "Cipolla");
			strcpy (ricettario[12].ingredienti[2].quantita, "25");
			ricettario[12].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[12].ingredienti[3].nome_alimento, "Acqua");
			strcpy (ricettario[12].ingredienti[3].quantita, "150");
			ricettario[12].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[12].ingredienti[4].nome_alimento, "Sale fino");
			strcpy (ricettario[12].ingredienti[4].quantita, "qb");
			ricettario[12].ingredienti[4].unita_misura = ' ';

			strcpy (ricettario[12].ingredienti[5].nome_alimento, "Pepe nero");
			strcpy (ricettario[12].ingredienti[5].quantita, "qb");
			ricettario[12].ingredienti[5].unita_misura = ' ';

			ricettario[12].numero_ingredienti = 6;
			ricettario[12].complessita = BASSA;
			ricettario[12].kcal = 1030;
			ricettario[12].n_persone = 2;
			ricettario[12].tempo_preparazione = 5;
			strcpy (ricettario[12].link_procedimento, "https://bit.ly/2JzjU3R");





			ricettario[13].id_ricetta = 14;
			strcpy (ricettario[13].nome_ricetta, "Gamberoni al forno");

			strcpy (ricettario[13].ingredienti[0].nome_alimento, "Gamberoni");
			strcpy (ricettario[13].ingredienti[0].quantita, "840");
			ricettario[13].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[13].ingredienti[1].nome_alimento, "Limone");
			strcpy (ricettario[13].ingredienti[1].quantita, "40");
			ricettario[13].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[13].ingredienti[2].nome_alimento, "Olio");
			strcpy (ricettario[13].ingredienti[2].quantita, "60");
			ricettario[12].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[13].ingredienti[3].nome_alimento, "Sale fino");
			strcpy (ricettario[13].ingredienti[3].quantita, "qb");
			ricettario[13].ingredienti[3].unita_misura = ' ';

			strcpy (ricettario[13].ingredienti[4].nome_alimento, "Prezzemolo");
			strcpy (ricettario[13].ingredienti[4].quantita, "qb");
			ricettario[13].ingredienti[4].unita_misura = ' ';

			strcpy (ricettario[13].ingredienti[5].nome_alimento, "Pepe nero");
			strcpy (ricettario[13].ingredienti[5].quantita, "qb");
			ricettario[13].ingredienti[5].unita_misura = ' ';

			ricettario[13].numero_ingredienti = 6;
			ricettario[13].complessita = BASSA;
			ricettario[13].kcal = 852;
			ricettario[13].n_persone = 4;
			ricettario[13].tempo_preparazione = 20;
			strcpy (ricettario[13].link_procedimento, "https://bit.ly/2Joib1K");




			ricettario[14].id_ricetta = 15;
			strcpy (ricettario[14].nome_ricetta, "Carpaccio di manzo");

			strcpy (ricettario[14].ingredienti[0].nome_alimento, "Filetto di manzo");
			strcpy (ricettario[14].ingredienti[0].quantita, "400");
			ricettario[14].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[14].ingredienti[1].nome_alimento, "Formaggio");
			strcpy (ricettario[14].ingredienti[1].quantita, "100");
			ricettario[14].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[14].ingredienti[2].nome_alimento, "Rucola");
			strcpy (ricettario[14].ingredienti[2].quantita, "100");
			ricettario[14].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[14].ingredienti[3].nome_alimento, "Limone");
			strcpy (ricettario[14].ingredienti[3].quantita, "70");
			ricettario[14].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[14].ingredienti[4].nome_alimento, "Olio");
			strcpy (ricettario[14].ingredienti[4].quantita, "100");
			ricettario[14].ingredienti[4].unita_misura = 'g';

			strcpy (ricettario[14].ingredienti[5].nome_alimento, "Pepe nero");
			strcpy (ricettario[14].ingredienti[5].quantita, "qb");
			ricettario[14].ingredienti[5].unita_misura = ' ';

			strcpy (ricettario[14].ingredienti[6].nome_alimento, "Sale fino");
			strcpy (ricettario[14].ingredienti[6].quantita, "qb");
			ricettario[14].ingredienti[6].unita_misura = ' ';

			ricettario[14].numero_ingredienti = 7;
			ricettario[14].complessita = BASSA;
			ricettario[14].kcal = 476;
			ricettario[14].n_persone = 4;
			ricettario[14].tempo_preparazione = 15;
			strcpy (ricettario[14].link_procedimento, "https://bit.ly/2JlInud");




			ricettario[15].id_ricetta = 16;
			strcpy (ricettario[15].nome_ricetta, "Polpette di zucca");

			strcpy (ricettario[15].ingredienti[0].nome_alimento, "Zucca");
			strcpy (ricettario[15].ingredienti[0].quantita, "180");
			ricettario[15].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[15].ingredienti[1].nome_alimento, "Pane");
			strcpy (ricettario[15].ingredienti[1].quantita, "100");
			ricettario[15].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[15].ingredienti[2].nome_alimento, "Formaggio");
			strcpy (ricettario[15].ingredienti[2].quantita, "30");
			ricettario[15].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[15].ingredienti[3].nome_alimento, "Uova");
			strcpy (ricettario[15].ingredienti[3].quantita, "60");
			ricettario[15].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[15].ingredienti[4].nome_alimento, "Pangrattato");
			strcpy (ricettario[15].ingredienti[4].quantita, "50");
			ricettario[15].ingredienti[4].unita_misura = 'g';

			strcpy (ricettario[15].ingredienti[5].nome_alimento, "Prezzemolo");
			strcpy (ricettario[15].ingredienti[5].quantita, "15");
			ricettario[15].ingredienti[5].unita_misura = 'g';

			strcpy (ricettario[15].ingredienti[6].nome_alimento, "Paprica");
			strcpy (ricettario[15].ingredienti[6].quantita, "qb");
			ricettario[15].ingredienti[6].unita_misura = ' ';

			strcpy (ricettario[15].ingredienti[7].nome_alimento, "Sale fino");
			strcpy (ricettario[15].ingredienti[7].quantita, "qb");
			ricettario[15].ingredienti[7].unita_misura = ' ';

			strcpy (ricettario[15].ingredienti[8].nome_alimento, "Provola");
			strcpy (ricettario[15].ingredienti[8].quantita, "60");
			ricettario[15].ingredienti[8].unita_misura = 'g';

			ricettario[15].numero_ingredienti = 9;
			ricettario[15].complessita = BASSA;
			ricettario[15].kcal = 675;
			ricettario[15].n_persone = 4;
			ricettario[15].tempo_preparazione = 20;
			strcpy (ricettario[15].link_procedimento, "https://bit.ly/2xQHfJD");





			ricettario[16].id_ricetta = 17;
			strcpy (ricettario[16].nome_ricetta, "Torta nal cioccolato");

			strcpy (ricettario[16].ingredienti[0].nome_alimento, "Cioccolato fondente");
			strcpy (ricettario[16].ingredienti[0].quantita, "150");
			ricettario[16].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[16].ingredienti[1].nome_alimento, "Cacao");
			strcpy (ricettario[16].ingredienti[1].quantita, "50");
			ricettario[16].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[16].ingredienti[2].nome_alimento, "Farina");
			strcpy (ricettario[16].ingredienti[2].quantita, "180");
			ricettario[16].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[16].ingredienti[3].nome_alimento, "Zucchero");
			strcpy (ricettario[16].ingredienti[3].quantita, "180");
			ricettario[16].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[16].ingredienti[4].nome_alimento, "Uova");
			strcpy (ricettario[16].ingredienti[4].quantita, "360");
			ricettario[16].ingredienti[4].unita_misura = 'g';

			strcpy (ricettario[16].ingredienti[5].nome_alimento, "Burro");
			strcpy (ricettario[16].ingredienti[5].quantita, "200");
			ricettario[16].ingredienti[5].unita_misura = 'g';

			strcpy (ricettario[16].ingredienti[6].nome_alimento, "Sale fino");
			strcpy (ricettario[16].ingredienti[6].quantita, "qb");
			ricettario[16].ingredienti[6].unita_misura = ' ';

			strcpy (ricettario[16].ingredienti[7].nome_alimento, "Lievito in polvere");
			strcpy (ricettario[16].ingredienti[7].quantita, "8");
			ricettario[16].ingredienti[7].unita_misura = 'g';

			ricettario[16].numero_ingredienti = 8;
			ricettario[16].complessita = BASSA;
			ricettario[16].kcal = 850;
			ricettario[16].n_persone = 8;
			ricettario[16].tempo_preparazione = 50;
			strcpy (ricettario[16].link_procedimento, "https://bit.ly/2JFRchy");





			ricettario[17].id_ricetta = 18;
			strcpy (ricettario[17].nome_ricetta, "Zucchine a scapece");

			strcpy (ricettario[17].ingredienti[0].nome_alimento, "Zucchine");
			strcpy (ricettario[17].ingredienti[0].quantita, "500");
			ricettario[17].ingredienti[0].unita_misura = 'g';

			strcpy (ricettario[17].ingredienti[1].nome_alimento, "Olio");
			strcpy (ricettario[17].ingredienti[1].quantita, "70");
			ricettario[17].ingredienti[1].unita_misura = 'g';

			strcpy (ricettario[17].ingredienti[2].nome_alimento, "Aceto");
			strcpy (ricettario[17].ingredienti[2].quantita, "40");
			ricettario[17].ingredienti[2].unita_misura = 'g';

			strcpy (ricettario[17].ingredienti[3].nome_alimento, "Aglio");
			strcpy (ricettario[17].ingredienti[3].quantita, "6");
			ricettario[17].ingredienti[3].unita_misura = 'g';

			strcpy (ricettario[17].ingredienti[4].nome_alimento, "Menta");
			strcpy (ricettario[17].ingredienti[4].quantita, "qb");
			ricettario[17].ingredienti[4].unita_misura = ' ';

			strcpy (ricettario[17].ingredienti[5].nome_alimento, "Pepe nero");
			strcpy (ricettario[17].ingredienti[5].quantita, "qb");
			ricettario[17].ingredienti[5].unita_misura = ' ';

			strcpy (ricettario[17].ingredienti[6].nome_alimento, "Sale fino");
			strcpy (ricettario[17].ingredienti[6].quantita, "20");
			ricettario[17].ingredienti[6].unita_misura = 'g';

			ricettario[17].numero_ingredienti = 7;
			ricettario[17].complessita = BASSA;
			ricettario[17].kcal = 920;
			ricettario[17].n_persone = 4;
			ricettario[17].tempo_preparazione = 10;
			strcpy (ricettario[17].link_procedimento, "https://bit.ly/2JFTIo7");



			for (int i=0; i<numero_ricette; i++ ){								/*ciclo che itera per ogni elemnto del vettore*/
				if (ricettario[i].id_ricetta > 0) {						/*scrive sul file solo gli elementi del vettore che hanno un id valido*/
					fwrite( &ricettario[i], sizeof(ricetta), 1, file );
					elementi_scritti++;
				}
			}


		}

		fclose(file);

		return elementi_scritti;	/*restituisce il numero degli alimenti scritti sul file*/
}





/**
* La funzione apre il file in lettura, leggere ciascun record (la cui dimensione e' sizeof(menu_giornaliero))
* e lo assegna ad un elemento del vettore 'menu_settimanale'.
* La funzione restituisce il puntatore al vettore menu_settimanale.
* Se il file e' vuoto, il vettore restituito avra' tutti i menu' giornalieri 'vuoti'.
* Per tutti i restanti elementi del vettore a cui non e' stato assegnato nulla, l'id verra' azzerato
* cosi da sovrascrivere valori anomali e evitare bug.
*
* @pre nome_file deve essere il nome di un file esistente, altrimenti si potrebbero avere errori a runtime.
* @pre numero_menu_giornalieri deve essere un intero > 0
* @post il vettore restituito deve contenere almeno un elemento di tipo menu_giornaliero (anche vuoto)
*/

menu_giornaliero* carica_menu_settimanale ( char* nome_file, unsigned short int numero_menu_giornalieri ) {

	menu_giornaliero* menu_settimanale = malloc( numero_menu_giornalieri * sizeof(menu_giornaliero));     /* allocazione in memoria di un vettore di menu giornalieri*/
	FILE *file;
	if ( (file = fopen (nome_file, "rb")) == NULL ) {			/*apertura del file in lettura*/
		printf("Errore nell'apertura");
	}
	else {
		int i = 0;
		while( !feof(file) ) {                              					// ciclo che legge i contenuti del file
			fread (&menu_settimanale[i], sizeof(menu_giornaliero), 1, file);  	// effettua una lettura di un menu_giornaliero dal file e la assegna menu_settimanale[i]
			i++;
		}

		for(i--; i<numero_menu_giornalieri; i++) {					/* inizializza a 0 tutti gli id*/
			menu_settimanale[i].id_menu = 0;						/* degli elementi del vettore per i quali non e' stato assegnato */
		}															/* alcun record */

	}

	fclose(file);
	return menu_settimanale;  /* restituisce un puntatore al primo elemento del vettore */
}


