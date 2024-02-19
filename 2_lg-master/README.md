* Install lg library: 

#Open the Raspberry Pi terminal and run the following commands:  
wget https://github.com/joan2937/lg/archive/master.zip 
unzip master.zip 
cd lg-master 
make 
sudo make install 
#For more details, you can refer to: https://github.com/gpiozero/lg

* Document
http://abyz.me.uk/lg/lgpio.html


* Hint
```
handle = lgGpiochipOpen(0);
```