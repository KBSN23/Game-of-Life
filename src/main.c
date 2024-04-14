#include <SFML/Graphics.h>
#include "functions.h"

int main() {
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Game of Life", sfClose, NULL);

    unsigned short rows = 30;
    unsigned short cols = 40;

    int** cellsMatrix = cellsMatrix_create(cols, rows);

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed) {
                 if (event.mouseButton.button == sfMouseLeft) {

                    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(window);

                    int cellOffsetX = ((mousePosition.x + (int) CELL_SIZE ) / (int) CELL_SIZE) *  CELL_SIZE -  CELL_SIZE;
                    int cellOffsetY = ((mousePosition.y + (int) CELL_SIZE ) / (int) CELL_SIZE) *  CELL_SIZE - CELL_SIZE;

                    int *cell = &cellsMatrix[cellOffsetY / (int) CELL_SIZE][ cellOffsetX / (int) CELL_SIZE];

                    if(*cell == 0)
                        *cell = 1;
                    else
                        *cell = 0;
            }}
        }
        
        sfRenderWindow_clear(window, sfWhite);
        drawBoard(window, cellsMatrix, cols, rows);
        sfRenderWindow_display(window);
    }
    
    sfRenderWindow_destroy(window);
    return 0;
}