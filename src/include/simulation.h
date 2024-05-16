#include <SFML/Graphics.h>
#include <stdbool.h>

extern const int SIMBTN_POSITION_X;
extern const int SIMBTN_POSITION_Y;
extern const sfVector2f SIMBTN_SIZE;

typedef struct
{
    bool isPaused;
    int speed;
} simState;

typedef struct
{
    int **cellsMatrix;
    simState *simulation;
} nextTickArgs;

simState initSimulation();
void drawSimBtn(sfRenderWindow *window, simState state);
bool isSimBtnClicked(sfVector2i mousePosition);
void handleSimBtnClick(simState *state);
void nextTick(nextTickArgs args);
void pause(int **cellsMatrix);