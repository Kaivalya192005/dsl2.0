def hash_function(value, size):  
    return hash(value) % size  # Calculates the index for key-value pair

def insert(hashtable, size, key, value):
    index = hash_function(value, size)
    for i in range(len(hashtable[index])):
        if hashtable[index][i][0] == key:
            hashtable[index][i] = (key, value)
            print("Updated:", key, value)
            return
    hashtable[index].append((key, value))  # Insert as a tuple
    print("Inserted:", key, value)

def search(hashtable, size, key):
    for bucket in hashtable:
        for pair in bucket:
            if pair[0] == key:
                print("Found:", pair[0], "| Value:", pair[1])
                return
    print("Key not found.")

def delete(hashtable, size, key):
    for bucket in hashtable:
        for pair in bucket:
            if pair[0] == key:
                bucket.remove(pair)
                print("Deleted:", key)
                return
    print("Key not found.")

def display(hashtable):
    for i in range(len(hashtable)):
        if hashtable[i]:
            for pair in hashtable[i]:
                print(f"{pair[0]}: {pair[1]}")
        else:
            print("Empty")

def main():
    size = 10
    hashtable = [[] for _ in range(size)]

    while True:
        print("\nMenu:")
        print("1. Insert")
        print("2. Search")
        print("3. Delete")
        print("4. Display")
        print("5. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            key = input("Enter key: ")
            value = int(input("Enter value: "))
            insert(hashtable, size, key, value)

        elif choice == "2":
            key = input("Enter key to search: ")
            search(hashtable, size, key)

        elif choice == "3":
            key = input("Enter key to delete: ")
            delete(hashtable, size, key)

        elif choice == "4":
            display(hashtable)

        elif choice == "5":
            print("Exiting program.")
            break

        else:
            print("Invalid choice. Try again.")
if __name__ == "__main__":
    main()
