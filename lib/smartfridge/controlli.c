#include <smartfridge/controlli.h>


/**
 * La funzione, per verificare se la stringa acquisista e' effettivamente un intero,
 * richiama la funzione is_intero(). Se is_intero() restituisce 0, verra' chiesto di reinserire
 * un altro valore e verra' rifatto lo stesso controllo. Altrimenti la stringa verra' convertita in intero e
 * verra' restituita come valore di ritorno.
 * Ogni volta che viene acquisisto un input da tastiera, viene richiamata la funzione svuota_buffer_input () per evitare bug.
 *
 * @pre messaggio deve contenere un messaggio significativo
 * @pre lunghezza_input deve essere > 1
 * @post il valore restituito deve corrispondere all'input inserito da tastiera
 * @bug se il secondo parametro e' troppo piccolo, potrebebro essere letti meno caratteri di quelli inseriti, producendo quindi un errore logico a runtime.
 */

short int inserisci_input_intero (char messaggio[], unsigned short int lunghezza_input) {
	char input[lunghezza_input];

	printf("%s", messaggio);
	fgets(input, lunghezza_input, stdin);

	svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/

	while(!is_intero(input)) {						/* ciclo che itera finche' l'input letto non e' un intero, cioe' quando is_intero(input) ritorna 0 */

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */

		fgets(input, lunghezza_input, stdin);
		svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/
	}

	return (short int) atoi(input) ;    /*l'input letto viene convertito in intero impostato come valore di ritorno*/
}





/** La funzione itera su ciascun carattere della stringa passata come parametro
 *  e utilizza isdigit() per verificare se tutti i caratteri sono effettivamente cifre.
 *  Se c'e' almeno un carattere che non e' una cifra, la funzione restituisce 0 altrimenti restituisce 1.
 *
 * @pre input la stringa deve contenere almeno un carattere
 * @post il valore restituito sara' 1 se la stringa e' un intero, 0 se la stringa non e' un intero
 */

unsigned short int is_intero (char input[]) {
	int input_corretto = 0;                   /*variabile che quando verra'a' posta a 1 determinera'a' che l'input e' un intero, altrimenti se non e' un intero verra'a' posta a 0*/

	for( int i=0; i<strlen(input); i++){      /*ciclo che itera per ogni carattere della stringa in input*/

		if( isdigit(input[i]) ){    /*controlla che tutti i caratteria siano cifre*/
			input_corretto = 1;
		} else {
			return 0;             /*se c'e anche un solo carattere che non e' una cifra, verra'a' restituito 0*/
		}

	}
	return input_corretto;    /*se tutti i caratteri sono cifre, verra'a' restituito 1*/
}





/**
 * @pre min deve essere un intero compreso tra -32768 e 32767
 * @pre max deve essere un intero compreso tra -32768 e 32767
 * @pre numero deve essere un intero compreso tra -32768 e 32767
 * @post il valore restituito deve esse 1 se numero e' compreso nell'intervallo, 0 altrimenti
 */

unsigned short int is_compreso_tra (short int min, short int max, short int numero){

	if ( numero>=min && numero<=max ){    /* se il numero e' compreso nell'intervallo [min, max] */
		return 1;
	} else {
		return 0;
	}

}





/**
 * @pre min deve essere un decimale compreso tra 1,175494351 E a' 38 e 3,402823466 E + 38
 * @pre max deve essere un decimale compreso tra 1,175494351 E a' 38 e 3,402823466 E + 38
 * @pre numero deve essere un decimale compreso tra 1,175494351 E a' 38 e 3,402823466 E + 38
 * @post il valore restituito deve esse 1 se numero e' compreso nell'intervallo, 0 altrimenti
 */

unsigned short int is_compreso_tra_float (float min, float max, float numero) {
	if ( numero>=min && numero<=max ){    /* se il numero e' compreso nell'intervallo [min, max] */
		return 1;
	} else {
		return 0;
	}
}





