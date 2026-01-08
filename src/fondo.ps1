# Descargar la imagen
$url = "https://raw.githubusercontent.com/M1ch43l-B/rubber-ducky-casero/main/src/jesucristo.jpeg"
$path = "$env:TEMP\bg.jpg"
(New-Object System.Net.WebClient).DownloadFile($url, $path)

# Cambiar el registro
Set-ItemProperty -Path 'HKCU:\Control Panel\Desktop' -Name Wallpaper -Value $path

# Comando de refresco instantáneo (Sin errores de teclado!)
Add-Type -TypeDefinition 'using System.Runtime.InteropServices; [DllImport("user32.dll")] public class W {[DllImport("user32.dll")] public static extern int SystemParametersInfo(int u, int p, string v, int f);}'
[W]::SystemParametersInfo(20, 0, $path, 3)
