#include <SFML/Graphics.h>
#include <stdbool.h>

extern const int SIMBTN_POSITION_X;
extern const int SIMBTN_POSITION_Y;
extern const sfVector2f SIMBTN_SIZE;

typedef struct simState
{
    bool isPaused;
    int speed;
} simState;

simState initSimulation();
void drawSimBtn(sfRenderWindow *window, simState state);
bool isSimBtnClicked(sfVector2i mousePosition);
void handleBtnClick(int **cellsMatrix, simState &state);
void nextTick(int **cellsMatrix);
void pause(int **cellsMatrix);