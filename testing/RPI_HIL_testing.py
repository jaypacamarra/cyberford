import spidev
import time

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
commandLeftTurnSignal       = 0x00
commandRightTurnSignal      = 0x01
commandStopSignal           = 0x02
commandTurnLeft             = 0x03
commandTurnRight            = 0x04
commandMotorSetSpeed        = 0x05
commandMotorSetForwardDrive = 0x06
commandMotorSetReverseDrive = 0x07

# Steering test
test_steering = [
    [commandTurnLeft,15],
    [commandTurnLeft,30],
    [commandTurnLeft,45],
    [commandTurnLeft,60],
    [commandTurnLeft,0],
    [commandTurnRight,15],
    [commandTurnRight,30],
    [commandTurnRight,45],
    [commandTurnRight,60],
    [commandTurnRight,0]
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


#spi.xfer2([0x0]) #need to send a dummy byte for some reason
#time.sleep(0.1)


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

