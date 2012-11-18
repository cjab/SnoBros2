//
//  Renderer.h
//  Component
//
//  Created by Cjab on 11/3/12.
//  Copyright (c) 2012 Cjab. All rights reserved.
//

#import <GLKit/GLKit.h>
#import "Component.h"

@class Transform;
@class Sprite;
@class Camera;
@class Entity;

@interface Renderer : Component {
  GLKBaseEffect  *effect_;
  Sprite         *sprite_;
  Transform      *transform_;
  int            width_;
  int            height_;
}

@property (readonly, nonatomic) int width;
@property (readonly, nonatomic) int height;

- (id)initWithEntity:(Entity *)entity
           transform:(Transform *)transform
              sprite:(Sprite *)sprite;
- (void)updateWithCamera:(Camera*)camera
      interpolationRatio:(double)ratio;

@end
