#include <FaceMoves.h>
#include <Servo.h>

int _pin_x_eyes, _pin_y_eyes, _pin_left_eyelid, _pin_right_eyelid;
Servo SX, SY, SL, SR;


FaceMoves::FaceMoves(int pin_x_eyes, int pin_y_eyes, int pin_left_eyelid, int pin_right_eyelid){
    SX.attach(pin_x_eyes);
    SY.attach(pin_y_eyes);
    SL.attach(pin_left_eyelid);
    SR.attach(pin_right_eyelid);
    _pin_x_eyes, _pin_y_eyes, _pin_left_eyelid, _pin_right_eyelid = pin_x_eyes, pin_y_eyes, pin_left_eyelid, pin_right_eyelid;
}
//pos is a value between -100 and 100 
int move_eyes_in_x(int pos){
    //10 a 50
    if(pos<-100 || pos>100){
        return -1;
    }
    int move_value = round(pos/5 + 30);
    SX.write(move_value);
    return 1;
}

int move_eyes_in_y(int pos){
    if(pos<-100 || pos>100){
        return -1;
    }
    int move_value = round(pos/5 + 30);
    SY.write(move_value);
    return 1;
}

int move_left_eyelid(int pos){
    if(pos<-100 || pos>100){
        return -1;
    }
    int move_value = round(pos/5 + 30);
    SL.write(move_value);
    return 1;
}

int move_right_eyelid(int pos){
    if(pos<-100 || pos>100){
        return -1;
    }
    int move_value = round(pos/5 + 30);
    SR.write(move_value);
    return 1;
}