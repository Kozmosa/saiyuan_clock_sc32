/**
 ******************************************************************************
 * @file    sc32f1xxx_can.h
 * @author  SOC AE Team
 * @version V1.4
 * @date     25-04-2024
 * @brief   Header file of CAN module.
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
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f1xxx_can_H
#define __sc32f1xxx_can_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"
/** @defgroup CAN_Enumerations CAN Enumerations
 * @{
 */
#define BaudRate_800k 800000
#define BaudRate_500k 500000
#define Sampling_pos_75 0.75
#define Sampling_pos_80 0.8
#define Sampling_pos_875 0.875
typedef enum
{
	CAN_Standard_format = (uint8_t)(0x00<<CAN_TX_CTRL_IDE_Pos),/*!<Packets are sent in standard mode*/
	CAN_Extended_format = (uint8_t)(0x01<<CAN_TX_CTRL_IDE_Pos),/*!<Packets are in extended mode*/
} CAN_IDEMODE_Typedef;

#define IS_CAN_IDEMODE(IDEMODE) (((IDEMODE) == CAN_Tx_Standard_format) || \
                               ((IDEMODE) == CAN_Tx_Extended_format)   )
/** @brief CAN RTR mode enumeration
  * @{
  */

typedef enum
{
	CAN_Data_frame =   (uint8_t)(0x0L << CAN_TX_CTRL_RTR_Pos),	/*!<The message uses a data frame*/
	CAN_Remote_frame = (uint8_t)(0x1L << CAN_TX_CTRL_RTR_Pos),/*!<The packet uses a remote frame*/
}CAN_RTRMODE_Typedef;	
#define IS_CAN_RTRMODE(RTRMODE) (((RTRMODE) == CAN_Tx_Data_frame ) || \
                               ((RTRMODE) == CAN_Tx_Remote_frame))
/** @brief CAN send frame mode
  * @{
  */
typedef enum
{
	
	CAN_Standard_frame = (uint8_t)(0x00 <<CAN_TX_CTRL_FDF_Pos ),/*!<The packet uses 2.0 frames*/
	CAN_FD_frame = (uint8_t)(0x01<<CAN_TX_CTRL_FDF_Pos),/*!<The message uses an FD frame*/

}CAN_FDFMODE_Typedef;
#define IS_CAN_FDFMODE(FDFMODE) (((FDFMODE) == CAN_TX_Standard_frame  ) || \
                               ((FDFMODE) ==CAN_TX_FD_frame))
/** @brief  CAN BRSMODE
  * @{
  */
typedef enum
{
	CAN_Disable_BRS = (uint8_t)(0x00 <<CAN_TX_CTRL_BRS_Pos),/*!<Packet bit rate switching is disabled. Procedure*/
	CAN_Enable_BRS = (uint8_t)(0x01 <<CAN_TX_CTRL_BRS_Pos),/*!<The packet allows switching of the bit rate*/
	
}CAN_BRSMODE_Typedef;
#define IS_CAN_BRSMODE(BRSMODE) (((BRSMODE) == CAN_Tx_Disable_BRS) || \
                               ((BRSMODE)== CAN_Tx_Enable_BRS))
/** @brief  PTB automatic retransmission mode selected
  * @{
  */
typedef enum
{
	
	TPSS_Enable = (uint8_t)(0x00 <<CAN_CFG_STAT_TPSS_Pos),/*!<Enable automatic PTB retransmission*/
	TPSS_Disable = (uint8_t)(0x01 <<CAN_CFG_STAT_TPSS_Pos),/*!<Disable automatic PTB retransmission*/
}CAN_PTB_AutoRetrans_TypeDef;
#define IS_CAN_PTB_AutoRetrans(PTB_AutoRetrans) (((PTB_AutoRetrans) == TPSS_Enable) || \
                                             ((PTB_AutoRetrans)== TPSS_Disable))
/** @brief  STB automatic retransmission mode selection
  * @{
  */
