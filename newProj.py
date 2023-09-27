from os import mkdir
from os.path import join as j
from shutil import copyfile

pname = input("Enter new project name: ")
t = ".template"

mkdir(pname)
mkdir(j(pname, "headers"))
mkdir(j(pname, "src"))
copyfile(j(t, "main.c"), j(pname, "src", "main.c"))

with open(j(t, "CMakeLists.txt"), "r") as inp:
    with open(j(pname, "CMakeLists.txt"), "w") as out:
        out.write(inp.read().replace("<PNAME>", pname))
