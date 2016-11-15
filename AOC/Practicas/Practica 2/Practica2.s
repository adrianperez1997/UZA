
		AREA datos,DATA,READWRITE	; area de datos	 
		
MAX		EQU 1024					; MAX es el ultimo numero a guardar
MAX_aux	EQU 512						; MAX_aux es el tamaño de la tabla auxiliar
tabla	SPACE 2048					; tabla es donde almacenaremos los numero
tab_aux	SPACE 512					; tab_aux es una tabla auxiliar para hacer la rotacion

    	AREA prog,CODE,READONLY		; area de codigo
    	ENTRY						; primera instruccion a ejecutar
								
    	ldr r0,=tabla				; r0=@tabla
		eor r1,r1,r1				; r1=0 (r10=componentes de la tabla)
		eor r2,r2,r2				; r2=0 (r2=direcciones de datos)

buc    	strh r1,[r0,r2]				; Mem(@tabla+r2)=r1
		add r2,r2,#2				; r2=r2+2
		add r1,r1,#1				; r1=r1+1
		cmp r1,#MAX					
		bne buc

		ldr r1,=tab_aux
		mov r3,#0
		b buc2

bloques	mov r1,r0
		add r0,r0,r3
		mov r3,#0
		add r2,r2,#1
		cmp	r2,#MAX
		beq fin

buc2	ldr r2,[r0,r3]
		strh r2,[r1,r3]
		add r3,r3,#2
		cmp r3,#MAX_aux
		bne buc2
		beq bloques



fin 	b fin						; fin de programa

    	END							; fin de ensamblado    