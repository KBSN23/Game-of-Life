#include <SFML/Graphics.h>
#include "include/simulation.h"
#include "include/board.h"
#include "include/cell.h"
#include "include/colors.h"

const int SIMBTN_POSITION_X = 200;
const int SIMBTN_POSITION_Y = 800;
const sfVector2f SIMBTN_SIZE = {150, 30};

simState initSimulation()
{
    simState state;
    state.isPaused = true;
    state.speed = 1;
    return state;
}

void drawSimBtn(sfRenderWindow *window, simState state)
{
    sfRectangleShape *randBtn = sfRectangleShape_create();
    sfVector2f randBtnPosition = {SIMBTN_POSITION_X, SIMBTN_POSITION_Y};

    sfRectangleShape_setSize(randBtn, SIMBTN_SIZE);
    sfRectangleShape_setOutlineThickness(randBtn, 1.f);
    sfRectangleShape_setFillColor(randBtn, BTN_FILL_COLOR);
    sfRectangleShape_setOutlineColor(randBtn, BTN_OUTLINE_COLOR);
    sfRectangleShape_setPosition(randBtn, randBtnPosition);

    sfFont *font = sfFont_createFromFile("./assets/arial.ttf");

    if (font != NULL)
    {
        sfText *randBtnText = sfText_create();
        sfText_setFont(randBtnText, font);
        sfText_setString(randBtnText, state.isPaused ? "Start" : "Stop");
        sfText_setColor(randBtnText, sfBlack);
        sfVector2f randBtnTextPosition = {SIMBTN_POSITION_X + 55, SIMBTN_POSITION_Y + 5};
        sfText_setCharacterSize(randBtnText, 16);
        sfText_setPosition(randBtnText, randBtnTextPosition);

        sfRenderWindow_drawRectangleShape(window, randBtn, NULL);
        sfRenderWindow_drawText(window, randBtnText, NULL);

        sfText_destroy(randBtnText);
    }

    sfFont_destroy(font);
    sfRectangleShape_destroy(randBtn);
}

bool isSimBtnClicked(sfVector2i mousePosition)
{
    return (mousePosition.x >= SIMBTN_POSITION_X && mousePosition.x <= SIMBTN_POSITION_X + SIMBTN_SIZE.x &&
            mousePosition.y >= SIMBTN_POSITION_Y && mousePosition.y <= SIMBTN_POSITION_Y + SIMBTN_SIZE.y);
}

void handleSimBtnClick(simState *state)
{
    if (state->isPaused)
    {
        state->isPaused = false;
    }
    else
    {
        state->isPaused = true;
    }
}

void nextTick(nextTickArgs args)
{
    simState *simulation = args.simulation;
    int **cellsMatrix = args.cellsMatrix;

    if (simulation->isPaused)
    {
        return;
    }
    int **tempMatrix = cellsMatrix_create();

    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLS; j++)
        {
            tempMatrix[i][j] = cellsMatrix[i][j];
        }
    }

    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLS; j++)
        {
            int live_neighbors = 0;

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0)
                    {
                        continue;
                    }
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < BOARD_ROWS && nj >= 0 && nj < BOARD_COLS)
                    {
                        live_neighbors += cellsMatrix[ni][nj];
                    }
                }
            }

            if (cellsMatrix[i][j] == 1)
            {
                if (live_neighbors < 2 || live_neighbors > 3)
                {
                    tempMatrix[i][j] = 0;
                }
            }
            else
            {
                if (live_neighbors == 3)
                {
                    tempMatrix[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLS; j++)
        {
            cellsMatrix[i][j] = tempMatrix[i][j];
        }
    }

    sfTime waitTime = sfMilliseconds(300);
    sfSleep(waitTime);
    nextTick(args);
};