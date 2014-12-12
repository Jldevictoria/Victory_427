################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
DMA_Milestone_One.elf.size \

ELFCHECK += \
DMA_Milestone_One.elf.elfcheck \


# All Target
all: DMA_Milestone_One.elf secondary-outputs

# Tool invocations
DMA_Milestone_One.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo Building target: $@
	@echo Invoking: MicroBlaze gcc linker
	mb-gcc -Wl,-T -Wl,../src/lscript.ld -L../../space_invaders_bsp/microblaze_0/lib -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mcpu=v8.20.b -mno-xl-soft-mul -o"DMA_Milestone_One.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo Finished building target: $@
	@echo ' '

DMA_Milestone_One.elf.size: DMA_Milestone_One.elf
	@echo Invoking: MicroBlaze Print Size
	mb-size DMA_Milestone_One.elf  |tee "DMA_Milestone_One.elf.size"
	@echo Finished building: $@
	@echo ' '

DMA_Milestone_One.elf.elfcheck: DMA_Milestone_One.elf
	@echo Invoking: Xilinx ELF Check
	elfcheck DMA_Milestone_One.elf -hw ../../Space_Invaders_Lab_4_hw_platform/system.xml -pe microblaze_0  |tee "DMA_Milestone_One.elf.elfcheck"
	@echo Finished building: $@
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) DMA_Milestone_One.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