/**
 * La funzione, per verificare se la stringa acquisista e' effettivamente una stringa formata da solo lettere,
 * richiama la funzione is_stringa_caratteri() . Se is_stringa_caratteri() restituisce 0, verra' chiesto di reinserire
 * un'altra stringa e verra' rifatto lo stesso controllo. Altrimenti la stringa verra' restituita come valore di ritorno.
 * Ogni volta che viene acquisisto un input da tastiera, viene richiamata la funzione svuota_buffer_input () per evitare bug.
 *
 * @pre messaggio deve contenere un messaggio significativo
 * @pre lunghezza_input deve essere > 1
 * @post il valore restituito deve corrispondere all'input inserito da tastiera
 * @bug se il secondo parametro e' troppo piccolo, potrebebro essere letti meno caratteri di quelli inseriti, producendo quindi un errore logico a runtime.
 */

char* inserisci_input_caratteri (char messaggio[], unsigned short int lunghezza_input) {
	char* input = (char*) calloc(LUNGHEZZA_NOME, sizeof(char));		/*allocazione dinamica della memoria per la stringa input*/

	printf("%s", messaggio);
	fgets (input, lunghezza_input, stdin);

	svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/

	while(!is_stringa_caratteri (input)) {						/* ciclo che itera finche' l'input letto non e' formato da sole lettere, cioe' quando is_stringa_caratteri( input ) ritorna 0 */

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */

		fgets(input, lunghezza_input, stdin);
		svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/
	}

	//free(input);
	return input ;    /*l'input letto viene convertito in intero impostato come valore di ritorno*/
}





/** La funzione itera su ciascun carattere della stringa passata come parametro
 *  e utilizza isalpha() per verificare se tutti i caratteri sono effettivamente delle lettere.
 *  Se c'e' almeno un carattere che non e' una lettera, la funzione restituisce 0 altrimenti restituisce 1.
 *
 * @pre stringa la stringa deve contenere almeno un carattere
 * @post il valore restituito sara' 1 se la stringa e' formata da solo lettere, 0 se la stringa non e' formata da solo lettere
 */

unsigned short int is_stringa_caratteri (char stringa[]) {

	/*flag che se e' 0 indica che la stringa contiene anche cifre o simboli, se e' 1 vuol dire che la stringa e' formata da sole lettere*/
	unsigned short  int stringa_corretta = 0;

	for (int i=0; i<strlen(stringa); i++){		 /*ciclo che itera per ogni carattere della stringa in input*/
		if (isalpha (stringa[i])) {				 /*controlla che tutti i caratteria siano lettere*/
			stringa_corretta = 1;
		} else {
			return 0;				/*se c'e anche un solo carattere che e' una cifra o un simbolo, verra'a' restituito 0*/
		}
	}
	return stringa_corretta;		/*se tutti i caratteri sono lettere, verra'a' restituito 1*/
}





/**
 * La funzione, per verificare se la stringa acquisista e' effettivamente una stringa formata da solo lettere (compreso lo spazio),
 * richiama la funzione is_stringa_caratteri_spazio (). Se is_stringa_caratteri_spazio() restituisce 0, verra' chiesto di reinserire
 * un'altra stringa e verra' rifatto lo stesso controllo. Altrimenti la stringa verra' restituita come valore di ritorno.
 * Ogni volta che viene acquisisto un input da tastiera, viene richiamata la funzione svuota_buffer_input () per evitare bug.
 *
 * @pre messaggio deve contenere un messaggio significativo
 * @pre lunghezza_input deve essere > 1
 * @post il valore restituito deve corrispondere all'input inserito da tastiera
 * @bug se il secondo parametro e' troppo piccolo, potrebebro essere letti meno caratteri di quelli inseriti, producendo quindi un errore logico a runtime.
 */

char* inserisci_input_caratteri_spazio (char messaggio[], unsigned short int lunghezza_input) {
	char* input = (char*) calloc(LUNGHEZZA_NOME, sizeof(char));		/*allocazione dinamica della memoria per la stringa input*/

	printf("%s", messaggio);
	fgets (input, lunghezza_input, stdin);

	svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/

	while(!is_stringa_caratteri_spazio (input)) {	/* ciclo che itera finche' l'input letto non e' formato da sole lettere o spazi, cioe' quando is_stringa_caratteri_spazio( input ) ritorna 0 */

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */

		fgets(input, lunghezza_input, stdin);
		svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/
	}

	return input ;    /*l'input letto viene convertito in intero impostato come valore di ritorno*/
}





