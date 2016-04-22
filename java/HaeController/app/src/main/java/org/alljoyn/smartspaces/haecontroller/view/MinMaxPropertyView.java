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
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.SeekBar;
import android.widget.TextView;

import org.alljoyn.bus.BusObject;
import org.alljoyn.smartspaces.haecontroller.R;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class MinMaxPropertyView extends PropertyView {
    private Method minGetter;
    private Method maxGetter;
    private Method stepGetter;

    private TextView nameView;
    private TextView valueView;
    private TextView minView;
    private TextView maxView;
    private MinMaxSeekBar seekBar;
    private TextView stepView;
    private TextView unitView;
    private Button submitBtn;

    private double value;
    private double min;
    private double max;
    private double step;

    public MinMaxPropertyView(Context context, Object obj, String valuePropertyName, String unit, String minPropertyName, String maxPropertyName, String stepPropertyName) {
        super(context, obj, valuePropertyName, unit);

        try {
            this.minGetter = obj.getClass().getDeclaredMethod("get" + minPropertyName);
            this.maxGetter = obj.getClass().getDeclaredMethod("get" + maxPropertyName);
            this.stepGetter = obj.getClass().getDeclaredMethod("get" + stepPropertyName);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
    }

    protected void initView() {
        LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        ViewGroup view = (ViewGroup) inflater.inflate(R.layout.view_min_max_property, this, false);

        this.addView(view);

        this.nameView = (TextView) view.findViewById(R.id.property_name);
        this.valueView = (TextView) view.findViewById(R.id.property_value);
        this.minView = (TextView) view.findViewById(R.id.min_value);
        this.maxView = (TextView) view.findViewById(R.id.max_value);
        this.seekBar = (MinMaxSeekBar) view.findViewById(R.id.seekBar);
        this.stepView = (TextView) view.findViewById(R.id.step_value);
        this.unitView = (TextView) view.findViewById(R.id.property_unit);

            this.nameView.setText(this.name);
        if (this.unit != null && !this.unit.isEmpty())
            this.unitView.setText(this.unit);
        else
            this.unitView.setVisibility(View.GONE);

        this.seekBar.setOnSeekBarChangeListener(new MinMaxSeekBar.OnMinMaxSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, double progress, boolean fromUser) {
                if (fromUser) {
                    MinMaxPropertyView.this.setProperty(String.valueOf(progress));
                    MinMaxPropertyView.this.setValueView(String.valueOf(progress));
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }

    @Override
    public void setValueView(String value) {
        double val;
        this.valueView.setText(value);
        this.value = Double.parseDouble(value);
        this.seekBar.setProgress(this.value);
    }

    @Override
    protected void getProperty() {
        super.getProperty();

        new AsyncTask<Void, Void, Object>() {
            @Override
            protected Object doInBackground(Void... params) {
                Object returnObj = null;
                try {
                    if (MinMaxPropertyView.this.minGetter != null)
                        returnObj = minGetter.invoke(MinMaxPropertyView.this.busObject);
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
                    MinMaxPropertyView.this.minView.setText(o.toString());
                    MinMaxPropertyView.this.min = Double.parseDouble(o.toString());
                    MinMaxPropertyView.this.seekBar.setMin(MinMaxPropertyView.this.min);
                }
            }
        }.execute();

        new AsyncTask<Void, Void, Object>() {
            @Override
            protected Object doInBackground(Void... params) {
                Object returnObj = null;
                try {
                    if (MinMaxPropertyView.this.maxGetter != null)
                        returnObj = maxGetter.invoke(MinMaxPropertyView.this.busObject);
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
                    MinMaxPropertyView.this.maxView.setText(o.toString());
                    MinMaxPropertyView.this.max = Double.parseDouble(o.toString());
                    MinMaxPropertyView.this.seekBar.setMax(MinMaxPropertyView.this.max);
                }
            }
        }.execute();

        new AsyncTask<Void, Void, Object>() {
            @Override
            protected Object doInBackground(Void... params) {
                Object returnObj = null;
                try {
                    if (MinMaxPropertyView.this.stepGetter != null)
                        returnObj = stepGetter.invoke(MinMaxPropertyView.this.busObject);
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
                    MinMaxPropertyView.this.step = Double.parseDouble(o.toString());
                    MinMaxPropertyView.this.stepView.setText(o.toString());
                    MinMaxPropertyView.this.seekBar.setStep(MinMaxPropertyView.this.step);
                }
            }
        }.execute();
    }
}
