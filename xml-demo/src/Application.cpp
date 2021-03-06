#include <iostream>

#include "hi_gv.h"
#include "hi_gv_log.h"
#include "hi_gv_parser.h"

#include "config/config.h"

int main(int argc,char* argv[]) {
    
    HI_GV_SetVsyncType(HIGV_VSYNC_SW);
    HI_GV_Log_SetLevel(HI_NULL, HIGV_LOG_DEBUG);

    HIGO_LAYER_INFO_S layerInfo = {
        SCREEN_WIDTH, SCREEN_HEIGHT,//图层在屏幕上显示宽度，必须大于0   图层在屏幕上显示高度，必须大于0
        SCREEN_WIDTH, SCREEN_HEIGHT,//图层的绘制buffer宽度，为0时，不创建绘制buffer 图层的绘制buffer高度，为0时，不创建绘制buffer
        SCREEN_WIDTH, SCREEN_HEIGHT,//图层的显示buffer宽度，为0时，和ScreenWidth相同    图层的显示buffer高度，为0时，和ScreenHeight相同

        HIGO_LAYER_FLUSH_DOUBBUFER,//图层的刷新方式，用户可根据使用场景选择不同的刷新模式来提高刷新效率,等于0时默认使用双缓冲+Flip刷新模式
        HIGO_LAYER_DEFLICKER_AUTO,//图层抗闪烁级别
        HIGO_PF_8888,//图层的像素格式，此格式必须为硬件图层所支持的格式，请根据不同硬件设备来选择图层的像素格式参数
        HIGO_LAYER_HD_0//图层硬件ID，能支持图层取决于芯片平台，支持一个高清和一个标清
    };


    HIGV_HANDLE layer = HI_NULL;//图层
    HIGV_HANDLE app = HI_NULL;


    HI_S32 status = 0;
    do {
        if(status = HI_GV_Init() != HI_SUCCESS)
            break;

        if(status = HI_GV_Layer_Create(&layerInfo, &layer) != HI_SUCCESS)
            break;
        
        if(status = HI_GV_Layer_SetDefault(layer) != HI_SUCCESS)
            break;

        if(status = HI_GV_Layer_SetActiveLayer(layer) != HI_SUCCESS)
            break;

        if(status = HI_GV_Layer_SetRotateMode(layer, SCREEN_ROTATE) != HI_SUCCESS)
            break;

        if(status = HI_GV_App_Create(APP_NAME, &app) != HI_SUCCESS)
            break;

        auto font_handle = CreateFont(DEFAULT_FONT_PATH, DEFAULT_FONT_SIZE);
        if(font_handle != HI_NULL) {
            HI_GV_Font_SetSystemDefault(font_handle);
        }


        //加载语言
        for (int i = 0; i < (sizeof(g_languages) / sizeof(g_languages[0])); i++) {
            HI_GV_Lan_Register(g_languages[i].name, font_handle, g_languages[i].type);
        }
        //设置当前语种
        HI_GV_Lan_Change(APP_LANGUAGE);

        //加载 bin 解析器
        if(status = HI_GV_PARSER_Init() != HI_SUCCESS)
            break;
        
        if(status = HI_GV_PARSER_LoadFile(APP_BIN_FILE_NAME) != HI_SUCCESS)
            break;

        //设置窗口回调函数，g_pfunHIGVAppEventFunc 函数列表必须使用 xml2bin 自动生成的
        HI_GV_PARSER_SetWidgetEventFunc(g_pfunHIGVAppEventFunc, sizeof(g_pfunHIGVAppEventFunc) / sizeof(g_pfunHIGVAppEventFunc[0]));

        if(status = HI_GV_PARSER_LoadViewById(APP_START_WINDOW) != HI_SUCCESS)
            break;

        if(status = HI_GV_Widget_Show(APP_START_WINDOW) != HI_SUCCESS)
            break;

        HI_GV_App_Start(app);
    } while(0);
    
    if(app != HI_NULL) {
        HI_GV_App_Destroy(app);
    }

    if(layer != HI_NULL) {
        HI_GV_Layer_Destroy(layer);
    }

    HI_GV_PARSER_Deinit();
    HI_GV_Deinit();
    return 0;
}