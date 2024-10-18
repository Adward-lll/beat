#include<iostream>
#include "datas.h"
#include<cmath>
using namespace std;

struct SolveTrajectoryParams st;

float high(float s, float v, float angle)
{
    float z;
    float t = (float)((exp(st.k * s) - 1) / (st.k * v * cos(angle)));
    z = (float)(v * sin(angle) * t - GRAVITY * t * t / 2);
    return z;
}

float angle(float s, float z_0, float z, float v)
{
    float z_temp, z_actual, dz;
    float angle_pitch;
    int i = 0;
    z_temp = z_0;
    i = 1;
    while (true)
    {

        angle_pitch = atan2(z_temp, s); // rad
        z_actual = high(s, v, angle_pitch);
        dz = z - z_actual;
        z_temp = z_temp + dz;
        double degrees = angle_pitch * (180.0 / PI);
        cout << "迭代次数" << i<<endl;
        cout << "击中实际高度为"<<z_actual<<endl;
        cout <<"暂存高度为" << z_temp << endl;
        cout << "仰角为" << degrees<<"°" << endl;
        cout << "误差为" << dz << endl;
        cout <<"\n" ;
        i++;
        if (fabsf(dz) < 0.000001)
        {
            break;
        }
    }
    return angle_pitch;
}

int main()
{
    st.x_target = 3;
    st.y_target = 4;
    st.z_target = 0.25;
    float s = 5;
    st.z_0 = 0.2;
    st.k = 0.077;
    st.current_v = 17;
    angle(s, st.z_0, st.z_target, st.current_v);

}