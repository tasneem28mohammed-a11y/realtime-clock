################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/TIMER0/subdir.mk
-include HAL/PB/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/EXTI/subdir.mk
-include HAL/7Seg/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
DIO_6.lss \

FLASH_IMAGE += \
DIO_6.hex \

EEPROM_IMAGE += \
DIO_6.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: DIO_6.elf secondary-outputs

# Tool invocations
DIO_6.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DIO_6.map -mmcu=atmega16 -o "DIO_6.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DIO_6.lss: DIO_6.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DIO_6.elf  >"DIO_6.lss"
	@echo 'Finished building: $@'
	@echo ' '

DIO_6.hex: DIO_6.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DIO_6.elf  "DIO_6.hex"
	@echo 'Finished building: $@'
	@echo ' '

DIO_6.eep: DIO_6.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex DIO_6.elf  "DIO_6.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DIO_6.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 DIO_6.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DIO_6.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
