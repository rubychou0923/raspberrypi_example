#!/usr/bin/python
# -*- coding:utf-8 -*-
import sys
import os
picdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'pic')
libdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'lib')
if os.path.exists(libdir):
    sys.path.append(libdir)

import logging
from waveshare_epd import epd2in13b_V4
import time
from PIL import Image,ImageDraw,ImageFont
import traceback
from os import walk
import glob

logging.basicConfig(level=logging.DEBUG)
sleep=2
font_size=16

try:
    logging.info("epd2in13b_V4 Demo")
    
    epd = epd2in13b_V4.EPD()
    logging.info("init and Clear")
    epd.init()
    epd.Clear()
    #time.sleep(1)
    
    # Drawing on the image
    logging.info("Drawing")    
    #font16 = ImageFont.truetype(os.path.join(picdir, 'Font.ttc'), 16)
    #font16 = ImageFont.truetype("/home/ruby/fonts/BoutiqueBitmap7x7/BoutiqueBitmap7x7_1.5.ttf", 16)
    #font16 = ImageFont.truetype("/home/ruby/fonts/tk-fangsong-font/dist/tkFangSong.ttf", 16)
    #font16 = ImageFont.truetype("/home/ruby/fonts/genseki-font/ttc/GenSekiGothic-M.ttc",15)
    font16 = ImageFont.truetype("/home/ruby/fonts/超研澤粗行楷.ttf",font_size)
  

    mypath="/home/ruby/fonts/"
    filenames = (glob.glob(mypath+"*")) 
    
    #for (dirpath, dirnames, filenames) in walk(mypath):
    #    print(filenames)
    #    #if( "ttc" in filenames or "TTC" in filenames):
    #    #    print("hit ttc or TTC")
    #    #    f.extend(filenames)
    #    break 

    for file in filenames:
        font_path = file
        print(font_path)
        if(not 'ttc' in file and not 'TTC' in file):
            continue
        font16 = ImageFont.truetype(font_path,font_size)
        print("Font:"+font_path)
        # Drawing on the Horizontal image
        logging.info("1.Drawing on the Horizontal image...") 
        HBlackimage = Image.new('1', (epd.height, epd.width), 255)  # 250*162
        HRYimage = Image.new('1', (epd.height, epd.width), 255)  # 250*162
        drawblack = ImageDraw.Draw(HBlackimage)
        drawry = ImageDraw.Draw(HRYimage)
        drawblack.text((0, 5), '申命記31:6', font = font16, fill = 0)
        drawblack.text((0, 30), '你們當剛強壯膽，不要害怕，也', font = font16, fill = 0)
        drawblack.text((0, 50), '不要畏懼他們，因為耶和華你的神', font = font16, fill = 0)
        drawblack.text((0, 70), '的神和你同去，他必不撇下你，也', font = font16, fill = 0)
        drawblack.text((0, 90), '不丟棄你。', font = font16, fill = 0)
        epd.display(epd.getbuffer(HBlackimage), epd.getbuffer(HRYimage))
        time.sleep(sleep)
    
    font16 = ImageFont.truetype("/home/ruby/fonts/標楷體.ttc",font_size)
    print("Font:"+font_path)
    # Drawing on the Horizontal image
    logging.info("1.Drawing on the Horizontal image...") 
    HBlackimage = Image.new('1', (epd.height, epd.width), 255)  # 250*162
    HRYimage = Image.new('1', (epd.height, epd.width), 255)  # 250*162
    drawblack = ImageDraw.Draw(HBlackimage)
    drawry = ImageDraw.Draw(HRYimage)
    drawblack.text((0, 5), '申命記31:6', font = font16, fill = 0)
    drawblack.text((0, 30), '你們當剛強壯膽，不要害怕，也', font = font16, fill = 0)
    drawblack.text((0, 50), '不要畏懼他們，因為耶和華你的神', font = font16, fill = 0)
    drawblack.text((0, 70), '的神和你同去，他必不撇下你，也', font = font16, fill = 0)
    drawblack.text((0, 90), '不丟棄你。', font = font16, fill = 0)
    epd.display(epd.getbuffer(HBlackimage), epd.getbuffer(HRYimage))
    time.sleep(100)
    
    logging.info("Goto Sleep...")
    epd.sleep()
        
except IOError as e:
    logging.info(e)
    
except KeyboardInterrupt:    
    logging.info("ctrl + c:")
    epd2in13b_V4.epdconfig.module_exit(cleanup=True)
    exit()
