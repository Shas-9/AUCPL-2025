.PHONY: test clean

test:
	@python3 run_tests.py $(filter-out $@,$(MAKECMDGOALS))

clean:
	@python3 run_tests.py clean

# Prevent make from treating the question name as a target
%:
	@:
