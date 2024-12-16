/*
 ******************************************************************************
 * @file    sc32f1xxx_ADC.h
 * @author  SOC AE Team
 * @version V1.5
 * @date     26-08-2024
 * @brief   Header file of ADC module.
 ******************************************************************************
 * @attention
 *
 *1.This software is supplied by SinOne Microelectronics Co.,Ltd. and is only
 *intended for use with SinOne products. No other uses are authorized. This
 *software is owned by SinOne Microelectronics Co.,Ltd. and is protected under
 *all applicable laws, including copyright laws.
 *2.The software which is for guidance only aims at providing customers with
 *coding information regarding their products in order for them to save time.
 *As a result, SinOne shall not be held liable for any direct, indirect or
 *consequential damages with respect to any claims arising from the content of
 *such software and/or the use made by customers of the coding information
 *contained herein in connection with their products.
 *
 *  COPYRIGHT 2024 SinOne Microelectronics
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f1xxx_ADC_H
#define __sc32f1xxx_ADC_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32_conf.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"

/** @addtogroup sc32f1xxx_StdPeriph_Driver
 * @{
 */

/** @addtogroup ADC
 * @{
 */

/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup ADC_Exported_Enumerations ADC Exported Enumerations
 * @{
 */

/** @brief ADC_ConvMode ADC Conversion Mode
 * @{
 */
typedef enum
{
    ADC_ConvMode_Single        = ( uint16_t ) ( 0x00 << ADC_CON_CONT_Pos ), /*!<Single conversion mode */
    ADC_ConvMode_Continuous    = ( uint16_t ) ( 0x01 << ADC_CON_CONT_Pos ), /*!<Continuous conversion mode */
} ADC_ConvMode_TypeDef;

#define IS_ADC_CONVMODE(MODE) (((MODE) == ADC_ConvMode_Single) ||  \
															 ((MODE) == ADC_ConvMode_Continuous))
/**
 * @}
 */

/** @brief ADC_Prescaler ADC Prescaler
 * @{
 */
typedef enum
{
    ADC_Prescaler_3CLOCK  = ( uint32_t ) ( 0x04 << ADC_CON_LOWSP_Pos ), /*!<The sampling time is 3 APB2 clocks */
    ADC_Prescaler_6CLOCK  = ( uint32_t ) ( 0x05 << ADC_CON_LOWSP_Pos ), /*!<The sampling time is 6 APB2 clocks */
    ADC_Prescaler_16CLOCK = ( uint32_t ) ( 0x06 << ADC_CON_LOWSP_Pos ), /*!<The sampling time is 16 APB2 clocks */
    ADC_Prescaler_32CLOCK = ( uint32_t ) ( 0x07 << ADC_CON_LOWSP_Pos ), /*!<The sampling time is 32 APB2 clocks */
} ADC_Prescaler_TypeDef;

#define IS_ADC_PRESCALER(PRESCALER) (((PRESCALER) == ADC_Prescaler_3CLOCK) ||  \
																		 ((PRESCALER) == ADC_Prescaler_6CLOCK) ||  \
																		 ((PRESCALER) == ADC_Prescaler_16CLOCK) || \
																		 ((PRESCALER) == ADC_Prescaler_32CLOCK))
/**
 * @}
 */

/** @brief ADC_ChannelTypedef ADC input channel
 * @{
 */

typedef enum
{
    ADC_Channel_0      = ( uint16_t ) 0x00,		 /*!< ADC input channel 0 */
    ADC_Channel_1      = ( uint16_t ) 0x01,		 /*!< ADC input channel 1 */
    ADC_Channel_2      = ( uint16_t ) 0x02,		 /*!< ADC input channel 2 */
    ADC_Channel_3      = ( uint16_t ) 0x03,		 /*!< ADC input channel 3 */
    ADC_Channel_4      = ( uint16_t ) 0x04,		 /*!< ADC input channel 4 */
    ADC_Channel_5      = ( uint16_t ) 0x05,	 	 /*!< ADC input channel 5 */
    ADC_Channel_6      = ( uint16_t ) 0x06,		 /*!< ADC input channel 6 */
    ADC_Channel_7      = ( uint16_t ) 0x07,		 /*!< ADC input channel 7 */
    ADC_Channel_8      = ( uint16_t ) 0x08,		 /*!< ADC input channel 8 */
    ADC_Channel_9      = ( uint16_t ) 0x09,		 /*!< ADC input channel 9 */
    ADC_Channel_10     = ( uint16_t ) 0x0A,		 /*!< ADC input channel 10 */
    ADC_Channel_11     = ( uint16_t ) 0x0B,		 /*!< ADC input channel 11 */
    ADC_Channel_12     = ( uint16_t ) 0x0C,		 /*!< ADC input channel 12 */
    ADC_Channel_13     = ( uint16_t ) 0x0D,		 /*!< ADC input channel 13 */
    ADC_Channel_14     = ( uint16_t ) 0x0E,		 /*!< ADC input channel 14 */
    ADC_Channel_15     = ( uint16_t ) 0x0F,		 /*!< ADC input channel 15 */
    ADC_Channel_VDD_D4 = ( uint16_t ) 0x1F,		 /*!< ADC_CHANNEL VDD Divide 4 */
#if defined(SC32f10xx)
    ADC_Channel_16     = ( uint16_t ) 0x10,		 /*!< ADC input channel 16 */
#elif defined(SC32f11xx)
    ADC_Channel_16     = ( uint16_t ) 0x10,		 /*!< ADC input channel 16 */
    ADC_Channel_17     = ( uint16_t ) 0x11,		 /*!< ADC input channel 17 */
    ADC_Channel_PGA    = ( uint16_t ) 0x1E,		 /*!< ADC_CHANNEL PGA */
#elif defined(SC32f12xx)
    ADC_Channel_OP    = ( uint16_t ) 0x1E,		 /*!< ADC_CHANNEL OP */
#endif
} ADC_ChannelTypedef;


