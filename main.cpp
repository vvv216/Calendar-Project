#include "login.h"

/**
 * @brief main
 * @param argc
 * @param argv
 * @return login window
 * @note this is a main class to display the first ui window
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}
