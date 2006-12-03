/*
**
** TheBar - Next Generation MUI Buttons Bar Class
**
** Copyright 2003-2005 by Alfonso [alfie] Ranieri <alforan@tin.it>
** All Rights Are Reserved.
**
** Destributed Under The Terms Of The LGPL II
**
**
**/

#ifndef _CLASS_H
#define _CLASS_H

#include <diskfont/glyph.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/utility.h>
#include <proto/diskfont.h>
#include <proto/graphics.h>
#include <proto/datatypes.h>
#include <proto/cybergraphics.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>

#include <clib/alib_protos.h>

#include <graphics/rpattr.h>
#include <utility/pack.h>
#include <datatypes/pictureclass.h>
#include <cybergraphx/cybergraphics.h>

#include <string.h>

#include <mui/TheBar_mcc.h>

#include "private.h"

#include "SDI_compiler.h"

/****************************************************************************/

#define _riflags(obj) (muiRenderInfo(obj)->mri_Flags)

/***********************************************************************/

enum
{
    MINTERM_ZERO        = 0,
    MINTERM_ONE         = ABC | ABNC | ANBC | ANBNC | NABC | NABNC | NANBC | NANBNC,
    MINTERM_COPY        = ABC | ABNC | NABC | NABNC,
    MINTERM_NOT_C       = ABNC | ANBNC | NABNC | NANBNC,
    MINTERM_B_AND_C     = ABC | NABC,
    MINTERM_NOT_B_AND_C = ANBC | NANBC,
    MINTERM_B_OR_C      = ABC | ABNC | NABC | NABNC | ANBC | NANBC,
};

/****************************************************************************/
/*
** stripUnderscore() modes
*/

enum
{
    STRIP_First,
    STRIP_All,
};

/***********************************************************************/

struct scale
{
    UWORD w;
    UWORD tw;
    UWORD sl;
    UWORD st;
    UWORD sw;
    UWORD sh;
    UWORD dw;
    UWORD dh;
};

/***********************************************************************/

/* utils.c */
#ifndef __MORPHOS__
Object * VARARGS68K DoSuperNew(struct IClass *cl, Object *obj, ...);
#endif
APTR allocVecPooled(APTR pool, ULONG size);
void freeVecPooled(APTR pool, APTR mem);
void stripUnderscore(STRPTR dest , STRPTR from, ULONG mode);
struct TextFont *openFont(STRPTR name);
APTR allocArbitratePooled(ULONG size);
APTR freeArbitratePooled(APTR mem, ULONG size);
APTR allocArbitrateVecPooled(ULONG size);
APTR freeArbitrateVecPooled(APTR mem);

/* brc1.c */
USHORT BRCUnpack(signed char *pSource, signed char *pDest, LONG srcBytes0, LONG dstBytes0);

/* scale.c */
void scale(struct scale *sce , UBYTE *src , UBYTE *dst);
void scaleRGB(struct scale *sce , ULONG *src , ULONG *dst);

/* build.c */
void scaleStripBitMaps(struct InstData *data);
void freeBitMaps(struct InstData *data);
void build(struct InstData *data);

/***********************************************************************/

#endif /* _CLASS_H */
