## Demo

https://bugraas.github.io/  
https://alaula.itch.io/potion-shop

## Documentation

![status](https://codedocs.xyz/BugraAS/witchs-brew.svg)
https://codedocs.xyz/BugraAS/witchs-brew

## What is this?

This is a modified version of the raylib game template aiming for an easy setup for Web targeted games via emscripten.

It aims to fully automate the creation of the development environment with the use of dev-containers with Visual Studio Code.

### How to use?

- Clone this repo and open it inside VS Code.
- Install the dev containers extension in VS Code and re-open the repository in a container. (You must have docker engine installed to do this. The VS Code extension can install it but I never tried that feature.)
- The extension should read the configurations I left to create a container with all the requirements for compiling and running this project. You will need internet access for this.
- Once the container is created, you will be asked to choose a kit. Choose Emscripten. Which should get you ready for Web compilation.
- You can compile the project using the `build` button that should appear at the bottom of VS Code. If you are getting errors, try deleting the build folder.
- Once compilation is done. You can run the game using the custom task I created by:
    - `Ctrl+Shift+P`
    - enter `Run Task`
    - You should see a task named `python http server` use that.
    - It should compile project and launch a http server. Click on the link you see on the terminal.
    - Which will open a port from the dev container to display the game on your browser

-----------------------------------

_DISCLAIMER:_

Welcome to **raylib game template**!

This template provides a base structure to start developing a small raylib game in plain C. The repo is also pre-configured with a default `LICENSE` (zlib/libpng) and a `README.md` (this one) to be properly filled by users. Feel free to change the LICENSE as required.

All the sections defined by `$(Data to Fill)` are expected to be edited and filled properly. It's recommended to delete this disclaimer message after editing this `README.md` file.

This template has been created to be used with raylib (www.raylib.com) and it's licensed under an unmodified zlib/libpng license.

_Copyright (c) 2014-2023 Ramon Santamaria ([@raysan5](https://twitter.com/raysan5))_

-----------------------------------
## Getting Started with this template
- After extracting the zip, the parent folder `raylib-game-template` should exist in the same directory as `raylib` itself.  So your file structure should look like this:
    - Some parent directory
        - `raylib`
            - the contents of https://github.com/raysan5/raylib
        - `raylib-game-template`
            - this `README.md` and all other raylib-game-template files
- If using Visual Studio, open projects/VS2022/raylib-game-template.sln
- Select on `raylib_game` in the solution explorer, then in the toolbar at the top, click `Project` > `Set as Startup Project`
- Now you're all set up!  Click `Local Windows Debugger` with the green play arrow and the project will run.

## $(Game Title)

![$(Game Title)](screenshots/screenshot000.png "$(Game Title)")

### Description

$(Your Game Description)

### Features

 - $(Game Feature 01)
 - $(Game Feature 02)
 - $(Game Feature 03)

### Controls

Keyboard:
 - $(Game Control 01)
 - $(Game Control 02)
 - $(Game Control 03)

### Screenshots

_TODO: Show your game to the world, animated GIFs recommended!._

### Developers

 - $(Developer 01) - $(Role/Tasks Developed)
 - $(Developer 02) - $(Role/Tasks Developed)
 - $(Developer 03) - $(Role/Tasks Developed)

### Links

 - YouTube Gameplay: $(YouTube Link)
 - itch.io Release: $(itch.io Game Page)
 - Steam Release: $(Steam Game Page)

### License

This game sources are licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.

$(Additional Licenses)

*Copyright (c) $(Year) $(User Name) ($(User Twitter/GitHub Name))*