/** La funzione itera su ciascun carattere della stringa passata come parametro
 *  e utilizza isalpha() e isspace() per verificare se tutti i caratteri sono effettivamente delle lettere o spazi.
 *  Se c'e' almeno un carattere che non e' una lettera o uno spazio, la funzione restituisce 0 altrimenti restituisce 1.
 *
 * @pre stringa la stringa deve contenere almeno un carattere
 * @post il valore restituito sara' 1 se la stringa e' formata da solo lettere e spazi, 0 se la stringa non e' formata da solo lettere e spazi
 */

unsigned short int is_stringa_caratteri_spazio (char stringa[]) {

	/*flag che se e' 0 indica che la stringa contiene anche cifre o simboli, se e' 1 vuol dire che la stringa e' formata da sole lettere*/
	unsigned short  int stringa_corretta = 0;

	for (int i=0; i<strlen(stringa); i++){		 /*ciclo che itera per ogni carattere della stringa in input*/
		if (isalpha (stringa[i]) || isspace (stringa[i])) {				 /*controlla che tutti i caratteria siano lettere o spazi*/
			stringa_corretta = 1;
		} else {
			return 0;				/*se c'e anche un solo carattere che e' una cifra o un simbolo, verra'a' restituito 0*/
		}
	}
	return stringa_corretta;		/*se tutti i caratteri sono lettere, verra'a' restituito 1*/
}





/**
 * La funzione, per verificare se la stringa acquisista e' effettivamente un link valido (che iniza con https://bit.ly/),
 * richiama la funzione is_link (). Se is_link() restituisce 0, verra' chiesto di reinserire
 * un'altra stringa e verra' rifatto lo stesso controllo. Altrimenti la stringa verra' restituita come valore di ritorno.
 * Ogni volta che viene acquisisto un input da tastiera, viene richiamata la funzione svuota_buffer_input () per evitare bug.
 *
 * @pre messaggio deve contenere un messaggio significativo
 * @pre lunghezza_input deve essere > 1
 * @post il valore restituito deve corrispondere all'input inserito da tastiera
 * @bug se il secondo parametro e' troppo piccolo, potrebebro essere letti meno caratteri di quelli inseriti, producendo quindi un errore logico a runtime.
 */

char* inserisci_input_link (char messaggio[], unsigned short int lunghezza_input) {
	char* input = (char*) calloc(lunghezza_input, sizeof(char));		/*allocazione dinamica della memoria per la stringa input*/

	printf("%s", messaggio);
	fgets (input, lunghezza_input, stdin);

	svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/

	while(!is_link (input)) {						/* ciclo che itera finche' l'input letto non e' formato da sole lettere, cioe' quando is_stringa_caratteri( input ) ritorna 0 */

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */

		fgets(input, lunghezza_input, stdin);
		svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/
	}
	return input ;    /*l'input letto viene convertito in intero impostato come valore di ritorno*/
}





/** La funzione confronta i primi 15 caratteri della stringa passata come parametro con la stringa
 *  'link' e se sono uguali, restituisce 1, altrimenti restituisce 0.
 *
 * @pre stringa la stringa deve contenere almeno un carattere
 * @post il valore restituito sara' 1 se la stringa e' un link corretto, 0 se la stringa non e' un link corretto
 */

unsigned short int is_link (char stringa[]) {
	unsigned short  int stringa_corretta = 0;

	char link[LINK_BASE] = "https://bit.ly/";

	if(!strncmp(link, stringa, LINK_BASE)) {
		stringa_corretta = 1;
	} else return 0;

	return stringa_corretta;
}





/**
 * @pre input la stringa deve contenere almeno un carattere
 */

unsigned short int svuota_buffer_input (char* input) {

	char* p;
	p = strchr(input, '\n');
	if(p){   //controlla se esiste una newline
		*p = 0;
		return 0;
	} else {
		scanf("%*[^\n]");
		scanf("%*c");	//considera solo la stringa fino alla newline
		return 1;
	}

}





/*/** La procedura itera su ciascun carattere della stringa passata come parametro
 *  e assegna ad ogni carattere il terminatore '\0'.
 *
 * @pre s la stringa deve contenere almeno un carattere
 * @pre lunghezza deve essere il numero di elementi da cui e' formato il vettore passato come primo parametro
 * @bug se 'lunghezza' e' diverso dal numeor di caratteri da cui e' composta la stringa, si potrebebro verificare dei bug
 */

