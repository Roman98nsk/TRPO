#ifndef HANGMAN_H
#define HANGMAN_H
#include <gtk/gtk.h>

int sym_used(char sym, char* str);
int get_symbol(GtkButton* button);

#endif
