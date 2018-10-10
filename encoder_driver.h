//Three wheels robot
//A wheel encode pin
#define ENC_A_PIN_A  2   
#define ENC_A_PIN_B  3   

//B wheel encode pin
#define ENC_B_PIN_A  21  
#define ENC_B_PIN_B  20  

//C wheel encode pin
#define ENC_C_PIN_A  19   
#define ENC_C_PIN_B  18     

long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();

void initEncoders();
