ports = ['A','B','C','D','E','F','G','H','J','K','L']  # список портов

# for port in ports:
#     for i in range(8):
#         print(f"constexpr DigitalPin<DB{port}, {i}> P{port}{i};")
#     print()

for port in ports:
    for i in range(8):
        pin = f"P{port}{i}"
        print(f"#ifdef {pin}")
        print(f"    #undef {pin}")
        print(f"#endif")
    print()