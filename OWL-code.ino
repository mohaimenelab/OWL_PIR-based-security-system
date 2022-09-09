

// Must have to pay attention in 7 different comments line whose have indicated with 5 star

#include <TimerOne.h>

int counter_1 = 0;
int counter_2 = 0;
int counter_3 = 0;
int counter_4 = 0;
int counter_5 = 0;

int Timeperiod;

int highTime_p1 ;
int lowTime_p12;
int highTime_p2;
int lowTime_p23;
int highTime_p3;

int flag_1 = 0;
int flag_2 = 0;
int flag_3 = 0;
int flag_4 = 0;
int flag_5 = 0;
int flag_6 = 0;


void setup() 
{
  //delay(45000);
  pinMode (8, OUTPUT);
  pinMode (7, INPUT);
  Timer1.initialize();
  Timer1.attachInterrupt(count_Timeperiod);
  Serial.begin(9600);
}



void loop() 
{
  Serial.print("C1 =");
  Serial.print(counter_1);
  Serial.print("   ");
  Serial.print("h1 =");
  Serial.print(highTime_p1);
  Serial.print("    ");
  Serial.print("C2 =");
  Serial.print(counter_2);
  Serial.print("   ");
  Serial.print("LT12 =");
  Serial.print(lowTime_p12);
  Serial.print("    ");
  Serial.print("C3 =");
  Serial.print(counter_3);
  Serial.print("   ");
  Serial.print("h2 =");
  Serial.print(highTime_p2);
  Serial.print("    ");
  Serial.print("C4 =");
  Serial.print(counter_4);
  Serial.print("   ");
  Serial.print("LT23 =");
  Serial.print(lowTime_p23);
  Serial.print("    ");
  Serial.print("C5 =");
  Serial.print(counter_5);
  Serial.print("   ");
  Serial.print("h3 =");
  Serial.print(highTime_p3);
  Serial.print("    ");
  Serial.print("Timeperiod = ");
  Serial.print(Timeperiod);
  Serial.println();


  if(Timeperiod > 0)
  {
     if( Timeperiod >= 26 & Timeperiod <= 36 )          //*****   Timeperiod(26-36) will change according to different sensor
     {
      
      int r = digitalRead(10);
      
      if( r == 1 )
      {
    
       flag_6 = 1; 
       
       if( flag_6 == 1 )
       {

        digitalWrite(8, LOW);
        
        Timeperiod = 0;
      
        counter_1 = 0;
        counter_2 = 0;
        counter_3 = 0;
        counter_4 = 0;
        counter_5 = 0;
      
        highTime_p1 = 0;
        lowTime_p12 = 0;
        highTime_p2 = 0;
        lowTime_p23 = 0;
        highTime_p3 = 0;
      
        flag_1 = 0;
        flag_2 = 0;
        flag_3 = 0;
        flag_4 = 0;
        flag_5 = 0;
        flag_6 = 0;
       }
       
      }    

      else
      {
       digitalWrite(8, HIGH);  
      }
       
     }

     
     else
     {
      digitalWrite(8, LOW); 
     }
  }

  
  else
  {
    digitalWrite(8, LOW);
  }
  
}




