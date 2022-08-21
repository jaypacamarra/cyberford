import spidev
import time

spi_bus = 0
spi_device = 0

spi = spidev.SpiDev()
spi.open(spi_bus, spi_device)
spi.max_speed_hz = 1000000

idx = 0


def spi_transfer_cyberFord_vehicleID():
    spi.xfer2([0x43]) #'C'
    spi.xfer2([0x79]) #'y'
    spi.xfer2([0x62]) #'b'
    spi.xfer2([0x65]) #'e'
    spi.xfer2([0x72]) #'r'
    spi.xfer2([0x46]) #'F'

def exec_test_commands(cmdList, cmdInterval = 0.1):
    for command in cmdList:
        spi_transfer_cyberFord_vehicleID()
        spi.xfer2([command])
        if idx % 2 != 0:
            time.sleep(cmdInterval) #in seconds
        idx += 1
        if len(cmdList) == idx+1:
            idx = 0


# command list
commandLeftTurnSignal       = 0x0
commandRightTurnSignal      = 0x1
commandStopSignal           = 0x2
commandTurnLeft             = 0x3
commandTurnRight            = 0x4
commandMotorSetSpeed        = 0x5
commandMotorSetForwardDrive = 0x6
commandMotorSetReverseDrive = 0x7

# Steering test
test_steering = [
    commandTurnLeft,
    0x15,
    commandTurnLeft,
    0x30,
    commandTurnLeft,
    0x45,
    commandTurnLeft,
    0x60,
    commandTurnLeft,
    0x0,
    commandTurnRight,
    0x15,
    commandTurnRight,
    0x30,
    commandTurnRight,
    0x45,
    commandTurnRight,
    0x60,
    commandTurnRight,
    0x0
]

# Throttle test
test_throttle = [
    commandMotorSetForwardDrive,
    0x0,
    commandMotorSetSpeed,
    0x10,
    commandMotorSetSpeed,
    0x20,
    commandMotorSetSpeed,
    0x30,
    commandMotorSetSpeed,
    0x40,
    commandMotorSetSpeed,
    0x50,
    commandMotorSetSpeed,
    0x60,
    commandMotorSetSpeed,
    0x70,
    commandMotorSetSpeed,
    0x80,
    commandMotorSetSpeed,
    0x90,
    commandMotorSetSpeed,
    0x100,
    commandMotorSetReverseDrive,
    0x0        
]

# Steering + Throttle test
test_throttleAndsteering = [
    commandMotorSetForwardDrive,
    0x0,
    commandMotorSetSpeed,
    0x50,
    commandTurnLeft,
    0x15,
    commandTurnLeft,
    0x45,
    commandTurnRight,
    0x15,
    commandTurnRight,
    0x45,
    commandTurnRight,
    0x0,
    commandMotorSetReverseDrive,
    0x0,
    commandMotorSetSpeed,
    0x0
]

# turn signal test
test_turnSignals = [
    commandLeftTurnSignal,
    0x0,
    commandRightTurnSignal,
    0x0,
    commandLeftTurnSignal,
    0x0,
    commandRightTurnSignal,
    0x0,
    commandStopSignal,
    0x0
]

# Execute test commands
# select test command list, and interval between each command
exec_test_commands(test_steering, 2.0)
exec_test_commands(test_throttle, 2.0)
exec_test_commands(test_throttleAndsteering, 2.0)
exec_test_commands(test_turnSignals, 4.0)


