vowels = "aeiouyAEIOUY"
consonants = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ"

inp_str = input("")
out_str = inp_str
if(len(inp_str)<=100 and len(inp_str)>0):
    for i in out_str:
        for j in vowels:
            if i == j:
                out_str = out_str.replace(i,'')

    for i in out_str:
        for j in consonants:
            if i == j:
                out_str=out_str.replace(i,"."+i)

    out_str =out_str.lower()

    print(out_str)  