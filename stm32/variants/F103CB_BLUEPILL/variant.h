#include "WVariant.h"

#include "usart.h"

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
#define digitalPinToPort(P)        ( g_APinDescription[P].GPIO )
#define digitalPinToBitMask(P)     ( g_APinDescription[P].pin )

#define PIN_LED  (45u)
