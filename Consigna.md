<h1> Un escáner elemental </h1>
<p> En este TP desarrollarán un escáner basado en tabla de transición. El lenguaje a reconocer tiene los siguientes tokens:</p>

<br>

<ul>
  <li> Identificador: comienzan con una letra y sigue con letras y dígitos. </li> 
  <li> Entero: solo dígitos decimales. </li> 
  <li> Hexadecimal: Comienza con un cero seguido de una equis, y luego puede seguir dígitos hexadecimales. </li> 
</ul>

<br>
<p> A tener en cuenta: </p>
<ul>
  <li> Las letras siempre pueden ser mayúsculas o minúsculas, tanto en identificadores como en hexadecimales. </li>
  <li>  0: es un entero válido. </li>
  <li> 0x ó 0X: son hexadecimales válidos. </li> 
</ul>

<br>
<p> Notas de implementación: </p>
<ul>
  <li> Deberá tener un token que represente el fin de archivo. </li>
  <li> Si bien en un escáner real lo habitual es manejar los errores en lugar de devolverlos, en esta implementación devolveremos como tokens los siguientes tipos de errores:</li>
  <li>  Error general: una cadena formada por caracteres que no pertenecen a nuestro alfabeto. </li>
  <li>  Entero mal formado: una cadena que comienza con dígitos, y es seguida por dígitos o letras. </li>
</ul>
<br>
<p> Comentarios: </p>
<ul>
  <li> Lea el texto usando getchar, no utilice ninguna otra función para ingresar el texto. </li>
  <li>  Recuerde que en ctype.h tiene funciones útiles para este TP. </li>
  <li>  Use enum en lugar de números mágicos. </li>
  <li>  En main simplemente llame al escáner repetidamente hasta recibir el token de fin de texto. Paracada token recibido informe la categoría léxica y el lexema correspondiente. </li>
</ul>