/*void pulisci_stringa(char s[], unsigned short int lunghezza){
	unsigned short int i;

	for (i = 0; i<lunghezza; i++) {
		s[i] = '\0';
	}
}*/





/**
 * La funzione, per verificare se la stringa acquisista e' effettivamente un numero decimale,
 * richiama la funzione is_float (). Se is_float() restituisce 0, verra' chiesto di reinserire
 * un'altra stringa e verra' rifatto lo stesso controllo. Altrimenti la stringa verra' convertita in decimale e
 * verra' restituita come valore di ritorno.
 * Ogni volta che viene acquisisto un input da tastiera, viene richiamata la funzione svuota_buffer_input () per evitare bug.
 *
 * @pre messaggio deve contenere un messaggio significativo
 * @pre lunghezza_input deve essere > 1
 * @post il valore restituito deve corrispondere all'input inserito da tastiera
 * @bug se il secondo parametro e' troppo piccolo, potrebebro essere letti meno caratteri di quelli inseriti, producendo quindi un errore logico a runtime.
 */

float inserisci_input_float (char messaggio[], unsigned short int lunghezza_input) {
	char input[lunghezza_input];

	printf("%s", messaggio);
	fgets(input, lunghezza_input, stdin);

	svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/

	while(!is_float(input)) {						/* ciclo che itera finche' l'input letto non e' un float, cioe' quando is_float( input ) ritorna 0 */

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */

		fgets(input, lunghezza_input, stdin);
		svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/
	}

	return (float) atof(input);    /*l'input letto viene convertito in float impostato come valore di ritorno*/
}





/** La funzione itera su ciascun carattere della stringa passata come parametro
 *  e utilizza isdigit() per verificare se tutti i caratteri sono effettivamente cifre oppure se un carattere e' un punto.
 *  Se c'e' almeno un carattere che non e' una cifra o un punto, la funzione restituisce 0 altrimenti restituisce 1.
 *
 * @pre input la stringa deve contenere almeno un carattere
 * @post il valore restituito sara' 1 se la stringa e' un decimale, 0 se la stringa non e' un decimale
 */

unsigned short int is_float (char input[]) {
	int input_corretto = 0;                   /*variabile che quando verra'a' posta a 1 determinera'a' che l'input e' un float, altrimenti se non e' un float verra'a' posta a 0*/

	for( int i=0; i<strlen(input); i++){      /*ciclo che itera per ogni carattere della stringa in input*/

		if( isdigit(input[i]) ||  input[i] == '.' ){    /*controlla che tutti i caratteria siano cifre*/
			input_corretto = 1;
		} else {
			return 0;             /*se c'e anche un solo carattere che non e' una cifra, verra'a' restituito 0*/
		}

	}
	return input_corretto;    /*se tutti i caratteri sono cifre, verra'a' restituito 1*/
}





/**
 * La funzione, per verificare se la stringa acquisista e' effettivamente un numero decimale o e' uguale a "qb",
 * richiama la funzione is_float (). Se is_float() restituisce 0 o se la stringa e' diversa da "qb", verra' chiesto di reinserire
 * un'altra stringa e verra' rifatto lo stesso controllo. Altrimenti la stringa verra' restituita come valore di ritorno.
 * Ogni volta che viene acquisisto un input da tastiera, viene richiamata la funzione svuota_buffer_input () per evitare bug.
 *
 * @pre messaggio deve contenere un messaggio significativo
 * @pre lunghezza_input deve essere > 1
 * @post il valore restituito deve corrispondere all'input inserito da tastiera
 * @bug se il secondo parametro e' troppo piccolo, potrebebro essere letti meno caratteri di quelli inseriti, producendo quindi un errore logico a runtime.
 */

char* inserisci_input_float_qb (char messaggio[], unsigned short int lunghezza_input) {
	char* input = (char*) calloc(lunghezza_input, sizeof(char));

	printf("%s", messaggio);
	fgets(input, lunghezza_input, stdin);

	svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/

	while(!is_float(input) && strcmp(input,"qb")) {						/* ciclo che itera finche' l'input letto non e' un float, cioe' quando is_float( input ) ritorna 0 */

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */

		fgets(input, lunghezza_input, stdin);
		svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/
	}

	return input;    /*l'input letto viene convertito in float impostato come valore di ritorno*/
}