typedef enum
{
	
	TSSS_Enable = (uint8_t)(0x00 << CAN_CFG_STAT_TSSS_Pos),/*!<Enable automatic STB retransmission*/	
	TSSS_Disable = (uint8_t)(0x01 << CAN_CFG_STAT_TSSS_Pos),/*!<Disable STB automatic retransmission*/
}CAN_STB_AutoRetrans_TypeDef;
#define IS_CAN_STB_AutoRetrans(STB_AutoRetrans) (((STB_AutoRetrans) == TSSS_Enable) || \
                                             ((STB_AutoRetrans)== TSSS_Disable))
/** @brief  CAN send buffer selection
  * @{
  */
typedef enum
{
	CANTBUF_Tx_PTB = (uint32_t)(0x00 << CAN_CFG_STAT_TBSEL_Pos),	/*!<Send buffer Select PTB*/
	CANTBUF_Tx_STB = (uint32_t)(0x01 << CAN_CFG_STAT_TBSEL_Pos),/*!<Send buffer select STB*/
}CANTBUF_TypeDef;
#define IS_CANTBUF(CANTBUF) (((CANTBUF) == CANTBUF_Tx_PTB) || \
                             ((CANTBUF)== CANTBUF_Tx_STB))
/** @brief  CAN TX Enable select
  * @{
  */
typedef enum
{
	
	TX_Disable =(uint16_t)(0x00 << CAN_IDE_TXEN_Pos),/*!<The CAN sending function is disabled*/
	TX_Enable =(uint16_t)(0x01 << CAN_IDE_TXEN_Pos),/*!<The CAN sending function was enabled*/
}CANTXEN_TypeDef;
#define IS_CANTXEN(CANTXEN) (((CANTXEN) == TX_Disable) || \
                              ((CANTXEN)== TX_Enable))
/** @brief  CAN RX Enable select
  * @{
  */
typedef enum
{	
	RX_Disable = (uint16_t)(0x00 << CAN_IDE_RXEN_Pos),/*!<The CAN receiving function is disabled*/
	RX_Enable =  (uint16_t)(0x01 << CAN_IDE_RXEN_Pos),	/*!<The CAN receiving function was enabled*/
}CANRXEN_TypeDef;
#define IS_CANRXEN(CANRXEN) (((CANRXEN) == RX_Disable) || \
                              ((CANRXEN)== RX_Enable))
/** @brief CAN receive overflow Discard old and new packets Select
  * @{
  */
typedef enum
{
	CANROM_Old = (uint32_t)(0x00 << CAN_CFG_STAT_ROM_Pos),/*!<The oldest packet was discarded. Procedure*/
	CANROM_New = (uint32_t)(0x01 << CAN_CFG_STAT_ROM_Pos),/*!<Discard the latest packet*/
}CANROM_TypeDef;
#define IS_CANROM(CANROM) (((CANROM) == CANROM_Old) || \
                           ((CANROM)== CANROM_New))
/** @brief CAN filter enumeration
  * @{
  */
typedef enum
{
	Fliter0 = 0x00,/*!<Select Fliter0*/
	Fliter1 = 0x01,/*!<Select Fliter1*/
	Fliter2 = 0x02,/*!<Select Fliter2*/
	Fliter3 = 0x03,/*!<Select Fliter3*/
	Fliter4 = 0x04,/*!<Select Fliter4*/
	Fliter5 = 0x05,/*!<Select Fliter5*/
	Fliter6 = 0x06,/*!<Select Fliter6*/
	Fliter7 = 0x07,/*!<Select Fliter7*/
}FliterNumber;
#define IS_FliterNumber(FliterNumber) (((FliterNumber) == Fliter0) || \
                                       ((FliterNumber)== Fliter1)  || \
                                       ((FliterNumber)== Fliter2)  || \
                                       ((FliterNumber)== Fliter3)  || \
                                       ((FliterNumber)== Fliter4)  || \
                                       ((FliterNumber)== Fliter5)  || \
                                       ((FliterNumber)== Fliter6)  || \
                                       ((FliterNumber)== Fliter7))
