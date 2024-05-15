#include <SFML/Graphics.h>
#include <stdio.h>
#include "include/functions.h"
#include "include/board.h"
#include "include/cell.h"

int main()
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Game of Life", sfClose, NULL);

    int **cellsMatrix = cellsMatrix_create(BOARD_COLS, BOARD_ROWS);

    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed)
            {
                if (event.mouseButton.button == sfMouseLeft)
                {
                    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(window);

                    if (isBoardClicked(mousePosition))
                    {
                        int *cell = getCellByPosition(mousePosition, cellsMatrix);
                        handleCellClick(cell);
                    }
                }
            }
        }

        sfRenderWindow_clear(window, sfWhite);
        drawBoard(window, cellsMatrix);
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return 0;
}