cmake_minimum_required(VERSION 3.10)

# all source files
set(SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/main.c)

# include header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# add library
set(SMART_FRIDGE_FILES
        ${PROJECT_SOURCE_DIR}/lib/smartfridge/carica_file.c
        ${PROJECT_SOURCE_DIR}/lib/smartfridge/controlli.c
        ${PROJECT_SOURCE_DIR}/lib/smartfridge/date.c
        ${PROJECT_SOURCE_DIR}/lib/smartfridge/elaborazione_alimenti.c
        ${PROJECT_SOURCE_DIR}/lib/smartfridge/elaborazione_alimenti.c
        ${PROJECT_SOURCE_DIR}/lib/smartfridge/elaborazione_ricette.c
        ${PROJECT_SOURCE_DIR}/lib/smartfridge/gestione_menu_settimanale.c
        ${PROJECT_SOURCE_DIR}/lib/smartfridge/gestione_utenti.c
        ${PROJECT_SOURCE_DIR}/lib/smartfridge/lista_spesa.c )
add_library(smartfridge ${SMART_FRIDGE_FILES})

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )
target_link_libraries(${PROJECT_NAME} smartfridge)