/** @brief The CAN filter selects standard frames from extended frames
  * @{
  */                                   
typedef enum
{
	Fliter_Standard = (uint8_t)(0x00<<CAN_ACFCTRL_ACFADR_Pos),/*!<Only standard frames pass through the filter*/	
	Fliter_Extension = (uint8_t)(0x01<<CAN_ACFCTRL_ACFADR_Pos),/*!<Let only the extension frames pass through the filter*/
	Fliter_Default = (uint8_t)(0x02<<CAN_ACFCTRL_ACFADR_Pos),/*No limit*/
}FliterFrame_TypeDef;
#define IS_FliterFrame(FliterFrame) (((FliterFrame) == Fliter_Standard) || \
                                       ((FliterFrame)== Fliter_Extension)|| \
                                        ((FliterFrame)== Fliter_Default) )
/** @brief CAN disables the mask switch
  * @{
  */
typedef enum
{
	
	CANInt_off =  (uint8_t)(0x00<<CAN_IDE_INTEN_Pos),/*!<Interrupt mask*/
	CANInt_on = (uint8_t)(0x01<<CAN_IDE_INTEN_Pos),	/*!<Interrupt on*/
}CANInt_TypeDef;
#define IS_CANInt(CANInt) (((CANInt) == CANInt_off) || \
                           ((CANInt)== CANInt_on) )
/** @brief CAN send packet mode Select
  * @{
  */
typedef enum
{
	
	TX_FIFO = (uint8_t)(0x00<<CAN_CFG_STAT_TSMODE_Pos),/*!<FIFO mode*/
	ID_priority = (uint8_t)(0x01<<CAN_CFG_STAT_TSMODE_Pos),/*!<ID priority mode*/
}CANTSMODE_TypeDef;
#define IS_CANTSMODE(CANTSMODE) (((CANTSMODE) == TX_FIFO) || \
                                ((CANTSMODE)== ID_priority) )
/** @brief CAN disables the mask switch
  * @{
  */

/*CAN中断枚举*/
typedef enum
{
	
	RIEEN = (uint16_t)(0x01<<CAN_RTIE_RIE_Pos), /*!<The receiving interrupt function was enabled*/
	ROIEEN = (uint16_t)(0x01<<CAN_RTIE_ROIE_Pos) , /*!<Overflow interrupt was enabled. Procedure*/
	RFIEEN = (uint16_t)(0x01<<CAN_RTIE_RFIE_Pos), /*!<RB full interrupt was enabled. Procedure*/
	RAFIEEN = (uint16_t)(0x01<<CAN_RTIE_RAFIE_Pos ), /*!<RB slots Threshold warning Indicates the interrupt function*/
	TPIEEN =(uint16_t)(0x01<<CAN_RTIE_TPIE_Pos ) , /*!<The interruption of PTB transmission completion was enabled*/
	TSIEEN = (uint16_t)(0x01<<CAN_RTIE_TSIE_Pos ), /*!<The STB transmission completion interrupt was enabled*/
	EIEEN = (uint16_t)(0x01<<CAN_RTIE_EIE_Pos ), /*!<The error interrupt function was enabled*/
	ALIEEN = (uint16_t)(0x01<<CAN_RTIE_ALIE_Pos ), /*!<The arbitration loss interruption function was enabled*/
	BEIEEN = (uint32_t)(0x01<<CAN_RTIE_BEIE_Pos ) , /*!<Bus error interrupt enabled*/
	EPIEEN = (uint32_t)(0x01<<CAN_RTIE_EPIE_Pos), /*!<Error passive interrupt enable bit*/
}CAN_INT_TypeDef;
#define IS_CAN_INT(CAN_INT) (((CAN_INT) == RIEEN)  ||\
                             ((CAN_INT)== ROIEEN)  ||\
                             ((CAN_INT)== RFIEEN)  ||\
                             ((CAN_INT)== RAFIEEN) ||\
													   ((CAN_INT)== TPIEEN)  ||\
														 ((CAN_INT)== TSIEEN)  ||\
														 ((CAN_INT)== EIEEN)   ||\
														 ((CAN_INT)== ALIEEN)  ||\
													   ((CAN_INT)== BEIEEN)  ||\
														 ((CAN_INT)== EPIEEN) )
