#ifndef CONTROLLER_H
#define CONTROLLER_H

void ControllerSetup(void);
void ControllerLoop(void);
byte ControllerGetRY(void);
byte ControllerGetLY(void);
bool ControllerGetCircle(void);
bool ControllerGetCircleReleased(void);
bool ControllerGetTriangle(void);
bool ControllerGetL1(void);
bool ControllerGetR2(void);
bool ControllerGetR2Released(void);
#endif /* CONTROLLER_H */

