#include <Encoder.h>




class Motor
{
public:
    // Constructor
    Motor();
    Motor(int EN, int DIR, int ENCA, int ENCB); // Constructor with pin numbers (use this one. Init function not working properly)
    ~Motor();
    
    int reverse_ = 1;   // Set the motor to reverse direction for ALL commands

    int EN_ = 2;    // The enable pin
    int DIR_ = 3;   // The direction pin

    /// The pin numbers for the knee encoder
    int ENCA_ = 0;
    int ENCB_ = 1;

    /// The encoder object for each individual motor
    Encoder* encoder_;

    // Control Variables:
    float Kp_ = 0.0;                // Proportional gain
    float Ki_ = 0.0;                // Integral gain
    float Kd_ = 0.0;                // Derivative gain
    float prevShaftPos_= 0.0;       // The previous position of the motor
    float shaftVel_ = 0.0;          // The velocity of the motor
    float integralError_ = 0.0;     // Integral error for the PID controller

    float gearReduction_ = (360)/(12*380.0); // The gear reduction of the motor

    void setReverse();                               // Set the motor to reverse direction for ALL commands
    void setGearReduction(float gearReduction);       // Set the gear reduction of the motor
    void fwdDrive(int speed);                        // Drive the motor forward
    void revDrive(int speed);                        // Drive the motor in reverse
    void init(int INA, int INB, int ENCA, int ENCB); // Initialize the motor
    int motorPos();                                  // Get the position of the motor encoder (in ticks)
    void setGains(float Kp, float Ki, float Kd);      // Set the PID gains
    void posControl(float desPos);                    // Control the position of the motor
    float shaftPos();                                // Get the position of the motor in degrees

private:
};