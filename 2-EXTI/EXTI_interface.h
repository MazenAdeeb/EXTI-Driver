/******************************************************************/
// Auther  : Mazen Adeeb                                          //
// Date    : 10/1/2022                                            //
// version : 0.0.1                                                //
// Driver  : EXTI_driver                                         //
/******************************************************************/
# ifndef EXTI_INTERFACE_H
# define EXTI_INTERFACE_H


# define EXTI_u8_INT0       0
# define EXTI_u8_INT1       1
# define EXTI_u8_INT2       2

/*MAcros for Edge source*/

# define EXTI_u8_RAISING_EDGE              0
# define EXTI_u8_FALLING_EDGE              1
# define EXTI_u8_ANY_LOGICAL_CHANGE_EDGE   2
# define EXTI_u8_LOW_LEVEL                 3

u8 EXTI_u8EXTIEnable(u8 copy_u8EXTIIndex, u8 copy_u8RdgeIndex);

u8 EXTI_u8EXTIDisable(u8 copy_u8EXTIIndex);

u8 EXTI_u8EXTISetCallBack(void (*copy_pf)(void), u8 copy_u8EXTIindex);


# endif