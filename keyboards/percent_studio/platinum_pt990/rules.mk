# # MCU name
# MCU = STM32F303

# # Bootloader selection
# BOOTLOADER = stm32-dfu

MCU = STM32F103
MCU_LDSCRIPT = STM32F103x8_0x08006000_bootloader
BOARD = STM32_F103_STM32DUINO
#dfu started address for download firmware: 0x08006000
DFU_ARGS = -d 1688:2220 -a 0 -s 0x08006000 
#voice65 PID
DFU_SUFFIX_ARGS = -v 1688 -p 2220 
# Bootloader selection
BOOTLOADER = stm32duino
# BOOTLOADER = custom

#Enter lower-power sleep mode when on the chibios idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys       //stamp_zhd
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover  stamp_zhd
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = no        # Rotary encoder





