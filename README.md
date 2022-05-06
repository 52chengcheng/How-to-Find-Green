# 绿色方法1：
step1:令r,g,b分别取值   
step2:对图像的像素进行处理p(i,j)=r\*p_red(i,j)+g\*p_green(i,j)+b\*p_blue(i,j)   
step3:如果p(i,j)>255,那么令p(i,j)=255；如果p(i,j)<0,那么p(i,j)=0；  
step4:最后设置阈值，进行二值化处理。
step5:将p分别和三通道进行逻辑与运算，合并三通道

![asdsf](https://user-images.githubusercontent.com/93379580/166921133-59b8f4bf-7ad7-4dd0-99e3-c9da61c29470.PNG)  
<p align="center">   
  jpg1-05年A.Ribeiro
</p>  



# 绿色方法2：   
step1:对RGB通道进行分离，R(i,j),G(i,j),B(i,j)分别三个通道为在(i,j)点的像素值    
step2:保留G(i,j)>B(i,j)且G(i,j)>R(i,j)点的像素，其它情况R(i,j),G(i,j),B(i,j)都为0   
step3:最后合并三通道   
![g-and](https://user-images.githubusercontent.com/93379580/166100810-283a1d80-941f-48a1-bde6-a0e37e9db4af.PNG)
<p align="center">   
  jpg2-11年张志斌
</p>  


# 绿色方法3： 
step1:对RGB通道进行分离，R(i,j),G(i,j),B(i,j)分别三个通道为在(i,j)点的像素值    
step2:直接进行MxG(i,j)=2\*G(i,j)-B(i,j)-R(i,j)。其中MxG(i,j)大于255时令MxG(i,j)=255；MxG(i,j)小于0时，令MxG(i,j)=0  
step3:对MxG灰度图像进行二值化，可以利用OTSU，自适应阈值分割，自己设置阈值等   
step3:逻辑与运算后合并三通道   
![54454554](https://user-images.githubusercontent.com/93379580/165488505-f1e10c63-3ee0-4575-b0ac-eb9ef27ca9fc.PNG)
<p align="center">   
  jpg3
</p>  


# 绿色方法4： 
step1:对RGB通道进行分离，R(i,j),G(i,j),B(i,j)分别三个通道为在(i,j)点的像素值    
step2:令r(i,j)=R(i,j)/(R(i,j)+G(i,j)+B(i,j)),g(i,j)=R(i,j)/(R(i,j)+G(i,j)+B(i,j)),b(i,j)=R(i,j)/(R(i,j)+G(i,j)+B(i,j))   
step3:进行MxG(i,j)=2\*g(i,j)-b(i,j)-r(i,j)。其中MxG(i,j)大于thresh时令MxG(i,j)=255；MxG(i,j)小于thresh时，令MxG(i,j)=0    
step3:逻辑与运算后合并三通道   
![4](https://user-images.githubusercontent.com/93379580/167097362-cfdf2e7d-90f5-413f-a940-b41d436d1951.PNG)
<p align="center">   
  jpg4
</p>  


# -
基于C++和opencv的超绿色特征分割，
记录对绿色提取的一些方法。

