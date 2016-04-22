/*
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

package org.alljoyn.smartspaces.haecontroller.util;

public class HaeUtil {
    public static <M> Object[] parseParams(Class<M> clazz, Object... objs) {
        Object[] params = new Object[objs.length];

        int idx = 0;
        for (Object obj : objs) {
            String value = obj.toString();
            if (clazz == Double.TYPE) {
                params[idx] = Double.parseDouble(value);
            } else if (clazz == Long.TYPE) {
                params[idx] = Long.parseLong(value);
            } else if (clazz == Integer.TYPE) {
                params[idx] = Integer.parseInt(value);
            } else if (clazz == Short.TYPE) {
                params[idx] = Short.parseShort(value);
            } else if (clazz == Byte.TYPE) {
                params[idx] = Byte.parseByte(value);
            } else if (clazz == String.class) {
                params[idx] = value;
            }
            idx++;
        }

        return params;
    }
}
