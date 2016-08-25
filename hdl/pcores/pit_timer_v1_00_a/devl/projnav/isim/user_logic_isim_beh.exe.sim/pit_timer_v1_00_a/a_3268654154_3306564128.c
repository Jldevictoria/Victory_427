/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xc3576ebc */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Victory_427/Space_Invaders_Lab_4/pcores/pit_timer_v1_00_a/hdl/vhdl/user_logic.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

unsigned char ieee_p_2592010699_sub_2545490612_503743352(char *, unsigned char , unsigned char );
unsigned char ieee_p_3620187407_sub_2546418145_3965413181(char *, char *, char *, int );
unsigned char ieee_p_3620187407_sub_3905759485_3965413181(char *, char *, char *, int );
char *ieee_p_3620187407_sub_436351764_3965413181(char *, char *, char *, char *, int );


static void pit_timer_v1_00_a_a_3268654154_3306564128_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(174, ng0);

LAB3:    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t3 = (2 - 2);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t6 = (t0 + 9768);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t6);

LAB2:    t11 = (t0 + 9496);
    *((int *)t11) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(175, ng0);

LAB3:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = (2 - 2);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t6 = (t0 + 9832);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t6);

LAB2:    t11 = (t0 + 9512);
    *((int *)t11) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_2(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned char t14;
    unsigned char t15;
    char *t16;
    char *t17;
    int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned char t22;
    unsigned char t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;

LAB0:    xsi_set_current_line(176, ng0);

LAB3:    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t3 = (0 - 2);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 1992U);
    t9 = *((char **)t8);
    t10 = (1 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t8 = (t9 + t13);
    t14 = *((unsigned char *)t8);
    t15 = ieee_p_2592010699_sub_2545490612_503743352(IEEE_P_2592010699, t7, t14);
    t16 = (t0 + 1992U);
    t17 = *((char **)t16);
    t18 = (2 - 2);
    t19 = (t18 * -1);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t16 = (t17 + t21);
    t22 = *((unsigned char *)t16);
    t23 = ieee_p_2592010699_sub_2545490612_503743352(IEEE_P_2592010699, t15, t22);
    t24 = (t0 + 9896);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    *((unsigned char *)t28) = t23;
    xsi_driver_first_trans_fast(t24);

LAB2:    t29 = (t0 + 9528);
    *((int *)t29) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_3(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned char t14;
    unsigned char t15;
    char *t16;
    char *t17;
    int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned char t22;
    unsigned char t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;

LAB0:    xsi_set_current_line(177, ng0);

LAB3:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = (0 - 2);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 1832U);
    t9 = *((char **)t8);
    t10 = (1 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t8 = (t9 + t13);
    t14 = *((unsigned char *)t8);
    t15 = ieee_p_2592010699_sub_2545490612_503743352(IEEE_P_2592010699, t7, t14);
    t16 = (t0 + 1832U);
    t17 = *((char **)t16);
    t18 = (2 - 2);
    t19 = (t18 * -1);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t16 = (t17 + t21);
    t22 = *((unsigned char *)t16);
    t23 = ieee_p_2592010699_sub_2545490612_503743352(IEEE_P_2592010699, t15, t22);
    t24 = (t0 + 9960);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    *((unsigned char *)t28) = t23;
    xsi_driver_first_trans_fast(t24);

LAB2:    t29 = (t0 + 9544);
    *((int *)t29) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_4(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(178, ng0);

LAB3:    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t3 = (0 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 10024);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast(t8);

LAB2:    t13 = (t0 + 9560);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_5(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(179, ng0);

LAB3:    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t3 = (1 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 10088);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast(t8);

LAB2:    t13 = (t0 + 9576);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_6(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(180, ng0);

LAB3:    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t3 = (2 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 10152);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast(t8);

LAB2:    t13 = (t0 + 9592);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_7(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    int t17;
    int t18;
    int t19;
    int t20;
    int t21;
    int t22;
    int t23;
    int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    int t30;
    int t31;
    int t32;
    unsigned int t33;
    char *t34;
    int t35;
    int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    int t41;
    int t42;
    int t43;
    char *t44;
    int t45;
    int t46;
    int t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    int t51;
    int t52;
    int t53;
    char *t54;
    int t55;
    int t56;
    int t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    int t61;
    int t62;
    int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    int t73;
    int t74;
    int t75;
    char *t76;
    int t77;
    int t78;
    int t79;
    unsigned int t80;
    unsigned int t81;
    char *t82;
    int t83;
    int t84;
    int t85;
    char *t86;
    int t87;
    int t88;
    int t89;
    unsigned int t90;
    unsigned int t91;

LAB0:    xsi_set_current_line(186, ng0);
    t2 = (t0 + 1152U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 9608);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(187, ng0);
    t4 = (t0 + 1352U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)2);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(191, ng0);
    t2 = (t0 + 3272U);
    t4 = *((char **)t2);
    t2 = (t0 + 16488);
    t17 = xsi_mem_cmp(t2, t4, 3U);
    if (t17 == 1)
        goto LAB12;

LAB15:    t8 = (t0 + 16491);
    t18 = xsi_mem_cmp(t8, t4, 3U);
    if (t18 == 1)
        goto LAB13;

LAB16:
LAB14:    xsi_set_current_line(204, ng0);

LAB11:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1192U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(188, ng0);
    t4 = xsi_get_transient_memory(32U);
    memset(t4, 0, 32U);
    t11 = t4;
    memset(t11, (unsigned char)2, 32U);
    t12 = (t0 + 10216);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 32U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(189, ng0);
    t2 = xsi_get_transient_memory(32U);
    memset(t2, 0, 32U);
    t4 = t2;
    memset(t4, (unsigned char)2, 32U);
    t5 = (t0 + 10280);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    goto LAB9;

LAB12:    xsi_set_current_line(193, ng0);
    t19 = (32 / 8);
    t20 = (t19 - 1);
    t12 = (t0 + 16494);
    *((int *)t12) = 0;
    t13 = (t0 + 16498);
    *((int *)t13) = t20;
    t21 = 0;
    t22 = t20;

LAB18:    if (t21 <= t22)
        goto LAB19;

LAB21:    goto LAB11;

LAB13:    xsi_set_current_line(199, ng0);
    t17 = (32 / 8);
    t18 = (t17 - 1);
    t2 = (t0 + 16502);
    *((int *)t2) = 0;
    t4 = (t0 + 16506);
    *((int *)t4) = t18;
    t19 = 0;
    t20 = t18;

LAB28:    if (t19 <= t20)
        goto LAB29;

LAB31:    goto LAB11;

LAB17:;
LAB19:    xsi_set_current_line(194, ng0);
    t14 = (t0 + 1672U);
    t15 = *((char **)t14);
    t14 = (t0 + 16494);
    t23 = *((int *)t14);
    t24 = (t23 - 3);
    t25 = (t24 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, *((int *)t14));
    t26 = (1U * t25);
    t27 = (0 + t26);
    t16 = (t15 + t27);
    t1 = *((unsigned char *)t16);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB22;

LAB24:
LAB23:
LAB20:    t2 = (t0 + 16494);
    t21 = *((int *)t2);
    t4 = (t0 + 16498);
    t22 = *((int *)t4);
    if (t21 == t22)
        goto LAB21;

LAB27:    t17 = (t21 + 1);
    t21 = t17;
    t5 = (t0 + 16494);
    *((int *)t5) = t21;
    goto LAB18;

LAB22:    xsi_set_current_line(195, ng0);
    t28 = (t0 + 1512U);
    t29 = *((char **)t28);
    t28 = (t0 + 16494);
    t30 = *((int *)t28);
    t31 = (t30 * 8);
    t32 = (t31 + 7);
    t33 = (31 - t32);
    t34 = (t0 + 16494);
    t35 = *((int *)t34);
    t36 = (t35 * 8);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t32, t36, -1);
    t37 = (t33 * 1U);
    t38 = (0 + t37);
    t39 = (t29 + t38);
    t40 = (t0 + 16494);
    t41 = *((int *)t40);
    t42 = (t41 * 8);
    t43 = (t42 + 7);
    t44 = (t0 + 16494);
    t45 = *((int *)t44);
    t46 = (t45 * 8);
    t47 = (t46 - t43);
    t48 = (t47 * -1);
    t48 = (t48 + 1);
    t49 = (1U * t48);
    t50 = (t0 + 16494);
    t51 = *((int *)t50);
    t52 = (t51 * 8);
    t53 = (t52 + 7);
    t54 = (t0 + 16494);
    t55 = *((int *)t54);
    t56 = (t55 * 8);
    t57 = (t56 - t53);
    t58 = (t57 * -1);
    t58 = (t58 + 1);
    t59 = (1U * t58);
    t6 = (t49 != t59);
    if (t6 == 1)
        goto LAB25;

LAB26:    t60 = (t0 + 16494);
    t61 = *((int *)t60);
    t62 = (t61 * 8);
    t63 = (t62 + 7);
    t64 = (31 - t63);
    t65 = (1U * t64);
    t66 = (0U + t65);
    t67 = (t0 + 10216);
    t68 = (t67 + 56U);
    t69 = *((char **)t68);
    t70 = (t69 + 56U);
    t71 = *((char **)t70);
    t72 = (t0 + 16494);
    t73 = *((int *)t72);
    t74 = (t73 * 8);
    t75 = (t74 + 7);
    t76 = (t0 + 16494);
    t77 = *((int *)t76);
    t78 = (t77 * 8);
    t79 = (t78 - t75);
    t80 = (t79 * -1);
    t80 = (t80 + 1);
    t81 = (1U * t80);
    memcpy(t71, t39, t81);
    t82 = (t0 + 16494);
    t83 = *((int *)t82);
    t84 = (t83 * 8);
    t85 = (t84 + 7);
    t86 = (t0 + 16494);
    t87 = *((int *)t86);
    t88 = (t87 * 8);
    t89 = (t88 - t85);
    t90 = (t89 * -1);
    t90 = (t90 + 1);
    t91 = (1U * t90);
    xsi_driver_first_trans_delta(t67, t66, t91, 0LL);
    goto LAB23;

LAB25:    xsi_size_not_matching(t49, t59, 0);
    goto LAB26;

LAB29:    xsi_set_current_line(200, ng0);
    t5 = (t0 + 1672U);
    t8 = *((char **)t5);
    t5 = (t0 + 16502);
    t21 = *((int *)t5);
    t22 = (t21 - 3);
    t25 = (t22 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, *((int *)t5));
    t26 = (1U * t25);
    t27 = (0 + t26);
    t11 = (t8 + t27);
    t1 = *((unsigned char *)t11);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB32;

LAB34:
LAB33:
LAB30:    t2 = (t0 + 16502);
    t19 = *((int *)t2);
    t4 = (t0 + 16506);
    t20 = *((int *)t4);
    if (t19 == t20)
        goto LAB31;

LAB37:    t17 = (t19 + 1);
    t19 = t17;
    t5 = (t0 + 16502);
    *((int *)t5) = t19;
    goto LAB28;

LAB32:    xsi_set_current_line(201, ng0);
    t12 = (t0 + 1512U);
    t13 = *((char **)t12);
    t12 = (t0 + 16502);
    t23 = *((int *)t12);
    t24 = (t23 * 8);
    t30 = (t24 + 7);
    t33 = (31 - t30);
    t14 = (t0 + 16502);
    t31 = *((int *)t14);
    t32 = (t31 * 8);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t30, t32, -1);
    t37 = (t33 * 1U);
    t38 = (0 + t37);
    t15 = (t13 + t38);
    t16 = (t0 + 16502);
    t35 = *((int *)t16);
    t36 = (t35 * 8);
    t41 = (t36 + 7);
    t28 = (t0 + 16502);
    t42 = *((int *)t28);
    t43 = (t42 * 8);
    t45 = (t43 - t41);
    t48 = (t45 * -1);
    t48 = (t48 + 1);
    t49 = (1U * t48);
    t29 = (t0 + 16502);
    t46 = *((int *)t29);
    t47 = (t46 * 8);
    t51 = (t47 + 7);
    t34 = (t0 + 16502);
    t52 = *((int *)t34);
    t53 = (t52 * 8);
    t55 = (t53 - t51);
    t58 = (t55 * -1);
    t58 = (t58 + 1);
    t59 = (1U * t58);
    t6 = (t49 != t59);
    if (t6 == 1)
        goto LAB35;

LAB36:    t39 = (t0 + 16502);
    t56 = *((int *)t39);
    t57 = (t56 * 8);
    t61 = (t57 + 7);
    t64 = (31 - t61);
    t65 = (1U * t64);
    t66 = (0U + t65);
    t40 = (t0 + 10280);
    t44 = (t40 + 56U);
    t50 = *((char **)t44);
    t54 = (t50 + 56U);
    t60 = *((char **)t54);
    t67 = (t0 + 16502);
    t62 = *((int *)t67);
    t63 = (t62 * 8);
    t73 = (t63 + 7);
    t68 = (t0 + 16502);
    t74 = *((int *)t68);
    t75 = (t74 * 8);
    t77 = (t75 - t73);
    t80 = (t77 * -1);
    t80 = (t80 + 1);
    t81 = (1U * t80);
    memcpy(t60, t15, t81);
    t69 = (t0 + 16502);
    t78 = *((int *)t69);
    t79 = (t78 * 8);
    t83 = (t79 + 7);
    t70 = (t0 + 16502);
    t84 = *((int *)t70);
    t85 = (t84 * 8);
    t87 = (t85 - t83);
    t90 = (t87 * -1);
    t90 = (t90 + 1);
    t91 = (1U * t90);
    xsi_driver_first_trans_delta(t40, t66, t91, 0LL);
    goto LAB33;

LAB35:    xsi_size_not_matching(t49, t59, 0);
    goto LAB36;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_8(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(215, ng0);
    t1 = (t0 + 3432U);
    t2 = *((char **)t1);
    t1 = (t0 + 16510);
    t4 = xsi_mem_cmp(t1, t2, 3U);
    if (t4 == 1)
        goto LAB3;

LAB7:    t5 = (t0 + 16513);
    t7 = xsi_mem_cmp(t5, t2, 3U);
    if (t7 == 1)
        goto LAB4;

LAB8:    t8 = (t0 + 16516);
    t10 = xsi_mem_cmp(t8, t2, 3U);
    if (t10 == 1)
        goto LAB5;

LAB9:
LAB6:    xsi_set_current_line(219, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t3 = (t0 + 10344);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t3);

LAB2:    t1 = (t0 + 9624);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(216, ng0);
    t11 = (t0 + 2792U);
    t12 = *((char **)t11);
    t11 = (t0 + 10344);
    t13 = (t11 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t12, 32U);
    xsi_driver_first_trans_fast(t11);
    goto LAB2;

LAB4:    xsi_set_current_line(217, ng0);
    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t1 = (t0 + 10344);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB5:    xsi_set_current_line(218, ng0);
    t1 = (t0 + 3112U);
    t2 = *((char **)t1);
    t1 = (t0 + 10344);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB10:;
}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_9(char *t0)
{
    char t17[16];
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t18;
    unsigned int t19;

LAB0:    xsi_set_current_line(227, ng0);
    t2 = (t0 + 1152U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 9640);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(228, ng0);
    t4 = (t0 + 1352U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)2);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(231, ng0);
    t2 = (t0 + 4072U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(250, ng0);
    t2 = (t0 + 3112U);
    t4 = *((char **)t2);
    t2 = (t0 + 16224U);
    t5 = (t0 + 2952U);
    t8 = *((char **)t5);
    t5 = (t0 + 16208U);
    t1 = ieee_std_logic_unsigned_greater_stdv_stdv(IEEE_P_3620187407, t4, t2, t8, t5);
    if (t1 != 0)
        goto LAB29;

LAB31:    xsi_set_current_line(253, ng0);
    t2 = (t0 + 2952U);
    t4 = *((char **)t2);
    t2 = (t0 + 10408);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t4, 32U);
    xsi_driver_first_trans_fast(t2);

LAB30:
LAB12:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1192U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(229, ng0);
    t4 = xsi_get_transient_memory(32U);
    memset(t4, 0, 32U);
    t11 = t4;
    memset(t11, (unsigned char)3, 32U);
    t12 = (t0 + 10408);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 32U);
    xsi_driver_first_trans_fast(t12);
    goto LAB9;

LAB11:    xsi_set_current_line(232, ng0);
    t2 = (t0 + 3112U);
    t5 = *((char **)t2);
    t2 = (t0 + 16224U);
    t6 = ieee_p_3620187407_sub_2546418145_3965413181(IEEE_P_3620187407, t5, t2, 1);
    if (t6 != 0)
        goto LAB14;

LAB16:    t2 = (t0 + 3112U);
    t4 = *((char **)t2);
    t2 = (t0 + 16224U);
    t1 = ieee_p_3620187407_sub_3905759485_3965413181(IEEE_P_3620187407, t4, t2, 0);
    if (t1 != 0)
        goto LAB22;

LAB23:    xsi_set_current_line(247, ng0);
    t2 = (t0 + 3112U);
    t4 = *((char **)t2);
    t2 = (t0 + 16224U);
    t5 = ieee_p_3620187407_sub_436351764_3965413181(IEEE_P_3620187407, t17, t4, t2, 1);
    t8 = (t17 + 12U);
    t18 = *((unsigned int *)t8);
    t19 = (1U * t18);
    t1 = (32U != t19);
    if (t1 == 1)
        goto LAB27;

LAB28:    t11 = (t0 + 10408);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t5, 32U);
    xsi_driver_first_trans_fast(t11);

LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(233, ng0);
    t8 = (t0 + 4392U);
    t11 = *((char **)t8);
    t7 = *((unsigned char *)t11);
    t9 = (t7 == (unsigned char)3);
    if (t9 != 0)
        goto LAB17;

LAB19:    xsi_set_current_line(236, ng0);
    t2 = (t0 + 10472);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);

