//
//  MatchingSystem.m
//  SnoBros2
//
//  Created by Cjab on 1/15/13.
//  Copyright (c) 2013 Attack Slug. All rights reserved.
//

#import "MatchingSystem.h"

#import "Entity.h"
#import "EntityManager.h"
#import "BoundingBox.h"
#import "Collision.h"
#import "Transform.h"

@implementation MatchingSystem

- (id)initWithEntityManager:(EntityManager *)entityManager {
  self = [super init];
  if (self) {
    entityManager_ = entityManager;
    boundsEntity_ = [entityManager_ buildEntity:@"MapNode"];

    topLeftEntity_ = [entityManager_ buildEntity:@"MapNode"];
    topRightEntity_ = [entityManager_ buildEntity:@"MapNode"];
    bottomLeftEntity_ = [entityManager_ buildEntity:@"MapNode"];
    bottomRightEntity_ = [entityManager_ buildEntity:@"MapNode"];

    [entityManager_ add:boundsEntity_];
    [entityManager_ add:topLeftEntity_];
    [entityManager_ add:topRightEntity_];
    [entityManager_ add:bottomLeftEntity_];
    [entityManager_ add:bottomRightEntity_];
  }
  return self;
}



- (void)activate {
}



- (void)deactivate {
}



- (void)update {
  NSMutableArray *shapes = [entityManager_ findAllWithComponent:@"Selectable"];
  NSMutableArray *boxes  = [[NSMutableArray alloc] initWithCapacity:shapes.count];
  for (Entity *shape in shapes) {
    Collision *collision = [shape getComponentByString:@"Collision"];
    [boxes addObject:collision.boundingBox];
  }

  if (boxes.count >= 1) {
    BoundingBox *container = boxes[0];
    for (BoundingBox *other in boxes) {
      container = [container unionWith:other];
    }

    Transform *t = [boundsEntity_ getComponentByString:@"Transform"];
    t.position = GLKVector2Make(container.x, container.y);

    BoundingBox *topLeft  = [[BoundingBox alloc] initWithX:(container.x - (container.width  / 2.f)) + 16.f
                                                         Y:(container.y - (container.height / 2.f)) + 16.f
                                                     width:32.f
                                                    height:32.f];
    t = [topLeftEntity_ getComponentByString:@"Transform"];
    t.position = GLKVector2Make(topLeft.x, topLeft.y);


    BoundingBox *topRight  = [[BoundingBox alloc] initWithX:(container.x + (container.width  / 2.f)) - 16.f
                                                          Y:(container.y - (container.height / 2.f)) + 16.f
                                                      width:32.f
                                                     height:32.f];
    t = [topRightEntity_ getComponentByString:@"Transform"];
    t.position = GLKVector2Make(topRight.x, topRight.y);

    BoundingBox *bottomLeft  = [[BoundingBox alloc] initWithX:(container.x - (container.width  / 2.f)) + 16.f
                                                          Y:(container.y + (container.height / 2.f)) - 16.f
                                                      width:32.f
                                                     height:32.f];
    t = [bottomLeftEntity_ getComponentByString:@"Transform"];
    t.position = GLKVector2Make(bottomLeft.x, bottomLeft.y);

    BoundingBox *bottomRight  = [[BoundingBox alloc] initWithX:(container.x + (container.width  / 2.f)) - 16.f
                                                          Y:(container.y + (container.height / 2.f)) - 16.f
                                                      width:32.f
                                                     height:32.f];
    t = [bottomRightEntity_ getComponentByString:@"Transform"];
    t.position = GLKVector2Make(bottomRight.x, bottomRight.y);
  }


}

@end