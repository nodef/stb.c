// Example implementing a simple text editor using stb_textedit.h
#include <stb.h>
#include <stdio.h>
#include <string.h>

#define TEXT_BUFFER_SIZE 256

// Define a structure for the text editor
typedef struct {
    char text[TEXT_BUFFER_SIZE];
    STB_TexteditState state;
} TextEditor;

// Define the required functions for stb_textedit
static void layout_func(StbTexteditRow *row, TextEditor *editor, int start_i) {
    row->x0 = 0;
    row->x1 = strlen(editor->text);
    row->baseline_y_delta = 1.25f;
    row->ymin = 0;
    row->ymax = 1;
    row->num_chars = strlen(editor->text) - start_i;
}

static float char_width(TextEditor *editor, int n) {
    return 1.0f; // Fixed width for simplicity
}

static int delete_chars(TextEditor *editor, int pos, int num) {
    int len = strlen(editor->text);
    if (pos + num > len) num = len - pos;
    memmove(editor->text + pos, editor->text + pos + num, len - pos - num + 1);
    return 1;
}

static int insert_chars(TextEditor *editor, int pos, const char *text, int num) {
    int len = strlen(editor->text);
    if (len + num >= TEXT_BUFFER_SIZE - 1) return 0; // Not enough space
    memmove(editor->text + pos + num, editor->text + pos, len - pos + 1);
    memcpy(editor->text + pos, text, num);
    return 1;
}

int main() {
    TextEditor editor;
    strcpy(editor.text, "Hello, stb_textedit!");
    stb_textedit_initialize_state(&editor.state, 0);

    printf("Initial text: %s\n", editor.text);

    // Simulate inserting text
    stb_textedit_key(&editor, &editor.state, 'A');
    printf("After inserting 'A': %s\n", editor.text);

    // Simulate deleting text
    stb_textedit_cut(&editor, &editor.state);
    printf("After deleting: %s\n", editor.text);

    return 0;
}
