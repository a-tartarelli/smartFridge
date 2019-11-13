#include "lista_spesa.h"


/**
 * @pre il file deve gia' esistere in memoria, altrimenti la lettura e la conseguente stampa non verra' effettuata
 * @return ritorna il numero di alimenti letti dal file
 */
unsigned short int stampa_lista_spesa (char* nome_file) {

	printf("\n******************** LISTA DELLA SPESA ********************\n");
	FILE* file;
	char record[LUNGHEZZA_NOME];
	unsigned short int valori_letti = 0;

	if ( (file = fopen (nome_file, "r+")) == NULL ) {
		printf("Errore nell'apertura");
	}
	else {

		while ( !feof( file ) ) {		// ciclo che legge i contenuti del file

			short int read = fscanf( file, "%s", record );	// effettua una scanf dal file

			if ( read > 0 ){				// se la scanf ha avuto successo
				printf( "• %s\n", record );		// stampa una parola letta dal file
				valori_letti++;
			}

		}
	}

	fclose(file);

	return valori_letti;
}


/**
 * @pre il file deve gia' esistere in memoria, altrimenti la lettura e la conseguente scrittura non verra' effettuata
 */
unsigned short int aggiungi_a_lista (char nome_file[], char* alimento) {
	unsigned short int is_presente = 0, flag_is_aggiunto = 0;
	FILE *file;
	FILE *file_aggiungi;
	char record[LUNGHEZZA_NOME];

	if ((file = fopen (nome_file, "r")) == NULL) {
		printf("Errore nell'apertura");
		return 0;
	}
	else {

		while (!feof(file)) {		// ciclo che legge i contenuti del file

			short int read = fscanf(file, "%s", record);	// effettua una scanf dal file

			if (read != feof(file)){

				if(strcasecmp(record, alimento) == 0) { //controllo se il record letto e' uguale all'alimento passato come parametro
					is_presente = 1; //imposto il flag su true
				}
			}
		}
	}

	fclose(file); //chiudo il file da cui ho letto i dati




	if(is_presente == 0) { //se il flag e' false scrivo il nuovo alimento sul file poiche' non e' presente

		if ((file_aggiungi = fopen (nome_file, "a")) == NULL) {
			printf("Errore nell'apertura");
			return 0;
		}
		else {
			fprintf(file_aggiungi, "%s\n", alimento);
			flag_is_aggiunto = 1;
		}

		fclose(file_aggiungi); //chiudo il file su cui ho scritto i dati


	}

	return flag_is_aggiunto;
}

/**
 * @pre il nome del file deve essere corretto, altrimenti si andra' a creare un altro file senza "cancellare" quello giusto
 */
unsigned short int cancella_lista_spesa(char nome_file[]) {
	FILE *file;
	unsigned short int flag;

	if ((file = fopen (nome_file, "w")) == NULL) {
		printf("Errore nell'apertura");
		flag = 0;
	}


	fclose(file); //chiudo il file che ho appena creato

	return flag = 1;
}

