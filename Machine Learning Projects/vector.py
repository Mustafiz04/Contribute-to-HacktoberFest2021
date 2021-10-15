from manim import *

class MoveVector(Scene):
    def construct(self):
        vector = Vector(direction=RIGHT)
        end_point = (4,0,0)
        animation = ApplyMethod(vector.shift,end_point)
        self.play(animation)
        
        
