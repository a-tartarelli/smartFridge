#include "strutture_dati.h"
#include "date.h"

/*variabili globali*/
alimento* array_alimenti_pieno;
alimento* array_alimenti_vuoto;
alimento* array_alimenti_uguale;
ricetta* array_ricette_pieno;
ricetta* array_ricette_vuoto;
menu_giornaliero* menu_settimanale_pieno;
menu_giornaliero* menu_settimanale_vuoto;

alimento* inizializza_array_alimenti_pieno ();
alimento* inizializza_array_alimenti_vuoto ();
alimento* inizializza_array_alimenti_uguale();
ricetta* inizializza_array_ricette_pieno ();
ricetta* inizializza_array_ricette_vuoto ();
menu_giornaliero* inizializza_menu_settimanale_pieno ();
menu_giornaliero* inizializza_menu_settimanale_vuoto ();
