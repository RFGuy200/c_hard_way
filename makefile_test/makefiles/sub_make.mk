.PHONY:test_target
test_target:
	rm -rf $(TEXT_FILE)
	touch $(TEXT_FILE)
	@echo "EXTERNAL in sub-make = $(EXTERNAL)"