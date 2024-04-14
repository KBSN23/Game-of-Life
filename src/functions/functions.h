#include <SFML/Graphics.h>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const float CELL_SIZE;
extern const sfColor cellColorAlive;
extern const sfColor cellColorDefault;


sfRectangleShape* createCell(sfVector2f size, sfVector2f position, unsigned short alive);

void drawBoard(sfRenderWindow *window, int** CellsMatrix, unsigned int cols, unsigned int rows);

int** cellsMatrix_create(unsigned int cols, unsigned int rows);