<p> Un escáner elemental </p>
<p> En este TP desarrollarán un escáner basado en tabla de transición. El lenguaje a reconocer tiene los siguientes tokens:
• Identificador: comienzan con una letra y sigue con letras y dígitos.
• Entero: solo dígitos decimales.
• Hexadecimal: Comienza con un cero seguido de una equis, y luego puede seguir dígitos hexadecimales.
<br>
<p> A tener en cuenta: </p>
• Las letras siempre pueden ser mayúsculas o minúsculas, tanto en identificadores como en hexadecimales.
• 0: es un entero válido.
• 0x ó 0X: son hexadecimales válidos.
<br>
<p> Notas de implementación: </p>
• Deberá tener un token que represente el fin de archivo.
• Si bien en un escáner real lo habitual es manejar los errores en lugar de devolverlos, en esta implementación devolveremos como tokens los siguientes tipos de errores:
◦ Error general: una cadena formada por caracteres que no pertenecen a nuestro alfabeto.
◦ Entero mal formado: una cadena que comienza con dígitos, y es seguida por dígitos o letras.
<br>
<p> Comentarios: </p>
• Lea el texto usando getchar, no utilice ninguna otra función para ingresar el texto.
• Recuerde que en ctype.h tiene funciones útiles para este TP.
• Use enum en lugar de números mágicos
• En main simplemente llame al escáner repetidamente hasta recibir el token de fin de texto. Paracada token recibido informe la categoría léxica y el lexema correspondiente.
