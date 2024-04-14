#include <SFML/Graphics.h>
#include "functions.h"
#include <stdlib.h>

const int WINDOW_WIDTH    = 800;
const int WINDOW_HEIGHT   = 600;
const float CELL_SIZE     = 15.f;

const sfColor cellColorAlive     = {26, 110, 26, 255};
const sfColor cellColorDefault   = {214, 212, 212, 255};

sfRectangleShape *createCell(sfVector2f size, sfVector2f position, unsigned short alive)
{
    const int n = 5;

    sfRectangleShape *square = sfRectangleShape_create();
    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setOutlineThickness(square, 1.f);
    if (alive == 1)
        sfRectangleShape_setFillColor(square, cellColorAlive);
    else
        sfRectangleShape_setFillColor(square, cellColorDefault);
    sfRectangleShape_setOutlineColor(square, sfBlack);
    sfRectangleShape_setPosition(square, position);

    return square;
};

void drawBoard(sfRenderWindow *window, int **cellsMatrix, unsigned int cols, unsigned int rows)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sfVector2f cellPosition = {j * CELL_SIZE, i * CELL_SIZE};

            sfVector2f cellSize = {CELL_SIZE, CELL_SIZE};
            unsigned short alive = cellsMatrix[i][j];
            sfRectangleShape *cell = createCell(cellSize, cellPosition, alive);
            sfRenderWindow_drawRectangleShape(window, cell, NULL);
            sfRectangleShape_destroy(cell);
        }
    }
}

int **cellsMatrix_create(unsigned int cols, unsigned int rows)
{
    int **cellsMatrix = (int **)malloc(rows * sizeof(int *));

    if (cellsMatrix == NULL)

        return 1;

    for (int i = 0; i < rows; i++)
    {
        cellsMatrix[i] = (int *)malloc(cols * sizeof(int));
        if (cellsMatrix[i] == NULL)

            return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
                cellsMatrix[i][j] = 0;
        }
    }

    return cellsMatrix;
}