# # Gestor-Contraseñas


## Proyecto Estructura de datos I


### Hernandez Moreno Enrique Alejandro

------------
El proyecto consiste en un gestor de contraseñas basico utilizando una lista doblemente ligada, donde cada nodo recibe 3 datos:

**-Usuario**

**-Dominio**

**-Contraseña**

El programa puede ejecutar las 4 operaciones basicas sobre cada dato:

**-Agregar**

**-Buscar**

**-Editar**

**-Eliminar**

Para la funcion  de busqueda se utiliza como parametro de busqueda el dominio y el resultado de la busqueda solo arroja el usuario buscado y el dominio

La unica manera de ver la contraseña utilizada en un nodo es mediante la opcion editar donde al ingresar al archivo pedira una contraseña de administrador, dicha contraseña es "Admin123" si no se utiliza dicha contraseña al inicio el programa se cierra en automatico, no esta habilitada una opcion de mas de 1 intento en caso de fallar la contraseña

Al cerrar el programa mediante la opcion "salir" toda la lista quedara guardada en un archivo txt encriptada mediante XOR

Asi mismo para cargar dicho txt de vuelta hay que entrar al sistema nuevamente y seleccionar la opcion 9, "cargar wallet" , sin embargo, para acceder a dichos datos se necesita la contraseña de administrador, de otro modo el programa se cerrara.

Finalmente cuenta con un metodo de ordenamiento burbuja en el que puede utilizar como parametro ya sea ordenar alfabeticamente por dominio o usuario
