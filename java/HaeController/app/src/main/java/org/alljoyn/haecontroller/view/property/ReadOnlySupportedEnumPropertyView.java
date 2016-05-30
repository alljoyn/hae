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

package org.alljoyn.haecontroller.view.property;

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
import android.widget.Toast;

import org.alljoyn.bus.BusException;
import org.alljoyn.bus.Variant;
import org.alljoyn.haecontroller.R;
import org.alljoyn.haecontroller.util.HaeUtil;
import org.alljoyn.haecontroller.view.PropertyView;
import org.alljoyn.smartspaces.EnumBase;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class ReadOnlySupportedEnumPropertyView<T extends EnumBase<T>> extends SupportedEnumPropertyView {
    private static final String TAG = "HAE_ReadProperty";


    public ReadOnlySupportedEnumPropertyView(Context context, Object obj, String propertyName, String supportedEnumPropertyName, Class<T> clazz) {
        super(context, obj, propertyName, supportedEnumPropertyName, clazz);

    }

    int positionC = 0;

    @Override
    public void setValueView(Object value) {
        T item = (T)HaeUtil.findEnum(value, clazz);

        if (item != null && valuesAdapter.getCount() > 0) {
            this.valuesView.setSelection(valuesAdapter.getPosition(item));
            positionC = valuesAdapter.getPosition(item);
        }
        if (this.listener == null) {
            this.listener = new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                 //   ReadOnlySupportedEnumPropertyView.this.setProperty(ReadOnlySupportedEnumPropertyView.this.valuesAdapter.getItem(position).toValue());
                    valuesView.setSelection(positionC);
                    warning(name+" is read only property");
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            };
            this.valuesView.setOnItemSelectedListener(this.listener);
        }

    }

    private void warning(String msg) {
        Toast.makeText(this.getContext(), msg, Toast.LENGTH_SHORT).show();
    }
}
