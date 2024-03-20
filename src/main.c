#include <SFML/Graphics.h>
#include "functions.h"

int main() {
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Game of Life", sfClose, NULL);
    
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        
        sfRenderWindow_clear(window, sfWhite);
        drawBoard(window, 10);
        sfRenderWindow_display(window);
    }
    
    sfRenderWindow_destroy(window);
    return 0;
}