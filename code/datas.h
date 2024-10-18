#define PI 3.1415926535f
#define GRAVITY 9.78


//设置参数
struct SolveTrajectoryParams
{
    float k;             //弹道系数

    //自身参数
    float current_v;      //当前弹速


    //目标参数
    float x_target;             //ROS坐标系下的x
    float y_target;             //ROS坐标系下的y
    float z_target;             //ROS坐标系下的z
    float z_0;
};
