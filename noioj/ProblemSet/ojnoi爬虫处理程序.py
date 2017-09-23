# -*- coding: utf-8 -*-
"""
Created on Sat Sep 23 20:58:06 2017

@author: user
"""

fp = open("240993ed-f491-421e-b525-a49620218fc7.txt", "r")
data = fp.read(-1)
fp.close()

spl = data.split("KSDLSADEVEFMNVV")

for s in spl:
    code = s[s.find("<h2>")+4:s.find("<h2>")+8]
    s = s[0:s.find("来源/作者: ")]
    fw = open("D:/OJNOI/"+code+".html", "w")
    fw.write(s)
    fw.close()
