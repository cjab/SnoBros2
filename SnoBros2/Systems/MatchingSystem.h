//
//  MatchingSystem.h
//  SnoBros2
//
//  Created by Cjab on 1/15/13.
//  Copyright (c) 2013 Attack Slug. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GameSystem.h"

@class BoundingBox;
@class EntityManager;
@class Entity;

@interface MatchingSystem : NSObject <GameSystem> {
  BoundingBox   *container_;
  EntityManager *entityManager_;
  Entity        *boundsEntity_;

  Entity        *topLeftEntity_;
  Entity        *topRightEntity_;
  Entity        *bottomLeftEntity_;
  Entity        *bottomRightEntity_;
}

- (id)initWithEntityManager:(EntityManager *)entityManager;

- (void)activate;
- (void)deactivate;
- (void)update;

@end