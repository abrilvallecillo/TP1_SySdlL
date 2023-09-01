Un escáner elemental
En este TP desarrollarán un escáner basado en tabla de transición. El lenguaje a reconocer tiene los 
siguientes tokens:
• Identificador: comienzan con una letra y sigue con letras y dígitos.
• Entero: solo dígitos decimales.
• Hexadecimal: Comienza con un cero seguido de una equis, y luego puede seguir dígitos 
hexadecimales.
A tener en cuenta:
• Las letras siempre pueden ser mayúsculas o minúsculas, tanto en identificadores como en 
hexadecimales.
• 0: es un entero válido.
• 0x ó 0X: son hexadecimales válidos.
Notas de implementación:
• Deberá tener un token que represente el fin de archivo.
• Si bien en un escáner real lo habitual es manejar los errores en lugar de devolverlos, en esta 
implementación devolveremos como tokens los siguientes tipos de errores:
◦ Error general: una cadena formada por caracteres que no pertenecen a nuestro alfabeto.
◦ Entero mal formado: una cadena que comienza con dígitos, y es seguida por dígitos o 
letras.
