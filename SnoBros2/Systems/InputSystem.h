//
//  Input.h
//  Component
//
//  Created by Chad Jablonski on 11/5/12.
//  Copyright (c) 2012 Attack Slug. All rights reserved.
//

#import <UIKit/UIKit.h>

@class EntityManager;
@class Camera;

@interface InputSystem : NSObject {
  EntityManager             *entityManager_;
  Camera                    *camera_;

  UITapGestureRecognizer    *oneFingerTap_;
  UITapGestureRecognizer    *twoFingerTap_;
  UITapGestureRecognizer    *buttonTap_;
  UIPanGestureRecognizer    *boxSelector_;
}


- (id)initWithView:(UIView *)view
     entityManager:(EntityManager *)entityManager
            camera:(Camera *)camera;
@end