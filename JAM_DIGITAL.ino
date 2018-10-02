#include <virtuabotixRTC.h>
#include <LiquidCrystal.h>
//pin LCD 20x4
LiquidCrystal lcd(7,6,5,4,3,2);
//pin RTC ke arduino (CLK, DAT, RST)
virtuabotixRTC myRTC(10, 11, 12);
//lm35
const int lm35 = A0;
float masuk =0;
float konversi, ukur = 0;

void setup()  
{    
  lcd.begin(16,2);
  lcd.setCursor(2,0);
  lcd.print("JAM  DIGITAL");
  lcd.setCursor(2,1);
  lcd.print("version  1.0");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("DUINO ELEKTRONIK");
  lcd.setCursor(0,1);
  lcd.print("made in  LAMPUNG");
  delay(2000);
  lcd.clear();

  //format RTC detik, menit, jam, banyak hari dalam satu minggu, hari, bulan, dan tahun
  //tidak diaktifkan agar mengikuti jam pada PC kita
  //myRTC.setDS1302Time(00, 00, 00, 6, 14, 9, 2018);
}
 
void loop()  
{                                                                                            
  DS1302();
  suhu();
  delay(1000);
}

void DS1302()
{
  // This allows for the update of variables for time or accessing the individual elements.
  myRTC.updateTime(); 
  lcd.setCursor(0,0);
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.println(myRTC.seconds);
  lcd.setCursor(0,1);
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
}

void suhu()
{
  masuk = analogRead(lm35);
  konversi = (masuk*5000)/1023;
  ukur = konversi/10;
  lcd.setCursor(11,0);
  lcd.print("SUHU");
  lcd.setCursor(10,1);
  lcd.print(ukur,1);//satu angka dibelakang koma
  lcd.print(char(223));
  lcd.print("C");
}

