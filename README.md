# cpp-distributed-text-system
Distributed Text Editor Coding Challange
## Building
1. This repo was created in the Ubuntu Windows Subsystem for Linux (WSL) enviroment.
2. This capability can be configured using the PowerShell
3. Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
4. The build system requires some host packages, primarily, make.
5. In the WSL enviroment, run: sudo apt-get install -y make
6. With make installed, the remaining dependencies can be installed using make prep-ubuntu-18.04
7. Finally, build the application: make all

## Running
1. Navigate to the application output directory (cd output/distributed-text-application).
2. Run the program by executing the elf application (./distributed-text.elf), you MUST execute from the same directory as the executable.
3. The application will print out necessary arguments.
4. Specify the necessary arguments in the format specified while exectuing the binary.
5. Open a browser and navigate to: http://localhost:8080/editor or specified webserver\_host and webserver\_port
