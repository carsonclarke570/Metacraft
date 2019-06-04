


with open("block.h", "r") as fi:
    with open("_block.h", "w") as fo:
        lines = iter(fi)
        
        while True:
            line = next(lines)
            fo.write(line)
            if line == "const BlockMeta blockMetas[] = {\n":
                break
        
        line = next(lines)
        
        while not line == "};\n":
            comment = line.split('}')[1]
            fo.write(
                "    {0b00000000, 0x0000, 0, NULL, NULL}" + comment
            )
            line = next(lines)
        
        fo.write("};\n\n\n\n#endif\n\n\n")



