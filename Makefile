.PHONY: clean All

All:
	@echo "----------Building project:[ NN - Debug ]----------"
	@$(MAKE) -f  "NN.mk"
clean:
	@echo "----------Cleaning project:[ NN - Debug ]----------"
	@$(MAKE) -f  "NN.mk" clean