LAB18:    xsi_set_current_line(238, ng0);
    t2 = (t0 + 3112U);
    t4 = *((char **)t2);
    t2 = (t0 + 16224U);
    t5 = ieee_p_3620187407_sub_436351764_3965413181(IEEE_P_3620187407, t17, t4, t2, 1);
    t8 = (t17 + 12U);
    t18 = *((unsigned int *)t8);
    t19 = (1U * t18);
    t1 = (32U != t19);
    if (t1 == 1)
        goto LAB20;

LAB21:    t11 = (t0 + 10408);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t5, 32U);
    xsi_driver_first_trans_fast(t11);
    goto LAB15;

LAB17:    xsi_set_current_line(234, ng0);
    t8 = (t0 + 10472);
    t12 = (t8 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t8);
    goto LAB18;

LAB20:    xsi_size_not_matching(32U, t19, 0);
    goto LAB21;

LAB22:    xsi_set_current_line(240, ng0);
    t5 = (t0 + 4552U);
    t8 = *((char **)t5);
    t3 = *((unsigned char *)t8);
    t6 = (t3 == (unsigned char)3);
    if (t6 != 0)
        goto LAB24;

LAB26:    xsi_set_current_line(244, ng0);
    t2 = xsi_get_transient_memory(32U);
    memset(t2, 0, 32U);
    t4 = t2;
    memset(t4, (unsigned char)2, 32U);
    t5 = (t0 + 10408);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast(t5);

