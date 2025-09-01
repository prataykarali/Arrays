def create_file():
    filename = input("Enter filename to create: ")
    with open(filename, "w") as f:
        print("Start typing your text (Enter '~' on a new line to stop):")
        while True:
            line = input()
            if line == "~":
                break
            f.write(line + "\n")
    print(f"File saved successfully as {filename}")


def read_file():
    filename = input("Enter filename to open: ")
    try:
        with open(filename, "r") as f:
            print("\n--- File Content ---")
            print(f.read(), end="")
            print("\n--- End of File ---")
    except FileNotFoundError:
        print("Error: File not found!")


def append_file():
    filename = input("Enter filename to append: ")
    try:
        with open(filename, "a") as f:
            print("Start typing text to append (Enter '~' on a new line to stop):")
            while True:
                line = input()
                if line == "~":
                    break
                f.write(line + "\n")
        print(f"Text appended successfully to {filename}")
    except FileNotFoundError:
        print("Error: File not found!")


def main():
    while True:
        print("\n===== Simple Text Editor =====")
        print("1. Create & Write File")
        print("2. Open & Read File")
        print("3. Append to File")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            create_file()
        elif choice == "2":
            read_file()
        elif choice == "3":
            append_file()
        elif choice == "4":
            print("Exiting editor...")
            break
        else:
            print("Invalid choice! Try again.")


if __name__ == "__main__":
    main()