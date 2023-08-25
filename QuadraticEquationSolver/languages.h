/////////////////////////////////////////////////////////////////////////
/// \file languages.h
/////////////////////////////////////////////////////////////////////////
#ifndef     LANGUAGES_H 
    #define LANGUAGES_H 

    /////////////////////////////////////////////////////////////////////////
    /// \brief Languages.
    /////////////////////////////////////////////////////////////////////////
    enum Language {
        RUSSIAN, ///< Russian language.
        ENGLISH, ///< US English language.
        GERMANY, ///< Germany language.
        CHINESE  ///< Chinese language.
    };

    /////////////////////////////////////////////////////////////////////////
    /// \brief User interface messages on different languages.
    /////////////////////////////////////////////////////////////////////////
    struct OutputLanguage {
        Language language_identification;   ///< Identification language name.
        const char * language_menu;         ///< Greeting and purpose of the program.
        const char * language_request;      ///< Request to input coefficients of equation.
        const char * language_error;        ///< If user input invalid coefficients.
        const char * language_show_equation;///< Show user equation.
        const char * language_inf_roots;    ///< If equation has infinity number of roots.
        const char * language_no_roots;     ///< If equation hasn't roots.
        const char * language_one_root;     ///< If equation has only one root.
        const char * language_two_roots;    ///< If equation has two roots.
        const char * language_this_root;    ///< Root reference if equation has one root.
        const char * language_first_root;   ///< First root reference if equation has two roots.
        const char * language_second_root;  ///< Second root reference if equation has two roots.
        const char * language_goodbye;      ///< Say goodbye to user.
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


#endif // LANGUAGES_H