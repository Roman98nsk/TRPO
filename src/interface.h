#ifndef INTERFACE_H
#define INTERFACE_H

#include <gtk/gtk.h>

#define UI_FILE "./iwi/interface.glade" //путь к файлу, где будет храниться
//интерфейс

GtkBuilder* builder; //объект, который сделает за нас окошко
GtkWidget *general_windows, *level_windows, *mess_windows; // виджеты окон
GtkRadioButton *lv_just, *lv_easy, *lv_medium,
        *lv_hard;                //кнопки уровня сложности
GtkButton *Start_but, *Exit_but; //кнопки начала/выхода
GtkLabel *hidden_wor_lab, *mess_Lab;
GtkGrid* keyboard_Gr;
GtkImage* Image;

#endif