LAB25:    goto LAB15;

LAB24:    xsi_set_current_line(241, ng0);
    t5 = (t0 + 10472);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(242, ng0);
    t2 = (t0 + 2952U);
    t4 = *((char **)t2);
    t2 = (t0 + 10408);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t4, 32U);
    xsi_driver_first_trans_fast(t2);
    goto LAB25;

LAB27:    xsi_size_not_matching(32U, t19, 0);
    goto LAB28;

LAB29:    xsi_set_current_line(251, ng0);
    t11 = (t0 + 2952U);
    t12 = *((char **)t11);
    t11 = (t0 + 10408);
    t13 = (t11 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t12, 32U);
    xsi_driver_first_trans_fast(t11);
    goto LAB30;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_10(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    xsi_set_current_line(264, ng0);
    t1 = (t0 + 3752U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t10 = xsi_get_transient_memory(32U);
    memset(t10, 0, 32U);
    t11 = t10;
    memset(t11, (unsigned char)2, 32U);
    t12 = (t0 + 10536);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t10, 32U);
    xsi_driver_first_trans_fast_port(t12);

LAB2:    t17 = (t0 + 9656);
    *((int *)t17) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 3592U);
    t5 = *((char **)t1);
    t1 = (t0 + 10536);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t5, 32U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB2;

LAB6:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_11(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(267, ng0);

LAB3:    t1 = (t0 + 3912U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 10600);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 9672);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_12(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(268, ng0);

LAB3:    t1 = (t0 + 3752U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 10664);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 9688);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void pit_timer_v1_00_a_a_3268654154_3306564128_p_13(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    xsi_set_current_line(269, ng0);

LAB3:    t1 = (t0 + 10728);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}


extern void pit_timer_v1_00_a_a_3268654154_3306564128_init()
{
	static char *pe[] = {(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_0,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_1,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_2,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_3,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_4,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_5,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_6,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_7,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_8,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_9,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_10,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_11,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_12,(void *)pit_timer_v1_00_a_a_3268654154_3306564128_p_13};
	xsi_register_didat("pit_timer_v1_00_a_a_3268654154_3306564128", "isim/user_logic_isim_beh.exe.sim/pit_timer_v1_00_a/a_3268654154_3306564128.didat");
	xsi_register_executes(pe);
}
