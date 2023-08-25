/////////////////////////////////////////////////////////////////////////
/// \file test.h
/////////////////////////////////////////////////////////////////////////
#ifndef TEST_H
    #define TEST_H

    #include "calculations.h"

/////////////////////////////////////////////////////////////////////////
/// \brief All kind of test results.
/////////////////////////////////////////////////////////////////////////
    enum TestResults { //TestResults????
        TEST_SUCCESS,        ///< If file successfully tested.
        TEST_CANT_OPEN_FILE, ///< If file not found.
        TEST_COUNT_FAILURE,  ///< If calculated wrong number of roots.
        TEST_ROOTS_FAILURE   ///< If calculated wrong roots.
    };

/////////////////////////////////////////////////////////////////////////
/// \brief Check the program's calculations.
/// \param[in] test_file Name of test file.
/// \return Results of test.
/////////////////////////////////////////////////////////////////////////
    TestResults test_program(const char * test_file);

#endif