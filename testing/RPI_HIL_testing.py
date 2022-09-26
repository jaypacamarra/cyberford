import spidev
import RPi.GPIO as GPIO
import time


# GPIO setup
HIGH = True
LOW  = False
Arduino_reset_detect_pin = 17 # Broadcom pin 17
GPIO.setmode(GPIO.BCM) # Broadcom pin-numbering scheme
GPIO.setup(Arduino_reset_detect_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)


# SPI setup
spi_bus = 0
spi_device = 0

spi = spidev.SpiDev()

spi.open(spi_bus, spi_device)

spi.mode = 0b00
spi.max_speed_hz = 4000000


def exec_test_commands(cmdList, cmdInterval = 0.1):
    for pair in cmdList:
        spi.xfer2([pair[0]])
        spi.xfer2([pair[1]])
        time.sleep(cmdInterval) #in seconds
    print("Test complete")

# command list
commandLeftTurnSignal       = 0
commandRightTurnSignal      = 1
commandStopSignal           = 2
commandTurnLeft             = 3
commandTurnRight            = 4
commandMotorSetSpeed        = 5
commandMotorSetForwardDrive = 6
commandMotorSetReverseDrive = 7
commandStraightWheel        = 8

# Steering test
test_steering = [
    [commandStraightWheel, 0],
    [commandTurnLeft,5],
    [commandTurnLeft,10],
    [commandTurnLeft,15],
    [commandStraightWheel, 0],
    [commandTurnRight,5],
    [commandTurnRight,10],
    [commandTurnRight,15],
    [commandStraightWheel, 0]
]

# Throttle test
test_throttle = [
    [commandMotorSetForwardDrive,0],
    [commandMotorSetSpeed,0],
    [commandMotorSetSpeed,10],
    [commandMotorSetSpeed,20],
    [commandMotorSetSpeed,30],
    [commandMotorSetSpeed,40],
    [commandMotorSetSpeed,50],
    [commandMotorSetSpeed,60],
    [commandMotorSetSpeed,70],
    [commandMotorSetSpeed,80],
    [commandMotorSetSpeed,90],
    [commandMotorSetSpeed,100],
    [commandMotorSetSpeed,90],
    [commandMotorSetSpeed,80],
    [commandMotorSetSpeed,70],
    [commandMotorSetSpeed,60],
    [commandMotorSetSpeed,50],
    [commandMotorSetSpeed,40],
    [commandMotorSetSpeed,30],
    [commandMotorSetSpeed,20],
    [commandMotorSetSpeed,10],
    [commandMotorSetSpeed,0],
    [commandMotorSetReverseDrive,0],
    [commandMotorSetForwardDrive,0]
]

# Steering + Throttle test
test_throttleAndsteering = [
    [commandMotorSetForwardDrive,0],
    [commandMotorSetSpeed,50],
    [commandTurnLeft,15],
    [commandTurnLeft,45],
    [commandTurnRight,15],
    [commandTurnRight,45],
    [commandTurnRight,0],
    [commandMotorSetReverseDrive,0],
    [commandMotorSetSpeed,0],
    [commandMotorSetForwardDrive,0],
]

# turn signal test
test_turnSignals = [
    [commandLeftTurnSignal,0],
    [commandRightTurnSignal,0],
    [commandLeftTurnSignal,0],
    [commandRightTurnSignal,0],
    [commandStopSignal,0]
]

# Continuously send a dummy byte until the reset detect pin on Arduino is pulled HIGH
while GPIO.input(Arduino_reset_detect_pin) == LOW:
    spi.xfer2([0xFF]) 
    time.sleep(0.1)


try:        
    # Execute test commands
    # select test command list, and interval between each command
    
    print("Running test_steering...")
    exec_test_commands(test_steering, 2.0)
    
    print("Running test_throttle...")
    exec_test_commands(test_throttle, 2.0)
    
    print("Running test_throttleAndsteering...")
    exec_test_commands(test_throttleAndsteering, 3.0)

    print("Running test_turnSignals...")
    exec_test_commands(test_turnSignals, 5.0)

finally:
    spi.close()

