from sys import exit

# dictionary (associative array)
# indices are words (can be int, strings, ...)
people = {
    "EMMA": "617-555-0100",
    "RODRIGO": "617-555-0101",
    "BRIAN": "617-555-0102",
    "DAVID": "617-555-0103"
}

if "EMMA" in people:
    print(f"Found {people['EMMA']}")
    exit(0)
print("Not found")
exit(1)