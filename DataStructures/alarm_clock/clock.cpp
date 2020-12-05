#include "clock.h"

Clock::Clock()
{
   ch_ = 12; cm_=0; cs_=0;
   ah_ = 12; ah_=0; as_=0;
   enable_= false;
}

Clock::Clock(int h, int m, int s)
{
   ch_ = h; cm_=m; cs_=s;
   ah_ = 12; ah_=0; as_=0;
   enable_= false;
}

void Clock::setTime(int h, int m, int s)
{
   ch_=h; cm_=m; cs_=s;
}

void Clock::setTime(int h, int m, int s)
{
   ah_=h; am_=m; as_=s;
}

bool Clock::isEnabled()
{
   return enabled_;
}

void Clock::toggleEnable()
{
   enabled_= !enabled;
}

bool Clock::checkAlarm(){
   return(enabled_ && ch_==ah_ && cm_==am_ && cs_==as);
}

void tick()
{
   cs_++;
   if(cs_ == 60){
      cm_++;
      cs_ = 0;
         if(cm_ == 60){
   ch_++;
   cm_ = 0;
   
   if (ch_== 24){
   ch_=0;
   }
   }
   }
if(checkAlarm()){
cout<<"Alarm!!"<<endl;
}
}

void Clock::setTime(int h, int m, int s)
{
 cout<<ch_<<":"<< cm_=m<<":"<< cs_=s<<endl;;
}
