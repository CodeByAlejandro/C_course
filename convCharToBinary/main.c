#include <stdio.h>

// Function to print the binary representation of a character
void printBinary(char c) {
    // Iterate over each bit in the character (assuming 8-bit char)
    for (int i = 7; i >= 0; i--) {
        // Use bitwise AND to check if the ith bit is set
        if (c & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n"); // Newline for better readability
}

int main() {
    char c;

    // Ask the user to input a character
    printf("Enter a signed character as decimal: ");
    scanf("%hhi", &c);

    // Print the binary representation of the character
    printf("Binary value of decimal %hhi is: ", c);
    printBinary(c);
    
    printf("\n");
    
    char mask = 0xFF;
    char complement = c ^ mask;
    
    printf("Complement in binary is: ");
    printBinary(complement);
    printf("Complement in decimal is: %hhi\n", complement);
    
    printf("\n");
    
    complement++;
        
    printf("Inverse sign in binary is: %hhi\n", complement);
    printf("Inverse sign in decimal is: ");
    printBinary(complement);
    
    // Notes:
    //   - Can't invert 0 -> becomes -1
    //   - Can't invert -128 (max negative) -> becomes -128 (itself)

    return 0;
}