# 🍃 so_long

**so_long** es un proyecto de [42 School](https://42.fr) que consiste en crear un pequeño **juego 2D** usando la MLX42.  
El objetivo es leer y validar un mapa, mostrarlo en pantalla y permitir que el jugador se mueva, recoja objetos y llegue a la salida. El proyecto pone énfasis en el manejo de archivos, estructuras y eventos gráficos.

## 🧠 Objetivos del Proyecto

- Trabajar con **MLX42** (ventanas, imágenes y eventos).
- Parsear y validar mapas en formato `.ber`.
- Implementar lógica de juego: movimiento, recogida de objetos, detección de salida.
- Gestionar errores y condiciones inválidas del mapa.
- Evitar fugas de memoria y cerrar correctamente recursos gráficos.
- Mejorar la organización del código y la modularidad en C.

## ✅ Funcionalidades Implementadas

- Lectura y validación completa de mapas `.ber`:
  - El mapa debe ser rectangular.
  - Debe estar cerrado por paredes (`1`).
  - Debe contener: 1 jugador (`P`), ≥1 coleccionable (`C`) y ≥1 salida (`E`).
  - Validación de ruta alcanzable mediante BFS/DFS.
- Renderizado del mapa con **MLX42** usando sprites personalizados.
- Movimiento del jugador mediante teclado (WASD o flechas).
- Recolección de coleccionables.
- Apertura de la salida al recoger todos los `C`.
- Conteo de movimientos mostrado en consola o ventana.
- Cierre limpio al llegar a la salida o pulsar una tecla de salida.

## 🗂️ Ejemplo de mapa (`.ber`)
```
111111
1P0C01
100001
1C0E11
111111
```
Leyenda:
- `1` → pared  
- `0` → suelo  
- `P` → jugador  
- `C` → coleccionable  
- `E` → salida  

## 🛠️ Compilación y ejecución

Compilar:
```
make
```

Ejecutar:
```
./so_long path/to/map.ber
```

Ejemplo:
```
./so_long maps/map1.ber
```

📌 El programa carga `map1.ber`, valida el mapa y abre la ventana del juego.

## ⌨️ Controles

- W / A / S / D → moverse  
- ESC → salir del juego

## ❌ Errores comunes detectados

- Mapa no rectangular.
- Bordes no cerrados por paredes.
- Carácter no permitido.
- Falta de `P`, `E` o `C`.
- Mapa sin ruta válida hacia todos los coleccionables y la salida.
- Fugas de memoria por malas liberaciones (importante comprobar con `valgrind`).

## 🧩 Estructura del repositorio
```
.
├─ sources/ # código fuente
├─ include/ # headers
├─ img/ # sprites .png
├─ libs/ # librerias
├─ maps/ # mapas de ejemplo
├─ Makefile
└─ README.md
```

## 🧪 Mapas de prueba recomendados

- `maps/valid1.ber` — mapa válido sencillo.
- `maps/no_exit.ber` — sin salida.
- `maps/no_collect.ber` — sin coleccionables.
- `maps/multi_player.ber` — más de un jugador.
- `maps/open_wall.ber` — mapa sin paredes cerradas.

## 📝 Notas de implementación

- Valida todo el mapa antes de cargar MLX42.
- Usa BFS/DFS para asegurarte de que todos los `C` y `E` son alcanzables.
- Dibuja cada tile con imágenes `.png`.
- Lleva un contador de movimientos y muéstralo.
- Libera todas las imágenes, punteros y la ventana antes de salir.

---
