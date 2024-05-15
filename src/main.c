#include <SFML/Graphics.h>
#include <stdio.h>
#include "include/functions.h"
#include "include/board.h"
#include "include/cell.h"
#include "include/randbtn.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Game of Life", sfClose, NULL);

    int **cellsMatrix = cellsMatrix_create();

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
                    else if (isRandBtnClicked(mousePosition))
                    {
                        handleRandBtnClick(cellsMatrix);
                    }
                }
            }
        }

        sfRenderWindow_clear(window, sfWhite);
        drawBoard(window, cellsMatrix);
        drawRandBtn(window);
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return 0;
}