#include <SFML/Graphics.h>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

sfRectangleShape* createCell(sfVector2f size, sfVector2f position);

void drawBoard(sfRenderWindow *window, int size);