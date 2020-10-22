#include "game.h"
#include "hangman.h"
#include "interface.h"
#include "word.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

int difficult = 0;

/*
 * Function: difficult_set
 * ---------------------
 * выбор сложности
 *
 * GtkToggleButton *button:  GtkToggleButton запоминает состояние кнопки при
 * нажатии
 *
 * returns: void
 */
void difficult_set(GtkToggleButton* button)
{
    if (gtk_toggle_button_get_active(button))
    /*Запрашивает GtkToggleButton и возвращает его текущее состояние.
     Возвращает TRUE, если кнопка переключения нажата, и FALSE, если она
     поднята.*/

    {
        const char* difficult_game = gtk_button_get_label(GTK_BUTTON(button));
        /*Извлекает текст из метки кнопки*/

        if (!strcmp(difficult_game, "Just")) {
            /*strcmp() сравнение строк; difficult_game, "just" - сравниваемые
             * строки*/
            difficult = 0;
        } else if (!strcmp(difficult_game, "Easy")) {
            difficult = 1;
        } else if (!strcmp(difficult_game, "Medium")) {
            difficult = 2;
        } else if (!strcmp(difficult_game, "Hard")) {
            difficult = 3;
        }
    }
}

/*
 * Function: start_game
 * --------------------
 * начало игры
 *
 * returns: void
 */
void start_game()
{
    int i;
    err_amount = 0;
    char path_word[60];
    gtk_image_set_from_file(Image, "./iwi/image/0.jpg");
    gtk_widget_hide(general_windows); /*заставляет скрыть виджет(невид-ый для
    пользователя)*/
    gtk_widget_hide(mess_windows);
    gtk_widget_show_all(GTK_WIDGET(keyboard_Gr));

    FILE* words = read_file(difficult);

    if (words == NULL) {
        printf("Words database \"%s\" not found.\n", path_word);
        GtkWidget* err_words_msg = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "Error");
        gtk_message_dialog_format_secondary_text(
                GTK_MESSAGE_DIALOG(err_words_msg),
                "Words database \"%s\" not found.\n",
                path_word);
        gtk_dialog_run(GTK_DIALOG(err_words_msg));
        gtk_main_quit();
        return;
    }

    if (!(word_game = word_select(words))) {
        return;
    }
    printf("Word: %s\n", word_game);

    word_size = strlen(word_game);

    hidden_word = (char*)malloc(word_size * sizeof(char));
    for (i = 0; i < word_size; i++) {
        hidden_word[i] = '-';
    }
    hidden_word[i] = '\0';

    gtk_label_set_text(hidden_wor_lab, hidden_word);
    gtk_widget_show(level_windows);
}

/*
 * Function:  replay_game
 * ----------------------
 * начать игру заново
 *
 * returns: void
 */
void replay_game()
{
    gtk_widget_hide(level_windows);
    gtk_widget_hide(mess_windows);
    gtk_widget_show(general_windows);
}
