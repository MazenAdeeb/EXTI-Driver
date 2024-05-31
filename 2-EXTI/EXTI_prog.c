/******************************************************************/
// Auther  : Mazen Adeeb                                          //
// Date    : 10/1/2022                                            //
// version : 0.0.1                                                //
// Driver  : EXTI_driver                                         //
/******************************************************************/
/*Library*/
#include "bit_math.h"
#include "std_types.h"

/*Mcal*/
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_Private.h"
#include "GI_interface.h"

/*Global Interrupt to function*/
static void (*EXTI_ApfEXTI[3])(void) = {NULL,NULL,NULL};

u8 EXTI_u8EXTIEnable(u8 copy_u8EXTIIndex, u8 copy_u8RdgeIndex)
{

    u8 Local_error_state = STD_Sucesses;
    switch (copy_u8EXTIIndex)
    {
    case EXTI_u8_INT0:
        switch (copy_u8RdgeIndex)
        {
        case EXTI_u8_RAISING_EDGE:
            SET_BIT(EXTI_U8_MCUSR, 1);
            SET_BIT(EXTI_U8_MCUSR, 0);
            /*Enable EXTI0*/
            SET_BIT(EXTI_U8_GICR, 6);
            break;
        case EXTI_u8_FALLING_EDGE:
            SET_BIT(EXTI_U8_MCUSR, 1);
            CLEAR_BIT(EXTI_U8_MCUSR, 0);
            /*Enable EXTI0*/
            SET_BIT(EXTI_U8_GICR, 6);
            break;
        case EXTI_u8_ANY_LOGICAL_CHANGE_EDGE:
            CLEAR_BIT(EXTI_U8_MCUSR, 1);
            SET_BIT(EXTI_U8_MCUSR, 0);
            /*Enable EXTI0*/
            SET_BIT(EXTI_U8_GICR, 6);
            break;
        case EXTI_u8_LOW_LEVEL:
            CLEAR_BIT(EXTI_U8_MCUSR, 1);
            CLEAR_BIT(EXTI_U8_MCUSR, 0);
            /*Enable EXTI0*/
            SET_BIT(EXTI_U8_GICR, 6);
            break;
        default:
            Local_error_state = STD_Error;
        }
        break;
    case EXTI_u8_INT1:
        switch (copy_u8RdgeIndex)
        {
        case EXTI_u8_RAISING_EDGE:
            SET_BIT(EXTI_U8_MCUSR, 2);
            SET_BIT(EXTI_U8_MCUSR, 3);
            /*Enable EXTI1*/
            SET_BIT(EXTI_U8_GICR, 7);
            break;
        case EXTI_u8_FALLING_EDGE:
            SET_BIT(EXTI_U8_MCUSR, 3);
            CLEAR_BIT(EXTI_U8_MCUSR, 2);
            /*Enable EXTI1*/
            SET_BIT(EXTI_U8_GICR, 7);
            break;
        case EXTI_u8_ANY_LOGICAL_CHANGE_EDGE:
            CLEAR_BIT(EXTI_U8_MCUSR, 3);
            SET_BIT(EXTI_U8_MCUSR, 2);
            /*Enable EXTI1*/
            SET_BIT(EXTI_U8_GICR, 7);
            break;
        case EXTI_u8_LOW_LEVEL:
            CLEAR_BIT(EXTI_U8_MCUSR, 2);
            CLEAR_BIT(EXTI_U8_MCUSR, 3);
            /*Enable EXTI1*/
            SET_BIT(EXTI_U8_GICR, 7);
            break;
        default:
            Local_error_state = STD_Error;
        }
        break;
    case EXTI_u8_INT2:
        switch (copy_u8RdgeIndex)
        {
        case EXTI_u8_RAISING_EDGE:
            SET_BIT(EXTI_U8_MCUCSR, 6);
            /*Enable EXTI2*/
            SET_BIT(EXTI_U8_GICR, 5);
            break;
        case EXTI_u8_FALLING_EDGE:
            CLEAR_BIT(EXTI_U8_MCUCSR, 6);
            /*Enable EXTI2*/
            SET_BIT(EXTI_U8_GICR, 5);
            break;
        default:
            Local_error_state = STD_Error;
        }
        break;

    default:
        Local_error_state = STD_Error;
    }
    return Local_error_state;
}

/* ISR for Interrupt 0*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (EXTI_ApfEXTI[EXTI_u8_INT0] != NULL)
    {
    EXTI_ApfEXTI[0]();
    }
    
}

/* ISR for Interrupt 1*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if (EXTI_ApfEXTI[EXTI_u8_INT1] != NULL)
    {EXTI_ApfEXTI[1]();}
}

/* ISR for Interrupt 2*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if (EXTI_ApfEXTI[EXTI_u8_INT2] != NULL)
    {EXTI_ApfEXTI[2]();}
}

u8 EXTI_u8EXTISetCallBack(void (*copy_pf)(void), u8 copy_u8EXTIindex)
{
    u8 Local_Error_state = STD_Sucesses;
    if ((copy_u8EXTIindex <= EXTI_u8_INT2) && (copy_pf != NULL))
    {
        EXTI_ApfEXTI[copy_u8EXTIindex] = copy_pf;
    }
    else
    {
        Local_Error_state = STD_Error;
    }
    return Local_Error_state;
}

// u8 EXTI_u8EXTIDisable(u8 copy_u8EXTIIndex)
// {

// }