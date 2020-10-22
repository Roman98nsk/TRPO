#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define alphabet_size 26

/*
 * Function:  sym_used
 * -------------------
 *
 * использованные символы
 *
 * sym: символ, который вводит пользователь
 *
 * str: указатель на массив использованных символов
 *
 * rteurn: 1 — если символ был использован; 0 — если символ не был использован
 */
int sym_used(char sym, char* str)
{
    for (int i = 0; i < strlen(str); i++) {
        /*Функция strlen начинает сначала считать количество символов, этот
        процесс выполняется до тех пор, пока не будет достигнут завершающий
        нулевой символ*/
        if (str[i] == sym) {
            return 1;
        }
    }
    return 0;
}
/*
 * Function: read_symbol
 * ---------------------
 *
 * чтение символа
 *
 * symbol: символ
 *
 * used_symbols[alphabet_size]: массив использованных символов [размер алфавита]
 *
 * err_amount: сумма ошибок
 *
 * hidden_word: указатель на массив со скрытым словом
 *
 * return: символ
 */
char read_symbol(
        char symbol,
        char used_symbols[alphabet_size],
        int err_amount,
        char* hidden_word)
{
    /* подсчитываем размер загаданного слова */
    int word_size = strlen(hidden_word);

    printf("Used symbols:\n");
    for (int k = 0; k < alphabet_size; k++) {
        printf("%c", used_symbols[k]);
    }
    printf("\n\n");
    printf("Errors: %d\n\n", err_amount);
    for (int i = 0; i < word_size; i++) {
        printf("%c", hidden_word[i]);
    }
    printf("\n\nEnter symbol: "); // использ-ый символ
    symbol = getche();
    /*Функция getche() возвращает очередной символ, считанный с консоли, и
    выводит этот символ на экран*/
    return symbol;
}
/*
 * Function:  check_symbol
 * -----------------------
 *
 * ф-ия проверяет, существует ли символ в загаданном слове
 *
 *  symbol: символ
 *
 *  word: указатель на загаданное слово
 *
 * return: существующий символ в загаданном слове
 */
int check_symbol(char symbol, char* word)
{
    int word_size, sym_exists = 0;
    for (word_size = 0; word[word_size] != '\0'; word_size++)
        ;
    for (int i = 0; i < word_size; i++) {
        if (word[i] == symbol) { // если символ есть в слове
            sym_exists = 1; /*то существующему символу присваиваем единицу*/
            break; /* Оператор break используется для того, чтобы прерывать
            ход программы и передавать управление следующему оператору*/
        }
    }
    /* функция возвращает 1 - символ присутствует в слове, 0 — символ
    отсутствует в слове */
    return sym_exists;
}
/*
 * Function: add_symbol_to_hidden_word
 * -----------------------------------
 *
 * записывает символ в загаданное слово
 *
 *  symbol: символ
 *
 *  word: указатель на загаданное слово
 *
 *  hidden_word: указатель на скрытое слово
 *
 * returns: void
 */
void add_symbol_to_hidden_word(char* word, char symbol, char* hidden_word)
{
    int word_size = strlen(word);
    for (int i = 0; i < word_size; i++) {
        /*если символ присутствует в загаданном слове*/
        if (word[i] == symbol) {
            /*записываем этот символ в массив загадываемого слова*/
            hidden_word[i] = symbol;
        }
    }
}
/*
 * Function: win_or_lose
 * ---------------------
 *
 * выигрыш или поражение
 *
 *  err_amount: количество ошибок
 *
 * return: 1 — выигрыш, 0 - проигрыш
 */
int win_or_lose(int err_amount)
{
    if (err_amount != 5) // кол-во попыток
    {
        printf("You win!\n"); //выигрыш
        return 1;
    } else {
        printf("You lose!\n"); //проигрыш
        return 0;
    }
}
/*
 * Function:  Hangman
 * ---------------------
 *
 * игра Виселица
 *
 * word: указатель на отгадываемое слово
 *
 * return: выигрыш или проигрыш
 */
int Hangman(char* word)
{
    int i, count = 0, word_size,
           err_amount = 0; /* символ, использ-ый_символ[размер алфавита]*/
    char symbol, used_symbols[alphabet_size];

    for (int k = 0; k < alphabet_size; k++) {
        used_symbols[k] = '-';
    }

    for (word_size = 0; word[word_size] != '\0'; word_size++)
        ;

    char* hidden_word;
    hidden_word = (char*)malloc(word_size * sizeof(char));
    for (i = 0; i < word_size; i++) {
        hidden_word[i] = '-';
    }
    printf("Press any key to start...\n");
    getch();
    /*
    Функция getch() возвращает очередной символ, считанный с консоли, но
    не выводит этот сим­вол на экран
    */
    system("clear");
    /* system: Функция выполняет заданную, через параметр "clear", системную
       команду "clear": Си-строка содержащая системную команду для выполнения
    */
    while (err_amount != 5) //кол-во попыток 5
    {
        symbol = read_symbol(symbol, used_symbols, err_amount, hidden_word);
        if (symbol < 'a' || symbol > 'z') {
            printf("\nYou should enter [a..z] symbols only.");
            getch();
            /*
              Функция getch() возвращает очередной символ, считанный с консоли,
              но не выводит этот сим­вол на экран
            */
            system("clear");
            /* system: Функция выполняет заданную, через параметр "clear",
               системную команду "clear": Си-строка содержащая системную команду
               для выполнения
            */
            continue;
            /*
              Оператор continue используется только в циклах. оператор continue
              выполняет пропуск оставшейся части кода тела цикла и переходит к
              следующей итерации цикла
            */
        }

        int sym_exists = check_symbol(symbol, word);

        if (sym_exists == 1) {
            add_symbol_to_hidden_word(word, symbol, hidden_word);
            /*strcmp – сравнение строк. word, hidden_word – указатели на
            сравниваемые строки. 0 – если сравниваемее строки идентичны.
            Положительное число – если строки оadd_symbol_to_hidden_word(word,
            symbol, hidden_word);тличаются и код первого отличающегося символа в
            строке word больше кода символа на той же позиции в строке
            hidden_word. Отрицательное число – если строки отличаются и код
            первого отличающегося символа в строке word меньше кода символа на
            той же позиции в строке hidden_word.*/

            if (!strcmp(word, hidden_word)) {
                system("clear");
                break;
            }
        } else if (!sym_exists && !sym_used(symbol, used_symbols)) {
            // если символ не угадан
            err_amount++; //кол-во использованных попыток увеличивается на 1
        }

        if (!sym_used(symbol, used_symbols)) {
            used_symbols[count] = symbol;
            count++;
        }

        system("clear");
    }

    return win_or_lose(err_amount);
}
