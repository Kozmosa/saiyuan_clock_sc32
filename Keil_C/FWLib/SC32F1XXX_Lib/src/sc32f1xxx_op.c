/*
 ******************************************************************************
 * @file    SC32f1xxx_OP.c
 * @author  SOC AE Team
 * @version V1.5
 * @date     26-08-2024
 * @brief OP function module
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
#if defined (SC32f12xx)
#include "sc32f1xxx_op.h"



/** @defgroup OP_Exported_Functions_Group1 Configuration of the OP computation unit functions
 *  @brief   Configuration of the OP computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### OP configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the OP peripheral registers to their default reset values.
 * @param  OPx[out]:
 *                  - OP:Only OP can be select the OPx peripheral.
 * @retval None
 */
void OP_DeInit ( OP_TypeDef* OPx )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );

    if ( OPx == OP )
    {
        /* Get the OPx OP_CON value */
        tmpreg = OPx->OP_CON;

        /* Set OPFS bit to OP_FreqSelect value */
        tmpreg &= 0x00000000;

        /* Write to OPx OP_CON */
        OPx->OP_CON = ( uint32_t ) tmpreg;
    }
}


/**
 * @brief  DeInitializes the OP peripheral
 * @param  OPx[out]:
 *                  - OP:Only OP can be select the OPx peripheral.
 * @param  OP_InitStruct[out]:Pointer to structure OP_InitTypeDef, to be initialized.
 * @retval None
 */
void OP_Init ( OP_TypeDef* OPx, OP_InitTypeDef* OP_InitStruct )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );
    assert_param ( IS_OP_Output ( Output ) );
    assert_param ( IS_OP_Negative ( Negative ) );
    assert_param ( IS_OP_Posittive ( Posittive ) );
    assert_param ( IS_OP_PGAGain ( PGAGain ) );
    assert_param ( IS_OP_FDBResisrance ( FDBResisrance ) );
    assert_param ( IS_OP_ShortCircuit ( ShortCircuit ) );

    /*---------------------------- OPx OP_CON Configuration ------------------------*/
    /* Get the OPx OP_CON value */
    tmpreg = OPx->OP_CON;

    /* Clear OPFS bits */
    tmpreg &= ( uint32_t ) ~ ( OP_CON_OPOSEL | OP_CON_OPNSEL | OP_CON_OPPSEL
                               | OP_CON_PGAGAN | OP_CON_FDBRSEL | OP_CON_PGAOFC );
    /* Set OPFS bit to OP_FreqSelect value */
    tmpreg |= ( uint32_t ) ( OP_InitStruct->OP_FDBResisrance | OP_InitStruct->OP_Negative | OP_InitStruct->OP_Output |
                             OP_InitStruct->OP_PGAGain | OP_InitStruct->OP_Posittive | OP_InitStruct->OP_ShortCircuit );

    /* Write to OPx OP_CON */
    OPx->OP_CON = tmpreg;
}

/**
 * @brief  Enables or disables the specified OP peripheral.
 * @param  OPx[out]:
 *                  - OP:Only OP can be select the OPx peripheral.
 * @param  NewState[in]: new state of the OPx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void OP_Cmd ( OP_TypeDef* OPx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the OP Function */
        OPx->OP_CON |= OP_CON_ENOP;
    }
    else
    {
        /* Disable the OP Function */
        OPx->OP_CON &= ( uint16_t ) ~OP_CON_ENOP;
    }
}

/**
  * @brief  Configure the trimming value of the OPAMP.
  * @param  OPx[out]:
  *                  - OP:Only OP can be select the OPx peripheral.
  * @param  OP_TrimValueH[in]: the trimming value(high).
  * @param  OP_TrimValueL[in]: the trimming value(low).
  * @retval None
  */
void OP_OffsetTrimConfig ( OP_TypeDef* OPx,  uint32_t OP_TrimValueH, uint32_t OP_TrimValueL )
{
    uint32_t tmpreg = 0;

    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );


    /*!< Get the OPAMPx_CSR register value */
    tmpreg = OPx->OP_CON;

    /*!< Clear the trimming bits */
    tmpreg &= ( uint32_t ) ~ ( ( OP_CON_TRIMOFFSETNL | OP_CON_TRIMOFFSETNH ) );

    /*!< Configure the new trimming value */
    tmpreg |= ( uint32_t ) ( ( OP_TrimValueL << OP_CON_TRIMOFFSETNL_Pos ) | ( OP_TrimValueH << OP_CON_TRIMOFFSETNH_Pos ) );

    /*!< Write to OPAMPx_CSR register */
    OPx->OP_CON = tmpreg;
}

/**
  * @brief  OP gain selection.
  * @param  OPx[out]:
  *                  - OP:Only OP can be select the OPx peripheral.
  * @param  OPGain[in]: Gain multiple.
  *                  - OP_PGAGain_NonInvert8_Invert7:The OP inverting input gain is 8/7 times
  *                  - OP_PGAGain_NonInvert16_Invert15:The OP inverting input gain is 16/15 times
  *                  - OP_PGAGain_NonInvert32_Invert31:The OP in-phase input gain is 32/31 times
  *                  - OP_PGAGain_NonInvert64_Invert63:The OP in-phase input gain is 64/63 times
  * @retval None
  */
void OP_GainSelection ( OP_TypeDef* OPx, OP_PGAGain_TypeDef PGAGain )
{
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );
    assert_param ( IS_OP_PGAGain ( PGAGAN ) );


    OPx->OP_CON &= ~ ( OP_CON_PGAGAN );
    OPx->OP_CON |= PGAGain;

}

/**
 * @}
 */
/**
  * @brief  OP Output port selection.
  * @param  OPx[out]:
  *                  - OP:Only OP can be select the OPx peripheral.
  * @param  OPOutput[in]: Output port selection.
  *                  - OP_Output_OFF:The OP Output  OFF
  *                  - OP_Output_ON:The OP Output  ON
  * @retval None
  */
void OP_OutputSelection ( OP_TypeDef* OPx, OP_Output_TypeDef OPOutput )
{
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );
    assert_param ( IS_OP_Output ( OPOutput ) );


    OPx->OP_CON &= ~ ( OP_CON_OPOSEL );
    OPx->OP_CON |= OPOutput;

}
#endif
/**
 * @}
 */
/**
 * @}
 */

/**
 * @}
 */

///************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
