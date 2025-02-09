/*
  DigitalRainAnim.h - Library for Digital Rain Animation for TFT_eSPI.
  Created by Eric Nam, December 30, 2020.
  Released into the public domain.
*/

#ifndef DigitalRainAnim_h
#define DigitalRainAnim_h

#include <TFT_eSPI.h>
#include <SPI.h>

#define FONT_SIZE 2             //set font size 2
#define LINE_WIDTH 17           //width for font size 2
#define LETTER_HEIGHT 18        //height for font size 2

class DigitalRainAnim {
  public:
    DigitalRainAnim();
    virtual ~DigitalRainAnim();   
    void init(TFT_eSPI* tft);            //initialization
    void init(TFT_eSPI* tft, int new_line_len_min, int new_line_len_max, int new_line_speed_min, int new_line_speed_max, int new_timeFrame); //initialization with parameters
    void loop();                         //loop animation
    void pause();                        //pause animation 
    void resume();                       //resume animation
    void stop();

  private:
    TFT_eSPI* tft_DigitalRainAnim; //target display TFT_eSPI
    TFT_eSprite* spr; 

    int line_len_min;              //minimum length of characters 
    int line_len_max;              //maximum length of characters c
    int line_speed_min;            //minimum vertical move speed
    int line_speed_max;            //maximum vertical move speed
    int width, height;             //width, height of display
    int numOfline;                 //number of calculated row
    bool isPlaying;                //boolean for play or pause
    int timeFrame;                 //time frame for drawing
    uint32_t lastDrawTime;         //checking last drawing time

    int* line_length;  //dynamic array for each line of vertical length
    int* line_pos;     //dynamic array for eacg line Y position
    int* line_speed;   //dynamic array for eacg line speed

    bool isEnding;

    void prepareAnim();                 //the function is to prepare all lines at the beginning
    void lineUpdate(int lineNum);       //the function is to update each line after disappeared from the screen
    void lineAnimation(int lineNum);    //the function is to update each line
    String getASCIIChar();              //the function is to get the random ASCII char 
    int getUnicodeChar();
    int setYPos(int lineLen);           //the function is to update the position of line
    int getRandomNum(int min, int max); //the function is to get the random number (including max)
};

#endif
