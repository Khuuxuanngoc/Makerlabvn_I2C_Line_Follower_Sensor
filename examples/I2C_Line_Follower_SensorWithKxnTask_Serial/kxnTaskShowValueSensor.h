#ifndef kxnTaskShowValueSensor_H
#define kxnTaskShowValueSensor_H

#include "kxnTask.h"
#include "MKE_I2C_5C_LineTracking.h"


CREATE_TASK(kxnTaskShowValueSensor)

MKE_I2C_5C_LineTracking LineFollowSensor;

void setup()
{
    Serial.begin(115200);
    LineFollowSensor.setup(0x2A);

    kxnTaskManager.add(this);
    setState(0); // KXN_TASK_STATE_START
}

void loop()
{
    /************ SENSOR *************/
    /*-------------------------------*/
    /* |LEFT| P1 P2 P3 P4 P5 |RIGHT| */
    /*     0b 1  1  1  1  1          */
    /*         0: White;             */
    /*         1: Black              */
    /*-------------------------------*/

    Serial.print("P1:");
    Serial.print(LineFollowSensor.getValue(0));
    Serial.print(" P2:");
    Serial.print(LineFollowSensor.getValue(1));
    Serial.print(" P3:");
    Serial.print(LineFollowSensor.getValue(2));
    Serial.print(" P4:");
    Serial.print(LineFollowSensor.getValue(3));
    Serial.print(" P5:");
    Serial.print(LineFollowSensor.getValue(4));

    Serial.print(" data:");
    Serial.println(LineFollowSensor.getValue(), BIN);

    kDelay(100); // Do not use delay() function
}

END

#endif