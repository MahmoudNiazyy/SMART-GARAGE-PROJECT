#ifndef LEDMATRIX_INT_H
#define LEDMATRIX_INT_H

/*PORTA , COLUMNS*/
#define COL0     PIN3
#define COL1     PIN4
#define COL2     PIN5
#define COL3     PIN10
#define COL4     PIN4
#define COL5     PIN6
#define COL6     PIN6
#define COL7     PIN7


/*PORTB , ROWS*/
#define ROW0     PIN8
#define ROW1     PIN9
#define ROW2     PIN0
#define ROW3     PIN11
#define ROW4     PIN12
#define ROW5     PIN13
#define ROW6     PIN14
#define ROW7     PIN15



void LEDMTX_vidInit(void);

void LEDMTX_vidDisplay(u8 *Copy_u8Frame);

void LEDMTX_vidDisableCols(void);

void LEDMTX_vidSetRowValues(u8 Copy_u8Frame);





#endif /* LEDMATRIX_INT_H */
