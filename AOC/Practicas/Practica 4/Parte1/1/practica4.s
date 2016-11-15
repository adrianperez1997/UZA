		AREA datos,DATA,READWRITE	; area de datos
n		EQU 4						; n=numero de elementos en la tabla
tabla	DCD 1,3,2,3					; tabla almacena los n elementos
stotal	DCD 0						; resultado

    	AREA prog,CODE,READONLY		; area de codigo
    	ENTRY						; primera instruccion a ejecutar
		
		sub sp,sp,#4				; reservo espacio para resultado		
       	ldr r0,=n
		PUSH{r0}					; apilo n
		ldr r0,=tabla
		PUSH{r0}					; apilo @tabla
		bl suma						; salto a subrutina suma
		add sp,sp,#8				; libero parametros
		POP{r0}						; desapilo el resultado
		ldr r1,=stotal
		str r0,[r1]					; guardo resultado en stotal

fin 	b fin						; fin de programa

suma	PUSH{lr}
		PUSH{r11}
		mov fp,sp
		PUSH{r0-r3}

		ldr r0,[fp,#8]				; r0=@tabla
		ldr r1,[fp,#12]				; r1=n
		mov r2,#0
		add r0,r0,r1,LSL #2			; r0=@[tabla+n]
		sub r0,r0,#4				; r0=@[tabla+n-1]
buc		cmp r1,#0					; r0=0
		beq fin_rut
		sub r1,r1,#1				; r1=r1-1=n-1
		ldr r3,[r0]					; r3=tabla[n]
		add r2,r2,r3				; r2=r2+r3=resultado+ultimo numero
		sub r0,r0,#4				; r0=r0-4
		b buc

fin_rut	str r2,[fp,#16]
		POP{r0-r3}
		POP{r11}
		POP{pc}

    	END							; fin de ensamblado