# 绿色方法1：
step1:令r,g,b分别取值   
step2:对图像的像素进行处理p(i,j)=r\*p_red(i,j)+g\*p_green(i,j)+b\*p_blue(i,j)   
step3:如果p(i,j)>255,那么令p(i,j)=255；如果p(i,j)<0,那么p(i,j)=0；  
step4:最后设置阈值，进行二值化处理。   
jpg1：
![asdsf](https://user-images.githubusercontent.com/93379580/166918066-280f7874-8da6-4505-805b-3e1c0138d19a.PNG)   

# 绿色方法2：



超绿：![54454554](https://user-images.githubusercontent.com/93379580/165488505-f1e10c63-3ee0-4575-b0ac-eb9ef27ca9fc.PNG)
G_AND: ![g-and](https://user-images.githubusercontent.com/93379580/166100810-283a1d80-941f-48a1-bde6-a0e37e9db4af.PNG)

# -
基于C++和opencv的超绿色特征分割，
记录对绿色提取的一些方法。
