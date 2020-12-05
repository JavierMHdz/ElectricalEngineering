class Clock{
   public:
   Clock(); //default
   Clock(int j, int, m, int s);
   void setTime(int h, int m, int s);
   void setAlarmTime(int h, int m, int s);
   bool isEnabled();
   void toggleEnable();
   bool checkAlarm();
   void tick();
   void printTime();
   
   private:
   int ch_,cm_,cs_;
   int ah_,am_,as_;
   
   bool enabled;

};