/**
 * La funzione converte la stringa acquisita in una data attraverso la funzione split_data e,
 * per verificare se la data acquisista e' effettivamente una data corretta,
 * richiama la funzione is_data_corretta (). Se is_data_corretta () restituisce 0, verra' chiesto di reinserire
 * un'altra data e verra' rifatto lo stesso controllo. Altrimenti la data verra' restituita come valore di ritorno.
 * Ogni volta che viene acquisisto un input da tastiera, viene richiamata la funzione svuota_buffer_input () per evitare bug.
 *
 * @pre messaggio deve contenere un messaggio significativo
 * @pre lunghezza_input deve essere > 1
 * @post il valore restituito deve corrispondere all'input inserito da tastiera
 * @bug se il secondo parametro e' troppo piccolo, potrebebro essere letti meno caratteri di quelli inseriti, producendo quindi un errore logico a runtime.
 */

data inserisci_input_data (char messaggio[], unsigned short int lunghezza_input) {
	char* input = (char*) calloc(LUNGHEZZA_NOME, sizeof(char));		/*allocazione dinamica della memoria per la stringa input*/
	data data_input;			/*variabile di tipo data in cui verra'a' convertita la stringa*/

	printf("%s", messaggio);
	fgets (input, lunghezza_input, stdin);
	svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/


	data_input = split_data (input);

	while( !is_data_corretta (data_input) ) {

		printf("Valore errato! Reinserire: ");   /* viene stampato un messaggio di errore */

		fgets(input, lunghezza_input, stdin);
		svuota_buffer_input (input);				/*svuota il buffer di input per evitare bug*/

		data_input = split_data (input);
	}

	return data_input ;
}





/**
 * La funzione utilizza strtok() per dividere la stringa passata come parametro ogni
 * volta che c'e il carattere "/". Il primo token sara' il giorno, il secondo il mese e il terzo l'anno.
*/

data split_data (char* data_input) {
	data d;
	char *token ;

	if ((token = strtok(data_input, "/")) != NULL ){
		d.giorno = atoi(token);

		if ((token = strtok(NULL, "/")) != NULL ){
			d.mese = atoi(token);

			if ((token = strtok(NULL, "/")) != NULL ){
				d.anno = atoi(token);
			}
		}
	} else {

		d.giorno = 0;
		d.mese = 0;
		d.anno = 0;
	}

	return d;
}





/** La funzione controlla se l'anno e' compreso in un certo range di validita' e se so,
 * in base al mese, controlla se il giorno e' valido o meno.
 *
 * @pre data_input i campi della struct data devono contenere valori > 0
 * @post il valore restituito sara' 1 se la data e' corretta, 0 se la data non e' corretta
 */

unsigned short int is_data_corretta( data data_input ) {

	/*flag che se e' 0 indica che la data non e' corretta, se e' 1 vuol dire che la data e' corretta*/
	unsigned short  int data_corretta = 0;


	if ( !is_compreso_tra (MIN_ANNO, MAX_ANNO, data_input.anno)) {	/*se l'anno non e' compreso tra 1990 e 2019*/
		return 0;
	} else {
		switch ( data_input.mese ) {                                      /*selezione multipla per rendere valido il giorno di nascita in base al mese*/
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if ( is_compreso_tra (MIN_GIORNO, MAX_GIORNO, data_input.giorno) ){
				data_corretta = 1;
			}
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			if ( is_compreso_tra (MIN_GIORNO, MAX_GIORNO-1, data_input.giorno) ){
				data_corretta = 1;
			}
			break;

		case 2:
			if (data_input.anno % BISESTILE == 0) {           /*Se il mese e' 2 e l'anno e' bisestile*/
				if ( is_compreso_tra (MIN_GIORNO, GIORNI_FEBBRAIO, data_input.giorno) ){
					data_corretta = 1;
				}
			} else {
				if ( is_compreso_tra (MIN_GIORNO, GIORNI_FEBBRAIO-1, data_input.giorno) ){
					data_corretta = 1;
				}
			}
			break;

		default:
			return 0;
			break;
		}

	}
	return data_corretta;        /*restituisce il flag*/
}



