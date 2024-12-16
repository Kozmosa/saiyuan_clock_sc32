/**
 ******************************************************************************
 * @file    sc32f1xxx_cmp.h
 * @author  SOC AE Team
 * @version V1.5
 * @date     26-08-2024
 * @brief   Header file of CMP module.
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
#ifndef __sc32f1xxx_CMP_H
#define __sc32f1xxx_CMP_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"

/** @addtogroup sc32f1xxx_StdPeriph_Driver
 * @{
 */

/** @addtogroup CMP
 * @{
 */

/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup CMP_Enumerations CMP Enumerations
 * @{
 */

/** @brief CMP_Positive CMP Positive
 * @{
 */
#if defined(SC32f10xx)
typedef enum
{
    CMP_Positive_CMP0 = ( uint16_t ) ( 0x00U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP0 as the CMP input port    */
    CMP_Positive_CMP1 = ( uint16_t ) ( 0x01U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP1 as the CMP input port  */
    CMP_Positive_CMP2 = ( uint16_t ) ( 0x02U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP2 as the CMP input port   */
    CMP_Positive_CMP3 = ( uint16_t ) ( 0x03U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP3 as the CMP input port   */
    CMP_Positive_1_5V = ( uint16_t ) ( 0x01U << CMP_CFG_CMPP_Pos ), /*!< Select CMPP as the CMP input port,CMPP is 1.5V reference voltage     */
} CMP_Positive_TypeDef;

#define IS_CMP_Positive(POSITIVE) (((POSITIVE) == CMP_Positive_CMP0) || \
                                   ((POSITIVE) == CMP_Positive_CMP1) || \
                                   ((POSITIVE) == CMP_Positive_CMP2) || \
                                   ((POSITIVE) == CMP_Positive_CMP3) || \
                                   ((POSITIVE) == CMP_Positive_1_5V))
#elif defined(SC32f11xx)
typedef enum
{
    CMP_Positive_CMP0 = ( uint16_t ) ( 0x00U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP0 as the CMP input port    */
    CMP_Positive_CMP1 = ( uint16_t ) ( 0x01U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP1 as the CMP input port    */
    CMP_Positive_1_5V = ( uint16_t ) ( 0x01U << CMP_CFG_CMPP_Pos ), /*!< Select CMPP as the CMP input port,CMPP is 1.5V reference voltage     */
    CMP_Positive_PGA  = ( uint16_t ) ( 0x07U << CMP_CFG_CMPIS_Pos ), /*!< Select OP as the CMP input port       */
} CMP_Positive_TypeDef;

#define IS_CMP_Positive(POSITIVE) (((POSITIVE) == CMP_Positive_CMP0) || \
                                   ((POSITIVE) == CMP_Positive_CMP1) || \
                                   ((POSITIVE) == CMP_Positive_1_5V) || \
																	 ((POSITIVE) == CMP_Positive_PGA))

#elif defined(SC32f12xx)
typedef enum
{
    CMP_Positive_CMP0 = ( uint16_t ) ( 0x00U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP0 as the CMP input port    */
    CMP_Positive_CMP1 = ( uint16_t ) ( 0x01U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP1 as the CMP input port    */
    CMP_Positive_CMP2 = ( uint16_t ) ( 0x02U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP2 as the CMP input port    */
    CMP_Positive_CMP3 = ( uint16_t ) ( 0x03U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP3 as the CMP input port    */
    CMP_Positive_1_5V = ( uint16_t ) ( 0x01U << CMP_CFG_CMPP_Pos ), /*!< Select CMPP as the CMP input port,CMPP is 1.5V reference voltage     */
    CMP_Positive_OP  = ( uint16_t ) ( 0x07U << CMP_CFG_CMPIS_Pos ), /*!< Select OP as the CMP input port       */
} CMP_Positive_TypeDef;

#define IS_CMP_Positive(POSITIVE) (((POSITIVE) == CMP_Positive_CMP0) || \
                                   ((POSITIVE) == CMP_Positive_CMP1) || \
                                   ((POSITIVE) == CMP_Positive_CMP2) || \
                                   ((POSITIVE) == CMP_Positive_CMP3) || \
                                   ((POSITIVE) == CMP_Positive_1_5V) || \
																	 ((POSITIVE) == CMP_Positive_OP))
#endif

/**
 * @}
 */

/** @brief CMP_Negative CMP Negative
 * @{
 */
typedef enum
{
    CMP_Negative_CMPR    	= ( uint16_t ) ( 0x00U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is CMPR  */
    CMP_Negative_1D16VDD 	= ( uint16_t ) ( 0x01U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 1/16VDD   */
    CMP_Negative_2D16VDD 	= ( uint16_t ) ( 0x02U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 2/16VDD   */
    CMP_Negative_3D16VDD 	= ( uint16_t ) ( 0x03U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 3/16VDD   */
    CMP_Negative_4D16VDD 	= ( uint16_t ) ( 0x04U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 4/16VDD   */
    CMP_Negative_5D16VDD 	= ( uint16_t ) ( 0x05U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 5/16VDD   */
    CMP_Negative_6D16VDD 	= ( uint16_t ) ( 0x06U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 6/16VDD   */
    CMP_Negative_7D16VDD 	= ( uint16_t ) ( 0x07U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 7/16VDD   */
    CMP_Negative_8D16VDD 	= ( uint16_t ) ( 0x08U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 8/16VDD   */
    CMP_Negative_9D16VDD 	= ( uint16_t ) ( 0x09U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 9/16VDD   */
    CMP_Negative_10D16VDD = ( uint16_t ) ( 0x0AU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 10/16VDD   */
    CMP_Negative_11D16VDD = ( uint16_t ) ( 0x0BU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 11/16VDD   */
    CMP_Negative_12D16VDD = ( uint16_t ) ( 0x0CU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 12/16VDD   */
    CMP_Negative_13D16VDD = ( uint16_t ) ( 0x0DU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 13/16VDD   */
    CMP_Negative_14D16VDD = ( uint16_t ) ( 0x0EU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 14/16VDD   */
    CMP_Negative_15D16VDD = ( uint16_t ) ( 0x0FU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 15/16VDD   */
} CMP_Negative_TypeDef;

#define IS_CMP_Negative(NEGATIVE) (((NEGATIVE) == CMP_Negative_CMPR) || \
                                   ((NEGATIVE) == CMP_Negative_1D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_2D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_3D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_4D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_5D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_6D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_7D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_8D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_9D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_10D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_11D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_12D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_13D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_14D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_15D16VDD))

/**
 * @}
 */

/** @brief CMP_TriggerMode CMP TriggerMode
 * @{
 */
typedef enum
{
    CMP_TriggerMode_Disable   = ( uint16_t ) ( 0x00U << CMP_CFG_CMPIM_Pos ), /*!< The trigger mode is disable  */
    CMP_TriggerMode_RISE      = ( uint16_t ) ( 0x01U << CMP_CFG_CMPIM_Pos ), /*!< The trigger mode of simulated comparator is rising edge  */
    CMP_TriggerMode_FALL      = ( uint16_t ) ( 0x02U << CMP_CFG_CMPIM_Pos ), /*!< The trigger mode of simulated comparator is falling edge  */
    CMP_TriggerMode_RISE_FALL = ( uint16_t ) ( 0x03U << CMP_CFG_CMPIM_Pos ), /*!< The trigger mode of the simulated comparator is rising edge and falling edge  */
} CMP_TriggerMode_TypeDef;

#define IS_CMP_TRIGGER(TRIGGER) (((TRIGGER) == CMP_TriggerMode_Disable) || \
                                 ((TRIGGER) == CMP_TriggerMode_RISE) || \
                                 ((TRIGGER) == CMP_TriggerMode_FALL) || \
                                 ((TRIGGER) == CMP_TriggerMode_RISE_FALL))

/**
 * @}
 */

/** @brief CMP_CMPSTA CMP CMPSTA
 * @{
 */
typedef enum
{
    CMP_CMPSTA_Low		= ( uint32_t ) ( 0x00 << CMP_STS_CMPSTA_Pos ), /*!< CMP Flag: The non-inverting input is at a lower voltage than the inverting input */
    CMP_CMPSTA_High		= ( uint32_t ) ( 0x01 << CMP_STS_CMPSTA_Pos ), /*!< CMP Flag: The non-inverting input is at a higher voltage than the inverting input */
} CMP_CMPSTA_TypeDef;

#define IS_CMP_CMPSTA(STA) (((STA) == CMP_TriggerMode_Disable) || \
                           ((STA) == CMP_TriggerMode_RISE_FALL))
/**
 * @}
 */

/** @brief CMP_FLAG CMP Flag
 * @{
 */
typedef enum
{
    CMP_FLAG_IF		= ( uint32_t ) CMP_STS_CMPIF, /*!< CMP Flag: Interrupt flag */
} CMP_FLAG_TypeDef;

#define IS_CMP_FLAG(FLAG) ((FLAG) == CMP_FLAG_IF)
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/



#define IS_CMP_ALL_PERIPH(PERIPH) ((PERIPH) == CMP)

/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup CMP_Exported_Struct CMP Exported Struct
 * @{
 */

/** @brief CMP Time base Configuration Structure definition
 * @{
 */
typedef struct
{
    uint16_t CMP_Negative;   /*!< This member configures CMP NEGATIVE.
                                              This parameter can be a value of @ref CMP_Negative_TypeDef. */

    uint16_t CMP_Positive; /*!< This member configures CMP POSITIVE.
                                              This parameter can be a value of @ref CMP_Positive_TypeDef. */

    uint16_t CMP_TriggerMode; /*!< This member configures CMPTRIGGER.
                                              This parameter can be a value of @ref CMP_TriggerMode_TypeDef. */

} CMP_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup CMP_Functions CMP Functions
 * @{
 */
/* CMP Base functions ********************************************************/
void CMP_DeInit ( CMP_TypeDef* CMPx );
void CMP_Init ( CMP_TypeDef* CMPx, CMP_InitTypeDef* CMP_InitStruct );
void CMP_StructInit ( CMP_InitTypeDef* CMP_InitStruct );
void CMP_Cmd ( CMP_TypeDef* CMPx, FunctionalState NewState );
void CMP_SetNegativeChannel ( CMP_TypeDef* CMPx, CMP_Negative_TypeDef CMP_Negative_Channel );
CMP_Negative_TypeDef CMP_GetNegativeChannel ( CMP_TypeDef* CMPx );
void CMP_SetPositiveChannel ( CMP_TypeDef* CMPx, CMP_Positive_TypeDef CMP_Positive_Channel );
CMP_Positive_TypeDef CMP_GetPositiveChannel ( CMP_TypeDef* CMPx );
/* Interrupts and flags management functions  **********************************************/
CMP_CMPSTA_TypeDef CMP_GetCMPSTA ( CMP_TypeDef* CMPx );
FlagStatus CMP_GetFlagStatus ( CMP_TypeDef* CMPx, CMP_FLAG_TypeDef CMP_FLAG );
void CMP_ClearFlag ( CMP_TypeDef* CMPx, CMP_FLAG_TypeDef CMP_FLAG );

/**
 * @}
 */
/* End of functions --------------------------------------------------*/

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
