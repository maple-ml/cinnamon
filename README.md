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
* [cocos headers](https://github.com/HJfod/cocos-headers)
* [MinHook](https://github.com/TsudaKageyu/minhook/)
* [Python 3.9 (32-bit version)](https://www.python.org/downloads/)

## Development
When developing or debugging Cinnamon or any associated projects, a few prerequisites needed are:
* An IDE that supports working with C++ (standard revision 2017) with proper IntelliSense; primarily [Visual Studio 2019](https://visualstudio.microsoft.com/vs/), for the .sln
* CMake, to use the build configuration
* Optional: [maple-cli](https://github.com/maple-ml/cli), for ease of use 

### Source Code
You are able to clone the repository over command line, or by downloading it. Updating this code to the latest commit would be done with `git pull`, inside the tau directory.
```sh
git clone https://github.com/maple-ml/cinnamon
cd cinnamon
```

### Building
If using [maple-cli](https://github.com/maple-ml/cli), all you have to do is run `maple build` in the directory of cinnamon. The optional flags for this command are as follows:

`--quiet`: Tries to make the build quieter
`--run`: Attempts to run Geometry Dash after build has finished, great for debugging (`GDPATH` must be defined)
`--copy`: If the build succeeds, copies the generated dll to the `Geometry Dash/mods` directory (`GDPATH` must be defined)

`GDPATH` can be defined via environment variable (`%GDPATH%`) or the command line argument `--path GDPATH`

If you are not using [maple-cli](https://github.com/maple-ml/cli) you need to compile with cmake directly.

Here's what we recommend
```
cmake --build build32 --config Release
```

## Contributions

For new ideas and features, we would prefer for you to write an issue before trying to add it to show the maintainers.

## License
Cinnamon uses the MIT license. All of the projects used here have their own licenses, and any packed dependency will have their license provided in the [incl](https://github.com/maple-ml/cinnamon/tree/master/incl) folder for your convenience.