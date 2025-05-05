class telebook:
    def __init__(self, name, tele):
        self.name = name
        self.tele = tele

def insert():
    hashtable = [None for i in range(10)]  # making a hashtable of size 10
    records = int(input("Enter the number of records: "))
    for i in range(records):  
        name = input("Enter name: ")
        tele = int(input("Enter telephone number: "))
        hashval = tele % 10

        # Insert with Quadratic Probing
        if hashtable[hashval] is None:
            hashtable[hashval] = telebook(name, tele)
        else:
            for j in range(1, 10):
                nhashval = (hashval + j**2) % 10
                if hashtable[nhashval] is None:
                    hashtable[nhashval] = telebook(name, tele)
                    break
    return hashtable

def display(h1):
    print("\n--- Phonebook Records ---")
    for idx, obj in enumerate(h1):
        if obj is not None:
            print(f"Index {idx}: Name = {obj.name}, Phone = {obj.tele}")
        else:
            print(f"Index {idx}: Empty")

def search(h1):
    to_search = input("Enter the name to be searched: ")
    for entry in h1:
        if entry is not None and entry.name == to_search:
            print("Name found:", entry.name, "| Phone:", entry.tele)
            return
    print("Name not found.")

def main():
    hash1 = []
    while True:
        print("\nPhonebook Menu:")
        print("1. Insert Records")
        print("2. Display Records")
        print("3. Search Records")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            hash1 = insert()
        elif choice == "2":
            if not hash1:
                print("Hash table is empty. Please insert records first.")
            else:
                display(hash1)
        elif choice == "3":
            if not hash1:
                print("Hash table is empty. Please insert records first.")
            else:
                search(hash1)
        elif choice == "4":
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please choose a valid option.")

# Ensure program runs when file is executed directly
if __name__ == "__main__":
    main()
