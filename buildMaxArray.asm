;;=============================================================
;; CS 2110 - Fall 2022
;; Homework 5 - buildMaxArray
;;=============================================================
;; Name: 
;;=============================================================


;; Pseudocode (see PDF for explanation)
;;
;;	int A[] = {1,2,3};
;;	int B[] = {-1, 7, 8};
;;	int C[3];
;;
;;	int i = 0;
;;
;;	while (i < A.length) {
;;		if (A[i] < B[i])
;;			C[i] = B[i];
;;		else
;;			C[i] = A[i];
;;
;;		i += 1;
;;	}


.orig x3000
	;; YOUR CODE HERE
	LD R0, A ;;Initialize Registers
	LD R1, B
	LD R2, C
	AND R3, R3, 0
LOOP
	LD R4, LEN	
	NOT R5, R3 ;; Subtract length - i, if <= 0 end loop
	ADD R5, R5, 1
	ADD R5, R4, R5
	BRn ENDLOOP ;;End loop possibly
	LDR R6, R0, 0 ;;Get num from array
	LDR R7, R1, 0 
	NOT R6, R6  ;;Make A num negative
	ADD R6, R6, 1  
	ADD R4, R6, R7 ;; add number together to set condition codes
    BRnz ALARGER ;;branch if A or B is larger
	BRp BLARGER
ALARGER
	NOT R6, R6 ;;Reset A to positive
	ADD R6, R6, 1
    STR	R6,	R2, 0 ;;store A
	ADD R3, R3, 1 ;;Increment A, B, C, i
	ADD R0, R0, 1
	ADD R1, R1, 1
	ADD R2, R2, 1
	JSR LOOP
BLARGER
	STR R7, R2, 0 ;;store B
	ADD R3, R3, 1 ;;Increment A, B, C, i
	ADD R0, R0, 1
	ADD R1, R1, 1
	ADD R2, R2, 1
	JSR LOOP
ENDLOOP
	HALT


A 	.fill x3200
B 	.fill x3300
C 	.fill x3400
LEN .fill 4

.end

.orig x3200
	.fill -1
	.fill 2
	.fill 7
	.fill -3
.end

.orig x3300
	.fill 3
	.fill 6
	.fill 0
	.fill 5
.end

.orig x3400
	.blkw 4
.end


