# :fork_knife_plate: Smart Fridge


**_Smart Fridge_** Command line system written in C, that manages the food in the fridge and offers recipes.
This project has been implemented for educational purposes for the final exam of the "Computer Science Laboratory" course of the degree in ITPS of the University of Bari.



## Cloning

First of all, you need to download the project through cloning.

```sh
git clone https://github.com/gmurro/smartFridge.git
cd smartFridge
```

## **1. Prerequisites**

> You need to have **_gcc_** compiler for C and **_cmake_** (min version 3.10) installed:
   - On linux
   
     ```sh
     sudo apt update
     sudo apt install build-essential
     sudo apt install cmake
     ```

   - On Windows

     You can install MinGW, following this [tutorial](http://collab.di.uniba.it/fabio/guide/guida-installazione-e-configurazione-ambiente-di-sviluppo-eclipse-cdt-cunit-windows/).

> If you want run test, **_CUnit_** is required:
   - On linux
     ```sh
     sudo apt update
     sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
     ```
   - On Windows
  
       You must install CUnit following this [tutorial](http://collab.di.uniba.it/fabio/guide/guida-installazione-e-configurazione-ambiente-di-sviluppo-eclipse-cdt-cunit-windows/).

## **2. Configuration**
#### 2.1 Configuration directory & change directory

> Generate build directory

```console
mkdir build && cd build
```



#### 2.2 Configuration cmake

> Choose configuration type: Debug or Release supported

- Debug

```console
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

**OR**

- Release

```console
cmake .. -DCMAKE_BUILD_TYPE=Release
```


#### 2.3 Change directory

> Change current directory to project root level

```console
cd ..
```

## **3. Compilation**

> The following command will build only smart fridge source code

```console
cmake --build build --target mySmartFridge
```

> If you want build also the test, run the following command

```console
cmake --build build --target test
```

## **4. Run**

> All binaries are under `build/bin/` folder. You can run the run with the following command

```console
cd build/bin
./mySmartFridge
./test
```


## [Docs](./doc/Documentazione.pdf)
Additional docs can be found under _doc_ folder.
It also been generated the documentation of the code using the tool Doxygen. Click [here to](.doc/'Documentazione doxygen'/index.html) see it


## Built With

- [CMake](https://cmake.org) - CMake is an open-source, cross-platform family of tools designed to build, test and package software
- [GNU Make](https://www.gnu.org/software/make/) - GNU Make is a tool which controls the generation of executables and other non-source files of a program from the program's source files.
- [Git](https://git-scm.com) - Git is a free and open source distributed version control system designed to handle everything from small to very large projects with speed and efficiency


## Versioning

We use [Git](https://git-scm.com) for versioning.


## Authors

| Matricola |  Name     |  Surname   |     Email                              |    Username      |
| :-------: | :-------: | :--------: | :------------------------------------: | :--------------: |
|  677798   | Giuseppe  | Murro      | `g.murro2@studenti.uniba.it`           | [_gmurro_](https://github.com/gmurro)         |
|  678711   | Alessio   | Tartarelli | `a.tartarelli2@studenti.uniba.it `     | [_0bugFound_](https://github.com/0bugFound) |




## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

