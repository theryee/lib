#ifndef MACROS_H
#define MACROS_H

#define FIT(it,x) for( typeof((x).begin()) it = (x).begin(); (it) != (x).end(); (it)++)
#define ll long long
#define ull unsigned long long

#ifdef USE_DEBUG
#define DEBUG(x) x
#else
#define DEBUG(x)
#endif

#endif
