//#####################################################################
// Copyright 2009, Andrew Selle.
// This file is part of PhysBAM whose distribution is governed by the license contained in the accompanying file PHYSBAM_COPYRIGHT.txt.
//#####################################################################
#if !COMPILE_WITHOUT_DYADIC_SUPPORT || COMPILE_WITH_BINTREE_SUPPORT
#ifndef __INTERPOLATION_POLICY_DYADIC__
#define __INTERPOLATION_POLICY_DYADIC__

#include <PhysBAM_Tools/Grids_Dyadic_Interpolation/INTERPOLATION_DYADIC_FORWARD.h>
#include <PhysBAM_Tools/Interpolation/INTERPOLATION_FORWARD.h>
namespace PhysBAM{

template<class T_GRID> struct INTERPOLATION_POLICY;

template<class T> class BINTREE_GRID;
template<class T,int d> class VECTOR;

template<class T>
struct INTERPOLATION_POLICY<BINTREE_GRID<T> >
{
//     typedef INTERPOLATION_DYADIC<BINTREE_GRID<T>,T> INTERPOLATION_SCALAR;
    typedef LINEAR_INTERPOLATION_BINTREE_HELPER<T> LINEAR_INTERPOLATION_HELPER;
    typedef LINEAR_INTERPOLATION_MAC_1D_HELPER<BINTREE_GRID<T> > LINEAR_INTERPOLATION_MAC_HELPER;
    typedef FACE_LOOKUP_DYADIC<BINTREE_GRID<T> > FACE_LOOKUP;
//     typedef LINEAR_INTERPOLATION_DYADIC<BINTREE_GRID<T>,T> LINEAR_INTERPOLATION_SCALAR;
};

#ifndef COMPILE_WITHOUT_DYADIC_SUPPORT
template<class T> class QUADTREE_GRID;
template<class T> class OCTREE_GRID;

template<class T>
struct INTERPOLATION_POLICY<OCTREE_GRID<T> >
{
    typedef INTERPOLATION_DYADIC<OCTREE_GRID<T>,T> INTERPOLATION_SCALAR;
    typedef LINEAR_INTERPOLATION_OCTREE_HELPER<T> LINEAR_INTERPOLATION_HELPER;
    typedef LINEAR_INTERPOLATION_MAC_3D_HELPER<OCTREE_GRID<T> > LINEAR_INTERPOLATION_MAC_HELPER;
    typedef FACE_LOOKUP_DYADIC<OCTREE_GRID<T> > FACE_LOOKUP;
    typedef LINEAR_INTERPOLATION_DYADIC<OCTREE_GRID<T>,T> LINEAR_INTERPOLATION_SCALAR;
};

template<class T>
struct INTERPOLATION_POLICY<QUADTREE_GRID<T> >
{
    typedef INTERPOLATION_DYADIC<QUADTREE_GRID<T>,T> INTERPOLATION_SCALAR;
    typedef LINEAR_INTERPOLATION_QUADTREE_HELPER<T> LINEAR_INTERPOLATION_HELPER;
    typedef LINEAR_INTERPOLATION_MAC_2D_HELPER<QUADTREE_GRID<T> > LINEAR_INTERPOLATION_MAC_HELPER;
    typedef FACE_LOOKUP_DYADIC<QUADTREE_GRID<T> > FACE_LOOKUP;
    typedef LINEAR_INTERPOLATION_DYADIC<QUADTREE_GRID<T>,T> LINEAR_INTERPOLATION_SCALAR;
};
#endif
}
#endif
#endif