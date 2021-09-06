# canal-de-suez
📖 Proyecto de Estructura de Datos y Algoritmos Fundamentales 

💾 El canal de Suez es un canal navegable que conecta el mar Mediterráneo con el mar Rojo a través de alrededor de 190 km, uniendo por un el lado del mar Mediterráneo desde el puerto Said hasta el golfo de Suez en el mar Rojo. Este canal es navegado entre 49 y 97 barcos diariamente. Se tiene un registro de los barcos que navegan por el canal con el siguiente formato:

<fecha> <hora> <punto-entrada> <UBI-Identificador único del buque>
  
Ejemplo:

3-jan-20 13:45 M 8PAK7

Donde el punto de entrada puede ser M – Mar Mediterráneo y R – Mar Rojo.

En equipos de tres personas, hacer una aplicación que:

    1. Solicite el nombre del archivo de entrada (Ej. canal.txt) y lo abra, almacenando los datos en un vector.
    2. Ordene la información por UBI + Fecha (primero por UBI, al haber empate ordenar por fecha).
    3. Solicite al usuario la serie a buscar (los primeros tres caracteres de el UBI).
    4. Despliegue todas las entradas al canal de los buques de esas series en forma ordenada UBI+Fecha.


