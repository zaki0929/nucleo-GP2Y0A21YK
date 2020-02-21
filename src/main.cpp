#include "mbed.h"
#include <math.h>

DigitalOut myled(LED1);
Serial pc(USBTX, USBRX);
AnalogIn ain(A6);
 
int main()
{
    while (1) {
        double data = ain.read();
        double distance = 26.663 * pow((data * 3.3), -1.25);
        pc.printf("Distance : %4.3f[cm]\n", distance);
        if (distance > 60.0f) {
            myled = 1;
        } else {
            myled = 0;
        }
        wait(1.0f);
    }
}

