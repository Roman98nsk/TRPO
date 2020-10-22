/* file minunit_example.c */

#include "assert.h"
#include "word.h"
#include <stdio.h>
#include <string.h>

int fake_random()
{
    return 1;
}
/* тестирование функции  get_random_word_num() */
void test_get_random_word_num()
{
    assert(get_random_word_num(2, fake_random) == 1); // assert кидает ошибку
}

/* тесты на функцию get_filepath_by_difficult */
void test_get_filepath_by_difficult()
{
    // если уровень сложности 0 - возаращаем путь к словарю со словами из 4
    // букв
    assert(strcmp(get_filepath_by_difficult(0), "./iwi/words/just.txt") == 0);
    // если уровень сложности 1 - возаращаем путь к словарю со словами из 5
    // букв
    assert(strcmp(get_filepath_by_difficult(1), "./iwi/words/easy.txt") == 0);
    // если уровень сложности 2 - возаращаем путь к словарю со словами из 4
    // букв
    assert(strcmp(get_filepath_by_difficult(2), "./iwi/words/medium.txt") == 0);
    // если уровень сложности 3 - возаращаем путь к словарю со словами из 4
    // букв
    assert(strcmp(get_filepath_by_difficult(3), "./iwi/words/hard.txt") == 0);
    // если уровень сложности некорректный - возаращаем NULL
    assert(get_filepath_by_difficult(-1) == NULL);
    assert(get_filepath_by_difficult(100) == NULL);
}

/* тесты на функцию get_words_amount */
void test_get_word_amount()
{
    FILE* words;

    words = fopen("./src/word_test_data/words/1.txt", "r");
    assert(get_words_amount(words) == 1);
    fclose(words);

    words = fopen("./src/word_test_data/words/2.txt", "r");
    assert(get_words_amount(words) == 2);
    fclose(words);

    words = fopen("./src/word_test_data/words/3.txt", "r");
    assert(get_words_amount(words) == 3);
    fclose(words);
}

/* тесты на функцию get_word_length */
void test_get_word_length()
{
    assert(get_word_length("1\n") == 1);
    assert(get_word_length("123\n") == 3);
}

int fake_random_return_0()
{
    return 0;
}

int fake_random_return_2()
{
    return 2;
}

int fake_random_return_4()
{
    return 4;
}

/* тесты на функцию word_select_with_rand */
void test_word_select_with_rand()
{
    FILE* words;
    char* word;

    // 0
    words = fopen("./src/word_test_data/words/5.txt", "r");
    word = word_select_with_rand(words, fake_random_return_0);
    assert(strcmp(word, "one") == 0);
    fclose(words);

    // 2
    words = fopen("./src/word_test_data/words/5.txt", "r");
    word = word_select_with_rand(words, fake_random_return_2);
    assert(strcmp(word, "three") == 0);
    fclose(words);

    // 4
    words = fopen("./src/word_test_data/words/5.txt", "r");
    word = word_select_with_rand(words, fake_random_return_4);
    assert(strcmp(word, "five") == 0);
    fclose(words);
}

int main()
{
    test_get_random_word_num();
    test_get_filepath_by_difficult();
    test_get_word_amount();
    test_get_word_length();
    test_word_select_with_rand();
    printf("all tests passed\n");
    return 0;
}
