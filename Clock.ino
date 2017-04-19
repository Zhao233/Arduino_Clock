#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int time_year = 2017;
int time_month = 4;
int time_day = 17;
int time_hour = 0;
int time_min = 0;
int time_sec = 0;

int position = 0;

void setup(){
    lcd.init();
    lcd.backlight();
}
void loop(){
    lcd.setCursor(0,0);
    lcd.print("It's a Good Day!");

    getTime();
    showTime();
    delay(1000);
}

void getTime(){
    time_sec += 1;
    getMin(time_sec);
    getHour(time_min);
    getDay(time_hour);
    getMonth(time_day);
    getYear(time_month);
}
void getMin(int sec){
    if(sec == 60){
        time_min += 1;
        time_sec = 0;
    }
}
void getHour(int min){
    if(min == 60){
        time_hour += 1;
        time_min = 0;
    }
}
void getDay(int hour){
    if(hour == 24){
        day += 1;
        hour = 0;
    }
}
void getMonth(int day){
    if(time_month / 2 == 0){  //odd number month
        if(day == 31){
            time_month += 1;
            time_day == 1;
        }
    } else { // even number month
        if(day == 32){
            time_month += 1;
            time_day == 1;
        }
    }
}
void getYear(int month){
    if(month == 13){
        time_year += 1;
        time_month == 1;
    }
}

int getTimePosition(int time){
    int pos = 0;
    while(time != 0){
        time = time / 10;
        pos += 1;
    }

    return pos;
}

void showTime(int year, int month, int day, int hour, int min, int sec){
    lcd.setCursor(0,1);
    lcd.print(year);
    lcd.print(month);
    lcd.print(day);
    lcd.print(".");
    lcd.print("hour");
    lcd.print(".");
    lcd.print("min");
    lcd.print(sec);
}