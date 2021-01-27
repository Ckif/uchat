//
// Created by Maksym Tsyfir on 1/26/21.
//

#include "client.h"

extern t_chat_win chat_win;
extern t_chat *chat;

static bool credentieal_file_type() {
    char *buff_str = chat->sys->file_path;
    char *extension = NULL;

    while (*buff_str) {
        buff_str++;
    }
    while (*buff_str != '.') {
        buff_str--;
    }
    extension = strdup(buff_str);
    if(strcmp(extension, ".wav") == 0 || strcmp(extension, ".mp3") == 0
      || strcmp(extension, ".aif") == 0 || strcmp(extension, ".mid") == 0) {
        free(extension);
        return true;
    }
    free(extension);
    return false;
}

static void relize () {
    mx_printstr("\nVoice path - ");
    mx_printint(chat->sys->position);
    mx_printstr("\nFile path - ");
    mx_printstr(chat->sys->file_path);
    mx_printstr("\nVoice name - ");
    mx_printstr(chat->sys->voice_name);
    mx_printstr("\nFile name - ");
    mx_printstr(chat->sys->filename);
    mx_printstr("\n");
//    mx_strdel(&chat->sys->file_path);
//    mx_strdel(&chat->sys->voice_name);
//    mx_strdel(&chat->sys->filename);
}
static void get_filename() {
    char *buff_path = chat->sys->file_path;

    while (*buff_path) {
        buff_path++;
    }
    while (*buff_path != '/') {
        buff_path--;
    }
    buff_path++;
    chat->sys->filename = strdup(buff_path);
//    mx_save_voice_file_request(chat->sys, chat->user, chat->json);
}


static bool open_file_cooser(int i) {

    // Show the "Open Text File" dialog box
//    gtk_window_set_transient_for(GTK_WINDOW(chat_win.file_choose_window), GTK_WINDOW(chat->sys->chat_window));
    gtk_widget_show_all(chat_win.file_choose_window);
    gtk_widget_get_can_default(chat_win.file_choose_window);

    // Check return value from Open Text File dialog box to see if user clicked the Open button
    if (gtk_dialog_run(GTK_DIALOG (chat_win.file_choose_window)) == 1) {
        // Get the file name from the dialog box
       chat->sys->file_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chat_win.file_choose_window));
        if (chat->sys->file_path != NULL && credentieal_file_type()) {
            chat->sys->position = i;
            get_filename();
            gtk_widget_hide(chat_win.file_choose_window);
            return true;
        }
    }
    // Finished with the "Open Text File" dialog box, so hide it
    return false;
    gtk_widget_hide(chat_win.file_choose_window);

}

void on_edit_vax1_open_btn_clicked (GtkButton *btn) {
    if (open_file_cooser(0)) {
        chat->sys->voice_name = strdup(gtk_entry_get_text(chat_win.edit_vax1_entry));
        relize();
    }
}
void on_edit_vax2_open_btn_clicked (GtkButton *btn) {
    if (open_file_cooser(1)) {
        chat->sys->voice_name = strdup(gtk_entry_get_text(chat_win.edit_vax2_entry));
        relize();
    }
}
void on_edit_vax3_open_btn_clicked (GtkButton *btn) {
    if (open_file_cooser(2)) {
        chat->sys->voice_name = strdup(gtk_entry_get_text(chat_win.edit_vax3_entry));
        relize();
    }
}
void on_edit_vax4_open_btn_clicked (GtkButton *btn) {
    if (open_file_cooser(3)) {
        chat->sys->voice_name = strdup(gtk_entry_get_text(chat_win.edit_vax4_entry));
        relize();
    }
}
void on_edit_vax5_open_btn_clicked (GtkButton *btn) {
    if (open_file_cooser(4)) {
        chat->sys->voice_name = strdup(gtk_entry_get_text(chat_win.edit_vax5_entry));
        relize();
    }
}
void on_edit_vax6_open_btn_clicked (GtkButton *btn) {
    if (open_file_cooser(5)) {
        chat->sys->voice_name = strdup(gtk_entry_get_text(chat_win.edit_vax6_entry));
        relize();
    }
}
void on_edit_vax7_open_btn_clicked (GtkButton *btn) {
    if (open_file_cooser(6)) {
        chat->sys->voice_name = strdup(gtk_entry_get_text(chat_win.edit_vax7_entry));
        relize();
    }
}
void on_edit_vax8_open_btn_clicked (GtkButton *btn) {
    if (open_file_cooser(7)) {
        chat->sys->voice_name = strdup(gtk_entry_get_text(chat_win.edit_vax8_entry));
        relize();
    }
}