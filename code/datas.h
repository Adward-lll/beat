#define PI 3.1415926535f
#define GRAVITY 9.78


//���ò���
struct SolveTrajectoryParams
{
    float k;             //����ϵ��

    //�������
    float current_v;      //��ǰ����


    //Ŀ�����
    float x_target;             //ROS����ϵ�µ�x
    float y_target;             //ROS����ϵ�µ�y
    float z_target;             //ROS����ϵ�µ�z
    float z_0;
};