/** @brief CAN disables the mask switch
  * @{
  */

/*CAN中断枚举*/
typedef enum
{ 
	RIF_FlAG = (uint32_t)(0x01<<CAN_RTIE_RIF_Pos),  /*!<Select the RIF FLAG*/
	TSFF_FLAG = (uint16_t)(0x01<<CAN_RTIE_TSFF_Pos), /*!<Select the TSFF FLAG*/
	AIF_FLAG = (uint16_t)(0x01<<CAN_RTIE_AIF_Pos), /*!<Select the AIF FLAG*/
	EIF_FLAG = (uint16_t)(0x01<<CAN_RTIE_EIF_Pos) ,	/*!<Select the EIF FLAG*/
	TSIF_FLAG = (uint16_t)(0x01<<CAN_RTIE_TSIF_Pos),/*!<Select the TSIF FLAG*/
	TPIF_FLAG = (uint16_t)(0x01<<CAN_RTIE_TPIF_Pos ),/*!<Select the TPIF FLAG*/
	RAFIF_FLAG =(uint16_t)(0x01<<CAN_RTIE_RAFIF_Pos ) ,/*!<Select the RAFIF FLAG*/
	RFIF_FLAG = (uint16_t)(0x01<<CAN_RTIE_RFIF_Pos ),/*!<Select the RFIF FLAG*/
	ROIF_FLAG = (uint16_t)(0x01<<CAN_RTIE_ROIF_Pos ),/*!<Select the ROIF FLAG*/
	ALIF_FLAG = (uint16_t)(0x01<<CAN_RTIE_ALIF_Pos ),/*!<Select the ALIF FLAG*/
	BEIF_FLAG = (uint32_t)(0x01<<CAN_RTIE_BEIF_Pos ) ,/*!<Select the BEIF FLAG*/
	EPIF_FLAG = (uint32_t)(0x01<<CAN_RTIE_EPIF_Pos),/*!<Select the EPIF FLAG*/
}CAN_FLAG_TypeDef;
#define IS_CAN_FLAG(CAN_FLAG) (((CAN_FLAG) == TSFF_FLAG)  ||\
                              ((CAN_FLAG)== AIF_FLAG)  ||\
                              ((CAN_FLAG)== EIF_FLAG)  ||\
                              ((CAN_FLAG)== TSIF_FLAG) ||\
													    ((CAN_FLAG)== TSIF_FLAG)  ||\
														  ((CAN_FLAG)== TPIF_FLAG)  ||\
														  ((CAN_FLAG)== RAFIF_FLAG)   ||\
														  ((CAN_FLAG)== RFIF_FLAG)  ||\
													    ((CAN_FLAG)== ROIF_FLAG)  ||\
														  ((CAN_FLAG)== ALIF_FLAG)  ||\
                              ((CAN_FLAG)== EPIF_FLAG)      )
/** @brief CAN Timestamp Enable Select
  * @{
  */
typedef enum
{
	
	TimeStampDisable = (uint8_t)(0x00<<CAN_ACFCTRL_TIMEEN_Pos),/*!<The timestamp is disabled*/
  TimeStampEnable = (uint8_t)(0x01<<CAN_ACFCTRL_TIMEEN_Pos),/*!<The timestamp was enabled*/
}CANTimeStamp_TypeDef;
#define IS_CANTimeStamp(CANTimeStamp) (((CANTimeStamp) == TimeStampDisable) || \
                                ((CANTimeStamp)== TimeStampEnable) )
/** @brief CAN Indicates whether to enable timestamp counting
  * @{
  */ 
