def specialCharacters():
    chars_to_remove = [chr(x) for x in range(0, 128) if( (x < 65) | ((x > 90) & (x < 97)) | (x > 122)) ]    
    return chars_to_remove

def main():
    special = specialCharacters()
    print(special)

main()
