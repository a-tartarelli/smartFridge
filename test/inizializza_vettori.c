#include "inizializza_vettori.h"

alimento* inizializza_array_alimenti_pieno () {
	alimento* alimenti_frigo = malloc( NUMERO_ALIMENTI * sizeof(alimento));     /* allocazione dinamica in memoria di un vettore di alimenti*/

	alimenti_frigo[0].id_alimento = 1;
	strcpy (alimenti_frigo[0].nome_alimento, "Acqua");
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
	strcpy (alimenti_frigo[17].nome_alimento, "Uva");
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
	strcpy (alimenti_frigo[27].nome_alimento, "Pancetta");
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

	for (int i=29; i<NUMERO_ALIMENTI; i++) {
		char nome[LUNGHEZZA_NOME];

		alimenti_frigo[i].id_alimento = i+1;
		sprintf(nome, "Alimento %d", i);
		strcpy (alimenti_frigo[i].nome_alimento, nome);
		alimenti_frigo[i].data_scadenza.giorno = 20;
		alimenti_frigo[i].data_scadenza.mese = 6;
		alimenti_frigo[i].data_scadenza.anno = 2018;
		alimenti_frigo[i].numero_pezzi = 1;
		alimenti_frigo[i].peso_unitario = 100;
	}

	return alimenti_frigo;
}


alimento* inizializza_array_alimenti_vuoto () {

	alimento* alimenti_frigo = malloc( NUMERO_ALIMENTI * sizeof(alimento));     /* allocazione dinamica in memoria di un vettore di alimenti*/

	for (int i=0; i<NUMERO_ALIMENTI; i++) {
		alimenti_frigo[i].id_alimento = 0;
		strcpy (alimenti_frigo[i].nome_alimento, "");
		alimenti_frigo[i].data_scadenza.giorno = 0;
		alimenti_frigo[i].data_scadenza.mese = 0;
		alimenti_frigo[i].data_scadenza.anno = 0;
		alimenti_frigo[i].numero_pezzi = 0;
		alimenti_frigo[i].peso_unitario = 0;
	}

	return alimenti_frigo;
}

alimento* inizializza_array_alimenti_uguale () {

	alimento* alimenti_frigo = malloc( NUMERO_ALIMENTI * sizeof(alimento));     /* allocazione dinamica in memoria di un vettore di alimenti*/

	for (int i=0; i<NUMERO_ALIMENTI; i++) {
		alimenti_frigo[i].id_alimento = i+1;
		strcpy (alimenti_frigo[i].nome_alimento, "Acqua");
		alimenti_frigo[i].data_scadenza.giorno = 29;
		alimenti_frigo[i].data_scadenza.mese = 6;
		alimenti_frigo[i].data_scadenza.anno = 2018;
		alimenti_frigo[i].numero_pezzi = 1;
		alimenti_frigo[i].peso_unitario = 100;
	}

	return alimenti_frigo;
}


ricetta* inizializza_array_ricette_pieno () {

	ricetta* ricettario = malloc( NUMERO_RICETTE * sizeof(ricetta));     /* allocazione dinamica in memoria di un vettore di ricette*/

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
	ricettario[0].kcal = 185;
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


	for (int i=6; i<NUMERO_RICETTE; i++) {
		char nome[LUNGHEZZA_NOME];

		ricettario[i].id_ricetta = i+1;

		sprintf(nome, "Ricetta %d", i);
		strcpy (ricettario[i].nome_ricetta, nome);

		strcpy (ricettario[i].ingredienti[0].nome_alimento, "Acqua");
		strcpy (ricettario[i].ingredienti[0].quantita, "100");
		ricettario[i].ingredienti[0].unita_misura = 'g';

		ricettario[i].numero_ingredienti = 1;
		ricettario[i].complessita = BASSA;
		ricettario[i].kcal = 100;
		ricettario[i].n_persone = 1;
		ricettario[i].tempo_preparazione = 2;
		strcpy (ricettario[i].link_procedimento, "https://bit.ly/2L7eQkl");
	}

	return ricettario;
}


ricetta* inizializza_array_ricette_vuoto () {

	ricetta* ricettario = malloc( NUMERO_RICETTE * sizeof(ricetta));     /* allocazione dinamica in memoria di un vettore di ricette*/

	for (int i=0; i<NUMERO_RICETTE; i++) {

		ricettario[i].id_ricetta = 0;
		strcpy (ricettario[i].nome_ricetta, "");

		ricettario[i].numero_ingredienti = 0;
		ricettario[i].complessita = 0;
		ricettario[i].kcal = 0;
		ricettario[i].n_persone = 0;
		ricettario[i].tempo_preparazione = 0;
		strcpy (ricettario[i].link_procedimento, "");
	}

	return ricettario;
}


menu_giornaliero* inizializza_menu_settimanale_pieno () {

	menu_giornaliero* menu_settimanale = malloc( NUMERO_MENU_GIORNALIERI * sizeof(menu_giornaliero));
	unsigned short int giorno_settimana = 0;
	unsigned short int id_utente = 1;

	data data_menu;
	data_menu.giorno = 3;
	data_menu.mese = 6;
	data_menu.anno = 2018;

	for (int i=0; i<NUMERO_MENU_GIORNALIERI; i++ ){

		strcpy (data_menu.giorno_settimana, get_giorno_settimana_char (giorno_settimana));

		menu_settimanale[i].id_menu = i+1;
		menu_settimanale[i].id_utente = id_utente;
		menu_settimanale[i].data_menu = data_menu;
		menu_settimanale[i].kcal_giornaliere = 3000;
		menu_settimanale[i].numero_pasti = 1;
		menu_settimanale[i].pasti[0].id_ricetta = i+1;
		menu_settimanale[i].pasti[0].n_persone = 1;

		data_menu.giorno++;
		giorno_settimana++;

		if(giorno_settimana == 6) {
			data_menu.giorno = 3;
			giorno_settimana = 0;
			id_utente++;
		}

	}
	return menu_settimanale;
}


menu_giornaliero* inizializza_menu_settimanale_vuoto () {

	menu_giornaliero* menu_settimanale = malloc( NUMERO_MENU_GIORNALIERI * sizeof(menu_giornaliero));

	data data_menu;
	data_menu.giorno = 0;
	data_menu.mese = 0;
	data_menu.anno = 0;
	strcpy (data_menu.giorno_settimana, "");

	for (int i=0; i<NUMERO_MENU_GIORNALIERI; i++) {

		menu_settimanale[i].id_menu = 0;
		menu_settimanale[i].id_utente = 0;
		menu_settimanale[i].data_menu = data_menu;
		menu_settimanale[i].kcal_giornaliere = 0;
		menu_settimanale[i].numero_pasti = 0;
	}

	return menu_settimanale;
}

