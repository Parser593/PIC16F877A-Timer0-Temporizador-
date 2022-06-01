#include <16F877A.h>
#fuses HS,NOWDT,NOPROTECT

#use delay(clock=2000000)

int8 rept;   //veces que se repetira la interrrupcion

#INT_RTCC
void temp(){
  rept--;
  set_rtcc(39);
  
  if(rept==0){
      rept = 90;
      output_toggle(PIN_B0);
  }
}

void main(){
   rept = 90;      
   set_RTCC(39);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256|RTCC_8_bit);
   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while(true){
   }
}

