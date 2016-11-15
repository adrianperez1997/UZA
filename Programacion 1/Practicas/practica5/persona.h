/*
 *  Fichero de interfaz persona.h del módulo persona
 */

#ifndef PERSONA_H

#define PERSONA_H

/*
 * Definición del tipo de dato Persona
 */
struct Persona {
   int fecha;    /* fecha escrita en base 10 tiene la forma aaaammdd */
   bool mujer;   /* si mujer = true entonces es una mujer sino es un hombre */
};

/*
 * Pre: d>=1 y d<=31, m>=1 y m<=12, a>0
 * Post: Devuelve un dato de tipo Persona que corresponde a una persona 
 *       nacida el d/m/a y cuyo sexo viene definido por el valor de 
 *       [esMujer] (true -> es una mujer, false -> es un hombre)
 */
Persona definirPersona (int d, int m, int a, bool esMujer);
Persona definirPersona (int f, bool esMujer);

/*
 * Pre: ---
 * Post: Devuelve la fecha de nacimiento de [p] como un entero que, al ser escrito
 *       en base 10, tiene la forma aaaammdd, donde aaaa: año, mm: mes y dd: dia
 */
int nacido (Persona p);

/*
 * Pre: ---
 * Post: Devuelve true si la persona [p] es mujer y false si es hombre
 */
bool esMujer (Persona p);

#endif