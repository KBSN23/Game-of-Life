#include <SFML/Graphics.h>
#include <stdbool.h>

extern const int RANDBTN_POSITION_X;
extern const int RANDBTN_POSITION_Y;

void drawRandBtn(sfRenderWindow *window);
bool isRandBtnClicked(sfVector2i mousePosition);
void handleRandBtnClick(int **cellsMatrix);
