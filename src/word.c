#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Function:  get_filepath_by_difficult
 * ------------------------------------
 * получает путь к файлу по сложности
 *
 * difficult: сложность игры
 *
 * return: путь к файлу либо NULL
 */
char* get_filepath_by_difficult(int difficult)
{
    switch (difficult) //уровень сложности
    {
    /*код выполнится, если difficult будет равен 0*/
    case 0:
        return "./iwi/words/just.txt"; // возвращаем путь к файлу
        /* break  прерывает ход программы в операторе switch и передает
        управление следующему оператору, после switch */
        break;
    case 1:
        return "./iwi/words/easy.txt";
        break;
    case 2:
        return "./iwi/words/medium.txt";
        break;
    case 3:
        return "./iwi/words/hard.txt";
        break;
    /* иначе возвращаем NULL */
    default:
        return NULL;
    }
}

/*
 * Function:  read_file
 * --------------------
 * считывает файл
 *
 * difficult: сложность игры
 *
 * return: читает файл
 */
FILE* read_file(int difficult)
{
    char* filepath = get_filepath_by_difficult(difficult);
    /* если текстовый файл пуст, то возвращаем NULL*/
    if (filepath == NULL) {
        return NULL;
    }
    /* открываем текстовый файл и считываем его */
    return fopen(filepath, "r");
}

/*
 * Function: get_words_amount
 * --------------------------
 * подсчитывает количество слов в файле
 *
 * words: указатель на текстовый файл
 *
 * return: количество слов в файле
 */
int get_words_amount(FILE* words)
{
    int ch, str_length = 0, words_amount = 0;
    /* читаем файл до тех пор пока не достигнут его конец */
    while ((ch = fgetc(words)) != EOF) {
        // если строка закончилась
        if (ch == '\n') {
            // увелилчиваем количество слов в файле
            if (str_length > 0) {
                words_amount += 1;
            }
            // обнуляем длину строку для посчета количетва символов в следующем
            // слове
            str_length = 0;
        }
        /* увеличиваем длину строки на единицу */
        str_length += 1;
    }
    return words_amount;
}

/*
 * Function: get_word_length
 * -------------------------
 * подсчитывает количество букв в слове
 *
 * str: указатель на массив, куда будет записываться загаданное слово
 *
 * return: количество букв в слове
 */
int get_word_length(char* str)
{
    int word_length = 0;
    /* вычисляем количество символов в строке */
    word_length = strlen(str) - 1;
    return word_length;
}

/*
 * Function:  get_random_word_num
 * ------------------------------
 * выбирает случайный номер слова
 *
 * words_amount: количество слов в текстовом файле
 *
 * (*rand_fn)(): указатель на функцию rand()
 *
 * return: случайно выбранный номер слова
 */
int get_random_word_num(int words_amount, int (*rand_fn)())
{
    return rand_fn() % words_amount;
}

/*
 * Function: word_select_with_rand
 * -------------------------------
 * выбирает слово с помощью функции rand()
 *
 * words: указатель на текстовый файл
 *
 * (*rand_fn)(): указатель на функцию rand()
 *
 * return: новое слово из текстового файла
 */
char* word_select_with_rand(FILE* words, int (*rand_fn)())
{
    int words_amount = 0, word_length = 0;
    char str[10]; /*массив куда будет записываться загадываемое слово*/
    words_amount = get_words_amount(words);
    int new_word_num = get_random_word_num(words_amount, rand_fn);
    /* устанавливаем позицию в начало файла */
    fseek(words, 0, SEEK_SET);
    int i = 0; /* i: счетчик */
    while (i <= new_word_num) {
        fgets(str,
              10,
              words); /*fgets() считывает символы из words и сохраняет
их в виде строки в параметр str до тех пор пока не наступит конец строки
или пока не будет достигнут конец файла.
10  - Максимальное количество символов для чтения, включая нулевой символ
words — текстовый файл, из которого считываются символы.*/
        i++;
    }

    word_length = get_word_length(str);
    char* new_word;
    new_word = (char*)malloc(word_length * sizeof(char));
    /*выделение динамической памяти; malloc() распред-ет байты размера и
    возвращает указатель на выделенную память*/

    for (i = 0; i < word_length; i++) {
        new_word[i] = str[i];
    }

    new_word[i] = '\0'; //конец строки

    return new_word;
}

/*
 * Function: word_select
 * ---------------------
 * выбирает слово из текстового файла
 *
 * words: указатель на текстовый файл
 *
 * returns: слово
 */
char* word_select(FILE* words)
{
    srand(time(NULL)); // устанавливает в качестве базы текущее время
    return word_select_with_rand(words, rand);
}
