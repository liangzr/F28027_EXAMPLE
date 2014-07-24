################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt -O2 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="H:/dsp/F28027_EXAMPLE/include" --include_path="H:/dsp/F28027_EXAMPLE" --include_path="H:/dsp/F28027_EXAMPLE/src" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


