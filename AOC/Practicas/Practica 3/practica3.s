		AREA datos,DATA,READWRITE	; area de datos
M		EQU	7
N		EQU	5
long	EQU M*N 
matriz	DCB "nkongvfkobcfeqpbjufcxxfrewomnkgytvd"


    	AREA prog,CODE,READONLY		; area de codigo
    	ENTRY						; primera instruccion a ejecutar
		
		ldr r0,=matriz				; r0=@columna
		ldr r5,=matriz				; r5=@i
		add r1,r0,#28				; r1=@j
		ldrb r2,[r0,#28]			; r2=j
		mov r4,#1					; r4=1 contador

burbuja	cmp r4,#N					; r4=N
		beq columna
		
buc		cmp r5,r1					; @j>@i
		bmi inter
		add r1,r0,#28				; actualizo @j
		ldrb r2,[r0,#28]			; actualizo j
		add r4,r4,#1				; contador++
		add r5,r5,#M				; actualizo @i
		b burbuja
		
inter	ldrb r3,[r1,#-M]			; Hace el intercambio
		cmp r2,r3					; usando r3 como
		strbmi r3,[r1]				; variable auxiliar
		strbmi r2,[r1,#-M]
		
		sub r1,r1,#M				; @j=@j-1
		ldrb r2,[r1]				; actualizo j
		b buc						
				
columna	ldr r3,=matriz
		add r3,r3,#long-1				; r3=columna+1
		cmp r5,r3					; analizo si he ordenado
		beq fin						; todas las columnas
		add r0,r0,#1				; actualizo r0=@columna
		mov r5,r0					; actualizo r5=@i
		add r1,r0,#28				; r1=@j
		ldrb r2,[r0,#28]			; r2=j
		mov r4,#1					; r4=1 contador
       	b burbuja

fin 	b fin						; fin de programa

    	END							; fin de ensamblado