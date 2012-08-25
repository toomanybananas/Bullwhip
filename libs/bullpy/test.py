from bullwhip import *
mydef = Def()
mydef.SetInt("someint", 5)
mydef.SetString("somestr", "blue")
mydef.SetFloat("somefloat", 3.14)

print(mydef.GetInt("someint"))
print(mydef.GetFloat("somefloat"))
print(mydef.GetString("somestr"))
