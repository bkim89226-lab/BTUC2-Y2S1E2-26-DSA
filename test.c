// #include <stdio.h>
// #include <windows.h>

// int main() {
//     HKEY hKey;
//     char machineGuid[256];
//     DWORD bufferSize = sizeof(machineGuid);

//     // Open the registry key where Windows stores the MachineGuid
//     LONG result = RegOpenKeyExA(
//         HKEY_LOCAL_MACHINE,
//         "SOFTWARE\\Microsoft\\Cryptography",
//         0,
//         KEY_READ | KEY_WOW64_64KEY,
//         &hKey
//     );

//     if (result == ERROR_SUCCESS) {
//         // Query the MachineGuid value
//         result = RegQueryValueExA(
//             hKey,
//             "MachineGuid",
//             NULL,
//             NULL,
//             (LPBYTE)machineGuid,
//             &bufferSize
//         );

//         RegCloseKey(hKey);

//         if (result == ERROR_SUCCESS) {
//             printf("Computer Device ID (MachineGuid): %s\n", machineGuid);
//         } else {
//             printf("Failed to read MachineGuid value.\n");
//         }
//     } else {
//         printf("Failed to open registry key.\n");
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_motherboard_serial(char *buffer, size_t max_len) {
    FILE *fp;
    
#if defined(_WIN32) || defined(_WIN64)
    // Windows: Use the modern PowerShell call to get the motherboard serial
    //const char *cmd = "powershell -Command \"(Get-CimInstance Win32_BaseBoard).SerialNumber\"";
    // (Get-CimInstance -ClassName Win32_ComputerSystemProduct).UUID
    const char *cmd = "powershell -Command \"(Get-CimInstance -ClassName Win32_ComputerSystemProduct).UUID\"";
    
    fp = _popen(cmd, "r");
#elif defined(__linux__)
    // Linux: Read directly from the DMI system files (Requires root permissions)
    const char *cmd = "cat /sys/class/dmi/id/board_serial 2>/dev/null";
    fp = popen(cmd, "r");
#else
    strncpy(buffer, "Unsupported OS", max_len);
    return;
#endif

    if (fp == NULL) {
        strncpy(buffer, "Failed to run command", max_len);
        return;
    }

    // Read the output string into the buffer
    if (fgets(buffer, max_len, fp) != NULL) {
        // Strip trailing newline characters if present
        size_t len = strlen(buffer);
        while (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r')) {
            buffer[len - 1] = '\0';
            len--;
        }
    } else {
        strncpy(buffer, "Unavailable or Permission Denied", max_len);
    }

#if defined(_WIN32) || defined(_WIN64)
    _pclose(fp);
#else
    pclose(fp);
#endif
}

int main() {
    char serial[256] = {0};
    
    get_motherboard_serial(serial, sizeof(serial));
    printf("Motherboard Serial/Device ID: %s\n", serial);
    
    return 0;
}
