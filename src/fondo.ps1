$u = "https://raw.githubusercontent.com/M1ch43l-B/rubber-ducky-casero/main/src/jesucristo.jpeg"
$f = "$env:TEMP\bg.jpg"
(New-Object System.Net.WebClient).DownloadFile($u, $f)
Set-ItemProperty -Path 'HKCU:\Control Panel\Desktop' -Name Wallpaper -Value $f
Add-Type -TypeDefinition 'using System.Runtime.InteropServices; [DllImport("user32.dll")] public class W {[DllImport("user32.dll")] public static extern int SystemParametersInfo(int u, int p, string v, int f);}'
[W]::SystemParametersInfo(20, 0, $f, 3)
