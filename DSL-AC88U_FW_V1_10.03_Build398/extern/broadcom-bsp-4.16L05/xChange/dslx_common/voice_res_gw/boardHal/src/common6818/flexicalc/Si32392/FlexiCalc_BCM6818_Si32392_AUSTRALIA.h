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
*       BCM6818                          
*       SLIC = Silicon Labs Si32392      
*       R1 = 220 ohms
*       R2 = 820 ohms
*       C1 = 115 nano Farads 
*       DLP = -9dB
*       ELP = -3dB
*       HWDACgain = 0dB
*       HW_impedance = 680 ohms
*       Protection resistor = 10 ohms
*       Ringing frequency = 25 hertz
*       Ringing amplitude = 45Vrms
*
*    Flexicalc Version: 3.7
*
****************************************************************************/

#ifndef FLEXICALC_AUSTRALIA_32392_H
#define FLEXICALC_AUSTRALIA_32392_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
** Flexicalc Values Structure                                              **
****************************************************************************/

#if !VRG_COUNTRY_CFG_AUSTRALIA
#define flexicalcAUSTRALIAArchive32392 ((const APM6818_FLEXICALC_CFG*) NULL)
#else
const APM6818_FLEXICALC_CFG flexicalcAUSTRALIAArchive32392[] =
{
{
   0x32392,          /* Slic type: Si32392 */
   45,               /* Ring Voltage (RMS) */
   -9,               /* DLP - Decode Level Point (receive loss) in dB */
   -3,               /* ELP - Encode Level Point (transmitt loss) in dB */
   0x0007,           /* eq_rx_shft */
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
      0x2D6A5,   /* YFIR1_VAL */
      0xA714D,   /* YFIR2_VAL */
      0x1867B,   /* YFIR3_VAL */
      0x20387,   /* YFIR4_VAL */
      0xFD671,   /* YFIR5_VAL */
      0xE9E42,   /* YFIR6_VAL */
      0xF5E1C,   /* YFIR7_VAL */
      0x0A17C,   /* YFIR8_VAL */
      0x0D612,   /* YFIR9_VAL */
      0x0049D,   /* YFIR10_VAL */
      0xF6400,   /* YFIR11_VAL */
      0xFB433,   /* YFIR12_VAL */
      0x06B9E,   /* YFIR13_VAL */
      0x08444,   /* YFIR14_VAL */
      0xFE134,   /* YFIR15_VAL */
      0xF87AD,   /* YFIR16_VAL */
      0x055EB,   /* YFIR17_VAL */
      0xFCFCF    /* YFIR18_VAL */
   },
   0x06,               /* y_fir_filter_shift */
   0x7FFFF,            /* yfltr_gain */
   {0x48C25},          /* y_iir1_filter[1] */
   0x96,               /* y_iir1_filter_shift */

   /* Hybrid Balance Coefficients */
   7,                  /* hybal_shft */
   {0x5476, 0x8327, 0x63C0, 0x8326, 0x5332},    /* hybal_audio_fir[5] */
   {0x0000, 0x0000, 0x0000, 0x0000, 0x0000},    /* hybal_pm_fir[5] */
   1,                  /* hybal_en */

   {  /* Rx Equalization Coefficents */
      0x54F8, 0xD8C0, 0x093D, 0xF9BD, 0x0215, 0xFDDB, 0x007C, 0xFEC0,
      0x0018, 0xFF1E, 0xFFF5, 0xFF62, 0xFFEE, 0xFF8B, 0xFFF3, 0xFFAC,
      0xFFF8, 0xFFC1, 0x0002, 0xFFCF, 0x0000, 0xFFDE, 0x0006, 0xFFDD,
      0xFFFF, 0xFFE6, 0xFFFE, 0xFFE6, 0x0000, 0xFFEB, 0xFFFA, 0xFFEF,
      0xFFFD, 0xFFEC, 0x0000, 0xFFF0, 0xFFFF, 0xFFF5, 0x0004, 0xFFF6,
      0x0005, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
   },

   {  /* Tx Equalization Coefficents */
      0x41ED, 0xFAFB, 0x00FE, 0xFE08, 0xFFE3, 0xFF6A, 0xFFD6, 0xFF9C,
      0xFFD3, 0xFFB4, 0xFFD6, 0xFFC7, 0xFFDF, 0xFFD5, 0xFFEA, 0xFFE0,
      0xFFF3, 0xFFE9, 0xFFF8, 0xFFEE, 0xFFF8, 0xFFF4, 0xFFFB, 0xFFF4,
      0xFFFB, 0xFFF6, 0xFFF8, 0xFFF7, 0xFFFA, 0xFFF8, 0xFFFB, 0xFFF9,
      0xFFFC, 0xFFF9, 0xFFFE, 0xFFFB, 0xFFFE, 0xFFFC, 0x0000, 0xFFFE,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
   },

   0x0004,           /* cic_int_shft */
   0x0004,           /* cic_dec_shft */
   0x75C5,           /* asrc_int_scale */
   0x0846,           /* asrc_dec_scale */
   2,                /* vtx_pg */
   1,                /* vrx_pg */
   0,                /* hpf_en */
   6,                /* hybal_smpl_offset */

}
};
#endif

#ifdef __cplusplus
}
#endif

#endif  /* FLEXICALC_AUSTRALIA_32392_H */
