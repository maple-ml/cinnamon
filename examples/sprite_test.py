# this file goes in Geometry Dash/cinnamon/mods/ (eventually will have to be in a mod folder)

import cinnamon
import geometrydash as gd
from cocos2d import *

class MenuLayer:
    @cinnamon.hook(gd.MenuLayer.init)
    def init(self):
        result = gd.MenuLayer.initO(self)

        sprite = CCSprite.create("GJ_button_01.png")

        director = CCDirector.sharedDirector()

        winSize = director.getWinSize()

        sprite.setPosition(winSize.width / 3, winSize.height / 3)
        
        self.addChild(sprite, 9999)

        return result

class SpriteTest(cinnamon.Mod):
    def __init__(self):
        cinnamon.Mod.__init__(self)
        self.name = "sprite_test"
        self.version = "0.0.1"
        self.author = "spook"
        self.description = "Adds a sprite to the screen!"

cinnamon.register_mod(SpriteTest)
