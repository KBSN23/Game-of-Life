#include <SFML/Graphics.h>

extern const float CELL_SIZE;
extern const sfColor CELL_COLOR_ALIVE;
extern const sfColor CELL_COLOR_DEFAULT;

sfRectangleShape *createCell(sfVector2f size, sfVector2f position, unsigned short alive);
int **cellsMatrix_create(unsigned int cols, unsigned int rows);
void handleCellClick(int *cell);
int *getCellByPosition(sfVector2i mousePosition, int **cellsMatrix);