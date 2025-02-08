# MatrixRain  

![matrixRain_TFTDisplay](https://github.com/user-attachments/assets/a754106c-ec9b-407c-b23e-888137f63c4e)
Forked from:https://github.com/delhoume/MatrixRain

A **Matrix rain** effect using **TFT_eSPI** and a modified version of **DigitalRainAnim**.  
Supports **smooth fonts** with ASCII and Hiragana characters, and utilizes **sprites** to reduce flicker.  

Compatible with **Arduino (ESP8266, ESP32)**, and also includes a **Processing** version.  

## Features & Improvements  

The original animation would **freeze instantly** when calling `digitalRainAnim.pause()`.  
This modification introduces a **smooth stop feature**, allowing existing lines to **finish falling naturally** before stopping the animation.  

### ✅ New Functionality  
- **Stop animation smoothly**:  
  Call `digitalRainAnim.stop();` to let existing lines fall but prevent new ones from spawning.  
- **Resume animation**:  
  Call `digitalRainAnim.resume();` to restart the effect.  

## 📝 Code Changes  

### 🔹 **New Function Added**  
```cpp
void DigitalRainAnim::stop() {
  isEnding = true;
}
```

### 🔹 **Modified Functions**
```cpp
void DigitalRainAnim::resume() { // also used in the original code to resume the animation after .pause()
  ...
  isEnding = false;
}

void DigitalRainAnim::lineAnimation(int lineNum) {  
    // Added code to stop drawing new lines when they reach the bottom of the screen
    //  and to stop drawing at all when the end of the line has reached the bottom.
  ...
  
  // If the end of the line has reached the bottom and isEnding is true, stop drawing  
  if ((line_pos[lineNum] - line_length[lineNum]) >= height && isEnding) {
    return;
  }

  ...

  // If the line reaches the bottom, restart it at the top IF not stop() -FLAG  
  if (line_pos[lineNum] >= height && !isEnding) {
    lineUpdate(lineNum);
  }
}
```

