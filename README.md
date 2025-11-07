From those above choose library you are interesed in. Curentlly avadiable only for windows with gcc extencion installed.
1. To connect your probram with lib, install library in same folder as your program.
2. Open terminal and change direction to the adress your program is in.
3. Type in terminal:
   gcc -shared -o dtabs.dll dtabs.c
4. Then type:
   gcc main.c -L. -ldtabs -o your_program //main.c instead of main type the name of your program, your_program is a new created program with .exe extencion
5. Then run your program by command in terminal:
   .\your_program

Enjoy!
