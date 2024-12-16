/*
 ******************************************************************************
 * @file    sc32f1xxx_cmp.c
 * @author  SOC AE Team
 * @version V1.5
 * @date    26-08-2024
 * @brief  CMP function module
 *
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

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx_cmp.h"


/** @defgroup CMP_Group1 Configuration of the CMP computation unit functions
 *  @brief   Configuration of the CMP computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### CMP configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the CMPx peripheral registers to their default reset values.
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @retval None
 */
void CMP_DeInit ( CMP_TypeDef* CMPx )
{
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    if ( CMPx == CMP )
    {
        /* Enable CMP0 reset state */
        CMPx->CMP_CFG = 0x0000;
        CMPx->CMP_STS = 0xFFFF;
    }
}

/**
 * @brief  Initializes the peripheral CMP register according to the parameters specified in CMP_InitStruct
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @param  CMP_InitStruct[out]:pointer to a CMP_InitTypeDef structure which will be initialized.
 * @retval None
 */
void CMP_Init ( CMP_TypeDef* CMPx, CMP_InitTypeDef* CMP_InitStruct )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_CMP_Negative ( CMP_InitStruct->CMP_Negative ) );
    assert_param ( IS_CMP_Positive ( CMP_InitStruct->CMP_Positive ) );
    assert_param ( IS_CMP_TRIGGER ( CMP_InitStruct->CMP_TriggerMode ) );

    /*---------------------------- CMPx CMP_CFG Configuration ------------------------*/
    /* Get the CMPx CMP_CFG value */
    tmpreg = CMPx->CMP_CFG;
    /* Clear CMPFS bits */
    tmpreg &= ( uint32_t ) ~ ( CMP_CFG_CMPIS | CMP_CFG_CMPP | CMP_CFG_CMPIM |
                               CMP_CFG_CMPRF ) ;

    /* Set CMPRF bits according to CMP_NEGATIVE value */
    /* Set CMPIS bits and CMPIP bit according to CMP_POSITIVE value */
    /* Set CMPIM bits according to CMP_TriggerMode value */
    tmpreg |= ( uint32_t ) ( CMP_InitStruct->CMP_Negative | CMP_InitStruct->CMP_Positive |
                             CMP_InitStruct->CMP_TriggerMode );
    /* Write to CMPx CMP_CFG */
    CMPx->CMP_CFG = tmpreg;
}

/**
  * @brief  Fills each CMP_CMPInitStruct member with its default value.
  * @param  CMP_InitStruct[out]:pointer to a CMP_InitTypeDef structure which will be initialized.
  * @retval None
  */
void CMP_StructInit ( CMP_InitTypeDef* CMP_InitStruct )
{
    /* Set the default configuration */
    CMP_InitStruct->CMP_Negative = CMP_Negative_CMPR;
    CMP_InitStruct->CMP_Positive = CMP_Positive_CMP0;
    CMP_InitStruct->CMP_TriggerMode = CMP_TriggerMode_Disable;
}

/**
 * @brief  Enables or disables the specified CMP.
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @param  NewState[in]: new state of the CMPx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void CMP_Cmd ( CMP_TypeDef* CMPx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the CMP Function */
        CMPx->CMP_CFG |= CMP_CFG_CMPEN;
    }
    else
    {
        /* Disable the CMP Function */
        CMPx->CMP_CFG &= ( uint16_t ) ~CMP_CFG_CMPEN;
    }
}
/**
 * @brief  Configure the CMP negative input channel
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @param  CMP_Negative_Channel[in]:
 *                  - CMP_Negative_CMPR:The comparison voltage of CMP is CMPR
 *                  - CMP_Negative_1D16VDD:The comparison voltage of CMP is 1/16VDD
 *                  - CMP_Negative_2D16VDD:The comparison voltage of CMP is 2/16VDD
 *                  - CMP_Negative_3D16VDD:The comparison voltage of CMP is 3/16VDD
 *                  - CMP_Negative_4D16VDD:The comparison voltage of CMP is 4/16VDD
 *                  - CMP_Negative_5D16VDD:The comparison voltage of CMP is 5/16VDD
 *                  - CMP_Negative_6D16VDD:The comparison voltage of CMP is 6/16VDD
 *                  - CMP_Negative_7D16VDD:The comparison voltage of CMP is 7/16VDD
 *                  - CMP_Negative_8D16VDD:The comparison voltage of CMP is 8/16VDD
 *                  - CMP_Negative_9D16VDD: The comparison voltage of CMP is 9/16VDD
 *                  - CMP_Negative_10D16VDD:The comparison voltage of CMP is 10/16VDD
 *                  - CMP_Negative_11D16VDD:The comparison voltage of CMP is 11/16VDD
 *                  - CMP_Negative_12D16VDD:The comparison voltage of CMP is 12/16VDD
 *                  - CMP_Negative_13D16VDD:The comparison voltage of CMP is 13/16VDD
 *                  - CMP_Negative_14D16VDD:The comparison voltage of CMP is 14/16VDD
 *                  - CMP_Negative_15D16VDD:The comparison voltage of CMP is 15/16VDD
 * @retval None
 */
