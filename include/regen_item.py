


ids = []



with open("item.h", "r") as ii:
    lines = iter(ii)
    with open("_item.h", "w") as io:
        while True:
            line = next(lines)
            io.write(line)
            if line == "const ItemMeta itemMetas[] = {\n":
                break
        while True:
            line = next(lines)
            if line == "};\n":
                io.write(line)
                break
            entry = line.split('\"', 2)
            ids += [entry[1].upper()]
            if True:
                io.write("    {\"" + entry[1] + "\"" + entry[2])
            else:
                io.write(line)
    io.write("\n\n\n")
    for i in range(len(ids)):
        n = str(i)
        j = 32 - len(ids[i])
        io.write(
            "#define ID_" + ids[i] + (j * ' ') + '(' +
            ((4 - len(n)) * ' ') + n + ")\n"
        )
    io.write("\n\n\n#endif\n\n\n")



with open("block.h", "w") as bi:
    lines = iter(bi)
    with open("_block.h", "w") as bo:
        while True:
            line = next(lines)
            bo.write(line)
            if line == "const BlockMeta blockMetas[] = {\n":
                break
        while True:
            line = next(lines)
            if line == "};\n":
                bo.write(line)
                break
            entry = line.split('\"', 2)
            ids += [entry[1].upper()]
            if True:
                bo.write("    {\"" + entry[1] + "\"" + entry[2])
            else:
                bo.write(line)


