;;=============================================================
;; CS 2110 - Fall 2022
;; Homework 5 - summation
;;=============================================================
;; Name: Antonio Mattson
;;=============================================================

;; Pseudocode (see PDF for explanation)
;;
;;    int result; (to save the summation of x)
;;    int x= -9; (given integer)
;;    int answer = 0;
;;    while (x > 0) {
;;        answer += x;
;;        x--;
;;    }
;;    result = answer;
.orig x3000
    ;; YOUR CODE HERE
    LD R1, x ;;Initialize the registers
    AND R3, R3, 0
    JSR CHECK

CHECK 
    ADD R1, R1, 0 ;;set condition codes
    BRn ENDLOOP ;;check if larger than 0
    ADD R3, R1, R3 ;;add current value to sum
    ADD R1, R1, -1 ;;decrement current value
    JSR CHECK ;;loop back to check

ENDLOOP ;;stores the results
    ST R3, result
    
    HALT
    x .fill 7
    result .blkw 1
.end

