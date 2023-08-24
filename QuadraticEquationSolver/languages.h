/////////////////////////////////////////////////////////////////////////
/// file languages.h
/////////////////////////////////////////////////////////////////////////
#ifndef LANGUAGES_H 
    #define LANGUAGES_H

/////////////////////////////////////////////////////////////////////////
/// \brief enumiration of languages from 0 to 3
/////////////////////////////////////////////////////////////////////////
    enum language {
        RUSSIAN,
        ENGLISH, 
        GERMANY,
        CHINESE
    };

/////////////////////////////////////////////////////////////////////////
/// \brief structure of output messages on different languages
/////////////////////////////////////////////////////////////////////////
    struct OutputLanguage {
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
    };

/////////////////////////////////////////////////////////////////////////
/// \brief select structure of language messages using identification character
/// \param[in] ch identification character
/// \return structure of language messages
/////////////////////////////////////////////////////////////////////////
    const OutputLanguage * select_language(const int ch);


#endif