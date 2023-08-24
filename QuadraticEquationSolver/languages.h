#ifndef LANGUAGES_H 
    #define LANGUAGES_H

    enum language {
        RUSSIAN,
        ENGLISH, 
        GERMANY,
        CHINESE
    };


    typedef struct {
        language language_indentification;
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
    } OutputLanguage;


    const OutputLanguage * select_language(const int ch);


#endif