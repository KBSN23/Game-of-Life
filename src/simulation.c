#include "include/simulation.h"

const int SIMBTN_POSITION_X = 200;
const int SIMBTN_POSITION_Y = 800;
const sfVector2f SIMBTN_SIZE = {}

initSimulation()
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
    sfRectangleShape_setSize(randBtn, SIMBTN);
    sfRectangleShape_setOutlineThickness(randBtn, 1.f);
    sfRectangleShape_setFillColor(randBtn, sfWhite);
    sfRectangleShape_setOutlineColor(randBtn, sfBlack);
    sfRectangleShape_setPosition(randBtn, randBtnPosition);

    sfFont *font = sfFont_createFromFile("./assets/arial.ttf");

    if (font != NULL)
    {

        sfText *randBtnText = sfText_create();
        sfText_setFont(randBtnText, font);
        sfText_setString(randBtnText, "Losuj");
        sfText_setColor(randBtnText, sfBlack);
        sfVector2f randBtnTextPosition = {RANDBTN_POSITION_X + 16, RANDBTN_POSITION_Y};
        sfText_setCharacterSize(randBtnText, 16);
        sfText_setPosition(randBtnText, randBtnTextPosition);

        sfRenderWindow_drawRectangleShape(window, randBtn, NULL);
        sfRenderWindow_drawText(window, randBtnText, NULL);

        sfText_destroy(randBtnText);
    }

    sfFont_destroy(font);
    sfRectangleShape_destroy(randBtn);
}