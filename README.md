
# DEVWAKE

This repository contains a simple Wake-on-LAN (WOL) service application written in C++. The application allows users to wake up devices on their network by sending WOL packets.

## Features

- Load and save configuration settings
- Display a main menu with options
- Send WOL packets to specified MAC addresses

## Files

### configuration.h

Contains configuration settings and function declarations for loading and saving configurations.

### main.cpp

The entry point of the application. It initializes the program by loading configuration settings and displaying the main menu.

### main_menu.cpp & main_menu.h

Defines the `MainMenu` class and its functions. The `display` function shows the menu options to the user.

### menu.cpp & menu.h

Defines a generic `Menu` class that allows adding options and displaying them. Each option is associated with a function pointer that gets called when the option is selected.

### wake_on_lan.cpp & wake_on_lan.h

Contains the implementation for sending WOL packets. The `sendWakeOnLanPacket` function constructs and sends the packet to wake up the specified device.

## How to Build

To compile the project, you can use the following commands:

```sh
g++ -o wol main.cpp main_menu.cpp menu.cpp wake_on_lan.cpp -std=c++11
```

## How to Run

After building the project, you can run the executable:

```sh
./wol
```

The program will start and display a menu where you can choose to wake a device or exit the program.

## Configuration

The configuration settings are defined in `configuration.h`. You can modify the following settings as needed:

- `SERVER_PORT`: The port number for the server (default: 8080)
- `WOL_PORT`: The port number for WOL packets (default: 9)
- `BROADCAST_ADDRESS`: The broadcast address for sending WOL packets (default: "255.255.255.255")

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
