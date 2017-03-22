//
//  EdgeService.h
//  Edge
//
//  Created by Mo Afrasiabi on 2017-03-08.
//  Copyright © 2017 mimik technology inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EdgeService : NSObject

- (instancetype)init;
- (void)startWithServicePort:(int)port;
- (void)stop;

@end
