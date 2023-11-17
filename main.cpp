#include "mbed.h"

PwmOut x(p21);
PwmOut y(p22);

float resistenciaX = 111.1f;
float condensadorX = 0.000001f;
float tauX;
float resistenciaY = 111.1f;
float condensadorY = 0.000001f;
float tauY;

int WAIT_TIME = 2;

void draw_shape() {
    int x_origin = 10;
    int x_end = 90;
    int y_origin = 10;
    int y_end = 90;

    int separation = 10;

    y.write(y_origin/100.0f);

    // Increment from X = Min to Max. 
    for (int duty = x_origin ; duty <= x_end ; duty += separation)
    {
        x.write(float(duty) / 100.0f);
        thread_sleep_for(WAIT_TIME); 
    }

    // Increment from Y = Min to Max. 
    for (int duty = y_origin; duty <= y_end; duty += separation)
    { 
        y.write(float(duty) / 100.0f);
        thread_sleep_for(WAIT_TIME); 
    }


    // Decrement from X = Max to Min. 
    for (int duty = x_end; duty >= x_origin; duty -= separation )
    {
        x.write(float(duty) / 100.0f);
        thread_sleep_for(WAIT_TIME); 
    }

    // Decrement from Y = Max to Min. 	
    for (int duty = y_end; duty >= y_origin; duty -= separation )
    {
        y.write(float(duty) / 100.0f);
        thread_sleep_for(WAIT_TIME); 
    }
}

// main() runs in its own thread in the OS
int main()
{
    tauX = resistenciaX * condensadorX;
    tauY = resistenciaY * condensadorY;

    x.period(tauX);
    y.period(tauY);

    while(1) {
        draw_shape();
    }
}

