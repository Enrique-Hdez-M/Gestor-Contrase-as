# Gestor-Contrase-as
Proyecto Estructura de datos I
Hernandez Moreno Enrique Alejandro
El proyecto consiste en un gestor de contraseñas basico utilizando una lista doblemente ligada
donde cada nodo recibe 3 datos:
-Usuario
-Dominio
-Contraseña
sobre cada nodo se pueden hacer las 4 operaciones basicas (insertar,buscar,editar y eliminar)
para la funcion buscar se utiliza como parametro de busqueda el dominio y el resultado de la busqueda solo arroja el usuario buscado y el dominio
la unica manera de ver la contraseña utilizada en un nodo es mediante la opcion editar
al ingresar al archivo pedira una contraseña de administrador, dicha contraseña es "Admin123" si no se utiliza dicha contraseña al inicio el programa se cierra en automatico, no da intentos
al cerrar el programa mediante la opcion "salir" toda la lista quedara guardada en un archivo txt encriptada mediante XOR
asi mismo para cargar dicho txt de vuelta hay que entrar al sistema nuevamente y seleccionar la opcion 9 sin embargo, para acceder a dichos datos se necesita la contraseña de administrador, de otro modo el programa se cerrara
finalmente cuenta con un metodo de ordenamiento burbuja en el que puede utilizar como parametro ya sea ordenar alfabeticamente por dominio o usuario
