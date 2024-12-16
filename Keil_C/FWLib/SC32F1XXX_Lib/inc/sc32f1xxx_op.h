/**
 ******************************************************************************
 * @file    SC32f12xx_op.h
 * @author  SOC AE Team
 * @version V1.4A
 * @date    06-08-2024
 * @brief   Header file of OP module.
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f1xxx_OP_H
#define __sc32f1xxx_OP_H

#ifdef __cplusplus
extern "C"
{
#endif
#if defined(SC32f12xx)
/* Includes ------------------------------------------------------------------*/
#include "SC32f12xx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"



/** @addtogroup SC32f12xx_StdPeriph_Driver
 * @{
 */

/** @addtogroup OP
 * @{
 */

/** @defgroup OP_Enumerations OP Enumerations
 * @{
 */

typedef enum
{
    OP_Output_OFF	= ( uint16_t ) ( 0x00U << OP_CON_OPOSEL_Pos ), /*!< The OP Output  OFF*/
    OP_Output_ON	= ( uint16_t ) ( 0x01U << OP_CON_OPOSEL_Pos ), /*!< The OP Output  ON*/
} OP_Output_TypeDef;

#define IS_OP_Output(Output) (((Output) == OP_OPOUTPUT_OFF) || \
			   ((Output) == OP_OPOUTPUT_ON))


/** @defgroup OP_POSITIVE OP POSITIVE
 * @{
 */
typedef enum
{
    OP_Negative_OPN	= ( uint16_t ) ( 0x00U << OP_CON_OPNSEL_Pos ), /*!< The OP Negative terminal OPN*/
    OP_Negative_PGA   	= ( uint16_t ) ( 0x01U << OP_CON_OPNSEL_Pos ), /*!< The OP Negative terminal PGA   */
} OP_Negative_TypeDef;

#define IS_OP_Negative(Negative) (((Negative) == OP_Negative_OPN) || \
                               ((Negative) == OP_Negative_PGA))

/**
 * @}
 */

/** @defgroup OP_NEGATIVE OP NEGATIVE
 * @{
 */
typedef enum
{
    OP_Posittive_OPP0 = ( uint16_t ) ( 0x00U << OP_CON_OPPSEL_Pos ), /*!< The OP Positive terminal OPP0  */
    OP_Posittive_OPP1 = ( uint16_t ) ( 0x01U << OP_CON_OPPSEL_Pos ), /*!< The OP Positive terminal OPP1    */
    OP_Posittive_VSS = ( uint16_t ) ( 0x02U << OP_CON_OPPSEL_Pos ), /*!< The OP Positive terminal VSS  */
    OP_Posittive_1_2V = ( uint16_t ) ( 0x03U << OP_CON_OPPSEL_Pos ), /*!< The OP Positive terminal 1_2V*/
    OP_Posittive_VDD = ( uint16_t ) ( 0x04U << OP_CON_OPPSEL_Pos ), /*!< The OP Positive terminal VDD*/
} OP_Posittive_TypeDef;

#define IS_OP_Posittive(Posittive) (((Posittive) == OP_Posittive_OPP0) || \
                             ((Posittive) == OP_Posittive_OPP1) || \
                             ((Posittive) == OP_Posittive_VSS) || \
                             ((Posittive) == OP_Posittive_1_2V) || \
                             ((Posittive) == OP_Posittive_VDD) )

/**
 * @}
 */
typedef enum
{
    OP_PGAGain_NonInvert8_Invert7 = ( uint16_t ) ( 0x00U << OP_CON_PGAGAN_Pos ), /*!< The OP inverting input gain is 8/7 times  */
    OP_PGAGain_NonInvert16_Invert15 = ( uint16_t ) ( 0x01U << OP_CON_PGAGAN_Pos ), /*!< The OP inverting input gain is 16/15 times   */
    OP_PGAGain_NonInvert32_Invert31 =  ( uint16_t ) ( 0x02U << OP_CON_PGAGAN_Pos ), /*!< The OP in-phase input gain is 32/31 times  */
    OP_PGAGain_NonInvert64_Invert63 = ( uint16_t ) ( 0x03U << OP_CON_PGAGAN_Pos ), /*!< The OP in-phase input gain is 64/63 times  */

} OP_PGAGain_TypeDef;

