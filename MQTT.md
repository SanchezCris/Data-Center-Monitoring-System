### Conexión MQTT

Pasos para crear un cliente MQTT en AWS

1. Crear una cuenta de AWS

Si aún no tienes una cuenta de AWS, puedes crear una de forma gratuita. Para ello, visita la página web de AWS y haz clic en el botón "Registrarse".

2. Habilitar AWS IoT Core

Una vez que tengas una cuenta de AWS, debes habilitar AWS IoT Core. Para ello, ve a la consola de AWS y busca "AWS IoT Core". Haz clic en el botón "Habilitar".

[![a.jpg](https://i.postimg.cc/prsTCL6X/a.jpg)](https://postimg.cc/kRtqXqCk)

Crear una cosa.

[![b.jpg](https://i.postimg.cc/pV3X23MS/b.jpg)](https://postimg.cc/K4ryfqz7)

[![c.jpg](https://i.postimg.cc/0jnfC7vM/c.jpg)](https://postimg.cc/4HKVf7ms)

[![d.jpg](https://i.postimg.cc/6prdVdh9/d.jpg)](https://postimg.cc/0zNMPK33)

3. Crear un certificado de cliente

Un certificado de cliente es un archivo que contiene la información de identificación de tu dispositivo. Para crear un certificado de cliente, ve a la consola de AWS y busca "AWS IoT Core". Haz clic en el botón "Certificados". Haz clic en el botón "Crear certificado". Selecciona el tipo de certificado "Cliente". Haz clic en el botón "Siguiente". Introduce un nombre para el certificado. Haz clic en el botón "Crear".

Crear una política.

[![e.jpg](https://i.postimg.cc/N0hQtXhr/e.jpg)](https://postimg.cc/K156rR8Z)

[![f.jpg](https://i.postimg.cc/GmXSJwK3/f.jpg)](https://postimg.cc/75TVwRjj)

Editar el archivo JSON para dar acceso sin restricciones.

[![g.jpg](https://i.postimg.cc/yd1xqR9y/g.jpg)](https://postimg.cc/f3PDmJ8V)

Activar la política creada.

[![h.jpg](https://i.postimg.cc/VsSrzjpK/h.jpg)](https://postimg.cc/7bkYVTxz)

4. Descargar el certificado de cliente

Una vez que se haya creado el certificado de cliente, haz clic en el botón "Descargar". Guarda el archivo del certificado en tu dispositivo.

[![i.jpg](https://i.postimg.cc/SR7pm1hX/i.jpg)](https://postimg.cc/D4ZNggmF)

5. Instalar un cliente MQTT y configurar el cliente MQTT

  Código main de la carpeta MonitoringDataCenter/src

  [![j.jpg](https://i.postimg.cc/59GzzP8c/j.jpg)](https://postimg.cc/Z080txfj)

6. Conectar el cliente MQTT a AWS IoT Core

Una vez que hayas configurado el cliente MQTT, puedes conectarlo a AWS IoT Core. Para ello, utiliza el certificado de cliente y la clave privada que descargaste en el paso 4.

[![k.jpg](https://i.postimg.cc/nVskN9kJ/k.jpg)](https://postimg.cc/z3rKgB6t)

7. Publicar y suscribirse a mensajes

Una vez que el cliente MQTT esté conectado a AWS IoT Core, puedes publicar y suscribirte a mensajes.

[![3.png](https://i.postimg.cc/tgt421hh/3.png)](https://postimg.cc/kVGC5gY4)


De mejor manera, acá un video en donde explican de forma acompañada el procedimiento:

https://youtu.be/x9GfxgkEpXg?si=qkPVO5daJy0mCpWK
