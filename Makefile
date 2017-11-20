.PHONY: clean All

All:
	@echo "----------Building project:[ therestofyourlife - Debug ]----------"
	@"$(MAKE)" -f  "therestofyourlife.mk"
clean:
	@echo "----------Cleaning project:[ therestofyourlife - Debug ]----------"
	@"$(MAKE)" -f  "therestofyourlife.mk" clean
