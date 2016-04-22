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
import android.widget.LinearLayout;
import android.widget.TextView;

import org.alljoyn.bus.BusObject;
import org.alljoyn.smartspaces.haecontroller.R;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class ReadOnlyPropertyView extends PropertyView {
    private TextView nameView;
    private TextView valueView;
    private TextView unitView;

    public ReadOnlyPropertyView(Context context, Object obj, String propertyName, String unit) {
        super(context, obj, propertyName, unit);
    }

    protected void initView() {
        LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        ViewGroup view = (ViewGroup)inflater.inflate(R.layout.view_readonly_property, this, false);

        this.addView(view);

        this.nameView = (TextView) view.findViewById(R.id.property_name);
        this.valueView = (TextView) view.findViewById(R.id.property_value);
        this.unitView = (TextView) view.findViewById(R.id.property_unit);

        this.nameView.setText(this.name);
        if (this.unit != null && !this.unit.isEmpty())
            this.unitView.setText(this.unit);
        else
            this.unitView.setVisibility(View.GONE);
    }

    @Override
    public void setValueView(String value) {
        this.valueView.setText(value);
    }
}
