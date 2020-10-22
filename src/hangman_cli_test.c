#include "assert.h"
// include "conio.h"
#include "hangman_cli.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*тест на ф-ию sym_used*/
void test_sym_used()
{
    char sym = 'a', *str = "abcd";
    assert(sym_used(sym, str) == 1); // assert кидает ошибку

    sym = 'f';
    assert(sym_used(sym, str) == 0);
}

/*тест на ф-ию check_symbol*/
void test_check_symbol()
{
    char symbol = 'a', *word = "cats";
    assert(check_symbol(symbol, word) == 1); // assert кидает ошибку

    symbol = 'c';
    assert(check_symbol(symbol, word) == 1);

    symbol = 'd';
    assert(check_symbol(symbol, word) == 0);
}

/*тест на ф-ию add_symbol_to_hidden_word*/
void test_add_symbol_to_hidden_word()
{
    char symbol = 'a', *word = "cats";
    char* hidden_word = (char*)malloc(4 * sizeof(char));
    strcat(hidden_word, "----");
    add_symbol_to_hidden_word(word, symbol, hidden_word);
    assert(strcmp(hidden_word, "-a--") == 0); // assert кидает ошибку
}

/*тест на ф-ию add_symbol_to_hidden_word 2*/
void test_add_symbol_to_hidden_word_2()
{
    char symbol = 'a', *word = "cats";
    char* hidden_word = (char*)malloc(4 * sizeof(char));
    strcat(hidden_word, "----");
    add_symbol_to_hidden_word(word, symbol, hidden_word);
    assert(strcmp(hidden_word, "-a--") == 0); // assert кидает ошибку

    symbol = 'c';
    add_symbol_to_hidden_word(word, symbol, hidden_word);
    assert(strcmp(hidden_word, "ca--") == 0); // assert кидает ошибку
}

/* тест на ф-ию win_or_lose */
void test_win_or_lose()
{
    int err_amount = 0;
    assert(win_or_lose(err_amount) == 1);

    err_amount = 5;
    assert(win_or_lose(err_amount) == 0);
}

int main()
{
    test_sym_used();
    test_check_symbol();
    test_add_symbol_to_hidden_word();
    test_add_symbol_to_hidden_word_2();
    test_win_or_lose();
    printf("all tests passed\n");
    return 0;
}
