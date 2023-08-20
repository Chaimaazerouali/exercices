#include "main.h"

/**
 * set_params - Reset parameter settings structure fields.
 * @params: The parameter settings struct.
 * @args: Argument pointer.
 *
 * Return: void
 */
void 	set_params(param_t *params, va_list args)
{
	params->isUnsigned = 0;
	params->plus = 0;
	params->space = 0;
	params->hashtag = 0;
	params->zero = 0;
	params->minus = 0;
	params->widthVal = 0;
	params-> precisionVal = UINT_MAX;

	params->hMod = 0;
	params->lMod = 0;
	(void)args;
}