#define IS_OP_PGAGain(PGAGain) (((PGAGain) == OP_PGAGain_NonInvert8_Invert7 ) || \
                             ((PGAGain) ==  OP_PGAGain_NonInvert16_Invert15) || \
                             ((PGAGain) == OP_PGAGain_NonInvert32_Invert31) || \
                             ((PGAGain) == OP_PGAGain_NonInvert64_Invert63)   )
/**
 * @}
 */
typedef enum
{
    OP_FDBResisrance_VSS = ( uint16_t ) ( 0x00U << OP_CON_FDBRSEL_Pos ), /*!< Feedback resistance terminal VSS  */
    OP_FDBResisrance_OPN = ( uint16_t ) ( 0x01U << OP_CON_FDBRSEL_Pos ), /*!< Feedback resistance terminal OPN  */
    OP_FDBResisrance_VDD =  ( uint16_t ) ( 0x02U << OP_CON_FDBRSEL_Pos ), /*!< Feedback resistance terminal VDD  */


} OP_FDBRESISTANCE_TypeDef;

#define IS_OP_FDBResisrance(FDBResisrance) (((FDBResisrance) == OP_FDBResisrance_VSS ) || \
                                     ((FDBResisrance) ==  OP_FDBResisrance_OPN) || \
                                     ((FDBResisrance) == OP_FDBResisrance_VDD)    )
/**
 * @}
 */
typedef enum
{
    OP_ShortCircuit_OFF = ( uint32_t ) ( 0x00U << OP_CON_PGAOFC_Pos ), /*!< The OP ShortCircuit OFF  */
    OP_ShortCircuit_ON = ( uint32_t ) ( 0x01U << OP_CON_PGAOFC_Pos ), /*!< The OP ShortCircuit ON   */
} OP_ShortCircuit_TypeDef;

#define IS_OP_ShortCircuit(ShortCircuit) (((ShortCircuit) == OP_ShortCircuit_OFF ) || \
                             ((ShortCircuit) ==  OP_ShortCircuit_ON)   )
/* End of enumerations -----------------------------------------------------*/

/** @defgroup TIM_Constants TIM Constants
  * @{
  */





/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup OP_Struct OP Struct
 * @{
 */

typedef struct
{

    uint32_t OP_ShortCircuit; /*!< This member configures OP.
                                              This parameter can be a value of @ref OP_SHORTCIRCUIT_TypeDef. */
    uint16_t OP_FDBResisrance;/*!< This member configures OP.
                                              This parameter can be a value of @ref OP_FDBRESISTANCE_TypeDef. */
    uint16_t OP_PGAGain;   /*!< This member configures OP.
                                              This parameter can be a value of @ref OP_PGAGAIN_TypeDef. */

    uint16_t OP_Posittive; /*!< This member configures OP.
                                              This parameter can be a value of @ref OP_OPPOSITTIVE_TypeDef. */
    uint16_t OP_Negative; /*!< This member configures OP.
                                              This parameter can be a value of @ref OP_OPNEGATIVE_TypeDef. */
    uint16_t OP_Output;  /*!< This member configures OP.
                                              This parameter can be a value of @ref OP_OPOUTPUT_TypeDef. */

} OP_InitTypeDef;

/**
 * @}
 */
#define IS_OP_ALL_PERIPH(PERIPH) ((PERIPH) == OP)
/**
 * @}
 */
/* End of Struct -----------------------------------------------------*/

/** @addtogroup OP_Functions OP Functions
 * @{
 */
#define IS_OP_ALL_PERIPH(PERIPH) ((PERIPH) == OP)
/* OP Base functions ********************************************************/
void OP_DeInit ( OP_TypeDef* OPx );
void OP_Init ( OP_TypeDef* PGAx, OP_InitTypeDef* OP_InitStruct );
void OP_Cmd ( OP_TypeDef* OPx, FunctionalState NewState );
//
///* Calibration functions ******************************************************/
void OP_OffsetTrimConfig ( OP_TypeDef* OPx,  uint32_t OP_TrimValueH, uint32_t OP_TrimValueL );
void OP_GainSelection ( OP_TypeDef* OPx, OP_PGAGain_TypeDef PGAGain );
void OP_OutputSelection ( OP_TypeDef* OPx, OP_Output_TypeDef OPOutput );
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

#endif
#ifdef __cplusplus
}
#endif

#endif
