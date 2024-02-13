#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

#define D_SCREEN_WIDTH (1280)
#define D_SCREEN_HEIGHT (720)

#define D_UI_BACK_HEIGHT (70)

#define D_GAME_SCREEN_LEFT (0)
#define D_GAME_SCREEN_RIGHT (1280)
#define D_GAME_SCREEN_UPPER (0)


/******************************************
* �񋓌^�̐錾
******************************************/
enum mode {
	TITLE,
	RANKING,
	MAIN,
};
#define D_GAME_SCREEN_FOOTER (D_SCREEN_HEIGHT - D_UI_BACK_HEIGHT)
