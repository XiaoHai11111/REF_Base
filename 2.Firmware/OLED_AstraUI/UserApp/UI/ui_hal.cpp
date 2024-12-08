//
// Created by 24302 on 2024/12/6.
//
#include "ui_hal.h"
void UiHal::init()
{
    oled.Init();
}

void UiHal::_canvasClear()
{
    oled.clearBuffer();
}

void UiHal::_canvasUpdate()
{
    oled.sendBuffer();
}

void* UiHal::_getCanvasBuffer()
{
    return oled.getBufferPtr();
}

uint8_t UiHal::_getBufferTileHeight()
{
    return oled.getBufferTileHeight();
}

uint8_t UiHal::_getBufferTileWidth()
{
    return oled.getBufferTileWidth();
}

uint8_t UiHal::_getFontWidth(std::string& _text)
{
    return oled.getUTF8Width(_text.c_str());
}

uint8_t UiHal::_getFontHeight()
{
    return oled.getMaxCharHeight();
}

void UiHal::_drawBox(float _x, float _y, float _w, float _h)
{
    oled.drawBox((int16_t)std::round(_x), (int16_t)std::round(_y), (int16_t)std::round(_w), (int16_t)std::round(_h));
}

void UiHal::_setDrawType(uint8_t _type)
{
    oled.setDrawColor(_type);
}

void UiHal::_setFont(const uint8_t * _font)
{
    oled.setFont(_font);
}

void UiHal::_drawEnglish(float _x, float _y, const std::string& _text)
{
    oled.drawStr((int16_t)std::round(_x), (int16_t)std::round(_y), _text.c_str());
}

void UiHal::_drawChinese(float _x, float _y, const std::string& _text)
{
    oled.drawUTF8((int16_t)std::round(_x), (int16_t)std::round(_y), _text.c_str());
}

void UiHal::_drawPixel(float _x, float _y)
{
    oled.drawPixel((int16_t)std::round(_x), (int16_t)std::round(_y));
}

void UiHal::_drawVDottedLine(float _x, float _y, float _h)
{
    for (unsigned char i = 0; i < (unsigned char)std::round(_h); i++) {
        if (i % 8 == 0 | (i - 1) % 8 == 0 | (i - 2) % 8 == 0) continue;
        oled.drawPixel((int16_t)std::round(_x), (int16_t)std::round(_y) + i);
    }
}
void UiHal::_drawHDottedLine(float _x, float _y, float _l)
{
    for (unsigned char i = 0; i < _l; i++) {
        if (i % 8 == 0 | (i - 1) % 8 == 0 | (i - 2) % 8 == 0) continue;
        oled.drawPixel((int16_t)std::round(_x) + i, (int16_t)std::round(_y));
    }
}

void UiHal::_drawVLine(float _x, float _y, float _h)
{
    oled.drawVLine((int16_t)std::round(_x), (int16_t)std::round(_y), (int16_t)std::round(_h));
}

void UiHal::_drawHLine(float _x, float _y, float _l)
{
    oled.drawHLine((int16_t)std::round(_x), (int16_t)std::round(_y), (int16_t)std::round(_l));
}

void UiHal::_drawBMP(float _x, float _y, float _w, float _h, const uint8_t* _bitMap)
{
    oled.drawXBMP((int16_t)std::round(_x), (int16_t)std::round(_y), (int16_t)std::round(_w), (int16_t)std::round(_h), _bitMap);
}

void UiHal::_drawRBox(float _x, float _y, float _w, float _h, float _r)
{
    oled.drawRBox((int16_t)std::round(_x), (int16_t)std::round(_y), (int16_t)std::round(_w), (int16_t)std::round(_h), (int16_t)std::round(_r));
}

void UiHal::_drawFrame(float _x, float _y, float _w, float _h)
{
    oled.drawFrame((int16_t)std::round(_x), (int16_t)std::round(_y), (int16_t)std::round(_w), (int16_t)std::round(_h));
}

void UiHal::_drawRFrame(float _x, float _y, float _w, float _h, float _r)
{
    oled.drawRFrame((int16_t)std::round(_x), (int16_t)std::round(_y), (int16_t)std::round(_w), (int16_t)std::round(_h), (int16_t)std::round(_r));
}

void UiHal::_delay(unsigned long _mill) {
    osDelay(_mill);
}

unsigned long UiHal::_millis() {
    return xTaskGetTickCount();
}

unsigned long UiHal::_getTick() {
    return xTaskGetTickCount();
}

unsigned long UiHal::_getRandomSeed() {
    return 2000;
}