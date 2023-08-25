/////////////////////////////////////////////////////////////////////////
/// \file languages.h
/////////////////////////////////////////////////////////////////////////
#ifndef LANGUAGES_H 
    #define LANGUAGES_H

/////////////////////////////////////////////////////////////////////////
/// \brief Languages.
/////////////////////////////////////////////////////////////////////////
    enum language {
        RUSSIAN,
        ENGLISH, 
        GERMANY,
        CHINESE
    };

/////////////////////////////////////////////////////////////////////////
/// \brief User interface messages on different languages.
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
/// \brief Select structure of language messages using identification character.
/// \param[in] ch Identification character.
/// \return Structure of language messages.
/////////////////////////////////////////////////////////////////////////
    const OutputLanguage * select_language(const int ch);

extern const OutputLanguage LANGUAGE_RUSSIAN;
extern const OutputLanguage LANGUAGE_ENGLISH;
extern const OutputLanguage LANGUAGE_GERMANY;
extern const OutputLanguage LANGUAGE_CHINESE;


#endif