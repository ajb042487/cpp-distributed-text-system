# cpp-distributed-text-system
Distributed Text Editor Coding Challange
## Building
- This Software was created in the Ubuntu variant of the Windows Subsystem for Linux (WSL) enviroment.
- This capability can be configured using the PowerShell:`Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux`
- The build system requires some host packages, primarily, make.
- In the WSL enviroment, run: `sudo apt-get install -y make`
- With make installed, the remaining dependencies can be installed using: `make prep-ubuntu-18.04`
- Finally, build the application: `make all`

## Running
- Navigate to the application output directory: `cd output/distributed-text-application`.
- Run the program by executing the elf application: `./distributed-text.elf`, you MUST execute the application from the same directory as the executable.
- The application will print out any necessary arguments.
- Specify the necessary arguments in the format specified while exectuing the binary.
- Open a browser and navigate to: http://localhost:8080/ or replacing with webserver\_host and webserver\_port if they were provided.
