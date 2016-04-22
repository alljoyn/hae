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

package org.alljoyn.smartspaces.haecontroller.view;

import android.content.Context;
import android.graphics.Canvas;
import android.os.AsyncTask;
import android.widget.LinearLayout;

import org.alljoyn.bus.BusException;
import org.alljoyn.bus.BusObject;
import org.alljoyn.bus.Variant;
import org.alljoyn.smartspaces.haecontroller.util.HaeUtil;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public abstract class PropertyView extends LinearLayout {
    private Method valueGetter = null;
    private Method valueSetter = null;

    protected Object busObject = null;

    protected String name = null;
    protected String unit = null;

    public PropertyView(Context context, Object obj, String propertyName, String unit) {
        super(context);
        try {
            this.valueGetter = obj.getClass().getDeclaredMethod("get" + propertyName);
        } catch (NoSuchMethodException e) {
            this.valueGetter = null;
        }

        try {
            this.valueSetter = obj.getClass().getDeclaredMethod("set" + propertyName, this.valueGetter.getReturnType());
        } catch (NoSuchMethodException e) {
            this.valueSetter = null;
        }

        this.name = propertyName;
        this.busObject = obj;
        this.unit = unit;
        initView();
        getProperty();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        getProperty();
    }

    public String getName() { return this.name; }

    protected abstract void initView();

    protected abstract void setValueView(String value);

    public void setValueView(Variant value) {
        try {
            this.setValueView(value.getObject(this.valueGetter.getReturnType()).toString());
        } catch (BusException e) {
            e.printStackTrace();
        }
    }

    protected void setProperty(String value) {
        Object[] param = HaeUtil.parseParams(PropertyView.this.valueGetter.getReturnType(), value);

        AsyncTask<Object, Void, Void> excuteSet = new AsyncTask<Object, Void, Void>() {
            @Override
            protected Void doInBackground(Object... params) {
                Object returnObj = null;
                try {
                    if (PropertyView.this.valueSetter != null)
                        returnObj = valueSetter.invoke(PropertyView.this.busObject, params);
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                } catch (InvocationTargetException e) {
                    e.printStackTrace();
                }
                return null;
            }
        };
        excuteSet.execute(param);
    }

    protected void getProperty() {
        AsyncTask<Void, Void, Object> excuteGet = new AsyncTask<Void, Void, Object>() {
            @Override
            protected Object doInBackground(Void... params) {
                Object returnObj = null;
                try {
                    if (PropertyView.this.valueGetter != null)
                        returnObj = valueGetter.invoke(PropertyView.this.busObject);
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                } catch (InvocationTargetException e) {
                    e.printStackTrace();
                }
                return returnObj;
            }

            @Override
            protected void onPostExecute(Object o) {
                if (o != null)
                    PropertyView.this.setValueView(String.valueOf(o));
            }
        };
        excuteGet.execute();
    }
}
