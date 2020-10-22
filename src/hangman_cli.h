#ifndef HAGMAN_H
#define HAGMAN_H

int sym_used(char sym, char* str);
char read_symbol(
        char symbol, char used_symbols, int err_amount, char* hidden_word);
int check_symbol(char symbol, char* word);
void add_symbol_to_hidden_word(char* word, char symbol, char* hidden_word);
int win_or_lose(int err_amount);
int Hangman(char* word);

#endif
