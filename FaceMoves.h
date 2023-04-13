#ifndef _FACEMOVES_H
#define _FACEMOVES_H

#include <Arduino.h>
#include <Servo.h>

class FaceMoves {

    private:

    public:
        FaceMoves(int pin_x_eyes, int pin_y_eyes, int pin_left_eyelid, int pin_right_eyelid);
        int move_eyes_in_x(int pos);
        int move_eyes_in_y(int pos);
        int move_left_eyelid(int pos);
        int move_right_eyelid(int pos);
};
#endif