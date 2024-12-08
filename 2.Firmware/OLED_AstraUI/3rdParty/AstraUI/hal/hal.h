//
// Created by Fir on 2024/2/8.
//
#pragma once
#ifndef ASTRA_CORE_SRC_HAL_HAL_H_
#define ASTRA_CORE_SRC_HAL_HAL_H_

#include <string>
#include <utility>
#include <vector>
#include "../astra/config/config.h"

namespace sys {
struct config {
  uint8_t screenWeight = 128;
  uint8_t screenHeight = 80;
  float screenBright = 255;
  //todo place other param of system
};

static config &getSystemConfig() {
  static config sysConfig;
  return sysConfig;
}
}

/**
 * @brief hardware abstraction layer.
 * @note provide a set of interfaces to access hardware.
 * @note provide some default implementation.
 */
class HAL {
private:
  static HAL *hal;

public:
  static HAL *get();    //get hal instance.
  static bool check();  //check if there is a hal instance.

  static bool inject(HAL *_hal);  //inject HAL instance and run hal_init.
  static void destroy();  //destroy HAL instance.

  virtual ~HAL() = default;

  virtual std::string type() { return "Base"; }

  virtual void init() {}

protected:
  sys::config config;

public:
  static void *getCanvasBuffer() { return get()->_getCanvasBuffer(); }

  virtual void *_getCanvasBuffer() { return nullptr; }

  static uint8_t getBufferTileHeight() { return get()->_getBufferTileHeight(); }

  virtual uint8_t _getBufferTileHeight() { return 0; }

  static uint8_t getBufferTileWidth() { return get()->_getBufferTileWidth(); }

  virtual uint8_t _getBufferTileWidth() { return 0; }

  static void canvasUpdate() { get()->_canvasUpdate(); }

  virtual void _canvasUpdate() {}

  static void canvasClear() { get()->_canvasClear(); }

  virtual void _canvasClear() {}

  static void setFont(const uint8_t *_font) { get()->_setFont(_font); }

  virtual void _setFont(const uint8_t *_font) {}

  static uint8_t getFontWidth(std::string &_text) { return get()->_getFontWidth(_text); }

  virtual uint8_t _getFontWidth(std::string &_text) { return 0; }

  static uint8_t getFontHeight() { return get()->_getFontHeight(); }

  virtual uint8_t _getFontHeight() { return 0; }

  static void setDrawType(uint8_t _type) { get()->_setDrawType(_type); }

  virtual void _setDrawType(uint8_t _type) {}

  static void drawPixel(float _x, float _y) { get()->_drawPixel(_x, _y); }

  virtual void _drawPixel(float _x, float _y) {}

  //notice: _x和_y是字体左下角的坐标 _x and _y is the coordinate the lower left corner of the font
  //todo 检查所有的draw函数的坐标是否是左下角的坐标
  static void drawEnglish(float _x, float _y, const std::string &_text) { get()->_drawEnglish(_x, _y, _text); }

  virtual void _drawEnglish(float _x, float _y, const std::string &_text) {}

  static void drawChinese(float _x, float _y, const std::string &_text) { get()->_drawChinese(_x, _y, _text); }

  virtual void _drawChinese(float _x, float _y, const std::string &_text) {}

  static void drawVDottedLine(float _x, float _y, float _h) { get()->_drawVDottedLine(_x, _y, _h); }

  virtual void _drawVDottedLine(float _x, float _y, float _h) {}

  static void drawHDottedLine(float _x, float _y, float _l) { get()->_drawHDottedLine(_x, _y, _l); }

  virtual void _drawHDottedLine(float _x, float _y, float _l) {}

  static void drawVLine(float _x, float _y, float _h) { get()->_drawVLine(_x, _y, _h); }

  virtual void _drawVLine(float _x, float _y, float _h) {}

  static void drawHLine(float _x, float _y, float _l) { get()->_drawHLine(_x, _y, _l); }

  virtual void _drawHLine(float _x, float _y, float _l) {}

  static void drawBMP(float _x, float _y, float _w, float _h, const uint8_t *_bitMap) {
    get()->_drawBMP(_x,
                    _y,
                    _w,
                    _h,
                    _bitMap);
  }

  virtual void _drawBMP(float _x, float _y, float _w, float _h, const uint8_t *_bitMap) {}

  static void drawBox(float _x, float _y, float _w, float _h) { get()->_drawBox(_x, _y, _w, _h); }

  virtual void _drawBox(float _x, float _y, float _w, float _h) {}

  static void drawRBox(float _x, float _y, float _w, float _h, float _r) {
    get()->_drawRBox(_x,
                     _y,
                     _w,
                     _h,
                     _r);
  }

  virtual void _drawRBox(float _x, float _y, float _w, float _h, float _r) {}

  static void drawFrame(float _x, float _y, float _w, float _h) { get()->_drawFrame(_x, _y, _w, _h); }

  virtual void _drawFrame(float _x, float _y, float _w, float _h) {}

  static void drawRFrame(float _x, float _y, float _w, float _h, float _r) {
    get()->_drawRFrame(_x,
                       _y,
                       _w,
                       _h,
                       _r);
  }

  virtual void _drawRFrame(float _x, float _y, float _w, float _h, float _r) {}

  static void printInfo(std::string _msg) { get()->_printInfo(std::move(_msg)); }

  virtual void _printInfo(std::string _msg);

  /**
   * @brief system timers.
   */
public:
  static void delay(unsigned long _mill) { get()->_delay(_mill); }

  virtual void _delay(unsigned long _mill) {}

  static unsigned long millis() { return get()->_millis(); }

  virtual unsigned long _millis() { return 0; }

  static unsigned long getTick() { return get()->_getTick(); }

  virtual unsigned long _getTick() { return 0; }

  static unsigned long getRandomSeed() { return get()->_getRandomSeed(); }

  /**optional**/
  virtual unsigned long _getRandomSeed() { return 0; }

  /**
   * @brief buzzer.
   * */


  /**
   * @brief key.
   */


  /**
   * @brief system config.
   */
public:
  static sys::config &getSystemConfig() { return get()->config; }

  static void setSystemConfig(sys::config _cfg) { get()->config = _cfg; }

  static void updateConfig() { get()->_updateConfig(); }

  virtual void _updateConfig() {}
};

#endif //ASTRA_CORE_SRC_HAL_HAL_H_
