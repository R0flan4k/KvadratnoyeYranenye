/////////////////////////////////////////////////////////////////////////
/// \file input-output.h
/////////////////////////////////////////////////////////////////////////
#ifndef     INPUT_OUTPUT_H
    #define INPUT_OUTPUT_H


    #include "languages.h"
    #include "calculations.h"

    #define GREEN_COLOR "\x1b[32m"
    #define DEFAULT_COLOR "\x1b[0m"

    /////////////////////////////////////////////////////////////////////////
    /// @brief String with allowed for language input characters.
    /////////////////////////////////////////////////////////////////////////  


    /////////////////////////////////////////////////////////////////////////
    /// @brief Flags and arguments from command line.
    /////////////////////////////////////////////////////////////////////////
    struct CmdLineArg {
        const char* name; ///< Name of flag.
        int num_of_param; ///< Number of flag parameters.
    };

    const int WRONG_CMD_INPUT     = 1;  ///< If user incorrectly using flags.
    const int RIGHT_CMD_INPUT     = 0;  ///< If user correctly using flags.
    const int TRIVIAL_CMD_INPUT   = 2;  ///< If user dont using flags.
    const int PREMATURE_CMD_INPUT = 3;  ///< If user prematurely enter coefficients.
    
    const int EXTRA_CHARACTERS = -2;  ///< If the user has entered unnecessary characters.
    const int WRONG_CHARACTER  = -3;  ///< If the user has entered wrong characters.

    /////////////////////////////////////////////////////////////////////////
    /// \brief User greeting and telling program abillity.
    /// \param[in] language Language that program using.
    /////////////////////////////////////////////////////////////////////////    
    void show_menu(const OutputLanguage * language);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Show user available languages.
    /////////////////////////////////////////////////////////////////////////
    void show_language_menu(void);
    
    /////////////////////////////////////////////////////////////////////////
    /// \brief Show user format of equation.
    /////////////////////////////////////////////////////////////////////////
    void show_equation_format(void);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Show user equation that he input.
    /// \param coeffs Inputed coefficients of equation.
    /// \param language Language that program using.
    /////////////////////////////////////////////////////////////////////////
    void show_equation(const EquationCoefficients * coeffs, const OutputLanguage * language);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Show user solution of inputed equatiin.
    /// \param[in] solution Solution of inputed equation.
    /// \param[in] language Language that program using.
    /////////////////////////////////////////////////////////////////////////
    void show_solution(const EquationRoots * solution, const OutputLanguage * language);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Say goodebye to user.
    /// \param[in] language Language that program using.
    /////////////////////////////////////////////////////////////////////////
    void show_goodbye(const OutputLanguage * language);
    

    /////////////////////////////////////////////////////////////////////////
    /// \brief Let user input coefficients of equation. 
    /// \param[out] coefficients Memory cell where the coefficients of the equation will be placed.                     
    /// \return Number of readed numbers.                      
    /////////////////////////////////////////////////////////////////////////
    int get_coefficients(EquationCoefficients * coefficients);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Get from stdin first non-space allowed character, and then skip anything after the character.
    /// \param[in] str List of allowed characters.
    /// \param[in] n Number of allowed characters.
    /// \return Is character alone or is it wrong character.
    /////////////////////////////////////////////////////////////////////////
    int get_one_char(const char * str, int n);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Check if user enter flags running the program.
    /// \param[in] argc Number of words inputed in cmd.
    /// \param[in] argv Array of words that inputed.
    /// \return Is cmd inputs was right or is it there.
    /////////////////////////////////////////////////////////////////////////
    int check_cmd_input(int argc, char ** argv);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Check if inputed coefficients are valid.
    /// \param[out] coefficients Pointer to the memory location where the coefficients will be written.
    /// \return Is inputed coefficients are valid.
    /////////////////////////////////////////////////////////////////////////
    bool is_valid_coefficients_input(EquationCoefficients * coefficients);

    /////////////////////////////////////////////////////////////////////////
    /// @brief Skip all characters in the line.
    /////////////////////////////////////////////////////////////////////////
    void skip_input(void);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Show request to input coefficients.
    /// \param[in] language Entered language.
    ///////////////////////////////////////////////////////////////////////// 
    void show_request(const OutputLanguage * language);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Skip all characters in the string and check if it has non-space characters.
    /// \return Is all characters in this string are spaces.
    /////////////////////////////////////////////////////////////////////////
    bool isspace_extra_characters(void);

    /////////////////////////////////////////////////////////////////////////
    /// \brief Show error if user entered invalid coefficients.
    /// \param[in] language Entered language.
    /////////////////////////////////////////////////////////////////////////
    void show_error(const OutputLanguage * language);

#endif // INPUT_OUTPUT_H