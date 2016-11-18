		AREA datos,DATA
;vuestras variables y constantes
reloj	DCD 	0 		;contador de centesimas de segundo
max		DCD 	8		;velocidad de movimiento (en centesimas s.)
cont	DCD		0		;instante siguiente movimiento
dirx	DCB		0		;direccion mov. caracter ‘H’ (-1 izda.,0 stop,1 der.)
diry 	DCB 	0 		;direccion mov. caracter ‘H’ (-1 arriba,0 stop,1 abajo)
fin 	DCB 	0 		;indicador fin de programa (si vale 1)

road	SPACE	16
roadi	DCB		15
primer	EQU		0x40007E00
ultim	EQU		0x40007FE0
spr		DCB		8
sprm	DCB		0
coche	DCD		0x40007FEC
mensa	DCB		"GAMEOVER "
texto	EQU		0x40007F28

VICIntEnable    EQU 0xFFFFF010  	;activar IRQs
VICIntEnClr   	EQU 0xFFFFF014  	;desactivar IRQs
VICSoftInt      EQU 0xFFFFF018  	;generar IRQs SW
VICSoftIntClear EQU 0xFFFFF01C  	;bajar IRQs SW
VICVectAddr0    EQU 0xFFFFF100  	;vector interrupciones
VICVectAddr     EQU 0xFFFFF030  	;registro para EOI
									
TEC_DAT	        EQU 0xE0010000  	;reg. dato teclado UART1
									
IOSET           EQU 0xE0028004  	;reg. datos GPIO(activar)
IOCLR           EQU 0xE002800C  	;reg. datos GPIP(desactivar)
TO_IR			EQU	0xE0004000		;reg. para bajar peticiones IRQ4
vac				DCB 0				
reloj_so		DCD 0				;var. para @RSI_timer_SO
tecl_so         DCD 0           	;var para @RSI_teclado_so


		AREA codigo,CODE
		EXPORT inicio			; forma de enlazar con el startup.s
		IMPORT srand			; para poder invocar SBR srand
		IMPORT rand				; para poder invocar SBR srand
