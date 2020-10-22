#include "conio.h"
#include "hangman_cli.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *word_of_the_game, prompt = 'y';
    int difficult = 0;
    FILE* words = read_file(difficult);
    while (prompt != 'n') {
        system("clear");
        /* system: Функция выполняет заданную, через параметр "clear", системную
           команду "clear": Си-строка содержащая системную команду для
           выполнения
        */
        word_of_the_game = word_select(words); //выбор слова сложности just
        printf("Word of the game: %s.\n", word_of_the_game); //слово игры
        Hangman(word_of_the_game);

        printf("Another try? [y/n] ");
        prompt = getche();
    }
    printf("\n");

    return 0;
}
