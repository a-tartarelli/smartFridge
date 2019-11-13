#include "gestione_menu_settimanale.h"
#include "lista_spesa.h"
#include "inizializza_vettori.h"
#include "CUnit/Basic.h"
#include "inizializza_vettori.h"

// SUITE DI INIZIALIZZAZIONE
int init_suite_default(void)
{
      return 0;
}

// SUITE DI PULITURA
int clean_suite_default(void)
{
      return 0;
}





/*
 * ASSERZIONI per le funzioni di
 *       date.h
 */

// ASSERZIONI PER IL TEST DELLA FUNZIONE giorno_successivo()
void test_giorno_successivo (void) {
	data data_minima;
	data_minima.giorno = MIN_GIORNO;
	data_minima.mese = MIN_MESE;
	data_minima.anno = MIN_ANNO;

	data succ_data_minima;
	succ_data_minima.giorno = MIN_GIORNO+1;
	succ_data_minima.mese = MIN_MESE;
	succ_data_minima.anno = MIN_ANNO;

	data data_massima;
	data_massima.giorno = MAX_GIORNO;
	data_massima.mese = MAX_MESE;
	data_massima.anno = MAX_ANNO;

	data succ_data_massima;
	succ_data_massima.giorno = MIN_GIORNO;
	succ_data_massima.mese = MIN_MESE;
	succ_data_massima.anno = MAX_ANNO+1;

	data data_errata;
	data_errata.giorno = 31;
	data_errata.mese = 2;
	data_errata.anno = 2018;

	data succ_data_errata;
	succ_data_errata.giorno = 1;
	succ_data_errata.mese = 3;
	succ_data_errata.anno = 2018;

	CU_ASSERT( giorno_successivo (data_massima).giorno == succ_data_massima.giorno &&
			   giorno_successivo (data_massima).mese == succ_data_massima.mese &&
			   giorno_successivo (data_massima).anno == succ_data_massima.anno
	);		/*input massimo*/
	CU_ASSERT( giorno_successivo (data_minima).giorno == succ_data_minima.giorno &&
			   giorno_successivo (data_minima).mese == succ_data_minima.mese &&
			   giorno_successivo (data_minima).anno == succ_data_minima.anno
	);		/*input minimo*/
	CU_ASSERT( giorno_successivo (data_errata).giorno == succ_data_errata.giorno &&
			   giorno_successivo (data_errata).mese == succ_data_errata.mese &&
			   giorno_successivo (data_errata).anno == succ_data_errata.anno
	);	/*input errato*/
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE giorno_precedente()
void test_giorno_precedente (void) {
	data data_minima;
	data_minima.giorno = MIN_GIORNO;
	data_minima.mese = MIN_MESE;
	data_minima.anno = MIN_ANNO;

	data prec_data_minima;
	prec_data_minima.giorno = MAX_GIORNO;
	prec_data_minima.mese = MAX_MESE;
	prec_data_minima.anno = MIN_ANNO-1;

	data data_massima;
	data_massima.giorno = MAX_GIORNO;
	data_massima.mese = MAX_MESE;
	data_massima.anno = MAX_ANNO;

	data prec_data_massima;
	prec_data_massima.giorno = MAX_GIORNO-1;
	prec_data_massima.mese = MAX_MESE;
	prec_data_massima.anno = MAX_ANNO;

	data data_errata;
	data_errata.giorno = 31;
	data_errata.mese = 2;
	data_errata.anno = 2018;

	data prec_data_errata;
	prec_data_errata.giorno = 30;
	prec_data_errata.mese = 2;
	prec_data_errata.anno = 2018;

	CU_ASSERT( giorno_precedente (data_massima).giorno == prec_data_massima.giorno &&
			   giorno_precedente (data_massima).mese == prec_data_massima.mese &&
			   giorno_precedente (data_massima).anno == prec_data_massima.anno
	);		/*input massimo*/
	CU_ASSERT( giorno_precedente (data_minima).giorno == prec_data_minima.giorno &&
			   giorno_precedente (data_minima).mese == prec_data_minima.mese &&
			   giorno_precedente (data_minima).anno == prec_data_minima.anno
	);		/*input minimo*/
	CU_ASSERT( giorno_precedente (data_errata).giorno == prec_data_errata.giorno &&
			   giorno_precedente (data_errata).mese == prec_data_errata.mese &&
			   giorno_precedente (data_errata).anno == prec_data_errata.anno
	);	/*input errato*/
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE get_giorno_settimana_char()
void test_get_giorno_settimana_char (void) {

	CU_ASSERT_STRING_EQUAL( get_giorno_settimana_char(6), "SABATO" );		/*input massimo*/
	CU_ASSERT_STRING_EQUAL( get_giorno_settimana_char(0), "DOMENICA" );		/*input minimo*/
	CU_ASSERT_STRING_EQUAL( get_giorno_settimana_char(-1), "ERRORE" );		/*input errato*/
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE get_giorno_settimana_intero()
void test_get_giorno_settimana_intero (void) {

	data data_minima;
	data_minima.giorno = MIN_GIORNO;
	data_minima.mese = MIN_MESE;
	data_minima.anno = MIN_ANNO;

	data data_massima;
	data_massima.giorno = MAX_GIORNO;
	data_massima.mese = MAX_MESE;
	data_massima.anno = MAX_ANNO;

	data data_errata;
	data_errata.giorno = 31;
	data_errata.mese = 2;
	data_errata.anno = 2018;


	CU_ASSERT_EQUAL( get_giorno_settimana_intero(data_minima), 1 );			/*input minimo*/
	CU_ASSERT_EQUAL( get_giorno_settimana_intero(data_massima), 4 );		/*input massimo*/
	CU_ASSERT_NOT_EQUAL( get_giorno_settimana_intero(data_errata), 6 );		/*input errato*/
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE confronta_date()
void test_confronta_date (void) {

	data data_minima;
	data_minima.giorno = MIN_GIORNO;
	data_minima.mese = MIN_MESE;
	data_minima.anno = MIN_ANNO;

	data data_massima;
	data_massima.giorno = MAX_GIORNO;
	data_massima.mese = MAX_MESE;
	data_massima.anno = MAX_ANNO;


	CU_ASSERT_EQUAL( confronta_date(data_minima, data_massima), 0 );			/*classe di equivalenza d1<d2*/
	CU_ASSERT_EQUAL( confronta_date(data_massima, data_minima), 1 );			/*classe di equivalenza d1>d2*/
	CU_ASSERT_EQUAL( confronta_date(data_massima, data_massima), 2 );		/*classe di equivalenza d1==d2*/
}







/*
 * ASSERZIONI per le funzioni di
 *       elaborazione_alimenti.h
 */

// ASSERZIONI PER IL TEST DELLA FUNZIONE aggiungi_alimento()
void test_aggiungi_alimento (void) {
	alimento alimento_frigo;
	alimento_frigo.id_alimento = 1;
	strcpy (alimento_frigo.nome_alimento, "Latte");
	alimento_frigo.data_scadenza.giorno = 23;
	alimento_frigo.data_scadenza.mese = 6;
	alimento_frigo.data_scadenza.anno = 2018;
	alimento_frigo.numero_pezzi = 10;
	alimento_frigo.peso_unitario = 100;

	CU_ASSERT_EQUAL( aggiungi_alimento("elenco_alimenti.bin", alimento_frigo), 1);	        /* file esistente */
	CU_ASSERT_EQUAL( aggiungi_alimento("", alimento_frigo), 0);								/* file non esistente */

}

// ASSERZIONI PER IL TEST DELLA FUNZIONE get_nuovo_id_alimento()
void test_get_nuovo_id_alimento (void) {
	array_alimenti_pieno = inizializza_array_alimenti_pieno ();
	array_alimenti_vuoto = inizializza_array_alimenti_vuoto ();

	CU_ASSERT_EQUAL( get_nuovo_id_alimento(array_alimenti_pieno, NUMERO_ALIMENTI), 101);	    /* array pieno */
	CU_ASSERT_EQUAL( get_nuovo_id_alimento(array_alimenti_vuoto, NUMERO_ALIMENTI), 1);			/* array vuoto */
	CU_ASSERT_NOT_EQUAL( get_nuovo_id_alimento(array_alimenti_pieno, 10), 101);				    /* numero alimenti non corrispondente alla lunghezza del vettore */
	CU_ASSERT_NOT_EQUAL( get_nuovo_id_alimento(array_alimenti_pieno, 0), 101);					/* numero alimenti nullo */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE get_ultimo_indice_alimento()
void test_get_ultimo_indice_alimento (void) {
	array_alimenti_pieno = inizializza_array_alimenti_pieno ();
	array_alimenti_vuoto = inizializza_array_alimenti_vuoto ();

	CU_ASSERT_EQUAL( get_ultimo_indice_alimento(array_alimenti_pieno, NUMERO_ALIMENTI), 99);	    /* array pieno */
	CU_ASSERT_EQUAL( get_ultimo_indice_alimento(array_alimenti_vuoto, NUMERO_ALIMENTI), 0);			/* array vuoto */
	CU_ASSERT_NOT_EQUAL( get_ultimo_indice_alimento(array_alimenti_pieno, 10), 99);					/* numero alimenti non corrispondente alla lunghezza del vettore */
	CU_ASSERT_NOT_EQUAL( get_ultimo_indice_alimento(array_alimenti_pieno, 0), 99);					/* numero alimenti nullo */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE is_alimento_esistente()
void test_is_alimento_esistente (void) {
	array_alimenti_pieno = inizializza_array_alimenti_pieno ();
	array_alimenti_vuoto = inizializza_array_alimenti_vuoto ();

	CU_ASSERT_EQUAL( is_alimento_esistente(array_alimenti_pieno, NUMERO_ALIMENTI, 2), 1);	    /* classe di equivalenza id esistente */
	CU_ASSERT_EQUAL( is_alimento_esistente(array_alimenti_pieno, NUMERO_ALIMENTI, 130), 0);	    /* classe di equivalenza id non esistente */
	CU_ASSERT_EQUAL( is_alimento_esistente(array_alimenti_vuoto, NUMERO_ALIMENTI, 0), 0);		/* array vuoto e id nullo */
	CU_ASSERT_NOT_EQUAL( is_alimento_esistente(array_alimenti_pieno, 10, 40), 1);				/* numero alimenti non corrispondente alla lunghezza del vettore */
	CU_ASSERT_NOT_EQUAL( is_alimento_esistente(array_alimenti_pieno, 0, 15), 1);				/* numero alimenti nullo */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE indice_id_alimento()
void test_indice_id_alimento (void) {
	array_alimenti_pieno = inizializza_array_alimenti_pieno ();
	array_alimenti_vuoto = inizializza_array_alimenti_vuoto ();

	CU_ASSERT_EQUAL( indice_id_alimento(array_alimenti_pieno, NUMERO_ALIMENTI, 3), 2);	    	/* id esistente */
	CU_ASSERT_NOT_EQUAL( indice_id_alimento(array_alimenti_pieno, NUMERO_ALIMENTI, 130), 100);	/* id non esistente */
	CU_ASSERT_EQUAL( indice_id_alimento(array_alimenti_vuoto, NUMERO_ALIMENTI, 0), 0);			/* array vuoto e id nullo */
	CU_ASSERT_NOT_EQUAL( indice_id_alimento(array_alimenti_pieno, 10, 12), 11);					/* numero alimenti non corrispondente alla lunghezza del vettore */
	CU_ASSERT_EQUAL( indice_id_alimento(array_alimenti_pieno, 0, 15), 0);					/* numero alimenti nullo */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE modifica_alimento()
void test_modifica_alimento (void) {
	alimento alimento_frigo;
	alimento_frigo.id_alimento = 1;
	strcpy (alimento_frigo.nome_alimento, "Latte");
	alimento_frigo.data_scadenza.giorno = 21;
	alimento_frigo.data_scadenza.mese = 6;
	alimento_frigo.data_scadenza.anno = 2018;
	alimento_frigo.numero_pezzi = 15;
	alimento_frigo.peso_unitario = 100;

	CU_ASSERT_EQUAL( modifica_alimento("elenco_alimenti.bin", alimento_frigo), 1);	        /* file esistente */
	CU_ASSERT_EQUAL( modifica_alimento("", alimento_frigo), 0);								/* file non esistente */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE is_scaduto()
void test_is_scaduto (void) {

	data data_odiena;
	data_odiena.giorno = 23;
	data_odiena.mese = 6;
	data_odiena.anno = 2018;


	alimento alimento_scaduto;
	alimento_scaduto.id_alimento = 1;
	strcpy (alimento_scaduto.nome_alimento, "Latte");
	alimento_scaduto.data_scadenza.giorno = 21;
	alimento_scaduto.data_scadenza.mese = 5;
	alimento_scaduto.data_scadenza.anno = 2018;
	alimento_scaduto.numero_pezzi = 3;
	alimento_scaduto.peso_unitario = 100;

	alimento alimento_scaduto_oggi;
	alimento_scaduto.id_alimento = 1;
	strcpy (alimento_scaduto.nome_alimento, "Salsa");
	alimento_scaduto.data_scadenza.giorno = 23;
	alimento_scaduto.data_scadenza.mese = 6;
	alimento_scaduto.data_scadenza.anno = 2018;
	alimento_scaduto.numero_pezzi = 3;
	alimento_scaduto.peso_unitario = 100;

	alimento alimento_non_scaduto;
	alimento_non_scaduto.id_alimento = 1;
	strcpy (alimento_non_scaduto.nome_alimento, "Uova");
	alimento_non_scaduto.data_scadenza.giorno = 11;
	alimento_non_scaduto.data_scadenza.mese = 7;
	alimento_non_scaduto.data_scadenza.anno = 2018;
	alimento_non_scaduto.numero_pezzi = 15;
	alimento_non_scaduto.peso_unitario = 100;

	alimento alimento_nullo;
	alimento_nullo.id_alimento = 0;
	strcpy (alimento_nullo.nome_alimento, "");
	alimento_nullo.data_scadenza.giorno = 0;
	alimento_nullo.data_scadenza.mese = 0;
	alimento_nullo.data_scadenza.anno = 0;
	alimento_nullo.numero_pezzi = 0;
	alimento_nullo.peso_unitario = 0;

	CU_ASSERT_EQUAL( is_scaduto (alimento_scaduto, data_odiena), 1);	        /* alimento con data scadenza < data_corrente */
	CU_ASSERT_EQUAL( is_scaduto (alimento_non_scaduto, data_odiena), 0);		/* alimento con data scadenza > data_corrente */
	CU_ASSERT_EQUAL( is_scaduto (alimento_scaduto_oggi, data_odiena), 1);		/* alimento con data scadenza = data_corrente */
	CU_ASSERT_EQUAL( is_scaduto (alimento_nullo, data_odiena), 1);			/* alimento con data scadenze nulla */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE cancella_alimento()
void test_cancella_alimento (void) {
	alimento alimento_frigo;
	alimento_frigo.id_alimento = 1;
	strcpy (alimento_frigo.nome_alimento, "Latte");
	alimento_frigo.data_scadenza.giorno = 21;
	alimento_frigo.data_scadenza.mese = 6;
	alimento_frigo.data_scadenza.anno = 2018;
	alimento_frigo.numero_pezzi = 15;
	alimento_frigo.peso_unitario = 100;

	CU_ASSERT_EQUAL( cancella_alimento ("elenco_alimenti.bin", alimento_frigo), 1);	        /* file esistente */
	CU_ASSERT_EQUAL( cancella_alimento ("", alimento_frigo), 0);							/* file non esistente */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE controlla_scadenza_alimenti()
void test_controlla_scadenza_alimenti (void) {

	data data_odiena;
	data_odiena.giorno = 10;
	data_odiena.mese = 6;
	data_odiena.anno = 2018;

	array_alimenti_pieno = inizializza_array_alimenti_pieno ();
	array_alimenti_vuoto = inizializza_array_alimenti_vuoto ();

	char alimenti_scadenza[NUMERO_ELEMENTI_SCADENZA][LUNGHEZZA_NOME];

	CU_ASSERT_EQUAL( controlla_scadenza_alimenti (alimenti_scadenza, array_alimenti_pieno, NUMERO_ALIMENTI, data_odiena, 65535), 100);	        /* array pieno e soglia scadenza massima */
	CU_ASSERT_EQUAL( controlla_scadenza_alimenti (alimenti_scadenza, array_alimenti_pieno, NUMERO_ALIMENTI, data_odiena, 0), 0);	        	/* array pieno e soglia scadenza nulla */
	CU_ASSERT_EQUAL( controlla_scadenza_alimenti (alimenti_scadenza, array_alimenti_vuoto, NUMERO_ALIMENTI, data_odiena, SOGLIA_SCADENZA), 0);	/* array vuoto */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE controlla_esaurimento_alimenti()
void test_controlla_esaurimento_alimenti (void) {

	array_alimenti_pieno = inizializza_array_alimenti_pieno ();
	array_alimenti_vuoto = inizializza_array_alimenti_vuoto ();
	array_alimenti_uguale = inizializza_array_alimenti_uguale ();

	char alimenti_esaurimento[NUMERO_ELEMENTI_ESAURIMENTO][LUNGHEZZA_NOME];

	CU_ASSERT_EQUAL( controlla_esaurimento_alimenti (alimenti_esaurimento, array_alimenti_pieno, NUMERO_ALIMENTI,  65535), NUMERO_ALIMENTI);	        	/* array pieno e soglia esaurimento massima */
	CU_ASSERT_EQUAL( controlla_esaurimento_alimenti (alimenti_esaurimento, array_alimenti_pieno, NUMERO_ALIMENTI, 0), 0);	        		/* array pieno e soglia esaurimento nulla */
	CU_ASSERT_EQUAL( controlla_esaurimento_alimenti (alimenti_esaurimento, array_alimenti_vuoto, NUMERO_ALIMENTI, SOGLIA_ESAURIMENTO), 0);	/* array vuoto */
	CU_ASSERT_EQUAL( controlla_esaurimento_alimenti (alimenti_esaurimento, array_alimenti_uguale, NUMERO_ALIMENTI, SOGLIA_ESAURIMENTO), 0);	/* array con alimenti tutti uguali in esaurimento */
}






/*
 * ASSERZIONI per le funzioni di
 *       gestione_menu_settimanale.h
 */

// ASSERZIONI PER IL TEST DELLA FUNZIONE  aggiungi_menu_giornaliero()
void test_aggiungi_menu_giornaliero (void) {

	menu_giornaliero menu_pieno;
	menu_pieno.id_menu = 1;
	menu_pieno.id_utente = 1;
	menu_pieno.kcal_giornaliere = 3000;
	menu_pieno.numero_pasti = 1;
	menu_pieno.pasti[0].id_ricetta = 3;
	menu_pieno.pasti[0].n_persone = 1;
	menu_pieno.data_menu.giorno = 29;
	menu_pieno.data_menu.mese = 6;
	menu_pieno.data_menu.anno = 2018;
	strcpy (menu_pieno.data_menu.giorno_settimana, "VENERDI");

	menu_giornaliero menu_vuoto;
	menu_vuoto.id_menu = 0;
	menu_vuoto.id_utente = 0;
	menu_vuoto.data_menu.giorno = 0;
	menu_vuoto.data_menu.mese = 0;
	menu_vuoto.data_menu.anno = 0;
	strcpy (menu_vuoto.data_menu.giorno_settimana, "");
	menu_vuoto.kcal_giornaliere = 0;
	menu_vuoto.numero_pasti = 0;

	CU_ASSERT_EQUAL( aggiungi_menu_giornaliero ("menu_settimanale.bin", menu_pieno, menu_pieno.data_menu), 1);	    /* file esistente */
	CU_ASSERT_EQUAL( aggiungi_menu_giornaliero ("", menu_pieno, menu_pieno.data_menu), 0);							/* file non esistente */
	CU_ASSERT_EQUAL( aggiungi_menu_giornaliero ("menu_settimanale.bin", menu_vuoto, menu_vuoto.data_menu), 1);		/* input nullo */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE  cancella_menu_giornaliero()
void test_cancella_menu_giornaliero (void) {

	data data_menu;
	data_menu.giorno = 23;
	data_menu.mese = 6;
	data_menu.anno = 2018;

	CU_ASSERT_EQUAL( cancella_menu_giornaliero ("menu_settimanale.bin", 10, data_menu), 1);	    			/* file esistente */
	CU_ASSERT_EQUAL( cancella_menu_giornaliero ("", 10, data_menu), 0);										/* file non esistente */
	CU_ASSERT_EQUAL( cancella_menu_giornaliero ("menu_settimanale.bin", NUMERO_UTENTI, data_menu), 1);		/* id_utente massimo */
	CU_ASSERT_EQUAL( cancella_menu_giornaliero ("menu_settimanale.bin", 1, data_menu), 1);					/* id_utente minimo */
	CU_ASSERT_EQUAL( cancella_menu_giornaliero ("menu_settimanale.bin", -1, data_menu), 1);					/* id_utente errato */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE get_nuovo_id_menu()
void test_get_nuovo_id_menu (void) {
	menu_settimanale_pieno = inizializza_menu_settimanale_pieno ();
	menu_settimanale_vuoto = inizializza_menu_settimanale_vuoto ();

	CU_ASSERT_EQUAL( get_nuovo_id_menu (menu_settimanale_pieno, NUMERO_MENU_GIORNALIERI), NUMERO_MENU_GIORNALIERI+1);	/* array pieno */
	CU_ASSERT_EQUAL( get_nuovo_id_menu (menu_settimanale_vuoto, NUMERO_MENU_GIORNALIERI), 1);	/* array vuoto */
	CU_ASSERT_NOT_EQUAL( get_nuovo_id_menu (menu_settimanale_pieno, 10), NUMERO_MENU_GIORNALIERI+1);				    /* numero menu giornalieri non corrispondente alla lunghezza del vettore */
	CU_ASSERT_NOT_EQUAL( get_nuovo_id_menu (menu_settimanale_pieno, 0), NUMERO_MENU_GIORNALIERI+1);					/* numero menu giornalieri nullo */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE get_ultimo_indice_menu()
void test_get_ultimo_indice_menu (void) {
	menu_settimanale_pieno = inizializza_menu_settimanale_pieno ();
	menu_settimanale_vuoto = inizializza_menu_settimanale_vuoto ();

	CU_ASSERT_EQUAL( get_ultimo_indice_menu (menu_settimanale_pieno, NUMERO_MENU_GIORNALIERI), NUMERO_MENU_GIORNALIERI-1);	/* array pieno */
	CU_ASSERT_EQUAL( get_ultimo_indice_menu (menu_settimanale_vuoto, NUMERO_MENU_GIORNALIERI), 0);	/* array vuoto */
	CU_ASSERT_NOT_EQUAL( get_ultimo_indice_menu (menu_settimanale_pieno, 10), NUMERO_MENU_GIORNALIERI-1);					/* numero menu giornalieri non corrispondente alla lunghezza del vettore */
	CU_ASSERT_NOT_EQUAL( get_ultimo_indice_menu (menu_settimanale_pieno, 0), NUMERO_MENU_GIORNALIERI-1);					/* numero menu giornalieri nullo */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE is_ricetta_preparabile()
void test_is_ricetta_preparabile (void) {
	array_alimenti_pieno = inizializza_array_alimenti_pieno ();
	array_alimenti_vuoto = inizializza_array_alimenti_vuoto ();

	ricetta ricetta_corretta;
	ricetta_corretta.id_ricetta = 1;
	ricetta_corretta.complessita = 1;
	strcpy(ricetta_corretta.ingredienti[0].nome_alimento, "Latte");
	ricetta_corretta.kcal = 125;
	strcpy(ricetta_corretta.link_procedimento, "https://bit.ly/2JbaNqs");
	ricetta_corretta.n_persone = 4;
	strcpy(ricetta_corretta.nome_ricetta, "Crostata amalfitana");
	ricetta_corretta.numero_ingredienti = 1;
	ricetta_corretta.tempo_preparazione = 40;

	ricetta ricetta_nulla;
	ricetta_nulla.id_ricetta = 0;
	ricetta_nulla.complessita = 0;
	ricetta_nulla.kcal = 0;
	strcpy(ricetta_nulla.link_procedimento, "");
	ricetta_nulla.n_persone = 0;
	strcpy(ricetta_nulla.nome_ricetta, "");
	ricetta_nulla.numero_ingredienti = 0;
	ricetta_nulla.tempo_preparazione = 0;

	CU_ASSERT_EQUAL( is_ricetta_preparabile (ricetta_corretta, array_alimenti_pieno, NUMERO_ALIMENTI, MAX_PERSONE), 1);	  /* input massimi */
	CU_ASSERT_EQUAL( is_ricetta_preparabile (ricetta_corretta, array_alimenti_vuoto, NUMERO_ALIMENTI, 1), 0);	  		  /* input minimi */
	CU_ASSERT_EQUAL( is_ricetta_preparabile (ricetta_nulla, array_alimenti_pieno, NUMERO_ALIMENTI, 1), 1);	  		  	  /* ricetta nulla */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE indice_id_menu()
void test_indice_id_menu (void) {
	menu_settimanale_pieno = inizializza_menu_settimanale_pieno ();
	menu_settimanale_vuoto = inizializza_menu_settimanale_vuoto ();

	CU_ASSERT_EQUAL( indice_id_menu (menu_settimanale_pieno, NUMERO_MENU_GIORNALIERI, 3), 2);	    	/* id esistente */
	CU_ASSERT_NOT_EQUAL( indice_id_menu (menu_settimanale_pieno, NUMERO_MENU_GIORNALIERI, 130), NUMERO_MENU_GIORNALIERI);	/* id non esistente */
	CU_ASSERT_EQUAL( indice_id_menu (menu_settimanale_vuoto, NUMERO_MENU_GIORNALIERI, 0), 0);			/* array vuoto e id nullo */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE is_menu_esistente()
void test_is_menu_esistente (void) {
	menu_settimanale_pieno = inizializza_menu_settimanale_pieno ();
	menu_settimanale_vuoto = inizializza_menu_settimanale_vuoto ();

	CU_ASSERT_EQUAL( is_menu_esistente(menu_settimanale_pieno, NUMERO_MENU_GIORNALIERI, 2, 1), 1);	    /* classe di equivalenza id_menu esistente */
	CU_ASSERT_EQUAL( is_menu_esistente(menu_settimanale_pieno, NUMERO_MENU_GIORNALIERI, 130, 1), 0);	    /* classe di equivalenza id_menu non esistente */
	CU_ASSERT_EQUAL( is_menu_esistente(	menu_settimanale_vuoto, NUMERO_MENU_GIORNALIERI, 0, 1), 0);		/* array vuoto e id_menu nullo */
}





/*
 * ASSERZIONI per le funzioni di
 *       gestione_utenti.h
 */

// ASSERZIONI PER IL TEST DELLA FUNZIONE aggiungi_utente()
void test_aggiungi_utente (void) {

	CU_ASSERT_EQUAL( aggiungi_utente("elenco_utenti.bin", "Antonio", 1), 2);	        	/* file esistente */
	CU_ASSERT_EQUAL( aggiungi_utente("", "Antonio", 1), 0);									/* file non esistente */
	CU_ASSERT_EQUAL( aggiungi_utente("elenco_utenti.bin", "", 1), 2);						/*nome utente nullo*/
	CU_ASSERT_EQUAL( aggiungi_utente("elenco_utenti.bin", "Antonio", NUMERO_UTENTI), NUMERO_UTENTI + 1);	/*id_ultimo_utente massimo*/
	CU_ASSERT_EQUAL( aggiungi_utente("elenco_utenti.bin", "Antonio", 0), 1);				/*id_ultimo_utente minimo*/
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE is_utente_esistente()
void test_is_utente_esistente (void) {

	CU_ASSERT_EQUAL( is_utente_esistente ("Antonio","elenco_utenti.bin"), 1);	        	/* file e nome utente esistenti */
	CU_ASSERT_EQUAL( is_utente_esistente ("Antonio",""), 0);	        					/* file non esitente */
	CU_ASSERT_EQUAL( is_utente_esistente ("Filippo","elenco_utenti.bin"), 0);	        	/* nome utente non esistente */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE ricerca_utente()
void test_ricerca_utente (void) {

	CU_ASSERT_STRING_EQUAL( ricerca_utente ("elenco_utenti.bin", 1 ), "Antonio");	        	/* file e id utente esistenti  */
	CU_ASSERT_EQUAL( ricerca_utente ("", 1 ), NULL);	        							/* file non esistente  */
	CU_ASSERT_EQUAL( ricerca_utente ("elenco_utenti.bin", 1000 ), NULL);	        		/* id utente non esistente  */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE cancella_utente()
void test_cancella_utente (void) {

	CU_ASSERT_EQUAL( cancella_utente ("elenco_utenti.bin", 1 ), 1);	        		/* file e id utente esistenti  */
	CU_ASSERT_EQUAL( cancella_utente ("", 1 ), 0);	        						/* file non esistente  */
	CU_ASSERT_EQUAL( cancella_utente ("elenco_utenti.bin", NUMERO_UTENTI ), 1);	    /* id utente massimo  */
	CU_ASSERT_EQUAL( cancella_utente ("elenco_utenti.bin", 1 ), 1);	    			/* id utente minimo  */
}






/*
 * ASSERZIONI per le funzioni di
 *       controlli.h
 */


// ASSERZIONI PER IL TEST DELLA FUNZIONE is_intero()
void test_is_intero (void) {
	CU_ASSERT_EQUAL( is_intero("65535") , 1 );	/*input massimo*/
	CU_ASSERT_EQUAL( is_intero("0") , 1 );	/*input minimo*/
	CU_ASSERT_EQUAL( is_intero("") , 0 );		/*input nullo*/
	CU_ASSERT_EQUAL( is_intero("dieci") , 0 );	/*input errato*/
}


void test_is_stringa_caratteri (void) {
	CU_ASSERT_EQUAL( is_stringa_caratteri("Verdure") , 1 );	/*input corretto*/
	CU_ASSERT_EQUAL( is_stringa_caratteri("") , 0 );		/*input nullo*/
	CU_ASSERT_EQUAL( is_stringa_caratteri("Verdur3") , 0 );	/*input errato*/
}


void test_is_compreso_tra (void) {
	CU_ASSERT_EQUAL( is_compreso_tra(1, MAX_CALORIE, MAX_CALORIE), 1 );	/*input massimo*/
	CU_ASSERT_EQUAL( is_compreso_tra(1, MAX_CALORIE, 2500), 1 );	/*input compreso*/
	CU_ASSERT_EQUAL(  is_compreso_tra(1, MAX_CALORIE, 9500), 0 );		/*input non compreso*/
	CU_ASSERT_EQUAL( is_compreso_tra(0, 0, 0), 1);	/*input nullo*/
}


void test_is_compreso_tra_float (void) {
	CU_ASSERT_EQUAL( is_compreso_tra_float(1, MAX_QUANTITA, MAX_QUANTITA), 1 );	/*input massimo*/
	CU_ASSERT_EQUAL( is_compreso_tra_float(1, MAX_QUANTITA, 1000), 1 );	/*input compreso*/
	CU_ASSERT_EQUAL(  is_compreso_tra_float(1, MAX_QUANTITA, MAX_QUANTITA+1), 0 );		/*input non compreso*/
	CU_ASSERT_EQUAL( is_compreso_tra_float(0, 0, 0), 1);	/*input errato*/
}

void test_is_link (void) {
	CU_ASSERT_EQUAL( is_link("https://bit.ly/dasd4"), 1 );	/*classe di equivalenza valida*/
	CU_ASSERT_EQUAL( is_link("https://google.it/"), 1 );	/*classe di equivalenza non valida*/
}


void test_is_float (void) {
	CU_ASSERT_EQUAL( is_float("65.5") , 1 );	/*input valido*/
	CU_ASSERT_EQUAL( is_float("65,5") , 0 );	/*input errato*/
	CU_ASSERT_EQUAL( is_float("0") , 1 );	/*input nullo*/
	CU_ASSERT_EQUAL( is_float("-65.5") , 0 );	/*input errato*/
}


void test_is_data_corretta (void) {
	data data_minima;
	data_minima.giorno = MIN_GIORNO;
	data_minima.mese = MIN_MESE;
	data_minima.anno = MIN_ANNO;

	data data_massima;
	data_massima.giorno = MAX_GIORNO;
	data_massima.mese = MAX_MESE;
	data_massima.anno = MAX_ANNO;

	data data_errata;
	data_errata.giorno = 31;
	data_errata.mese = 2;
	data_errata.anno = 2018;

	CU_ASSERT_EQUAL( is_data_corretta(data_minima) , 1 );	/*data minima valida*/
	CU_ASSERT_EQUAL( is_data_corretta(data_massima) , 1 );	/*data massima valida*/
	CU_ASSERT_EQUAL( is_data_corretta(data_errata) , 0 );	/*esempio di data errato*/
}






/*
 * ASSERZIONI per le funzioni di
 *       elaborazione_ricette.h
 */

// ASSERZIONI PER IL TEST DELLA FUNZIONEaggiungi_ricetta()
void test_aggiungi_ricetta (void) {
	ricetta ricetta_nuova;
	ricetta_nuova.id_ricetta = 1;
	ricetta_nuova.complessita = 1;
	strcpy(ricetta_nuova.ingredienti[0].nome_alimento, "Latte");
	ricetta_nuova.kcal = 125;
	strcpy(ricetta_nuova.link_procedimento, "https://bit.ly/2JbaNqs");
	ricetta_nuova.n_persone = 4;
	strcpy(ricetta_nuova.nome_ricetta, "Crostata amalfitana");
	ricetta_nuova.numero_ingredienti = 1;
	ricetta_nuova.tempo_preparazione = 40;


	CU_ASSERT_EQUAL( aggiungi_ricetta("elenco_ricette.bin", ricetta_nuova), 1);	        /* file esistente */
	CU_ASSERT_EQUAL( aggiungi_ricetta("", ricetta_nuova), 0);							/* file non esistente */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE get_ultimo_indice_ricetta()
void test_get_ultimo_id_ricetta (void) {
	array_ricette_pieno = inizializza_array_ricette_pieno ();
	array_ricette_vuoto = inizializza_array_ricette_vuoto ();

	CU_ASSERT_EQUAL( get_ultimo_id_ricetta(array_ricette_pieno, NUMERO_RICETTE), 50);	    /* array pieno */
	CU_ASSERT_EQUAL( get_ultimo_id_ricetta(array_ricette_vuoto, NUMERO_RICETTE), 0);			/* array vuoto */
	CU_ASSERT_NOT_EQUAL( get_ultimo_id_ricetta(array_ricette_pieno, 10), 49);					/* numero alimenti non corrispondente alla lunghezza del vettore */
	CU_ASSERT_NOT_EQUAL( get_ultimo_id_ricetta(array_ricette_pieno, 0), 49);					/* numero alimenti nullo */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE get_ultimo_indice_ricetta()
void test_get_ultimo_indice_ricetta (void) {
	array_ricette_pieno = inizializza_array_ricette_pieno ();
	array_ricette_vuoto = inizializza_array_ricette_vuoto ();

	CU_ASSERT_EQUAL( get_ultimo_indice_ricetta(array_ricette_pieno, NUMERO_RICETTE), 49);	    /* array pieno */
	CU_ASSERT_EQUAL( get_ultimo_indice_ricetta(array_ricette_vuoto, NUMERO_RICETTE), 0);			/* array vuoto */
	CU_ASSERT_NOT_EQUAL( get_ultimo_indice_ricetta(array_ricette_pieno, 10), 49);					/* numero alimenti non corrispondente alla lunghezza del vettore */
	CU_ASSERT_NOT_EQUAL( get_ultimo_indice_ricetta(array_ricette_pieno, 0), 49);					/* numero alimenti nullo */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE modifica_ricetta()
void test_modifica_ricetta (void) {
	ricetta ricetta_nuova;
	ricetta_nuova.id_ricetta = 1;
	ricetta_nuova.complessita = 1;
	strcpy(ricetta_nuova.ingredienti[0].nome_alimento, "Latte");
	ricetta_nuova.kcal = 125;
	strcpy(ricetta_nuova.link_procedimento, "https://bit.ly/2JbaNqs");
	ricetta_nuova.n_persone = 4;
	strcpy(ricetta_nuova.nome_ricetta, "Crostata amalfitana");
	ricetta_nuova.numero_ingredienti = 1;
	ricetta_nuova.tempo_preparazione = 40;

	CU_ASSERT_EQUAL( modifica_ricetta("elenco_ricette.bin", ricetta_nuova), 1);	        /* file esistente */
	CU_ASSERT_EQUAL( modifica_ricetta("", ricetta_nuova), 0);								/* file non esistente */
}


// ASSERZIONI PER IL TEST DELLA FUNZIONE indice_id_ricetta()
void test_indice_id_ricetta (void) {
	array_ricette_pieno = inizializza_array_ricette_pieno ();
	array_ricette_vuoto = inizializza_array_ricette_vuoto ();

	CU_ASSERT_EQUAL( indice_id_ricetta(array_ricette_pieno, NUMERO_RICETTE, 3), 2);	    	/* id esistente */
	CU_ASSERT_EQUAL( indice_id_ricetta(array_ricette_pieno, NUMERO_RICETTE, 130), 100);		/* id non esistente */
	CU_ASSERT_EQUAL( indice_id_ricetta(array_ricette_vuoto, NUMERO_RICETTE, 0), 0);			/* array vuoto e id nullo */
	CU_ASSERT_NOT_EQUAL( indice_id_ricetta(array_ricette_pieno, 10, 12), 11);					/* numero ricette non corrispondente alla lunghezza del vettore */

}


// ASSERZIONI PER IL TEST DELLA FUNZIONE is_alimento_esistente()
void test_is_ricetta_esistente (void) {
	array_ricette_pieno = inizializza_array_ricette_pieno ();
	array_ricette_vuoto = inizializza_array_ricette_vuoto ();

	CU_ASSERT_EQUAL( is_ricetta_esistente(array_ricette_pieno, NUMERO_RICETTE, 2), 1);	    /* classe di equivalenza id esistente */
	CU_ASSERT_EQUAL( is_ricetta_esistente(array_ricette_pieno, NUMERO_RICETTE, 130), 0);	    /* classe di equivalenza id non esistente */
	CU_ASSERT_EQUAL( is_ricetta_esistente(array_ricette_vuoto, NUMERO_RICETTE, 0), 0);		/* array vuoto e id nullo */
	CU_ASSERT_NOT_EQUAL( is_ricetta_esistente(array_ricette_pieno, 10, 40), 1);				/* numero ricette non corrispondente alla lunghezza del vettore */
	CU_ASSERT_NOT_EQUAL( is_ricetta_esistente(array_ricette_pieno, 0, 15), 1);				/* numero alimenti nullo */
}

// ASSERZIONI PER IL TEST DELLA FUNZIONE cancella_ricetta()
void test_cancella_ricetta (void) {
	ricetta ricetta_nuova;
	ricetta_nuova.id_ricetta = 1;
	ricetta_nuova.complessita = 1;
	strcpy(ricetta_nuova.ingredienti[0].nome_alimento, "Latte");
	ricetta_nuova.kcal = 125;
	strcpy(ricetta_nuova.link_procedimento, "https://bit.ly/2JbaNqs");
	ricetta_nuova.n_persone = 4;
	strcpy(ricetta_nuova.nome_ricetta, "Crostata amalfitana");
	ricetta_nuova.numero_ingredienti = 1;
	ricetta_nuova.tempo_preparazione = 40;

	CU_ASSERT_EQUAL( cancella_ricetta ("elenco_alimenti.bin", ricetta_nuova.id_ricetta), 1);	        /* file esistente */
	CU_ASSERT_EQUAL( cancella_ricetta ("nome_file_non_valido.bin", ricetta_nuova.id_ricetta), 0);		/* file non esistente */
	CU_ASSERT_EQUAL( cancella_ricetta ("elenco_alimenti.bin", 100), 1);									/*id ricetta errato*/
}






/*
 * ASSERZIONI per le funzioni di
 *       lista_spesa.h
 */

// ASSERZIONI PER IL TEST DELLA FUNZIONE aggiungi_a_lista()
void test_aggiungi_a_lista (void) {
	int seed = time(NULL);
	srand(seed);

	char nome_file_non_valido[LUNGHEZZA_NOME];
	sprintf(nome_file_non_valido,"file_non_valido%d",  rand() % 1000);

	CU_ASSERT_EQUAL(aggiungi_a_lista("lista_spesa.txt", "Marmellata"), 1);	        /* caso valido */
	CU_ASSERT_EQUAL(aggiungi_a_lista(nome_file_non_valido, array_alimenti_pieno[1].nome_alimento), 0);	/* file non esistente */
	CU_ASSERT_EQUAL(aggiungi_a_lista("lista_spesa.txt", " "), 1);				/* alimento passato nullo */
	CU_ASSERT_EQUAL(aggiungi_a_lista("lista_spesa.txt", "Cipolle"), 0);			/*caso in cui l'alimento e' gia' presente in lista*/

}


// ASSERZIONI PER IL TEST DELLA FUNZIONE cancella_lista_spesa()
void test_cancella_lista_spesa (void) {

	CU_ASSERT_NOT_EQUAL(cancella_lista_spesa("nome_file_non_valido"), 0);	/* file non esistente, verra' creato un file con il nome sbagliato non cancellando quello giusto */
	CU_ASSERT_EQUAL(cancella_lista_spesa("lista_spesa.txt"), 1);				/* il file viene cancellato correttamente */

}






// MAIN: inizializza il registro, crea le test suite e aggiunge i test method
int main()
{
	CU_initialize_registry();

	// Creo diverse test suite, a seconda delle funzioni da testare
	CU_pSuite pSuite_Date = CU_add_suite("Suite_Date", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_Alimenti = CU_add_suite("Suite_Alimenti", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_Menu = CU_add_suite("Suite_Menu", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_Utenti = CU_add_suite("Suite_Utenti", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_Lista_spesa = CU_add_suite("Suite_Lista_spesa", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_controlli_h = CU_add_suite("Suite_Controlli", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_Ricette = CU_add_suite("Suite_Ricette", init_suite_default, clean_suite_default);

	// Aggiunta dei test method
	CU_add_test(pSuite_Date, "test of giorno_successivo()", test_giorno_successivo);
	CU_add_test(pSuite_Date, "test of giorno_precedente()", test_giorno_precedente);
	CU_add_test(pSuite_Date, "test of get_giorno_settimana_char()", test_get_giorno_settimana_char);
	CU_add_test(pSuite_Date, "test of get_giorno_settimana_intero()", test_get_giorno_settimana_intero);
	CU_add_test(pSuite_Date, "test of confronta_date()", test_confronta_date);

	CU_add_test(pSuite_Alimenti, "test of aggiungi_alimento()", test_aggiungi_alimento);
	CU_add_test(pSuite_Alimenti, "test of get_nuovo_id_alimento()", test_get_nuovo_id_alimento);
	CU_add_test(pSuite_Alimenti, "test of get_ultimo_indice_alimento()", test_get_ultimo_indice_alimento);
	CU_add_test(pSuite_Alimenti, "test of is_alimento_esistente()", test_is_alimento_esistente);
	CU_add_test(pSuite_Alimenti, "test of indice_id_alimento()", test_indice_id_alimento);
	CU_add_test(pSuite_Alimenti, "test of modifica_alimento()", test_modifica_alimento);
	CU_add_test(pSuite_Alimenti, "test of is_scaduto()", test_is_scaduto);
	CU_add_test(pSuite_Alimenti, "test of cancella_alimento()", test_cancella_alimento);
	CU_add_test(pSuite_Alimenti, "test of controlla_scadenza_alimenti()", test_controlla_scadenza_alimenti);
	CU_add_test(pSuite_Alimenti, "test of controlla_esaurimento_alimenti()", test_controlla_esaurimento_alimenti);

	CU_add_test(pSuite_Menu, "test of aggiungi_menu_giornaliero()", test_aggiungi_menu_giornaliero);
	CU_add_test(pSuite_Menu, "test of cancella_menu_giornaliero()", test_cancella_menu_giornaliero);
	CU_add_test(pSuite_Menu, "test of get_nuovo_id_menu()", test_get_nuovo_id_menu);
	CU_add_test(pSuite_Menu, "test of get_ultimo_indice_menu()", test_get_ultimo_indice_menu);
	CU_add_test(pSuite_Menu, "test of is_ricetta_preparabile()", test_is_ricetta_preparabile);
	CU_add_test(pSuite_Menu, "test of indice_id_menu()", test_indice_id_menu);
	CU_add_test(pSuite_Menu, "test of is_menu_esistente()", test_is_menu_esistente);

	CU_add_test(pSuite_Utenti, "test of aggiungi_utente()", test_aggiungi_utente);
	CU_add_test(pSuite_Utenti, "test of is_utente_esistente()", test_is_utente_esistente);
	CU_add_test(pSuite_Utenti, "test of ricerca_utente()", test_ricerca_utente);
	CU_add_test(pSuite_Utenti, "test of cancella_utente()", test_cancella_utente);

	CU_add_test(pSuite_controlli_h, "test of is_intero()", test_is_intero);
	CU_add_test(pSuite_controlli_h, "test of test_is_stringa_caratteri()", test_is_stringa_caratteri);
	CU_add_test(pSuite_controlli_h, "test of test_is_compreso_tra()", test_is_compreso_tra);
	CU_add_test(pSuite_controlli_h, "test of test_is_compreso_tra_float()", test_is_compreso_tra_float);
	CU_add_test(pSuite_controlli_h, "test of test_is_float()", test_is_float);
	CU_add_test(pSuite_controlli_h, "test of test_is_data_corretta()", test_is_data_corretta);

	CU_add_test(pSuite_Ricette, "test of test_is_data_corretta()", test_is_data_corretta);
	CU_add_test(pSuite_Ricette, "test of test_aggiungi_ricetta()", test_aggiungi_ricetta);
	CU_add_test(pSuite_Ricette, "test of test_get_ultimo_id_ricetta()", test_get_ultimo_id_ricetta);
	CU_add_test(pSuite_Ricette, "test of test_get_ultimo_indice_ricetta()", test_get_ultimo_indice_ricetta);
	CU_add_test(pSuite_Ricette, "test of test_modifica_ricetta()", test_modifica_ricetta);
	CU_add_test(pSuite_Ricette, "test of test_indice_id_ricetta()", test_indice_id_ricetta);
	CU_add_test(pSuite_Ricette, "test of test_is_ricetta_esistente()", test_is_ricetta_esistente);
	CU_add_test(pSuite_Ricette, "test of test_cancella_ricetta()", test_cancella_ricetta);

	CU_add_test(pSuite_Lista_spesa, "test of test_aggiungi_a_lista()", test_aggiungi_a_lista);
	CU_add_test(pSuite_Lista_spesa, "test of test_cancella_lista_spesa()", test_cancella_lista_spesa);


	// Esecuzione del test e pulitura del registry
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();

}



