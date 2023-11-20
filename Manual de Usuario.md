# Sistema de monitoreo de centro de datos

Desarrollo e implementación de un sistema integral de monitoreo de centros de datos, utilizando sensores de huellas dactilares, temperatura y humedad para abordar problemas críticos en la operación de un centro de datos.

### Clonar repositorio:

    $ git clone https://github.com/SanchezCris/Data-Center-Monitoring-System.git

# ¿Cómo usar el prototipo?

Se recomienda utilizar Platformio IDE en Visual Studio Code ya que es mucho más fácil la instalación de librerías compatibles.

### Descargar Visual Studio Code:

    https://code.visualstudio.com/download

[![Visual-Studio-Code.png](https://i.postimg.cc/kGLLTj38/Visual-Studio-Code.png)](https://postimg.cc/H84Sx9Ls)

### Agregar a Visual Studio Code la extensión Platformio IDE:

Dirigirse a Platformio y esperar a que se instalen las dependencias de la IDE, luego reiniciar Visual Studio Code.

[![Platformio.png](https://i.postimg.cc/xTFmjXJ4/Platformio.png)](https://postimg.cc/jLP2ZdhH)

[![2.png](https://i.postimg.cc/N06jJvLQ/2.png)](https://postimg.cc/TyPx1Srs)

### Crear un nuevo proyecto en Platformio:

Dirigirse a Platformio, PIO Home, create new project. Colocar las especificaciones que se muestran en la siguiente imagen, escoger la ruta de preferencia donde se almacenará el proyecto.

[![Board.png](https://i.postimg.cc/gJNt3xYZ/Board.png)](https://postimg.cc/xJNP2TNf)

Importar al proyecto las siguientes librerías:

[![Captura.jpg](https://i.postimg.cc/RhqBrQWG/Captura.jpg)](https://postimg.cc/Lgd7LPBZ)

Luego crear copias del proyecto en el explorador de archivos, cambiar el nombre a las carpetas de la siguiente forma:

[![10.png](https://i.postimg.cc/R0NCxB2w/10.png)](https://postimg.cc/3yQQ2P8w)

Sustituir el código de los archivos main.cpp de cada carpeta según los archivos que se muestran en este repositorio.
Copiar la carpeta certificates a la carperta de trabajo del proyecto.
Copiar el archivo secrets.h a la primer carpeta creada, tal y como se muestra en este repositorio.
Añadir las cuatro carpetas al área de trabajo en Visual Studio Code. 

[![11.png](https://i.postimg.cc/GhQP2Wm4/11.png)](https://postimg.cc/bsZSVFbP)

### Borrar Huellas:

Dirigirse al archivo main.cpp dentro de la carpeta Clean Fingerprint, verificar que la terminal se encuentre en el entorno Default(Clean Fingerprint), compilar, cargar y seguir las instrucciones para borrar las huellas anteriormente registradas.

[![12.png](https://i.postimg.cc/NGNmv1JX/12.png)](https://postimg.cc/vDVcW6d8)

### Añadir Huellas:

Dirigirse al archivo main.cpp dentro de la carpeta Enroll Fingerprint, verificar que la terminal se encuentre en el entorno Default(Enroll Fingerprint), compilar, cargar y seguir las instrucciones para añadir las huellas anteriormente registradas.

[![13.png](https://i.postimg.cc/VvLYf0NZ/13.png)](https://postimg.cc/k6zrw4KW)

### Funcionamiento del sistema de monitoreo:

Dirigirse al archivo main.cpp dentro de la carpeta DataCenterMonitoring, verificar que la terminal se encuentre en el entorno Default(DataCenterMonitoring), compilar, cargar y seguir las instrucciones para verificar el funcionamiento del sistema de monitoreo.

[![14.png](https://i.postimg.cc/ZRwGL7Tj/14.png)](https://postimg.cc/Hc7vYt87)

En cuanto se ejecute la terminal de comandos y se establezca una correcta conexión a la red Wi-Fi se podrá observar las siguientes impresiones:

[![5.png](https://i.postimg.cc/SKhL6J8b/5.png)](https://postimg.cc/zyxR5D0x)

Según la imagen anterior, se puede observar que se realizó una conexión exitosa con los servicios de AWS IoT.
También se detectó el sensor lector de huellas, indicando que posee tres huellas registradas, de igual forma, se lee las características del sensor de temperatura y humedad.
Posteriormente comienza a imprimir de forma local los valores de Temperatura y Humedada, además de que aún no se han detectado huellas.

Para hacer accionar el servomotor que simula el acceso físico al centro de datos, se debe colocar el dedo de la mano registrado en el sensor lector de huellas.
¿Cómo se sabe si la huella está registrada?

Existe un diodo led de color verde que se encuentra intermitente, significa que se puede colar una huella para ser analizada.
Si el diodo led de color verde de queda encendido por uno o dos segundos, significa que la huella está registrada y se activa el servomotor.
Si la huella es rechazada, significa que no está registrada y se activa una alarmas emitida por un buzzer.

[![7.jpg](https://i.postimg.cc/rmYwW19p/7.jpg)](https://postimg.cc/8JMGgr98)

### Thingskeapk:

En la plataforma thingspeak se construyó un tablero en el cual muestra de forma gráfica en tiempo real los valores obtenidos, en dicho tablero se pueden observar gráficas en tiempo real de los valores de temperatura y humedad que existe en el ambiente, así como un indicador de marcación para los valores de humedad y temperatura.

[![1.png](https://i.postimg.cc/nrn73bjL/1.png)](https://postimg.cc/cg5rJzcq)

Adjunto se encuentra un registro de la cantidad de veces que las personas que registraron sus huellas han accedido al centro de datos, y la cantidad de veces que una persona no registrada ha intentado acceder.

[![2.png](https://i.postimg.cc/NffmTtvJ/2.png)](https://postimg.cc/5jTXdZ0L)

### AWS:

Dentro de los servicios proporcionados por AWS Cloud, se realizó una conexión MQTT en la cual se muestran los valores de Humedad y Temperatura en tiempo real.

[![3.png](https://i.postimg.cc/tgt421hh/3.png)](https://postimg.cc/kVGC5gY4)

DE igual forma, se realizó una base de datos para almacenar los registros de dichos valores (Humedad y Temperatura) en una tabla dynamo en tiempo real.

[![4.png](https://i.postimg.cc/KYyn1MGL/4.png)](https://postimg.cc/Mndc4XjK)
