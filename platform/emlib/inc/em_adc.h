/*
 * em_adc.h
 *
 *  Created on: Apr 18, 2019
 *      Author: srina
 */

#ifndef PLATFORM_EMLIB_INC_EM_ADC_H_
#define PLATFORM_EMLIB_INC_EM_ADC_H_

/***************************************************************************/
// #ifndef EM_ADC_H
// #define EM_ADC_H

 /***************************************************************************/
// #ifndef EM_ADC_H
// #define EM_ADC_H

 #include "em_device.h"
 #if defined( ADC_COUNT ) && ( ADC_COUNT > 0 )

 #include <stdbool.h>

 #ifdef __cplusplus
 extern "C" {
 #endif

 /***************************************************************************/
 /***************************************************************************/
 /*******************************************************************************
  ********************************   ENUMS   ************************************
  ******************************************************************************/

 typedef enum
 {
   adcAcqTime1   = _ADC_SINGLECTRL_AT_1CYCLE,
   adcAcqTime2   = _ADC_SINGLECTRL_AT_2CYCLES,
   adcAcqTime4   = _ADC_SINGLECTRL_AT_4CYCLES,
   adcAcqTime8   = _ADC_SINGLECTRL_AT_8CYCLES,
   adcAcqTime16  = _ADC_SINGLECTRL_AT_16CYCLES,
   adcAcqTime32  = _ADC_SINGLECTRL_AT_32CYCLES,
   adcAcqTime64  = _ADC_SINGLECTRL_AT_64CYCLES,
   adcAcqTime128 = _ADC_SINGLECTRL_AT_128CYCLES,
   adcAcqTime256 = _ADC_SINGLECTRL_AT_256CYCLES
 } ADC_AcqTime_TypeDef;

 #if defined( _ADC_CTRL_LPFMODE_MASK )

 typedef enum
 {
   adcLPFilterBypass = _ADC_CTRL_LPFMODE_BYPASS,

   adcLPFilterRC     = _ADC_CTRL_LPFMODE_RCFILT,

   adcLPFilterDeCap  = _ADC_CTRL_LPFMODE_DECAP
 } ADC_LPFilter_TypeDef;
 #endif

 typedef enum
 {
   adcOvsRateSel2    = _ADC_CTRL_OVSRSEL_X2,

   adcOvsRateSel4    = _ADC_CTRL_OVSRSEL_X4,

   adcOvsRateSel8    = _ADC_CTRL_OVSRSEL_X8,

   adcOvsRateSel16   = _ADC_CTRL_OVSRSEL_X16,

   adcOvsRateSel32   = _ADC_CTRL_OVSRSEL_X32,

   adcOvsRateSel64   = _ADC_CTRL_OVSRSEL_X64,

   adcOvsRateSel128  = _ADC_CTRL_OVSRSEL_X128,

   adcOvsRateSel256  = _ADC_CTRL_OVSRSEL_X256,

   adcOvsRateSel512  = _ADC_CTRL_OVSRSEL_X512,

   adcOvsRateSel1024 = _ADC_CTRL_OVSRSEL_X1024,

   adcOvsRateSel2048 = _ADC_CTRL_OVSRSEL_X2048,

   adcOvsRateSel4096 = _ADC_CTRL_OVSRSEL_X4096
 } ADC_OvsRateSel_TypeDef;


 typedef enum
 {
 #if defined( _ADC_SINGLECTRL_PRSSEL_MASK )
   adcPRSSELCh0 = _ADC_SINGLECTRL_PRSSEL_PRSCH0,
   adcPRSSELCh1 = _ADC_SINGLECTRL_PRSSEL_PRSCH1,
   adcPRSSELCh2 = _ADC_SINGLECTRL_PRSSEL_PRSCH2,
   adcPRSSELCh3 = _ADC_SINGLECTRL_PRSSEL_PRSCH3,
 #if defined( _ADC_SINGLECTRL_PRSSEL_PRSCH4 )
   adcPRSSELCh4 = _ADC_SINGLECTRL_PRSSEL_PRSCH4,
 #endif
 #if defined( _ADC_SINGLECTRL_PRSSEL_PRSCH5 )
   adcPRSSELCh5 = _ADC_SINGLECTRL_PRSSEL_PRSCH5,
 #endif
 #if defined( _ADC_SINGLECTRL_PRSSEL_PRSCH6 )
   adcPRSSELCh6 = _ADC_SINGLECTRL_PRSSEL_PRSCH6,
 #endif
 #if defined( _ADC_SINGLECTRL_PRSSEL_PRSCH7 )
   adcPRSSELCh7 = _ADC_SINGLECTRL_PRSSEL_PRSCH7,
 #endif
 #if defined( _ADC_SINGLECTRL_PRSSEL_PRSCH8 )
   adcPRSSELCh8 = _ADC_SINGLECTRL_PRSSEL_PRSCH8,
 #endif
 #if defined( _ADC_SINGLECTRL_PRSSEL_PRSCH9 )
   adcPRSSELCh9 = _ADC_SINGLECTRL_PRSSEL_PRSCH9,
 #endif
 #if defined( _ADC_SINGLECTRL_PRSSEL_PRSCH10 )
   adcPRSSELCh10 = _ADC_SINGLECTRL_PRSSEL_PRSCH10,
 #endif
 #if defined( _ADC_SINGLECTRL_PRSSEL_PRSCH11 )
   adcPRSSELCh11 = _ADC_SINGLECTRL_PRSSEL_PRSCH11,
 #endif
 #elif defined(_ADC_SINGLECTRLX_PRSSEL_MASK)
   adcPRSSELCh0 = _ADC_SINGLECTRLX_PRSSEL_PRSCH0,
   adcPRSSELCh1 = _ADC_SINGLECTRLX_PRSSEL_PRSCH1,
   adcPRSSELCh2 = _ADC_SINGLECTRLX_PRSSEL_PRSCH2,
   adcPRSSELCh3 = _ADC_SINGLECTRLX_PRSSEL_PRSCH3,
   adcPRSSELCh4 = _ADC_SINGLECTRLX_PRSSEL_PRSCH4,
   adcPRSSELCh5 = _ADC_SINGLECTRLX_PRSSEL_PRSCH5,
   adcPRSSELCh6 = _ADC_SINGLECTRLX_PRSSEL_PRSCH6,
   adcPRSSELCh7 = _ADC_SINGLECTRLX_PRSSEL_PRSCH7,
   adcPRSSELCh8 = _ADC_SINGLECTRLX_PRSSEL_PRSCH8,
   adcPRSSELCh9 = _ADC_SINGLECTRLX_PRSSEL_PRSCH9,
   adcPRSSELCh10 = _ADC_SINGLECTRLX_PRSSEL_PRSCH10,
   adcPRSSELCh11 = _ADC_SINGLECTRLX_PRSSEL_PRSCH11,
 #if defined( _ADC_SINGLECTRLX_PRSSEL_PRSCH12 )
   adcPRSSELCh12 = _ADC_SINGLECTRLX_PRSSEL_PRSCH12,
   adcPRSSELCh13 = _ADC_SINGLECTRLX_PRSSEL_PRSCH13,
   adcPRSSELCh14 = _ADC_SINGLECTRLX_PRSSEL_PRSCH14,
   adcPRSSELCh15 = _ADC_SINGLECTRLX_PRSSEL_PRSCH15,
 #endif
 #endif
 } ADC_PRSSEL_TypeDef;


 #if defined( _ADC_SCANCTRLX_VREFSEL_MASK )
 #define ADC_CTRLX_VREFSEL_REG     0x80
 #endif
 typedef enum
 {
   adcRef1V25      = _ADC_SINGLECTRL_REF_1V25,

   adcRef2V5       = _ADC_SINGLECTRL_REF_2V5,

   adcRefVDD       = _ADC_SINGLECTRL_REF_VDD,

 #if defined( _ADC_SINGLECTRL_REF_5VDIFF )

   adcRef5VDIFF    = _ADC_SINGLECTRL_REF_5VDIFF,
 #endif

 #if defined( _ADC_SINGLECTRL_REF_5V )

   adcRef5V        = _ADC_SINGLECTRL_REF_5V,
 #endif

   adcRefExtSingle = _ADC_SINGLECTRL_REF_EXTSINGLE,

   adcRef2xExtDiff = _ADC_SINGLECTRL_REF_2XEXTDIFF,

   adcRef2xVDD     = _ADC_SINGLECTRL_REF_2XVDD,

 #if defined( _ADC_SINGLECTRLX_VREFSEL_VBGR )

   adcRefVBGR      = _ADC_SINGLECTRLX_VREFSEL_VBGR | ADC_CTRLX_VREFSEL_REG,
 #endif

 #if defined( _ADC_SINGLECTRLX_VREFSEL_VDDXWATT )

   adcRefVddxAtt   = _ADC_SINGLECTRLX_VREFSEL_VDDXWATT | ADC_CTRLX_VREFSEL_REG,
 #endif

 #if defined( _ADC_SINGLECTRLX_VREFSEL_VREFPWATT )

   adcRefVPxAtt    = _ADC_SINGLECTRLX_VREFSEL_VREFPWATT | ADC_CTRLX_VREFSEL_REG,
 #endif

 #if defined( _ADC_SINGLECTRLX_VREFSEL_VREFP )

   adcRefP         = _ADC_SINGLECTRLX_VREFSEL_VREFP | ADC_CTRLX_VREFSEL_REG,
 #endif

 #if defined( _ADC_SINGLECTRLX_VREFSEL_VENTROPY )

   adcRefVEntropy = _ADC_SINGLECTRLX_VREFSEL_VENTROPY | ADC_CTRLX_VREFSEL_REG,
 #endif

 #if defined( _ADC_SINGLECTRLX_VREFSEL_VREFPNWATT )

   adcRefVPNxAtt  = _ADC_SINGLECTRLX_VREFSEL_VREFPNWATT | ADC_CTRLX_VREFSEL_REG,
 #endif

 #if defined( _ADC_SINGLECTRLX_VREFSEL_VREFPN )

   adcRefPN       = _ADC_SINGLECTRLX_VREFSEL_VREFPN | ADC_CTRLX_VREFSEL_REG,
 #endif
 } ADC_Ref_TypeDef;

 /* Deprecated enum names */
 #if !defined( _ADC_SINGLECTRL_REF_5VDIFF )
 #define adcRef5VDIFF adcRef5V
 #endif

 typedef enum
 {
   adcRes12Bit = _ADC_SINGLECTRL_RES_12BIT,
   adcRes8Bit  = _ADC_SINGLECTRL_RES_8BIT,
   adcRes6Bit  = _ADC_SINGLECTRL_RES_6BIT,
   adcResOVS   = _ADC_SINGLECTRL_RES_OVS
 } ADC_Res_TypeDef;


 #if defined( _ADC_SINGLECTRL_INPUTSEL_MASK )

 typedef enum
 {
   /* Differential mode disabled */
   adcSingleInputCh0      = _ADC_SINGLECTRL_INPUTSEL_CH0,
   adcSingleInputCh1      = _ADC_SINGLECTRL_INPUTSEL_CH1,
   adcSingleInputCh2      = _ADC_SINGLECTRL_INPUTSEL_CH2,
   adcSingleInputCh3      = _ADC_SINGLECTRL_INPUTSEL_CH3,
   adcSingleInputCh4      = _ADC_SINGLECTRL_INPUTSEL_CH4,
   adcSingleInputCh5      = _ADC_SINGLECTRL_INPUTSEL_CH5,
   adcSingleInputCh6      = _ADC_SINGLECTRL_INPUTSEL_CH6,
   adcSingleInputCh7      = _ADC_SINGLECTRL_INPUTSEL_CH7,
   adcSingleInputTemp     = _ADC_SINGLECTRL_INPUTSEL_TEMP,
   adcSingleInputVDDDiv3  = _ADC_SINGLECTRL_INPUTSEL_VDDDIV3,
   adcSingleInputVDD      = _ADC_SINGLECTRL_INPUTSEL_VDD,
   adcSingleInputVSS      = _ADC_SINGLECTRL_INPUTSEL_VSS,
   adcSingleInputVrefDiv2 = _ADC_SINGLECTRL_INPUTSEL_VREFDIV2,
   adcSingleInputDACOut0  = _ADC_SINGLECTRL_INPUTSEL_DAC0OUT0,
   adcSingleInputDACOut1  = _ADC_SINGLECTRL_INPUTSEL_DAC0OUT1,
   adcSingleInputATEST    = 15,
   /* Differential mode enabled */
   adcSingleInputCh0Ch1   = _ADC_SINGLECTRL_INPUTSEL_CH0CH1,
   adcSingleInputCh2Ch3   = _ADC_SINGLECTRL_INPUTSEL_CH2CH3,
   adcSingleInputCh4Ch5   = _ADC_SINGLECTRL_INPUTSEL_CH4CH5,
   adcSingleInputCh6Ch7   = _ADC_SINGLECTRL_INPUTSEL_CH6CH7,
   adcSingleInputDiff0    = 4
 } ADC_SingleInput_TypeDef;

 /* Deprecated enum names */
 #define adcSingleInpCh0       adcSingleInputCh0
 #define adcSingleInpCh1       adcSingleInputCh1
 #define adcSingleInpCh2       adcSingleInputCh2
 #define adcSingleInpCh3       adcSingleInputCh3
 #define adcSingleInpCh4       adcSingleInputCh4
 #define adcSingleInpCh5       adcSingleInputCh5
 #define adcSingleInpCh6       adcSingleInputCh6
 #define adcSingleInpCh7       adcSingleInputCh7
 #define adcSingleInpTemp      adcSingleInputTemp
 #define adcSingleInpVDDDiv3   adcSingleInputVDDDiv3
 #define adcSingleInpVDD       adcSingleInputVDD
 #define adcSingleInpVSS       adcSingleInputVSS
 #define adcSingleInpVrefDiv2  adcSingleInputVrefDiv2
 #define adcSingleInpDACOut0   adcSingleInputDACOut0
 #define adcSingleInpDACOut1   adcSingleInputDACOut1
 #define adcSingleInpATEST     adcSingleInputATEST
 #define adcSingleInpCh0Ch1    adcSingleInputCh0Ch1
 #define adcSingleInpCh2Ch3    adcSingleInputCh2Ch3
 #define adcSingleInpCh4Ch5    adcSingleInputCh4Ch5
 #define adcSingleInpCh6Ch7    adcSingleInputCh6Ch7
 #define adcSingleInpDiff0     adcSingleInputDiff0

 #endif

 #if defined( _ADC_SINGLECTRL_POSSEL_MASK )

 typedef enum
 {
   adcPosSelAPORT0XCH0  = _ADC_SINGLECTRL_POSSEL_APORT0XCH0,
   adcPosSelAPORT0XCH1  = _ADC_SINGLECTRL_POSSEL_APORT0XCH1,
   adcPosSelAPORT0XCH2  = _ADC_SINGLECTRL_POSSEL_APORT0XCH2,
   adcPosSelAPORT0XCH3  = _ADC_SINGLECTRL_POSSEL_APORT0XCH3,
   adcPosSelAPORT0XCH4  = _ADC_SINGLECTRL_POSSEL_APORT0XCH4,
   adcPosSelAPORT0XCH5  = _ADC_SINGLECTRL_POSSEL_APORT0XCH5,
   adcPosSelAPORT0XCH6  = _ADC_SINGLECTRL_POSSEL_APORT0XCH6,
   adcPosSelAPORT0XCH7  = _ADC_SINGLECTRL_POSSEL_APORT0XCH7,
   adcPosSelAPORT0XCH8  = _ADC_SINGLECTRL_POSSEL_APORT0XCH8,
   adcPosSelAPORT0XCH9  = _ADC_SINGLECTRL_POSSEL_APORT0XCH9,
   adcPosSelAPORT0XCH10 = _ADC_SINGLECTRL_POSSEL_APORT0XCH10,
   adcPosSelAPORT0XCH11 = _ADC_SINGLECTRL_POSSEL_APORT0XCH11,
   adcPosSelAPORT0XCH12 = _ADC_SINGLECTRL_POSSEL_APORT0XCH12,
   adcPosSelAPORT0XCH13 = _ADC_SINGLECTRL_POSSEL_APORT0XCH13,
   adcPosSelAPORT0XCH14 = _ADC_SINGLECTRL_POSSEL_APORT0XCH14,
   adcPosSelAPORT0XCH15 = _ADC_SINGLECTRL_POSSEL_APORT0XCH15,
   adcPosSelAPORT0YCH0  = _ADC_SINGLECTRL_POSSEL_APORT0YCH0,
   adcPosSelAPORT0YCH1  = _ADC_SINGLECTRL_POSSEL_APORT0YCH1,
   adcPosSelAPORT0YCH2  = _ADC_SINGLECTRL_POSSEL_APORT0YCH2,
   adcPosSelAPORT0YCH3  = _ADC_SINGLECTRL_POSSEL_APORT0YCH3,
   adcPosSelAPORT0YCH4  = _ADC_SINGLECTRL_POSSEL_APORT0YCH4,
   adcPosSelAPORT0YCH5  = _ADC_SINGLECTRL_POSSEL_APORT0YCH5,
   adcPosSelAPORT0YCH6  = _ADC_SINGLECTRL_POSSEL_APORT0YCH6,
   adcPosSelAPORT0YCH7  = _ADC_SINGLECTRL_POSSEL_APORT0YCH7,
   adcPosSelAPORT0YCH8  = _ADC_SINGLECTRL_POSSEL_APORT0YCH8,
   adcPosSelAPORT0YCH9  = _ADC_SINGLECTRL_POSSEL_APORT0YCH9,
   adcPosSelAPORT0YCH10 = _ADC_SINGLECTRL_POSSEL_APORT0YCH10,
   adcPosSelAPORT0YCH11 = _ADC_SINGLECTRL_POSSEL_APORT0YCH11,
   adcPosSelAPORT0YCH12 = _ADC_SINGLECTRL_POSSEL_APORT0YCH12,
   adcPosSelAPORT0YCH13 = _ADC_SINGLECTRL_POSSEL_APORT0YCH13,
   adcPosSelAPORT0YCH14 = _ADC_SINGLECTRL_POSSEL_APORT0YCH14,
   adcPosSelAPORT0YCH15 = _ADC_SINGLECTRL_POSSEL_APORT0YCH15,
   adcPosSelAPORT1XCH0  = _ADC_SINGLECTRL_POSSEL_APORT1XCH0,
   adcPosSelAPORT1YCH1  = _ADC_SINGLECTRL_POSSEL_APORT1YCH1,
   adcPosSelAPORT1XCH2  = _ADC_SINGLECTRL_POSSEL_APORT1XCH2,
   adcPosSelAPORT1YCH3  = _ADC_SINGLECTRL_POSSEL_APORT1YCH3,
   adcPosSelAPORT1XCH4  = _ADC_SINGLECTRL_POSSEL_APORT1XCH4,
   adcPosSelAPORT1YCH5  = _ADC_SINGLECTRL_POSSEL_APORT1YCH5,
   adcPosSelAPORT1XCH6  = _ADC_SINGLECTRL_POSSEL_APORT1XCH6,
   adcPosSelAPORT1YCH7  = _ADC_SINGLECTRL_POSSEL_APORT1YCH7,
   adcPosSelAPORT1XCH8  = _ADC_SINGLECTRL_POSSEL_APORT1XCH8,
   adcPosSelAPORT1YCH9  = _ADC_SINGLECTRL_POSSEL_APORT1YCH9,
   adcPosSelAPORT1XCH10 = _ADC_SINGLECTRL_POSSEL_APORT1XCH10,
   adcPosSelAPORT1YCH11 = _ADC_SINGLECTRL_POSSEL_APORT1YCH11,
   adcPosSelAPORT1XCH12 = _ADC_SINGLECTRL_POSSEL_APORT1XCH12,
   adcPosSelAPORT1YCH13 = _ADC_SINGLECTRL_POSSEL_APORT1YCH13,
   adcPosSelAPORT1XCH14 = _ADC_SINGLECTRL_POSSEL_APORT1XCH14,
   adcPosSelAPORT1YCH15 = _ADC_SINGLECTRL_POSSEL_APORT1YCH15,
   adcPosSelAPORT1XCH16 = _ADC_SINGLECTRL_POSSEL_APORT1XCH16,
   adcPosSelAPORT1YCH17 = _ADC_SINGLECTRL_POSSEL_APORT1YCH17,
   adcPosSelAPORT1XCH18 = _ADC_SINGLECTRL_POSSEL_APORT1XCH18,
   adcPosSelAPORT1YCH19 = _ADC_SINGLECTRL_POSSEL_APORT1YCH19,
   adcPosSelAPORT1XCH20 = _ADC_SINGLECTRL_POSSEL_APORT1XCH20,
   adcPosSelAPORT1YCH21 = _ADC_SINGLECTRL_POSSEL_APORT1YCH21,
   adcPosSelAPORT1XCH22 = _ADC_SINGLECTRL_POSSEL_APORT1XCH22,
   adcPosSelAPORT1YCH23 = _ADC_SINGLECTRL_POSSEL_APORT1YCH23,
   adcPosSelAPORT1XCH24 = _ADC_SINGLECTRL_POSSEL_APORT1XCH24,
   adcPosSelAPORT1YCH25 = _ADC_SINGLECTRL_POSSEL_APORT1YCH25,
   adcPosSelAPORT1XCH26 = _ADC_SINGLECTRL_POSSEL_APORT1XCH26,
   adcPosSelAPORT1YCH27 = _ADC_SINGLECTRL_POSSEL_APORT1YCH27,
   adcPosSelAPORT1XCH28 = _ADC_SINGLECTRL_POSSEL_APORT1XCH28,
   adcPosSelAPORT1YCH29 = _ADC_SINGLECTRL_POSSEL_APORT1YCH29,
   adcPosSelAPORT1XCH30 = _ADC_SINGLECTRL_POSSEL_APORT1XCH30,
   adcPosSelAPORT1YCH31 = _ADC_SINGLECTRL_POSSEL_APORT1YCH31,
   adcPosSelAPORT2YCH0  = _ADC_SINGLECTRL_POSSEL_APORT2YCH0,
   adcPosSelAPORT2XCH1  = _ADC_SINGLECTRL_POSSEL_APORT2XCH1,
   adcPosSelAPORT2YCH2  = _ADC_SINGLECTRL_POSSEL_APORT2YCH2,
   adcPosSelAPORT2XCH3  = _ADC_SINGLECTRL_POSSEL_APORT2XCH3,
   adcPosSelAPORT2YCH4  = _ADC_SINGLECTRL_POSSEL_APORT2YCH4,
   adcPosSelAPORT2XCH5  = _ADC_SINGLECTRL_POSSEL_APORT2XCH5,
   adcPosSelAPORT2YCH6  = _ADC_SINGLECTRL_POSSEL_APORT2YCH6,
   adcPosSelAPORT2XCH7  = _ADC_SINGLECTRL_POSSEL_APORT2XCH7,
   adcPosSelAPORT2YCH8  = _ADC_SINGLECTRL_POSSEL_APORT2YCH8,
   adcPosSelAPORT2XCH9  = _ADC_SINGLECTRL_POSSEL_APORT2XCH9,
   adcPosSelAPORT2YCH10 = _ADC_SINGLECTRL_POSSEL_APORT2YCH10,
   adcPosSelAPORT2XCH11 = _ADC_SINGLECTRL_POSSEL_APORT2XCH11,
   adcPosSelAPORT2YCH12 = _ADC_SINGLECTRL_POSSEL_APORT2YCH12,
   adcPosSelAPORT2XCH13 = _ADC_SINGLECTRL_POSSEL_APORT2XCH13,
   adcPosSelAPORT2YCH14 = _ADC_SINGLECTRL_POSSEL_APORT2YCH14,
   adcPosSelAPORT2XCH15 = _ADC_SINGLECTRL_POSSEL_APORT2XCH15,
   adcPosSelAPORT2YCH16 = _ADC_SINGLECTRL_POSSEL_APORT2YCH16,
   adcPosSelAPORT2XCH17 = _ADC_SINGLECTRL_POSSEL_APORT2XCH17,
   adcPosSelAPORT2YCH18 = _ADC_SINGLECTRL_POSSEL_APORT2YCH18,
   adcPosSelAPORT2XCH19 = _ADC_SINGLECTRL_POSSEL_APORT2XCH19,
   adcPosSelAPORT2YCH20 = _ADC_SINGLECTRL_POSSEL_APORT2YCH20,
   adcPosSelAPORT2XCH21 = _ADC_SINGLECTRL_POSSEL_APORT2XCH21,
   adcPosSelAPORT2YCH22 = _ADC_SINGLECTRL_POSSEL_APORT2YCH22,
   adcPosSelAPORT2XCH23 = _ADC_SINGLECTRL_POSSEL_APORT2XCH23,
   adcPosSelAPORT2YCH24 = _ADC_SINGLECTRL_POSSEL_APORT2YCH24,
   adcPosSelAPORT2XCH25 = _ADC_SINGLECTRL_POSSEL_APORT2XCH25,
   adcPosSelAPORT2YCH26 = _ADC_SINGLECTRL_POSSEL_APORT2YCH26,
   adcPosSelAPORT2XCH27 = _ADC_SINGLECTRL_POSSEL_APORT2XCH27,
   adcPosSelAPORT2YCH28 = _ADC_SINGLECTRL_POSSEL_APORT2YCH28,
   adcPosSelAPORT2XCH29 = _ADC_SINGLECTRL_POSSEL_APORT2XCH29,
   adcPosSelAPORT2YCH30 = _ADC_SINGLECTRL_POSSEL_APORT2YCH30,
   adcPosSelAPORT2XCH31 = _ADC_SINGLECTRL_POSSEL_APORT2XCH31,
   adcPosSelAPORT3XCH0  = _ADC_SINGLECTRL_POSSEL_APORT3XCH0,
   adcPosSelAPORT3YCH1  = _ADC_SINGLECTRL_POSSEL_APORT3YCH1,
   adcPosSelAPORT3XCH2  = _ADC_SINGLECTRL_POSSEL_APORT3XCH2,
   adcPosSelAPORT3YCH3  = _ADC_SINGLECTRL_POSSEL_APORT3YCH3,
   adcPosSelAPORT3XCH4  = _ADC_SINGLECTRL_POSSEL_APORT3XCH4,
   adcPosSelAPORT3YCH5  = _ADC_SINGLECTRL_POSSEL_APORT3YCH5,
   adcPosSelAPORT3XCH6  = _ADC_SINGLECTRL_POSSEL_APORT3XCH6,
   adcPosSelAPORT3YCH7  = _ADC_SINGLECTRL_POSSEL_APORT3YCH7,
   adcPosSelAPORT3XCH8  = _ADC_SINGLECTRL_POSSEL_APORT3XCH8,
   adcPosSelAPORT3YCH9  = _ADC_SINGLECTRL_POSSEL_APORT3YCH9,
   adcPosSelAPORT3XCH10 = _ADC_SINGLECTRL_POSSEL_APORT3XCH10,
   adcPosSelAPORT3YCH11 = _ADC_SINGLECTRL_POSSEL_APORT3YCH11,
   adcPosSelAPORT3XCH12 = _ADC_SINGLECTRL_POSSEL_APORT3XCH12,
   adcPosSelAPORT3YCH13 = _ADC_SINGLECTRL_POSSEL_APORT3YCH13,
   adcPosSelAPORT3XCH14 = _ADC_SINGLECTRL_POSSEL_APORT3XCH14,
   adcPosSelAPORT3YCH15 = _ADC_SINGLECTRL_POSSEL_APORT3YCH15,
   adcPosSelAPORT3XCH16 = _ADC_SINGLECTRL_POSSEL_APORT3XCH16,
   adcPosSelAPORT3YCH17 = _ADC_SINGLECTRL_POSSEL_APORT3YCH17,
   adcPosSelAPORT3XCH18 = _ADC_SINGLECTRL_POSSEL_APORT3XCH18,
   adcPosSelAPORT3YCH19 = _ADC_SINGLECTRL_POSSEL_APORT3YCH19,
   adcPosSelAPORT3XCH20 = _ADC_SINGLECTRL_POSSEL_APORT3XCH20,
   adcPosSelAPORT3YCH21 = _ADC_SINGLECTRL_POSSEL_APORT3YCH21,
   adcPosSelAPORT3XCH22 = _ADC_SINGLECTRL_POSSEL_APORT3XCH22,
   adcPosSelAPORT3YCH23 = _ADC_SINGLECTRL_POSSEL_APORT3YCH23,
   adcPosSelAPORT3XCH24 = _ADC_SINGLECTRL_POSSEL_APORT3XCH24,
   adcPosSelAPORT3YCH25 = _ADC_SINGLECTRL_POSSEL_APORT3YCH25,
   adcPosSelAPORT3XCH26 = _ADC_SINGLECTRL_POSSEL_APORT3XCH26,
   adcPosSelAPORT3YCH27 = _ADC_SINGLECTRL_POSSEL_APORT3YCH27,
   adcPosSelAPORT3XCH28 = _ADC_SINGLECTRL_POSSEL_APORT3XCH28,
   adcPosSelAPORT3YCH29 = _ADC_SINGLECTRL_POSSEL_APORT3YCH29,
   adcPosSelAPORT3XCH30 = _ADC_SINGLECTRL_POSSEL_APORT3XCH30,
   adcPosSelAPORT3YCH31 = _ADC_SINGLECTRL_POSSEL_APORT3YCH31,
   adcPosSelAPORT4YCH0  = _ADC_SINGLECTRL_POSSEL_APORT4YCH0,
   adcPosSelAPORT4XCH1  = _ADC_SINGLECTRL_POSSEL_APORT4XCH1,
   adcPosSelAPORT4YCH2  = _ADC_SINGLECTRL_POSSEL_APORT4YCH2,
   adcPosSelAPORT4XCH3  = _ADC_SINGLECTRL_POSSEL_APORT4XCH3,
   adcPosSelAPORT4YCH4  = _ADC_SINGLECTRL_POSSEL_APORT4YCH4,
   adcPosSelAPORT4XCH5  = _ADC_SINGLECTRL_POSSEL_APORT4XCH5,
   adcPosSelAPORT4YCH6  = _ADC_SINGLECTRL_POSSEL_APORT4YCH6,
   adcPosSelAPORT4XCH7  = _ADC_SINGLECTRL_POSSEL_APORT4XCH7,
   adcPosSelAPORT4YCH8  = _ADC_SINGLECTRL_POSSEL_APORT4YCH8,
   adcPosSelAPORT4XCH9  = _ADC_SINGLECTRL_POSSEL_APORT4XCH9,
   adcPosSelAPORT4YCH10 = _ADC_SINGLECTRL_POSSEL_APORT4YCH10,
   adcPosSelAPORT4XCH11 = _ADC_SINGLECTRL_POSSEL_APORT4XCH11,
   adcPosSelAPORT4YCH12 = _ADC_SINGLECTRL_POSSEL_APORT4YCH12,
   adcPosSelAPORT4XCH13 = _ADC_SINGLECTRL_POSSEL_APORT4XCH13,
   adcPosSelAPORT4YCH14 = _ADC_SINGLECTRL_POSSEL_APORT4YCH14,
   adcPosSelAPORT4XCH15 = _ADC_SINGLECTRL_POSSEL_APORT4XCH15,
   adcPosSelAPORT4YCH16 = _ADC_SINGLECTRL_POSSEL_APORT4YCH16,
   adcPosSelAPORT4XCH17 = _ADC_SINGLECTRL_POSSEL_APORT4XCH17,
   adcPosSelAPORT4YCH18 = _ADC_SINGLECTRL_POSSEL_APORT4YCH18,
   adcPosSelAPORT4XCH19 = _ADC_SINGLECTRL_POSSEL_APORT4XCH19,
   adcPosSelAPORT4YCH20 = _ADC_SINGLECTRL_POSSEL_APORT4YCH20,
   adcPosSelAPORT4XCH21 = _ADC_SINGLECTRL_POSSEL_APORT4XCH21,
   adcPosSelAPORT4YCH22 = _ADC_SINGLECTRL_POSSEL_APORT4YCH22,
   adcPosSelAPORT4XCH23 = _ADC_SINGLECTRL_POSSEL_APORT4XCH23,
   adcPosSelAPORT4YCH24 = _ADC_SINGLECTRL_POSSEL_APORT4YCH24,
   adcPosSelAPORT4XCH25 = _ADC_SINGLECTRL_POSSEL_APORT4XCH25,
   adcPosSelAPORT4YCH26 = _ADC_SINGLECTRL_POSSEL_APORT4YCH26,
   adcPosSelAPORT4XCH27 = _ADC_SINGLECTRL_POSSEL_APORT4XCH27,
   adcPosSelAPORT4YCH28 = _ADC_SINGLECTRL_POSSEL_APORT4YCH28,
   adcPosSelAPORT4XCH29 = _ADC_SINGLECTRL_POSSEL_APORT4XCH29,
   adcPosSelAPORT4YCH30 = _ADC_SINGLECTRL_POSSEL_APORT4YCH30,
   adcPosSelAPORT4XCH31 = _ADC_SINGLECTRL_POSSEL_APORT4XCH31,
   adcPosSelAVDD        = _ADC_SINGLECTRL_POSSEL_AVDD,
   adcPosSelDVDD        = _ADC_SINGLECTRL_POSSEL_AREG,
   adcPosSelPAVDD       = _ADC_SINGLECTRL_POSSEL_VREGOUTPA,
   adcPosSelDECOUPLE    = _ADC_SINGLECTRL_POSSEL_PDBU,
   adcPosSelIOVDD       = _ADC_SINGLECTRL_POSSEL_IO0,
   adcPosSelOPA2        = _ADC_SINGLECTRL_POSSEL_OPA2,
   adcPosSelOPA3        = _ADC_SINGLECTRL_POSSEL_OPA3,
   adcPosSelTEMP        = _ADC_SINGLECTRL_POSSEL_TEMP,
   adcPosSelDAC0OUT0    = _ADC_SINGLECTRL_POSSEL_DAC0OUT0,
   adcPosSelDAC0OUT1    = _ADC_SINGLECTRL_POSSEL_DAC0OUT1,
   adcPosSelSUBLSB      = _ADC_SINGLECTRL_POSSEL_SUBLSB,
   adcPosSelDEFAULT     = _ADC_SINGLECTRL_POSSEL_DEFAULT,
   adcPosSelVSS         = _ADC_SINGLECTRL_POSSEL_VSS
 } ADC_PosSel_TypeDef;

 /* Map legacy or incorrectly named select enums to correct enums. */
 #define adcPosSelIO0            adcPosSelIOVDD
 #define adcPosSelVREGOUTPA      adcPosSelPAVDD
 #define adcPosSelAREG           adcPosSelDVDD
 #define adcPosSelPDBU           adcPosSelDECOUPLE

 #endif


 #if defined( _ADC_SINGLECTRL_NEGSEL_MASK )

 typedef enum
 {
   adcNegSelAPORT0XCH0  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH0,
   adcNegSelAPORT0XCH1  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH1,
   adcNegSelAPORT0XCH2  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH2,
   adcNegSelAPORT0XCH3  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH3,
   adcNegSelAPORT0XCH4  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH4,
   adcNegSelAPORT0XCH5  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH5,
   adcNegSelAPORT0XCH6  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH6,
   adcNegSelAPORT0XCH7  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH7,
   adcNegSelAPORT0XCH8  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH8,
   adcNegSelAPORT0XCH9  = _ADC_SINGLECTRL_NEGSEL_APORT0XCH9,
   adcNegSelAPORT0XCH10 = _ADC_SINGLECTRL_NEGSEL_APORT0XCH10,
   adcNegSelAPORT0XCH11 = _ADC_SINGLECTRL_NEGSEL_APORT0XCH11,
   adcNegSelAPORT0XCH12 = _ADC_SINGLECTRL_NEGSEL_APORT0XCH12,
   adcNegSelAPORT0XCH13 = _ADC_SINGLECTRL_NEGSEL_APORT0XCH13,
   adcNegSelAPORT0XCH14 = _ADC_SINGLECTRL_NEGSEL_APORT0XCH14,
   adcNegSelAPORT0XCH15 = _ADC_SINGLECTRL_NEGSEL_APORT0XCH15,
   adcNegSelAPORT0YCH0  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH0,
   adcNegSelAPORT0YCH1  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH1,
   adcNegSelAPORT0YCH2  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH2,
   adcNegSelAPORT0YCH3  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH3,
   adcNegSelAPORT0YCH4  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH4,
   adcNegSelAPORT0YCH5  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH5,
   adcNegSelAPORT0YCH6  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH6,
   adcNegSelAPORT0YCH7  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH7,
   adcNegSelAPORT0YCH8  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH8,
   adcNegSelAPORT0YCH9  = _ADC_SINGLECTRL_NEGSEL_APORT0YCH9,
   adcNegSelAPORT0YCH10 = _ADC_SINGLECTRL_NEGSEL_APORT0YCH10,
   adcNegSelAPORT0YCH11 = _ADC_SINGLECTRL_NEGSEL_APORT0YCH11,
   adcNegSelAPORT0YCH12 = _ADC_SINGLECTRL_NEGSEL_APORT0YCH12,
   adcNegSelAPORT0YCH13 = _ADC_SINGLECTRL_NEGSEL_APORT0YCH13,
   adcNegSelAPORT0YCH14 = _ADC_SINGLECTRL_NEGSEL_APORT0YCH14,
   adcNegSelAPORT0YCH15 = _ADC_SINGLECTRL_NEGSEL_APORT0YCH15,
   adcNegSelAPORT1XCH0  = _ADC_SINGLECTRL_NEGSEL_APORT1XCH0,
   adcNegSelAPORT1YCH1  = _ADC_SINGLECTRL_NEGSEL_APORT1YCH1,
   adcNegSelAPORT1XCH2  = _ADC_SINGLECTRL_NEGSEL_APORT1XCH2,
   adcNegSelAPORT1YCH3  = _ADC_SINGLECTRL_NEGSEL_APORT1YCH3,
   adcNegSelAPORT1XCH4  = _ADC_SINGLECTRL_NEGSEL_APORT1XCH4,
   adcNegSelAPORT1YCH5  = _ADC_SINGLECTRL_NEGSEL_APORT1YCH5,
   adcNegSelAPORT1XCH6  = _ADC_SINGLECTRL_NEGSEL_APORT1XCH6,
   adcNegSelAPORT1YCH7  = _ADC_SINGLECTRL_NEGSEL_APORT1YCH7,
   adcNegSelAPORT1XCH8  = _ADC_SINGLECTRL_NEGSEL_APORT1XCH8,
   adcNegSelAPORT1YCH9  = _ADC_SINGLECTRL_NEGSEL_APORT1YCH9,
   adcNegSelAPORT1XCH10 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH10,
   adcNegSelAPORT1YCH11 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH11,
   adcNegSelAPORT1XCH12 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH12,
   adcNegSelAPORT1YCH13 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH13,
   adcNegSelAPORT1XCH14 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH14,
   adcNegSelAPORT1YCH15 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH15,
   adcNegSelAPORT1XCH16 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH16,
   adcNegSelAPORT1YCH17 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH17,
   adcNegSelAPORT1XCH18 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH18,
   adcNegSelAPORT1YCH19 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH19,
   adcNegSelAPORT1XCH20 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH20,
   adcNegSelAPORT1YCH21 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH21,
   adcNegSelAPORT1XCH22 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH22,
   adcNegSelAPORT1YCH23 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH23,
   adcNegSelAPORT1XCH24 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH24,
   adcNegSelAPORT1YCH25 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH25,
   adcNegSelAPORT1XCH26 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH26,
   adcNegSelAPORT1YCH27 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH27,
   adcNegSelAPORT1XCH28 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH28,
   adcNegSelAPORT1YCH29 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH29,
   adcNegSelAPORT1XCH30 = _ADC_SINGLECTRL_NEGSEL_APORT1XCH30,
   adcNegSelAPORT1YCH31 = _ADC_SINGLECTRL_NEGSEL_APORT1YCH31,
   adcNegSelAPORT2YCH0  = _ADC_SINGLECTRL_NEGSEL_APORT2YCH0,
   adcNegSelAPORT2XCH1  = _ADC_SINGLECTRL_NEGSEL_APORT2XCH1,
   adcNegSelAPORT2YCH2  = _ADC_SINGLECTRL_NEGSEL_APORT2YCH2,
   adcNegSelAPORT2XCH3  = _ADC_SINGLECTRL_NEGSEL_APORT2XCH3,
   adcNegSelAPORT2YCH4  = _ADC_SINGLECTRL_NEGSEL_APORT2YCH4,
   adcNegSelAPORT2XCH5  = _ADC_SINGLECTRL_NEGSEL_APORT2XCH5,
   adcNegSelAPORT2YCH6  = _ADC_SINGLECTRL_NEGSEL_APORT2YCH6,
   adcNegSelAPORT2XCH7  = _ADC_SINGLECTRL_NEGSEL_APORT2XCH7,
   adcNegSelAPORT2YCH8  = _ADC_SINGLECTRL_NEGSEL_APORT2YCH8,
   adcNegSelAPORT2XCH9  = _ADC_SINGLECTRL_NEGSEL_APORT2XCH9,
   adcNegSelAPORT2YCH10 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH10,
   adcNegSelAPORT2XCH11 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH11,
   adcNegSelAPORT2YCH12 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH12,
   adcNegSelAPORT2XCH13 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH13,
   adcNegSelAPORT2YCH14 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH14,
   adcNegSelAPORT2XCH15 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH15,
   adcNegSelAPORT2YCH16 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH16,
   adcNegSelAPORT2XCH17 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH17,
   adcNegSelAPORT2YCH18 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH18,
   adcNegSelAPORT2XCH19 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH19,
   adcNegSelAPORT2YCH20 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH20,
   adcNegSelAPORT2XCH21 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH21,
   adcNegSelAPORT2YCH22 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH22,
   adcNegSelAPORT2XCH23 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH23,
   adcNegSelAPORT2YCH24 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH24,
   adcNegSelAPORT2XCH25 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH25,
   adcNegSelAPORT2YCH26 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH26,
   adcNegSelAPORT2XCH27 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH27,
   adcNegSelAPORT2YCH28 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH28,
   adcNegSelAPORT2XCH29 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH29,
   adcNegSelAPORT2YCH30 = _ADC_SINGLECTRL_NEGSEL_APORT2YCH30,
   adcNegSelAPORT2XCH31 = _ADC_SINGLECTRL_NEGSEL_APORT2XCH31,
   adcNegSelAPORT3XCH0  = _ADC_SINGLECTRL_NEGSEL_APORT3XCH0,
   adcNegSelAPORT3YCH1  = _ADC_SINGLECTRL_NEGSEL_APORT3YCH1,
   adcNegSelAPORT3XCH2  = _ADC_SINGLECTRL_NEGSEL_APORT3XCH2,
   adcNegSelAPORT3YCH3  = _ADC_SINGLECTRL_NEGSEL_APORT3YCH3,
   adcNegSelAPORT3XCH4  = _ADC_SINGLECTRL_NEGSEL_APORT3XCH4,
   adcNegSelAPORT3YCH5  = _ADC_SINGLECTRL_NEGSEL_APORT3YCH5,
   adcNegSelAPORT3XCH6  = _ADC_SINGLECTRL_NEGSEL_APORT3XCH6,
   adcNegSelAPORT3YCH7  = _ADC_SINGLECTRL_NEGSEL_APORT3YCH7,
   adcNegSelAPORT3XCH8  = _ADC_SINGLECTRL_NEGSEL_APORT3XCH8,
   adcNegSelAPORT3YCH9  = _ADC_SINGLECTRL_NEGSEL_APORT3YCH9,
   adcNegSelAPORT3XCH10 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH10,
   adcNegSelAPORT3YCH11 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH11,
   adcNegSelAPORT3XCH12 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH12,
   adcNegSelAPORT3YCH13 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH13,
   adcNegSelAPORT3XCH14 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH14,
   adcNegSelAPORT3YCH15 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH15,
   adcNegSelAPORT3XCH16 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH16,
   adcNegSelAPORT3YCH17 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH17,
   adcNegSelAPORT3XCH18 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH18,
   adcNegSelAPORT3YCH19 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH19,
   adcNegSelAPORT3XCH20 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH20,
   adcNegSelAPORT3YCH21 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH21,
   adcNegSelAPORT3XCH22 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH22,
   adcNegSelAPORT3YCH23 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH23,
   adcNegSelAPORT3XCH24 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH24,
   adcNegSelAPORT3YCH25 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH25,
   adcNegSelAPORT3XCH26 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH26,
   adcNegSelAPORT3YCH27 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH27,
   adcNegSelAPORT3XCH28 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH28,
   adcNegSelAPORT3YCH29 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH29,
   adcNegSelAPORT3XCH30 = _ADC_SINGLECTRL_NEGSEL_APORT3XCH30,
   adcNegSelAPORT3YCH31 = _ADC_SINGLECTRL_NEGSEL_APORT3YCH31,
   adcNegSelAPORT4YCH0  = _ADC_SINGLECTRL_NEGSEL_APORT4YCH0,
   adcNegSelAPORT4XCH1  = _ADC_SINGLECTRL_NEGSEL_APORT4XCH1,
   adcNegSelAPORT4YCH2  = _ADC_SINGLECTRL_NEGSEL_APORT4YCH2,
   adcNegSelAPORT4XCH3  = _ADC_SINGLECTRL_NEGSEL_APORT4XCH3,
   adcNegSelAPORT4YCH4  = _ADC_SINGLECTRL_NEGSEL_APORT4YCH4,
   adcNegSelAPORT4XCH5  = _ADC_SINGLECTRL_NEGSEL_APORT4XCH5,
   adcNegSelAPORT4YCH6  = _ADC_SINGLECTRL_NEGSEL_APORT4YCH6,
   adcNegSelAPORT4XCH7  = _ADC_SINGLECTRL_NEGSEL_APORT4XCH7,
   adcNegSelAPORT4YCH8  = _ADC_SINGLECTRL_NEGSEL_APORT4YCH8,
   adcNegSelAPORT4XCH9  = _ADC_SINGLECTRL_NEGSEL_APORT4XCH9,
   adcNegSelAPORT4YCH10 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH10,
   adcNegSelAPORT4XCH11 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH11,
   adcNegSelAPORT4YCH12 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH12,
   adcNegSelAPORT4XCH13 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH13,
   adcNegSelAPORT4YCH14 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH14,
   adcNegSelAPORT4XCH15 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH15,
   adcNegSelAPORT4YCH16 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH16,
   adcNegSelAPORT4XCH17 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH17,
   adcNegSelAPORT4YCH18 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH18,
   adcNegSelAPORT4XCH19 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH19,
   adcNegSelAPORT4YCH20 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH20,
   adcNegSelAPORT4XCH21 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH21,
   adcNegSelAPORT4YCH22 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH22,
   adcNegSelAPORT4XCH23 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH23,
   adcNegSelAPORT4YCH24 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH24,
   adcNegSelAPORT4XCH25 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH25,
   adcNegSelAPORT4YCH26 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH26,
   adcNegSelAPORT4XCH27 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH27,
   adcNegSelAPORT4YCH28 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH28,
   adcNegSelAPORT4XCH29 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH29,
   adcNegSelAPORT4YCH30 = _ADC_SINGLECTRL_NEGSEL_APORT4YCH30,
   adcNegSelAPORT4XCH31 = _ADC_SINGLECTRL_NEGSEL_APORT4XCH31,
   adcNegSelTESTN       = _ADC_SINGLECTRL_NEGSEL_TESTN,
   adcNegSelDEFAULT     = _ADC_SINGLECTRL_NEGSEL_DEFAULT,
   adcNegSelVSS         = _ADC_SINGLECTRL_NEGSEL_VSS
 } ADC_NegSel_TypeDef;
 #endif


 #if defined( _ADC_SCANINPUTSEL_MASK )
   /* ADC scan input groups */
 typedef enum
 {
   adcScanInputGroup0 = 0,
   adcScanInputGroup1 = 1,
   adcScanInputGroup2 = 2,
   adcScanInputGroup3 = 3,
 } ADC_ScanInputGroup_TypeDef;

 /* Define none selected for ADC_SCANINPUTSEL */
 #define ADC_SCANINPUTSEL_GROUP_NONE     0xFFU
 #define ADC_SCANINPUTSEL_NONE           ((ADC_SCANINPUTSEL_GROUP_NONE                   \
                                           << _ADC_SCANINPUTSEL_INPUT0TO7SEL_SHIFT)      \
                                          | (ADC_SCANINPUTSEL_GROUP_NONE                 \
                                             << _ADC_SCANINPUTSEL_INPUT8TO15SEL_SHIFT)   \
                                          | (ADC_SCANINPUTSEL_GROUP_NONE                 \
                                             << _ADC_SCANINPUTSEL_INPUT16TO23SEL_SHIFT)  \
                                          | (ADC_SCANINPUTSEL_GROUP_NONE                 \
                                             << _ADC_SCANINPUTSEL_INPUT24TO31SEL_SHIFT))

   /* ADC scan alternative negative inputs */
 typedef enum
 {
   adcScanNegInput1  = 1,
   adcScanNegInput3  = 3,
   adcScanNegInput5  = 5,
   adcScanNegInput7  = 7,
   adcScanNegInput8  = 8,
   adcScanNegInput10 = 10,
   adcScanNegInput12 = 12,
   adcScanNegInput14 = 14,
   adcScanNegInputDefault = 0xFF,
 } ADC_ScanNegInput_TypeDef;
 #endif


 typedef enum
 {
   adcStartSingle        = ADC_CMD_SINGLESTART,

   adcStartScan          = ADC_CMD_SCANSTART,

   adcStartScanAndSingle = ADC_CMD_SCANSTART | ADC_CMD_SINGLESTART
 } ADC_Start_TypeDef;


 typedef enum
 {
   adcWarmupNormal          = _ADC_CTRL_WARMUPMODE_NORMAL,

 #if defined( _ADC_CTRL_WARMUPMODE_FASTBG )

   adcWarmupFastBG          = _ADC_CTRL_WARMUPMODE_FASTBG,
 #endif

 #if defined( _ADC_CTRL_WARMUPMODE_KEEPSCANREFWARM )

   adcWarmupKeepScanRefWarm = _ADC_CTRL_WARMUPMODE_KEEPSCANREFWARM,
 #endif

 #if defined( _ADC_CTRL_WARMUPMODE_KEEPINSTANDBY )

   adcWarmupKeepInStandby   = _ADC_CTRL_WARMUPMODE_KEEPINSTANDBY,
 #endif

 #if defined( _ADC_CTRL_WARMUPMODE_KEEPINSLOWACC )

   adcWarmupKeepInSlowAcq   = _ADC_CTRL_WARMUPMODE_KEEPINSLOWACC,
 #endif

   adcWarmupKeepADCWarm     = _ADC_CTRL_WARMUPMODE_KEEPADCWARM,

 } ADC_Warmup_TypeDef;


 #if defined( _ADC_CTRL_ADCCLKMODE_MASK )

 typedef enum
 {
   adcEm2Disabled           = 0,
   adcEm2ClockOnDemand      = ADC_CTRL_ADCCLKMODE_ASYNC | ADC_CTRL_ASYNCCLKEN_ASNEEDED,
   adcEm2ClockAlwaysOn      = ADC_CTRL_ADCCLKMODE_ASYNC | ADC_CTRL_ASYNCCLKEN_ALWAYSON,
 } ADC_EM2ClockConfig_TypeDef;
 #endif


 /*******************************************************************************
  *******************************   STRUCTS   ***********************************
  ******************************************************************************/

 typedef struct
 {
   ADC_OvsRateSel_TypeDef        ovsRateSel;

 #if defined( _ADC_CTRL_LPFMODE_MASK )

   ADC_LPFilter_TypeDef          lpfMode;
 #endif

   ADC_Warmup_TypeDef            warmUpMode;

   uint8_t                       timebase;

   uint8_t                       prescale;

   bool                          tailgate;

 #if defined( _ADC_CTRL_ADCCLKMODE_MASK )
   ADC_EM2ClockConfig_TypeDef    em2ClockConfig;
 #endif
 } ADC_Init_TypeDef;


 #if defined( _ADC_CTRL_LPFMODE_MASK ) && (!defined( _ADC_CTRL_ADCCLKMODE_MASK ))
 #define ADC_INIT_DEFAULT                                                      \
 {                                                                             \
   adcOvsRateSel2,                /* 2x oversampling (if enabled). */          \
   adcLPFilterBypass,             /* No input filter selected. */              \
   adcWarmupNormal,               /* ADC shutdown after each conversion. */    \
   _ADC_CTRL_TIMEBASE_DEFAULT,    /* Use HW default value. */                  \
   _ADC_CTRL_PRESC_DEFAULT,       /* Use HW default value. */                  \
   false                          /* Do not use tailgate. */                   \
 }
 #elif (!defined( _ADC_CTRL_LPFMODE_MASK )) && (!defined( _ADC_CTRL_ADCCLKMODE_MASK ))
 #define ADC_INIT_DEFAULT                                                      \
 {                                                                             \
   adcOvsRateSel2,                /* 2x oversampling (if enabled). */          \
   adcWarmupNormal,               /* ADC shutdown after each conversion. */    \
   _ADC_CTRL_TIMEBASE_DEFAULT,    /* Use HW default value. */                  \
   _ADC_CTRL_PRESC_DEFAULT,       /* Use HW default value. */                  \
   false                          /* Do not use tailgate. */                   \
 }
 #elif (!defined( _ADC_CTRL_LPFMODE_MASK )) && defined( _ADC_CTRL_ADCCLKMODE_MASK )
 #define ADC_INIT_DEFAULT                                                      \
 {                                                                             \
   adcOvsRateSel2,                /* 2x oversampling (if enabled). */          \
   adcWarmupNormal,               /* ADC shutdown after each conversion. */    \
   _ADC_CTRL_TIMEBASE_DEFAULT,    /* Use HW default value. */                  \
   _ADC_CTRL_PRESC_DEFAULT,       /* Use HW default value. */                  \
   false,                         /* Do not use tailgate. */                   \
   adcEm2Disabled                 /* ADC disabled in EM2 */                    \
 }
 #endif


 typedef struct
 {
   uint32_t            scanInputSel;

   uint32_t            scanInputEn;

   uint32_t            scanNegSel;
 } ADC_InitScanInput_TypeDef;


 typedef struct
 {
   ADC_PRSSEL_TypeDef  prsSel;

   ADC_AcqTime_TypeDef acqTime;

   ADC_Ref_TypeDef     reference;

   ADC_Res_TypeDef     resolution;

 #if defined( _ADC_SCANCTRL_INPUTMASK_MASK )

   uint32_t            input;
 #endif

 #if defined( _ADC_SCANINPUTSEL_MASK )

   ADC_InitScanInput_TypeDef scanInputConfig;
 #endif

   bool                diff;

   bool                prsEnable;

   bool                leftAdjust;

   bool                rep;

 #if defined( _ADC_CTRL_SCANDMAWU_MASK )
   bool                scanDmaEm2Wu;
 #endif

 #if defined( _ADC_SCANCTRLX_FIFOOFACT_MASK )

   bool                fifoOverwrite;
 #endif
 } ADC_InitScan_TypeDef;

 #if defined( _ADC_SCANCTRL_INPUTMASK_MASK )
 #define ADC_INITSCAN_DEFAULT                                                      \
 {                                                                                 \
   adcPRSSELCh0,              /* PRS ch0 (if enabled). */                          \
   adcAcqTime1,               /* 1 ADC_CLK cycle acquisition time. */              \
   adcRef1V25,                /* 1.25V internal reference. */                      \
   adcRes12Bit,               /* 12 bit resolution. */                             \
   0,                         /* No input selected. */                             \
   false,                     /* Single-ended input. */                            \
   false,                     /* PRS disabled. */                                  \
   false,                     /* Right adjust. */                                  \
   false,                     /* Deactivate conversion after one scan sequence. */ \
 }
 #endif

 #if defined( _ADC_SCANINPUTSEL_MASK )
 #define ADC_INITSCAN_DEFAULT                                                      \
 {                                                                                 \
   adcPRSSELCh0,              /* PRS ch0 (if enabled). */                          \
   adcAcqTime1,               /* 1 ADC_CLK cycle acquisition time. */              \
   adcRef1V25,                /* 1.25V internal reference. */                      \
   adcRes12Bit,               /* 12 bit resolution. */                             \
   {                                                                               \
     /* Initialization should match values set by @ref ADC_ScanInputClear() */     \
     ADC_SCANINPUTSEL_NONE,   /* Default ADC inputs */                             \
     0,                       /* Default input mask (all off) */                   \
     _ADC_SCANNEGSEL_RESETVALUE,/* Default negative select for positive ternimal */\
   },                                                                              \
   false,                     /* Single-ended input. */                            \
   false,                     /* PRS disabled. */                                  \
   false,                     /* Right adjust. */                                  \
   false,                     /* Deactivate conversion after one scan sequence. */ \
   false,                     /* No EM2 DMA wakeup from scan FIFO DVL */           \
   false                      /* Discard new data on full FIFO. */                 \
 }
 #endif


 typedef struct
 {
   ADC_PRSSEL_TypeDef            prsSel;

   ADC_AcqTime_TypeDef           acqTime;

   ADC_Ref_TypeDef               reference;

   ADC_Res_TypeDef               resolution;

 #if defined( _ADC_SINGLECTRL_INPUTSEL_MASK )

   ADC_SingleInput_TypeDef       input;
 #endif

 #if defined( _ADC_SINGLECTRL_POSSEL_MASK )

   ADC_PosSel_TypeDef            posSel;
 #endif

 #if defined( _ADC_SINGLECTRL_NEGSEL_MASK )

   ADC_NegSel_TypeDef            negSel;
 #endif

   bool                          diff;

   bool                          prsEnable;

   bool                          leftAdjust;

   bool                          rep;

 #if defined( _ADC_CTRL_SINGLEDMAWU_MASK )

   bool                          singleDmaEm2Wu;
 #endif

 #if defined( _ADC_SINGLECTRLX_FIFOOFACT_MASK )

   bool                          fifoOverwrite;
 #endif
 } ADC_InitSingle_TypeDef;

 #if defined( _ADC_SINGLECTRL_INPUTSEL_MASK )
 #define ADC_INITSINGLE_DEFAULT                                                    \
 {                                                                                 \
   adcPRSSELCh0,              /* PRS ch0 (if enabled). */                          \
   adcAcqTime1,               /* 1 ADC_CLK cycle acquisition time. */              \
   adcRef1V25,                /* 1.25V internal reference. */                      \
   adcRes12Bit,               /* 12 bit resolution. */                             \
   adcSingleInpCh0,           /* CH0 input selected. */                            \
   false,                     /* Single ended input. */                            \
   false,                     /* PRS disabled. */                                  \
   false,                     /* Right adjust. */                                  \
   false                      /* Deactivate conversion after one scan sequence. */ \
 }
 #else
 #define ADC_INITSINGLE_DEFAULT                                                    \
 {                                                                                 \
   adcPRSSELCh0,              /* PRS ch0 (if enabled). */                          \
   adcAcqTime1,               /* 1 ADC_CLK cycle acquisition time. */              \
   adcRef1V25,                /* 1.25V internal reference. */                      \
   adcRes12Bit,               /* 12 bit resolution. */                             \
   adcPosSelAPORT0XCH0,       /* Select node BUS0XCH0 as posSel */                 \
   adcNegSelVSS,              /* Select VSS as negSel */                           \
   false,                     /* Single ended input. */                            \
   false,                     /* PRS disabled. */                                  \
   false,                     /* Right adjust. */                                  \
   false,                     /* Deactivate conversion after one scan sequence. */ \
   false,                     /* No EM2 DMA wakeup from single FIFO DVL */         \
   false                      /* Discard new data on full FIFO. */                 \
 }
 #endif

 /*******************************************************************************
  *****************************   PROTOTYPES   **********************************
  ******************************************************************************/

 /***************************************************************************/
 __STATIC_INLINE uint32_t ADC_DataSingleGet(ADC_TypeDef *adc)
 {
   return adc->SINGLEDATA;
 }


 /***************************************************************************/
 __STATIC_INLINE uint32_t ADC_DataSinglePeek(ADC_TypeDef *adc)
 {
   return adc->SINGLEDATAP;
 }


 /***************************************************************************/
 __STATIC_INLINE uint32_t ADC_DataScanGet(ADC_TypeDef *adc)
 {
   return adc->SCANDATA;
 }


 /***************************************************************************/
 __STATIC_INLINE uint32_t ADC_DataScanPeek(ADC_TypeDef *adc)
 {
   return adc->SCANDATAP;
 }


 #if defined( _ADC_SCANDATAX_MASK )
 uint32_t ADC_DataIdScanGet(ADC_TypeDef *adc, uint32_t *scanId);
 #endif

 void ADC_Init(ADC_TypeDef *adc, const ADC_Init_TypeDef *init);
 void ADC_Reset(ADC_TypeDef *adc);
 void ADC_InitScan(ADC_TypeDef *adc, const ADC_InitScan_TypeDef *init);

 #if defined( _ADC_SCANINPUTSEL_MASK )
 void ADC_ScanInputClear(ADC_InitScan_TypeDef *scanInit);
 uint32_t ADC_ScanSingleEndedInputAdd(ADC_InitScan_TypeDef *scanInit,
                                      ADC_ScanInputGroup_TypeDef inputGroup,
                                      ADC_PosSel_TypeDef singleEndedSel);
 uint32_t ADC_ScanDifferentialInputAdd(ADC_InitScan_TypeDef *scanInit,
                                       ADC_ScanInputGroup_TypeDef inputGroup,
                                       ADC_PosSel_TypeDef posSel,
                                       ADC_ScanNegInput_TypeDef adcScanNegInput);
 #endif

 void ADC_InitSingle(ADC_TypeDef *adc, const ADC_InitSingle_TypeDef *init);
 uint8_t ADC_TimebaseCalc(uint32_t hfperFreq);
 uint8_t ADC_PrescaleCalc(uint32_t adcFreq, uint32_t hfperFreq);


 /***************************************************************************/
 __STATIC_INLINE void ADC_IntClear(ADC_TypeDef *adc, uint32_t flags)
 {
   adc->IFC = flags;
 }


 /***************************************************************************/
 __STATIC_INLINE void ADC_IntDisable(ADC_TypeDef *adc, uint32_t flags)
 {
   adc->IEN &= ~flags;
 }


 /***************************************************************************/
 __STATIC_INLINE void ADC_IntEnable(ADC_TypeDef *adc, uint32_t flags)
 {
   adc->IEN |= flags;
 }


 /***************************************************************************/
 __STATIC_INLINE uint32_t ADC_IntGet(ADC_TypeDef *adc)
 {
   return adc->IF;
 }


 /***************************************************************************/
 __STATIC_INLINE uint32_t ADC_IntGetEnabled(ADC_TypeDef *adc)
 {
   uint32_t ien;

   /* Store ADCx->IEN in temporary variable in order to define explicit order
    * of volatile accesses. */
   ien = adc->IEN;

   /* Bitwise AND of pending and enabled interrupts */
   return adc->IF & ien;
 }


 /***************************************************************************/
 __STATIC_INLINE void ADC_IntSet(ADC_TypeDef *adc, uint32_t flags)
 {
   adc->IFS = flags;
 }


 /***************************************************************************/
 __STATIC_INLINE void ADC_Start(ADC_TypeDef *adc, ADC_Start_TypeDef cmd)
 {
   adc->CMD = (uint32_t)cmd;
 }


 #ifdef __cplusplus
 }
 #endif

 #endif /* defined(ADC_COUNT) && (ADC_COUNT > 0) */
//#endif /* EM_ADC_H */


#endif /* PLATFORM_EMLIB_INC_EM_ADC_H_ */
