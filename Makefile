.PHONY: clean All

All:
	@echo "----------Building project:[ dbmiddle - Debug ]----------"
	@cd "dbmiddle" && $(MAKE) -f  "dbmiddle.mk"
clean:
	@echo "----------Cleaning project:[ dbmiddle - Debug ]----------"
	@cd "dbmiddle" && $(MAKE) -f  "dbmiddle.mk" clean
