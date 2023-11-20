### Conexión DynamoDB

Pasos para crear una base de datos en DynamoDB en AWS

1. Crear una cuenta de AWS

Si aún no tienes una cuenta de AWS, puedes crear una de forma gratuita. Para ello, visita la página web de AWS y haz clic en el botón "Registrarse".

2. Habilitar AWS DynamoDB

[![a1.jpg](https://i.postimg.cc/nrYg7sMM/a1.jpg)](https://postimg.cc/hQv2RtLq)

3.	Crear tabla en DynamoDB con el parámetro de clave de partición siendo ID y clave de ordenamiento Timestamp.

[![a2.jpg](https://i.postimg.cc/d3Vrm194/a2.jpg)](https://postimg.cc/MMgnzzNQ)

4.  Crear función lambda en la cual el runtime que se tenga en dicha función sea Python 3.11

[![a3.jpg](https://i.postimg.cc/W3n0kr0d/a3.jpg)](https://postimg.cc/7G5Cv5s4)

5.	Editar la política de la función con el fin de permitir las acciones de escritura en la tabla creada previamente en DynamoDB. El código utilizado fue el siguiente:

[![a4.jpg](https://i.postimg.cc/ZqPdG37w/a4.jpg)](https://postimg.cc/WD3zrDPZ)

[![a5.jpg](https://i.postimg.cc/KYhTpQNK/a5.jpg)](https://postimg.cc/xXgqcvBY)

[![a6.jpg](https://i.postimg.cc/JzkJQSbV/a6.jpg)](https://postimg.cc/dhJLsHH4)

6.	Verificar que los permisos asignados a través de la política permitan la escritura en la tabla.

[![a7.jpg](https://i.postimg.cc/yY5cc73y/a7.jpg)](https://postimg.cc/nC4XtbkX)

7.	Crear un código de escritura en la tabla de DynamoDB a través de la función lambda. A continuación, se puede observar el código utilizado:

[![a8.jpg](https://i.postimg.cc/wM4JWpfH/a8.jpg)](https://postimg.cc/xNHcCWVF)

[![a9.jpg](https://i.postimg.cc/B6qK46R4/a9.jpg)](https://postimg.cc/Ty4wcRR4)

8.	Crear una prueba de simulación de una entrada de MQTT para la escritura en la tabla de DynamoDB, a través de la función. Se puede observar los valores utilizados para dicha prueba a continuación:

[![a10.jpg](https://i.postimg.cc/cHX8HWNY/a10.jpg)](https://postimg.cc/mz1rX0k2)

[![a11.jpg](https://i.postimg.cc/SRRYYPyP/a11.jpg)](https://postimg.cc/Mfkphdf0)

9.	Realizar la prueba de la función y verificar que se retorne la respuesta programada.

[![a12.jpg](https://i.postimg.cc/NFn96xFj/a12.jpg)](https://postimg.cc/XBwY3d9R)

10.	Verificar que el contenido de la prueba haya sido escrito en la tabla creada en DynamoDB.

[![a13.jpg](https://i.postimg.cc/2j9ZNCGN/a13.jpg)](https://postimg.cc/146tphbv)
   
