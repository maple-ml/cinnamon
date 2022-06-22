# this file goes in Geometry Dash/cinnamon/mods/ (eventually will have to be in a mod folder)

import cinnamon
import geometrydash as gd
from cocos2d import *

class MyMenuLayer:
    def init(self):
        gd.MenuLayer.initO(self)
        sprite = CCSprite("GJ_button_01.png")
        
        self.addChild(sprite)

class SpriteTest(cinnamon.Mod):
    def __init__(self):
        cinnamon.Mod.__init__(self)
        self.name = "sprite_test"
        self.version = "0.0.1"
        self.author = "spook"
        self.description = "Adds a sprite to the screen!"
        
        cinnamon.hook(gd.MenuLayer.init, MyMenuLayer.init)

cinnamon.register_mod(SpriteTest)
