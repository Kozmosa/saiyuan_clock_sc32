  /**
 *****************************************************************************************************
  * @copyright	(c)  Shenzhen Saiyuan Microelectronics Co., Ltd
  * @file	         system_sc32f1xxx.c
  * @author	         MCD Application Team
  * @version 	
  * @date	
  * @brief	         CMSIS Cortex-M0 PlUs Device Peripheral Access Layer System Source File.
  * @details         
 *****************************************************************************************************
 * @attention
 *
 *****************************************************************************************************
 */

#include "sc32_conf.h"
#include "system_sc32f1xxx.h"


/************************* Miscellaneous Configuration ************************/
/*!< Uncomment the following line if you need to relocate your vector Table in Internal SRAM. */
/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET  0x00 /*!< Vector Table base offset field. This value must be a multiple of 0x200. */
/******************************************************************************/

/*
  * @brief  Setup the microcontroller system
  *         Initialize the vector table location configuration.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
  /* Configure the Vector Table location add offset address ------------------*/
#ifdef VECT_TAB_SRAM
  SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#else
  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
#endif
}



