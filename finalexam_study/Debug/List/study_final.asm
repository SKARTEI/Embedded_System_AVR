
;CodeVisionAVR C Compiler V3.28 Evaluation
;(C) Copyright 1998-2016 Pavel Haiduc, HP InfoTech s.r.l.
;http://www.hpinfotech.com

;Build configuration    : Debug
;Chip type              : ATmega128
;Program type           : Application
;Clock frequency        : 16.000000 MHz
;Memory model           : Small
;Optimize for           : Size
;(s)printf features     : int, width
;(s)scanf features      : int, width
;External RAM size      : 0
;Data Stack size        : 1024 byte(s)
;Heap size              : 0 byte(s)
;Promote 'char' to 'int': Yes
;'char' is unsigned     : Yes
;8 bit enums            : Yes
;Global 'const' stored in FLASH: No
;Enhanced function parameter passing: Mode 2
;Enhanced core instructions: On
;Automatic register allocation for global variables: On
;Smart register allocation: On

	#define _MODEL_SMALL_

	#pragma AVRPART ADMIN PART_NAME ATmega128
	#pragma AVRPART MEMORY PROG_FLASH 131072
	#pragma AVRPART MEMORY EEPROM 4096
	#pragma AVRPART MEMORY INT_SRAM SIZE 4096
	#pragma AVRPART MEMORY INT_SRAM START_ADDR 0x100

	#define CALL_SUPPORTED 1

	.LISTMAC
	.EQU UDRE=0x5
	.EQU RXC=0x7
	.EQU USR=0xB
	.EQU UDR=0xC
	.EQU SPSR=0xE
	.EQU SPDR=0xF
	.EQU EERE=0x0
	.EQU EEWE=0x1
	.EQU EEMWE=0x2
	.EQU EECR=0x1C
	.EQU EEDR=0x1D
	.EQU EEARL=0x1E
	.EQU EEARH=0x1F
	.EQU WDTCR=0x21
	.EQU MCUCR=0x35
	.EQU RAMPZ=0x3B
	.EQU SPL=0x3D
	.EQU SPH=0x3E
	.EQU SREG=0x3F
	.EQU XMCRA=0x6D
	.EQU XMCRB=0x6C

	.DEF R0X0=R0
	.DEF R0X1=R1
	.DEF R0X2=R2
	.DEF R0X3=R3
	.DEF R0X4=R4
	.DEF R0X5=R5
	.DEF R0X6=R6
	.DEF R0X7=R7
	.DEF R0X8=R8
	.DEF R0X9=R9
	.DEF R0XA=R10
	.DEF R0XB=R11
	.DEF R0XC=R12
	.DEF R0XD=R13
	.DEF R0XE=R14
	.DEF R0XF=R15
	.DEF R0X10=R16
	.DEF R0X11=R17
	.DEF R0X12=R18
	.DEF R0X13=R19
	.DEF R0X14=R20
	.DEF R0X15=R21
	.DEF R0X16=R22
	.DEF R0X17=R23
	.DEF R0X18=R24
	.DEF R0X19=R25
	.DEF R0X1A=R26
	.DEF R0X1B=R27
	.DEF R0X1C=R28
	.DEF R0X1D=R29
	.DEF R0X1E=R30
	.DEF R0X1F=R31

	.EQU __SRAM_START=0x0100
	.EQU __SRAM_END=0x10FF
	.EQU __DSTACK_SIZE=0x0400
	.EQU __HEAP_SIZE=0x0000
	.EQU __CLEAR_SRAM_SIZE=__SRAM_END-__SRAM_START+1

	.MACRO __CPD1N
	CPI  R30,LOW(@0)
	LDI  R26,HIGH(@0)
	CPC  R31,R26
	LDI  R26,BYTE3(@0)
	CPC  R22,R26
	LDI  R26,BYTE4(@0)
	CPC  R23,R26
	.ENDM

	.MACRO __CPD2N
	CPI  R26,LOW(@0)
	LDI  R30,HIGH(@0)
	CPC  R27,R30
	LDI  R30,BYTE3(@0)
	CPC  R24,R30
	LDI  R30,BYTE4(@0)
	CPC  R25,R30
	.ENDM

	.MACRO __CPWRR
	CP   R@0,R@2
	CPC  R@1,R@3
	.ENDM

	.MACRO __CPWRN
	CPI  R@0,LOW(@2)
	LDI  R30,HIGH(@2)
	CPC  R@1,R30
	.ENDM

	.MACRO __ADDB1MN
	SUBI R30,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDB2MN
	SUBI R26,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDW1MN
	SUBI R30,LOW(-@0-(@1))
	SBCI R31,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW2MN
	SUBI R26,LOW(-@0-(@1))
	SBCI R27,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	SBCI R22,BYTE3(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1N
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	SBCI R22,BYTE3(-@0)
	SBCI R23,BYTE4(-@0)
	.ENDM

	.MACRO __ADDD2N
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	SBCI R24,BYTE3(-@0)
	SBCI R25,BYTE4(-@0)
	.ENDM

	.MACRO __SUBD1N
	SUBI R30,LOW(@0)
	SBCI R31,HIGH(@0)
	SBCI R22,BYTE3(@0)
	SBCI R23,BYTE4(@0)
	.ENDM

	.MACRO __SUBD2N
	SUBI R26,LOW(@0)
	SBCI R27,HIGH(@0)
	SBCI R24,BYTE3(@0)
	SBCI R25,BYTE4(@0)
	.ENDM

	.MACRO __ANDBMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ANDWMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ANDI R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ANDD1N
	ANDI R30,LOW(@0)
	ANDI R31,HIGH(@0)
	ANDI R22,BYTE3(@0)
	ANDI R23,BYTE4(@0)
	.ENDM

	.MACRO __ANDD2N
	ANDI R26,LOW(@0)
	ANDI R27,HIGH(@0)
	ANDI R24,BYTE3(@0)
	ANDI R25,BYTE4(@0)
	.ENDM

	.MACRO __ORBMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ORWMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ORI  R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ORD1N
	ORI  R30,LOW(@0)
	ORI  R31,HIGH(@0)
	ORI  R22,BYTE3(@0)
	ORI  R23,BYTE4(@0)
	.ENDM

	.MACRO __ORD2N
	ORI  R26,LOW(@0)
	ORI  R27,HIGH(@0)
	ORI  R24,BYTE3(@0)
	ORI  R25,BYTE4(@0)
	.ENDM

	.MACRO __DELAY_USB
	LDI  R24,LOW(@0)
__DELAY_USB_LOOP:
	DEC  R24
	BRNE __DELAY_USB_LOOP
	.ENDM

	.MACRO __DELAY_USW
	LDI  R24,LOW(@0)
	LDI  R25,HIGH(@0)
__DELAY_USW_LOOP:
	SBIW R24,1
	BRNE __DELAY_USW_LOOP
	.ENDM

	.MACRO __GETD1S
	LDD  R30,Y+@0
	LDD  R31,Y+@0+1
	LDD  R22,Y+@0+2
	LDD  R23,Y+@0+3
	.ENDM

	.MACRO __GETD2S
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	LDD  R24,Y+@0+2
	LDD  R25,Y+@0+3
	.ENDM

	.MACRO __PUTD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R31
	STD  Y+@0+2,R22
	STD  Y+@0+3,R23
	.ENDM

	.MACRO __PUTD2S
	STD  Y+@0,R26
	STD  Y+@0+1,R27
	STD  Y+@0+2,R24
	STD  Y+@0+3,R25
	.ENDM

	.MACRO __PUTDZ2
	STD  Z+@0,R26
	STD  Z+@0+1,R27
	STD  Z+@0+2,R24
	STD  Z+@0+3,R25
	.ENDM

	.MACRO __CLRD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R30
	STD  Y+@0+2,R30
	STD  Y+@0+3,R30
	.ENDM

	.MACRO __POINTB1MN
	LDI  R30,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW1MN
	LDI  R30,LOW(@0+(@1))
	LDI  R31,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTD1M
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __POINTW1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	LDI  R22,BYTE3(2*@0+(@1))
	LDI  R23,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTB2MN
	LDI  R26,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW2MN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTD2M
	LDI  R26,LOW(@0)
	LDI  R27,HIGH(@0)
	LDI  R24,BYTE3(@0)
	LDI  R25,BYTE4(@0)
	.ENDM

	.MACRO __POINTW2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	LDI  R24,BYTE3(2*@0+(@1))
	LDI  R25,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTBRM
	LDI  R@0,LOW(@1)
	.ENDM

	.MACRO __POINTWRM
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __POINTBRMN
	LDI  R@0,LOW(@1+(@2))
	.ENDM

	.MACRO __POINTWRMN
	LDI  R@0,LOW(@2+(@3))
	LDI  R@1,HIGH(@2+(@3))
	.ENDM

	.MACRO __POINTWRFN
	LDI  R@0,LOW(@2*2+(@3))
	LDI  R@1,HIGH(@2*2+(@3))
	.ENDM

	.MACRO __GETD1N
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __GETD2N
	LDI  R26,LOW(@0)
	LDI  R27,HIGH(@0)
	LDI  R24,BYTE3(@0)
	LDI  R25,BYTE4(@0)
	.ENDM

	.MACRO __GETB1MN
	LDS  R30,@0+(@1)
	.ENDM

	.MACRO __GETB1HMN
	LDS  R31,@0+(@1)
	.ENDM

	.MACRO __GETW1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	.ENDM

	.MACRO __GETD1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	LDS  R22,@0+(@1)+2
	LDS  R23,@0+(@1)+3
	.ENDM

	.MACRO __GETBRMN
	LDS  R@0,@1+(@2)
	.ENDM

	.MACRO __GETWRMN
	LDS  R@0,@2+(@3)
	LDS  R@1,@2+(@3)+1
	.ENDM

	.MACRO __GETWRZ
	LDD  R@0,Z+@2
	LDD  R@1,Z+@2+1
	.ENDM

	.MACRO __GETD2Z
	LDD  R26,Z+@0
	LDD  R27,Z+@0+1
	LDD  R24,Z+@0+2
	LDD  R25,Z+@0+3
	.ENDM

	.MACRO __GETB2MN
	LDS  R26,@0+(@1)
	.ENDM

	.MACRO __GETW2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	.ENDM

	.MACRO __GETD2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	LDS  R24,@0+(@1)+2
	LDS  R25,@0+(@1)+3
	.ENDM

	.MACRO __PUTB1MN
	STS  @0+(@1),R30
	.ENDM

	.MACRO __PUTW1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	.ENDM

	.MACRO __PUTD1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	STS  @0+(@1)+2,R22
	STS  @0+(@1)+3,R23
	.ENDM

	.MACRO __PUTB1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMWRB
	.ENDM

	.MACRO __PUTW1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMWRW
	.ENDM

	.MACRO __PUTD1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMWRD
	.ENDM

	.MACRO __PUTBR0MN
	STS  @0+(@1),R0
	.ENDM

	.MACRO __PUTBMRN
	STS  @0+(@1),R@2
	.ENDM

	.MACRO __PUTWMRN
	STS  @0+(@1),R@2
	STS  @0+(@1)+1,R@3
	.ENDM

	.MACRO __PUTBZR
	STD  Z+@1,R@0
	.ENDM

	.MACRO __PUTWZR
	STD  Z+@2,R@0
	STD  Z+@2+1,R@1
	.ENDM

	.MACRO __GETW1R
	MOV  R30,R@0
	MOV  R31,R@1
	.ENDM

	.MACRO __GETW2R
	MOV  R26,R@0
	MOV  R27,R@1
	.ENDM

	.MACRO __GETWRN
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __PUTW1R
	MOV  R@0,R30
	MOV  R@1,R31
	.ENDM

	.MACRO __PUTW2R
	MOV  R@0,R26
	MOV  R@1,R27
	.ENDM

	.MACRO __ADDWRN
	SUBI R@0,LOW(-@2)
	SBCI R@1,HIGH(-@2)
	.ENDM

	.MACRO __ADDWRR
	ADD  R@0,R@2
	ADC  R@1,R@3
	.ENDM

	.MACRO __SUBWRN
	SUBI R@0,LOW(@2)
	SBCI R@1,HIGH(@2)
	.ENDM

	.MACRO __SUBWRR
	SUB  R@0,R@2
	SBC  R@1,R@3
	.ENDM

	.MACRO __ANDWRN
	ANDI R@0,LOW(@2)
	ANDI R@1,HIGH(@2)
	.ENDM

	.MACRO __ANDWRR
	AND  R@0,R@2
	AND  R@1,R@3
	.ENDM

	.MACRO __ORWRN
	ORI  R@0,LOW(@2)
	ORI  R@1,HIGH(@2)
	.ENDM

	.MACRO __ORWRR
	OR   R@0,R@2
	OR   R@1,R@3
	.ENDM

	.MACRO __EORWRR
	EOR  R@0,R@2
	EOR  R@1,R@3
	.ENDM

	.MACRO __GETWRS
	LDD  R@0,Y+@2
	LDD  R@1,Y+@2+1
	.ENDM

	.MACRO __PUTBSR
	STD  Y+@1,R@0
	.ENDM

	.MACRO __PUTWSR
	STD  Y+@2,R@0
	STD  Y+@2+1,R@1
	.ENDM

	.MACRO __MOVEWRR
	MOV  R@0,R@2
	MOV  R@1,R@3
	.ENDM

	.MACRO __INWR
	IN   R@0,@2
	IN   R@1,@2+1
	.ENDM

	.MACRO __OUTWR
	OUT  @2+1,R@1
	OUT  @2,R@0
	.ENDM

	.MACRO __CALL1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	ICALL
	.ENDM

	.MACRO __CALL1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	CALL __GETW1PF
	ICALL
	.ENDM

	.MACRO __CALL2EN
	PUSH R26
	PUSH R27
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMRDW
	POP  R27
	POP  R26
	ICALL
	.ENDM

	.MACRO __CALL2EX
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	CALL __EEPROMRDD
	ICALL
	.ENDM

	.MACRO __GETW1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R31,Z
	MOV  R30,R0
	.ENDM

	.MACRO __GETD1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R1,Z+
	LD   R22,Z
	MOVW R30,R0
	.ENDM

	.MACRO __NBST
	BST  R@0,@1
	IN   R30,SREG
	LDI  R31,0x40
	EOR  R30,R31
	OUT  SREG,R30
	.ENDM


	.MACRO __PUTB1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RNS
	MOVW R26,R@0
	ADIW R26,@1
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	CALL __PUTDP1
	.ENDM


	.MACRO __GETB1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R30,Z
	.ENDM

	.MACRO __GETB1HSX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	.ENDM

	.MACRO __GETW1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R0,Z+
	LD   R31,Z
	MOV  R30,R0
	.ENDM

	.MACRO __GETD1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R0,Z+
	LD   R1,Z+
	LD   R22,Z+
	LD   R23,Z
	MOVW R30,R0
	.ENDM

	.MACRO __GETB2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R26,X
	.ENDM

	.MACRO __GETW2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	.ENDM

	.MACRO __GETD2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R1,X+
	LD   R24,X+
	LD   R25,X
	MOVW R26,R0
	.ENDM

	.MACRO __GETBRSX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	LD   R@0,Z
	.ENDM

	.MACRO __GETWRSX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	LD   R@0,Z+
	LD   R@1,Z
	.ENDM

	.MACRO __GETBRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	LD   R@0,X
	.ENDM

	.MACRO __GETWRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	LD   R@0,X+
	LD   R@1,X
	.ENDM

	.MACRO __LSLW8SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	CLR  R30
	.ENDM

	.MACRO __PUTB1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __CLRW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __CLRD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R30
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __PUTB2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z,R26
	.ENDM

	.MACRO __PUTW2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z,R27
	.ENDM

	.MACRO __PUTD2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z+,R27
	ST   Z+,R24
	ST   Z,R25
	.ENDM

	.MACRO __PUTBSRX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	ST   Z,R@0
	.ENDM

	.MACRO __PUTWSRX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	ST   Z+,R@0
	ST   Z,R@1
	.ENDM

	.MACRO __PUTB1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __MULBRR
	MULS R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRRU
	MUL  R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRR0
	MULS R@0,R@1
	.ENDM

	.MACRO __MULBRRU0
	MUL  R@0,R@1
	.ENDM

	.MACRO __MULBNWRU
	LDI  R26,@2
	MUL  R26,R@0
	MOVW R30,R0
	MUL  R26,R@1
	ADD  R31,R0
	.ENDM

;NAME DEFINITIONS FOR GLOBAL VARIABLES ALLOCATED TO REGISTERS
	.DEF _ival=R4
	.DEF _ival_msb=R5
	.DEF _state_flag=R6
	.DEF _state_flag_msb=R7
	.DEF _timer_counting=R8
	.DEF _timer_counting_msb=R9
	.DEF _First_desti=R10
	.DEF _First_desti_msb=R11
	.DEF _Second_desti=R12
	.DEF _Second_desti_msb=R13

	.CSEG
	.ORG 0x00

;START OF CODE MARKER
__START_OF_CODE:

;INTERRUPT VECTORS
	JMP  __RESET
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  _IR_recheck
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  _destination_recieve
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00

;GLOBAL REGISTER VARIABLES INITIALIZATION
__REG_VARS:
	.DB  0x0,0x0,0x0,0x0
	.DB  0x0,0x0,0x0,0x0

_0x0:
	.DB  0x44,0x65,0x6C,0x69,0x76,0x65,0x72,0x79
	.DB  0x20,0x45,0x6E,0x64,0x0,0x54,0x68,0x61
	.DB  0x6E,0x6B,0x20,0x59,0x6F,0x75,0x0,0x31
	.DB  0x73,0x74,0x3A,0x20,0x31,0x20,0x20,0x20
	.DB  0x20,0x32,0x6E,0x64,0x3A,0x20,0x32,0x0
	.DB  0x31,0x73,0x74,0x3A,0x20,0x31,0x20,0x20
	.DB  0x20,0x20,0x32,0x6E,0x64,0x3A,0x20,0x33
	.DB  0x0,0x31,0x73,0x74,0x3A,0x20,0x31,0x20
	.DB  0x20,0x20,0x20,0x32,0x6E,0x64,0x3A,0x20
	.DB  0x34,0x0,0x31,0x73,0x74,0x3A,0x20,0x32
	.DB  0x20,0x20,0x20,0x20,0x32,0x6E,0x64,0x3A
	.DB  0x20,0x31,0x0,0x31,0x73,0x74,0x3A,0x20
	.DB  0x32,0x20,0x20,0x20,0x20,0x32,0x6E,0x64
	.DB  0x3A,0x20,0x33,0x0,0x31,0x73,0x74,0x3A
	.DB  0x20,0x32,0x20,0x20,0x20,0x20,0x32,0x6E
	.DB  0x64,0x3A,0x20,0x34,0x0,0x31,0x73,0x74
	.DB  0x3A,0x20,0x33,0x20,0x20,0x20,0x20,0x32
	.DB  0x6E,0x64,0x3A,0x20,0x31,0x0,0x31,0x73
	.DB  0x74,0x3A,0x20,0x33,0x20,0x20,0x20,0x20
	.DB  0x32,0x6E,0x64,0x3A,0x20,0x32,0x0,0x31
	.DB  0x73,0x74,0x3A,0x20,0x33,0x20,0x20,0x20
	.DB  0x20,0x32,0x6E,0x64,0x3A,0x20,0x34,0x0
	.DB  0x31,0x73,0x74,0x3A,0x20,0x34,0x20,0x20
	.DB  0x20,0x20,0x32,0x6E,0x64,0x3A,0x20,0x31
	.DB  0x0,0x31,0x73,0x74,0x3A,0x20,0x34,0x20
	.DB  0x20,0x20,0x20,0x32,0x6E,0x64,0x3A,0x20
	.DB  0x32,0x0,0x31,0x73,0x74,0x3A,0x20,0x34
	.DB  0x20,0x20,0x20,0x20,0x32,0x6E,0x64,0x3A
	.DB  0x20,0x33,0x0,0x31,0x73,0x74,0x3A,0x20
	.DB  0x31,0x0,0x31,0x73,0x74,0x3A,0x20,0x32
	.DB  0x0,0x31,0x73,0x74,0x3A,0x20,0x33,0x0
	.DB  0x31,0x73,0x74,0x3A,0x20,0x34,0x0,0x31
	.DB  0x73,0x74,0x20,0x4C,0x6F,0x61,0x64,0x20
	.DB  0x4F,0x4B,0x0,0x32,0x6E,0x64,0x20,0x4C
	.DB  0x6F,0x61,0x64,0x20,0x4F,0x4B,0x0,0x31
	.DB  0x73,0x74,0x44,0x65,0x6C,0x69,0x76,0x65
	.DB  0x72,0x79,0x20,0x53,0x55,0x43,0x43,0x0
	.DB  0x31,0x73,0x74,0x44,0x65,0x6C,0x69,0x76
	.DB  0x65,0x72,0x79,0x20,0x46,0x41,0x49,0x4C
	.DB  0x0,0x32,0x6E,0x64,0x44,0x65,0x6C,0x69
	.DB  0x76,0x65,0x72,0x79,0x20,0x53,0x55,0x43
	.DB  0x43,0x0,0x32,0x6E,0x64,0x44,0x65,0x6C
	.DB  0x69,0x76,0x65,0x72,0x79,0x20,0x46,0x41
	.DB  0x49,0x4C,0x0,0x32,0x30,0x31,0x37,0x31
	.DB  0x36,0x31,0x30,0x34,0x31,0x0,0x53,0x65
	.DB  0x72,0x76,0x69,0x6E,0x67,0x20,0x52,0x6F
	.DB  0x62,0x6F,0x74,0x0,0x4D,0x4F,0x56,0x49
	.DB  0x4E,0x47,0x20,0x50,0x4F,0x49,0x4E,0x54
	.DB  0x0

__GLOBAL_INI_TBL:
	.DW  0x08
	.DW  0x06
	.DW  __REG_VARS*2

_0xFFFFFFFF:
	.DW  0

#define __GLOBAL_INI_TBL_PRESENT 1

__RESET:
	CLI
	CLR  R30
	OUT  EECR,R30

;INTERRUPT VECTORS ARE PLACED
;AT THE START OF FLASH
	LDI  R31,1
	OUT  MCUCR,R31
	OUT  MCUCR,R30
	STS  XMCRB,R30

;CLEAR R2-R14
	LDI  R24,(14-2)+1
	LDI  R26,2
	CLR  R27
__CLEAR_REG:
	ST   X+,R30
	DEC  R24
	BRNE __CLEAR_REG

;CLEAR SRAM
	LDI  R24,LOW(__CLEAR_SRAM_SIZE)
	LDI  R25,HIGH(__CLEAR_SRAM_SIZE)
	LDI  R26,LOW(__SRAM_START)
	LDI  R27,HIGH(__SRAM_START)
__CLEAR_SRAM:
	ST   X+,R30
	SBIW R24,1
	BRNE __CLEAR_SRAM

;GLOBAL VARIABLES INITIALIZATION
	LDI  R30,LOW(__GLOBAL_INI_TBL*2)
	LDI  R31,HIGH(__GLOBAL_INI_TBL*2)
__GLOBAL_INI_NEXT:
	LPM  R24,Z+
	LPM  R25,Z+
	SBIW R24,0
	BREQ __GLOBAL_INI_END
	LPM  R26,Z+
	LPM  R27,Z+
	LPM  R0,Z+
	LPM  R1,Z+
	MOVW R22,R30
	MOVW R30,R0
__GLOBAL_INI_LOOP:
	LPM  R0,Z+
	ST   X+,R0
	SBIW R24,1
	BRNE __GLOBAL_INI_LOOP
	MOVW R30,R22
	RJMP __GLOBAL_INI_NEXT
__GLOBAL_INI_END:

	OUT  RAMPZ,R24

;HARDWARE STACK POINTER INITIALIZATION
	LDI  R30,LOW(__SRAM_END-__HEAP_SIZE)
	OUT  SPL,R30
	LDI  R30,HIGH(__SRAM_END-__HEAP_SIZE)
	OUT  SPH,R30

;DATA STACK POINTER INITIALIZATION
	LDI  R28,LOW(__SRAM_START+__DSTACK_SIZE)
	LDI  R29,HIGH(__SRAM_START+__DSTACK_SIZE)

	JMP  _main

	.ESEG
	.ORG 0

	.DSEG
	.ORG 0x500

	.CSEG
;#include <mega128.h>
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x20
	.EQU __sm_mask=0x1C
	.EQU __sm_powerdown=0x10
	.EQU __sm_powersave=0x18
	.EQU __sm_standby=0x14
	.EQU __sm_ext_standby=0x1C
	.EQU __sm_adc_noise_red=0x08
	.SET power_ctrl_reg=mcucr
	#endif
;#include <delay.h>
;
;#define FUNCSET       0x28    // Function Set
;#define ENTMODE       0x06    // Entry Mode Set
;#define ALLCLR        0x01    // All Clear
;#define DISPON        0x0c     // Display On
;#define LINE2         0xC0    // 2nd Line Move
;#define HOME          0x02  //cursor home
;void LCD_init(void);
;void LCD_String(char flash *);                // LCD function
;void Busy(void);
;void Command(unsigned char);
;void Data(unsigned char);
;
;void AD_DS(int);
;void LOAD_CHECK();                            // ADC function
;void FRONTBACK_CHECK();
;void NEGLECT();
;void LCD_IDLE();
;void LCD_mov();
;
;void initial_go();                            // MOVING function
;void initial_back();
;void move_go(int);
;void move_back(int);
;void waiting();
;
;
;void straight_1(int);
;void left_1(int);
;void right_1(int);
;void backward_1(int);
;
;float fval;
;int ival;
;unsigned int state_flag = 0, timer_counting = 0, First_desti = 0, Second_desti = 0;
;unsigned char R_num;
;
;void main(void)
; 0000 0029 {

	.CSEG
_main:
; .FSTART _main
; 0000 002A     int ad_val, i;
; 0000 002B     unsigned char SW;
; 0000 002C 
; 0000 002D     DDRA = 0xFF;
;	ad_val -> R16,R17
;	i -> R18,R19
;	SW -> R21
	LDI  R30,LOW(255)
	OUT  0x1A,R30
; 0000 002E     DDRE = 0x0;
	LDI  R30,LOW(0)
	OUT  0x2,R30
; 0000 002F     PORTA = 0b00000000; // DC motor driver
	OUT  0x1B,R30
; 0000 0030 
; 0000 0031     TIMSK = 0x04;
	LDI  R30,LOW(4)
	OUT  0x37,R30
; 0000 0032     TCCR1A = 0x0;
	LDI  R30,LOW(0)
	OUT  0x2F,R30
; 0000 0033     TCCR1B = 0x05;
	LDI  R30,LOW(5)
	OUT  0x2E,R30
; 0000 0034     TCCR1C = 0x0;
	LDI  R30,LOW(0)
	STS  122,R30
; 0000 0035     TCNT1 = 49911; // 1s
	RCALL SUBOPT_0x0
; 0000 0036 
; 0000 0037     ADMUX = 0b01000010;   // PE2 초기 설정한다.
	LDI  R30,LOW(66)
	OUT  0x7,R30
; 0000 0038     ADCSRA = 0x87;        // 단일 변환모드
	LDI  R30,LOW(135)
	OUT  0x6,R30
; 0000 0039 
; 0000 003A     UCSR0A = 0x0;
	LDI  R30,LOW(0)
	OUT  0xB,R30
; 0000 003B     UCSR0B = 0b10011000;
	LDI  R30,LOW(152)
	OUT  0xA,R30
; 0000 003C     UCSR0C = 0b00000110;
	LDI  R30,LOW(6)
	STS  149,R30
; 0000 003D     UBRR0H = 0;
	LDI  R30,LOW(0)
	STS  144,R30
; 0000 003E     UBRR0L = 103;
	LDI  R30,LOW(103)
	OUT  0x9,R30
; 0000 003F     SREG = 0x80;
	LDI  R30,LOW(128)
	OUT  0x3F,R30
; 0000 0040 
; 0000 0041     LCD_IDLE();
	RCALL _LCD_IDLE
; 0000 0042     for(i = 1 ; i <3 ; i++)
	__GETWRN 18,19,1
_0x4:
	__CPWRN 18,19,3
	BRGE _0x5
; 0000 0043         delay_ms(1000);
	LDI  R26,LOW(1000)
	LDI  R27,HIGH(1000)
	RCALL _delay_ms
	__ADDWRN 18,19,1
	RJMP _0x4
_0x5:
; 0000 0045 LCD_init();
	RCALL _LCD_init
; 0000 0046 
; 0000 0047     while(1)
_0x6:
; 0000 0048     {
; 0000 0049         ADCSRA = ADCSRA | 0b01000000;
	SBI  0x6,6
; 0000 004A         while((ADCSRA & 0x10) == 0);
_0x9:
	SBIS 0x6,4
	RJMP _0x9
; 0000 004B             ad_val = (int)ADCL + ((int)ADCH << 8);
	RCALL SUBOPT_0x1
; 0000 004C         AD_DS(ad_val);
; 0000 004D         SW = PINE & 0b00010000;
	IN   R30,0x1
	ANDI R30,LOW(0x10)
	MOV  R21,R30
; 0000 004E 
; 0000 004F         if((state_flag >= 0) || (state_flag <= 2))  {
; 0000 0050         if(ival >= 140)
	LDI  R30,LOW(140)
	LDI  R31,HIGH(140)
	CP   R4,R30
	CPC  R5,R31
	BRLT _0xF
; 0000 0051             LOAD_CHECK();
	RCALL _LOAD_CHECK
; 0000 0052         else
	RJMP _0x10
_0xF:
; 0000 0053             NEGLECT();
	RCALL _NEGLECT
; 0000 0054         }
_0x10:
; 0000 0055 
; 0000 0056         if(SW == 0)
	CPI  R21,0
	BRNE _0x11
; 0000 0057         {
; 0000 0058             if(state_flag == 3)
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	CP   R30,R6
	CPC  R31,R7
	BRNE _0x12
; 0000 0059                 state_flag = 4;
	LDI  R30,LOW(4)
	LDI  R31,HIGH(4)
	MOVW R6,R30
; 0000 005A             else if(state_flag != 3);
_0x12:
; 0000 005B                 NEGLECT();
	RCALL _NEGLECT
; 0000 005C         }
; 0000 005D 
; 0000 005E         if((First_desti !=0) && state_flag ==4 )
_0x11:
	CLR  R0
	CP   R0,R10
	CPC  R0,R11
	BREQ _0x16
	RCALL SUBOPT_0x2
	BREQ _0x17
_0x16:
	RJMP _0x15
_0x17:
; 0000 005F         {
; 0000 0060             initial_go();
	RCALL _initial_go
; 0000 0061             move_go(First_desti);           //move to first destination
	MOVW R26,R10
	RCALL _move_go
; 0000 0062             state_flag = 6;
	LDI  R30,LOW(6)
	LDI  R31,HIGH(6)
	RCALL SUBOPT_0x3
; 0000 0063             waiting();                      // arrive & wait
; 0000 0064             state_flag = 5;
; 0000 0065             move_back(First_desti);         // back to the 분기점
	MOVW R26,R10
	RCALL _move_back
; 0000 0066                                             // 1차 왕복 완료
; 0000 0067 
; 0000 0068             if(Second_desti == 5)   {       // 1개만 입력될 경우 2차 경유지 값이 5로 저장된다.
	LDI  R30,LOW(5)
	LDI  R31,HIGH(5)
	CP   R30,R12
	CPC  R31,R13
	BREQ _0x95
; 0000 0069                 initial_back();
; 0000 006A                 state_flag =0;
; 0000 006B             }
; 0000 006C             else
; 0000 006D             {
; 0000 006E                 state_flag = 4;
	LDI  R30,LOW(4)
	LDI  R31,HIGH(4)
	MOVW R6,R30
; 0000 006F                 move_go(Second_desti);
	MOVW R26,R12
	RCALL _move_go
; 0000 0070                 state_flag = 7;
	LDI  R30,LOW(7)
	LDI  R31,HIGH(7)
	RCALL SUBOPT_0x3
; 0000 0071                 waiting();
; 0000 0072                 state_flag = 5;
; 0000 0073                 move_back(Second_desti);
	MOVW R26,R12
	RCALL _move_back
; 0000 0074                 initial_back();
_0x95:
	RCALL _initial_back
; 0000 0075                 state_flag = 0;
	CLR  R6
	CLR  R7
; 0000 0076             }
; 0000 0077             First_desti = 0;
	CLR  R10
	CLR  R11
; 0000 0078             Second_desti = 0;
	CLR  R12
	CLR  R13
; 0000 0079             LCD_init();
	RCALL _LCD_init
; 0000 007A 
; 0000 007B             LCD_String("Delivery End");
	__POINTW2FN _0x0,0
	RCALL _LCD_String
; 0000 007C             Command(LINE2);
	LDI  R26,LOW(192)
	RCALL _Command
; 0000 007D             LCD_String("Thank You");
	__POINTW2FN _0x0,13
	RCALL _LCD_String
; 0000 007E 
; 0000 007F             for(i = 0 ; i < 3 ; i++)
	__GETWRN 18,19,0
_0x1B:
	__CPWRN 18,19,3
	BRGE _0x1C
; 0000 0080                 delay_ms(1000);
	LDI  R26,LOW(1000)
	LDI  R27,HIGH(1000)
	RCALL _delay_ms
	__ADDWRN 18,19,1
	RJMP _0x1B
_0x1C:
; 0000 0081 LCD_init();
	RCALL _LCD_init
; 0000 0082             ADMUX = 0b01000010;
	LDI  R30,LOW(66)
	OUT  0x7,R30
; 0000 0083         }
; 0000 0084     }
_0x15:
	RJMP _0x6
; 0000 0085 }
_0x1D:
	RJMP _0x1D
; .FEND
;
;interrupt [TIM1_OVF] void IR_recheck (void)       // IR SENSOR(LOAD) 갱신 방법
; 0000 0088 {
_IR_recheck:
; .FSTART _IR_recheck
	RCALL SUBOPT_0x4
; 0000 0089     TCNT1 = 49911;
	RCALL SUBOPT_0x0
; 0000 008A 
; 0000 008B     if(timer_counting ==3)
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	CP   R30,R8
	CPC  R31,R9
	BRNE _0x1E
; 0000 008C     {
; 0000 008D         timer_counting = 0;
	CLR  R8
	CLR  R9
; 0000 008E         if(state_flag == 0 || state_flag > 2)
	CLR  R0
	CP   R0,R6
	CPC  R0,R7
	BREQ _0x20
	RCALL SUBOPT_0x5
	BRSH _0x1F
_0x20:
; 0000 008F             NEGLECT();
	RCALL _NEGLECT
; 0000 0090         else if(state_flag == 1 || state_flag == 2){
	RJMP _0x22
_0x1F:
	RCALL SUBOPT_0x6
	BREQ _0x24
	RCALL SUBOPT_0x5
	BRNE _0x23
_0x24:
; 0000 0091             LCD_init();
	RCALL _LCD_init
; 0000 0092             state_flag = 0;
	CLR  R6
	CLR  R7
; 0000 0093             ADMUX = 0b01000010;
	LDI  R30,LOW(66)
	OUT  0x7,R30
; 0000 0094         }
; 0000 0095     }
_0x23:
_0x22:
; 0000 0096     else
	RJMP _0x26
_0x1E:
; 0000 0097         timer_counting++;
	MOVW R30,R8
	ADIW R30,1
	MOVW R8,R30
; 0000 0098 }
_0x26:
	RJMP _0x9D
; .FEND
;
;interrupt [USART0_RXC] void destination_recieve (void)
; 0000 009B {
_destination_recieve:
; .FSTART _destination_recieve
	RCALL SUBOPT_0x4
; 0000 009C     R_num = UDR0;   // recieve
	IN   R30,0xC
	STS  _R_num,R30
; 0000 009D 
; 0000 009E     if(R_num == 'w')    {
	LDS  R26,_R_num
	CPI  R26,LOW(0x77)
	BRNE _0x27
; 0000 009F         straight_1(100);
	LDI  R26,LOW(100)
	LDI  R27,0
	RCALL _straight_1
; 0000 00A0     }
; 0000 00A1     else if(R_num == 'x')   {
	RJMP _0x28
_0x27:
	LDS  R26,_R_num
	CPI  R26,LOW(0x78)
	BRNE _0x29
; 0000 00A2         backward_1(100);
	LDI  R26,LOW(100)
	LDI  R27,0
	RCALL _backward_1
; 0000 00A3     }
; 0000 00A4     else if(R_num == 'y')   {
	RJMP _0x2A
_0x29:
	LDS  R26,_R_num
	CPI  R26,LOW(0x79)
	BRNE _0x2B
; 0000 00A5         left_1(40);
	LDI  R26,LOW(40)
	LDI  R27,0
	RCALL _left_1
; 0000 00A6 
; 0000 00A7     }
; 0000 00A8     else if(R_num == 'z')   {
	RJMP _0x2C
_0x2B:
	LDS  R26,_R_num
	CPI  R26,LOW(0x7A)
	BRNE _0x2D
; 0000 00A9         right_1(33);
	LDI  R26,LOW(33)
	LDI  R27,0
	RCALL _right_1
; 0000 00AA     }
; 0000 00AB     else if(R_num == 'o'){
	RJMP _0x2E
_0x2D:
	LDS  R26,_R_num
	CPI  R26,LOW(0x6F)
	BRNE _0x2F
; 0000 00AC         PORTA = 0b10101010;
	LDI  R30,LOW(170)
	RJMP _0x96
; 0000 00AD     }
; 0000 00AE     else if(R_num == 'p'){
_0x2F:
	LDS  R26,_R_num
	CPI  R26,LOW(0x70)
	BRNE _0x31
; 0000 00AF         PORTA = 0b01010101;
	LDI  R30,LOW(85)
	RJMP _0x96
; 0000 00B0     }
; 0000 00B1     else if(R_num == 'q'){
_0x31:
	LDS  R26,_R_num
	CPI  R26,LOW(0x71)
	BRNE _0x33
; 0000 00B2         PORTA = 0b10100101;
	LDI  R30,LOW(165)
	RJMP _0x96
; 0000 00B3     }
; 0000 00B4     else if(R_num == 'r'){
_0x33:
	LDS  R26,_R_num
	CPI  R26,LOW(0x72)
	BRNE _0x35
; 0000 00B5         PORTA = 0b01011010;
	LDI  R30,LOW(90)
	RJMP _0x96
; 0000 00B6     }
; 0000 00B7     else if(R_num == 's'){     //정지
_0x35:
	LDS  R26,_R_num
	CPI  R26,LOW(0x73)
	BRNE _0x37
; 0000 00B8         PORTA = 0b00000000;
	LDI  R30,LOW(0)
_0x96:
	OUT  0x1B,R30
; 0000 00B9     }
; 0000 00BA 
; 0000 00BB 
; 0000 00BC 
; 0000 00BD     if((state_flag == 2))   {
_0x37:
_0x2E:
_0x2C:
_0x2A:
_0x28:
	RCALL SUBOPT_0x5
	BREQ PC+2
	RJMP _0x38
; 0000 00BE         state_flag = 3;
	RCALL SUBOPT_0x7
; 0000 00BF         if(R_num == 'a')    {
	CPI  R26,LOW(0x61)
	BRNE _0x39
; 0000 00C0             LCD_mov();
	RCALL _LCD_mov
; 0000 00C1             LCD_String("1st: 1    2nd: 2");
	__POINTW2FN _0x0,23
	RCALL SUBOPT_0x8
; 0000 00C2             First_desti = 1;
; 0000 00C3             Second_desti = 2;
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	MOVW R12,R30
; 0000 00C4         }
; 0000 00C5         else if(R_num == 'b')   {
	RJMP _0x3A
_0x39:
	LDS  R26,_R_num
	CPI  R26,LOW(0x62)
	BRNE _0x3B
; 0000 00C6             LCD_mov();
	RCALL _LCD_mov
; 0000 00C7             LCD_String("1st: 1    2nd: 3");
	__POINTW2FN _0x0,40
	RCALL SUBOPT_0x8
; 0000 00C8             First_desti = 1;
; 0000 00C9             Second_desti = 3;
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	MOVW R12,R30
; 0000 00CA         }
; 0000 00CB         else if(R_num == 'c')   {
	RJMP _0x3C
_0x3B:
	LDS  R26,_R_num
	CPI  R26,LOW(0x63)
	BRNE _0x3D
; 0000 00CC             LCD_mov();
	RCALL _LCD_mov
; 0000 00CD             LCD_String("1st: 1    2nd: 4");     // 1 to 2 3 4
	__POINTW2FN _0x0,57
	RCALL SUBOPT_0x8
; 0000 00CE             First_desti = 1;
; 0000 00CF             Second_desti = 4;
	LDI  R30,LOW(4)
	LDI  R31,HIGH(4)
	MOVW R12,R30
; 0000 00D0         }
; 0000 00D1         else if(R_num == 'd')   {
	RJMP _0x3E
_0x3D:
	LDS  R26,_R_num
	CPI  R26,LOW(0x64)
	BRNE _0x3F
; 0000 00D2             LCD_mov();
	RCALL _LCD_mov
; 0000 00D3             LCD_String("1st: 2    2nd: 1");
	__POINTW2FN _0x0,74
	RCALL SUBOPT_0x9
; 0000 00D4             First_desti = 2;
; 0000 00D5             Second_desti = 1;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	MOVW R12,R30
; 0000 00D6         }
; 0000 00D7         else if(R_num == 'e')   {
	RJMP _0x40
_0x3F:
	LDS  R26,_R_num
	CPI  R26,LOW(0x65)
	BRNE _0x41
; 0000 00D8             LCD_mov();
	RCALL _LCD_mov
; 0000 00D9             LCD_String("1st: 2    2nd: 3");
	__POINTW2FN _0x0,91
	RCALL SUBOPT_0x9
; 0000 00DA             First_desti = 2;
; 0000 00DB             Second_desti = 3;
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	MOVW R12,R30
; 0000 00DC         }
; 0000 00DD         else if(R_num == 'f')   {
	RJMP _0x42
_0x41:
	LDS  R26,_R_num
	CPI  R26,LOW(0x66)
	BRNE _0x43
; 0000 00DE             LCD_mov();
	RCALL _LCD_mov
; 0000 00DF             LCD_String("1st: 2    2nd: 4");   // 2 to 1 3 4
	__POINTW2FN _0x0,108
	RCALL SUBOPT_0x9
; 0000 00E0             First_desti = 2;
; 0000 00E1             Second_desti = 4;
	LDI  R30,LOW(4)
	LDI  R31,HIGH(4)
	MOVW R12,R30
; 0000 00E2         }
; 0000 00E3         else if(R_num == 'g')   {
	RJMP _0x44
_0x43:
	LDS  R26,_R_num
	CPI  R26,LOW(0x67)
	BRNE _0x45
; 0000 00E4             LCD_mov();
	RCALL _LCD_mov
; 0000 00E5             LCD_String("1st: 3    2nd: 1");
	__POINTW2FN _0x0,125
	RCALL SUBOPT_0xA
; 0000 00E6             First_desti = 3;
; 0000 00E7             Second_desti = 1;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	MOVW R12,R30
; 0000 00E8         }
; 0000 00E9         else if(R_num == 'h')   {
	RJMP _0x46
_0x45:
	LDS  R26,_R_num
	CPI  R26,LOW(0x68)
	BRNE _0x47
; 0000 00EA             LCD_mov();
	RCALL _LCD_mov
; 0000 00EB             LCD_String("1st: 3    2nd: 2");
	__POINTW2FN _0x0,142
	RCALL SUBOPT_0xA
; 0000 00EC             First_desti = 3;
; 0000 00ED             Second_desti = 2;
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	MOVW R12,R30
; 0000 00EE         }
; 0000 00EF         else if(R_num == 'i')   {
	RJMP _0x48
_0x47:
	LDS  R26,_R_num
	CPI  R26,LOW(0x69)
	BRNE _0x49
; 0000 00F0             LCD_mov();
	RCALL _LCD_mov
; 0000 00F1             LCD_String("1st: 3    2nd: 4");    // 3 to 124
	__POINTW2FN _0x0,159
	RCALL SUBOPT_0xA
; 0000 00F2             First_desti = 3;
; 0000 00F3             Second_desti = 4;
	LDI  R30,LOW(4)
	LDI  R31,HIGH(4)
	MOVW R12,R30
; 0000 00F4         }
; 0000 00F5         else if(R_num == 'j')   {
	RJMP _0x4A
_0x49:
	LDS  R26,_R_num
	CPI  R26,LOW(0x6A)
	BRNE _0x4B
; 0000 00F6             LCD_mov();
	RCALL _LCD_mov
; 0000 00F7             LCD_String("1st: 4    2nd: 1");
	__POINTW2FN _0x0,176
	RCALL SUBOPT_0xB
; 0000 00F8             First_desti = 4;
; 0000 00F9             Second_desti = 1;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	MOVW R12,R30
; 0000 00FA         }
; 0000 00FB         else if(R_num == 'k')   {
	RJMP _0x4C
_0x4B:
	LDS  R26,_R_num
	CPI  R26,LOW(0x6B)
	BRNE _0x4D
; 0000 00FC             LCD_mov();
	RCALL _LCD_mov
; 0000 00FD             LCD_String("1st: 4    2nd: 2");
	__POINTW2FN _0x0,193
	RCALL SUBOPT_0xB
; 0000 00FE             First_desti = 4;
; 0000 00FF             Second_desti = 2;
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	MOVW R12,R30
; 0000 0100         }
; 0000 0101         else if(R_num == 'l')   {
	RJMP _0x4E
_0x4D:
	LDS  R26,_R_num
	CPI  R26,LOW(0x6C)
	BRNE _0x4F
; 0000 0102             LCD_mov();
	RCALL _LCD_mov
; 0000 0103             LCD_String("1st: 4    2nd: 3");     // 4 to 123
	__POINTW2FN _0x0,210
	RCALL SUBOPT_0xB
; 0000 0104             First_desti = 4;
; 0000 0105             Second_desti = 3;
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	MOVW R12,R30
; 0000 0106         }
; 0000 0107         else
	RJMP _0x50
_0x4F:
; 0000 0108             NEGLECT();
	RCALL _NEGLECT
; 0000 0109     }
_0x50:
_0x4E:
_0x4C:
_0x4A:
_0x48:
_0x46:
_0x44:
_0x42:
_0x40:
_0x3E:
_0x3C:
_0x3A:
; 0000 010A     else if((state_flag == 1))  {
	RJMP _0x51
_0x38:
	RCALL SUBOPT_0x6
	BRNE _0x52
; 0000 010B         state_flag = 3;
	RCALL SUBOPT_0x7
; 0000 010C          if(R_num == '1')    {
	CPI  R26,LOW(0x31)
	BRNE _0x53
; 0000 010D             LCD_mov();
	RCALL _LCD_mov
; 0000 010E             LCD_String("1st: 1");
	__POINTW2FN _0x0,227
	RCALL SUBOPT_0x8
; 0000 010F             First_desti = 1;
; 0000 0110             Second_desti = 5;
	LDI  R30,LOW(5)
	LDI  R31,HIGH(5)
	MOVW R12,R30
; 0000 0111         }
; 0000 0112         else if(R_num == '2')   {
	RJMP _0x54
_0x53:
	LDS  R26,_R_num
	CPI  R26,LOW(0x32)
	BRNE _0x55
; 0000 0113             LCD_mov();
	RCALL _LCD_mov
; 0000 0114             LCD_String("1st: 2");
	__POINTW2FN _0x0,234
	RCALL SUBOPT_0x9
; 0000 0115             First_desti = 2;
; 0000 0116             Second_desti = 5;
	LDI  R30,LOW(5)
	LDI  R31,HIGH(5)
	MOVW R12,R30
; 0000 0117         }
; 0000 0118         else if(R_num == '3')   {
	RJMP _0x56
_0x55:
	LDS  R26,_R_num
	CPI  R26,LOW(0x33)
	BRNE _0x57
; 0000 0119             LCD_mov();
	RCALL _LCD_mov
; 0000 011A             LCD_String("1st: 3");
	__POINTW2FN _0x0,241
	RCALL SUBOPT_0xA
; 0000 011B             First_desti = 3;
; 0000 011C             Second_desti = 5;
	LDI  R30,LOW(5)
	LDI  R31,HIGH(5)
	MOVW R12,R30
; 0000 011D         }
; 0000 011E         else if(R_num == '4')   {
	RJMP _0x58
_0x57:
	LDS  R26,_R_num
	CPI  R26,LOW(0x34)
	BRNE _0x59
; 0000 011F             LCD_mov();
	RCALL _LCD_mov
; 0000 0120             LCD_String("1st: 4");
	__POINTW2FN _0x0,248
	RCALL SUBOPT_0xB
; 0000 0121             First_desti = 4;
; 0000 0122             Second_desti = 5;
	LDI  R30,LOW(5)
	LDI  R31,HIGH(5)
	MOVW R12,R30
; 0000 0123         }
; 0000 0124         else
	RJMP _0x5A
_0x59:
; 0000 0125             NEGLECT();
	RCALL _NEGLECT
; 0000 0126     }
_0x5A:
_0x58:
_0x56:
_0x54:
; 0000 0127     else
	RJMP _0x5B
_0x52:
; 0000 0128         NEGLECT();
	RCALL _NEGLECT
; 0000 0129 
; 0000 012A }
_0x5B:
_0x51:
_0x9D:
	LD   R30,Y+
	OUT  SREG,R30
	LD   R31,Y+
	LD   R30,Y+
	LD   R27,Y+
	LD   R26,Y+
	LD   R25,Y+
	LD   R24,Y+
	LD   R23,Y+
	LD   R22,Y+
	LD   R15,Y+
	LD   R1,Y+
	LD   R0,Y+
	RETI
; .FEND
;
;void AD_DS(int val)
; 0000 012D {
_AD_DS:
; .FSTART _AD_DS
; 0000 012E     fval = (float)val * 5.0 / 1023.0;
	ST   -Y,R17
	ST   -Y,R16
	MOVW R16,R26
;	val -> R16,R17
	MOVW R30,R16
	RCALL __CWD1
	RCALL __CDF1
	__GETD2N 0x40A00000
	RCALL __MULF12
	MOVW R26,R30
	MOVW R24,R22
	__GETD1N 0x447FC000
	RCALL __DIVF21
	STS  _fval,R30
	STS  _fval+1,R31
	STS  _fval+2,R22
	STS  _fval+3,R23
; 0000 012F     ival = (int)(fval * 100.0 + 0.5);
	LDS  R26,_fval
	LDS  R27,_fval+1
	LDS  R24,_fval+2
	LDS  R25,_fval+3
	__GETD1N 0x42C80000
	RCALL __MULF12
	__GETD2N 0x3F000000
	RCALL __ADDF12
	RCALL __CFD1
	MOVW R4,R30
; 0000 0130 }
	RJMP _0x2000005
; .FEND
;
;void LOAD_CHECK()
; 0000 0133 {
_LOAD_CHECK:
; .FSTART _LOAD_CHECK
; 0000 0134     if(state_flag == 0) // PE0
	MOV  R0,R6
	OR   R0,R7
	BRNE _0x5C
; 0000 0135     {
; 0000 0136        LCD_init();
	RCALL _LCD_init
; 0000 0137        LCD_String("1st Load OK");
	__POINTW2FN _0x0,255
	RCALL _LCD_String
; 0000 0138        state_flag = 1;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	MOVW R6,R30
; 0000 0139        ADMUX = 0b01000011;
	LDI  R30,LOW(67)
	OUT  0x7,R30
; 0000 013A     }
; 0000 013B     else if(state_flag == 1) //PE1
	RJMP _0x5D
_0x5C:
	RCALL SUBOPT_0x6
	BRNE _0x5E
; 0000 013C     {
; 0000 013D         Command(LINE2);
	LDI  R26,LOW(192)
	RCALL _Command
; 0000 013E         LCD_String("2nd Load OK");
	__POINTW2FN _0x0,267
	RCALL _LCD_String
; 0000 013F         state_flag = 2;
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	MOVW R6,R30
; 0000 0140         ADMUX = 0b01000010;
	LDI  R30,LOW(66)
	OUT  0x7,R30
; 0000 0141     }
; 0000 0142     else
	RJMP _0x5F
_0x5E:
; 0000 0143         NEGLECT();
	RCALL _NEGLECT
; 0000 0144 }
_0x5F:
_0x5D:
	RET
; .FEND
;void FRONTBACK_CHECK()
; 0000 0146 {
_FRONTBACK_CHECK:
; .FSTART _FRONTBACK_CHECK
; 0000 0147     int ad_val;
; 0000 0148     ADCSRA = ADCSRA | 0b01000000;
	ST   -Y,R17
	ST   -Y,R16
;	ad_val -> R16,R17
	SBI  0x6,6
; 0000 0149         while((ADCSRA & 0x10) == 0);
_0x60:
	SBIS 0x6,4
	RJMP _0x60
; 0000 014A             ad_val = (int)ADCL + ((int)ADCH << 8);
	RCALL SUBOPT_0x1
; 0000 014B         AD_DS(ad_val);
; 0000 014C 
; 0000 014D         if(ival >= 150)
	LDI  R30,LOW(150)
	LDI  R31,HIGH(150)
	CP   R4,R30
	CPC  R5,R31
	BRLT _0x63
; 0000 014E         {
; 0000 014F             PORTA = 0b00000000;
	LDI  R30,LOW(0)
	OUT  0x1B,R30
; 0000 0150             delay_ms(3000);
	LDI  R26,LOW(3000)
	LDI  R27,HIGH(3000)
	RCALL _delay_ms
; 0000 0151             if (state_flag == 4)
	RCALL SUBOPT_0x2
	BRNE _0x64
; 0000 0152                 PORTA = 0b10101010;
	LDI  R30,LOW(170)
	RJMP _0x97
; 0000 0153             else if(state_flag == 5)
_0x64:
	LDI  R30,LOW(5)
	LDI  R31,HIGH(5)
	CP   R30,R6
	CPC  R31,R7
	BRNE _0x66
; 0000 0154                 PORTA = 0b01010101;
	LDI  R30,LOW(85)
_0x97:
	OUT  0x1B,R30
; 0000 0155             ival = 0;
_0x66:
	CLR  R4
	CLR  R5
; 0000 0156         }
; 0000 0157         else
	RJMP _0x67
_0x63:
; 0000 0158             delay_us(1);
	__DELAY_USB 5
; 0000 0159 
; 0000 015A }
_0x67:
	RJMP _0x2000005
; .FEND
;
;void waiting()
; 0000 015D {
_waiting:
; .FSTART _waiting
; 0000 015E     int ad_val, i;
; 0000 015F     for(i = 1; i <= 10; i++)
	RCALL __SAVELOCR4
;	ad_val -> R16,R17
;	i -> R18,R19
	__GETWRN 18,19,1
_0x69:
	__CPWRN 18,19,11
	BRGE _0x6A
; 0000 0160         delay_ms(1000);
	LDI  R26,LOW(1000)
	LDI  R27,HIGH(1000)
	RCALL _delay_ms
	__ADDWRN 18,19,1
	RJMP _0x69
_0x6A:
; 0000 0162 if (state_flag == 6)
	LDI  R30,LOW(6)
	LDI  R31,HIGH(6)
	CP   R30,R6
	CPC  R31,R7
	BRNE _0x6B
; 0000 0163         ADMUX = 0b01000010;    //PF2
	LDI  R30,LOW(66)
	RJMP _0x98
; 0000 0164     else if(state_flag == 7)
_0x6B:
	LDI  R30,LOW(7)
	LDI  R31,HIGH(7)
	CP   R30,R6
	CPC  R31,R7
	BRNE _0x6D
; 0000 0165         ADMUX = 0b01000011;    //PF3
	LDI  R30,LOW(67)
_0x98:
	OUT  0x7,R30
; 0000 0166 
; 0000 0167     ADCSRA = ADCSRA | 0b01000000;
_0x6D:
	SBI  0x6,6
; 0000 0168         while((ADCSRA & 0x10) == 0);
_0x6E:
	SBIS 0x6,4
	RJMP _0x6E
; 0000 0169             ad_val = (int)ADCL + ((int)ADCH << 8);
	RCALL SUBOPT_0x1
; 0000 016A         AD_DS(ad_val);
; 0000 016B 
; 0000 016C         if(ADMUX == 0b01000010)
	IN   R30,0x7
	CPI  R30,LOW(0x42)
	BRNE _0x71
; 0000 016D         {
; 0000 016E             if(ival < 130)
	RCALL SUBOPT_0xC
	BRGE _0x72
; 0000 016F             {
; 0000 0170                 Command(HOME);
	LDI  R26,LOW(2)
	RCALL _Command
; 0000 0171                 LCD_String("1stDelivery SUCC");
	__POINTW2FN _0x0,279
	RJMP _0x99
; 0000 0172             }
; 0000 0173             else
_0x72:
; 0000 0174             {
; 0000 0175                 Command(HOME);
	LDI  R26,LOW(2)
	RCALL _Command
; 0000 0176                 LCD_String("1stDelivery FAIL");
	__POINTW2FN _0x0,296
_0x99:
	RCALL _LCD_String
; 0000 0177             }
; 0000 0178         }
; 0000 0179         else if(ADMUX == 0b01000011)
	RJMP _0x74
_0x71:
	IN   R30,0x7
	CPI  R30,LOW(0x43)
	BRNE _0x75
; 0000 017A         {
; 0000 017B             if(ival < 130)
	RCALL SUBOPT_0xC
	BRGE _0x76
; 0000 017C             {
; 0000 017D                 Command(LINE2);
	LDI  R26,LOW(192)
	RCALL _Command
; 0000 017E                 LCD_String("2ndDelivery SUCC");
	__POINTW2FN _0x0,313
	RJMP _0x9A
; 0000 017F             }
; 0000 0180             else
_0x76:
; 0000 0181             {
; 0000 0182                 Command(LINE2);
	LDI  R26,LOW(192)
	RCALL _Command
; 0000 0183                 LCD_String("2ndDelivery FAIL");
	__POINTW2FN _0x0,330
_0x9A:
	RCALL _LCD_String
; 0000 0184             }
; 0000 0185         }
; 0000 0186 }
_0x75:
_0x74:
	RJMP _0x2000002
; .FEND
;
;void initial_go()
; 0000 0189 {
_initial_go:
; .FSTART _initial_go
; 0000 018A     straight_1(200);
	LDI  R26,LOW(200)
	LDI  R27,0
	RCALL _straight_1
; 0000 018B }
	RET
; .FEND
;void initial_back()
; 0000 018D {
_initial_back:
; .FSTART _initial_back
; 0000 018E      backward_1(200);
	LDI  R26,LOW(200)
	LDI  R27,0
	RCALL _backward_1
; 0000 018F }
	RET
; .FEND
;void move_go(int a)
; 0000 0191 {
_move_go:
; .FSTART _move_go
; 0000 0192      if(a == 1)
	RCALL SUBOPT_0xD
;	a -> R16,R17
	BRNE _0x78
; 0000 0193      {
; 0000 0194         straight_1(20);
	RCALL SUBOPT_0xE
; 0000 0195         left_1(33);
; 0000 0196         straight_1(180);
	LDI  R26,LOW(180)
	RJMP _0x9B
; 0000 0197      }
; 0000 0198      else if(a == 2)
_0x78:
	RCALL SUBOPT_0xF
	BRNE _0x7A
; 0000 0199      {
; 0000 019A         straight_1(20);
	RCALL SUBOPT_0xE
; 0000 019B         left_1(33);
; 0000 019C         straight_1(80);
	LDI  R26,LOW(80)
	RCALL SUBOPT_0x10
; 0000 019D         right_1(37);
; 0000 019E         straight_1(80);
	RJMP _0x9C
; 0000 019F      }
; 0000 01A0      else if(a == 3)
_0x7A:
	RCALL SUBOPT_0x11
	BRNE _0x7C
; 0000 01A1      {
; 0000 01A2         right_1(40);
	LDI  R26,LOW(40)
	LDI  R27,0
	RCALL _right_1
; 0000 01A3         straight_1(230);
	LDI  R26,LOW(230)
	RCALL SUBOPT_0x10
; 0000 01A4         right_1(37);
; 0000 01A5         straight_1(115);
	LDI  R26,LOW(115)
	RJMP _0x9B
; 0000 01A6      }
; 0000 01A7      else if(a == 4)
_0x7C:
	RCALL SUBOPT_0x12
	BRNE _0x7E
; 0000 01A8      {
; 0000 01A9         left_1(33);
	LDI  R26,LOW(33)
	LDI  R27,0
	RCALL _left_1
; 0000 01AA         straight_1(80);
	LDI  R26,LOW(80)
	LDI  R27,0
	RCALL _straight_1
; 0000 01AB         left_1(35);
	LDI  R26,LOW(35)
	LDI  R27,0
	RCALL _left_1
; 0000 01AC         straight_1(80);
_0x9C:
	LDI  R26,LOW(80)
_0x9B:
	LDI  R27,0
	RCALL _straight_1
; 0000 01AD      }
; 0000 01AE }
_0x7E:
	RJMP _0x2000005
; .FEND
;void move_back(int a)
; 0000 01B0 {
_move_back:
; .FSTART _move_back
; 0000 01B1     if(a == 1)
	RCALL SUBOPT_0xD
;	a -> R16,R17
	BRNE _0x7F
; 0000 01B2      {
; 0000 01B3         backward_1(180);
	LDI  R26,LOW(180)
	LDI  R27,0
	RCALL _backward_1
; 0000 01B4         right_1(36);
	LDI  R26,LOW(36)
	LDI  R27,0
	RCALL _right_1
; 0000 01B5         backward_1(20);
	LDI  R26,LOW(20)
	LDI  R27,0
	RCALL _backward_1
; 0000 01B6      }
; 0000 01B7      else if(a == 2)
	RJMP _0x80
_0x7F:
	RCALL SUBOPT_0xF
	BRNE _0x81
; 0000 01B8      {
; 0000 01B9         backward_1(80);
	RCALL SUBOPT_0x13
; 0000 01BA         left_1(37);
	RCALL _left_1
; 0000 01BB         backward_1(100);
	LDI  R26,LOW(100)
	LDI  R27,0
	RCALL _backward_1
; 0000 01BC         right_1(34);
	LDI  R26,LOW(34)
	LDI  R27,0
	RCALL _right_1
; 0000 01BD         backward_1(10);
	LDI  R26,LOW(10)
	LDI  R27,0
	RCALL _backward_1
; 0000 01BE      }
; 0000 01BF      else if(a == 3)
	RJMP _0x82
_0x81:
	RCALL SUBOPT_0x11
	BRNE _0x83
; 0000 01C0      {
; 0000 01C1         backward_1(115);
	LDI  R26,LOW(115)
	RCALL SUBOPT_0x14
; 0000 01C2         left_1(38);
; 0000 01C3         backward_1(230);
	LDI  R26,LOW(230)
	RCALL SUBOPT_0x14
; 0000 01C4         left_1(38);
; 0000 01C5         backward_1(20);
	LDI  R26,LOW(20)
	LDI  R27,0
	RCALL _backward_1
; 0000 01C6      }
; 0000 01C7      else if(a == 4)
	RJMP _0x84
_0x83:
	RCALL SUBOPT_0x12
	BRNE _0x85
; 0000 01C8      {
; 0000 01C9         backward_1(80);
	RCALL SUBOPT_0x13
; 0000 01CA         right_1(37);
	RCALL _right_1
; 0000 01CB         backward_1(80);
	LDI  R26,LOW(80)
	LDI  R27,0
	RCALL _backward_1
; 0000 01CC         right_1(38);
	LDI  R26,LOW(38)
	LDI  R27,0
	RCALL _right_1
; 0000 01CD      }
; 0000 01CE }
_0x85:
_0x84:
_0x82:
_0x80:
_0x2000005:
	LD   R16,Y+
	LD   R17,Y+
	RET
; .FEND
;
;void straight_1(int act_time)
; 0000 01D1 {
_straight_1:
; .FSTART _straight_1
; 0000 01D2     int i;
; 0000 01D3     int act_num = 100 * act_time;
; 0000 01D4     ADMUX = 0b01000000;
	RCALL SUBOPT_0x15
;	act_time -> Y+4
;	i -> R16,R17
;	act_num -> R18,R19
	LDI  R30,LOW(64)
	OUT  0x7,R30
; 0000 01D5     for(i = 1; i <= act_num; i++)
	__GETWRN 16,17,1
_0x87:
	__CPWRR 18,19,16,17
	BRLT _0x88
; 0000 01D6     {
; 0000 01D7         FRONTBACK_CHECK();
	RCALL _FRONTBACK_CHECK
; 0000 01D8         PORTA = 0b10101010;
	LDI  R30,LOW(170)
	RCALL SUBOPT_0x16
; 0000 01D9         delay_ms(1);
; 0000 01DA     }
	__ADDWRN 16,17,1
	RJMP _0x87
_0x88:
; 0000 01DB     PORTA = 0b00000000;
	RJMP _0x2000004
; 0000 01DC }
; .FEND
;void left_1(int act_time)
; 0000 01DE {
_left_1:
; .FSTART _left_1
; 0000 01DF     int i;
; 0000 01E0     ADCSRA = ADCSRA & 0b10111111;            //시계 반대 방향 선회중 전후방 적외선 센서 OFF
	RCALL SUBOPT_0x17
;	act_time -> R18,R19
;	i -> R16,R17
; 0000 01E1     for(i = 1; i <= act_time; i++)
_0x8A:
	__CPWRR 18,19,16,17
	BRLT _0x8B
; 0000 01E2     {
; 0000 01E3         PORTA = 0b10100101;
	LDI  R30,LOW(165)
	RCALL SUBOPT_0x18
; 0000 01E4         delay_ms(100);
; 0000 01E5     }
	__ADDWRN 16,17,1
	RJMP _0x8A
_0x8B:
; 0000 01E6     PORTA = 0b00000000;
	LDI  R30,LOW(0)
	OUT  0x1B,R30
; 0000 01E7     ADCSRA = ADCSRA | 0b01000000;            // 선회 완료시 적외선 센서 재작동
	SBI  0x6,6
; 0000 01E8 }
	RJMP _0x2000002
; .FEND
;void right_1(int act_time)
; 0000 01EA {
_right_1:
; .FSTART _right_1
; 0000 01EB     int i;
; 0000 01EC     ADCSRA = ADCSRA & 0b10111111;            //시계 방향 선회중 전후방 적외선 센서 OFF
	RCALL SUBOPT_0x17
;	act_time -> R18,R19
;	i -> R16,R17
; 0000 01ED     for(i = 1; i <= act_time; i++)
_0x8D:
	__CPWRR 18,19,16,17
	BRLT _0x8E
; 0000 01EE     {
; 0000 01EF         PORTA = 0b01011010;
	LDI  R30,LOW(90)
	RCALL SUBOPT_0x18
; 0000 01F0         delay_ms(100);
; 0000 01F1     }
	__ADDWRN 16,17,1
	RJMP _0x8D
_0x8E:
; 0000 01F2     PORTA = 0b00000000;
	LDI  R30,LOW(0)
	OUT  0x1B,R30
; 0000 01F3     ADCSRA = ADCSRA | 0b01000000;             // 선회 완료시 적외선 센서 재작동
	SBI  0x6,6
; 0000 01F4 }
	RJMP _0x2000002
; .FEND
;void backward_1(int act_time)
; 0000 01F6 {
_backward_1:
; .FSTART _backward_1
; 0000 01F7     int i;
; 0000 01F8     int act_num = 100 * act_time;
; 0000 01F9     ADMUX = 0b01000001;
	RCALL SUBOPT_0x15
;	act_time -> Y+4
;	i -> R16,R17
;	act_num -> R18,R19
	LDI  R30,LOW(65)
	OUT  0x7,R30
; 0000 01FA     for(i = 1; i <= act_num; i++)
	__GETWRN 16,17,1
_0x90:
	__CPWRR 18,19,16,17
	BRLT _0x91
; 0000 01FB     {
; 0000 01FC         FRONTBACK_CHECK();
	RCALL _FRONTBACK_CHECK
; 0000 01FD 
; 0000 01FE         PORTA = 0b01010101;
	LDI  R30,LOW(85)
	RCALL SUBOPT_0x16
; 0000 01FF         delay_ms(1);
; 0000 0200     }
	__ADDWRN 16,17,1
	RJMP _0x90
_0x91:
; 0000 0201     PORTA = 0b00000000;
_0x2000004:
	LDI  R30,LOW(0)
	OUT  0x1B,R30
; 0000 0202 }
	RCALL __LOADLOCR4
	ADIW R28,6
	RET
; .FEND
;void NEGLECT()
; 0000 0204 {
_NEGLECT:
; .FSTART _NEGLECT
; 0000 0205     delay_us(500);
	__DELAY_USW 2000
; 0000 0206 }
	RET
; .FEND
;//-----------------LCD-------------------
;
;void LCD_IDLE()
; 0000 020A {
_LCD_IDLE:
; .FSTART _LCD_IDLE
; 0000 020B     LCD_init();
	RCALL _LCD_init
; 0000 020C     LCD_String("2017161041");
	__POINTW2FN _0x0,347
	RCALL _LCD_String
; 0000 020D     Command(LINE2);
	LDI  R26,LOW(192)
	RCALL _Command
; 0000 020E     LCD_String("Serving Robot");
	__POINTW2FN _0x0,358
	RCALL _LCD_String
; 0000 020F }
	RET
; .FEND
;
;void LCD_mov()
; 0000 0212 {
_LCD_mov:
; .FSTART _LCD_mov
; 0000 0213     LCD_init();
	RCALL _LCD_init
; 0000 0214     LCD_String("MOVING POINT");
	__POINTW2FN _0x0,372
	RCALL _LCD_String
; 0000 0215     Command(LINE2);
	LDI  R26,LOW(192)
	RJMP _0x2000003
; 0000 0216 }
; .FEND
;
;void LCD_init(void)
; 0000 0219 {
_LCD_init:
; .FSTART _LCD_init
; 0000 021A     DDRD = 0xFF;
	LDI  R30,LOW(255)
	OUT  0x11,R30
; 0000 021B     PORTD &= 0xFB;
	CBI  0x12,2
; 0000 021C 
; 0000 021D     delay_ms(15);
	LDI  R26,LOW(15)
	RCALL SUBOPT_0x19
; 0000 021E     Command(0x20);
; 0000 021F     delay_ms(5);
	LDI  R26,LOW(5)
	RCALL SUBOPT_0x19
; 0000 0220     Command(0x20);
; 0000 0221     delay_us(100);
	__DELAY_USW 400
; 0000 0222     Command(0x20);
	LDI  R26,LOW(32)
	RCALL _Command
; 0000 0223     Command(FUNCSET);
	LDI  R26,LOW(40)
	RCALL _Command
; 0000 0224     Command(DISPON);
	LDI  R26,LOW(12)
	RCALL _Command
; 0000 0225     Command(ALLCLR);
	LDI  R26,LOW(1)
	RCALL _Command
; 0000 0226     Command(ENTMODE);
	LDI  R26,LOW(6)
_0x2000003:
	RCALL _Command
; 0000 0227 }
	RET
; .FEND
;
;void LCD_String(char flash *str)
; 0000 022A {
_LCD_String:
; .FSTART _LCD_String
; 0000 022B     char flash *pStr=0;
; 0000 022C 
; 0000 022D     pStr = str;
	RCALL __SAVELOCR4
	MOVW R18,R26
;	*str -> R18,R19
;	*pStr -> R16,R17
	__GETWRN 16,17,0
	MOVW R16,R18
; 0000 022E     while(*pStr) Data(*pStr++);
_0x92:
	MOVW R30,R16
	LPM  R30,Z
	CPI  R30,0
	BREQ _0x94
	MOVW R30,R16
	__ADDWRN 16,17,1
	LPM  R26,Z
	RCALL _Data
	RJMP _0x92
_0x94:
; 0000 022F }
_0x2000002:
	RCALL __LOADLOCR4
	ADIW R28,4
	RET
; .FEND
;
;void Command(unsigned char byte)
; 0000 0232 {
_Command:
; .FSTART _Command
; 0000 0233     Busy();
	RCALL SUBOPT_0x1A
;	byte -> R17
; 0000 0234 
; 0000 0235     PORTD = (byte & 0xF0);        // 데이터
; 0000 0236     PORTD &= 0xFE;            //RS = 0;
	CBI  0x12,0
; 0000 0237     PORTD &= 0xFD;            //RW = 0;
	RCALL SUBOPT_0x1B
; 0000 0238     delay_us(1);
; 0000 0239     PORTD |= 0x04;            //E = 1;
; 0000 023A     delay_us(1);
; 0000 023B     PORTD &= 0xFB;            //E = 0;
; 0000 023C 
; 0000 023D     PORTD = ((byte<<4) & 0xF0);    // 데이터
; 0000 023E     PORTD &= 0xFE;            //RS = 0;
	CBI  0x12,0
; 0000 023F     PORTD &= 0xFD;            //RW = 0;
	RJMP _0x2000001
; 0000 0240     delay_us(1);
; 0000 0241     PORTD |= 0x04;            //E = 1;
; 0000 0242     delay_us(1);
; 0000 0243     PORTD &= 0xFB;            //E = 0;
; 0000 0244 }
; .FEND
;
;void Data(unsigned char byte)
; 0000 0247 {
_Data:
; .FSTART _Data
; 0000 0248     Busy();
	RCALL SUBOPT_0x1A
;	byte -> R17
; 0000 0249 
; 0000 024A     PORTD = (byte & 0xF0);        // 데이터
; 0000 024B     PORTD |= 0x01;            //RS = 1;
	SBI  0x12,0
; 0000 024C     PORTD &= 0xFD;            //RW = 0;
	RCALL SUBOPT_0x1B
; 0000 024D     delay_us(1);
; 0000 024E     PORTD |= 0x04;            //E = 1;
; 0000 024F     delay_us(1);
; 0000 0250     PORTD &= 0xFB;            //E = 0;
; 0000 0251 
; 0000 0252     PORTD = ((byte<<4) & 0xF0);      // 데이터
; 0000 0253     PORTD |= 0x01;            //RS = 1;
	SBI  0x12,0
; 0000 0254     PORTD &= 0xFD;            //RW = 0;
_0x2000001:
	CBI  0x12,1
; 0000 0255     delay_us(1);
	__DELAY_USB 5
; 0000 0256     PORTD |= 0x04;            //E = 1;
	SBI  0x12,2
; 0000 0257     delay_us(1);
	__DELAY_USB 5
; 0000 0258     PORTD &= 0xFB;            //E = 0;
	CBI  0x12,2
; 0000 0259 }
	LD   R17,Y+
	RET
; .FEND
;
;void Busy(void)
; 0000 025C {
_Busy:
; .FSTART _Busy
; 0000 025D     delay_ms(2);
	LDI  R26,LOW(2)
	LDI  R27,0
	RCALL _delay_ms
; 0000 025E }
	RET
; .FEND

	.DSEG
_fval:
	.BYTE 0x4
_R_num:
	.BYTE 0x1

	.CSEG
;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x0:
	LDI  R30,LOW(49911)
	LDI  R31,HIGH(49911)
	OUT  0x2C+1,R31
	OUT  0x2C,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:18 WORDS
SUBOPT_0x1:
	IN   R30,0x4
	LDI  R31,0
	MOVW R26,R30
	IN   R30,0x5
	MOV  R31,R30
	LDI  R30,0
	ADD  R30,R26
	ADC  R31,R27
	MOVW R16,R30
	MOVW R26,R16
	RJMP _AD_DS

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x2:
	LDI  R30,LOW(4)
	LDI  R31,HIGH(4)
	CP   R30,R6
	CPC  R31,R7
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x3:
	MOVW R6,R30
	RCALL _waiting
	LDI  R30,LOW(5)
	LDI  R31,HIGH(5)
	MOVW R6,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0x4:
	ST   -Y,R0
	ST   -Y,R1
	ST   -Y,R15
	ST   -Y,R22
	ST   -Y,R23
	ST   -Y,R24
	ST   -Y,R25
	ST   -Y,R26
	ST   -Y,R27
	ST   -Y,R30
	ST   -Y,R31
	IN   R30,SREG
	ST   -Y,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x5:
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	CP   R30,R6
	CPC  R31,R7
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x6:
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	CP   R30,R6
	CPC  R31,R7
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x7:
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	MOVW R6,R30
	LDS  R26,_R_num
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x8:
	RCALL _LCD_String
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	MOVW R10,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x9:
	RCALL _LCD_String
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	MOVW R10,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0xA:
	RCALL _LCD_String
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	MOVW R10,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0xB:
	RCALL _LCD_String
	LDI  R30,LOW(4)
	LDI  R31,HIGH(4)
	MOVW R10,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xC:
	LDI  R30,LOW(130)
	LDI  R31,HIGH(130)
	CP   R4,R30
	CPC  R5,R31
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0xD:
	ST   -Y,R17
	ST   -Y,R16
	MOVW R16,R26
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	CP   R30,R16
	CPC  R31,R17
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:3 WORDS
SUBOPT_0xE:
	LDI  R26,LOW(20)
	LDI  R27,0
	RCALL _straight_1
	LDI  R26,LOW(33)
	LDI  R27,0
	RJMP _left_1

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xF:
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	CP   R30,R16
	CPC  R31,R17
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x10:
	LDI  R27,0
	RCALL _straight_1
	LDI  R26,LOW(37)
	LDI  R27,0
	RJMP _right_1

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x11:
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	CP   R30,R16
	CPC  R31,R17
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x12:
	LDI  R30,LOW(4)
	LDI  R31,HIGH(4)
	CP   R30,R16
	CPC  R31,R17
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x13:
	LDI  R26,LOW(80)
	LDI  R27,0
	RCALL _backward_1
	LDI  R26,LOW(37)
	LDI  R27,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x14:
	LDI  R27,0
	RCALL _backward_1
	LDI  R26,LOW(38)
	LDI  R27,0
	RJMP _left_1

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:6 WORDS
SUBOPT_0x15:
	ST   -Y,R27
	ST   -Y,R26
	RCALL __SAVELOCR4
	LDD  R30,Y+4
	LDD  R31,Y+4+1
	LDI  R26,LOW(100)
	LDI  R27,HIGH(100)
	RCALL __MULW12
	MOVW R18,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x16:
	OUT  0x1B,R30
	LDI  R26,LOW(1)
	LDI  R27,0
	RJMP _delay_ms

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x17:
	RCALL __SAVELOCR4
	MOVW R18,R26
	CBI  0x6,6
	__GETWRN 16,17,1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x18:
	OUT  0x1B,R30
	LDI  R26,LOW(100)
	LDI  R27,0
	RJMP _delay_ms

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x19:
	LDI  R27,0
	RCALL _delay_ms
	LDI  R26,LOW(32)
	RJMP _Command

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:3 WORDS
SUBOPT_0x1A:
	ST   -Y,R17
	MOV  R17,R26
	RCALL _Busy
	MOV  R30,R17
	ANDI R30,LOW(0xF0)
	OUT  0x12,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0x1B:
	CBI  0x12,1
	__DELAY_USB 5
	SBI  0x12,2
	__DELAY_USB 5
	CBI  0x12,2
	MOV  R30,R17
	SWAP R30
	ANDI R30,LOW(0xF0)
	OUT  0x12,R30
	RET

;RUNTIME LIBRARY

	.CSEG
__SAVELOCR4:
	ST   -Y,R19
__SAVELOCR3:
	ST   -Y,R18
__SAVELOCR2:
	ST   -Y,R17
	ST   -Y,R16
	RET

__LOADLOCR4:
	LDD  R19,Y+3
__LOADLOCR3:
	LDD  R18,Y+2
__LOADLOCR2:
	LDD  R17,Y+1
	LD   R16,Y
	RET

__ANEGW1:
	NEG  R31
	NEG  R30
	SBCI R31,0
	RET

__ANEGD1:
	COM  R31
	COM  R22
	COM  R23
	NEG  R30
	SBCI R31,-1
	SBCI R22,-1
	SBCI R23,-1
	RET

__CWD1:
	MOV  R22,R31
	ADD  R22,R22
	SBC  R22,R22
	MOV  R23,R22
	RET

__MULW12U:
	MUL  R31,R26
	MOV  R31,R0
	MUL  R30,R27
	ADD  R31,R0
	MUL  R30,R26
	MOV  R30,R0
	ADD  R31,R1
	RET

__MULW12:
	RCALL __CHKSIGNW
	RCALL __MULW12U
	BRTC __MULW121
	RCALL __ANEGW1
__MULW121:
	RET

__CHKSIGNW:
	CLT
	SBRS R31,7
	RJMP __CHKSW1
	RCALL __ANEGW1
	SET
__CHKSW1:
	SBRS R27,7
	RJMP __CHKSW2
	NEG  R27
	NEG  R26
	SBCI R27,0
	BLD  R0,0
	INC  R0
	BST  R0,0
__CHKSW2:
	RET

__ROUND_REPACK:
	TST  R21
	BRPL __REPACK
	CPI  R21,0x80
	BRNE __ROUND_REPACK0
	SBRS R30,0
	RJMP __REPACK
__ROUND_REPACK0:
	ADIW R30,1
	ADC  R22,R25
	ADC  R23,R25
	BRVS __REPACK1

__REPACK:
	LDI  R21,0x80
	EOR  R21,R23
	BRNE __REPACK0
	PUSH R21
	RJMP __ZERORES
__REPACK0:
	CPI  R21,0xFF
	BREQ __REPACK1
	LSL  R22
	LSL  R0
	ROR  R21
	ROR  R22
	MOV  R23,R21
	RET
__REPACK1:
	PUSH R21
	TST  R0
	BRMI __REPACK2
	RJMP __MAXRES
__REPACK2:
	RJMP __MINRES

__UNPACK:
	LDI  R21,0x80
	MOV  R1,R25
	AND  R1,R21
	LSL  R24
	ROL  R25
	EOR  R25,R21
	LSL  R21
	ROR  R24

__UNPACK1:
	LDI  R21,0x80
	MOV  R0,R23
	AND  R0,R21
	LSL  R22
	ROL  R23
	EOR  R23,R21
	LSL  R21
	ROR  R22
	RET

__CFD1U:
	SET
	RJMP __CFD1U0
__CFD1:
	CLT
__CFD1U0:
	PUSH R21
	RCALL __UNPACK1
	CPI  R23,0x80
	BRLO __CFD10
	CPI  R23,0xFF
	BRCC __CFD10
	RJMP __ZERORES
__CFD10:
	LDI  R21,22
	SUB  R21,R23
	BRPL __CFD11
	NEG  R21
	CPI  R21,8
	BRTC __CFD19
	CPI  R21,9
__CFD19:
	BRLO __CFD17
	SER  R30
	SER  R31
	SER  R22
	LDI  R23,0x7F
	BLD  R23,7
	RJMP __CFD15
__CFD17:
	CLR  R23
	TST  R21
	BREQ __CFD15
__CFD18:
	LSL  R30
	ROL  R31
	ROL  R22
	ROL  R23
	DEC  R21
	BRNE __CFD18
	RJMP __CFD15
__CFD11:
	CLR  R23
__CFD12:
	CPI  R21,8
	BRLO __CFD13
	MOV  R30,R31
	MOV  R31,R22
	MOV  R22,R23
	SUBI R21,8
	RJMP __CFD12
__CFD13:
	TST  R21
	BREQ __CFD15
__CFD14:
	LSR  R23
	ROR  R22
	ROR  R31
	ROR  R30
	DEC  R21
	BRNE __CFD14
__CFD15:
	TST  R0
	BRPL __CFD16
	RCALL __ANEGD1
__CFD16:
	POP  R21
	RET

__CDF1U:
	SET
	RJMP __CDF1U0
__CDF1:
	CLT
__CDF1U0:
	SBIW R30,0
	SBCI R22,0
	SBCI R23,0
	BREQ __CDF10
	CLR  R0
	BRTS __CDF11
	TST  R23
	BRPL __CDF11
	COM  R0
	RCALL __ANEGD1
__CDF11:
	MOV  R1,R23
	LDI  R23,30
	TST  R1
__CDF12:
	BRMI __CDF13
	DEC  R23
	LSL  R30
	ROL  R31
	ROL  R22
	ROL  R1
	RJMP __CDF12
__CDF13:
	MOV  R30,R31
	MOV  R31,R22
	MOV  R22,R1
	PUSH R21
	RCALL __REPACK
	POP  R21
__CDF10:
	RET

__SWAPACC:
	PUSH R20
	MOVW R20,R30
	MOVW R30,R26
	MOVW R26,R20
	MOVW R20,R22
	MOVW R22,R24
	MOVW R24,R20
	MOV  R20,R0
	MOV  R0,R1
	MOV  R1,R20
	POP  R20
	RET

__UADD12:
	ADD  R30,R26
	ADC  R31,R27
	ADC  R22,R24
	RET

__NEGMAN1:
	COM  R30
	COM  R31
	COM  R22
	SUBI R30,-1
	SBCI R31,-1
	SBCI R22,-1
	RET

__ADDF12:
	PUSH R21
	RCALL __UNPACK
	CPI  R25,0x80
	BREQ __ADDF129

__ADDF120:
	CPI  R23,0x80
	BREQ __ADDF128
__ADDF121:
	MOV  R21,R23
	SUB  R21,R25
	BRVS __ADDF1211
	BRPL __ADDF122
	RCALL __SWAPACC
	RJMP __ADDF121
__ADDF122:
	CPI  R21,24
	BRLO __ADDF123
	CLR  R26
	CLR  R27
	CLR  R24
__ADDF123:
	CPI  R21,8
	BRLO __ADDF124
	MOV  R26,R27
	MOV  R27,R24
	CLR  R24
	SUBI R21,8
	RJMP __ADDF123
__ADDF124:
	TST  R21
	BREQ __ADDF126
__ADDF125:
	LSR  R24
	ROR  R27
	ROR  R26
	DEC  R21
	BRNE __ADDF125
__ADDF126:
	MOV  R21,R0
	EOR  R21,R1
	BRMI __ADDF127
	RCALL __UADD12
	BRCC __ADDF129
	ROR  R22
	ROR  R31
	ROR  R30
	INC  R23
	BRVC __ADDF129
	RJMP __MAXRES
__ADDF128:
	RCALL __SWAPACC
__ADDF129:
	RCALL __REPACK
	POP  R21
	RET
__ADDF1211:
	BRCC __ADDF128
	RJMP __ADDF129
__ADDF127:
	SUB  R30,R26
	SBC  R31,R27
	SBC  R22,R24
	BREQ __ZERORES
	BRCC __ADDF1210
	COM  R0
	RCALL __NEGMAN1
__ADDF1210:
	TST  R22
	BRMI __ADDF129
	LSL  R30
	ROL  R31
	ROL  R22
	DEC  R23
	BRVC __ADDF1210

__ZERORES:
	CLR  R30
	CLR  R31
	MOVW R22,R30
	POP  R21
	RET

__MINRES:
	SER  R30
	SER  R31
	LDI  R22,0x7F
	SER  R23
	POP  R21
	RET

__MAXRES:
	SER  R30
	SER  R31
	LDI  R22,0x7F
	LDI  R23,0x7F
	POP  R21
	RET

__MULF12:
	PUSH R21
	RCALL __UNPACK
	CPI  R23,0x80
	BREQ __ZERORES
	CPI  R25,0x80
	BREQ __ZERORES
	EOR  R0,R1
	SEC
	ADC  R23,R25
	BRVC __MULF124
	BRLT __ZERORES
__MULF125:
	TST  R0
	BRMI __MINRES
	RJMP __MAXRES
__MULF124:
	PUSH R0
	PUSH R17
	PUSH R18
	PUSH R19
	PUSH R20
	CLR  R17
	CLR  R18
	CLR  R25
	MUL  R22,R24
	MOVW R20,R0
	MUL  R24,R31
	MOV  R19,R0
	ADD  R20,R1
	ADC  R21,R25
	MUL  R22,R27
	ADD  R19,R0
	ADC  R20,R1
	ADC  R21,R25
	MUL  R24,R30
	RCALL __MULF126
	MUL  R27,R31
	RCALL __MULF126
	MUL  R22,R26
	RCALL __MULF126
	MUL  R27,R30
	RCALL __MULF127
	MUL  R26,R31
	RCALL __MULF127
	MUL  R26,R30
	ADD  R17,R1
	ADC  R18,R25
	ADC  R19,R25
	ADC  R20,R25
	ADC  R21,R25
	MOV  R30,R19
	MOV  R31,R20
	MOV  R22,R21
	MOV  R21,R18
	POP  R20
	POP  R19
	POP  R18
	POP  R17
	POP  R0
	TST  R22
	BRMI __MULF122
	LSL  R21
	ROL  R30
	ROL  R31
	ROL  R22
	RJMP __MULF123
__MULF122:
	INC  R23
	BRVS __MULF125
__MULF123:
	RCALL __ROUND_REPACK
	POP  R21
	RET

__MULF127:
	ADD  R17,R0
	ADC  R18,R1
	ADC  R19,R25
	RJMP __MULF128
__MULF126:
	ADD  R18,R0
	ADC  R19,R1
__MULF128:
	ADC  R20,R25
	ADC  R21,R25
	RET

__DIVF21:
	PUSH R21
	RCALL __UNPACK
	CPI  R23,0x80
	BRNE __DIVF210
	TST  R1
__DIVF211:
	BRPL __DIVF219
	RJMP __MINRES
__DIVF219:
	RJMP __MAXRES
__DIVF210:
	CPI  R25,0x80
	BRNE __DIVF218
__DIVF217:
	RJMP __ZERORES
__DIVF218:
	EOR  R0,R1
	SEC
	SBC  R25,R23
	BRVC __DIVF216
	BRLT __DIVF217
	TST  R0
	RJMP __DIVF211
__DIVF216:
	MOV  R23,R25
	PUSH R17
	PUSH R18
	PUSH R19
	PUSH R20
	CLR  R1
	CLR  R17
	CLR  R18
	CLR  R19
	MOVW R20,R18
	LDI  R25,32
__DIVF212:
	CP   R26,R30
	CPC  R27,R31
	CPC  R24,R22
	CPC  R20,R17
	BRLO __DIVF213
	SUB  R26,R30
	SBC  R27,R31
	SBC  R24,R22
	SBC  R20,R17
	SEC
	RJMP __DIVF214
__DIVF213:
	CLC
__DIVF214:
	ROL  R21
	ROL  R18
	ROL  R19
	ROL  R1
	ROL  R26
	ROL  R27
	ROL  R24
	ROL  R20
	DEC  R25
	BRNE __DIVF212
	MOVW R30,R18
	MOV  R22,R1
	POP  R20
	POP  R19
	POP  R18
	POP  R17
	TST  R22
	BRMI __DIVF215
	LSL  R21
	ROL  R30
	ROL  R31
	ROL  R22
	DEC  R23
	BRVS __DIVF217
__DIVF215:
	RCALL __ROUND_REPACK
	POP  R21
	RET

_delay_ms:
	adiw r26,0
	breq __delay_ms1
__delay_ms0:
	wdr
	__DELAY_USW 0xFA0
	sbiw r26,1
	brne __delay_ms0
__delay_ms1:
	ret

;END OF CODE MARKER
__END_OF_CODE:
