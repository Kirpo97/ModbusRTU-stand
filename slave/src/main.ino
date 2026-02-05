
#include <ModbusRTU.h>
#include <LiquidCrystal_I2C.h>

uint32_t tmr;
ModbusRTU mb;
LiquidCrystal_I2C lcd(0x27,16,2);
int n = 0;

void setup() {
  Serial.begin(9600, SERIAL_8N1);
  lcd.begin();  
  lcd.backlight();
  mb.begin(&Serial, 12);    //TXswitch - D12 GPIO Arduino nano
  mb.setBaudrate(9600);
  mb.slave(3);

  mb.addHreg(0, 0, 3);     // mb.addHreg (Start Regs, fill, NumRegs)
  mb.Hreg(0, 11);
  mb.Hreg(1, 55);
  mb.Hreg(2, 33);

  mb.addCoil(0, 0, 3);
  mb.Coil(0, 1);
  mb.Coil(1, 1);
  mb.Coil(2, 1);

  mb.addIreg(0, 0, 3);
  mb.Ireg(0, 88);
  mb.Ireg(1, 9);
  mb.Ireg(2, 22);

  mb.addIsts(0, 0, 3);
  mb.Ists(0, 1);
  mb.Ists(1, 1);
  mb.Ists(2, 1);

}

void loop() {

  mb.task();
  yield();

  lcd.home();
  lcd.print("InA=");
  lcd.print(mb.Ireg(0));
  lcd.print("  ");
  lcd.setCursor(0,1);
  lcd.print("InD=");
  lcd.print(mb.Ists(0));

  lcd.setCursor(8,0);
  lcd.print("OutA=");
  lcd.print(mb.Hreg(0));
  lcd.print("  ");
  lcd.setCursor(8,1);
  lcd.print("OutD=");
  lcd.print(mb.Coil(0));

}