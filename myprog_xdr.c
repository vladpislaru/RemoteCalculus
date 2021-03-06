/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "myprog.h"

bool_t
xdr_SensorsArray (XDR *xdrs, SensorsArray *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->SensorsArray_val, (u_int *) &objp->SensorsArray_len, ~0,
		sizeof (struct SensorData), (xdrproc_t) xdr_SensorData))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_SensorData (XDR *xdrs, SensorData *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->dataId))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->noValues))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->values.values_val, (u_int *) &objp->values.values_len, ~0,
		sizeof (float), (xdrproc_t) xdr_float))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_GetData (XDR *xdrs, GetData *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->sensor))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->session))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_PostData (XDR *xdrs, PostData *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->session))
		 return FALSE;
	 if (!xdr_SensorData (xdrs, &objp->sensor))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_SensorStat (XDR *xdrs, SensorStat *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->min))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->max))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->middle))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->median))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->min);
			IXDR_PUT_LONG(buf, objp->max);
			IXDR_PUT_LONG(buf, objp->middle);
			IXDR_PUT_LONG(buf, objp->median);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->min))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->max))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->middle))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->median))
				 return FALSE;
		} else {
			objp->min = IXDR_GET_LONG(buf);
			objp->max = IXDR_GET_LONG(buf);
			objp->middle = IXDR_GET_LONG(buf);
			objp->median = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->min))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->max))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->middle))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->median))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_UserSpace (XDR *xdrs, UserSpace *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->session))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->username, ~0))
		 return FALSE;
	 if (!xdr_SensorData (xdrs, &objp->bd))
		 return FALSE;
	return TRUE;
}