void count_Timeperiod()
{   
  
   int x = digitalRead(7);

//--------------------------------------------------------------------------- First Pulse Start -----------------------------------------------------------------------------------------------
     
   if (x = 1 & x != 0 & flag_1 != 1 & flag_2 != 1)  
   {
     counter_1++;
     if(counter_1 > 15)         //*****   value 15 will change according to different sensor
     {
       counter_1 = 0;       
     }          
   }

          
   if( x != 1 )
   {
    
    if( counter_1 >= 8 & counter_1 <= 10)         //*****   range 8-10 will change according to different sensor
    {
      
     flag_1 = 1;
     highTime_p1 = counter_1;
    
    }
    
    else
    {
       counter_1 = 0;
       flag_1 = 0;
    }
    
   }
   
//------------------------------------------------------------- First pulse end , waiting for second pulse-------------------------------------------------------------------------------------
 
    if(highTime_p1 > 0) 
    {     
     int y = digitalRead(7);
     if(y != 1 & flag_2 != 1)
     {
      counter_2++;
      /*
      if(counter_2 > 4)
      {
        counter_2 = 0;
               
      }*/
     }
     if ( y == 1 & y != 0)
     { 
        if(counter_2 >= 1 & counter_2 < 4)
        {
         flag_2 = 1;
         lowTime_p12 = counter_2;
        }
        else
        {
         counter_2 = 0;
         lowTime_p12 = 0;
         counter_1 = 0;
         highTime_p1 = 0;
         flag_1 = 0;
         flag_2 = 0;  
        }
     }
      
   }

//-------------------------------------------------------------------------- Second pulse start -----------------------------------------------------------------------------------------------

 if(lowTime_p12 > 0)
 {
   int z = digitalRead(7);
   if(z == 1 & z != 0 & flag_3 != 1)
   {
    counter_3++;
    if(counter_3 > 15)           //*****   value 15 will change according to different sensor
    {
     counter_3 = 0;  
    }
   }

   if(z != 1)
   {
    if(counter_3 >= 8 & counter_3 <= 10)          //*****   range 8-10 will change according to different sensor
    {
      flag_3 = 1;
      highTime_p2 = counter_3; 
    } 
    else
    {
     counter_1 = 0;
     counter_2 = 0;
     counter_3 = 0;
     highTime_p1 = 0;
     lowTime_p12 = 0;
     highTime_p2 = 0;
     flag_1 = 0;
     flag_2 = 0;
     flag_3 = 0;  
    }
   }
   
 }
 
//------------------------------------------------------------------------ Second pulse end , waiting for third pulse -------------------------------------------------------------------------

if(highTime_p2 > 0) 
    {     
     int p = digitalRead(7);
     if(p != 1 & flag_4 != 1)
     {
      counter_4++;
      
      /*if(counter_4 > 4)
      {
        counter_4 = 0;
               
      }*/
     }
     if ( p == 1 & p != 0)
     { 
        if(counter_4 >= 1 & counter_4 < 4)
        {
         flag_4 = 1;
         lowTime_p23 = counter_4;
        }
        else
        {
          counter_1 = 0;
          counter_2 = 0;
          counter_3 = 0;
          counter_4 = 0;
          highTime_p1 = 0;
          lowTime_p12 = 0;         
          highTime_p2 = 0;
          lowTime_p23 = 0;
          flag_1 = 0;
          flag_2 = 0;
          flag_3 = 0; 
          flag_4 = 0;
           
        }
     }
      
   }


//----------------------------------------------------------------------------- Third pulse start ---------------------------------------------------------------------------------------------


 if(lowTime_p23 > 0)
 {
   int q = digitalRead(7);
   if(q == 1 & q != 0 & flag_5 != 1)
   {
    counter_5++;
    if(counter_5 > 15)          //*****   value 15 will change according to different sensor
    {
     counter_5 = 0;  
    }
   }

   if(q != 1)
   {
    if(counter_5 >= 8 & counter_5 <= 10)          //*****   range 8-10 will change according to different sensor
    {
      flag_5 = 1;
      highTime_p3 = counter_5; 
      if(highTime_p3 > 0)
      {
         Timeperiod = ( highTime_p1 + lowTime_p12 + highTime_p2 + lowTime_p23 + highTime_p3 );
      }
    } 
    else
    {
          counter_1 = 0;
          counter_2 = 0;
          counter_3 = 0;
          counter_4 = 0;
          counter_5 = 0;  
          highTime_p1 = 0;
          lowTime_p12 = 0;         
          highTime_p2 = 0;
          lowTime_p23 = 0;
          highTime_p3 = 0;
          flag_1 = 0;
          flag_2 = 0;
          flag_3 = 0; 
          flag_4 = 0;
          flag_5 = 0;
    }
    
   }
      
 }

}



