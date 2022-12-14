#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SH110X.h"
#include "Defines.h"
#include "Vector2.h"

class Display
{
public:
    Display(const Display&) = delete;
    void operator=(const Display&) = delete;

    static Display& instance();

    void setup();

    void print(const char* text);
    void print(const char* text, int x, int y, int size = 1);
    void drawPixel(const Vector2& position, int color = SH110X_WHITE);
    void drawBox(const Vector2& position, int width, int height, int color = SH110X_WHITE);
    
    void display();
    void clear();

    bool isPixelDrawn(const Vector2& position);

private:
    Display();

    Adafruit_SH1107 m_display;
};

#endif