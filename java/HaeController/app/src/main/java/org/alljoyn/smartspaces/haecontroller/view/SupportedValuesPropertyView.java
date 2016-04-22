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
import android.os.AsyncTask;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.TextView;

import org.alljoyn.bus.annotation.Position;
import org.alljoyn.smartspaces.haecontroller.R;
import org.alljoyn.smartspaces.haecontroller.util.HaeUtil;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class SupportedValuesPropertyView extends PropertyView {
    private static final String TAG = "HAE_ReadWriteProperty";

    private Method supportedGetter = null;

    private TextView nameView;
    private Spinner valuesView;
    private TextView unitView;
    private Object[] params;
    private int position = -1;

    private ArrayAdapter<String> valuesAdapter;

    public SupportedValuesPropertyView(Context context, Object obj, String propertyName, String unit) {
        this(context, obj, propertyName, "Supported" + propertyName, unit);
    }

    public SupportedValuesPropertyView(Context context, Object obj, String propertyName, String unit, int position, String SupportedListPropertyName) {
        super(context, obj, propertyName, unit);
        this.position = position;
        try {
            this.supportedGetter = obj.getClass().getMethod("get" + SupportedListPropertyName);
        } catch (NoSuchMethodException e) {
            this.supportedGetter = null;
        }
    }

    public SupportedValuesPropertyView(Context context, Object obj, String propertyName, String unit, String SupportedListPropertyName) {
        this(context, obj, propertyName, unit, -1, SupportedListPropertyName);
    }

    public SupportedValuesPropertyView(Context context, Object obj, String propertyName, String unit, int position, String SupportedListMethodName, Object... parameters) {
        super(context, obj, propertyName, unit);

        params = parameters;

        this.position = position;

        this.supportedGetter = null;
        for (Method method : obj.getClass().getDeclaredMethods()) {
            if (method.getName().equals(SupportedListMethodName)) {
                this.supportedGetter = method;
                break;
            }
        }
    }

    public SupportedValuesPropertyView(Context context, Object obj, String propertyName, String unit, String SupportedListMethodName, Object... parameters) {
        this(context, obj, propertyName, unit, -1, SupportedListMethodName, parameters);
    }

    protected void initView() {
        LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        ViewGroup view = (ViewGroup) inflater.inflate(R.layout.view_supported_property, this, false);

        this.addView(view);

        this.nameView = (TextView) view.findViewById(R.id.property_name);
        this.valuesView = (Spinner) view.findViewById(R.id.property_values);
        this.unitView = (TextView) view.findViewById(R.id.property_unit);
        Log.d(TAG, "1: valueView is " + this.valuesView.toString());


        valuesAdapter = new ArrayAdapter<String>(this.getContext(), android.R.layout.simple_spinner_item);
        this.valuesView.setAdapter(valuesAdapter);

        this.valuesView.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                SupportedValuesPropertyView.this.setProperty(SupportedValuesPropertyView.this.valuesAdapter.getItem(position));
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        this.nameView.setText(this.name);
        if (this.unit != null && !this.unit.isEmpty())
            this.unitView.setText(this.unit);
        else
            this.unitView.setVisibility(View.GONE);
    }

    @Override
    public void setValueView(String value) {
        this.valuesView.setSelection(this.valuesAdapter.getPosition(value));
    }

    @Override
    protected void getProperty() {
        AsyncTask<Void, Void, Object> execute = new AsyncTask<Void, Void, Object>() {
            @Override
            protected Object doInBackground(Void... voids) {
                Object returnObj = null;
                try {
                    if (SupportedValuesPropertyView.this.supportedGetter != null) {
                        Class<?>[] paramTypes = SupportedValuesPropertyView.this.supportedGetter.getParameterTypes();
                        Object[] params = new Object[paramTypes.length];
                        int idx = 0;
                        for (Class<?> clazz : paramTypes) {
                            SupportedValuesPropertyView.this.params[idx] = HaeUtil.parseParams(clazz, SupportedValuesPropertyView.this.params[idx])[0];
                            idx++;
                        }
                        returnObj = supportedGetter.invoke(SupportedValuesPropertyView.this.busObject, SupportedValuesPropertyView.this.params);
                    }
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                } catch (InvocationTargetException e) {
                    e.printStackTrace();
                }
                return returnObj;
            }

            @Override
            protected void onPostExecute(Object o) {
                if (o != null) {
                    SupportedValuesPropertyView.this.valuesAdapter.clear();
                    Object[] result = (Object[])o;
                    for (Object obj : result) {
                        if (SupportedValuesPropertyView.this.position == -1)
                            SupportedValuesPropertyView.this.valuesAdapter.add(obj.toString());
                        else {
                            for (Field field : obj.getClass().getFields()) {
                                if (field.getAnnotation(Position.class).value() == SupportedValuesPropertyView.this.position) {
                                    Object value = null;
                                    try {
                                        value = field.get(obj);
                                        SupportedValuesPropertyView.this.valuesAdapter.add(value.toString());
                                    } catch (IllegalAccessException e) {
                                        e.printStackTrace();
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
                SupportedValuesPropertyView.super.getProperty();
            }
        }.execute();
    }
}
