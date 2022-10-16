//
// Created by Galli on 9/10/2022.
//

/*
 * 1. mid = (l + r + 1) / 2
 *    if (check(mid))
 *          true [mid, r] l = mid;
 *          false [l, mid - 1] r = mid - 1;
 * 2. mid = (l+ r) / 2
 *    if (check(mid))
 *          true [l, mid] r = mid;
 *          false [mid + 1, r] l = mid + 1;
 */