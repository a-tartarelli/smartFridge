#include "carica_file.h"
#include "gestione_menu_settimanale.h"
#include "lista_spesa.h"

/**
 * @mainpage Il sistema 'Smart Fridge' trova la sua applicazione in ambiente domestico e si affianca a quelle che sono le abitudini alimentari familiari, consigliando piatti in base ai cibi presenti in frigorifero cosi' che si abbia sempre fantasia per la realizzazione di ricette piu' o meno complesse di giorno in giorno.
 */

int main(void) {

	setbuf(stdout, NULL);

	/*Dichiarazione variabili*/
	unsigned short int scelta;		/* input intero dell'utente per scegliere una voce dal menu iniziale */
	unsigned short int id_utente;	/* identificativo dell'utente su cui tutte le operazioni vengono svolte */
	data data_corrente;				/* data corrente necessaria per verificare se gli alimenti sono scaduti */
	char alimenti_esaurimento[NUMERO_ELEMENTI_ESAURIMENTO][LUNGHEZZA_NOME];
	unsigned short int contatore_esaurimento_alimenti = 0;
	unsigned short int contatore_scadenza_alimenti = 0;
	unsigned short int temp, i, flag = 0, j;
	unsigned short int is_ordinato = 0;
	unsigned short int num_alimenti_cercare;
	float kcal_temp;
	char* nome_alimento = (char*) calloc(LUNGHEZZA_NOME, sizeof(char));
	char insieme_alimenti[MAX_ALIMENTI_RICERCA][LUNGHEZZA_NOME];
	char alimenti_scadenza[NUMERO_ELEMENTI_SCADENZA][LUNGHEZZA_NOME];


	alimento* alimenti_frigo = carica_elenco_alimenti ( "elenco_alimenti.bin", NUMERO_ALIMENTI );	/* vettore di tipo alimento contenente 100 elementi */
	ricetta* ricettario = carica_elenco_ricette ( "elenco_ricette.bin", NUMERO_RICETTE );	/* vettore di tipo ricette contenente 50 elementi */
	ricetta* ricettario_copiato = copia_ricettario(ricettario, NUMERO_RICETTE);
	menu_giornaliero* menu_settimanale = carica_menu_settimanale ( "menu_settimanale.bin", NUMERO_MENU_GIORNALIERI );	/* vettore di tipo menu_giornaliero contenente 100 elementi */



	char messaggio[]= "\n\nMENU SCELTA\n"
			"Inserisci la tua scelta:\n"
			"1-  Passare al giorno successivo\n"
			"2-  Cambia utente\n"
			"3-  Cancella accout\n"
			"4-  Apri frigorifero\n"
			"5-  Aggiungere alimento nel frigo\n"
			"6-  Modificare alimenti presenti nel frigo\n"
			"7-  Apri ricettario\n"
			"8-  Aggiungere una ricetta all'elenco\n"
			"9-  Modificare una ricetta dell'elenco\n"
			"10- Cancellare una ricetta dall'elenco\n"
			"11- Visualizza menu settimanale\n"
			"12- Consuma pasto\n"
			"13- Modificare le informazioni relative ai pasti consumati in un giorno dal menu' settimanale\n"
			"14- Cancellare un pasto dal menu' settimanale\n"
			"15- Visualizzare la lista della spesa\n"
			"16- Suggeriscimi una ricetta (fatta con gli alimenti in prossima scadenza)\n"
			"17- Cercare ricetta/e per ingredienti/e\n"
			"18- Cercare ricette/a per soglia di kcal\n"
			"19- Ordinare le ricette per Kcal (crescente)\n"
			"20- Cancella lista della spesa\n"
			"21- Fine programma\n? \0";


	/*Elaborazione*/

	data_corrente = calcola_data_corrente();				/*impostazione della data corrente dal sistema*/
	stampa_data_corrente (data_corrente);					/*visualizzazione della data corrente*/

	id_utente = seleziona_utente ("elenco_utenti.bin");	/*funzione che fa inserire in input un identificativo all'utente e lo assegna a id_utente*/


	/* ciclo che si ripete finchea' l'utente non inserisce un input uguale a 21 */
	/* ad ogni iterazione verraa' visualizzato il menu e  l'input dell'utente sara' assegnato a scelta */

	while((scelta = inserisci_input_intero(messaggio, LUNGHEZZA_INPUT))  != NUMERO_VOCI_MENU){

		shell_sort_date (alimenti_frigo, NUMERO_ALIMENTI);
		contatore_esaurimento_alimenti = controlla_esaurimento_alimenti (alimenti_esaurimento, alimenti_frigo, NUMERO_ALIMENTI, SOGLIA_ESAURIMENTO);
		contatore_scadenza_alimenti = controlla_scadenza_alimenti  (alimenti_scadenza, alimenti_frigo, NUMERO_ALIMENTI, data_corrente, SOGLIA_SCADENZA);

		switch(scelta){						/* switch che eseguira' un operazione diversa in base all'input dell'utente */

		case 1:
			data_corrente = giorno_successivo (data_corrente);
			stampa_data_corrente (data_corrente);
			break;

		case 2:
			id_utente = seleziona_utente ("elenco_utenti.bin");
			break;

		case 3:
			id_utente = input_cancella_utente ("elenco_utenti.bin", "menu_settimanale.bin", id_utente, menu_settimanale, NUMERO_MENU_GIORNALIERI);
			break;

		case 4:
			apri_frigo (alimenti_frigo, NUMERO_ALIMENTI );
			stampa_alimenti_esaurimento (alimenti_esaurimento, contatore_esaurimento_alimenti);
			contatore_scadenza_alimenti = controlla_scadenza_alimenti  (alimenti_scadenza, alimenti_frigo, NUMERO_ALIMENTI, data_corrente, SOGLIA_SCADENZA);
			stampa_alimenti_scadenza (alimenti_scadenza, contatore_scadenza_alimenti, SOGLIA_SCADENZA);
			break;

		case 5:
			input_aggiungi_alimento ("elenco_alimenti.bin", alimenti_frigo, NUMERO_ALIMENTI );
			break;

		case 6:
			input_modifica_alimento ("elenco_alimenti.bin", alimenti_frigo, NUMERO_ALIMENTI);
			break;

		case 7:
			apri_ricettario (ricettario, NUMERO_RICETTE);
			break;

		case 8:
			input_aggiungi_ricetta ("elenco_ricette.bin", ricettario, NUMERO_RICETTE );
			break;

		case 9:
			input_modifica_ricetta ("elenco_ricette.bin", ricettario, NUMERO_RICETTE );
			break;

		case 10:
			apri_ricettario (ricettario, NUMERO_RICETTE);
			input_cancella_ricetta(ricettario, NUMERO_RICETTE);
			break;

		case 11:
			visualizza_menu_settimanale (menu_settimanale, NUMERO_MENU_GIORNALIERI, ricettario, id_utente);
			break;

		case 12:
			input_prepara_ricetta ( "menu_settimanale.bin", menu_settimanale, NUMERO_MENU_GIORNALIERI, ricettario, NUMERO_RICETTE, alimenti_frigo, NUMERO_ALIMENTI, id_utente, data_corrente );
			break;

		case 13:
			input_modifica_menu ( "menu_settimanale.bin", menu_settimanale, NUMERO_MENU_GIORNALIERI, ricettario, NUMERO_RICETTE, alimenti_frigo, NUMERO_ALIMENTI, id_utente, data_corrente );
			break;

		case 14:
			input_cancella_menu ( "menu_settimanale.bin", menu_settimanale, NUMERO_MENU_GIORNALIERI, ricettario, NUMERO_RICETTE, id_utente );
			break;

		case 15:

			if(stampa_lista_spesa("lista_spesa.txt") == 0) {
				printf("La lista della spesa e' vuota!\n");
			}


			break;

		case 16:
			stampa_alimenti_scadenza (alimenti_scadenza, contatore_scadenza_alimenti, SOGLIA_SCADENZA);
			printf("\nTi consiglio di preparare le seguenti ricette:\n\n");

			flag=0;
			if(contatore_scadenza_alimenti > 0) {

				for(i=0; i<contatore_scadenza_alimenti; i++) {
					if (ricerca_ricetta_alimento(ricettario, NUMERO_RICETTE, alimenti_scadenza[i])) {
						flag++;
					}
				}

				if(flag == 0) {
					printf("\nLa/e ricetta/e con gli alimenti in scadenza non e' presente nel ricettario\n");
				}

			} else printf("\nNon ci sono alimenti in scadenza");

			break;

		case 17:
			switch(input_ricerca_ricetta()) {

			case 1:
				temp = input_inserisci_id();

				if(is_ricetta_esistente(ricettario, NUMERO_RICETTE, temp)) {
					visualizza_ricetta(ricettario[temp-1]);
				} else printf("La ricetta non e' presente nel ricettario\n");

				break;

			case 2:
				input_alimento(nome_alimento);

				if (!ricerca_ricetta_alimento(ricettario, NUMERO_RICETTE, nome_alimento)) {
					printf("La/e ricetta/e con questo ingrediente non e' presente nel ricettario\n");
				}
				break;

			case 3:
				num_alimenti_cercare = input_numero_alimenti();
				input_insieme_alimenti(insieme_alimenti, num_alimenti_cercare);
				flag = 0;

				for(j=0; j<num_alimenti_cercare; j++) {

					if(ricerca_ricetta_alimento(ricettario, NUMERO_RICETTE, insieme_alimenti[j])) {
						flag++;
					}

				}

				if(flag == 0) {
					printf("La/e ricetta/e con questo/i ingredienti non e' presente nel ricettario\n");
				}


				break;

			case 4:
				printf("Ricerca terminata");
				break;
			}

			break;

		case 18:

			kcal_temp = inserisci_input_float("\nInserire la soglia di kcal da ricercare: ", LUNGHEZZA_INPUT);
			while (!is_compreso_tra(1, MAX_CALORIE, kcal_temp)) {
				kcal_temp = inserisci_input_intero("Non superare il limite massimo di 9000 kcal, reinserire valore: ", LUNGHEZZA_INPUT);
			}

			printf("Le ricette con kcal al di sotto di tale soglia sono: \n\n");
			if(!ricerca_ricetta_kcal(ricettario_copiato, NUMERO_RICETTE, kcal_temp, is_ordinato)) {
				printf("Non ci sono ricette con questa soglia di kcal\n");
			}
			break;

		case 19:
			quickSort(ricettario_copiato, 0, NUMERO_RICETTE-1);
			apri_ricettario (ricettario_copiato, NUMERO_RICETTE);

			is_ordinato = 1;
			break;

		case 20:
			if(cancella_lista_spesa("lista_spesa.txt")) {

				printf("\nLista della spesa cancellata.\n");

			} else printf("\nErrore nella cancellazione della lista della spesa.\n");
			break;

		default:
			printf("Scelta errata! Reinserire valore");
		}

		is_alimenti_scaduti  ( "elenco_alimenti.bin", alimenti_frigo, NUMERO_ALIMENTI, data_corrente );


	}
	printf("FINE PROGRAMMA.\n");
	return 0;
}
