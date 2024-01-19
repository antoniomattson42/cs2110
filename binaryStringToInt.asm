;;=============================================================
;; CS 2110 - Fall 2022
;; Homework 5 - binaryStringToInt
;;=============================================================
;; Name: Antonio Mattson
;;=============================================================

;; Pseudocode (see PDF for explanation)
;;
;;    int result = x4000; (given memory address to save the converted value)
;;    String binaryString= "01000000"; (given binary string)
;;    int length = 8; (given length of the above binary string)
;;    int base = 1;
;;    int value = 0;
;;    while (length > 0) {
;;        int y = binaryString.charAt(length - 1) - 48;
;;        if (y == 1) {
;;            value += base;
;;        }     
;;            base += base;
;;            length--;
;;    }
;;    mem[result] = value;
.orig x3000
    ;; YOUR CODE HERE
    LD R1, length ;;R1 actual length
    AND R2, R2, 0 ;;R2 BASE
    ADD R2, R2, 1
    AND R3, R3, 0 ;;R3 result
    LD R4, binaryString ;;R4 binary string
LOOP
    ADD R1, R1, 0
    BRnz ENDLOOP
    ADD R5, R1, R4 ;;R5 location of next binary value
    LDR R6, R5, 0 ;;R6 next int
    ADD R6, R6, -12
    ADD R6, R6, -12
    ADD R6, R6, -12
    ADD R6, R6, -12
    BRnz ZERO
    ADD R3, R3, R2
ZERO
    ADD R2, R2, R2
    ADD R1, R1, -1
    JSR LOOP
ENDLOOP
    LD R7, result
    STR R3, R7, 0
    HALT

    binaryString .fill x5000
    length .fill 8
    result .fill x4000
.end 

.orig x5000
    .stringz "000000011"
.end