void CMP_SetNegativeChannel ( CMP_TypeDef* CMPx, CMP_Negative_TypeDef CMP_Negative_Channel )
{
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_CMP_Negative ( CMP_Negative_Channel ) );

    CMPx->CMP_CFG &= ( uint32_t ) ~CMP_CFG_CMPRF;
    CMPx->CMP_CFG |= ( uint32_t ) CMP_Negative_Channel;
}

/**
 * @brief  Get the CMP negative input channel
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @retval  CMP_Negative_Channel[in]: CMP negative input channel type.
 *                  - CMP_Negative_CMPR:The comparison voltage of CMP is CMPR
 *                  - CMP_Negative_1D16VDD:The comparison voltage of CMP is 1/16VDD
 *                  - CMP_Negative_2D16VDD:The comparison voltage of CMP is 2/16VDD
 *                  - CMP_Negative_3D16VDD:The comparison voltage of CMP is 3/16VDD
 *                  - CMP_Negative_4D16VDD:The comparison voltage of CMP is 4/16VDD
 *                  - CMP_Negative_5D16VDD:The comparison voltage of CMP is 5/16VDD
 *                  - CMP_Negative_6D16VDD:The comparison voltage of CMP is 6/16VDD
 *                  - CMP_Negative_7D16VDD:The comparison voltage of CMP is 7/16VDD
 *                  - CMP_Negative_8D16VDD:The comparison voltage of CMP is 8/16VDD
 *                  - CMP_Negative_9D16VDD: The comparison voltage of CMP is 9/16VDD
 *                  - CMP_Negative_10D16VDD:The comparison voltage of CMP is 10/16VDD
 *                  - CMP_Negative_11D16VDD:The comparison voltage of CMP is 11/16VDD
 *                  - CMP_Negative_12D16VDD:The comparison voltage of CMP is 12/16VDD
 *                  - CMP_Negative_13D16VDD:The comparison voltage of CMP is 13/16VDD
 *                  - CMP_Negative_14D16VDD:The comparison voltage of CMP is 14/16VDD
 *                  - CMP_Negative_15D16VDD:The comparison voltage of CMP is 15/16VDD
 */
CMP_Negative_TypeDef CMP_GetNegativeChannel ( CMP_TypeDef* CMPx )
{
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    /* Get the CMP negative input channel type */
    return ( CMP_Negative_TypeDef ) ( CMPx->CMP_CFG & CMP_CFG_CMPRF );
}

/**
 * @brief  Configure the CMP positive input channel
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @param  CMP_Positive_Channel[in]: CMP positive input channel selection.
 *                  SC32f10xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP3,CMP_Positive_1_5V)
 *                  SC32f11xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP1,CMP_Positive_1_5V,CMP_Positive_PGA)
 *                  SC32f12xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP3,CMP_Positive_1_5V,CMP_Positive_OP)
 *                  - CMP_Positive_CMP0:Select CMP0 as the CMP input port
 *                  - CMP_Positive_CMP1:Select CMP1 as the CMP input port
 *                  - CMP_Positive_CMP2:Select CMP2 as the CMP input port
 *                  - CMP_Positive_CMP3:Select CMP3 as the CMP input port
 *                  - CMP_Positive_1_5V:Select CMPP as the CMP input port,CMPP is 1.5V reference voltage
 *                  - CMP_Positive_PGA:Select PGA as the CMP input port
 *                  - CMP_Positive_OP:Select OP as the CMP input port
 * @retval None
 */
