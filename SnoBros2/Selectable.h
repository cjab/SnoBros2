//
//  Selectable.h
//  SnoBros2
//
//  Created by Tanoy Sinha on 11/20/12.
//  Copyright (c) 2012 Cjab. All rights reserved.
//

#import <GLKit/GLKit.h>

#import "Component.h"

@interface Selectable : Component {
  BOOL  selected_;
}

@property (nonatomic) BOOL selected;

- (id) initWithEntity:(Entity *)entity;
- (id)initWithEntity:(Entity *)entity dictionary:(NSDictionary *)data;

- (BOOL) isAtLocation:(GLKVector2)location;
- (BOOL) isInRectangle:(CGRect)rectangle;

@end