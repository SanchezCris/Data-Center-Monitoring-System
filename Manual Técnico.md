# Sistema de monitoreo de centro de datos

## Descripción

El proyecto de Internet de las Cosas que se presenta a continuación se enfoca en el 
desarrollo y la implementación de un sistema de monitoreo integral para centros de 
datos. Este sistema utiliza tecnologías avanzadas como lectores de huellas dactilares, 
sensores de temperatura y sensores de humedad para abordar problemas críticos en la 
operación de centros de datos. Estos dispositivos tendrán un desarrollo en un 
microcontrolador el cual se conectará via Wi-fi a nuestra nube publica a escoger que 
seria thingSpeack. El objetivo principal es garantizar la seguridad y la disponibilidad de 
los equipos en estos entornos esenciales para las operaciones empresariales.

## Problemática

Los centros de datos almacenan y gestionan una gran cantidad de información sensible 
y crítica para las operaciones empresariales. La falta de un sistema de seguridad efectivo 
puede llevar a accesos no autorizados, lo que pone en riesgo la confidencialidad e 
integridad de los datos. Sin medidas adecuadas de control de acceso, es posible que 
personas no autorizadas obtengan acceso a áreas restringidas del centro de datos, lo 
que podría resultar en pérdida de datos, filtración de información confidencial y 
violaciones de cumplimiento normativo.
Los equipos y servidores dentro de un centro de datos son esenciales para el 
funcionamiento de las operaciones empresariales. La exposición a condiciones 
ambientales adversas, como temperaturas extremadamente altas o bajas, puede dañar 
irreversiblemente los componentes electrónicos. El sobrecalentamiento puede causar 
fallos en los sistemas y resultar en tiempos de inactividad costosos. Por otro lado, una 
humedad inadecuada puede provocar la corrosión de los circuitos y conectores, lo que 
también puede generar fallas en el funcionamiento de los equipos

## Objetivos

### Objetivo General

Diseñar e implementar un sistema de monitoreo basado en IoT 
para centros de datos, que integre un lector de huellas, un sensor 
de temperatura y un sensor de humedad, con el propósito de 
mejorar la seguridad y prevenir daños a equipos

### Objetivos Específicos

• Desarrollar y desplegar un sistema de lector de huellas dactilares 
que permita el acceso autorizado al centro de datos, garantizando 
la seguridad de las áreas críticas y reduciendo el riesgo de accesos 
no autorizados.
• Instalar y configurar sensores de temperatura y humedad en áreas 
clave del centro de datos, con el fin de recopilar datos en tiempo 
real y detectar fluctuaciones que puedan indicar problemas 
potenciales en el entorno operativo.
• Implementar un sistema de alertas automatizadas que notifiquen 
al personal en tiempo real cuando se detecten condiciones fuera 
de los límites establecidos, como temperaturas extremas o niveles 
de humedad inadecuados. Además, generar reportes periódicos 
para el análisis de tendencias y la toma de decisiones informadas.

## Arquitectura de la solución

[![Arquitectura.jpg](https://i.postimg.cc/G34fvJM0/Arquitectura.jpg)](https://postimg.cc/z31prWZp)

## Diagrama del circuito eléctrónico

[![diagrama-circuito-final.jpg](https://i.postimg.cc/zBgnGBkQ/diagrama-circuito-final.jpg)](https://postimg.cc/tZ91r9wd)

## Diagrama de flujo del sistema "CleanFingerprint"

[![Clean.png](https://i.postimg.cc/R03PwvR7/Clean.png)](https://postimg.cc/XZbcbStq)

## Diagrama de flujo del sistema "EnrollFingerprint"

[![Enroll.png](https://i.postimg.cc/W3gXfSxt/Enroll.png)](https://postimg.cc/gXcVxyzP)

## Diagrama de flujo del sistema "MonitoringDataCenter"

[![Monitoring.png](https://i.postimg.cc/LsrxTGCr/Monitoring.png)](https://postimg.cc/d7jRQNKB)

## Resultados

[![1.png](https://i.postimg.cc/nrn73bjL/1.png)](https://postimg.cc/cg5rJzcq)

[![2.png](https://i.postimg.cc/NffmTtvJ/2.png)](https://postimg.cc/5jTXdZ0L)

[![3.png](https://i.postimg.cc/tgt421hh/3.png)](https://postimg.cc/kVGC5gY4)

[![4.png](https://i.postimg.cc/KYyn1MGL/4.png)](https://postimg.cc/Mndc4XjK)

## Recomendaciones

• Mejorar el sistema físico de acceso, en especial el ensamble entre el servomotor y la puerta, para que cuando se acceda se abra y cierre automáticamente.
• Mejorar la declaración de las políticas en AWS, para contribuir con las buenas prácticas.
• Implementar la activación del resto de pines del NodeMCU ESP8266 para agregar más activadores y poder así mejoara la experiencia del usuario.
