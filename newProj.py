from os import mkdir, makedirs
from os.path import join as j
from shutil import copyfile
from argparse import ArgumentParser

parser =ArgumentParser()
parser.add_argument("-n", required=False)
args = parser.parse_args()

if args.n == None:
    ppath = input("Enter new project name: ").split("/")
else:
    ppath = args.n.split("/")
t = ".template"
pname = ppath[-1]

makedirs(j(*ppath))
mkdir(j(*ppath, "headers"))
mkdir(j(*ppath, "src"))
copyfile(j(t, "main.c"), j(*ppath, "src", "main.c"))

with open(j(t, "CMakeLists.txt"), "r") as inp:
    with open(j(*ppath, "CMakeLists.txt"), "w") as out:
        out.write(inp.read().replace("<PNAME>", pname))
