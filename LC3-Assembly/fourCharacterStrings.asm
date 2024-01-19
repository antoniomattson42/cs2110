;;=============================================================
;; CS 2110 - Fall 2022
;; Homework 5 - fourCharacterStrings
;;=============================================================
;; Name: Antonio Mattson
;;=============================================================


;; Pseudocode (see PDF for explanation)
;;
;; int count = 0;
;; int chars = 0;
;; int i = 0;
;;
;;  while(str[i] != '\0') {
;;      if (str[i] != ' ') 
;;          chars++;
;;      
;;      else {
;;          if (chars == 4) 
;;              count++;   
;;          chars = 0;
;;      }
;;      i++;
;;  }
;; ***IMPORTANT***
;; - Assume that all strings provided will end with a space (' ').
;; - Special characters do not have to be treated differently. For instance, strings like "it's" and "But," are considered 4 character strings.
;;

.orig x3000
	;; YOUR CODE HERE
	AND R0, R0, 0 ;;R0 count
	AND R1, R1, 0 ;;R1char
	AND R2, R2, 0 ;;R2 i
	LD R3, STRING ;;R3 STRING
	AND R4, R4, 0 ;;R4 space
	ADD R4, R4, 15
	ADD R4, R4, 15
	ADD R4, R4, 2
	LD R7, SPACE
LOOP
	LD R7, SPACE
	ADD R5, R3, R2 ;;STRING + offset
	LDR R6, R5, 0 ;;Current Char
	ADD R6, R6, 0
	BRz ENDLOOP
	ADD R6, R6, R7
	BRz SPACES
	ADD R1, R1, 1
	JSR Increment
SPACES
	ADD R5, R1, -4
	BRnp Reset
	ADD R0, R0, 1
Reset
	AND R1, R1, 0
Increment
	ADD R2, R2, 1
	JSR LOOP
ENDLOOP
	ST R0, ANSWER
	HALT


SPACE 	.fill #-32
STRING	.fill x4000
ANSWER .blkw 1

.end


.orig x4000

.stringz "I love CS 2110 and assembly is very fun! "

.end
