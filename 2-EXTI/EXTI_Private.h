/******************************************************************/
// Auther  : Mazen Adeeb                                          //
// Date    : 10/1/2022                                            //
// version : 0.0.1                                                //
// Driver  : EXTI_driver                                         //
/******************************************************************/

# ifndef EXTI_PRIVATE_H
# define EXTI_PRIVATE_H

# define EXTI_U8_GICR              *((u8 *)0x5B)
# define EXTI_U8_GIFR              *((u8 *)0x5A) 
# define EXTI_U8_MCUSR             *((u8 *)0x55)
# define EXTI_U8_MCUCSR            *((u8 *)0x54)


# endif