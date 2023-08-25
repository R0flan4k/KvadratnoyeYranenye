/////////////////////////////////////////////////////////////////////////
/// \file languages.cpp
/// \brief Language support.
/////////////////////////////////////////////////////////////////////////
#include "languages.h"


const OutputLanguage LANGUAGE_ENGLISH = {
    .language_identification = ENGLISH,

    .language_menu =            "Hello, Ruslan Alekseyevich.\n\
                                \rThis program can solve quadratic equation.\n\
                                \rEquation must looks like: ",

    .language_request =         "Enter coeficients a, b, c:\n",

    .language_error =           "Error. Enter 3 real numbers\n\
                                \rlike 12, -1.5, 3.14 or 1.618.\n",

    .language_show_equation =   "Your equation: ",

    .language_inf_roots =       "This equation has infinite number of roots.\n",

    .language_no_roots =        "This equation hasn't roots.\n",

    .language_one_root =        "This equation has one root.\n",

    .language_two_roots =       "This equation has two roots.\n",

    .language_this_root =       "This root: ",

    .language_first_root =      "First root: ",

    .language_second_root =     "Second root: ",

    .language_goodbye =         "Have a good day! End."
};


const OutputLanguage LANGUAGE_RUSSIAN = {
    .language_identification = RUSSIAN,

    .language_menu =            "Здравствуйте, Руслан Алексеевич.\n\
                                \rЭта программа преднозначена для решения квадратных уравнений.\n\
                                \rУравнение должно выглядеть следующим образом: ",

    .language_request =         "Введите коэффициенты a, b и c:\n",

    .language_error =           "Ошибка. Введите 3 вещественных числа\n\
                                \rтаких как 12, -1.5, 3.14 или 1.618.\n",

    .language_show_equation =   "Ваше уравнение: ",

    .language_inf_roots =       "Это уравнение имеет бесконечное количество корней.\n",

    .language_no_roots =        "Это уравнение не имеет корней.\n",
    
    .language_one_root =        "Это уравнение имеет всего один корень.\n",

    .language_two_roots =       "Это уравнение имеет два корня.\n",

    .language_this_root =       "Этот корень: ",

    .language_first_root =      "Первый корень: ",

    .language_second_root =     "Второй корень: ",

    .language_goodbye =         "Всего доброго! Конец."
};


const OutputLanguage LANGUAGE_GERMANY = {
    .language_identification = GERMANY,

    .language_menu =            "Hallo, Ruslan Alekseevich.\n\
                                \rDieses Programm dient zur Lösung quadratischer Gleichungen.\n\
                                \rDie Gleichung sollte so aussehen: ",

    .language_request =         "Geben Sie die Quoten ein a, b, c:\n",

    .language_error =           "Fehler. Geben Sie 3 reelle Zahlen ein\n\
                                \rZum Beispiel 12, -1.5, 3.14, 1.618.\n",

    .language_show_equation =   "Hier ist deine Gleichung: ",

    .language_inf_roots =       "Diese Gleichung hat unendlich viele Wurzeln.\n",

    .language_no_roots =        "Diese Gleichung hat keine Wurzeln.\n",

    .language_one_root =        "Diese Gleichung hat nur eine Wurzel.\n",

    .language_two_roots =       "Diese Gleichung hat zwei Wurzeln.\n",

    .language_this_root =       "das ist die Wurzel: ",

    .language_first_root =      "erste Wurzel: ",

    .language_second_root =     "zweite Wurzel: ",

    .language_goodbye =         "Auf Wiedersehen! Ende."
};


const OutputLanguage LANGUAGE_CHINESE = {
    .language_identification = CHINESE,

    .language_menu =            "你好，鲁斯兰·阿列克谢耶维奇。\n\
                                \r该程序旨在求解二次方程。\n\
                                \r等式应如下所示： ",

    .language_request =         "输入赔率 a, b, c:\n",

    .language_error =           "О错误。输入三个实数\n\
                                \r例如 12, -1.5, 3.14, 1.618.\n",

    .language_show_equation =   "这是你的等式： ",

    .language_inf_roots =       "这个方程有无数个根。\n",

    .language_no_roots =        "该方程没有实根。\n",

    .language_one_root =        "这个方程只有一个根。\n",

    .language_two_roots =       "这个方程有两个根。\n",

    .language_this_root =       "这是根: ",

    .language_first_root =      "第一个根： ",

    .language_second_root =     "第二根： ",

    .language_goodbye =         "再见！结尾。"
};