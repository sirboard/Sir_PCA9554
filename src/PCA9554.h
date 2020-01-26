#ifndef __SIR_PCA9554_H__
#define __SIR_PCA9554_H__

#include <Arduino.h>
#include <Wire.h>

#define NORMAL          0
#define INVERTED        1

#define INPUT_REG  	    0x00
#define OUTPUT_REG 	    0x01
#define POLARITY_REG	0x02
#define CONFIG_REG 	    0x03


struct registers {
    uint8_t input_;
    uint8_t output_;
    uint8_t polarity_;
    uint8_t config_;
 }

class Sir_PCA9554
{
  private:
    registers _registers;
    uint16_t readRegister(uint8_t, uint8_t);
    void writeRegister(uint8_t, uint8_t, uint8_t);

  public:
    Sir_PCA9554();
    void init(void);

    void pinMode(uint8_t, uint8_t);
    void pinPolarity(uint8_t, uint8_t);
    void digitalWrite(uint8_t, boolean);
    uint8_t digitalRead(uint8_t);
};


#endif