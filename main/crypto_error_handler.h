#include "freertos/task.h"

/*
 *  * Check the return status of a function.
 *   * Assume 0 = SUCCESS.
 *    * If non-zero, stop the code.
 *     */
void check_ret(int ret)
{
	if(ret != 0)
	{
		printf("There is a problem. Error code %X. Refer here for more information:\n%s\n", ret, "https://github.com/MicrochipTech/cryptoauthlib/blob/master/lib/atca_status.h");
		while(true) vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}