#if defined(SC32f10xx)
#define IS_ADC_CHANNEL(CHANNEL) ((CHANNEL) <= ADC_Channel_16 ||\
                                 (CHANNEL) == ADC_Channel_VDD_D4)
#elif defined(SC32f11xx)
#define IS_ADC_CHANNEL(CHANNEL) ((CHANNEL) <= ADC_Channel_17  ||\
                                 (CHANNEL) == ADC_Channel_PGA ||\
                                 (CHANNEL) == ADC_Channel_VDD_D4)
#elif defined(SC32f12xx)
#define IS_ADC_CHANNEL(CHANNEL) ((CHANNEL) <= ADC_Channel_15  ||\
                                 (CHANNEL) == ADC_Channel_OP ||\
                                 (CHANNEL) == ADC_Channel_VDD_D4)
#endif
/**
 * @}
 */

/** @brief ADC_EAIN ADC Enable Input
 * @{
 */

typedef enum
{
    ADC_EAIN_Less = ( uint32_t ) 0x00000000,	/*!< ADC port Less */
    ADC_EAIN_0   = ( uint32_t ) 0x00000001,	/*!< ADC port 0 */
    ADC_EAIN_1   = ( uint32_t ) 0x00000002,	/*!< ADC port 1 */
    ADC_EAIN_2   = ( uint32_t ) 0x00000004,	/*!< ADC port 2 */
    ADC_EAIN_3   = ( uint32_t ) 0x00000008,	/*!< ADC port 3 */
    ADC_EAIN_4   = ( uint32_t ) 0x00000010,	/*!< ADC port 4 */
    ADC_EAIN_5   = ( uint32_t ) 0x00000020,	/*!< ADC port 5 */
    ADC_EAIN_6   = ( uint32_t ) 0x00000040,	/*!< ADC port 6 */
    ADC_EAIN_7   = ( uint32_t ) 0x00000080,	/*!< ADC port 7 */
    ADC_EAIN_8   = ( uint32_t ) 0x00000100,	/*!< ADC port 8 */
    ADC_EAIN_9   = ( uint32_t ) 0x00000200,	/*!< ADC port 9 */
    ADC_EAIN_10   = ( uint32_t ) 0x0000400,	/*!< ADC port 10 */
    ADC_EAIN_11   = ( uint32_t ) 0x0000800,	/*!< ADC port 11 */
    ADC_EAIN_12  = ( uint32_t ) 0x00001000, /*!< ADC port 12 */
    ADC_EAIN_13  = ( uint32_t ) 0x00002000, /*!< ADC port 13 */
    ADC_EAIN_14  = ( uint32_t ) 0x00004000, /*!< ADC port 14 */
    ADC_EAIN_15  = ( uint32_t ) 0x00008000, /*!< ADC port 15 */
#if defined(SC32f10xx)
    ADC_EAIN_16  = ( uint32_t ) 0x00010000, /*!< ADC port 16 */
    ADC_EAIN_All = ( uint32_t ) 0x0001FFFF, /*!< ADC port All */
#elif defined(SC32f11xx)
    ADC_EAIN_16  = ( uint32_t ) 0x00010000, /*!< ADC port 16 */
    ADC_EAIN_17  = ( uint32_t ) 0x00020000, /*!< ADC port 17 */
    ADC_EAIN_All = ( uint32_t ) 0x0003FFFF, /*!< ADC port All */
#elif defined(SC32f12xx)
    ADC_EAIN_All = ( uint32_t ) 0x0000FFFF, /*!< ADC port All */
#endif
} ADC_EAIN_Typedef;