typedef enum
{

	TimeStampCntDisable = (uint16_t)(0x00<<CAN_IDE_TIMEN_Pos),	/*!<Disable the timestamp counting function*/
  TimeStampCntEnable = (uint16_t)(0x00<<CAN_IDE_TIMEN_Pos),/*!<Enable the timestamp counting function*/
}CANTimeStampCnt_TypeDef;
#define IS_CANTimeStampCnt(CANTimeStampCnt) (((CANTimeStampCnt) == TimeStampCntDisable) || \
                                ((CANTimeStampCnt)== TimeStampCntEnable) )
/** @brief CAN timestamp location selection
  * @{
  */
typedef enum
{
	
	CANTimeStampPosition_SOF = (uint16_t)(0x00<<CAN_ACFCTRL_TIMEPOS_Pos),/*!<Select the frame start as the timestamp location*/
  CANTimeStampPosition_EOF = (uint16_t)(0x00<<CAN_ACFCTRL_TIMEPOS_Pos),	/*!<Select the end of frame as the timestamp location*/
}CANTimeStampPosition_TypeDef;
#define IS_CANTimeStampPosition(CANTimeStampPosition) (((CANTimeStampPosition) == CANTimeStampPosition_SOF) || \
                                                       ((CANTimeStampPosition)== CANTimeStampPosition_EOF) )

/** @brief CAN DATA Length
  * @{
  */
 typedef enum 
	{
    CAN_DLC_0 = 0x00,/*!<Select CAN DATA Length 0*/
    CAN_DLC_1 = 0x01,/*!<Select CAN DATA Length 1*/
    CAN_DLC_2 = 0x02,/*!<Select CAN DATA Length 2*/  
    CAN_DLC_3 = 0x03,/*!<Select CAN DATA Length 3*/
    CAN_DLC_4 = 0x04,/*!<Select CAN DATA Length 4*/
    CAN_DLC_5 = 0x05,/*!<Select CAN DATA Length 5*/
    CAN_DLC_6 = 0x06,/*!<Select CAN DATA Length 6*/
    CAN_DLC_7 = 0x07,/*!<Select CAN DATA Length 7*/
    CAN_DLC_8 = 0x08,/*!<Select CAN DATA Length 8*/
    CAN_DLC_12 = 0x09,/*!<Select CAN DATA Length 12*/
    CAN_DLC_16 = 0x0A,/*!<Select CAN DATA Length 16*/
    CAN_DLC_20 = 0x0B,/*!<Select CAN DATA Length 20*/
    CAN_DLC_24 = 0x0C,/*!<Select CAN DATA Length 24*/
    CAN_DLC_32 = 0x0D,/*!<Select CAN DATA Length 32*/
    CAN_DLC_48 = 0x0E,/*!<Select CAN DATA Length 4*/
    CAN_DLC_64 = 0x0F,/*!<Select CAN DATA Length 64*/
} CAN_DLC;
/** @brief CAN Select the sending mode
  * @{
  */
typedef enum
{
	CAN_TransMod_TPE =(uint16_t) (0x01<<CAN_CFG_STAT_TPE_Pos),	/*!<PTB Send a single message*/	
	CAN_TransMod_TSONE =(uint16_t)(0x01<<CAN_CFG_STAT_TSONE_Pos),/*!<STB single send*/
  CAN_TransMod_TSALL = (uint16_t)(0x01<<CAN_CFG_STAT_TSALL_Pos),	/*!<All STBS are sent*/
}CAN_TransMod_TypeDef;
#define IS_CAN_TransMod(CAN_TransMod) (((CAN_TransMod) ==CAN_TransMod_TPE) || \
                                     ((CAN_TransMod) ==CAN_TransMod_TSONE) || \
                                     ((CAN_TransMod)== CAN_TransMod_TSALL) )
/** @brief CAN ISO mode selection
  * @{
  */
typedef enum
{
	
	CAN_BOSCH = (uint32_t)(0x00<<CAN_CFG_STAT_FD_ISO_Pos),/*!<Non-iso mode*/
	

	CAN_ISO = (uint32_t)(0x01<<CAN_CFG_STAT_FD_ISO_Pos),	/*!<ISO mode*/
}CANFD_ISO_MODE_TypeDef;
#define IS_CANFD_ISO_MODE(ISO_MODE) (((ISO_MODE) == CAN_BOSCH) || \
                           ((ISO_MODE)== CAN_ISO) )
