


with open("item.h", "r") as fi:
    with open("_item.h", "w") as fo:
        lines = iter(fi)
        items = []
        i = 0
        
        line = next(lines)
        fo.write(line)
        
        while not line == "const ItemProperty itemProperties[] {\n":
            line = next(lines)
            fo.write(line)
        
        line = next(lines)
        fo.write(line)
        
        while not line == "};\n":
            items += [line.split('\"')[1].upper()]
            i += 1
            line = next(lines)
            fo.write(line)
        
        fo.write("\n\n\n")
        for i in range(len(items)):
            n = str(i)
            j = 32 - len(items[i])
            fo.write(
                "#define " + items[i] + (j * ' ') + '(' +
                ((4 - len(n)) * ' ') + n + ")\n"
            )
        fo.write("\n\n\n#endif\n\n\n\n")



