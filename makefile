.PHONY: test

test:
	@echo "Usage: make test <Question>"

test_%:
	@letter=$*; \
	src_file="$$letter/$$letter.cpp"; \
	py_file="$$letter/$$letter.py"; \
	out_file="$$letter/$$letter.out"; \
	\
	if [ -f "$$py_file" ] && [ -s "$$py_file" ]; then \
		echo "Python file '$$py_file' found and is not empty."; \
		for i in $$(seq 1 7); do \
			test_file="$$letter/$$letter"test"$$i.txt"; \
			echo ""; \
			echo "===== Running $$py_file with $$test_file ====="; \
			if [ -s "$$test_file" ]; then \
				echo "Input:"; cat "$$test_file"; echo ""; \
				echo ""; \
				echo "Output:"; python3 "$$py_file" < "$$test_file"; \
			else \
				echo "(Skipped: $$test_file is empty)"; \
			fi; \
		done; \
	else \
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
			test_file="$$letter/$$letter"test"$$i.txt"; \
			echo ""; \
			echo "===== Running $$out_file with $$test_file ====="; \
			if [ -s "$$test_file" ]; then \
				echo "Input:"; cat "$$test_file"; echo ""; \
				echo ""; \
				echo "Output:"; ./"$$out_file" < "$$test_file"; \
			else \
				echo "(Skipped: $$test_file is empty)"; \
			fi; \
		done; \
	fi

generate:
	@echo Usage: make generate <Question>

generate_%:
	@Question=$*; \
	mkdir -p "$$Question"; \
	touch "$$Question/$$Question.cpp"; \
	cp "template.cpp" "$$Question/$$Question.cpp"; \
	for i in $$(seq 1 7); do \
		touch "$$Question/$$Question"test"$$i.txt"; \
	done


.PHONY: clean

clean:
	@echo "Cleaning up .out files..."
	@rm -f *.out