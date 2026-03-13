import os
import sys
import subprocess

NUM_TESTS = 7


def run_tests(letter):
    src_file = f"{letter}/{letter}.cpp"
    py_file = f"{letter}/{letter}.py"
    out_file = f"{letter}/{letter}.out"

    if os.path.exists(py_file) and os.path.getsize(py_file) > 0:
        print(f"Python file '{py_file}' found and is not empty.")

        for i in range(1, NUM_TESTS + 1):
            test_file = f"{letter}/{letter}test{i}.txt"

            print(f"\n\n===== Running {py_file} with {test_file} =====")

            if os.path.exists(test_file) and os.path.getsize(test_file) > 0:
                print("Input:")
                print(open(test_file).read())

                print("\nOutput:")
                with open(test_file) as f:
                    subprocess.run(["python3", py_file], stdin=f)
            else:
                print(f"(Skipped: {test_file} is empty)")

    else:
        if not os.path.exists(src_file):
            print(f"Error: Source file '{src_file}' not found.")
            sys.exit(1)

        print(f"Compiling {src_file}...")

        res = subprocess.run(
            ["g++", "--std=c++17", src_file, "-o", out_file]
        )

        if res.returncode != 0:
            print("Compilation failed.")
            sys.exit(1)

        for i in range(1, NUM_TESTS + 1):
            test_file = f"{letter}/{letter}test{i}.txt"

            print(f"\n\n===== Running {out_file} with {test_file} =====")

            if os.path.exists(test_file) and os.path.getsize(test_file) > 0:
                print("Input:")
                print(open(test_file).read())

                print("\nOutput:")
                with open(test_file) as f:
                    subprocess.run([f"./{out_file}"], stdin=f)
            else:
                print(f"(Skipped: {test_file} is empty)")


def clean():
    print("Cleaning up .out files...")
    for root, _, files in os.walk("."):
        for f in files:
            if f.endswith(".out"):
                os.remove(os.path.join(root, f))


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: make test <Question>")
        sys.exit(1)

    if sys.argv[1] == "clean":
        clean()
    else:
        run_tests(sys.argv[1])
