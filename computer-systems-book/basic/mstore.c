//  ----------------------------------------------------------------------------
//  Header file for the mstore class.        mstore.c
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on August 29, 2020.
//  Copyright (c) 2020 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

long mult2(long, long);

void multstore(long x, long y, long *dest) {
  long t = mult2(x, y);
  *dest = t;
}