/** @brief CAN BaudRate
  * @{
  */
typedef enum
{
	 Baudrate_125kHz = 125000,/*!<Select the baud rate of 125khz*/
   Baudrate_250kHz = 250000,/*!<Select the baud rate of 250khz*/
	 Baudrate_500kHz = 500000,/*!<Select the baud rate of 500khz*/
	 Baudrate_800kHz = 800000,/*!<Select the baud rate of 800khz*/
	 Baudrate_1000kHz = 1000000,/*!<Select the baud rate of 1000khz*/
}CAN_BaudRate;


/** @brief CAN mode selection
  * @{
  */
typedef enum
{
	CAN_Normal =0,/*!<Working mode:Normal*/
	CAN_Listenonly,/*!<Working mode:Listenonly*/
	CAN_StandBy,/*!<Working mode:StandBy*/
	CAN_LoopBack,/*!<Working mode:LoopBack*/
	CAN_LoopBackIn,/*!<Working mode:LoopBackIn*/
	CAN_LoopBackSack,/*!<Working mode:LoopBackSack*/
}ModSelect_TypeDef;

/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup CAN_Struct CAN Struct
 * @{
 */
/** @brief CAN send data structures
  * @{
  */
typedef struct
{
	uint32_t CAN_TXID; /*!< This member configures the ID of the CAN sent data */
  uint32_t Tx_msg[8]; /*!< This member configures the sending data of CAN*/
	uint16_t Data_len; /*!< This member configures the length of the sent data of CAN*/
	uint8_t CAN_RTR; /*!< This member configures whether the sent data of CAN is a remote frame*/
	uint8_t CAN_FDF; /*!< This member configures whether the sent data of CAN is FD*/
	uint8_t CAN_BRS; /*!<This member configures whether CAN sends data at a variable baud rate*/
	uint8_t CAN_IDE; /*!< This member configures whether the sent data of CAN is an extended frame*/  
	uint8_t Tx_msg_len; /*!< This member configures the number of data sent by CAN */
}CanTxMsg;

typedef struct
{
	uint32_t CAN_RXID; /*!< This member is the ID of the CAN receive data */
	uint32_t Rx_msg[8];/*!< This member is the receive data of CAN*/ 
  uint8_t CAN_IDE; /*!< This member is The frame format of the received data */
  uint16_t Data_len;/*!< This member is the length of the receive data of CAN*/
  uint8_t CAN_RTR; /*!< This member is The frame format of the received data*/
  uint8_t CAN_FDF; /*!< This member configures whether the received data of CAN is FD*/
	uint8_t CAN_BRS;  /*!<This member Gets whether the baud rate of the received data is variable */
} CanRxMsg;

typedef struct
{
	uint32_t S_SJW; /*!< This member configures CAN SLOW BAUD. */	
	
	uint32_t S_SEG1; /*!< This member configures CAN SLOW BAUD. */	
	
	uint32_t S_SEG2; /*!< This member configures CAN SLOW BAUD. */	
	
	uint32_t S_PRESCALER; /*!< This member configures CAN SLOW BAUD. */	
	
	uint32_t F_SJW; /*!< This member configures CAN HIGH BAUD. */	
	
	uint32_t F_SEG1; /*!< This member configures CAN HIGH BAUD. */
	
	uint32_t F_SEG2; /*!< This member configures CAN HIGH BAUD. */
	
	uint32_t F_PRESCALER; /*!< This member configures CAN HIGH BAUD. */
	
	uint32_t CANFDFrame; /*!< This member configures CAN Frame.
                                              This parameter can be a value of @ref CAN_FDFMODE_Typedef */	

	uint32_t CANROMSelect; /*!< This member configures CAN ROMSelect.
                                              This parameter can be a value of @ref CANROM_TypeDef */
	uint32_t CAN_MOD; /*!< This member configures CAN  mode.
                                              This parameter can be a value of @ref ModSelect_TypeDef */
	
  uint32_t CANTSMODESelect; /*!< This member configures CAN TSMODESelect.
                                              This parameter can be a value of @ref CANTSMODE_TypeDef */
	
	uint32_t CANFDISOSelect; /*!< This member configures CAN FDISO Select.
                                              This parameter can be a value of @ref CANFD_ISO_MODE_TypeDef */
	
	uint16_t CANTimeStampPositon; /*!< This member configures CAN TimeStamp Positon.
                                              This parameter can be a value of @ref CANTimeStampPosition_TypeDef */
	
	uint16_t CANTBUFSelect; /*!< This member configures CAN Sending mode.
                                              This parameter can be a value of @ref CANTBUF_TypeDef */
	
	uint16_t  TransMod; /*!< This member configures CAN TransMod.
                                              This parameter can be a value of @ref ModSelect_TypeDef */
	
	FunctionalState CANTXEN; /*!< This member configures CAN Send enable.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CANRXEN; /*!< This member configures CAN Receive enable.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CANTimeStamp; /*!< This member configures CAN TimeStamp mode.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CANTimeStampCnt; /*!< This member configures CAN TimeStampCnt mode.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CAN_PTB_AutoRetrans; /*!< This member configures CAN PTB AutoRetrans enable.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CAN_STB_AutoRetrans; /*!< This member configures CAN STB AutoRetrans enable.
                                              This parameter can be a value of @ref FunctionalState */
	
}CAN_InitTypeDef;

/** @brief Filter structure
  * @{
  */
typedef struct
{
	uint32_t Acode;/*!<Filter ID Settings*/
	uint32_t Amask;/*!<Filter ID Settings*/
	uint8_t CAN_Fliter;/*!<Configure filter*/
  uint8_t CANFliterFrame;/*!<Filter frame format*/
}CAN_FliterTypeDef;



#endif

#define FD_Mode_on 0x80000000
#define FD_Mode_off 0x00000000
#define CAN_CFG_STAT_ACK 0x80000000
/** @brief CAN_synchronisation_jump_width 
  * @{
  */

#define CAN_SJW_1tq                 ((uint8_t)0x00)  /*!< 1 time quantum */
#define CAN_SJW_2tq                 ((uint8_t)0x01)  /*!< 2 time quantum */
#define CAN_SJW_3tq                 ((uint8_t)0x02)  /*!< 3 time quantum */
#define CAN_SJW_4tq                 ((uint8_t)0x03)  /*!< 4 time quantum */

#define IS_CAN_SJW(SJW) (((SJW) == CAN_SJW_1tq) || ((SJW) == CAN_SJW_2tq)|| \
                         ((SJW) == CAN_SJW_3tq) || ((SJW) == CAN_SJW_4tq))
