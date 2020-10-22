#include "game.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function: get_symbol
 * --------------------
 *
 * получение символа
 *
 *  GtkButton* button: виджет, который издает сигнал при нажатии на кнопку
 *
 * return: 0
 */
int get_symbol(GtkButton* button)
{
    char err_path[20], word_mess[20];
    /*ширинаб высота*/
    int width, height;
    gtk_window_get_size(GTK_WINDOW(mess_windows), &width, &height);
    /*Получает текущий размер mess_windows*/
    const char* symbol = gtk_button_get_label(button);
    /*Извлекает текст из метки кнопки. Если текст метки не был установлен,
     возвращаемое значение будет NULL.*/
    gtk_widget_hide(GTK_WIDGET(button));
    /*заставляя виджет быть скрытым (невидимым для пользователя)*/

    int sym_exists = 0;

    for (int i = 0; i < word_size; i++) {
        if (word_game[i] == *symbol) {
            sym_exists = 1;
            break;
        }
    }

    if (sym_exists) {
        for (int i = 0; i < word_size; i++) {
            if (word_game[i] == *symbol) {
                hidden_word[i] = *symbol;
            }
        }
        gtk_label_set_text(hidden_wor_lab, hidden_word);
        if (!strcmp(word_game, hidden_word)) {
            gtk_window_move(
                    GTK_WINDOW(mess_windows),
                    gdk_screen_width() / 1.35,
                    gdk_screen_height() / 2
                            - height / 2); /*изменение размера окна*/
            gtk_widget_hide(GTK_WIDGET(keyboard_Gr)); /*заставляет скрыть
             виджет(невид-ый для пользователя)*/
            gtk_label_set_text(mess_Lab, "You save mouse!");
            /*Устанавливает текст в виджете GtkLabel*/
            gtk_image_set_from_file(Image, "./iwi/image/win.jpg");
            /*Создает новый GtkImage, отображающий имя файла
            Если файл содержит анимацию, изображение будет содержать анимацию.*/
            gtk_widget_show(mess_windows); //отображение окна
        }
    } else if (!sym_exists) {
        err_amount++;
        sprintf(err_path, "./iwi/image/%d.jpg", err_amount);
        gtk_image_set_from_file(Image, err_path);
    }

    if (err_amount == 5) // если кол-во ошибок = 5
    {
        gtk_window_move(
                GTK_WINDOW(mess_windows),
                gdk_screen_width() / 1.35,
                gdk_screen_height() / 2 - height / 2);
        gtk_widget_hide(GTK_WIDGET(keyboard_Gr));
        sprintf(word_mess, "Hidden word is - %s", word_game);
        gtk_label_set_text(mess_Lab, "You kill mouse!");
        gtk_label_set_text(hidden_wor_lab, word_mess);
        gtk_widget_show(mess_windows);
    }

    return 0;
}
