# Act-4.3---Actividad-Integral-de-Grafos

**Función readFile: 
Pseudocódigo de como funciona esta función (lol)**

función readFile(nombreArchivo):
  abrir archivo

  si el archivo no se puede abrir:
        mostrar mensaje "No se pudo abrir archivo"
        regresar lista vacía

  crear lista vacía listaPuertos

  para cada línea del archivo:

  buscar la última aparición de ":" en la línea
  si no existe:
      continuar con la siguiente línea

  buscar el primer espacio después de esos dos puntos
  si no existe:
      continuar con la siguiente línea

  extraer la subcadena entre ":" y ese espacio → strPuerto
  convertir strPuerto a entero → puerto

  buscar el último espacio de la línea
  si no existe:
      continuar con la siguiente línea

  extraer la subcadena después del último espacio → usuario

  found = falso

  // revisar si el puerto ya existe en la lista
  para i desde 0 hasta listaPuertos.size() - 1:
      si listaPuertos[i].puerto == puerto:
          listaPuertos[i].agregarUsuario(usuario)
          listaPuertos[i].aumentarFreq()
          found = verdadero
          romper el ciclo

  si found == falso:
      crear un nuevo objeto Puerto con ese número de puerto
      agregar el usuario al nuevo objeto
      insertar el nuevo objeto en listaPuertos

cerrar archivo
regresar listaPuertos
