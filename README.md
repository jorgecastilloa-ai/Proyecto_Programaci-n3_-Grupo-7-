# Proyecto_Programación3_-Grupo-7-

## **Integrantes:**

-Jorge Adrián Castillo Alache

-Isaac David Pasahe David

-Valeria Bazán Melendez

-Nicolas Alexandre Panduro Quispe

## **Resumen/descripción del proyecto:**

Este proyecto implementa una plataforma de streming, estando enfocada en la búsqueda eficiente de contenido mediante estructuras de datos.

El sistema permite gestionar obras, realizar búsquedas rápidas por título y sinopsis, entre otros atributos, priorizando la facilidad y la experiencia del usuario al usar la plataforma mediante algoritmos.

## **Objetivos del prosesamiento de datos:**

-Eliminar inconsistencias entre mayúsculas y minúsculas.

-Ignorar caracteres especiales o símbolos innecesarios.

-Facilitar búsquedas parciales o por prefijos.

-Estandarizar palabras provenientes de títulos, directores y actores.

Usamos conversión a minusculas, eliminación de caracteres especiales, y selección de palabras claves en listas para su inserción para Trie.

TRIE: Nuestro arbol de prefijos, es una estructura de datos diseñada para almacenar cadenas de texto de la forma más eficiente posble, un carácter es representada por un nodo y el recorrido (con un for) edesde la raíz hasta un nodo terminal forma una palabra completa.

## **Proceso del algoritmo de inserción:**

-Se comienza desde la raíz.

-Se recorre carácter por carácter.

-Si el nodo del carácter no existe, se crea.

-Se avanza al siguiente nodo.

-Al finalizar la palabra, se marca el nodo como final de palabra.

Lo que planteamos previamente como Pseudocódigo:

  <img width="272" height="118" alt="image" src="https://github.com/user-attachments/assets/ee194c6e-d8f6-4d48-bde8-3a4aa093d6b5" />


## **Algoritmo de busqueda:**

-Se inicia en la raíz.

-Se recorre cada carácter de la palabra o prefijo.

-Si algún carácter no existe, la búsqueda falla.

-Si se llega al final , Si isEndOfWord = true, la palabra si existe, si no, solo existe como prefijo.
  

  ## **Pseudocódigo:**

  <img width="180" height="106" alt="image" src="https://github.com/user-attachments/assets/a5d85c69-81d7-434b-b34f-7614cdb9e829" />


Como conclusión el pre-procesamiento garantiza que al los datos ingresados se vuelvan uniformes y con el trie se asegure a rapidez y precisión de las respuestas en el output
