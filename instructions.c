
#include "dc_motor.h"
#include "instructions.h"

void executeInstruction(DC_motor *mL, DC_motor *mR, int colourCode) {
    switch (colourCode) {
        case 0:
            Red(DC_motor *mL, DC_motor *mR);
            break;
        case 1:
            Green(DC_motor *mL, DC_motor *mR);
            break;
        case 2:
            Blue(DC_motor *mL, DC_motor *mR);
            break;
        case 3:
            Yellow(DC_motor *mL, DC_motor *mR);
            break;
        case 4:
            Pink(DC_motor *mL, DC_motor *mR);
            break;
        case 5:
            Orange(DC_motor *mL, DC_motor *mR);
            break;
        case 6:
            LightBlue(DC_motor *mL, DC_motor *mR);
            break;
        case 7:
            White(DC_motor *mL, DC_motor *mR);
            break;
        case 8:
            Black(DC_motor *mL, DC_motor *mR);
            break;
        case 9:
            reverseYellow(DC_motor *mL, DC_motor *mR);
            break;
        case 10:
            reversePink(DC_motor *mL, DC_motor * mR);
            break;
        case 11: 
            reverseOrange(DC_motor *mL, DC_motor * mR);
            break;
        case 12:
            reverseLightBlue(DC_motor *mL, DC_motor * mR);
            break;
    }
}

void Red(DC_motor *mL, DC_motor *mR){
    turnRight(mL, mR);
}

void Green(DC_motor *mL, DC_motor *mR) {
    turnLeft(mL, mR);
}

void Blue(DC_motor *mL, DC_motor *mR) {
    turn180(mL, mR);
}

void Yellow(DC_motor *mL, DC_motor *mR) {
    trundleSquare(mL, mR, square, 1);
    turnRight(mL, mR);
}

void Pink(DC_motor *mL, DC_motor *mR) {
    trundleSquare(mL, mR, square, 1);
    turnLeft(mL, mR);

}

void Orange(DC_motor *mL, DC_motor *mR) {
    turnRight135(mL, mR);
}

void LightBlue(DC_motor *mL, DC_motor *mR) {
    turnLeft135(mL, mR);
}

void White(DC_motor *mL, DC_motor *mR) {
    reverseRoute(mL, mR);
}

void Black(DC_motor *mL, DC_motor *mR) {
    
}

// =======================

void reverseYellow(DC_motor *mL, DC_motor *mR) {
    turnLeft(mL, mR);
    trundleSquare(mL, mR, square, 0);
    turn180(mL, mR);
}

void reversePink(DC_motor *mL, DC_motor *mR) {
    turnRight(mL, mR);
    trundleSquare(mL, mR, square, 0);
    turn180(mL, mR);

}

void reverseOrange(DC_motor *mL, DC_motor *mR) {
    turnRight135(mL, mR);
}

void reverseLightBlue(DC_motor *mL, DC_motor *mR) {
    turnLeft135(mL, mR);
}

void reverseRoute(DC_motor *mL, DC_motor *mR) {
    // face the way you came
    int last_increments = increment;
    turn180(mL, mR);
    timed_trundle(mL, mR, last_increments);
    
    // [0, 1, 2, 3, 4, 5, 6, 7, 8]
    char reverseMapping[9] = [1, 0, 2, 9, 10, 11, 12, -1, -1]
    for (i = instruction_array_index; i >= 0; i--) {
        executeInstruction(mL, mR, reverseMapping[instruction_array[i][0]]);
        timed_trundle(mL, mR, instruction_array[i][1]);
    }
    Sleep();
}