#define IS_ADC_EAIN(EAIN) ((EAIN | ADC_EAIN_All) != 0 || EAIN == ADC_EAIN_Less)
/**
 * @}
 */

/** @brief ADC_VREF ADC Reference Voltage
 * @{
 */
typedef enum
{
    ADC_VREF_VDD    = ( uint32_t ) ( 0x00 << ADC_CON_VREFS_Pos ),	 /*!< ADC reference voltage is VDD    */
    ADC_VREF_2_048V = ( uint32_t ) ( 0x01 << ADC_CON_VREFS_Pos ),	 /*!< ADC reference voltage is 2.048V */
    ADC_VREF_1_024V = ( uint32_t ) ( 0x02 << ADC_CON_VREFS_Pos ),	 /*!< ADC reference voltage is 1.024V */
    ADC_VREF_2_4V   = ( uint32_t ) ( 0x03 << ADC_CON_VREFS_Pos )	 /*!< ADC reference voltage is 2.4V   */
} ADC_VREF_TypeDef;

#define IS_ADC_VREF(VREF) (((VREF) == ADC_VREF_VDD)    || \
													 ((VREF) == ADC_VREF_2_048V) || \
													 ((VREF) == ADC_VREF_1_024V) || \
													 ((VREF) == ADC_VREF_2_4V))
/**
 * @}
 */

/** @brief ADC_IT ADC Interrupt
 * @{
 */
typedef enum
{
    ADC_IT_ADCIF = ( uint16_t ) ADC_CON_INTEN,	/*!< ADC Interrupt: ADC  Interrupt */
} ADC_IT_TypeDef;

#define IS_ADC_IT(IT) ((((IT) & (uint16_t)0xFEFF) == 0x00) && ((IT) != (uint16_t)0x0000))
/**
 * @}
 */

/** @brief ADC_FLAG ADC Flag
 * @{
 */
typedef enum
{
    ADC_Flag_ADCIF = ( uint8_t ) ADC_STS_EOC,	/*!< ADC Flag:ADC  Flag */
} ADC_FLAG_TypeDef;

#define IS_ADC_FLAG(FLAG) ((((FLAG) & (uint16_t)0xFFFE) == 0x00) && ((FLAG) != (uint16_t)0x0000))
#define IS_GET_ADC_FLAG(FLAG) ((FLAG) == ADC_STS_EOC)

/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/


#define IS_ADC_ALL_PERIPH(PERIPH) ((PERIPH) == ADC)

/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup ADC_Exported_Struct ADC Exported Struct
 * @{
 */

/** @brief ADC Time base Configuration Structure definition
 * @{
 */
typedef struct
{
    uint32_t ADC_Prescaler; /*!<  Specifies sampling time of ADC.
																  This parameter can be a value of @ref ADC_Prescaler_TypeDef */

    uint32_t ADC_EAIN; /*!< Specifies Input channel of ADC.
																	This parameter can be a value of @ref ADC_EAIN_Typedef */

    uint32_t ADC_VREF; /*!<  Specifies reference voltage of ADC.
																	This parameter can be a value of @ref ADC_VREF_TypeDef */

    uint16_t ADC_ConvMode; /*!< Specifies ADC work conversion mode.
																	This parameter can be a value of @ref ADC_ConvMode_TypeDef */
} ADC_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of struct -----------------------------------------------------*/

/** @addtogroup ADC_Exported_Functions ADC Exported Functions
 * @{
 */

/* ADC Base functions ********************************************************/
void ADC_DeInit ( ADC_TypeDef* ADCx );
void ADC_Init ( ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_Base_InitStruct );
void ADC_StructInit ( ADC_InitTypeDef* ADC_InitStruct );
void ADC_Cmd ( ADC_TypeDef *ADCx, FunctionalState NewState );
void ADC_ConvModeConfig ( ADC_TypeDef* ADCx, ADC_ConvMode_TypeDef ADC_ConvMode );
void ADC_SetChannel ( ADC_TypeDef* ADCx, ADC_ChannelTypedef ADC_Channel );
ADC_ChannelTypedef ADC_GetChannel ( ADC_TypeDef* ADCx );

/* ADC Conversion management functions ********************************************************/
uint16_t ADC_GetConversionValue ( ADC_TypeDef* ADCx );
void ADC_SoftwareStartConv ( ADC_TypeDef* ADCx );

/* Interrupts and flags  ***********************************************/
void ADC_ITConfig ( ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState );
FlagStatus ADC_GetFlagStatus ( ADC_TypeDef* ADCx, uint16_t ADC_FLAG );
void ADC_ClearFlag ( ADC_TypeDef* ADCx, uint16_t ADC_FLAG );
void ADC_DMACmd ( ADC_TypeDef *ADCx, FunctionalState NewState );

/**
 * @}
 */
/* End of exported functions --------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
