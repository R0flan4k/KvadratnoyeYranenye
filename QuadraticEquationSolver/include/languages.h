#ifndef LANGUAGES_H 

    enum LANGUAGE {
        RUSSIAN,
        ENGLISH,
        GERMANY,
        CHINESE
    };


    typedef struct {
        LANGUAGE language_indentification;
        const char * language_menu;
        const char * language_request;
        const char * language_error;
        const char * language_show_equation;
        const char * language_inf_roots;
        const char * language_no_roots;
        const char * language_one_root;
        const char * language_two_roots;
        const char * language_this_root;
        const char * language_first_root;
        const char * language_second_root;
        const char * language_goodbye;
    } OutputLanguages;


    const OutputLanguages * get_language(void);

    #define LANGUAGES_H

#endif