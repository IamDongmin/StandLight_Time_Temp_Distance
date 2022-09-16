#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    bDistanceLight=false;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight)
            {
                view->setState(lightState);
            }
            else    //거리범위 밖
            {
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight)
            {
                view->setState(lightState);
            }
            else    //거리범위 밖
            {
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight)
            {
                view->setState(lightState);
            }
            else    //거리범위 밖
            {
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight)
            {
                view->setState(lightState);
            }
            else    //거리범위 밖
            {
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight)
            {
                view->setState(lightState);
            }
            else    //거리범위 밖
            {
                view->setState(LIGHT_OFF);
            }
        break;
    }
}

void Service::updateDistance(int distance)
{
    printf("distance : %d\n", distance);

    static int distance_level_check_count = 0;
    if(distance < 0 || distance > 100)
    {
        distance_level_check_count++;
        if(distance_level_check_count > 10)
        {
            bDistanceLight = false;//Lightoff
            view->setState(LIGHT_OFF);
        }
    }
    else
    {
        distance_level_check_count = 0;
        
        bDistanceLight = true;
        view -> setState(lightState);
        //LightOn
    }
}