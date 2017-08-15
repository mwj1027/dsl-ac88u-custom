/***************************************************************************
*    Copyright (c) 2000-2011 Broadcom                             
*                                                                           
*    This program is the proprietary software of Broadcom and/or
*    its licensors, and may only be used, duplicated, modified or           
*    distributed pursuant to the terms and conditions of a separate, written
*    license agreement executed between you and Broadcom (an Authorized     
*    License).  Except as set forth in an Authorized License, Broadcom      
*    grants no license (express or implied), right to use, or waiver of any 
*    kind with respect to the Software, and Broadcom expressly reserves all 
*    rights in and to the Software and all intellectual property rights     
*    therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO 
*    USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM   
*    AND DISCONTINUE ALL USE OF THE SOFTWARE.                               
*                                                                           
*                                                                           
*    Except as expressly set forth in the Authorized License,               
*                                                                           
*    1.     This program, including its structure, sequence and             
*    organization, constitutes the valuable trade secrets of Broadcom, and  
*    you shall use all reasonable efforts to protect the confidentiality    
*    thereof, and to use this information only in connection with your use  
*    of Broadcom integrated circuit products.                               
*                                                                           
*    2.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED
*    AS IS AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,              
*    REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR  
*    OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY        
*    DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,    
*    NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,    
*    ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR         
*    CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT  
*    OF USE OR PERFORMANCE OF THE SOFTWARE.                                 
*                                                                           
*    3.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL       
*    BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, 
*    SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN
*    ANY WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN  
*    IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR    
*    (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE 
*    ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY 
*    NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
*
****************************************************************************
*
*    Filename: FlexiCalc.h
*
****************************************************************************
*    Description:
*
*    FlexiCalc output constants for the following inputs:
*
*       BCM6828                          
*       SLIC = Zarlink L9530            
*       R1 = 220 ohms
*       R2 = 820 ohms
*       C1 = 115 nano Farads 
*       DLP = -11dB
*       ELP = -4dB
*       HWDACgain = 0dB
*       HW_impedance = 600 ohms
*       Protection resistor = 50 ohms
*       Ringing frequency = 25 hertz
*       Ringing amplitude = 45Vrms
*
*    Flexicalc Version: 3.7
*
****************************************************************************/

#ifndef FLEXICALC_SWITZERLAND_9530_H
#define FLEXICALC_SWITZERLAND_9530_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
** Flexicalc Values Structure                                              **
****************************************************************************/

#if !VRG_COUNTRY_CFG_SWITZERLAND
#define flexicalcSWITZERLANDArchive9530 ((const APM6828_FLEXICALC_CFG*) NULL)
#else
const APM6828_FLEXICALC_CFG flexicalcSWITZERLANDArchive9530[] =
{
{
   0x9530,           /* Slic type: L9530 */
   45,               /* Ring Voltage (RMS) */
   -11,               /* DLP - Decode Level Point (receive loss) in dB */
   -4,               /* ELP - Encode Level Point (transmitt loss) in dB */
   0x0006,           /* eq_rx_shft */
   0x000B,           /* eq_tx_shft */
   0,                /* eq_imp_resp */

   /*
   ** Y-filter Coefficients
   */
   1,                /* yfltr_en */
   {  /* IIR 2 Filter Coefficients */
      0x04966,   /* Y IIR2 filter b0 */
      0x061FA,   /* Y IIR2 filter b1 */
      0x04966,   /* Y IIR2 filter b2 */
      0x4E1DC,   /* Y IIR2 filter a1 */
      0xE28AB    /* Y IIR2 filter a2 */
   },
   0x77,             /* y_iir2_filter_shift */
   {  /* Fir Filter Coefficients */
      0xD9EFA,   /* YFIR1_VAL */
      0x4CB88,   /* YFIR2_VAL */
      0xE3CB9,   /* YFIR3_VAL */
      0xE5F1D,   /* YFIR4_VAL */
      0x0709C,   /* YFIR5_VAL */
      0x12529,   /* YFIR6_VAL */
      0x04007,   /* YFIR7_VAL */
      0xF4C9B,   /* YFIR8_VAL */
      0xF6C56,   /* YFIR9_VAL */
      0x03888,   /* YFIR10_VAL */
      0x094F3,   /* YFIR11_VAL */
      0x01DE8,   /* YFIR12_VAL */
      0xF87AE,   /* YFIR13_VAL */
      0xFA5B6,   /* YFIR14_VAL */
      0x04D38,   /* YFIR15_VAL */
      0x074CE,   /* YFIR16_VAL */
      0xF7A99,   /* YFIR17_VAL */
      0x0324D    /* YFIR18_VAL */
   },
   0x06,               /* y_fir_filter_shift */
   0x7FFFF,            /* yfltr_gain */
   {0x6BB39},          /* y_iir1_filter[1] */
   0xA6,               /* y_iir1_filter_shift */

   /* Hybrid Balance Coefficients */
   4,                  /* hybal_shft */
   {0x4F1C, 0x28DB, 0xAC57, 0x6721, 0x94B8},    /* hybal_audio_fir[5] */
   {0x0000, 0x0000, 0x0000, 0x0000, 0x0000},    /* hybal_pm_fir[5] */
   1,                  /* hybal_en */

   {  /* Rx Equalization Coefficents */
      0x7AAC, 0x0413, 0xFA5E, 0x008F, 0xFB93, 0xFF0F, 0xFD2E, 0xFEAF,
      0xFDDD, 0xFEBA, 0xFE57, 0xFEDE, 0xFEBE, 0xFF10, 0xFF0B, 0xFF50,
      0xFF49, 0xFF7D, 0xFF78, 0xFFA4, 0xFF8F, 0xFFBB, 0xFFA6, 0xFFC6,
      0xFFB2, 0xFFCE, 0xFFB9, 0xFFCC, 0xFFC2, 0xFFCD, 0xFFC8, 0xFFD1,
      0xFFD3, 0xFFDE, 0xFFD9, 0xFFEB, 0xFFE4, 0xFFF4, 0xFFEF, 0xFFFE,
      0xFFF8, 0x0004, 0x0005, 0x0004, 0x0004, 0x0003, 0x0003, 0x0002,
      0x0002, 0x0002, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
      0x0001, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
   },

   {  /* Tx Equalization Coefficents */
      0x5F3C, 0x280D, 0x051A, 0x0301, 0xFDDB, 0xFF57, 0xFE27, 0xFF14,
      0xFE86, 0xFF25, 0xFEDE, 0xFF42, 0xFF1C, 0xFF6C, 0xFF56, 0xFF8C,
      0xFF80, 0xFFB0, 0xFF9A, 0xFFBF, 0xFFAF, 0xFFD5, 0xFFC1, 0xFFD3,
      0xFFC7, 0xFFDA, 0xFFCC, 0xFFD8, 0xFFCE, 0xFFDA, 0xFFD5, 0xFFE1,
      0xFFDD, 0xFFE9, 0xFFE3, 0xFFF0, 0xFFEC, 0xFFF8, 0xFFF2, 0x0000,
      0xFFFA, 0x0000, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
      0x0001, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
   },

   0x0004,           /* cic_int_shft */
   0x0004,           /* cic_dec_shft */
   0x7E4F,           /* asrc_int_scale */
   0x0A1E,           /* asrc_dec_scale */
   0,                /* vtx_pg */
   1,                /* vrx_pg */
   0,                /* hpf_en */
   4,                /* hybal_smpl_offset */

}
};
#endif

#ifdef __cplusplus
}
#endif

#endif  /* FLEXICALC_SWITZERLAND_9530_H */