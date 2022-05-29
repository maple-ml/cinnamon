<div align="center">
	<img src="https://github.com/maple-ml/cinnamon/blob/master/assets/banner-main.png?raw=true">
</div>

###### The lovable and adorable Geometry Dash modloader.

<div>
    <a href="https://discord.gg/jHWE33TkJb"><img src="https://canary.discordapp.com/api/guilds/810630217605054474/widget.png?style=shield" alt="Join Discord Server"/></a>
</div>

----

**Cinnamon** is a project that aims to implement advanced modding capabilities to Geometry Dash, while providing a stable interface for advanced usage natively in Geometry Dash. Alongside providing an interactive and innovative model for developers to work off of, it aims to create a sustainable community and environment for that of creation, and prosperity.

## Objectives
* Provide a comprehensive API for interfacing with Geometry Dash.
* Maintain an active hub for these interfaces to be posted to.
* Value performance and abstraction equally, for newer developers.
* Cover whatever is possible of Geometry Dash, server or not.

## Installation
As of writing this (February 16th, 2021) there are no built binaries that can be added alongside Geometry Dash. We are currently in a **very early** stage of development, and do not expect for much to happen in a while.

### Dependencies
* [Cappuccino SDK](https://github.com/AndreNIH/CappuccinoSDK)
* [MinHook](https://github.com/TsudaKageyu/minhook/)
* [Python 3.9 (with debug binaries added)](https://www.python.org/downloads/)

## Development
When developing or debugging Cinnamon or any associated projects, a few prerequisites needed are:
* An IDE that supports working with C++ (standard revision 2017) with proper IntelliSense; primarily [Visual Studio 2019](https://visualstudio.microsoft.com/vs/), for the .sln
* A compiler that can handle C++17, and Windows headers; such as MSVC.

### Source Code
You are able to clone the repository over command line, or by downloading it. Updating this code to the latest commit would be done with `git pull`, inside the tau directory.
```sh
git clone https://github.com/maple-ml/cinnamon
cd cinnamon
```

### Building
We have not written a building guide, as this project is primarily self-explanatory built using [Visual Studio 2019](https://visualstudio.microsoft.com/vs/) and MSVC.
This section will be community managed, otherwise.

## Contributions

For new ideas and features, we would prefer for you to write an issue before trying to add it to show the maintainers.

## License
Cinnamon uses the MIT license. All of the projects used here have their own licenses, and any packed dependency will have their license provided in the [incl](https://github.com/maple-ml/cinnamon/tree/master/incl) folder for your convenience.