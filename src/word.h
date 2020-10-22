#ifndef WORD_H
#define WORD_H

#include <stdio.h>

char* get_filepath_by_difficult(int difficult);
FILE* read_file(int difficult);
int get_words_amount(FILE* words);
int get_word_length(char* str);
int get_random_word_num(int words_amount, int (*rand_fn)());
char* word_select(FILE* words);
char* word_select_with_rand(FILE* words, int (*rand_fn)());

#endif
