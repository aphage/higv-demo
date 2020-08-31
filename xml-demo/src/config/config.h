#pragma once

#include "hi_gv.h"

typedef struct {
    const char* name;
    const char* type;
}LANGUAGES_TYPE;

#define SCREEN_WIDTH 480    //屏幕宽度
#define SCREEN_HEIGHT 854   //屏幕高度
#define SCREEN_ROTATE HIGV_ROTATE_180 //屏幕旋转

#define APP_NAME "app"
#define APP_START_WINDOW PAGE_MAIN
#define APP_BIN_FILE_NAME "resource/app.bin"

#define APP_LANGUAGE LAN_ZH     //默认语言

#define DEFAULT_FONT_PATH "resource/fonts/simhei.ttf" //字体
#define DEFAULT_FONT_SIZE 18

LANGUAGES_TYPE g_languages[] = {
    {"resource/languages/en.lang", LAN_EN},
    {"resource/languages/zh.lang", LAN_ZH}
};