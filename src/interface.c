#include "interface.h"
#include <gtk/gtk.h>

/*
 * Function: main
 * --------------
 *
 * главная, она будет выполнена первой
 *
 * return: 0
 */
int main(int argc, char* argv[])
{
    GError* error = NULL; // здесь будут храниться ошибки

    gtk_init(&argc, &argv); //запускаем GTK+
    builder = gtk_builder_new(); //загружаем файл с интерфейсом
    if (!gtk_builder_add_from_file(builder, UI_FILE, &error)) {
        printf("Interface file \"%s\" not found.", UI_FILE);
        GtkWidget* errMsg = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "Error");
        gtk_message_dialog_format_secondary_text(
                GTK_MESSAGE_DIALOG(errMsg),
                "Interface file \"%s\" not found.",
                UI_FILE);
        // загрузить файл не удалось
        gtk_dialog_run(GTK_DIALOG(errMsg));
        return 1;
    }

    // получаем виджеты окна, чтобы их показать
    general_windows
            = GTK_WIDGET(gtk_builder_get_object(builder, "general_windows"));
    level_windows
            = GTK_WIDGET(gtk_builder_get_object(builder, "level_windows"));
    mess_windows = GTK_WIDGET(gtk_builder_get_object(builder, "mess_windows"));
    // кнопки с уровнями сложностями
    lv_just = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "lv_just"));
    lv_easy = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "lv_easy"));
    lv_medium = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "lv_medium"));
    lv_hard = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "lv_hard"));
    // кнопки начала и выхода из игры
    Start_but = GTK_BUTTON(gtk_builder_get_object(builder, "Start_but"));
    Exit_but = GTK_BUTTON(gtk_builder_get_object(builder, "Exit_but"));
    // метки с загаданным словом, конец игры, кол-во выигрыш/проигрыш
    hidden_wor_lab
            = GTK_LABEL(gtk_builder_get_object(builder, "hidden_wor_lab"));
    mess_Lab = GTK_LABEL(gtk_builder_get_object(builder, "mess_Lab"));
    // виртуальная клавиатура
    keyboard_Gr = GTK_GRID(gtk_builder_get_object(builder, "keyboard_Gr"));
    //картинка
    Image = GTK_IMAGE(gtk_builder_get_object(builder, "Image"));

    gtk_builder_connect_signals(builder, NULL); //загрузка сигналов объектов
    g_object_unref(G_OBJECT(builder));
    gtk_widget_show(general_windows); // отображение окна
    gtk_main(); // передаем управление GTK+

    return 0;
}
