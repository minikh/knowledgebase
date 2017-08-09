#include "math.h"     // математические функции
#include "PACRXPlc.h" //процедуры для контроллера

static float num[] = { 0.006, 0.011, 0.022, 0.044, 0.088, 0.176, 0.352, 0.703, 1.406, 2.813, 5.625, 11.25, 22.5, 45.0, 90.0, 180.0 };

int GefMain( unsigned int *in, float *res)
{
	int i;

	*res = 0;
	for( i = 0; i < 16; i++)
	{
		if( *in>>i & 0x01 )
		{
			*res += num[i];
		}
	}
	return GEF_EXECUTION_OK;
}