#include <SFML/Graphics.h>
#include <stdio.h>
#include "include/functions.h"
#include "include/board.h"
#include "include/cell.h"
#include "include/randbtn.h"
#include "include/simulation.h"
#include <time.h>

int main()
{

    srand(time(NULL));

    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Game of Life", sfClose, NULL);
    int **cellsMatrix = cellsMatrix_create();

    simState simulation = initSimulation();
    nextTickArgs args = {cellsMatrix, &simulation};
    sfThread *thread = sfThread_create(nextTick, &args);

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
                    else if (isSimBtnClicked(mousePosition))
                    {
                        handleSimBtnClick(&simulation);
                        sfThread_launch(thread);
                    }
                }
            }
        }

        sfRenderWindow_clear(window, sfWhite);
        drawBoard(window, cellsMatrix);
        drawRandBtn(window, !simulation.isPaused);
        drawSimBtn(window, simulation);
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return 0;
}