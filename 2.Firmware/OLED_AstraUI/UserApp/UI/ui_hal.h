//
// Created by 24302 on 2024/12/6.
//

#ifndef OLED_ASTRAUI_UI_HAL_H
#define OLED_ASTRAUI_UI_HAL_H
#include "hal.h"
#include "u8g2.h"
#include "common_inc.h"
#include <cmath>
extern SSD1306 oled;

class UiHal:public HAL
{
public:
    UiHal() = default;
public:
    void init() override;

public:
    void _canvasUpdate() override;
    void _canvasClear() override;
    void* _getCanvasBuffer() override;
    uint8_t _getBufferTileHeight() override;
    uint8_t _getBufferTileWidth() override;
    uint8_t _getFontWidth(std::string& _text) override;
    uint8_t _getFontHeight() override;
    void _setFont(const uint8_t * _font) override;
    void _drawBox(float _x, float _y, float _w, float _h) override;
    void _setDrawType(uint8_t _type) override;
    void _drawEnglish(float _x, float _y, const std::string& _text) override;
    void _drawChinese(float _x, float _y, const std::string& _text) override;
    void _drawPixel(float _x, float _y) override;
    void _drawVDottedLine(float _x, float _y, float _h) override;
    void _drawHDottedLine(float _x, float _y, float _l) override;
    void _drawVLine(float _x, float _y, float _h) override;
    void _drawHLine(float _x, float _y, float _l) override;
    void _drawBMP(float _x, float _y, float _w, float _h, const uint8_t* _bitMap) override;
    void _drawRBox(float _x, float _y, float _w, float _h, float _r) override;
    void _drawFrame(float _x, float _y, float _w, float _h) override;
    void _drawRFrame(float _x, float _y, float _w, float _h, float _r) override;

public:
    void _delay(unsigned long _mill) override;
    unsigned long _millis() override;
    unsigned long _getTick() override;
    unsigned long _getRandomSeed() override;
};
#endif //OLED_ASTRAUI_UI_HAL_H