/**
  * @}
  */

/** @brief CAN_time_quantum_in_bit_segment_1 
  * @{
  */

#define CAN_SEG1_1tq                 ((uint8_t)0x00)  /*!< 1 time quantum */
#define CAN_SEG1_2tq                 ((uint8_t)0x01)  /*!< 2 time quantum */
#define CAN_SEG1_3tq                 ((uint8_t)0x02)  /*!< 3 time quantum */
#define CAN_SEG1_4tq                 ((uint8_t)0x03)  /*!< 4 time quantum */
#define CAN_SEG1_5tq                 ((uint8_t)0x04)  /*!< 5 time quantum */
#define CAN_SEG1_6tq                 ((uint8_t)0x05)  /*!< 6 time quantum */
#define CAN_SEG1_7tq                 ((uint8_t)0x06)  /*!< 7 time quantum */
#define CAN_SEG1_8tq                 ((uint8_t)0x07)  /*!< 8 time quantum */
#define CAN_SEG1_9tq                 ((uint8_t)0x08)  /*!< 9 time quantum */
#define CAN_SEG1_10tq                ((uint8_t)0x09)  /*!< 10 time quantum */
#define CAN_SEG1_11tq                ((uint8_t)0x0A)  /*!< 11 time quantum */
#define CAN_SEG1_12tq                ((uint8_t)0x0B)  /*!< 12 time quantum */
#define CAN_SEG1_13tq                ((uint8_t)0x0C)  /*!< 13 time quantum */
#define CAN_SEG1_14tq                ((uint8_t)0x0D)  /*!< 14 time quantum */
#define CAN_SEG1_15tq                ((uint8_t)0x0E)  /*!< 15 time quantum */
#define CAN_SEG1_16tq                ((uint8_t)0x0F)  /*!< 16 time quantum */

