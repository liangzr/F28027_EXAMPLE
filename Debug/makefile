################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv5/tools/compiler/c2000_6.1.3

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./src/user_5110lib.obj" \
"./src/user_5110.obj" \
"./src/F2802x_usDelay.obj" \
"./src/F2802x_TempSensorConv.obj" \
"./src/F2802x_SysCtrl.obj" \
"./src/F2802x_Spi.obj" \
"./src/F2802x_Sci.obj" \
"./src/F2802x_PieVect.obj" \
"./src/F2802x_PieCtrl.obj" \
"./src/F2802x_OscComp.obj" \
"./src/F2802x_I2C.obj" \
"./src/F2802x_Gpio.obj" \
"./src/F2802x_GlobalVariableDefs.obj" \
"./src/F2802x_EPwm.obj" \
"./src/F2802x_ECap.obj" \
"./src/F2802x_DisInt.obj" \
"./src/F2802x_DefaultIsr.obj" \
"./src/F2802x_CpuTimers.obj" \
"./src/F2802x_Comp.obj" \
"./src/F2802x_CodeStartBranch.obj" \
"./src/F2802x_Adc.obj" \
"./src/DSP2802x_MemCopy.obj" \
"./main.obj" \
-l"libc.a" \
"../28027_RAM_lnk.cmd" \
"../F2802x_Headers_nonBIOS.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include src/subdir_vars.mk
-include subdir_rules.mk
-include src/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: F28027_5110.out

# Tool invocations
F28027_5110.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt -O2 -g --diag_warning=225 --display_error_number --diag_wrap=off -z --stack_size=0x300 -m"F28027_5110.map" --warn_sections -i"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/lib" -i"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --reread_libs --display_error_number --diag_wrap=off --rom_model -o "F28027_5110.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C2000_EXECUTABLE_OUTPUTS__QUOTED) "F28027_5110.out"
	-$(RM) "main.pp" "src\DSP2802x_MemCopy.pp" "src\F2802x_Adc.pp" "src\F2802x_Comp.pp" "src\F2802x_CpuTimers.pp" "src\F2802x_DefaultIsr.pp" "src\F2802x_ECap.pp" "src\F2802x_EPwm.pp" "src\F2802x_GlobalVariableDefs.pp" "src\F2802x_Gpio.pp" "src\F2802x_I2C.pp" "src\F2802x_OscComp.pp" "src\F2802x_PieCtrl.pp" "src\F2802x_PieVect.pp" "src\F2802x_Sci.pp" "src\F2802x_Spi.pp" "src\F2802x_SysCtrl.pp" "src\F2802x_TempSensorConv.pp" "src\user_5110.pp" "src\user_5110lib.pp" 
	-$(RM) "main.obj" "src\DSP2802x_MemCopy.obj" "src\F2802x_Adc.obj" "src\F2802x_CodeStartBranch.obj" "src\F2802x_Comp.obj" "src\F2802x_CpuTimers.obj" "src\F2802x_DefaultIsr.obj" "src\F2802x_DisInt.obj" "src\F2802x_ECap.obj" "src\F2802x_EPwm.obj" "src\F2802x_GlobalVariableDefs.obj" "src\F2802x_Gpio.obj" "src\F2802x_I2C.obj" "src\F2802x_OscComp.obj" "src\F2802x_PieCtrl.obj" "src\F2802x_PieVect.obj" "src\F2802x_Sci.obj" "src\F2802x_Spi.obj" "src\F2802x_SysCtrl.obj" "src\F2802x_TempSensorConv.obj" "src\F2802x_usDelay.obj" "src\user_5110.obj" "src\user_5110lib.obj" 
	-$(RM) "src\F2802x_CodeStartBranch.pp" "src\F2802x_DisInt.pp" "src\F2802x_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
