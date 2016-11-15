    AREA datos, DATA, READWRITE
N	    EQU 5  
M	   	EQU 7
Matriz	DCB 'n','k','o','n','g','v','f','k','o','b','c','f','e','q','p','b','j','u','f','c','x','x','f','r','e','w','o','m','n','k','g','y','t','v','d'
    
	AREA prog, CODE, READONLY

    ENTRY
    eor r0, r0, r0 
	eor r1, r1, r1
   	eor r2, r2, r2
	eor r3, r3, r3
	mov r3, r3, #M-1
b1	ldr r4, =matriz
	add r4, r4, #28
	add r4, r4, r2
b2	ldrb r0, [r4]
	ldrb r1, [r4,#-M]
	cmp r0, r1
	bhi nif						; Cuándo el if no se cumple
	strb r0, [r4,#-M]
	strb r1, [r4]
nif add r3, #1
	sub r4, #M*r3
	cmp r3, #N    
	bne b2
	add r2, #1
	cmp r2, #M-1
	bne b1
	
	


fin	b fin

    END 