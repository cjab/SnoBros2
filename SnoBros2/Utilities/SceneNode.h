//
//  SceneNode.h
//  SnoBros2
//
//  Created by Tanoy Sinha on 11/27/12.
//  Copyright (c) 2012 Attack Slug. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

@class Sprite;

@interface SceneNode : NSObject {
  SceneNode       *parent_;
  NSMutableArray  *children_;
  NSString        *spriteName_;
  GLKMatrix4      modelViewMatrix_;
  BOOL            visible_;
}

@property (nonatomic) SceneNode       *parent;
@property (nonatomic) NSMutableArray  *children;
@property (nonatomic) NSString        *spriteName;
@property (nonatomic) GLKMatrix4      modelViewMatrix;
@property (nonatomic) BOOL            visible;

- (id)initWithSpriteRef:(NSString *)spriteRef;
- (void)addChild:(SceneNode *)child;
- (void)addChildren:(NSArray *)children;
- (void)translate:(GLKVector2)translation;

@end