#define IS_CAN_SEG1(SEG1) ((SEG1) <= CAN_SEG1_16tq)
/**
  * @}
  */

/** @brief CAN_time_quantum_in_bit_segment_2 
  * @{
  */

#define CAN_SEG2_1tq                 ((uint8_t)0x00)  /*!< 1 time quantum */
#define CAN_SEG2_2tq                 ((uint8_t)0x01)  /*!< 2 time quantum */
#define CAN_SEG2_3tq                 ((uint8_t)0x02)  /*!< 3 time quantum */
#define CAN_SEG2_4tq                 ((uint8_t)0x03)  /*!< 4 time quantum */
#define CAN_SEG2_5tq                 ((uint8_t)0x04)  /*!< 5 time quantum */
#define CAN_SEG2_6tq                 ((uint8_t)0x05)  /*!< 6 time quantum */
#define CAN_SEG2_7tq                 ((uint8_t)0x06)  /*!< 7 time quantum */
#define CAN_SEG2_8tq                 ((uint8_t)0x07)  /*!< 8 time quantum */

#define IS_CAN_SEG2(SEG2) ((SEG2) <= CAN_SEG2_8tq)

/**
  * @}
  */
#define IS_CAN_PRESCALER(PRESCALER) (((PRESCALER) >= 0) && ((PRESCALER) <= 255))
#define IS_CAN_ALL_PERIPH(PERIPH) ((PERIPH) == CAN)
/* CAN Base functions ********************************************************/
void CAN_DeInit(CAN_TypeDef* CANx);
void CAN_Init(CAN_TypeDef *CANx, CAN_InitTypeDef *CAN_InitStruct);
void CAN_StructInit(CAN_InitTypeDef* CAN_InitStruct);
void CAN_TBUFSelect(CAN_TypeDef *CANx, CANTBUF_TypeDef CANTBUF);
void CAN_FBaudRate_Select(unsigned int CAN_Clk,unsigned int CAN_FPrescaler,CAN_BaudRate BaudRate);
void CAN_SBaudRate_Select(unsigned int CAN_Clk,unsigned int CAN_FPrescaler,CAN_BaudRate BaudRate);

void CAN_Trans_Select(CAN_TypeDef *CANx,CAN_TransMod_TypeDef TransModSelect);
void CAN_RxThresholdConfig(CAN_TypeDef *CANx, int Rth);
void CAN_FliterInit( CAN_FliterTypeDef *CAN_FliterStruct);
void CAN_ModeSelect(CAN_TypeDef *CANx, ModSelect_TypeDef CAN_MOD);
/* Data transfers functions ********************************************************/
void CAN_Trans_Init(CAN_TypeDef *CANx, CanTxMsg *CAN_Tx_msg);
void CAN_TransStop(CAN_TypeDef *CANx);
void CAN_RecieveConfig(CAN_TypeDef *CANx, CanRxMsg* RxMessage);
/* Interrupts and flags management functions  **********************************************/
void CAN_ITConfig(CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState NewState);
ITStatus CAN_GetFlagStatus(CAN_TypeDef *CANx, uint32_t CAN_Flag);
void CAN_ClearFlag(CAN_TypeDef *CANx, uint32_t CAN_Flag);
/* Number of error data and Reset  **********************************************/
uint8_t CAN_GetTECNT(CAN_TypeDef* CANx);
uint8_t CAN_GetRECNT(CAN_TypeDef* CANx);
void CAN_ResetCmd(CAN_TypeDef *CANx, FunctionalState NewState);
/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
