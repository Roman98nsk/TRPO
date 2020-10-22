#include <stdio.h>
#include <termios.h>
#include <unistd.h>

/*
 * Function: getch
 * ---------------
 * читает символ с клавиатуры
 *
 * void: отсутствие параметров
 *
 * return: переменная, куда будет записана нажатая клавиша
 */
int getch(void)
{
    /*
     *	объявляются структуры, в которых будем хранить состояния
     *терминалов oldattr - до приема клавиши newattr - во время приема
     */
    struct termios oldattr, newattr;
    int ch; //в нее запишется нажатая клавиша
    /*получаем старые настройки ввода / вывода терминала*/
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr; /*делаем новые настройки такими же, как старые.*/
    /*Отключение канонического режима и вывода на экран */
    newattr.c_lflag &= ~(ICANON | ECHO);
    /*переключаемся в новый режим, перед этим запомнили старый режим
    (записали в oldattr).*/
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar(); //приняли клавишу
    /* переключились в старый режим */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

/*
 * Function: getche
 * ----------------
 * читает символ с клавиатуры и отображает экран
 *
 * void: отсутствие параметров
 *
 * return: переменная, куда будет записана нажатая клавиша
 */
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    /*отключение буферизованного ввода-вывода*/
    newattr.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
