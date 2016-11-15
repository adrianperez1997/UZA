		AREA codigo, CODE
 		EXPORT ordena 
ordena	PUSH{lr}					; Apilo lr

		add r1,r0,r1,LSL #2			; r1=@[tabla+n]
		sub r1,r1,#4				; r1=@[tabla+n-1]
		PUSH{r0,r1}					; Apilo iz y de
		bl qksort					; SBR qksort
		add sp,sp,#8				; Libero los parametros
		POP{pc}						; Retorno a pc


qksort	PUSH{lr}
		PUSH{r11}
		mov fp,sp
		PUSH{r0-r6}
    	
		ldr r0,[fp,#8]				; r0=@i
		ldr r1,[fp,#12]				; r1=@j
		add r4,r0,r1				; r4=(iz+de)/2
		mov r4,r4,LSR #3
		mov r4,r4,LSL #2
		ldr r4,[r4]
		ldr r5,[fp,#8]				; r5=@iz
		ldr r6,[fp,#12]				; r6=@de



buc1	ldr r2,[r0]					; r2=i
		ldr r3,[r1]					; r3=j
		cmp r2,r4
		addmi r0,r0,#4				; i=i+1
		ldrmi r2,[r0]
		bmi buc1

buc2	cmp r4,r3
		submi r1,r1,#4				; j=j-1
		ldrmi r3,[r1]
		bmi buc2

if		cmp r1,r0					; j<i
		bmi buc3
		str r2,[r1]					; intercambio
		str r3,[r0]
		add r0,r0,#4				; i=i+1
		sub r1,r1,#4				; j=j-1
		
buc3	cmp r1,r0					; j>=i
		bpl buc1
									
invc1	cmp	r5,r1					; iz<j
		bpl invc2
		PUSH{r1}
		PUSH{r5}
		bl qksort					; recursividad 
		add sp,sp,#8	

invc2	cmp	r0,r6					; i<de
		bpl fin_rut
		PUSH{r6}
		PUSH{r0}
		bl qksort					; recursividad
		add sp,sp,#8	

fin_rut	POP{r0-r6}
		POP{r11}
		POP{pc}

		END							; fin de ensamblado