#include <arduino.h>

#define PIN_LED_WITNESS (13)
#define PIN_PHOTO_REC (2)


void photo_rec_pin_changed ()
{
  // unsigned long curr_date = micros () ;
  /* Write the state of the photo transistor receiver on the witness LED. */
  digitalWrite (PIN_LED_WITNESS, digitalRead (PIN_PHOTO_REC)) ;
  /* Change the date anyway. */
  // prev_change_date = change_date ;
}

void setup ()
{
  pinMode (PIN_LED_WITNESS, OUTPUT) ;
  pinMode (PIN_PHOTO_REC, INPUT) ;
  digitalWrite (PIN_LED_WITNESS, LOW) ;  /* Initially turn the LED off. */
  /* Attach the handler detecting changes from the photo transistor receiver. */
  attachInterrupt (PIN_PHOTO_REC, photo_rec_pin_changed, CHANGE) ;
}

void loop ()
{
  /* Intentionnally empty. */
}
