
#include "include/cell.h"
#include "include/board.h"
#include <stdlib.h>

const float CELL_SIZE = 15.f;
const sfColor CELL_COLOR_ALIVE = {26, 110, 26, 255};
const sfColor CELL_COLOR_DEFAULT = {214, 212, 212, 255};

sfRectangleShape *createCell(sfVector2f size, sfVector2f position, unsigned short alive)
{
    sfRectangleShape *square = sfRectangleShape_create();
    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setOutlineThickness(square, 1.f);
    if (alive == 1)
        sfRectangleShape_setFillColor(square, CELL_COLOR_ALIVE);
    else
        sfRectangleShape_setFillColor(square, CELL_COLOR_DEFAULT);
    sfRectangleShape_setOutlineColor(square, sfBlack);
    sfRectangleShape_setPosition(square, position);

    return square;
};

int **cellsMatrix_create(unsigned int cols, unsigned int rows)
{
    int **cellsMatrix = (int **)malloc(rows * sizeof(int *));

    if (cellsMatrix == NULL)
        return NULL;

    for (int i = 0; i < rows; i++)
    {
        cellsMatrix[i] = (int *)malloc(cols * sizeof(int));
        if (cellsMatrix[i] == NULL)
            return NULL;
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

void handleCellClick(int *cell)
{
    if (*cell == 0)
        *cell = 1;
    else
        *cell = 0;
}

int *getCellByPosition(sfVector2i mousePosition, int **cellsMatrix)
{
    int cellOffsetX = ((mousePosition.x - BOARD_POSITION_X) / CELL_SIZE) * CELL_SIZE;
    int cellOffsetY = ((mousePosition.y - BOARD_POSITION_Y) / CELL_SIZE) * CELL_SIZE;

    return &cellsMatrix[(int)cellOffsetY / (int)CELL_SIZE][(int)cellOffsetX / (int)CELL_SIZE];
}