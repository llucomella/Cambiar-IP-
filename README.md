# Cambiar tu direccion IP con C++

Este codigo cambia la ip de la interfaz que digas, solo funciona en maquinas que tengan el idioma en español porque para buscar las interfaces hace un find a "interfaz", si lo quieres usar y tu maquina esta en ingues debes cambiar esta linea:

```bash
system("netsh interface ipv4 show config | find \"la interfaz\"");
```
Por esta:

```bash
system("netsh interface ipv4 show config | find \"the interface\"");
```
El resto del codigo es almacena en las variables correspondientes la ip, mascara y gateway.

Finalmente he usado este comando:

```bash
netsh interface ipv4 set address name="X" static X X X
```
Cambiando las X por las variables en las que se guarda las direcciones que hayas puesto.

He empleado una variable para asi mantener el main limpio y facil de entender.

> [!IMPORTANT]
> Este ejercicio es muy simple y con el tiempo lo quiero ir sofisticando a medida que vaya aprendiendo mas a programar.

## Cosas que quiero implementar:
- [X] Cambiar direccion IP
- [X] Cambiar DNS
- [ ] Revisar si las direcciones introducidas son con el formato correcto
- [ ] Ver si la IP esta en uso para evitar conflicto de IP
- [ ] Compatible con ingles y castellano (Idioma de Windows)