inicio	; se recomienda poner punto de parada (breakpoint) en la primera
		; instruccion de código para poder ejecutar todo el Startup de golpe

	
		;programar @IRQ4 -> RSI_reloj
        LDR r0,=VICVectAddr0
        LDR r1,=reloj_so
        mov r2,#4
        ldr r3, [r0,r2,LSL #2]
        str r3, [r1]

        LDR r1,=RSI_reloj
        str r1, [r0,r2,LSL #2]

        ;programar @IRQ7 -> RSI_teclado
        LDR r0,=VICVectAddr0
        LDR r1,=tecl_so
        mov r2,#7
        ldr r3, [r0,r2,LSL #2]
        str r3, [r1]

        LDR r1,=RSI_teclado
        str r1, [r0,r2,LSL #2]
	    
		;activar IRQ4,IRQ7
        LDR r0,=VICIntEnable
        mov r1,#2_10010000
        str r1, [r0]

		;llama a srand
		mov r0, #3
        PUSH {r0}
        bl srand
        add sp, sp, #4

		;inicializar road

		ldr r0,=road
		mov r1,#0
		mov r2,#8
iniroad	cmp r1,#16
		strbne r2,[r0,r1]
		addne r1,r1,#1
		bne iniroad

 		;dibujar pantalla inicial

		ldr r0,=primer
		mov r2,#'#'
		ldr r1,=ultim
dcarre	cmp r1,r0					   ;dibujo la carretera
		bmi dcoche
		strb r2,[r0,#8]
		strb r2,[r0,#16]
		add r0,r0,#32
		b dcarre

dcoche	ldr r0,=coche
		ldr r0,[r0]
		mov r1,#'H'
		strb r1,[r0]

	 	;si toca mover coche
bucle	ldr r0,=dirx					;compruebo si hay que mover en eje x
		ldrsb r0,[r0]
		cmp r0,#0
		beq ejey
		ldr r1,=coche
		ldr r3,[r1]
		mov r2,#0
		strb r2,[r3]					;borro el coche
		add r3,r3,r0
		
		ldrb r7,[r3]
		cmp r7,#0						;compruebo si se ha chocado
		beq choc1
		ldr r0,=fin
		mov r1,#1
		strb r1,[r0]
		b sifin
		
choc1	mov r2,#'H'
		strb r2,[r3]					;dibujo coche nuevo
		
		str r3,[r1]						;actualizo @coche

		mov r1,#0
		ldr r0,=dirx
		strb r1,[r0]					;actualizo dirx=0

ejey	ldr r0,=diry					;compruebo si hay que mover en eje y
		ldrsb r0,[r0]
		cmp r0,#0
		beq carrt
		ldr r1,=coche
		ldr r3,[r1]
		
		mov r2,#32
		cmp r0,#1
		subeq r4,r3,r2
		addne r4,r3,r2
		ldr r5,=primer
		cmp r4,r5
		bmi carrt
		ldr r5,=ultim
		add r5,r5,r2
		cmp r4,r5
		bpl carrt

		mov r2,#0
		strb r2,[r3]					;borro el coche
		
		ldrb r7,[r3]
		cmp r7,#0						;compruebo si se ha chocado
		beq choc2
		ldr r0,=fin
		mov r1,#1
		strb r1,[r0]
		b sifin

choc2	mov r2,#'H'
		strb r2,[r4]					;dibujo coche nuevo
		
		str r4,[r1]						;actualizo @coche

		mov r1,#0
		ldr r0,=diry					;actualizo diry=0
		strb r1,[r0]
 		
		
		;si toca mover carretera
carrt	ldr r0,=cont
		ldr r1,[r0]
		cmp r1,#0				;comprobamos que el contador=0
		bne sifin

		ldr r1,=max
		ldr r1,[r1]
		str r1,[r0]				;reiniciamos el contador

		sub sp, sp, #4
        bl rand            		;conseguimos el numero aleatorio
        pop {r0}
		mov r0,r0,LSR #29		;le hacemos modulo 3

		cmp r0,#0				;si es 0 permanecera quieto
		bne uno
		mov r3,#0
		b mueve

uno		cmp r0,#1				;si es 1 se movera a la derecha
		bne dos
		mov r3,#1
		b mueve

dos		cmp r0,#2				;si es 2 se movera igual que el ultimo
		movne r3,#-1			;sino es que es 3 y se movera a la izquierda
		bne mueve
		ldr r3,=sprm			;guardamos en r3 el siguiente mov
		ldrsb r3,[r3]

mueve	ldr r0,=road			;r0=@road
		ldr r1,=roadi
		ldrb r1,[r1]			;r1=indice del ultimo elemento
		mov r5,r1				;guardo en r5 el indice del suprimido
		add r0,r0,r1
	 	mov r2,r0				;r2=@elemento a suprimir
		ldrb r0,[r0]
		ldr r4,=spr				;guardamos en spr la pos del elemento suprimido
		strb r0,[r4]

		cmp r1,#15
		ldreq r4,=road
		ldrbeq r4,[r4]			;guardamos en r4 la nueva posicion
		ldrbne r4,[r2,#1]
		add r4,r4,r3

		cmp r4,#0				;comprobamos los limites izq y der
		movmi r4,#0
		cmp r4,#23
		movpl r4,#23

		strb r4,[r2]			;guardamos el nuevo elemento

		ldr r0,=sprm
		strb r3,[r0]
		ldr r1,=roadi
		ldrb r0,[r1]			;actualizo las var sprm y roadi
		cmp r0,#0
		moveq r0,#15
		subne r0,r0,#1
		strb r0,[r1]
		;ya he calculado todas las posiciones de la nueva
		;carretera y ahora queda dibujarla

		ldr r0,=primer
		ldr r1,=ultim
		mov r2,#'#'
		mov r6,#0
		ldr r4,=road

dibuj	cmp r1,r0
		beq ultimo
		
		cmp r5,#15					  ;borro el limite izq
		movpl r5,#0
		addne r5,r5,#1
		ldrb r3,[r4,r5]
		strb r6,[r0,r3]
		add r3,r3,#8				  ;borro el limite derecho
		strb r6,[r0,r3]

		cmp r5,#0					  ;compruebo siempre si el indice ha
		moveq r5,#15				  ;llegado a 0 o a 15 para hacer que rote
		subne r5,r5,#1
			
		ldrb r3,[r4,r5]
		
		ldrb r7,[r0,r3]
		cmp r7,#0						;compruebo si se ha chocado
		beq choc5
		ldr r0,=fin
		mov r1,#1
		strb r1,[r0]
		b sifin
		
choc5	strb r2,[r0,r3]				  ;escribo el nuevo limite izq
		add r3,r3,#8
		
		ldrb r7,[r0,r3]
		cmp r7,#0						;compruebo si se ha chocado
		beq choc6
		ldr r0,=fin
		mov r1,#1
		strb r1,[r0]
		b sifin

choc6	strb r2,[r0,r3]				  ;escribo el nuevo limite der
		
		cmp r5,#15
		movpl r5,#0
		addne r5,r5,#1
		add r0,r0,#32
		b dibuj
		
		;Borro y escribo el ultimo elemento de la carretera
		
ultimo	ldr r1,=spr					  ;esta vez cojo el elemento de la var spr
		ldrb r1,[r1]
		strb r6,[r0,r1]
		
		add r1,r1,#8				  ;lo borro
		strb r6,[r0,r1]
					
		ldrb r3,[r4,r5]
		
		ldrb r7,[r0,r3]
		cmp r7,#0						;compruebo si se ha chocado
		beq choc3
		ldr r0,=fin
		mov r1,#1
		strb r1,[r0]
		b sifin
		
choc3	strb r2,[r0,r3]				  ;y lo escribo
		add r3,r3,#8

		ldrb r7,[r0,r3]
		cmp r7,#0						;compruebo si se ha chocado
		beq choc4
		ldr r0,=fin
		mov r1,#1
		strb r1,[r0]
		b sifin

choc4	strb r2,[r0,r3]

 		;si fin=0 salto a bucle
sifin	ldr r0,=fin
		ldrb r0,[r0]
		cmp r0,#0
		beq bucle


		ldr r0,=texto					;GAME OVER
		ldr r1,=mensa
		ldr r2,[r1]
		str r2,[r0]
		add r1,r1,#4
		add r0,r0,#8
		ldr r2,[r1]
		str r2,[r0]

 		;desactivar IRQ4,IRQ7
 		LDR r0, =VICIntEnClr
        mov r1, #2_10010000
        str r1, [r0]

        ;desactivar RSI_reloj
		
		LDR r0, =VICVectAddr0
        LDR r1,=reloj_so
        ldr r1, [r1]
        mov r2, #4
        str r1, [r0,r2,LSL #2]
		
        ;desactivar RSI_boton

        LDR r0, =VICVectAddr0
        LDR r1,=tecl_so
        ldr r1, [r1]
        mov r2, #7
        str r1, [r0,r2,LSL #2]
		
bfin 	b bfin




RSI_reloj 		;Rutina de servicio a la interrupcion IRQ4 (timer 0)
 				;Cada 0,01 s. llega una peticion de interrupcion
		 
         sub lr,lr,#4
         PUSH {lr}
         mrs r14,spsr
         PUSH {r14}
         msr cpsr_c,#2_01010010
		 
         PUSH{r0-r1}
		 
         LDR r0,=TO_IR
         mov r1,#1
         str r1,[r0]
		 
         LDR r0,=cont
         ldr r1, [r0]
		 cmp r1, #0
		 beq finreloj
         sub r1, r1, #1
         str r1, [r0]

finreloj POP{r0-r1}
		 msr cpsr_c, #2_11010010
         POP{r14}
         msr spsr_fsxc,r14
         LDR r14,=VICVectAddr
         str r14,[r14]
         POP{pc}^
				
RSI_teclado 	;Rutina de servicio a la interrupcion IRQ7 (teclado)
 				;al pulsar cada tecla llega peticion de interrupcion IRQ7
	
        sub lr,lr,#4		 
        PUSH {lr}
        mrs r14,spsr
        PUSH {r14}
        msr cpsr_c,#2_01010010
		
        PUSH{r0-r1}
		
        LDR r1,=TEC_DAT
        ldrb r0,[r1]
mas		cmp r0,#43
		bne menos
		ldr r1,=max
		ldr r0,[r1]
		cmp r0,#1
		beq fintec
		mov r0,r0,LSR #1
		str r0,[r1]
		b fintec
		
menos	cmp r0,#45
		bne mayus
		ldr r1,=max
		ldr r0,[r1]
		cmp r0,#128
		beq fintec
		mov r0,r0,LSL #1
		str r0,[r1]
		b fintec 
		 		
mayus	bic r0,r0,#2_100000					;transformo a mayusculas


j		cmp r0,#74
		bne l
		ldr r0,=dirx
		mov r1,#-1
		strb r1,[r0]
		b fintec

l		cmp r0,#76
		bne i
		ldr r0,=dirx
		mov r1,#1
		strb r1,[r0]
		b fintec

i		cmp r0,#73
		bne k
		ldr r0,=diry
		mov r1,#1
		strb r1,[r0]
		b fintec

k		cmp r0,#75
		bne q
		ldr r0,=diry
		mov r1,#-1
		strb r1,[r0]
		b fintec

q		cmp r0,#81
		bne fintec
		ldr r1,=fin
		mov r0,#1
		strb r0,[r1]
		b fintec		

fintec  POP{r0-r1}

        msr cpsr_c, #2_11010010
        POP{r14}
        msr spsr_fsxc,r14
        LDR r14,=VICVectAddr
        str r14,[r14]
        POP{pc}^
		
		END 
