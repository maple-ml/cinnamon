# this file goes in Geometry Dash/cinnamon/mods/ (eventually will have to be in a mod folder)

import cinnamon
import geometry_dash as gd
import cocos2d as cc

class MenuLayer:
    @cinnamon.hook(gd.MenuLayer.init)
    def init(self):
        result = gd.MenuLayer.initO(self)

        sprite = cc.CCSprite.create("GJ_button_01.png")
        menu = cc.CCMenu.create()

        director = cc.CCDirector.sharedDirector()

        winSize = director.getWinSize()

        btn = gd.CCMenuItemSpriteExtra.create(sprite, self, self.button_clicked)

        menu.addChild(btn)

        menu.setPosition(winSize.width / 3, winSize.height / 3)
        
        self.addChild(menu, 9999)

        return result
    
    def button_clicked(self, sender):
        print("Button pressed", self, sender)
        scene = cc.CCScene.create()
        sprite = cc.CCSprite.create("GJ_button_01.png")
        text = cc.CCLabelBMFont.create("Hello World from python!", "bigFont.fnt")

        director = cc.CCDirector.sharedDirector()

        winSize = director.getWinSize()

        sprite.setPosition(winSize.width / 2, winSize.height / 2)
        text.setPosition(winSize.width / 2, winSize.height / 3)
        
        scene.addChild(sprite, 9999)
        scene.addChild(text, 9999)

        director.replaceScene(scene)

class ButtonTest(cinnamon.Mod):
    def __init__(self):
        cinnamon.Mod.__init__(self)
        self.name = "button_test"
        self.version = "0.0.1"
        self.author = "spook"
        self.description = "Adds a simple button to the screen!"

cinnamon.register_mod(ButtonTest)
