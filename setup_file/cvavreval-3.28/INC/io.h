// CodeVisionAVR V3.28+ C Compiler
// (C) 1998-2016 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions

#ifndef _IO_INCLUDED_
#define _IO_INCLUDED_

#ifdef _CHIP_ATTINY10_
#include <tiny10.h>
#elif defined _CHIP_ATTINY102_
#include <tiny102.h>
#elif defined _CHIP_ATTINY104_
#include <tiny104.h>
#elif defined _CHIP_ATTINY13_
#include <tiny13.h>
#elif defined _CHIP_ATTINY13A_
#include <tiny13a.h>
#elif defined _CHIP_ATTINY1634_
#include <tiny1634.h>
#elif defined _CHIP_ATTINY167_
#include <tiny167.h>
#elif defined _CHIP_ATTINY20_
#include <tiny20.h>
#elif defined _CHIP_ATTINY22_ | defined _CHIP_ATTINY22L_
#include <tiny22.h>
#elif defined _CHIP_ATTINY2313_ | defined _CHIP_ATTINY2313V_
#include <tiny2313.h>
#elif defined _CHIP_ATTINY2313A_
#include <tiny2313a.h>
#elif defined _CHIP_ATTINY24_
#include <tiny24.h>
#elif defined _CHIP_ATTINY24A_
#include <tiny24a.h>
#elif defined _CHIP_ATTINY25_
#include <tiny25.h>
#elif defined _CHIP_ATTINY26_ | defined _CHIP_ATTINY26L_
#include <tiny26.h>
#elif defined _CHIP_ATTINY261_ | defined _CHIP_ATTINY261V_
#include <tiny261.h>
#elif defined _CHIP_ATTINY261A_
#include <tiny261a.h>
#elif defined _CHIP_ATTINY4_
#include <tiny4.h>
#elif defined _CHIP_ATTINY40_
#include <tiny40.h>
#elif defined _CHIP_ATTINY4313_
#include <tiny4313.h>
#elif defined _CHIP_ATTINY43U_
#include <tiny43u.h>
#elif defined _CHIP_ATTINY44_
#include <tiny44.h>
#elif defined _CHIP_ATTINY44A_
#include <tiny44a.h>
#elif defined _CHIP_ATTINY441_
#include <tiny441.h>
#elif defined _CHIP_ATTINY45_
#include <tiny45.h>
#elif defined _CHIP_ATTINY461_ | defined _CHIP_ATTINY461V_
#include <tiny461.h>
#elif defined _CHIP_ATTINY461A_
#include <tiny461a.h>
#elif defined _CHIP_ATTINY48_ | defined _CHIP_ATTINY48V_
#include <tiny48.h>
#elif defined _CHIP_ATTINY5_
#include <tiny5.h>
#elif defined _CHIP_ATTINY828_
#include <tiny828.h>
#elif defined _CHIP_ATTINY84_
#include <tiny84.h>
#elif defined _CHIP_ATTINY84A_
#include <tiny84a.h>
#elif defined _CHIP_ATTINY841_
#include <tiny841.h>
#elif defined _CHIP_ATTINY85_
#include <tiny85.h>
#elif defined _CHIP_ATTINY861_ | defined _CHIP_ATTINY861V_
#include <tiny861.h>
#elif defined _CHIP_ATTINY861A_
#include <tiny861a.h>
#elif defined _CHIP_ATTINY87_
#include <tiny87.h>
#elif defined _CHIP_ATTINY88_ | defined _CHIP_ATTINY88V_
#include <tiny88.h>
#elif defined _CHIP_ATTINY9_
#include <tiny9.h>
#elif defined _CHIP_AT90S2313_
#include <90s2313.h>
#elif defined _CHIP_AT90S2323_ | defined _CHIP_AT90LS2323_
#include <90s2323.h>
#elif defined _CHIP_AT90S2333_ | defined _CHIP_AT90LS2333_
#include <90s2333.h>
#elif defined _CHIP_AT90S2343_ | defined _CHIP_AT90LS2343_
#include <90s2343.h>
#elif defined _CHIP_AT90S4414_
#include <90s4414.h>
#elif defined _CHIP_AT90S4433_ | defined _CHIP_AT90LS4433_
#include <90s4433.h>
#elif defined _CHIP_AT90S4434_ | defined _CHIP_AT90LS4434_
#include <90s4434.h>
#elif defined _CHIP_AT90S8515_
#include <90s8515.h>
#elif defined _CHIP_AT90C8534_
#include <90c8534.h>
#elif defined _CHIP_AT90S8535_ | defined _CHIP_AT90LS8535_
#include <90s8535.h>
#elif defined _CHIP_AT90CAN128_
#include <90can128.h>
#elif defined _CHIP_AT90CAN32_
#include <90can32.h>
#elif defined _CHIP_AT90CAN64_
#include <90can64.h>
#elif defined _CHIP_AT90PWM2_
#include <90pwm2.h>
#elif defined _CHIP_AT90PWM2B_
#include <90pwm2b.h>
#elif defined _CHIP_AT90PWM216_
#include <90pwm216.h>
#elif defined _CHIP_AT90PWM3_
#include <90pwm3.h>
#elif defined _CHIP_AT90PWM3B_
#include <90pwm3b.h>
#elif defined _CHIP_AT90PWM316_
#include <90pwm316.h>
#elif defined _CHIP_AT90USB1286_
#include <90usb1286.h>
#elif defined _CHIP_AT90USB1287_
#include <90usb1287.h>
#elif defined _CHIP_AT90USB162_
#include <90usb162.h>
#elif defined _CHIP_AT90USB646_
#include <90usb646.h>
#elif defined _CHIP_AT90USB647_
#include <90usb647.h>
#elif defined _CHIP_AT90USB82_
#include <90usb82.h>
#elif defined _CHIP_ATA6285_
#include <ata6285.h>
#elif defined _CHIP_ATA6286_
#include <ata6286.h>
#elif defined _CHIP_ATA6289_
#include <ata6289.h>
#elif defined _CHIP_ATMEGA103_ | defined _CHIP_ATMEGA103L_
#include <mega103.h>
#elif defined _CHIP_ATMEGA128_ | defined _CHIP_ATMEGA128L_
#include <mega128.h>
#elif defined _CHIP_ATMEGA128A_
#include <mega128a.h>
#elif defined _CHIP_ATMEGA128RFA1_
#include <mega128rfa1.h>
#elif defined _CHIP_ATMEGA128RFR2_
#include <mega128rfr2.h>
#elif defined _CHIP_ATMEGA1280_ | defined _CHIP_ATMEGA1280V_
#include <mega1280.h>
#elif defined _CHIP_ATMEGA1281_ | defined _CHIP_ATMEGA1281V_
#include <mega1281.h>
#elif defined _CHIP_ATMEGA1284_
#include <mega1284.h>
#elif defined _CHIP_ATMEGA1284P_
#include <mega1284p.h>
#elif defined _CHIP_ATMEGA16_ | defined _CHIP_ATMEGA16L_
#include <mega16.h>
#elif defined _CHIP_ATMEGA16A_
#include <mega16a.h>
#elif defined _CHIP_ATMEGA16HVA_
#include <mega16hva.h>
#elif defined _CHIP_ATMEGA16HVB_
#include <mega16hvb.h>
#elif defined _CHIP_ATMEGA16M1_
#include <mega16m1.h>
#elif defined _CHIP_ATMEGA16U2_
#include <mega16u2.h>
#elif defined _CHIP_ATMEGA16U4_
#include <mega16u4.h>
#elif defined _CHIP_ATMEGA161_ | defined _CHIP_ATMEGA161L_
#include <mega161.h>
#elif defined _CHIP_ATMEGA162_ | defined _CHIP_ATMEGA162L_ | defined _CHIP_ATMEGA162U_ | defined _CHIP_ATMEGA162V_
#include <mega162.h>
#elif defined _CHIP_ATMEGA163_ | defined _CHIP_ATMEGA163L_
#include <mega163.h>
#elif defined _CHIP_ATMEGA164_ | defined _CHIP_ATMEGA164V_ | defined _CHIP_ATMEGA164P_ | defined _CHIP_ATMEGA164PV_
#include <mega164.h>
#elif defined _CHIP_ATMEGA164A_ | defined _CHIP_ATMEGA164PA_
#include <mega164a.h>
#elif defined _CHIP_ATMEGA165_ | defined _CHIP_ATMEGA165V_
#include <mega165.h>
#elif defined _CHIP_ATMEGA165A_ | defined _CHIP_ATMEGA165PA_
#include <mega165a.h>
#elif defined _CHIP_ATMEGA168_ | defined _CHIP_ATMEGA168V_
#include <mega168.h>
#elif defined _CHIP_ATMEGA168A_ | defined _CHIP_ATMEGA168PA_
#include <mega168a.h>
#elif defined _CHIP_ATMEGA168PB_ // 16122014_1
#include <mega168pb.h>
#elif defined _CHIP_ATMEGA168P_ | defined _CHIP_ATMEGA168PV_
#include <mega168p.h>
#elif defined _CHIP_ATMEGA169_ | defined _CHIP_ATMEGA169L_ | defined _CHIP_ATMEGA169V_
#include <mega169.h>
#elif defined _CHIP_ATMEGA169P_
#include <mega169p.h>
#elif defined _CHIP_ATMEGA169A_ | defined _CHIP_ATMEGA169PA_
#include <mega169a.h>
#elif defined _CHIP_ATMEGA256RFR2_
#include <mega256rfr2.h>
#elif defined _CHIP_ATMEGA2560_ | defined _CHIP_ATMEGA2560V_
#include <mega2560.h>
#elif defined _CHIP_ATMEGA2561_ | defined _CHIP_ATMEGA2561V_
#include <mega2561.h>
#elif defined _CHIP_ATMEGA32_ | defined _CHIP_ATMEGA32L_
#include <mega32.h>
#elif defined _CHIP_ATMEGA32A_
#include <mega32a.h>
#elif defined _CHIP_ATMEGA32C1_
#include <mega32c1.h>
#elif defined _CHIP_ATMEGA32HVB_
#include <mega32hvb.h>
#elif defined _CHIP_ATMEGA32M1_
#include <mega32m1.h>
#elif defined _CHIP_ATMEGA32U2_
#include <mega32u2.h>
#elif defined _CHIP_ATMEGA32U4_
#include <mega32u4.h>
#elif defined _CHIP_ATMEGA32U6_
#include <mega32u6.h>
#elif defined _CHIP_ATMEGA323_ | defined _CHIP_ATMEGA323L_
#include <mega323.h>
#elif defined _CHIP_ATMEGA324_ | defined _CHIP_ATMEGA324V_ | defined _CHIP_ATMEGA324P_ | defined _CHIP_ATMEGA324PV_
#include <mega324.h>
#elif defined _CHIP_ATMEGA324A_ | defined _CHIP_ATMEGA324PA_
#include <mega324a.h>
#elif defined _CHIP_ATMEGA324PB_
#include <mega324pb.h>
#elif defined _CHIP_ATMEGA325_ | defined _CHIP_ATMEGA325V_
#include <mega325.h>
#elif defined _CHIP_ATMEGA325A_ | defined _CHIP_ATMEGA325PA_
#include <mega325a.h>
#elif defined _CHIP_ATMEGA325P_ | defined _CHIP_ATMEGA325PV_
#include <mega325p.h>
#elif defined _CHIP_ATMEGA3250_ | defined _CHIP_ATMEGA3250V_
#include <mega3250.h>
#elif defined _CHIP_ATMEGA3250A_ | defined _CHIP_ATMEGA3250PA_
#include <mega3250a.h>
#elif defined _CHIP_ATMEGA3250P_ | defined _CHIP_ATMEGA3250PV_
#include <mega3250p.h>
#elif defined _CHIP_ATMEGA328_
#include <mega328.h>
#elif defined _CHIP_ATMEGA328P_ | defined _CHIP_ATMEGA328PV_
#include <mega328p.h>
#elif defined _CHIP_ATMEGA328PB_
#include <mega328pb.h>
#elif defined _CHIP_ATMEGA329_ | defined _CHIP_ATMEGA329V_
#include <mega329.h>
#elif defined _CHIP_ATMEGA329A_ | defined _CHIP_ATMEGA329PA_
#include <mega329a.h>
#elif defined _CHIP_ATMEGA329P_ | defined _CHIP_ATMEGA329PV_
#include <mega329p.h>
#elif defined _CHIP_ATMEGA3290_ | defined _CHIP_ATMEGA3290V_
#include <mega3290.h>
#elif defined _CHIP_ATMEGA3290A_ | defined _CHIP_ATMEGA3290PA_
#include <mega3290a.h>
#elif defined _CHIP_ATMEGA3290P_ | defined _CHIP_ATMEGA3290PV_
#include <mega3290p.h>
#elif defined _CHIP_ATMEGA406_
#include <mega406.h>
#elif defined _CHIP_ATMEGA48_ | defined _CHIP_ATMEGA48V_
#include <mega48.h>
#elif defined _CHIP_ATMEGA48A_ | defined _CHIP_ATMEGA48PA_
#include <mega48a.h>
#elif defined _CHIP_ATMEGA48PB_ // 16122014_1
#include <mega48pb.h>
#elif defined _CHIP_ATMEGA48P_ | defined _CHIP_ATMEGA48PV_
#include <mega48p.h>
#elif defined _CHIP_ATMEGA603_ | defined _CHIP_ATMEGA603L_
#include <mega603.h>
#elif defined _CHIP_ATMEGA64_ | defined _CHIP_ATMEGA64L_
#include <mega64.h>
#elif defined _CHIP_ATMEGA64A_
#include <mega64a.h>
#elif defined _CHIP_ATMEGA64C1_
#include <mega64c1.h>
#elif defined _CHIP_ATMEGA64M1_
#include <mega64m1.h>
#elif defined _CHIP_ATMEGA64RFR2_
#include <mega64rfr2.h>
#elif defined _CHIP_ATMEGA640_ | defined _CHIP_ATMEGA640V_
#include <mega640.h>
#elif defined _CHIP_ATMEGA644_ | defined _CHIP_ATMEGA644V_
#include <mega644.h>
#elif defined _CHIP_ATMEGA644P_ | defined _CHIP_ATMEGA644PV_
#include <mega644p.h>
#elif defined _CHIP_ATMEGA644A_ | defined _CHIP_ATMEGA644PA_
#include <mega644a.h>
#elif defined _CHIP_ATMEGA645_ | defined _CHIP_ATMEGA645V_
#include <mega645.h>
#elif defined _CHIP_ATMEGA645A_ | defined _CHIP_ATMEGA645VP_
#include <mega645a.h>
#elif defined _CHIP_ATMEGA6450_ | defined _CHIP_ATMEGA6450V_
#include <mega6450.h>
#elif defined _CHIP_ATMEGA6450A_ | defined _CHIP_ATMEGA6450P_
#include <mega6450a.h>
#elif defined _CHIP_ATMEGA649_ | defined _CHIP_ATMEGA649V_
#include <mega649.h>
#elif defined _CHIP_ATMEGA649A_ | defined _CHIP_ATMEGA649P_
#include <mega649a.h>
#elif defined _CHIP_ATMEGA6490_ | defined _CHIP_ATMEGA6490V_
#include <mega6490.h>
#elif defined _CHIP_ATMEGA6490A_ | defined _CHIP_ATMEGA6490P_
#include <mega6490a.h>
#elif defined _CHIP_ATMEGA8_ | defined _CHIP_ATMEGA8L_ | defined _CHIP_ATMEGA8A_
#include <mega8.h>
#elif defined _CHIP_ATMEGA8HVA_
#include <mega8hva.h>
#elif defined _CHIP_ATMEGA8U2_
#include <mega8u2.h>
#elif defined _CHIP_ATMEGA8515_ | defined _CHIP_ATMEGA8515L_
#include <mega8515.h>
#elif defined _CHIP_ATMEGA8535_ | defined _CHIP_ATMEGA8535L_
#include <mega8535.h>
#elif defined _CHIP_ATMEGA88_ | defined _CHIP_ATMEGA88V_
#include <mega88.h>
#elif defined _CHIP_ATMEGA88A_ | defined _CHIP_ATMEGA88PA_
#include <mega88a.h>
#elif defined _CHIP_ATMEGA88PB_ // 16122014_1
#include <mega88pb.h>
#elif defined _CHIP_ATMEGA88P_ | defined _CHIP_ATMEGA88PV_
#include <mega88p.h>
#elif defined _CHIP_ATXMEGA128A1_
#include <xmega128a1.h>
#elif defined _CHIP_ATXMEGA128A1U_
#include <xmega128a1u.h>
#elif defined _CHIP_ATXMEGA128A3_
#include <xmega128a3.h>
#elif defined _CHIP_ATXMEGA128A3U_
#include <xmega128a3u.h>
#elif defined _CHIP_ATXMEGA128A4_
#include <xmega128a4.h>
#elif defined _CHIP_ATXMEGA128A4U_
#include <xmega128a4u.h>
#elif defined _CHIP_ATXMEGA128B1_
#include <xmega128b1.h>
#elif defined _CHIP_ATXMEGA128B3_
#include <xmega128b3.h>
#elif defined _CHIP_ATXMEGA128C3_
#include <xmega128c3.h>
#elif defined _CHIP_ATXMEGA128D3_
#include <xmega128d3.h>
#elif defined _CHIP_ATXMEGA128D4_
#include <xmega128d4.h>
#elif defined _CHIP_ATXMEGA16A4_
#include <xmega16a4.h>
#elif defined _CHIP_ATXMEGA16A4U_
#include <xmega16a4u.h>
#elif defined _CHIP_ATXMEGA16C4_
#include <xmega16c4.h>
#elif defined _CHIP_ATXMEGA16D4_
#include <xmega16d4.h>
#elif defined _CHIP_ATXMEGA16E5_
#include <xmega16e5.h>
#elif defined _CHIP_ATXMEGA192A1_
#include <xmega192a1.h>
#elif defined _CHIP_ATXMEGA192A3_
#include <xmega192a3.h>
#elif defined _CHIP_ATXMEGA192A3U_
#include <xmega192a3u.h>
#elif defined _CHIP_ATXMEGA192C3_
#include <xmega192c3.h>
#elif defined _CHIP_ATXMEGA192D3_
#include <xmega192d3.h>
#elif defined _CHIP_ATXMEGA256A1_
#include <xmega256a1.h>
#elif defined _CHIP_ATXMEGA256A3_
#include <xmega256a3.h>
#elif defined _CHIP_ATXMEGA256A3U_
#include <xmega256a3u.h>
#elif defined _CHIP_ATXMEGA256A3B_
#include <xmega256a3b.h>
#elif defined _CHIP_ATXMEGA256A3BU_
#include <xmega256a3bu.h>
#elif defined _CHIP_ATXMEGA256C3_
#include <xmega256c3.h>
#elif defined _CHIP_ATXMEGA256D3_
#include <xmega256d3.h>
#elif defined _CHIP_ATXMEGA384C3_
#include <xmega384c3.h>
#elif defined _CHIP_ATXMEGA384D3_
#include <xmega384d3.h>
#elif defined _CHIP_ATXMEGA32A4_
#include <xmega32a4.h>
#elif defined _CHIP_ATXMEGA32A4U_
#include <xmega32a4u.h>
#elif defined _CHIP_ATXMEGA32C3_
#include <xmega32c3.h>
#elif defined _CHIP_ATXMEGA32C4_
#include <xmega32c4.h>
#elif defined _CHIP_ATXMEGA32D3_
#include <xmega32d3.h>
#elif defined _CHIP_ATXMEGA32D4_
#include <xmega32d4.h>
#elif defined _CHIP_ATXMEGA32E5_
#include <xmega32e5.h>
#elif defined _CHIP_ATXMEGA384A1_
#include <xmega384a1.h>
#elif defined _CHIP_ATXMEGA64A1_
#include <xmega64a1.h>
#elif defined _CHIP_ATXMEGA64A1U_
#include <xmega64a1u.h>
#elif defined _CHIP_ATXMEGA64A3_
#include <xmega64a3.h>
#elif defined _CHIP_ATXMEGA64A3U_
#include <xmega64a3u.h>
#elif defined _CHIP_ATXMEGA64A4_
#include <xmega64a4.h>
#elif defined _CHIP_ATXMEGA64A4U_
#include <xmega64a4u.h>
#elif defined _CHIP_ATXMEGA64B1_
#include <xmega64b1.h>
#elif defined _CHIP_ATXMEGA64B3_
#include <xmega64b3.h>
#elif defined _CHIP_ATXMEGA64C3_
#include <xmega64c3.h>
#elif defined _CHIP_ATXMEGA64D3_
#include <xmega64d3.h>
#elif defined _CHIP_ATXMEGA64D4_
#include <xmega64d4.h>
#elif defined _CHIP_ATXMEGA8E5_
#include <xmega8e5.h>
#elif defined _CHIP_AT43USB355_
#include <43usb355.h>
#elif defined _CHIP_AT76C711_
#include <76c711.h>
#elif defined _CHIP_AT86RF401_
#include <86rf401.h>
#elif defined _CHIP_AT94K05_ | defined _CHIP_AT94K_
#include <94k.h>
#endif

#endif
