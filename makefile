.PHONY: test

test:
	@echo "Usage: make test <LETTER>"

test_%:
	@letter=$*; \
	src_file="$$letter.cpp"; \
	out_file="$$letter.out"; \
	test_dir="$$letter"test; \
	\
	if [ ! -f "$$src_file" ]; then \
		echo "Error: Source file '$$src_file' not found."; \
		exit 1; \
	fi; \
	\
	echo "Compiling $$src_file..."; \
	g++ --std=c++17 "$$src_file" -o "$$out_file"; \
	if [ $$? -ne 0 ]; then \
		echo "Compilation failed."; \
		exit 1; \
	fi; \
	\
	for i in $$(seq 1 7); do \
		test_file="$$test_dir/$$letter"test"$$i.txt"; \
		echo ""; \
		echo "===== Running $$out_file with $$test_file ====="; \
		if [ -s "$$test_file" ]; then \
			echo "Input:"; cat "$$test_file"; echo ""; \
			echo ""; \
			echo "Output:"; ./"$$out_file" < "$$test_file"; \
		else \
			echo "(Skipped: $$test_file is empty)"; \
		fi; \
	done


.PHONY: clean

clean:
	@echo "Cleaning up .out files..."
	@rm -f *.out