void CMP_SetPositiveChannel ( CMP_TypeDef* CMPx, CMP_Positive_TypeDef CMP_Positive_Channel )
{
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_CMP_Positive ( CMP_Positive_Channel ) );

    CMPx->CMP_CFG &= ( uint32_t ) ~ ( CMP_CFG_CMPIS | CMP_CFG_CMPP );
    CMPx->CMP_CFG |= ( uint32_t ) CMP_Positive_Channel;
}

/**
 * @brief  Get the CMP positive input channel
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @param CMP_Positive_Channel[in]: CMP positive input channel type.
 *                  SC32f10xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP3,CMP_Positive_1_5V)
 *                  SC32f11xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP1,CMP_Positive_1_5V,CMP_Positive_PGA)
 *                  SC32f12xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP3,CMP_Positive_1_5V,CMP_Positive_OP)
 *                  - CMP_Positive_CMP0:Select CMP0 as the CMP input port
 *                  - CMP_Positive_CMP1:Select CMP1 as the CMP input port
 *                  - CMP_Positive_CMP2:Select CMP2 as the CMP input port
 *                  - CMP_Positive_CMP3:Select CMP3 as the CMP input port
 *                  - CMP_Positive_1_5V:Select CMPP as the CMP input port,CMPP is 1.5V reference voltage
 *                  - CMP_Positive_PGA:Select PGA as the CMP input port
 *                  - CMP_Positive_OP:Select OP as the CMP input port
 */
CMP_Positive_TypeDef CMP_GetPositiveChannel ( CMP_TypeDef* CMPx )
{
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    /* Get the CMP positive input channel type */
    return ( CMP_Positive_TypeDef ) ( CMPx->CMP_CFG & ( CMP_CFG_CMPIS | CMP_CFG_CMPP ) );
}

/** @defgroup CMP_Group2 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Return the cmp state (high or low) of the selected comparator.
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @retval The new state of CMP(CMP_CMPSTA_Low or CMP_CMPSTA_High).
 *                  - CMP_CMPSTA_Low:The non-inverting input is at a lower voltage than the inverting input
 *                  - CMP_CMPSTA_High: The non-inverting input is at a higher voltage than the inverting input
 */
CMP_CMPSTA_TypeDef CMP_GetCMPSTA ( CMP_TypeDef* CMPx )
{
    CMP_CMPSTA_TypeDef CMP_CMPSTA = CMP_CMPSTA_Low;
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    if ( ( CMPx->CMP_STS & CMP_STS_CMPSTA ) != 0 )
    {
        CMP_CMPSTA = CMP_CMPSTA_High;
    }
    else
    {
        CMP_CMPSTA = CMP_CMPSTA_Low;
    }

    return CMP_CMPSTA;
}

/**
 * @brief  Checks whether the specified CMP flag is set or not.
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @param  CMP_FLAG[in]:specifies the flag to check.
 *                  - CMP_FLAG_IF: Interrupt flag
 * @retval The new state of CMP_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up.
 */
FlagStatus CMP_GetFlagStatus ( CMP_TypeDef* CMPx, CMP_FLAG_TypeDef CMP_FLAG )
{
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_CMP_FLAG ( CMP_FLAG ) );

    if ( ( CMPx->CMP_STS & CMP_FLAG ) != ( uint16_t ) RESET )
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
 * @brief  Clears the CMPx's pending flags.
 * @param  CMPx[out]:
 *                  - CMP: Only CMP can be select the CMPx peripheral.
 * @param  CMP_FLAG[in]: specifies the flag bit to clear.
 *                  -  CMP_FLAG_IF:CMP Flag: Interrupt flag
 * @retval None
 */
void CMP_ClearFlag ( CMP_TypeDef* CMPx, CMP_FLAG_TypeDef CMP_FLAG )
{
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    /* Clear the flags */
    CMPx->CMP_STS = ( uint16_t ) CMP_FLAG;
}

/**
 * @}
 */
/* End of CMP_Group2.	*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/

