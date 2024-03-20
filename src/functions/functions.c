#include <SFML/Graphics.h>
#include "functions.h"


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

sfRectangleShape* createCell(sfVector2f size, sfVector2f position){
    sfRectangleShape* square = sfRectangleShape_create();
    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setOutlineThickness(square, 1.f);
    sfRectangleShape_setOutlineColor(square, sfBlack);
    sfRectangleShape_setPosition(square, position);

    return square;
};

void drawBoard(sfRenderWindow *window, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            sfVector2f cellPosition = { (WINDOW_WIDTH - size * size) / 2 + i * size,  j * size };


            sfVector2f cellSize = { size,  size};
            sfRectangleShape* cell = createCell(cellSize, cellPosition);
            sfRenderWindow_drawRectangleShape(window, cell, NULL);
        }
    }
}